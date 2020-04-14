// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/impact/IMPACTXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

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


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace afrl {
namespace impact {


    avtas::lmcp::Object* IMPACTXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "PowerConfiguration"){
           PowerConfiguration* o = new PowerConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "NominalPowerConfiguration")
              {
                 Node* tmp = el->getChild(i);
                 o->setNominalPowerConfiguration( afrl::impact::PowerPlant::get_PowerPlant( get_string( tmp )));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
                 continue;
              }
              if(name == "PayloadKind")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadKind( get_string( tmp ));
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
           }
           return o;
        }
        if (type == "RadioConfiguration"){
           RadioConfiguration* o = new RadioConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Range")
              {
                 Node* tmp = el->getChild(i);
                 o->setRange( get_real32( tmp ));
                 continue;
              }
              if(name == "RallyPoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setRallyPoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Timeout")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeout( get_int64( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
                 continue;
              }
              if(name == "PayloadKind")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadKind( get_string( tmp ));
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
           }
           return o;
        }
        if (type == "RadioTowerConfiguration"){
           RadioTowerConfiguration* o = new RadioTowerConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Position")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setPosition((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Range")
              {
                 Node* tmp = el->getChild(i);
                 o->setRange( get_real32( tmp ));
                 continue;
              }
              if(name == "Enabled")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnabled( get_bool( tmp ));
                 continue;
              }
              if(name == "ID")
              {
                 Node* tmp = el->getChild(i);
                 o->setID( get_int64( tmp ));
                 continue;
              }
              if(name == "Affiliation")
              {
                 Node* tmp = el->getChild(i);
                 o->setAffiliation( get_string( tmp ));
                 continue;
              }
              if(name == "EntityType")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityType( get_string( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
              if(name == "NominalSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setNominalSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "NominalAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setNominalAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "NominalAltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setNominalAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
                 continue;
              }
              if(name == "PayloadConfigurationList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPayloadConfigurationList().push_back( (afrl::cmasi::PayloadConfiguration*) oo);
                 }
                 continue;
              }
              if(name == "Info")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getInfo().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RadioState"){
           RadioState* o = new RadioState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Enabled")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnabled( get_bool( tmp ));
                 continue;
              }
              if(name == "InRange")
              {
                 Node* tmp = el->getChild(i);
                 o->setInRange( get_bool( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
           }
           return o;
        }
        if (type == "RadioTowerState"){
           RadioTowerState* o = new RadioTowerState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Enabled")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnabled( get_bool( tmp ));
                 continue;
              }
              if(name == "ID")
              {
                 Node* tmp = el->getChild(i);
                 o->setID( get_int64( tmp ));
                 continue;
              }
              if(name == "u")
              {
                 Node* tmp = el->getChild(i);
                 o->setU( get_real32( tmp ));
                 continue;
              }
              if(name == "v")
              {
                 Node* tmp = el->getChild(i);
                 o->setV( get_real32( tmp ));
                 continue;
              }
              if(name == "w")
              {
                 Node* tmp = el->getChild(i);
                 o->setW( get_real32( tmp ));
                 continue;
              }
              if(name == "udot")
              {
                 Node* tmp = el->getChild(i);
                 o->setUdot( get_real32( tmp ));
                 continue;
              }
              if(name == "vdot")
              {
                 Node* tmp = el->getChild(i);
                 o->setVdot( get_real32( tmp ));
                 continue;
              }
              if(name == "wdot")
              {
                 Node* tmp = el->getChild(i);
                 o->setWdot( get_real32( tmp ));
                 continue;
              }
              if(name == "Heading")
              {
                 Node* tmp = el->getChild(i);
                 o->setHeading( get_real32( tmp ));
                 continue;
              }
              if(name == "Pitch")
              {
                 Node* tmp = el->getChild(i);
                 o->setPitch( get_real32( tmp ));
                 continue;
              }
              if(name == "Roll")
              {
                 Node* tmp = el->getChild(i);
                 o->setRoll( get_real32( tmp ));
                 continue;
              }
              if(name == "p")
              {
                 Node* tmp = el->getChild(i);
                 o->setP( get_real32( tmp ));
                 continue;
              }
              if(name == "q")
              {
                 Node* tmp = el->getChild(i);
                 o->setQ( get_real32( tmp ));
                 continue;
              }
              if(name == "r")
              {
                 Node* tmp = el->getChild(i);
                 o->setR( get_real32( tmp ));
                 continue;
              }
              if(name == "Course")
              {
                 Node* tmp = el->getChild(i);
                 o->setCourse( get_real32( tmp ));
                 continue;
              }
              if(name == "Groundspeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundspeed( get_real32( tmp ));
                 continue;
              }
              if(name == "Location")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "EnergyAvailable")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnergyAvailable( get_real32( tmp ));
                 continue;
              }
              if(name == "ActualEnergyRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setActualEnergyRate( get_real32( tmp ));
                 continue;
              }
              if(name == "PayloadStateList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPayloadStateList().push_back( (afrl::cmasi::PayloadState*) oo);
                 }
                 continue;
              }
              if(name == "CurrentWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setCurrentWaypoint( get_int64( tmp ));
                 continue;
              }
              if(name == "CurrentCommand")
              {
                 Node* tmp = el->getChild(i);
                 o->setCurrentCommand( get_int64( tmp ));
                 continue;
              }
              if(name == "Mode")
              {
                 Node* tmp = el->getChild(i);
                 o->setMode( afrl::cmasi::NavigationMode::get_NavigationMode( get_string( tmp )));
                 continue;
              }
              if(name == "AssociatedTasks")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAssociatedTasks().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "Time")
              {
                 Node* tmp = el->getChild(i);
                 o->setTime( get_int64( tmp ));
                 continue;
              }
              if(name == "Info")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getInfo().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "ImpactPayloadConfiguration"){
           ImpactPayloadConfiguration* o = new ImpactPayloadConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AvailablePayloads")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAvailablePayloads().push_back( afrl::impact::ImpactPayloadType::get_ImpactPayloadType(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
                 continue;
              }
              if(name == "PayloadKind")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadKind( get_string( tmp ));
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
           }
           return o;
        }
        if (type == "DeployImpactPayload"){
           DeployImpactPayload* o = new DeployImpactPayload();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "DeployedPayload")
              {
                 Node* tmp = el->getChild(i);
                 o->setDeployedPayload( afrl::impact::ImpactPayloadType::get_ImpactPayloadType( get_string( tmp )));
                 continue;
              }
              if(name == "TargetEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTargetEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "AssociatedTaskList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAssociatedTaskList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "PowerPlantState"){
           PowerPlantState* o = new PowerPlantState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ActivePowerPlant")
              {
                 Node* tmp = el->getChild(i);
                 o->setActivePowerPlant( afrl::impact::PowerPlant::get_PowerPlant( get_string( tmp )));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
           }
           return o;
        }
        if (type == "BatchRoutePlanRequest"){
           BatchRoutePlanRequest* o = new BatchRoutePlanRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "Vehicles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVehicles().push_back( get_int64( tmp->getChild(j)));
                 }
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
              if(name == "ComputeTaskToTaskTiming")
              {
                 Node* tmp = el->getChild(i);
                 o->setComputeTaskToTaskTiming( get_bool( tmp ));
                 continue;
              }
              if(name == "ComputeInterTaskToTaskTiming")
              {
                 Node* tmp = el->getChild(i);
                 o->setComputeInterTaskToTaskTiming( get_bool( tmp ));
                 continue;
              }
              if(name == "InterTaskPercentage")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getInterTaskPercentage().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "BatchRoutePlanResponse"){
           BatchRoutePlanResponse* o = new BatchRoutePlanResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleTiming")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleTiming().push_back( (afrl::impact::TaskTimingPair*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskTimingPair"){
           TaskTimingPair* o = new TaskTimingPair();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "InitialTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setInitialTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "InitialTaskPercentage")
              {
                 Node* tmp = el->getChild(i);
                 o->setInitialTaskPercentage( get_real32( tmp ));
                 continue;
              }
              if(name == "DestinationTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationTaskID( get_int64( tmp ));
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
        if (type == "BatchSummaryRequest"){
           BatchSummaryRequest* o = new BatchSummaryRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "Vehicles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVehicles().push_back( get_int64( tmp->getChild(j)));
                 }
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
              if(name == "TaskRelationships")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskRelationships( get_string( tmp ));
                 continue;
              }
              if(name == "InterTaskPercentage")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getInterTaskPercentage().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "BatchSummaryResponse"){
           BatchSummaryResponse* o = new BatchSummaryResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "Summaries")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getSummaries().push_back( (afrl::impact::TaskSummary*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "TaskSummary"){
           TaskSummary* o = new TaskSummary();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "PerformingVehicles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPerformingVehicles().push_back( (afrl::impact::VehicleSummary*) oo);
                 }
                 continue;
              }
              if(name == "BestEffort")
              {
                 Node* tmp = el->getChild(i);
                 o->setBestEffort( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "VehicleSummary"){
           VehicleSummary* o = new VehicleSummary();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "InitialTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setInitialTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "InitialTaskPercentage")
              {
                 Node* tmp = el->getChild(i);
                 o->setInitialTaskPercentage( get_real32( tmp ));
                 continue;
              }
              if(name == "EstimateTimeToTaskPercentage")
              {
                 Node* tmp = el->getChild(i);
                 o->setEstimateTimeToTaskPercentage( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeToArrive")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeToArrive( get_int64( tmp ));
                 continue;
              }
              if(name == "TimeOnTask")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeOnTask( get_int64( tmp ));
                 continue;
              }
              if(name == "EnergyRemaining")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnergyRemaining( get_real32( tmp ));
                 continue;
              }
              if(name == "BeyondCommRange")
              {
                 Node* tmp = el->getChild(i);
                 o->setBeyondCommRange( get_bool( tmp ));
                 continue;
              }
              if(name == "ConflictsWithROZ")
              {
                 Node* tmp = el->getChild(i);
                 o->setConflictsWithROZ( get_bool( tmp ));
                 continue;
              }
              if(name == "ROZIDs")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getROZIDs().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "WaypointList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getWaypointList().push_back( (afrl::cmasi::Waypoint*) oo);
                 }
                 continue;
              }
              if(name == "FirstWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setFirstWaypoint( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SpeedAltPair"){
           SpeedAltPair* o = new SpeedAltPair();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "TaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "Altitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "AltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "ImpactAutomationRequest"){
           ImpactAutomationRequest* o = new ImpactAutomationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "TrialRequest")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setTrialRequest((afrl::cmasi::AutomationRequest*) oo );
                 continue;
              }
              if(name == "OverridePlanningConditions")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getOverridePlanningConditions().push_back( (afrl::impact::SpeedAltPair*) oo);
                 }
                 continue;
              }
              if(name == "PlayID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPlayID( get_int64( tmp ));
                 continue;
              }
              if(name == "SolutionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSolutionID( get_int64( tmp ));
                 continue;
              }
              if(name == "Sandbox")
              {
                 Node* tmp = el->getChild(i);
                 o->setSandbox( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "ImpactAutomationResponse"){
           ImpactAutomationResponse* o = new ImpactAutomationResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "TrialResponse")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setTrialResponse((afrl::cmasi::AutomationResponse*) oo );
                 continue;
              }
              if(name == "PlayID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPlayID( get_int64( tmp ));
                 continue;
              }
              if(name == "SolutionID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSolutionID( get_int64( tmp ));
                 continue;
              }
              if(name == "Sandbox")
              {
                 Node* tmp = el->getChild(i);
                 o->setSandbox( get_bool( tmp ));
                 continue;
              }
              if(name == "Summaries")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getSummaries().push_back( (afrl::impact::TaskSummary*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "PointOfInterest"){
           PointOfInterest* o = new PointOfInterest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PointID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointID( get_int64( tmp ));
                 continue;
              }
              if(name == "Location")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "PointAction")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointAction( afrl::impact::AreaActionOptions::get_AreaActionOptions( get_string( tmp )));
                 continue;
              }
              if(name == "PointLabel")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointLabel( get_string( tmp ));
                 continue;
              }
              if(name == "BackgroundBehaviorPoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setBackgroundBehaviorPoint( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "LineOfInterest"){
           LineOfInterest* o = new LineOfInterest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "LineID")
              {
                 Node* tmp = el->getChild(i);
                 o->setLineID( get_int64( tmp ));
                 continue;
              }
              if(name == "Line")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getLine().push_back( (afrl::cmasi::Location3D*) oo);
                 }
                 continue;
              }
              if(name == "LineAction")
              {
                 Node* tmp = el->getChild(i);
                 o->setLineAction( afrl::impact::AreaActionOptions::get_AreaActionOptions( get_string( tmp )));
                 continue;
              }
              if(name == "LineLabel")
              {
                 Node* tmp = el->getChild(i);
                 o->setLineLabel( get_string( tmp ));
                 continue;
              }
              if(name == "BackgroundBehaviorLine")
              {
                 Node* tmp = el->getChild(i);
                 o->setBackgroundBehaviorLine( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "AreaOfInterest"){
           AreaOfInterest* o = new AreaOfInterest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AreaID")
              {
                 Node* tmp = el->getChild(i);
                 o->setAreaID( get_int64( tmp ));
                 continue;
              }
              if(name == "Area")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setArea((afrl::cmasi::AbstractGeometry*) oo );
                 continue;
              }
              if(name == "AreaAction")
              {
                 Node* tmp = el->getChild(i);
                 o->setAreaAction( afrl::impact::AreaActionOptions::get_AreaActionOptions( get_string( tmp )));
                 continue;
              }
              if(name == "AreaLabel")
              {
                 Node* tmp = el->getChild(i);
                 o->setAreaLabel( get_string( tmp ));
                 continue;
              }
              if(name == "BackgroundBehaviorArea")
              {
                 Node* tmp = el->getChild(i);
                 o->setBackgroundBehaviorArea( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "ImpactPointSearchTask"){
           ImpactPointSearchTask* o = new ImpactPointSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SearchLocationID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSearchLocationID( get_int64( tmp ));
                 continue;
              }
              if(name == "SearchLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setSearchLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "StandoffDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setStandoffDistance( get_real32( tmp ));
                 continue;
              }
              if(name == "ViewAngleList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getViewAngleList().push_back( (afrl::cmasi::Wedge*) oo);
                 }
                 continue;
              }
              if(name == "DesiredAction")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setDesiredAction((afrl::cmasi::LoiterAction*) oo );
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "PatternSearchTask"){
           PatternSearchTask* o = new PatternSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SearchLocationID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSearchLocationID( get_int64( tmp ));
                 continue;
              }
              if(name == "SearchLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setSearchLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Pattern")
              {
                 Node* tmp = el->getChild(i);
                 o->setPattern( afrl::impact::AreaSearchPattern::get_AreaSearchPattern( get_string( tmp )));
                 continue;
              }
              if(name == "Extent")
              {
                 Node* tmp = el->getChild(i);
                 o->setExtent( get_real32( tmp ));
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "AngledAreaSearchTask"){
           AngledAreaSearchTask* o = new AngledAreaSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SearchAreaID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSearchAreaID( get_int64( tmp ));
                 continue;
              }
              if(name == "SweepAngle")
              {
                 Node* tmp = el->getChild(i);
                 o->setSweepAngle( get_real32( tmp ));
                 continue;
              }
              if(name == "StartPoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStartPoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "ImpactLineSearchTask"){
           ImpactLineSearchTask* o = new ImpactLineSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "LineID")
              {
                 Node* tmp = el->getChild(i);
                 o->setLineID( get_int64( tmp ));
                 continue;
              }
              if(name == "ViewAngleList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getViewAngleList().push_back( (afrl::cmasi::Wedge*) oo);
                 }
                 continue;
              }
              if(name == "UseInertialViewAngles")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseInertialViewAngles( get_bool( tmp ));
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "WatchTask"){
           WatchTask* o = new WatchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "WatchedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setWatchedEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "MultiVehicleWatchTask"){
           MultiVehicleWatchTask* o = new MultiVehicleWatchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "WatchedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setWatchedEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "NumberVehicles")
              {
                 Node* tmp = el->getChild(i);
                 o->setNumberVehicles( get_byte( tmp ));
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "CommRelayTask"){
           CommRelayTask* o = new CommRelayTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SupportedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSupportedEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setDestinationLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "TowerID")
              {
                 Node* tmp = el->getChild(i);
                 o->setTowerID( get_int64( tmp ));
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
        if (type == "CordonTask"){
           CordonTask* o = new CordonTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CordonLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setCordonLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "StandoffDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setStandoffDistance( get_real32( tmp ));
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
        if (type == "BlockadeTask"){
           BlockadeTask* o = new BlockadeTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "BlockedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setBlockedEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "StandoffDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setStandoffDistance( get_real32( tmp ));
                 continue;
              }
              if(name == "NumberVehicles")
              {
                 Node* tmp = el->getChild(i);
                 o->setNumberVehicles( get_byte( tmp ));
                 continue;
              }
              if(name == "ProtectedLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setProtectedLocation((afrl::cmasi::Location3D*) oo );
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
        if (type == "EscortTask"){
           EscortTask* o = new EscortTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SupportedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSupportedEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "RouteID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRouteID( get_int64( tmp ));
                 continue;
              }
              if(name == "PrescribedWaypoints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPrescribedWaypoints().push_back( (afrl::cmasi::Waypoint*) oo);
                 }
                 continue;
              }
              if(name == "StandoffDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setStandoffDistance( get_real32( tmp ));
                 continue;
              }
              if(name == "DesiredWavelengthBands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDesiredWavelengthBands().push_back( afrl::cmasi::WavelengthBand::get_WavelengthBand(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "DwellTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setDwellTime( get_int64( tmp ));
                 continue;
              }
              if(name == "GroundSampleDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setGroundSampleDistance( get_real32( tmp ));
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
        if (type == "ConfigurationRequest"){
           ConfigurationRequest* o = new ConfigurationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVehicleID().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "WaterReport"){
           WaterReport* o = new WaterReport();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Area")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setArea((afrl::cmasi::AbstractGeometry*) oo );
                 continue;
              }
              if(name == "CurrentSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setCurrentSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "CurrentDirection")
              {
                 Node* tmp = el->getChild(i);
                 o->setCurrentDirection( get_real32( tmp ));
                 continue;
              }
              if(name == "WaveDirection")
              {
                 Node* tmp = el->getChild(i);
                 o->setWaveDirection( get_real32( tmp ));
                 continue;
              }
              if(name == "WaveHeight")
              {
                 Node* tmp = el->getChild(i);
                 o->setWaveHeight( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "WaterZone"){
           WaterZone* o = new WaterZone();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ZoneID")
              {
                 Node* tmp = el->getChild(i);
                 o->setZoneID( get_int64( tmp ));
                 continue;
              }
              if(name == "MinAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "MinAltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
                 continue;
              }
              if(name == "MaxAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxAltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
                 continue;
              }
              if(name == "AffectedAircraft")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAffectedAircraft().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "StartTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartTime( get_int64( tmp ));
                 continue;
              }
              if(name == "EndTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setEndTime( get_int64( tmp ));
                 continue;
              }
              if(name == "Padding")
              {
                 Node* tmp = el->getChild(i);
                 o->setPadding( get_real32( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
              if(name == "Boundary")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setBoundary((afrl::cmasi::AbstractGeometry*) oo );
                 continue;
              }
           }
           return o;
        }
        if (type == "PayloadDropTask"){
           PayloadDropTask* o = new PayloadDropTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "DropLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setDropLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "BDALocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setBDALocation((afrl::cmasi::Location3D*) oo );
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


         return NULL;
        
    }

} // end namespace impact
} // end namespace afrl

