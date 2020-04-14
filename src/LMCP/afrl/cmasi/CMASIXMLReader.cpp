// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/cmasi/CMASIXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

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


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace afrl {
namespace cmasi {


    avtas::lmcp::Object* CMASIXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "AbstractGeometry"){
           AbstractGeometry* o = new AbstractGeometry();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
           }
           return o;
        }
        if (type == "KeyValuePair"){
           KeyValuePair* o = new KeyValuePair();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Key")
              {
                 Node* tmp = el->getChild(i);
                 o->setKey( get_string( tmp ));
                 continue;
              }
              if(name == "Value")
              {
                 Node* tmp = el->getChild(i);
                 o->setValue( get_string( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "Location3D"){
           Location3D* o = new Location3D();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Latitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLatitude( get_real64( tmp ));
                 continue;
              }
              if(name == "Longitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLongitude( get_real64( tmp ));
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
        if (type == "PayloadAction"){
           PayloadAction* o = new PayloadAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
        if (type == "PayloadConfiguration"){
           PayloadConfiguration* o = new PayloadConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "PayloadState"){
           PayloadState* o = new PayloadState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "VehicleAction"){
           VehicleAction* o = new VehicleAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "Task"){
           Task* o = new Task();
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
        if (type == "SearchTask"){
           SearchTask* o = new SearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "AbstractZone"){
           AbstractZone* o = new AbstractZone();
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
        if (type == "EntityConfiguration"){
           EntityConfiguration* o = new EntityConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "FlightProfile"){
           FlightProfile* o = new FlightProfile();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Name")
              {
                 Node* tmp = el->getChild(i);
                 o->setName( get_string( tmp ));
                 continue;
              }
              if(name == "Airspeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setAirspeed( get_real32( tmp ));
                 continue;
              }
              if(name == "PitchAngle")
              {
                 Node* tmp = el->getChild(i);
                 o->setPitchAngle( get_real32( tmp ));
                 continue;
              }
              if(name == "VerticalSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setVerticalSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxBankAngle")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxBankAngle( get_real32( tmp ));
                 continue;
              }
              if(name == "EnergyRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnergyRate( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "AirVehicleConfiguration"){
           AirVehicleConfiguration* o = new AirVehicleConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "MinimumSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinimumSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "MaximumSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaximumSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "NominalFlightProfile")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setNominalFlightProfile((afrl::cmasi::FlightProfile*) oo );
                 continue;
              }
              if(name == "AlternateFlightProfiles")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getAlternateFlightProfiles().push_back( (afrl::cmasi::FlightProfile*) oo);
                 }
                 continue;
              }
              if(name == "AvailableLoiterTypes")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAvailableLoiterTypes().push_back( afrl::cmasi::LoiterType::get_LoiterType(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "AvailableTurnTypes")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAvailableTurnTypes().push_back( afrl::cmasi::TurnType::get_TurnType(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "MinimumAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinimumAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "MinAltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
                 continue;
              }
              if(name == "MaximumAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaximumAltitude( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxAltitudeType")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxAltitudeType( afrl::cmasi::AltitudeType::get_AltitudeType( get_string( tmp )));
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
        if (type == "EntityState"){
           EntityState* o = new EntityState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "AirVehicleState"){
           AirVehicleState* o = new AirVehicleState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Airspeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setAirspeed( get_real32( tmp ));
                 continue;
              }
              if(name == "VerticalSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setVerticalSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "WindSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setWindSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "WindDirection")
              {
                 Node* tmp = el->getChild(i);
                 o->setWindDirection( get_real32( tmp ));
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
        if (type == "Wedge"){
           Wedge* o = new Wedge();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AzimuthCenterline")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuthCenterline( get_real32( tmp ));
                 continue;
              }
              if(name == "VerticalCenterline")
              {
                 Node* tmp = el->getChild(i);
                 o->setVerticalCenterline( get_real32( tmp ));
                 continue;
              }
              if(name == "AzimuthExtent")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuthExtent( get_real32( tmp ));
                 continue;
              }
              if(name == "VerticalExtent")
              {
                 Node* tmp = el->getChild(i);
                 o->setVerticalExtent( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "AreaSearchTask"){
           AreaSearchTask* o = new AreaSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SearchArea")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setSearchArea((afrl::cmasi::AbstractGeometry*) oo );
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
        if (type == "CameraAction"){
           CameraAction* o = new CameraAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "HorizontalFieldOfView")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalFieldOfView( get_real32( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
        if (type == "CameraConfiguration"){
           CameraConfiguration* o = new CameraConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SupportedWavelengthBand")
              {
                 Node* tmp = el->getChild(i);
                 o->setSupportedWavelengthBand( afrl::cmasi::WavelengthBand::get_WavelengthBand( get_string( tmp )));
                 continue;
              }
              if(name == "FieldOfViewMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setFieldOfViewMode( afrl::cmasi::FOVOperationMode::get_FOVOperationMode( get_string( tmp )));
                 continue;
              }
              if(name == "MinHorizontalFieldOfView")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinHorizontalFieldOfView( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxHorizontalFieldOfView")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxHorizontalFieldOfView( get_real32( tmp ));
                 continue;
              }
              if(name == "DiscreteHorizontalFieldOfViewList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getDiscreteHorizontalFieldOfViewList().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "VideoStreamHorizontalResolution")
              {
                 Node* tmp = el->getChild(i);
                 o->setVideoStreamHorizontalResolution( get_uint32( tmp ));
                 continue;
              }
              if(name == "VideoStreamVerticalResolution")
              {
                 Node* tmp = el->getChild(i);
                 o->setVideoStreamVerticalResolution( get_uint32( tmp ));
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
        if (type == "GimballedPayloadState"){
           GimballedPayloadState* o = new GimballedPayloadState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PointingMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointingMode( afrl::cmasi::GimbalPointingMode::get_GimbalPointingMode( get_string( tmp )));
                 continue;
              }
              if(name == "Azimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "Elevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "Rotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setRotation( get_real32( tmp ));
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
        if (type == "CameraState"){
           CameraState* o = new CameraState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "HorizontalFieldOfView")
              {
                 Node* tmp = el->getChild(i);
                 o->setHorizontalFieldOfView( get_real32( tmp ));
                 continue;
              }
              if(name == "VerticalFieldOfView")
              {
                 Node* tmp = el->getChild(i);
                 o->setVerticalFieldOfView( get_real32( tmp ));
                 continue;
              }
              if(name == "Footprint")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getFootprint().push_back( (afrl::cmasi::Location3D*) oo);
                 }
                 continue;
              }
              if(name == "Centerpoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setCenterpoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "PointingMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointingMode( afrl::cmasi::GimbalPointingMode::get_GimbalPointingMode( get_string( tmp )));
                 continue;
              }
              if(name == "Azimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "Elevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "Rotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setRotation( get_real32( tmp ));
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
        if (type == "Circle"){
           Circle* o = new Circle();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CenterPoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setCenterPoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Radius")
              {
                 Node* tmp = el->getChild(i);
                 o->setRadius( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "GimbalAngleAction"){
           GimbalAngleAction* o = new GimbalAngleAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Azimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "Elevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "Rotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setRotation( get_real32( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
        if (type == "GimbalConfiguration"){
           GimbalConfiguration* o = new GimbalConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "SupportedPointingModes")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getSupportedPointingModes().push_back( afrl::cmasi::GimbalPointingMode::get_GimbalPointingMode(get_string( tmp->getChild(j))));
                 }
                 continue;
              }
              if(name == "MinAzimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxAzimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "IsAzimuthClamped")
              {
                 Node* tmp = el->getChild(i);
                 o->setIsAzimuthClamped( get_bool( tmp ));
                 continue;
              }
              if(name == "MinElevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxElevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "IsElevationClamped")
              {
                 Node* tmp = el->getChild(i);
                 o->setIsElevationClamped( get_bool( tmp ));
                 continue;
              }
              if(name == "MinRotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setMinRotation( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxRotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxRotation( get_real32( tmp ));
                 continue;
              }
              if(name == "IsRotationClamped")
              {
                 Node* tmp = el->getChild(i);
                 o->setIsRotationClamped( get_bool( tmp ));
                 continue;
              }
              if(name == "MaxAzimuthSlewRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxAzimuthSlewRate( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxElevationSlewRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxElevationSlewRate( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxRotationRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxRotationRate( get_real32( tmp ));
                 continue;
              }
              if(name == "ContainedPayloadList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getContainedPayloadList().push_back( get_int64( tmp->getChild(j)));
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
        if (type == "GimbalScanAction"){
           GimbalScanAction* o = new GimbalScanAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AzimuthSlewRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuthSlewRate( get_real32( tmp ));
                 continue;
              }
              if(name == "ElevationSlewRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setElevationSlewRate( get_real32( tmp ));
                 continue;
              }
              if(name == "StartAzimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "EndAzimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setEndAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "StartElevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "EndElevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setEndElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "Cycles")
              {
                 Node* tmp = el->getChild(i);
                 o->setCycles( get_uint32( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
        if (type == "GimbalStareAction"){
           GimbalStareAction* o = new GimbalStareAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Starepoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStarepoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Duration")
              {
                 Node* tmp = el->getChild(i);
                 o->setDuration( get_int64( tmp ));
                 continue;
              }
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
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
        if (type == "GimbalState"){
           GimbalState* o = new GimbalState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PointingMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setPointingMode( afrl::cmasi::GimbalPointingMode::get_GimbalPointingMode( get_string( tmp )));
                 continue;
              }
              if(name == "Azimuth")
              {
                 Node* tmp = el->getChild(i);
                 o->setAzimuth( get_real32( tmp ));
                 continue;
              }
              if(name == "Elevation")
              {
                 Node* tmp = el->getChild(i);
                 o->setElevation( get_real32( tmp ));
                 continue;
              }
              if(name == "Rotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setRotation( get_real32( tmp ));
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
        if (type == "GoToWaypointAction"){
           GoToWaypointAction* o = new GoToWaypointAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "WaypointNumber")
              {
                 Node* tmp = el->getChild(i);
                 o->setWaypointNumber( get_int64( tmp ));
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
        if (type == "KeepInZone"){
           KeepInZone* o = new KeepInZone();
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
        if (type == "KeepOutZone"){
           KeepOutZone* o = new KeepOutZone();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ZoneType")
              {
                 Node* tmp = el->getChild(i);
                 o->setZoneType( afrl::cmasi::ZoneAvoidanceType::get_ZoneAvoidanceType( get_string( tmp )));
                 continue;
              }
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
        if (type == "LineSearchTask"){
           LineSearchTask* o = new LineSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PointList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getPointList().push_back( (afrl::cmasi::Location3D*) oo);
                 }
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
        if (type == "NavigationAction"){
           NavigationAction* o = new NavigationAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "LoiterAction"){
           LoiterAction* o = new LoiterAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "LoiterType")
              {
                 Node* tmp = el->getChild(i);
                 o->setLoiterType( afrl::cmasi::LoiterType::get_LoiterType( get_string( tmp )));
                 continue;
              }
              if(name == "Radius")
              {
                 Node* tmp = el->getChild(i);
                 o->setRadius( get_real32( tmp ));
                 continue;
              }
              if(name == "Axis")
              {
                 Node* tmp = el->getChild(i);
                 o->setAxis( get_real32( tmp ));
                 continue;
              }
              if(name == "Length")
              {
                 Node* tmp = el->getChild(i);
                 o->setLength( get_real32( tmp ));
                 continue;
              }
              if(name == "Direction")
              {
                 Node* tmp = el->getChild(i);
                 o->setDirection( afrl::cmasi::LoiterDirection::get_LoiterDirection( get_string( tmp )));
                 continue;
              }
              if(name == "Duration")
              {
                 Node* tmp = el->getChild(i);
                 o->setDuration( get_int64( tmp ));
                 continue;
              }
              if(name == "Airspeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setAirspeed( get_real32( tmp ));
                 continue;
              }
              if(name == "Location")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setLocation((afrl::cmasi::Location3D*) oo );
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
        if (type == "LoiterTask"){
           LoiterTask* o = new LoiterTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "DesiredAction")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setDesiredAction((afrl::cmasi::LoiterAction*) oo );
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
        if (type == "Waypoint"){
           Waypoint* o = new Waypoint();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Number")
              {
                 Node* tmp = el->getChild(i);
                 o->setNumber( get_int64( tmp ));
                 continue;
              }
              if(name == "NextWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setNextWaypoint( get_int64( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "SpeedType")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedType( afrl::cmasi::SpeedType::get_SpeedType( get_string( tmp )));
                 continue;
              }
              if(name == "ClimbRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setClimbRate( get_real32( tmp ));
                 continue;
              }
              if(name == "TurnType")
              {
                 Node* tmp = el->getChild(i);
                 o->setTurnType( afrl::cmasi::TurnType::get_TurnType( get_string( tmp )));
                 continue;
              }
              if(name == "VehicleActionList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleActionList().push_back( (afrl::cmasi::VehicleAction*) oo);
                 }
                 continue;
              }
              if(name == "ContingencyWaypointA")
              {
                 Node* tmp = el->getChild(i);
                 o->setContingencyWaypointA( get_int64( tmp ));
                 continue;
              }
              if(name == "ContingencyWaypointB")
              {
                 Node* tmp = el->getChild(i);
                 o->setContingencyWaypointB( get_int64( tmp ));
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
              if(name == "Latitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLatitude( get_real64( tmp ));
                 continue;
              }
              if(name == "Longitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLongitude( get_real64( tmp ));
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
        if (type == "MissionCommand"){
           MissionCommand* o = new MissionCommand();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
              if(name == "CommandID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCommandID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleActionList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleActionList().push_back( (afrl::cmasi::VehicleAction*) oo);
                 }
                 continue;
              }
              if(name == "Status")
              {
                 Node* tmp = el->getChild(i);
                 o->setStatus( afrl::cmasi::CommandStatusType::get_CommandStatusType( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "MustFlyTask"){
           MustFlyTask* o = new MustFlyTask();
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
              if(name == "UseAltitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseAltitude( get_bool( tmp ));
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
        if (type == "OperatorSignal"){
           OperatorSignal* o = new OperatorSignal();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Signals")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getSignals().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "OperatingRegion"){
           OperatingRegion* o = new OperatingRegion();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ID")
              {
                 Node* tmp = el->getChild(i);
                 o->setID( get_int64( tmp ));
                 continue;
              }
              if(name == "KeepInAreas")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getKeepInAreas().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "KeepOutAreas")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getKeepOutAreas().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "AutomationRequest"){
           AutomationRequest* o = new AutomationRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEntityList().push_back( get_int64( tmp->getChild(j)));
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
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
              if(name == "RedoAllTasks")
              {
                 Node* tmp = el->getChild(i);
                 o->setRedoAllTasks( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "PointSearchTask"){
           PointSearchTask* o = new PointSearchTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
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
        if (type == "Polygon"){
           Polygon* o = new Polygon();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "BoundaryPoints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getBoundaryPoints().push_back( (afrl::cmasi::Location3D*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "Rectangle"){
           Rectangle* o = new Rectangle();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CenterPoint")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setCenterPoint((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "Width")
              {
                 Node* tmp = el->getChild(i);
                 o->setWidth( get_real32( tmp ));
                 continue;
              }
              if(name == "Height")
              {
                 Node* tmp = el->getChild(i);
                 o->setHeight( get_real32( tmp ));
                 continue;
              }
              if(name == "Rotation")
              {
                 Node* tmp = el->getChild(i);
                 o->setRotation( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "RemoveTasks"){
           RemoveTasks* o = new RemoveTasks();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "TaskList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getTaskList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "ServiceStatus"){
           ServiceStatus* o = new ServiceStatus();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PercentComplete")
              {
                 Node* tmp = el->getChild(i);
                 o->setPercentComplete( get_real32( tmp ));
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
              if(name == "StatusType")
              {
                 Node* tmp = el->getChild(i);
                 o->setStatusType( afrl::cmasi::ServiceStatusType::get_ServiceStatusType( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "SessionStatus"){
           SessionStatus* o = new SessionStatus();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "State")
              {
                 Node* tmp = el->getChild(i);
                 o->setState( afrl::cmasi::SimulationStatusType::get_SimulationStatusType( get_string( tmp )));
                 continue;
              }
              if(name == "StartTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartTime( get_int64( tmp ));
                 continue;
              }
              if(name == "ScenarioTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setScenarioTime( get_int64( tmp ));
                 continue;
              }
              if(name == "RealTimeMultiple")
              {
                 Node* tmp = el->getChild(i);
                 o->setRealTimeMultiple( get_real32( tmp ));
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
        if (type == "VehicleActionCommand"){
           VehicleActionCommand* o = new VehicleActionCommand();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "CommandID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCommandID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleActionList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleActionList().push_back( (afrl::cmasi::VehicleAction*) oo);
                 }
                 continue;
              }
              if(name == "Status")
              {
                 Node* tmp = el->getChild(i);
                 o->setStatus( afrl::cmasi::CommandStatusType::get_CommandStatusType( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "VideoStreamAction"){
           VideoStreamAction* o = new VideoStreamAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "VideoStreamID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVideoStreamID( get_int32( tmp ));
                 continue;
              }
              if(name == "ActiveSensor")
              {
                 Node* tmp = el->getChild(i);
                 o->setActiveSensor( get_int32( tmp ));
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
        if (type == "VideoStreamConfiguration"){
           VideoStreamConfiguration* o = new VideoStreamConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "AvailableSensorList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAvailableSensorList().push_back( get_int64( tmp->getChild(j)));
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
        if (type == "VideoStreamState"){
           VideoStreamState* o = new VideoStreamState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ActiveSensor")
              {
                 Node* tmp = el->getChild(i);
                 o->setActiveSensor( get_int64( tmp ));
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
        if (type == "AutomationResponse"){
           AutomationResponse* o = new AutomationResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "MissionCommandList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getMissionCommandList().push_back( (afrl::cmasi::MissionCommand*) oo);
                 }
                 continue;
              }
              if(name == "VehicleCommandList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleCommandList().push_back( (afrl::cmasi::VehicleActionCommand*) oo);
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
        if (type == "RemoveZones"){
           RemoveZones* o = new RemoveZones();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ZoneList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getZoneList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RemoveEntities"){
           RemoveEntities* o = new RemoveEntities();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getEntityList().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "FlightDirectorAction"){
           FlightDirectorAction* o = new FlightDirectorAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "SpeedType")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedType( afrl::cmasi::SpeedType::get_SpeedType( get_string( tmp )));
                 continue;
              }
              if(name == "Heading")
              {
                 Node* tmp = el->getChild(i);
                 o->setHeading( get_real32( tmp ));
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
              if(name == "ClimbRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setClimbRate( get_real32( tmp ));
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
        if (type == "WeatherReport"){
           WeatherReport* o = new WeatherReport();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Area")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setArea((afrl::cmasi::AbstractZone*) oo );
                 continue;
              }
              if(name == "WindSpeed")
              {
                 Node* tmp = el->getChild(i);
                 o->setWindSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "WindDirection")
              {
                 Node* tmp = el->getChild(i);
                 o->setWindDirection( get_real32( tmp ));
                 continue;
              }
              if(name == "Visibility")
              {
                 Node* tmp = el->getChild(i);
                 o->setVisibility( get_real32( tmp ));
                 continue;
              }
              if(name == "CloudCeiling")
              {
                 Node* tmp = el->getChild(i);
                 o->setCloudCeiling( get_real32( tmp ));
                 continue;
              }
              if(name == "CloudCoverage")
              {
                 Node* tmp = el->getChild(i);
                 o->setCloudCoverage( get_real32( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "FollowPathCommand"){
           FollowPathCommand* o = new FollowPathCommand();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "FirstWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setFirstWaypoint( get_int64( tmp ));
                 continue;
              }
              if(name == "WaypointList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getWaypointList().push_back( (afrl::cmasi::PathWaypoint*) oo);
                 }
                 continue;
              }
              if(name == "StartTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartTime( get_int64( tmp ));
                 continue;
              }
              if(name == "StopTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setStopTime( get_int64( tmp ));
                 continue;
              }
              if(name == "RepeatMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setRepeatMode( afrl::cmasi::TravelMode::get_TravelMode( get_string( tmp )));
                 continue;
              }
              if(name == "CommandID")
              {
                 Node* tmp = el->getChild(i);
                 o->setCommandID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 o->setVehicleID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleActionList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleActionList().push_back( (afrl::cmasi::VehicleAction*) oo);
                 }
                 continue;
              }
              if(name == "Status")
              {
                 Node* tmp = el->getChild(i);
                 o->setStatus( afrl::cmasi::CommandStatusType::get_CommandStatusType( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "PathWaypoint"){
           PathWaypoint* o = new PathWaypoint();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PauseTime")
              {
                 Node* tmp = el->getChild(i);
                 o->setPauseTime( get_int64( tmp ));
                 continue;
              }
              if(name == "Number")
              {
                 Node* tmp = el->getChild(i);
                 o->setNumber( get_int64( tmp ));
                 continue;
              }
              if(name == "NextWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setNextWaypoint( get_int64( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
                 continue;
              }
              if(name == "SpeedType")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeedType( afrl::cmasi::SpeedType::get_SpeedType( get_string( tmp )));
                 continue;
              }
              if(name == "ClimbRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setClimbRate( get_real32( tmp ));
                 continue;
              }
              if(name == "TurnType")
              {
                 Node* tmp = el->getChild(i);
                 o->setTurnType( afrl::cmasi::TurnType::get_TurnType( get_string( tmp )));
                 continue;
              }
              if(name == "VehicleActionList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getVehicleActionList().push_back( (afrl::cmasi::VehicleAction*) oo);
                 }
                 continue;
              }
              if(name == "ContingencyWaypointA")
              {
                 Node* tmp = el->getChild(i);
                 o->setContingencyWaypointA( get_int64( tmp ));
                 continue;
              }
              if(name == "ContingencyWaypointB")
              {
                 Node* tmp = el->getChild(i);
                 o->setContingencyWaypointB( get_int64( tmp ));
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
              if(name == "Latitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLatitude( get_real64( tmp ));
                 continue;
              }
              if(name == "Longitude")
              {
                 Node* tmp = el->getChild(i);
                 o->setLongitude( get_real64( tmp ));
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
        if (type == "StopMovementAction"){
           StopMovementAction* o = new StopMovementAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "Location")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setLocation((afrl::cmasi::Location3D*) oo );
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
        if (type == "WaypointTransfer"){
           WaypointTransfer* o = new WaypointTransfer();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_int64( tmp ));
                 continue;
              }
              if(name == "Waypoints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getWaypoints().push_back( (afrl::cmasi::Waypoint*) oo);
                 }
                 continue;
              }
              if(name == "TransferMode")
              {
                 Node* tmp = el->getChild(i);
                 o->setTransferMode( afrl::cmasi::WaypointTransferMode::get_WaypointTransferMode( get_string( tmp )));
                 continue;
              }
           }
           return o;
        }
        if (type == "PayloadStowAction"){
           PayloadStowAction* o = new PayloadStowAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PayloadID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPayloadID( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }


         return NULL;
        
    }

} // end namespace cmasi
} // end namespace afrl

