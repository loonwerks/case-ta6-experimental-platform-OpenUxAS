// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/uxnative/UXNATIVEFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "uxas/messages/uxnative/VideoRecord.h"
#include "uxas/messages/uxnative/StartupComplete.h"
#include "uxas/messages/uxnative/CreateNewService.h"
#include "uxas/messages/uxnative/KillService.h"
#include "uxas/messages/uxnative/IncrementWaypoint.h"
#include "uxas/messages/uxnative/SafeHeadingAction.h"
#include "uxas/messages/uxnative/EntityLocation.h"
#include "uxas/messages/uxnative/BandwidthTest.h"
#include "uxas/messages/uxnative/BandwidthReceiveReport.h"
#include "uxas/messages/uxnative/SubTaskExecution.h"
#include "uxas/messages/uxnative/SubTaskAssignment.h"
#include "uxas/messages/uxnative/AutopilotKeepAlive.h"
#include "uxas/messages/uxnative/OnboardStatusReport.h"
#include "uxas/messages/uxnative/EntityJoin.h"
#include "uxas/messages/uxnative/EntityExit.h"
#include "uxas/messages/uxnative/SimulationTimeStepAcknowledgement.h"
#include "uxas/messages/uxnative/SpeedOverrideAction.h"
#include "uxas/messages/uxnative/ZeroizeCommand.h"
#include "uxas/messages/uxnative/ZeroizeCondition.h"
#include "uxas/messages/uxnative/DownloadRequest.h"
#include "uxas/messages/uxnative/DownloadReply.h"
#include "uxas/messages/uxnative/FileTransferRequest.h"
#include "uxas/messages/uxnative/File.h"
#include "uxas/messages/uxnative/FileTransfer.h"
#include "uxas/messages/uxnative/UXNATIVEEnum.h"


namespace uxas {
namespace messages {
namespace uxnative {


        const uint32_t UXNATIVEFactory::HEADER_SIZE = 8;
        const uint32_t UXNATIVEFactory::CHECKSUM_SIZE = 4;
        const uint32_t UXNATIVEFactory::SERIESNAME_SIZE = 8;
        const int32_t UXNATIVEFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        UXNATIVEFactory::UXNATIVEFactory(void) { }

        UXNATIVEFactory::UXNATIVEFactory(const UXNATIVEFactory & that) { }

        UXNATIVEFactory & UXNATIVEFactory::operator=(const UXNATIVEFactory & that)
        {
            return *this;
        }

        UXNATIVEFactory::~UXNATIVEFactory(void) { }

        avtas::lmcp::ByteBuffer* UXNATIVEFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
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
                UXNATIVEFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void UXNATIVEFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
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

        avtas::lmcp::Object * UXNATIVEFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (UXNATIVEFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (UXNATIVEFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (UXNATIVEFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (UXNATIVEFactory::getObject): checksum invalid.\n";
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
            avtas::lmcp::Object* o = UXNATIVEFactory::createObject(series_id, msgtype, version);

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

        avtas::lmcp::Object * UXNATIVEFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 6149751333668345413LL)
               if (version == 9)
                  switch(type)
                  {
                     case 1: return new uxas::messages::uxnative::VideoRecord; 
                     case 2: return new uxas::messages::uxnative::StartupComplete; 
                     case 3: return new uxas::messages::uxnative::CreateNewService; 
                     case 4: return new uxas::messages::uxnative::KillService; 
                     case 5: return new uxas::messages::uxnative::IncrementWaypoint; 
                     case 6: return new uxas::messages::uxnative::SafeHeadingAction; 
                     case 7: return new uxas::messages::uxnative::EntityLocation; 
                     case 8: return new uxas::messages::uxnative::BandwidthTest; 
                     case 9: return new uxas::messages::uxnative::BandwidthReceiveReport; 
                     case 10: return new uxas::messages::uxnative::SubTaskExecution; 
                     case 11: return new uxas::messages::uxnative::SubTaskAssignment; 
                     case 12: return new uxas::messages::uxnative::AutopilotKeepAlive; 
                     case 13: return new uxas::messages::uxnative::OnboardStatusReport; 
                     case 14: return new uxas::messages::uxnative::EntityJoin; 
                     case 15: return new uxas::messages::uxnative::EntityExit; 
                     case 16: return new uxas::messages::uxnative::SimulationTimeStepAcknowledgement; 
                     case 17: return new uxas::messages::uxnative::SpeedOverrideAction; 
                     case 18: return new uxas::messages::uxnative::ZeroizeCommand; 
                     case 19: return new uxas::messages::uxnative::ZeroizeCondition; 
                     case 20: return new uxas::messages::uxnative::DownloadRequest; 
                     case 21: return new uxas::messages::uxnative::DownloadReply; 
                     case 22: return new uxas::messages::uxnative::FileTransferRequest; 
                     case 23: return new uxas::messages::uxnative::File; 
                     case 24: return new uxas::messages::uxnative::FileTransfer; 
                  }

            return nullptr;
        }

        uint32_t UXNATIVEFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t UXNATIVEFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
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

        bool UXNATIVEFactory::validate(const uint8_t * bytes, const uint32_t size)
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

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

