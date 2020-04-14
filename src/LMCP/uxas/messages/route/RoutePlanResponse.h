// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROUTEPLANRESPONSE_H_
#define _UXAS_MESSAGES_ROUTE_ROUTEPLANRESPONSE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/route/RoutePlan.h"

#include <vector>


namespace uxas {
namespace messages {
namespace route {


   bool isRoutePlanResponse(avtas::lmcp::Object* obj);
   bool isRoutePlanResponse(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RoutePlanResponseDescendants();
   
   class RoutePlanResponse : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RoutePlanResponse(void);

      // Copy Constructor
      RoutePlanResponse(const RoutePlanResponse &that);

      // Assignment Operator
      RoutePlanResponse & operator=(const RoutePlanResponse &that);

      // Destructor
      virtual ~RoutePlanResponse(void);

      // Equals overload
      bool operator==(const RoutePlanResponse & that);
      bool operator!=(const RoutePlanResponse & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RoutePlanResponse* clone() const;

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
      /** Response ID matching ID from request ({@link RoutePlanRequest})(Units: None)*/
      int64_t getResponseID(void) const { return __ResponseID; }
      RoutePlanResponse& setResponseID(const int64_t val);

      /** Associated Task ID (0 if no associated task) that this set of responses corresponds to (Units: None)*/
      int64_t getAssociatedTaskID(void) const { return __AssociatedTaskID; }
      RoutePlanResponse& setAssociatedTaskID(const int64_t val);

      /** Vehicle that was considered during planning (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      RoutePlanResponse& setVehicleID(const int64_t val);

      /** Operating region that was considered during planning (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      RoutePlanResponse& setOperatingRegion(const int64_t val);

      /** List of all responses for this vehicle + operating region situation (Units: None)*/
      std::vector<uxas::messages::route::RoutePlan*> & getRouteResponses(void) { return __RouteResponses; }



   protected:
      /** Response ID matching ID from request ({@link RoutePlanRequest})*/
      int64_t __ResponseID;
      /** Associated Task ID (0 if no associated task) that this set of responses corresponds to */
      int64_t __AssociatedTaskID;
      /** Vehicle that was considered during planning */
      int64_t __VehicleID;
      /** Operating region that was considered during planning */
      int64_t __OperatingRegion;
      /** List of all responses for this vehicle + operating region situation */
      std::vector< uxas::messages::route::RoutePlan* > __RouteResponses;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_ROUTEPLANRESPONSE_H_
