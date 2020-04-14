// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include "uxas/messages/route/ROUTEXMLReader.h"
#include "avtas/lmcp/XMLParser.h"
#include <vector>
#include <string>
#include "avtas/lmcp/LmcpXMLReader.h"

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


using namespace avtas::lmcp;
using namespace avtas::lmcp::xml;


namespace uxas {
namespace messages {
namespace route {


    avtas::lmcp::Object* ROUTEXMLReader :: visitType(avtas::lmcp::Node* el){

        if (el == NULL) return NULL;
        
        std::string type = el->getTagName();
            
        if (type == "GraphNode"){
           GraphNode* o = new GraphNode();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "NodeID")
              {
                 Node* tmp = el->getChild(i);
                 o->setNodeID( get_int64( tmp ));
                 continue;
              }
              if(name == "Coordinates")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setCoordinates((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "AssociatedEdges")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getAssociatedEdges().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "GraphEdge"){
           GraphEdge* o = new GraphEdge();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "EdgeID")
              {
                 Node* tmp = el->getChild(i);
                 o->setEdgeID( get_int64( tmp ));
                 continue;
              }
              if(name == "StartNode")
              {
                 Node* tmp = el->getChild(i);
                 o->setStartNode( get_int64( tmp ));
                 continue;
              }
              if(name == "EndNode")
              {
                 Node* tmp = el->getChild(i);
                 o->setEndNode( get_int64( tmp ));
                 continue;
              }
              if(name == "Waypoints")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getWaypoints().push_back( (afrl::cmasi::Location3D*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "GraphRegion"){
           GraphRegion* o = new GraphRegion();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ID")
              {
                 Node* tmp = el->getChild(i);
                 o->setID( get_int64( tmp ));
                 continue;
              }
              if(name == "NodeList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getNodeList().push_back( (uxas::messages::route::GraphNode*) oo);
                 }
                 continue;
              }
              if(name == "EdgeList")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getEdgeList().push_back( (uxas::messages::route::GraphEdge*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RouteConstraints"){
           RouteConstraints* o = new RouteConstraints();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RouteID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRouteID( get_int64( tmp ));
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
              if(name == "UseStartHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseStartHeading( get_bool( tmp ));
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
              if(name == "UseEndHeading")
              {
                 Node* tmp = el->getChild(i);
                 o->setUseEndHeading( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "RouteRequest"){
           RouteRequest* o = new RouteRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "AssociatedTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setAssociatedTaskID( get_int64( tmp ));
                 continue;
              }
              if(name == "VehicleID")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getVehicleID().push_back( get_int64( tmp->getChild(j)));
                 }
                 continue;
              }
              if(name == "OperatingRegion")
              {
                 Node* tmp = el->getChild(i);
                 o->setOperatingRegion( get_int64( tmp ));
                 continue;
              }
              if(name == "RouteRequests")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRouteRequests().push_back( (uxas::messages::route::RouteConstraints*) oo);
                 }
                 continue;
              }
              if(name == "IsCostOnlyRequest")
              {
                 Node* tmp = el->getChild(i);
                 o->setIsCostOnlyRequest( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "RoutePlanRequest"){
           RoutePlanRequest* o = new RoutePlanRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "AssociatedTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setAssociatedTaskID( get_int64( tmp ));
                 continue;
              }
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
              if(name == "RouteRequests")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRouteRequests().push_back( (uxas::messages::route::RouteConstraints*) oo);
                 }
                 continue;
              }
              if(name == "IsCostOnlyRequest")
              {
                 Node* tmp = el->getChild(i);
                 o->setIsCostOnlyRequest( get_bool( tmp ));
                 continue;
              }
           }
           return o;
        }
        if (type == "RoutePlan"){
           RoutePlan* o = new RoutePlan();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RouteID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRouteID( get_int64( tmp ));
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
              if(name == "RouteCost")
              {
                 Node* tmp = el->getChild(i);
                 o->setRouteCost( get_int64( tmp ));
                 continue;
              }
              if(name == "RouteError")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRouteError().push_back( (afrl::cmasi::KeyValuePair*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RoutePlanResponse"){
           RoutePlanResponse* o = new RoutePlanResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "AssociatedTaskID")
              {
                 Node* tmp = el->getChild(i);
                 o->setAssociatedTaskID( get_int64( tmp ));
                 continue;
              }
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
              if(name == "RouteResponses")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRouteResponses().push_back( (uxas::messages::route::RoutePlan*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RouteResponse"){
           RouteResponse* o = new RouteResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "Routes")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRoutes().push_back( (uxas::messages::route::RoutePlanResponse*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "EgressRouteRequest"){
           EgressRouteRequest* o = new EgressRouteRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "StartLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStartLocation((afrl::cmasi::Location3D*) oo );
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
        if (type == "EgressRouteResponse"){
           EgressRouteResponse* o = new EgressRouteResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "NodeLocations")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getNodeLocations().push_back( (afrl::cmasi::Location3D*) oo);
                 }
                 continue;
              }
              if(name == "Headings")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    o->getHeadings().push_back( get_real32( tmp->getChild(j)));
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RoadPointsConstraints"){
           RoadPointsConstraints* o = new RoadPointsConstraints();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RoadPointsID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRoadPointsID( get_int64( tmp ));
                 continue;
              }
              if(name == "StartLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setStartLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
              if(name == "EndLocation")
              {
                 Node* tmp = el->getChild(i);
                 Object* oo = readXML( tmp->getChild(0) );
                 o->setEndLocation((afrl::cmasi::Location3D*) oo );
                 continue;
              }
           }
           return o;
        }
        if (type == "RoadPointsRequest"){
           RoadPointsRequest* o = new RoadPointsRequest();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "RequestID")
              {
                 Node* tmp = el->getChild(i);
                 o->setRequestID( get_int64( tmp ));
                 continue;
              }
              if(name == "RoadPointsRequests")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRoadPointsRequests().push_back( (uxas::messages::route::RoadPointsConstraints*) oo);
                 }
                 continue;
              }
           }
           return o;
        }
        if (type == "RoadPointsResponse"){
           RoadPointsResponse* o = new RoadPointsResponse();
           for (uint32_t i=0; i<el->getChildCount(); i++)
           {
              std::string name = el->getChild(i)->getTagName();
              if(name == "ResponseID")
              {
                 Node* tmp = el->getChild(i);
                 o->setResponseID( get_int64( tmp ));
                 continue;
              }
              if(name == "RoadPointsResponses")
              {
                 Node* tmp = el->getChild(i);
                 for (uint32_t j=0; j<tmp->getChildCount(); j++)
                 {
                    Object* oo = readXML( tmp->getChild(j));
                    o->getRoadPointsResponses().push_back( (afrl::impact::LineOfInterest*) oo);
                 }
                 continue;
              }
           }
           return o;
        }


         return NULL;
        
    }

} // end namespace route
} // end namespace messages
} // end namespace uxas

