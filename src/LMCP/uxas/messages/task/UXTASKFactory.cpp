// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/task/UXTASKFactory.h"
#include "avtas/lmcp/Object.h"
#include <iostream>
#include <string>
#include <cstdint>

#include "uxas/messages/task/AssignmentCoordinatorTask.h"
#include "uxas/messages/task/RendezvousTask.h"
#include "uxas/messages/task/PlanningState.h"
#include "uxas/messages/task/AssignmentCoordination.h"
#include "uxas/messages/task/CoordinatedAutomationRequest.h"
#include "uxas/messages/task/TaskAutomationRequest.h"
#include "uxas/messages/task/TaskAutomationResponse.h"
#include "uxas/messages/task/UniqueAutomationRequest.h"
#include "uxas/messages/task/UniqueAutomationResponse.h"
#include "uxas/messages/task/SensorFootprintRequests.h"
#include "uxas/messages/task/FootprintRequest.h"
#include "uxas/messages/task/SensorFootprint.h"
#include "uxas/messages/task/SensorFootprintResponse.h"
#include "uxas/messages/task/TaskImplementationRequest.h"
#include "uxas/messages/task/TaskImplementationResponse.h"
#include "uxas/messages/task/AssignmentCostMatrix.h"
#include "uxas/messages/task/TaskOptionCost.h"
#include "uxas/messages/task/TaskAssignment.h"
#include "uxas/messages/task/TaskAssignmentSummary.h"
#include "uxas/messages/task/TaskOption.h"
#include "uxas/messages/task/TaskPlanOptions.h"
#include "uxas/messages/task/TaskPause.h"
#include "uxas/messages/task/TaskResume.h"
#include "uxas/messages/task/TaskProgress.h"
#include "uxas/messages/task/TaskProgressRequest.h"
#include "uxas/messages/task/TaskInitialized.h"
#include "uxas/messages/task/TaskActive.h"
#include "uxas/messages/task/TaskComplete.h"
#include "uxas/messages/task/CancelTask.h"
#include "uxas/messages/task/UXTASKEnum.h"


namespace uxas {
namespace messages {
namespace task {


        const uint32_t UXTASKFactory::HEADER_SIZE = 8;
        const uint32_t UXTASKFactory::CHECKSUM_SIZE = 4;
        const uint32_t UXTASKFactory::SERIESNAME_SIZE = 8;
        const int32_t UXTASKFactory::LMCP_CONTROL_STR = 0x4c4d4350;

        UXTASKFactory::UXTASKFactory(void) { }

        UXTASKFactory::UXTASKFactory(const UXTASKFactory & that) { }

        UXTASKFactory & UXTASKFactory::operator=(const UXTASKFactory & that)
        {
            return *this;
        }

        UXTASKFactory::~UXTASKFactory(void) { }

        avtas::lmcp::ByteBuffer* UXTASKFactory::packMessage(const avtas::lmcp::Object * const rootObject, const bool enableChecksum)
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
                UXTASKFactory::putObject( rootObject, *buffer);

                // add checksum
                uint32_t cs = enableChecksum ? calculateChecksum(buffer->array(), buffer->capacity()) : 0;
                buffer->putUInt(cs);
                return buffer;
            }
            return nullptr;
        }

        void UXTASKFactory::putObject(const avtas::lmcp::Object* o, avtas::lmcp::ByteBuffer & buffer)
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

        avtas::lmcp::Object * UXTASKFactory::getObject(avtas::lmcp::ByteBuffer & buffer)
        {
            if (buffer.capacity() < HEADER_SIZE + CHECKSUM_SIZE)
            {
                std::cerr << "Error (UXTASKFactory::getObject): buffer at least as big as"
                        << " header + checksum (" << HEADER_SIZE + CHECKSUM_SIZE << ").\n";
                return nullptr;
            }

            int32_t ctrl_str = buffer.getInt();
            if ( ctrl_str != LMCP_CONTROL_STR)
            {
                std::cerr << "Error (UXTASKFactory::getObject): Not a proper LMCP message.";
                std::cerr << "   Expected: " << LMCP_CONTROL_STR << "   Received: " << ctrl_str << std::endl;
                return nullptr;
            }

            uint32_t msgsize = buffer.getUInt();
            if ( buffer.capacity() < msgsize )
            {
                std::cerr << "Error (UXTASKFactory::getObject): Buffer size too small for packed object.";
                std::cerr << "   MsgSize: " << msgsize << "    Capacity: " << buffer.capacity() << std::endl;
                return nullptr;
            }

            // validate the buffer's checksum
            if (!validate(buffer.array(), buffer.capacity()))
            {
                std::cerr << "Error (UXTASKFactory::getObject): checksum invalid.\n";
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
            avtas::lmcp::Object* o = UXTASKFactory::createObject(series_id, msgtype, version);

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

        avtas::lmcp::Object * UXTASKFactory::createObject(int64_t series_id, uint32_t type, uint16_t version)
        {
            if (series_id == 6149757930721443840LL)
               if (version == 8)
                  switch(type)
                  {
                     case 1: return new uxas::messages::task::AssignmentCoordinatorTask; 
                     case 2: return new uxas::messages::task::RendezvousTask; 
                     case 3: return new uxas::messages::task::PlanningState; 
                     case 4: return new uxas::messages::task::AssignmentCoordination; 
                     case 5: return new uxas::messages::task::CoordinatedAutomationRequest; 
                     case 6: return new uxas::messages::task::TaskAutomationRequest; 
                     case 7: return new uxas::messages::task::TaskAutomationResponse; 
                     case 8: return new uxas::messages::task::UniqueAutomationRequest; 
                     case 9: return new uxas::messages::task::UniqueAutomationResponse; 
                     case 10: return new uxas::messages::task::SensorFootprintRequests; 
                     case 11: return new uxas::messages::task::FootprintRequest; 
                     case 12: return new uxas::messages::task::SensorFootprint; 
                     case 13: return new uxas::messages::task::SensorFootprintResponse; 
                     case 14: return new uxas::messages::task::TaskImplementationRequest; 
                     case 15: return new uxas::messages::task::TaskImplementationResponse; 
                     case 16: return new uxas::messages::task::AssignmentCostMatrix; 
                     case 17: return new uxas::messages::task::TaskOptionCost; 
                     case 18: return new uxas::messages::task::TaskAssignment; 
                     case 19: return new uxas::messages::task::TaskAssignmentSummary; 
                     case 20: return new uxas::messages::task::TaskOption; 
                     case 21: return new uxas::messages::task::TaskPlanOptions; 
                     case 22: return new uxas::messages::task::TaskPause; 
                     case 23: return new uxas::messages::task::TaskResume; 
                     case 24: return new uxas::messages::task::TaskProgress; 
                     case 25: return new uxas::messages::task::TaskProgressRequest; 
                     case 26: return new uxas::messages::task::TaskInitialized; 
                     case 27: return new uxas::messages::task::TaskActive; 
                     case 28: return new uxas::messages::task::TaskComplete; 
                     case 29: return new uxas::messages::task::CancelTask; 
                  }

            return nullptr;
        }

        uint32_t UXTASKFactory::calculateChecksum(const uint8_t * bytes, const uint32_t size)
        {
            uint32_t sum = 0;
            for (uint32_t i = 0; i < size - CHECKSUM_SIZE; i++)
                sum += (uint32_t) bytes[i];
            return sum & 0x00000000FFFFFFFF; // truncate value
        }

        uint32_t UXTASKFactory::getObjectSize(const uint8_t * bytes, const uint32_t size)
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

        bool UXTASKFactory::validate(const uint8_t * bytes, const uint32_t size)
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

} // end namespace task
} // end namespace messages
} // end namespace uxas

