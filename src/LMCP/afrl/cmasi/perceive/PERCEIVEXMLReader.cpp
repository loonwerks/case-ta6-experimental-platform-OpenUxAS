// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "afrl/cmasi/perceive/PERCEIVEXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

#include "afrl/cmasi/perceive/EntityPerception.h"
#include "afrl/cmasi/perceive/TrackEntityAction.h"
#include "afrl/cmasi/perceive/TrackEntityTask.h"
#include "afrl/cmasi/perceive/PERCEIVEEnum.h"


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace afrl {
namespace cmasi {
namespace perceive {


    avtas::lmcp::Object* PERCEIVEXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "EntityPerception"){
           EntityPerception* o = new EntityPerception();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "PerceivedEntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPerceivedEntityID( get_uint32( tmp ));
                 continue;
              }
              if(name == "PerceiverID")
              {
                 Node* tmp = el->getChild(i);
                 o->setPerceiverID( get_uint32( tmp ));
                 continue;
              }
              if(name == "PerceiverPayloads")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getPerceiverPayloads().push_back( get_uint32( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "Velocity")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVelocity()[j] = get_real32( tmp->getChild(j));
                 }
                 continue;
              }
              if(name == "VelocityError")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVelocityError()[j] = get_real32( tmp->getChild(j));
                 }
                 continue;
              }
              if(name == "VelocityValid")
              {
                 Node* tmp = el->getChild(i);
                 o->setVelocityValid( get_bool( tmp ));
                 continue;
              }
              if(name == "Attitude")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAttitude()[j] = get_real32( tmp->getChild(j));
                 }
                 continue;
              }
              if(name == "AttitudeError")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAttitudeError()[j] = get_real32( tmp->getChild(j));
                 }
                 continue;
              }
              if(name == "AttitudeValid")
              {
                 Node* tmp = el->getChild(i);
                 o->setAttitudeValid( get_bool( tmp ));
                 continue;
              }
              if(name == "Location")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "LocationError")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getLocationError()[j] = get_real32( tmp->getChild(j));
                 }
                 continue;
              }
              if(name == "TimeLastSeen")
              {
                 Node* tmp = el->getChild(i);
                 o->setTimeLastSeen( get_int64( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "TrackEntityAction"){
           TrackEntityAction* o = new TrackEntityAction();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_uint32( tmp ));
                 continue;
              }
              if(name == "SensorID")
              {
                 Node* tmp = el->getChild(i);
                 o->setSensorID( get_uint32( tmp ));
                 continue;
              }
              if(name == "ReturnToWaypoint")
              {
                 Node* tmp = el->getChild(i);
                 o->setReturnToWaypoint( get_uint32( tmp ));
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
        if (type == "TrackEntityTask"){
           TrackEntityTask* o = new TrackEntityTask();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EntityID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEntityID( get_uint32( tmp ));
                 continue;
              }
              if(name == "SensorModality")
              {
                 Node* tmp = el->getChild(i);
                 o->setSensorModality( afrl::cmasi::WavelengthBand::get_WavelengthBand( get_string( tmp )));
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


         return NULL;
        
    }

} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl

