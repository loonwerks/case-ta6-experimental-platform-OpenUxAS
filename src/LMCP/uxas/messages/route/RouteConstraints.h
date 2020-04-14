// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROUTECONSTRAINTS_H_
#define _UXAS_MESSAGES_ROUTE_ROUTECONSTRAINTS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Location3D.h"



namespace uxas {
namespace messages {
namespace route {


   bool isRouteConstraints(avtas::lmcp::Object* obj);
   bool isRouteConstraints(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RouteConstraintsDescendants();
   
   class RouteConstraints : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RouteConstraints(void);

      // Copy Constructor
      RouteConstraints(const RouteConstraints &that);

      // Assignment Operator
      RouteConstraints & operator=(const RouteConstraints &that);

      // Destructor
      virtual ~RouteConstraints(void);

      // Equals overload
      bool operator==(const RouteConstraints & that);
      bool operator!=(const RouteConstraints & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RouteConstraints* clone() const;

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
      /** ID denoting this set of route constraints (Units: None)*/
      int64_t getRouteID(void) const { return __RouteID; }
      RouteConstraints& setRouteID(const int64_t val);

      /** Location from which the planned route will start. A valid RouteConstraints message must define StartLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getStartLocation(void) { return __StartLocation; }
      RouteConstraints& setStartLocation(const afrl::cmasi::Location3D* const val);

      /** Heading of entity at the start of the route (Units: degrees)*/
      float getStartHeading(void) const { return __StartHeading; }
      RouteConstraints& setStartHeading(const float val);

      /** If "true" the heading value in StartHeading must be used to start the route. If not, any starting heading can be used. (Units: None)*/
      bool getUseStartHeading(void) const { return __UseStartHeading; }
      RouteConstraints& setUseStartHeading(const bool val);

      /** Location to which the planned route will end. A valid RouteConstraints message must define EndLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getEndLocation(void) { return __EndLocation; }
      RouteConstraints& setEndLocation(const afrl::cmasi::Location3D* const val);

      /** Heading of entity at the end of the route (Units: degrees)*/
      float getEndHeading(void) const { return __EndHeading; }
      RouteConstraints& setEndHeading(const float val);

      /** If "true" the heading value in EndHeading must be used to end the route. If not, any ending heading can be used. (Units: None)*/
      bool getUseEndHeading(void) const { return __UseEndHeading; }
      RouteConstraints& setUseEndHeading(const bool val);



   protected:
      /** ID denoting this set of route constraints */
      int64_t __RouteID;
      /** Location from which the planned route will start. A valid RouteConstraints message must define StartLocation (null not allowed). */
      afrl::cmasi::Location3D* __StartLocation;
      /** Heading of entity at the start of the route */
      float __StartHeading;
      /** If "true" the heading value in StartHeading must be used to start the route. If not, any starting heading can be used. */
      bool __UseStartHeading;
      /** Location to which the planned route will end. A valid RouteConstraints message must define EndLocation (null not allowed). */
      afrl::cmasi::Location3D* __EndLocation;
      /** Heading of entity at the end of the route */
      float __EndHeading;
      /** If "true" the heading value in EndHeading must be used to end the route. If not, any ending heading can be used. */
      bool __UseEndHeading;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_ROUTECONSTRAINTS_H_
