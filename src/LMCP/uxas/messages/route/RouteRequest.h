// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROUTEREQUEST_H_
#define _UXAS_MESSAGES_ROUTE_ROUTEREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/route/RouteConstraints.h"

#include <vector>


namespace uxas {
namespace messages {
namespace route {


   bool isRouteRequest(avtas::lmcp::Object* obj);
   bool isRouteRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RouteRequestDescendants();
   
   class RouteRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RouteRequest(void);

      // Copy Constructor
      RouteRequest(const RouteRequest &that);

      // Assignment Operator
      RouteRequest & operator=(const RouteRequest &that);

      // Destructor
      virtual ~RouteRequest(void);

      // Equals overload
      bool operator==(const RouteRequest & that);
      bool operator!=(const RouteRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RouteRequest* clone() const;

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
      /** Request ID for correlating with response (Units: None)*/
      int64_t getRequestID(void) const { return __RequestID; }
      RouteRequest& setRequestID(const int64_t val);

      /** Associated Task ID (0 if no associated task) for this set of requests (Units: None)*/
      int64_t getAssociatedTaskID(void) const { return __AssociatedTaskID; }
      RouteRequest& setAssociatedTaskID(const int64_t val);

      /** Vehicles to consider when planning. If list is empty, route planner plans for all known vehicles. (Units: None)*/
      std::vector<int64_t> & getVehicleID(void) { return __VehicleID; }

      /** Operating region to be considered during planning (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      RouteRequest& setOperatingRegion(const int64_t val);

      /** List of all requests for this vehicle set + operating region situation (Units: None)*/
      std::vector<uxas::messages::route::RouteConstraints*> & getRouteRequests(void) { return __RouteRequests; }

      /** Request that planner only return costs of routes rather than complete waypoint plans (Units: None)*/
      bool getIsCostOnlyRequest(void) const { return __IsCostOnlyRequest; }
      RouteRequest& setIsCostOnlyRequest(const bool val);



   protected:
      /** Request ID for correlating with response */
      int64_t __RequestID;
      /** Associated Task ID (0 if no associated task) for this set of requests */
      int64_t __AssociatedTaskID;
      /** Vehicles to consider when planning. If list is empty, route planner plans for all known vehicles. */
      std::vector< int64_t > __VehicleID;
      /** Operating region to be considered during planning */
      int64_t __OperatingRegion;
      /** List of all requests for this vehicle set + operating region situation */
      std::vector< uxas::messages::route::RouteConstraints* > __RouteRequests;
      /** Request that planner only return costs of routes rather than complete waypoint plans */
      bool __IsCostOnlyRequest;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_ROUTEREQUEST_H_
