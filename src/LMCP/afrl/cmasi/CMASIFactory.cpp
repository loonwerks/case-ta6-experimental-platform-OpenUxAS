// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/cmasi/CMASIFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "afrl/cmasi/AbstractGeometry.h"
#include "afrl/cmasi/KeyValuePair.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/PayloadAction.h"
#include "afrl/cmasi/PayloadConfiguration.h"
#include "afrl/cmasi/PayloadState.h"
#include "afrl/cmasi/VehicleAction.h"
#include "afrl/cmasi/Task.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/AbstractZone.h"
#include "afrl/cmasi/EntityConfiguration.h"
#include "afrl/cmasi/FlightProfile.h"
#include "afrl/cmasi/AirVehicleConfiguration.h"
#include "afrl/cmasi/EntityState.h"
#include "afrl/cmasi/AirVehicleState.h"
#include "afrl/cmasi/Wedge.h"
#include "afrl/cmasi/AreaSearchTask.h"
#include "afrl/cmasi/CameraAction.h"
#include "afrl/cmasi/CameraConfiguration.h"
#include "afrl/cmasi/GimballedPayloadState.h"
#include "afrl/cmasi/CameraState.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/GimbalAngleAction.h"
#include "afrl/cmasi/GimbalConfiguration.h"
#include "afrl/cmasi/GimbalScanAction.h"
#include "afrl/cmasi/GimbalStareAction.h"
#include "afrl/cmasi/GimbalState.h"
#include "afrl/cmasi/GoToWaypointAction.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"
#include "afrl/cmasi/LineSearchTask.h"
#include "afrl/cmasi/NavigationAction.h"
#include "afrl/cmasi/LoiterAction.h"
#include "afrl/cmasi/LoiterTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/MissionCommand.h"
#include "afrl/cmasi/MustFlyTask.h"
#include "afrl/cmasi/OperatorSignal.h"
#include "afrl/cmasi/OperatingRegion.h"
#include "afrl/cmasi/AutomationRequest.h"
#include "afrl/cmasi/PointSearchTask.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"
#include "afrl/cmasi/RemoveTasks.h"
#include "afrl/cmasi/ServiceStatus.h"
#include "afrl/cmasi/SessionStatus.h"
#include "afrl/cmasi/VehicleActionCommand.h"
#include "afrl/cmasi/VideoStreamAction.h"
#include "afrl/cmasi/VideoStreamConfiguration.h"
#include "afrl/cmasi/VideoStreamState.h"
#include "afrl/cmasi/AutomationResponse.h"
#include "afrl/cmasi/RemoveZones.h"
#include "afrl/cmasi/RemoveEntities.h"
#include "afrl/cmasi/FlightDirectorAction.h"
#include "afrl/cmasi/WeatherReport.h"
#include "afrl/cmasi/FollowPathCommand.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/StopMovementAction.h"
#include "afrl/cmasi/WaypointTransfer.h"
#include "afrl/cmasi/PayloadStowAction.h"
#include "afrl/cmasi/WavelengthBand.h"
#include "afrl/cmasi/NavigationMode.h"
#include "afrl/cmasi/FOVOperationMode.h"
#include "afrl/cmasi/GimbalPointingMode.h"
#include "afrl/cmasi/ZoneAvoidanceType.h"
#include "afrl/cmasi/LoiterType.h"
#include "afrl/cmasi/LoiterDirection.h"
#include "afrl/cmasi/ServiceStatusType.h"
#include "afrl/cmasi/SimulationStatusType.h"
#include "afrl/cmasi/SpeedType.h"
#include "afrl/cmasi/TurnType.h"
#include "afrl/cmasi/CommandStatusType.h"
#include "afrl/cmasi/AltitudeType.h"
#include "afrl/cmasi/TravelMode.h"
#include "afrl/cmasi/WaypointTransferMode.h"
#include "afrl/cmasi/CMASIEnum.h"


namespace afrl {
namespace cmasi {


        const uint32_t CMASIFactory::HEADER_SIZE = 8;
        const uint32_t CMASIFactory::CHECKSUM_SIZE = 4;
        const uint32_t CMASIFactory::SERIESNAME_SIZE = 8;
        const int32_t CMASIFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        CMASIFactory::CMASIFactory(void) { }

        CMASIFactory::CMASIFactory(const CMASIFactory & that) { }

        CMASIFactory & CMASIFactory::operator=(const CMASIFactory & that)
        {
            return *this;
        }

        CMASIFactory::~CMASIFactory(void) { }

        avtas::lmcp::ByteBuffer* CMASIFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
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
                CMASIFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void CMASIFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
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

        avtas::lmcp::Object * CMASIFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (CMASIFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (CMASIFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (CMASIFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (CMASIFactory::getObject): checksum invalid.\n";
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
            avtas::lmcp::Object* o = CMASIFactory::createObject(series_id, msgtype, version);

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

        avtas::lmcp::Object * CMASIFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 4849604199710720000LL)
               if (version == 3)
                  switch(type)
                  {
                     case 1: return new afrl::cmasi::AbstractGeometry; 
                     case 2: return new afrl::cmasi::KeyValuePair; 
                     case 3: return new afrl::cmasi::Location3D; 
                     case 4: return new afrl::cmasi::PayloadAction; 
                     case 5: return new afrl::cmasi::PayloadConfiguration; 
                     case 6: return new afrl::cmasi::PayloadState; 
                     case 7: return new afrl::cmasi::VehicleAction; 
                     case 8: return new afrl::cmasi::Task; 
                     case 9: return new afrl::cmasi::SearchTask; 
                     case 10: return new afrl::cmasi::AbstractZone; 
                     case 11: return new afrl::cmasi::EntityConfiguration; 
                     case 12: return new afrl::cmasi::FlightProfile; 
                     case 13: return new afrl::cmasi::AirVehicleConfiguration; 
                     case 14: return new afrl::cmasi::EntityState; 
                     case 15: return new afrl::cmasi::AirVehicleState; 
                     case 16: return new afrl::cmasi::Wedge; 
                     case 17: return new afrl::cmasi::AreaSearchTask; 
                     case 18: return new afrl::cmasi::CameraAction; 
                     case 19: return new afrl::cmasi::CameraConfiguration; 
                     case 20: return new afrl::cmasi::GimballedPayloadState; 
                     case 21: return new afrl::cmasi::CameraState; 
                     case 22: return new afrl::cmasi::Circle; 
                     case 23: return new afrl::cmasi::GimbalAngleAction; 
                     case 24: return new afrl::cmasi::GimbalConfiguration; 
                     case 25: return new afrl::cmasi::GimbalScanAction; 
                     case 26: return new afrl::cmasi::GimbalStareAction; 
                     case 27: return new afrl::cmasi::GimbalState; 
                     case 28: return new afrl::cmasi::GoToWaypointAction; 
                     case 29: return new afrl::cmasi::KeepInZone; 
                     case 30: return new afrl::cmasi::KeepOutZone; 
                     case 31: return new afrl::cmasi::LineSearchTask; 
                     case 32: return new afrl::cmasi::NavigationAction; 
                     case 33: return new afrl::cmasi::LoiterAction; 
                     case 34: return new afrl::cmasi::LoiterTask; 
                     case 35: return new afrl::cmasi::Waypoint; 
                     case 36: return new afrl::cmasi::MissionCommand; 
                     case 37: return new afrl::cmasi::MustFlyTask; 
                     case 38: return new afrl::cmasi::OperatorSignal; 
                     case 39: return new afrl::cmasi::OperatingRegion; 
                     case 40: return new afrl::cmasi::AutomationRequest; 
                     case 41: return new afrl::cmasi::PointSearchTask; 
                     case 42: return new afrl::cmasi::Polygon; 
                     case 43: return new afrl::cmasi::Rectangle; 
                     case 44: return new afrl::cmasi::RemoveTasks; 
                     case 45: return new afrl::cmasi::ServiceStatus; 
                     case 46: return new afrl::cmasi::SessionStatus; 
                     case 47: return new afrl::cmasi::VehicleActionCommand; 
                     case 48: return new afrl::cmasi::VideoStreamAction; 
                     case 49: return new afrl::cmasi::VideoStreamConfiguration; 
                     case 50: return new afrl::cmasi::VideoStreamState; 
                     case 51: return new afrl::cmasi::AutomationResponse; 
                     case 52: return new afrl::cmasi::RemoveZones; 
                     case 53: return new afrl::cmasi::RemoveEntities; 
                     case 54: return new afrl::cmasi::FlightDirectorAction; 
                     case 55: return new afrl::cmasi::WeatherReport; 
                     case 56: return new afrl::cmasi::FollowPathCommand; 
                     case 57: return new afrl::cmasi::PathWaypoint; 
                     case 58: return new afrl::cmasi::StopMovementAction; 
                     case 59: return new afrl::cmasi::WaypointTransfer; 
                     case 60: return new afrl::cmasi::PayloadStowAction; 
                  }

            return nullptr;
        }

        uint32_t CMASIFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t CMASIFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
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

        bool CMASIFactory::validate(const uint8_t * bytes, const uint32_t size)
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

} // end namespace cmasi
} // end namespace afrl

