// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROUTEPLAN_H_
#define _UXAS_MESSAGES_ROUTE_ROUTEPLAN_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace uxas {
namespace messages {
namespace route {


   bool isRoutePlan(avtas::lmcp::Object* obj);
   bool isRoutePlan(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RoutePlanDescendants();
   
   class RoutePlan : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RoutePlan(void);

      // Copy Constructor
      RoutePlan(const RoutePlan &that);

      // Assignment Operator
      RoutePlan & operator=(const RoutePlan &that);

      // Destructor
      virtual ~RoutePlan(void);

      // Equals overload
      bool operator==(const RoutePlan & that);
      bool operator!=(const RoutePlan & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RoutePlan* clone() const;

      // Returns string representation of object
      virtual std::string toString(int32_t depth=0) const;

      // Returns an XML string representation of the object.
      virtual std::string toXML(int32_t depth=0);

      // Returns object type id
      virtual uint32_t getLmcpType(void) const { return TypeId; }
	  
      // Returns object type name string
      virtual std::string getLmcpTypeName(void) const { return TypeName; }
	  
      // Returns object type name string with full namespace prepended, same as subscription name
      virtual std::string getFullLmcpTypeName(void) const { return Subscription; }

      // Returns series name string
      virtual std::string getSeriesName(void) const { return SeriesName; }

      // gets the series name as a long value
      virtual int64_t getSeriesNameAsLong(void) const { return SeriesId; }

      //gets the version number of the series
      virtual uint16_t getSeriesVersion(void) const { return SeriesVersion; }

      // Accessors and Modifiers
      /** ID denoting this plan corresponding with requested route constraint pair (Units: None)*/
      int64_t getRouteID(void) const { return __RouteID; }
      RoutePlan& setRouteID(const int64_t val);

      /** Waypoints that connect the start location with the end location. Empty if only costs were requested (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getWaypoints(void) { return __Waypoints; }

      /** Time cost of route. If less than zero, a planning error has occurred (Units: milliseconds)*/
      int64_t getRouteCost(void) const { return __RouteCost; }
      RoutePlan& setRouteCost(const int64_t val);

      /** Error messages, if applicable (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getRouteError(void) { return __RouteError; }



   protected:
      /** ID denoting this plan corresponding with requested route constraint pair */
      int64_t __RouteID;
      /** Waypoints that connect the start location with the end location. Empty if only costs were requested */
      std::vector< afrl::cmasi::Waypoint* > __Waypoints;
      /** Time cost of route. If less than zero, a planning error has occurred */
      int64_t __RouteCost;
      /** Error messages, if applicable */
      std::vector< afrl::cmasi::KeyValuePair* > __RouteError;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_ROUTEPLAN_H_
