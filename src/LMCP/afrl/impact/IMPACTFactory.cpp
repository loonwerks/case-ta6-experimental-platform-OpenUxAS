// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/impact/IMPACTFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "afrl/impact/PowerConfiguration.h"
#include "afrl/impact/RadioConfiguration.h"
#include "afrl/impact/RadioTowerConfiguration.h"
#include "afrl/impact/RadioState.h"
#include "afrl/impact/RadioTowerState.h"
#include "afrl/impact/ImpactPayloadConfiguration.h"
#include "afrl/impact/DeployImpactPayload.h"
#include "afrl/impact/PowerPlantState.h"
#include "afrl/impact/BatchRoutePlanRequest.h"
#include "afrl/impact/BatchRoutePlanResponse.h"
#include "afrl/impact/TaskTimingPair.h"
#include "afrl/impact/BatchSummaryRequest.h"
#include "afrl/impact/BatchSummaryResponse.h"
#include "afrl/impact/TaskSummary.h"
#include "afrl/impact/VehicleSummary.h"
#include "afrl/impact/SpeedAltPair.h"
#include "afrl/impact/ImpactAutomationRequest.h"
#include "afrl/impact/ImpactAutomationResponse.h"
#include "afrl/impact/PointOfInterest.h"
#include "afrl/impact/LineOfInterest.h"
#include "afrl/impact/AreaOfInterest.h"
#include "afrl/impact/ImpactPointSearchTask.h"
#include "afrl/impact/PatternSearchTask.h"
#include "afrl/impact/AngledAreaSearchTask.h"
#include "afrl/impact/ImpactLineSearchTask.h"
#include "afrl/impact/WatchTask.h"
#include "afrl/impact/MultiVehicleWatchTask.h"
#include "afrl/impact/CommRelayTask.h"
#include "afrl/impact/CordonTask.h"
#include "afrl/impact/BlockadeTask.h"
#include "afrl/impact/EscortTask.h"
#include "afrl/impact/ConfigurationRequest.h"
#include "afrl/impact/WaterReport.h"
#include "afrl/impact/WaterZone.h"
#include "afrl/impact/PayloadDropTask.h"
#include "afrl/impact/AreaSearchPattern.h"
#include "afrl/impact/PowerPlant.h"
#include "afrl/impact/AreaActionOptions.h"
#include "afrl/impact/ImpactPayloadType.h"
#include "afrl/impact/IMPACTEnum.h"


namespace afrl {
namespace impact {


        const uint32_t IMPACTFactory::HEADER_SIZE = 8;
        const uint32_t IMPACTFactory::CHECKSUM_SIZE = 4;
        const uint32_t IMPACTFactory::SERIESNAME_SIZE = 8;
        const int32_t IMPACTFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        IMPACTFactory::IMPACTFactory(void) { }

        IMPACTFactory::IMPACTFactory(const IMPACTFactory & that) { }

        IMPACTFactory & IMPACTFactory::operator=(const IMPACTFactory & that)
        {
            return *this;
        }

        IMPACTFactory::~IMPACTFactory(void) { }

        avtas::lmcp::ByteBuffer* IMPACTFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
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
                IMPACTFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void IMPACTFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
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

        avtas::lmcp::Object * IMPACTFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (IMPACTFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (IMPACTFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (IMPACTFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (IMPACTFactory::getObject): checksum invalid.\n";
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
            avtas::lmcp::Object* o = IMPACTFactory::createObject(series_id, msgtype, version);

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

        avtas::lmcp::Object * IMPACTFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 5281966179208134656LL)
               if (version == 14)
                  switch(type)
                  {
                     case 1: return new afrl::impact::PowerConfiguration; 
                     case 2: return new afrl::impact::RadioConfiguration; 
                     case 3: return new afrl::impact::RadioTowerConfiguration; 
                     case 4: return new afrl::impact::RadioState; 
                     case 5: return new afrl::impact::RadioTowerState; 
                     case 6: return new afrl::impact::ImpactPayloadConfiguration; 
                     case 7: return new afrl::impact::DeployImpactPayload; 
                     case 8: return new afrl::impact::PowerPlantState; 
                     case 9: return new afrl::impact::BatchRoutePlanRequest; 
                     case 10: return new afrl::impact::BatchRoutePlanResponse; 
                     case 11: return new afrl::impact::TaskTimingPair; 
                     case 12: return new afrl::impact::BatchSummaryRequest; 
                     case 13: return new afrl::impact::BatchSummaryResponse; 
                     case 14: return new afrl::impact::TaskSummary; 
                     case 15: return new afrl::impact::VehicleSummary; 
                     case 16: return new afrl::impact::SpeedAltPair; 
                     case 17: return new afrl::impact::ImpactAutomationRequest; 
                     case 18: return new afrl::impact::ImpactAutomationResponse; 
                     case 19: return new afrl::impact::PointOfInterest; 
                     case 20: return new afrl::impact::LineOfInterest; 
                     case 21: return new afrl::impact::AreaOfInterest; 
                     case 22: return new afrl::impact::ImpactPointSearchTask; 
                     case 23: return new afrl::impact::PatternSearchTask; 
                     case 24: return new afrl::impact::AngledAreaSearchTask; 
                     case 25: return new afrl::impact::ImpactLineSearchTask; 
                     case 26: return new afrl::impact::WatchTask; 
                     case 27: return new afrl::impact::MultiVehicleWatchTask; 
                     case 28: return new afrl::impact::CommRelayTask; 
                     case 29: return new afrl::impact::CordonTask; 
                     case 30: return new afrl::impact::BlockadeTask; 
                     case 31: return new afrl::impact::EscortTask; 
                     case 32: return new afrl::impact::ConfigurationRequest; 
                     case 33: return new afrl::impact::WaterReport; 
                     case 34: return new afrl::impact::WaterZone; 
                     case 35: return new afrl::impact::PayloadDropTask; 
                  }

            return nullptr;
        }

        uint32_t IMPACTFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t IMPACTFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
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

        bool IMPACTFactory::validate(const uint8_t * bytes, const uint32_t size)
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

} // end namespace impact
} // end namespace afrl

