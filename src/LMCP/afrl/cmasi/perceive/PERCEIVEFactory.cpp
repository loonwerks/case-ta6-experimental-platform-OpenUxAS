// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/cmasi/perceive/PERCEIVEFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "afrl/cmasi/perceive/EntityPerception.h"
#include "afrl/cmasi/perceive/TrackEntityAction.h"
#include "afrl/cmasi/perceive/TrackEntityTask.h"
#include "afrl/cmasi/perceive/PERCEIVEEnum.h"


namespace afrl {
namespace cmasi {
namespace perceive {


        const uint32_t PERCEIVEFactory::HEADER_SIZE = 8;
        const uint32_t PERCEIVEFactory::CHECKSUM_SIZE = 4;
        const uint32_t PERCEIVEFactory::SERIESNAME_SIZE = 8;
        const int32_t PERCEIVEFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        PERCEIVEFactory::PERCEIVEFactory(void) { }

        PERCEIVEFactory::PERCEIVEFactory(const PERCEIVEFactory & that) { }

        PERCEIVEFactory & PERCEIVEFactory::operator=(const PERCEIVEFactory & that)
        {
            return *this;
        }

        PERCEIVEFactory::~PERCEIVEFactory(void) { }

        avtas::lmcp::ByteBuffer* PERCEIVEFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
        {
            if (rootObject != nullptr)
            {
                // allocate space for message
                // 15 = boolean (1 byte), series name (8 bytes), type (4 bytes) , version number (2 bytes)
                uint32_t msgSize = rootObject->calculatePackedSize() + 15;
                avtas::lmcp::ByteBuffer* buffer = new avtas::lmcp::ByteBuffer();
                buffer->allocate(HEADER_SIZE + msgSize + CHECKSUM_SIZE);

                // add header values
                buffer->putInt(LMCP_CONTROL_STR);
                buffer->putUInt( msgSize );

                // add root object
                PERCEIVEFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void PERCEIVEFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
        {
            if (!o)
            {
                buffer.putBool(false);
            }
            else
            {
                buffer.putBool(true);
                buffer.putLong(o->getSeriesNameAsLong());
                buffer.putUInt(o->getLmcpType());
                buffer.putUShort(o->getSeriesVersion());
                o->pack(buffer);
            }
        }

        avtas::lmcp::Object * PERCEIVEFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (PERCEIVEFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (PERCEIVEFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (PERCEIVEFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (PERCEIVEFactory::getObject): checksum invalid.\n";
                return nullptr;
            }

            if(!buffer.getBool())
            {
                std::cerr << "Message indicated it was packed as NULL\n";
                return nullptr;
            }

            int64_t series_id = buffer.getLong();
            uint32_t msgtype = buffer.getUInt();
            uint16_t version = buffer.getUShort();
            avtas::lmcp::Object* o = PERCEIVEFactory::createObject(series_id, msgtype, version);

            if (o != nullptr)
            {
                o->unpack(buffer);
            }
            else
            {
                std::cerr << "Buffer does not contain a recognized object type. \n";
            }

            return o;

        }

        avtas::lmcp::Object * PERCEIVEFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 5784119745305990725LL)
               if (version == 1)
                  switch(type)
                  {
                     case 1: return new afrl::cmasi::perceive::EntityPerception; 
                     case 2: return new afrl::cmasi::perceive::TrackEntityAction; 
                     case 3: return new afrl::cmasi::perceive::TrackEntityTask; 
                  }

            return nullptr;
        }

        uint32_t PERCEIVEFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t PERCEIVEFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t id = 0;
            if (size >= HEADER_SIZE)
            {
                id |= (bytes[4] & 0xFF);
                id <<= 8;
                id |= (bytes[5] & 0xFF);
                id <<= 8;
                id |= (bytes[6] & 0xFF);
                id <<= 8;
                id |= (bytes[7] & 0xFF);
            }
            return id;
        }

        bool PERCEIVEFactory::validate(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t cs = 0;
            if (size >= HEADER_SIZE + CHECKSUM_SIZE)
            {
                cs = 0;
                cs |= (bytes[size - 4] & 0xFF);
                cs <<= 8;
                cs |= (bytes[size - 3] & 0xFF);
                cs <<= 8;
                cs |= (bytes[size - 2] & 0xFF);
                cs <<= 8;
                cs |= (bytes[size - 1] & 0xFF);
                return (cs == 0) || (cs == calculateChecksum(bytes, size));
            }
            return false;
        }

} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl

