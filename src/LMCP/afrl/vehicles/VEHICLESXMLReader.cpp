// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/vehicles/VEHICLESXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

#include "afrl/vehicles/GroundVehicleConfiguration.h"
#include "afrl/vehicles/GroundVehicleState.h"
#include "afrl/vehicles/SurfaceVehicleConfiguration.h"
#include "afrl/vehicles/SurfaceVehicleState.h"
#include "afrl/vehicles/StationarySensorConfiguration.h"
#include "afrl/vehicles/StationarySensorState.h"
#include "afrl/vehicles/VEHICLESEnum.h"


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace afrl {
namespace vehicles {


    avtas::lmcp::Object* VEHICLESXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "GroundVehicleConfiguration"){
           GroundVehicleConfiguration* o = new GroundVehicleConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RoadGraphID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRoadGraphID( get_int64( tmp ));
                 continue;
              }
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
              if(name == "EnergyRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnergyRate( get_real32( tmp ));
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
        if (type == "GroundVehicleState"){
           GroundVehicleState* o = new GroundVehicleState();
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
        if (type == "SurfaceVehicleConfiguration"){
           SurfaceVehicleConfiguration* o = new SurfaceVehicleConfiguration();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "WaterArea")
              {
                 Node* tmp = el->getChild(i);
                 o->setWaterArea( get_int64( tmp ));
                 continue;
              }
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
              if(name == "EnergyRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setEnergyRate( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxBankAngle")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxBankAngle( get_real32( tmp ));
                 continue;
              }
              if(name == "MaxBankRate")
              {
                 Node* tmp = el->getChild(i);
                 o->setMaxBankRate( get_real32( tmp ));
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
        if (type == "SurfaceVehicleState"){
           SurfaceVehicleState* o = new SurfaceVehicleState();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "BankAngle")
              {
                 Node* tmp = el->getChild(i);
                 o->setBankAngle( get_real32( tmp ));
                 continue;
              }
              if(name == "Speed")
              {
                 Node* tmp = el->getChild(i);
                 o->setSpeed( get_real32( tmp ));
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
        if (type == "StationarySensorConfiguration"){
           StationarySensorConfiguration* o = new StationarySensorConfiguration();
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
        if (type == "StationarySensorState"){
           StationarySensorState* o = new StationarySensorState();
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


         return NULL;
        
    }

} // end namespace vehicles
} // end namespace afrl

