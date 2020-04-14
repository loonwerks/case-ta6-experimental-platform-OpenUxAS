// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/task/UXTASKXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

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


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace uxas {
namespace messages {
namespace task {


    avtas::lmcp::Object* UXTASKXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "AssignmentCoordinatorTask"){
           AssignmentCoordinatorTask* o = new AssignmentCoordinatorTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
              if(name == "EligibleEntities")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEligibleEntities().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "RevisitRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setRevisitRate( get_real32( tmp ));
                 continue;
              }
              if(name == "Parameters")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getParameters().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
              if(name == "Priority")
              {
                 Node* tmp = el->getChild(i);
                 o->setPriority( get_byte( tmp ));
                 continue;
              }
              if(name == "Required")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequired( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "RendezvousTask"){
           RendezvousTask* o = new RendezvousTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "NumberOfParticipants")
              {
                 Node* tmp = el->getChild(i);
                 o->setNumberOfParticipants( get_byte( tmp ));
                 continue;
              }
              if(name == "RendezvousStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRendezvousStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
              if(name == "EligibleEntities")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEligibleEntities().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "RevisitRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setRevisitRate( get_real32( tmp ));
                 continue;
              }
              if(name == "Parameters")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getParameters().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
              if(name == "Priority")
              {
                 Node* tmp = el->getChild(i);
                 o->setPriority( get_byte( tmp ));
                 continue;
              }
              if(name == "Required")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequired( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "PlanningState"){
           PlanningState* o = new PlanningState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "PlanningPosition")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setPlanningPosition((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "PlanningHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setPlanningHeading( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "AssignmentCoordination"){
           AssignmentCoordination* o = new AssignmentCoordination();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CoordinatedAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCoordinatedAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "PlanningState")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setPlanningState((uxas::messages::task::PlanningState*) oo );
                 continue;
              }
           }
           return o;
        }
        if (type == "CoordinatedAutomationRequest"){
           CoordinatedAutomationRequest* o = new CoordinatedAutomationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "MaximumResponseTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaximumResponseTime( get_int64( tmp ));
                 continue;
              }
              if(name == "OriginalRequest")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setOriginalRequest((afrl::cmasi::AutomationRequest*) oo );
                 continue;
              }
              if(name == "PlanningStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPlanningStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskAutomationRequest"){
           TaskAutomationRequest* o = new TaskAutomationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "OriginalRequest")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setOriginalRequest((afrl::cmasi::AutomationRequest*) oo );
                 continue;
              }
              if(name == "SandBoxRequest")
              {
                 Node* tmp = el->getChild(i);
                 o->setSandBoxRequest( get_bool( tmp ));
                 continue;
              }
              if(name == "PlanningStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPlanningStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskAutomationResponse"){
           TaskAutomationResponse* o = new TaskAutomationResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "OriginalResponse")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setOriginalResponse((afrl::cmasi::AutomationResponse*) oo );
                 continue;
              }
              if(name == "FinalStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFinalStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "UniqueAutomationRequest"){
           UniqueAutomationRequest* o = new UniqueAutomationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "OriginalRequest")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setOriginalRequest((afrl::cmasi::AutomationRequest*) oo );
                 continue;
              }
              if(name == "SandBoxRequest")
              {
                 Node* tmp = el->getChild(i);
                 o->setSandBoxRequest( get_bool( tmp ));
                 continue;
              }
              if(name == "PlanningStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPlanningStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "UniqueAutomationResponse"){
           UniqueAutomationResponse* o = new UniqueAutomationResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "OriginalResponse")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setOriginalResponse((afrl::cmasi::AutomationResponse*) oo );
                 continue;
              }
              if(name == "FinalStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFinalStates().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "SensorFootprintRequests"){
           SensorFootprintRequests* o = new SensorFootprintRequests();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "Footprints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFootprints().push_back( (uxas::messages::task::FootprintRequest*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "FootprintRequest"){
           FootprintRequest* o = new FootprintRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "FootprintRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setFootprintRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "EligibleWavelengths")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEligibleWavelengths().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "GroundSampleDistances")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getGroundSampleDistances().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "AglAltitudes")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAglAltitudes().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "ElevationAngles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getElevationAngles().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "SensorFootprint"){
           SensorFootprint* o = new SensorFootprint();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "FootprintResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setFootprintResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "CameraID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCameraID( get_int64( tmp ));
                 continue;
              }
              if(name == "GimbalID")
              {
                 Node* tmp = el->getChild(i);
                 o->setGimbalID( get_int64( tmp ));
                 continue;
              }
              if(name == "HorizontalFOV")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalFOV( get_real32( tmp ));
                 continue;
              }
              if(name == "AglAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setAglAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "GimbalElevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setGimbalElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "AspectRatio")
              {
                 Node* tmp = el->getChild(i);
                 o->setAspectRatio( get_real32( tmp ));
                 continue;
              }
              if(name == "AchievedGSD")
              {
                 Node* tmp = el->getChild(i);
                 o->setAchievedGSD( get_real32( tmp ));
                 continue;
              }
              if(name == "CameraWavelength")
              {
                 Node* tmp = el->getChild(i);
                 o->setCameraWavelength( afrl::cmasi::WavelengthBand::get_WavelengthBand( get_string( tmp )));
                 continue;
              }
              if(name == "HorizontalToLeadingEdge")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalToLeadingEdge( get_real32( tmp ));
                 continue;
              }
              if(name == "HorizontalToTrailingEdge")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalToTrailingEdge( get_real32( tmp ));
                 continue;
              }
              if(name == "HorizontalToCenter")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalToCenter( get_real32( tmp ));
                 continue;
              }
              if(name == "WidthCenter")
              {
                 Node* tmp = el->getChild(i);
                 o->setWidthCenter( get_real32( tmp ));
                 continue;
              }
              if(name == "SlantRangeToCenter")
              {
                 Node* tmp = el->getChild(i);
                 o->setSlantRangeToCenter( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SensorFootprintResponse"){
           SensorFootprintResponse* o = new SensorFootprintResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "Footprints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFootprints().push_back( (uxas::messages::task::SensorFootprint*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskImplementationRequest"){
           TaskImplementationRequest* o = new TaskImplementationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "CorrespondingAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCorrespondingAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "StartingWaypointID")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartingWaypointID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "StartPosition")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStartPosition((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "StartHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartHeading( get_real32( tmp ));
                 continue;
              }
              if(name == "StartTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartTime( get_int64( tmp ));
                 continue;
              }
              if(name == "RegionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRegionID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "OptionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setOptionID( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeThreshold")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeThreshold( get_int64( tmp ));
                 continue;
              }
              if(name == "NeighborLocations")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getNeighborLocations().push_back( (uxas::messages::task::PlanningState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskImplementationResponse"){
           TaskImplementationResponse* o = new TaskImplementationResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "CorrespondingAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCorrespondingAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "OptionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setOptionID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskWaypoints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getTaskWaypoints().push_back( (afrl::cmasi::Waypoint*) oo);
                 }
                 continue;
              }
              if(name == "FinalLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setFinalLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "FinalHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setFinalHeading( get_real32( tmp ));
                 continue;
              }
              if(name == "FinalTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setFinalTime( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "AssignmentCostMatrix"){
           AssignmentCostMatrix* o = new AssignmentCostMatrix();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CorrespondingAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCorrespondingAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskLevelRelationship")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskLevelRelationship( get_string( tmp ));
                 continue;
              }
              if(name == "TaskList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getTaskList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
              if(name == "CostMatrix")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getCostMatrix().push_back( (uxas::messages::task::TaskOptionCost*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskOptionCost"){
           TaskOptionCost* o = new TaskOptionCost();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "IntialTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setIntialTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "IntialTaskOption")
              {
                 Node* tmp = el->getChild(i);
                 o->setIntialTaskOption( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationTaskOption")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationTaskOption( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeToGo")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeToGo( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskAssignment"){
           TaskAssignment* o = new TaskAssignment();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "OptionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setOptionID( get_int64( tmp ));
                 continue;
              }
              if(name == "AssignedVehicle")
              {
                 Node* tmp = el->getChild(i);
                 o->setAssignedVehicle( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeThreshold")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeThreshold( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeTaskCompleted")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeTaskCompleted( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskAssignmentSummary"){
           TaskAssignmentSummary* o = new TaskAssignmentSummary();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CorrespondingAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCorrespondingAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getTaskList().push_back( (uxas::messages::task::TaskAssignment*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskOption"){
           TaskOption* o = new TaskOption();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "OptionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setOptionID( get_int64( tmp ));
                 continue;
              }
              if(name == "EligibleEntities")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEligibleEntities().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "Cost")
              {
                 Node* tmp = el->getChild(i);
                 o->setCost( get_int64( tmp ));
                 continue;
              }
              if(name == "StartLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStartLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "StartHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartHeading( get_real32( tmp ));
                 continue;
              }
              if(name == "EndLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setEndLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "EndHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setEndHeading( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskPlanOptions"){
           TaskPlanOptions* o = new TaskPlanOptions();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CorrespondingAutomationRequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCorrespondingAutomationRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "Composition")
              {
                 Node* tmp = el->getChild(i);
                 o->setComposition( get_string( tmp ));
                 continue;
              }
              if(name == "Options")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getOptions().push_back( (uxas::messages::task::TaskOption*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskPause"){
           TaskPause* o = new TaskPause();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskResume"){
           TaskResume* o = new TaskResume();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "RestartCompletely")
              {
                 Node* tmp = el->getChild(i);
                 o->setRestartCompletely( get_bool( tmp ));
                 continue;
              }
              if(name == "ReAssign")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setReAssign((uxas::messages::task::TaskAssignment*) oo );
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskProgress"){
           TaskProgress* o = new TaskProgress();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "PercentComplete")
              {
                 Node* tmp = el->getChild(i);
                 o->setPercentComplete( get_real32( tmp ));
                 continue;
              }
              if(name == "EntitiesEngaged")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEntitiesEngaged().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskProgressRequest"){
           TaskProgressRequest* o = new TaskProgressRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskInitialized"){
           TaskInitialized* o = new TaskInitialized();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskActive"){
           TaskActive* o = new TaskActive();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeTaskActivated")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeTaskActivated( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskComplete"){
           TaskComplete* o = new TaskComplete();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "EntitiesInvolved")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEntitiesInvolved().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "TimeTaskCompleted")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeTaskCompleted( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "CancelTask"){
           CancelTask* o = new CancelTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Vehicles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVehicles().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "CanceledTasks")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getCanceledTasks().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }


         return NULL;
        
    }

} // end namespace task
} // end namespace messages
} // end namespace uxas

