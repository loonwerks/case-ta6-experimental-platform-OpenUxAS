// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/route/ROUTEFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "uxas/messages/route/GraphNode.h"
#include "uxas/messages/route/GraphEdge.h"
#include "uxas/messages/route/GraphRegion.h"
#include "uxas/messages/route/RouteConstraints.h"
#include "uxas/messages/route/RouteRequest.h"
#include "uxas/messages/route/RoutePlanRequest.h"
#include "uxas/messages/route/RoutePlan.h"
#include "uxas/messages/route/RoutePlanResponse.h"
#include "uxas/messages/route/RouteResponse.h"
#include "uxas/messages/route/EgressRouteRequest.h"
#include "uxas/messages/route/EgressRouteResponse.h"
#include "uxas/messages/route/RoadPointsConstraints.h"
#include "uxas/messages/route/RoadPointsRequest.h"
#include "uxas/messages/route/RoadPointsResponse.h"
#include "uxas/messages/route/ROUTEEnum.h"


namespace uxas {
namespace messages {
namespace route {


        const uint32_t ROUTEFactory::HEADER_SIZE = 8;
        const uint32_t ROUTEFactory::CHECKSUM_SIZE = 4;
        const uint32_t ROUTEFactory::SERIESNAME_SIZE = 8;
        const int32_t ROUTEFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        ROUTEFactory::ROUTEFactory(void) { }

        ROUTEFactory::ROUTEFactory(const ROUTEFactory & that) { }

        ROUTEFactory & ROUTEFactory::operator=(const ROUTEFactory & that)
        {
            return *this;
        }

        ROUTEFactory::~ROUTEFactory(void) { }

        avtas::lmcp::ByteBuffer* ROUTEFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
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
                ROUTEFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void ROUTEFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
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

        avtas::lmcp::Object * ROUTEFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (ROUTEFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (ROUTEFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (ROUTEFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (ROUTEFactory::getObject): checksum invalid.\n";
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
            avtas::lmcp::Object* o = ROUTEFactory::createObject(series_id, msgtype, version);

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

        avtas::lmcp::Object * ROUTEFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 5931053054693474304LL)
               if (version == 4)
                  switch(type)
                  {
                     case 1: return new uxas::messages::route::GraphNode; 
                     case 2: return new uxas::messages::route::GraphEdge; 
                     case 3: return new uxas::messages::route::GraphRegion; 
                     case 4: return new uxas::messages::route::RouteConstraints; 
                     case 5: return new uxas::messages::route::RouteRequest; 
                     case 6: return new uxas::messages::route::RoutePlanRequest; 
                     case 7: return new uxas::messages::route::RoutePlan; 
                     case 8: return new uxas::messages::route::RoutePlanResponse; 
                     case 9: return new uxas::messages::route::RouteResponse; 
                     case 10: return new uxas::messages::route::EgressRouteRequest; 
                     case 11: return new uxas::messages::route::EgressRouteResponse; 
                     case 12: return new uxas::messages::route::RoadPointsConstraints; 
                     case 13: return new uxas::messages::route::RoadPointsRequest; 
                     case 14: return new uxas::messages::route::RoadPointsResponse; 
                  }

            return nullptr;
        }

        uint32_t ROUTEFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t ROUTEFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
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

        bool ROUTEFactory::validate(const uint8_t * bytes, const uint32_t size)
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

} // end namespace route
} // end namespace messages
} // end namespace uxas

