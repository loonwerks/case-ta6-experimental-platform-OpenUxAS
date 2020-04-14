// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/uxnative/UXNATIVEXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

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


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace uxas {
namespace messages {
namespace uxnative {


    avtas::lmcp::Object* UXNATIVEXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "VideoRecord"){
           VideoRecord* o = new VideoRecord();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Record")
              {
                 Node* tmp = el->getChild(i);
                 o->setRecord( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "StartupComplete"){
           StartupComplete* o = new StartupComplete();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
           }
           return o;
        }
        if (type == "CreateNewService"){
           CreateNewService* o = new CreateNewService();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ServiceID")
              {
                 Node* tmp = el->getChild(i);
                 o->setServiceID( get_int64( tmp ));
                 continue;
              }
              if(name == "XmlConfiguration")
              {
                 Node* tmp = el->getChild(i);
                 o->setXmlConfiguration( get_string( tmp ));
                 continue;
              }
              if(name == "EntityConfigurations")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getEntityConfigurations().push_back( (afrl::cmasi::EntityConfiguration*) oo);
                 }
                 continue;
              }
              if(name == "EntityStates")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getEntityStates().push_back( (afrl::cmasi::EntityState*) oo);
                 }
                 continue;
              }
              if(name == "MissionCommands")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getMissionCommands().push_back( (afrl::cmasi::MissionCommand*) oo);
                 }
                 continue;
              }
              if(name == "Areas")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getAreas().push_back( (afrl::impact::AreaOfInterest*) oo);
                 }
                 continue;
              }
              if(name == "Lines")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getLines().push_back( (afrl::impact::LineOfInterest*) oo);
                 }
                 continue;
              }
              if(name == "Points")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPoints().push_back( (afrl::impact::PointOfInterest*) oo);
                 }
                 continue;
              }
              if(name == "KeepInZones")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getKeepInZones().push_back( (afrl::cmasi::KeepInZone*) oo);
                 }
                 continue;
              }
              if(name == "KeepOutZones")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getKeepOutZones().push_back( (afrl::cmasi::KeepOutZone*) oo);
                 }
                 continue;
              }
              if(name == "OperatingRegions")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getOperatingRegions().push_back( (afrl::cmasi::OperatingRegion*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "KillService"){
           KillService* o = new KillService();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ServiceID")
              {
                 Node* tmp = el->getChild(i);
                 o->setServiceID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "IncrementWaypoint"){
           IncrementWaypoint* o = new IncrementWaypoint();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SafeHeadingAction"){
           SafeHeadingAction* o = new SafeHeadingAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
              if(name == "LeadAheadDistance")
              {
                 Node* tmp = el->getChild(i);
                 o->setLeadAheadDistance( get_real32( tmp ));
                 continue;
              }
              if(name == "LoiterRadius")
              {
                 Node* tmp = el->getChild(i);
                 o->setLoiterRadius( get_real32( tmp ));
                 continue;
              }
              if(name == "DesiredHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setDesiredHeading( get_real32( tmp ));
                 continue;
              }
              if(name == "DesiredHeadingRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setDesiredHeadingRate( get_real32( tmp ));
                 continue;
              }
              if(name == "UseHeadingRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseHeadingRate( get_bool( tmp ));
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
              if(name == "UseAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseAltitude( get_bool( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "UseSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseSpeed( get_bool( tmp ));
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
        if (type == "EntityLocation"){
           EntityLocation* o = new EntityLocation();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Position")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setPosition((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Time")
              {
                 Node* tmp = el->getChild(i);
                 o->setTime( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "BandwidthTest"){
           BandwidthTest* o = new BandwidthTest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "MessageID")
              {
                 Node* tmp = el->getChild(i);
                 o->setMessageID( get_int64( tmp ));
                 continue;
              }
              if(name == "Payload")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayload( get_string( tmp ));
                 continue;
              }
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Position")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setPosition((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Time")
              {
                 Node* tmp = el->getChild(i);
                 o->setTime( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "BandwidthReceiveReport"){
           BandwidthReceiveReport* o = new BandwidthReceiveReport();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntitySender")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setEntitySender((uxas::messages::uxnative::EntityLocation*) oo );
                 continue;
              }
              if(name == "EntityReceiver")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setEntityReceiver((uxas::messages::uxnative::EntityLocation*) oo );
                 continue;
              }
              if(name == "TransferPayloadSize")
              {
                 Node* tmp = el->getChild(i);
                 o->setTransferPayloadSize( get_uint32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SubTaskExecution"){
           SubTaskExecution* o = new SubTaskExecution();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SubTasks")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getSubTasks().push_back( (afrl::cmasi::Task*) oo);
                 }
                 continue;
              }
              if(name == "StrictOrder")
              {
                 Node* tmp = el->getChild(i);
                 o->setStrictOrder( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SubTaskAssignment"){
           SubTaskAssignment* o = new SubTaskAssignment();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SubTasks")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getSubTasks().push_back( (afrl::cmasi::Task*) oo);
                 }
                 continue;
              }
              if(name == "Neighbors")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getNeighbors().push_back( (afrl::cmasi::EntityState*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "AutopilotKeepAlive"){
           AutopilotKeepAlive* o = new AutopilotKeepAlive();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AutopilotEnabled")
              {
                 Node* tmp = el->getChild(i);
                 o->setAutopilotEnabled( get_bool( tmp ));
                 continue;
              }
              if(name == "SpeedAuthorized")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedAuthorized( get_bool( tmp ));
                 continue;
              }
              if(name == "GimbalEnabled")
              {
                 Node* tmp = el->getChild(i);
                 o->setGimbalEnabled( get_bool( tmp ));
                 continue;
              }
              if(name == "TimeSent")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeSent( get_int64( tmp ));
                 continue;
              }
              if(name == "SpeedOverride")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedOverride( get_real32( tmp ));
                 continue;
              }
              if(name == "AltOverride")
              {
                 Node* tmp = el->getChild(i);
                 o->setAltOverride( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "OnboardStatusReport"){
           OnboardStatusReport* o = new OnboardStatusReport();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "ConnectedEntities")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getConnectedEntities().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "CurrentTaskList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getCurrentTaskList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "ValidState")
              {
                 Node* tmp = el->getChild(i);
                 o->setValidState( get_bool( tmp ));
                 continue;
              }
              if(name == "ValidAuthorization")
              {
                 Node* tmp = el->getChild(i);
                 o->setValidAuthorization( get_bool( tmp ));
                 continue;
              }
              if(name == "SpeedAuthorization")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedAuthorization( get_bool( tmp ));
                 continue;
              }
              if(name == "GimbalAuthorization")
              {
                 Node* tmp = el->getChild(i);
                 o->setGimbalAuthorization( get_bool( tmp ));
                 continue;
              }
              if(name == "VehicleTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleTime( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "EntityJoin"){
           EntityJoin* o = new EntityJoin();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "EntityExit"){
           EntityExit* o = new EntityExit();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Label")
              {
                 Node* tmp = el->getChild(i);
                 o->setLabel( get_string( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SimulationTimeStepAcknowledgement"){
           SimulationTimeStepAcknowledgement* o = new SimulationTimeStepAcknowledgement();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "ReportedTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setReportedTime( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "SpeedOverrideAction"){
           SpeedOverrideAction* o = new SpeedOverrideAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
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
        if (type == "ZeroizeCommand"){
           ZeroizeCommand* o = new ZeroizeCommand();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "ZeroizeKeys")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeKeys( get_bool( tmp ));
                 continue;
              }
              if(name == "ZeroizeLogs")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeLogs( get_bool( tmp ));
                 continue;
              }
              if(name == "ZeroizeData")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeData( get_bool( tmp ));
                 continue;
              }
              if(name == "ZeroizeTasks")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeTasks( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "ZeroizeCondition"){
           ZeroizeCondition* o = new ZeroizeCondition();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "ZeroizeOnLanding")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeOnLanding( get_bool( tmp ));
                 continue;
              }
              if(name == "ZeroizeOnExitingOperationalArea")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeOnExitingOperationalArea( get_bool( tmp ));
                 continue;
              }
              if(name == "ActiveOperationalArea")
              {
                 Node* tmp = el->getChild(i);
                 o->setActiveOperationalArea( get_int64( tmp ));
                 continue;
              }
              if(name == "ZeroizeOnTasksComplete")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeOnTasksComplete( get_bool( tmp ));
                 continue;
              }
              if(name == "ZeroizeAccumulationTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeAccumulationTime( get_int64( tmp ));
                 continue;
              }
              if(name == "ZeroizeHoldoffTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setZeroizeHoldoffTime( get_int64( tmp ));
                 continue;
              }
              if(name == "KeepInZones")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getKeepInZones().push_back( (afrl::cmasi::KeepInZone*) oo);
                 }
                 continue;
              }
              if(name == "KeepOutZones")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getKeepOutZones().push_back( (afrl::cmasi::KeepOutZone*) oo);
                 }
                 continue;
              }
              if(name == "OperationalAreas")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getOperationalAreas().push_back( (afrl::cmasi::OperatingRegion*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "DownloadRequest"){
           DownloadRequest* o = new DownloadRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestedLmcpTypeName")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestedLmcpTypeName( get_string( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "DownloadReply"){
           DownloadReply* o = new DownloadReply();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Contents")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getContents().push_back( (avtas::lmcp::Object*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "FileTransferRequest"){
           FileTransferRequest* o = new FileTransferRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Nonce")
              {
                 Node* tmp = el->getChild(i);
                 o->setNonce( get_int64( tmp ));
                 continue;
              }
              if(name == "SourceEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSourceEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "FileNames")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getFileNames().push_back( get_string( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "File"){
           File* o = new File();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "FileName")
              {
                 Node* tmp = el->getChild(i);
                 o->setFileName( get_string( tmp ));
                 continue;
              }
              if(name == "FileContents")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getFileContents().push_back( get_byte( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "FileTransfer"){
           FileTransfer* o = new FileTransfer();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Nonce")
              {
                 Node* tmp = el->getChild(i);
                 o->setNonce( get_int64( tmp ));
                 continue;
              }
              if(name == "DestinationEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setDestinationEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Files")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFiles().push_back( (uxas::messages::uxnative::File*) oo);
                 }
                 continue;
              }
           }
           return o;
        }


         return NULL;
        
    }

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

