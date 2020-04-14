// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_ESCORTTASK_H_
#define _AFRL_IMPACT_ESCORTTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/Waypoint.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isEscortTask(avtas::lmcp::Object* obj);
   bool isEscortTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > EscortTaskDescendants();
   
   class EscortTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      EscortTask(void);

      // Copy Constructor
      EscortTask(const EscortTask &that);

      // Assignment Operator
      EscortTask & operator=(const EscortTask &that);

      // Destructor
      virtual ~EscortTask(void);

      // Equals overload
      bool operator==(const EscortTask & that);
      bool operator!=(const EscortTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual EscortTask* clone() const;

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
      /** ID of entity which will provide the basis for the escort. Tasked vehicle will attempt to stay 'StandoffDistance' ahead of this entity on its route. (Units: None)*/
      int64_t getSupportedEntityID(void) const { return __SupportedEntityID; }
      EscortTask& setSupportedEntityID(const int64_t val);

      /** ID of line which describes the route that the 'SupportedEntityID' is following. If the 'SupportedEntityID' is one of the controlled entities, such as a taskable ground vehicle, then 'RouteID' can be zero and this task will use current, known route for that vehicle. Otherwise, 'RouteID' must be an ID for a previously described '{@link LineOfInterest}'. (Units: None)*/
      int64_t getRouteID(void) const { return __RouteID; }
      EscortTask& setRouteID(const int64_t val);

      /** Waypoints that the supported entity is presumed to be following if 'RouteID' is zero (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getPrescribedWaypoints(void) { return __PrescribedWaypoints; }

      /** Distance ahead (positive) or behind (negative) that the vehicle will provide surveillance relative to 'SupportedEntityID's location on route 'RouteID' (Units: meters)*/
      float getStandoffDistance(void) const { return __StandoffDistance; }
      EscortTask& setStandoffDistance(const float val);



   protected:
      /** ID of entity which will provide the basis for the escort. Tasked vehicle will attempt to stay 'StandoffDistance' ahead of this entity on its route. */
      int64_t __SupportedEntityID;
      /** ID of line which describes the route that the 'SupportedEntityID' is following. If the 'SupportedEntityID' is one of the controlled entities, such as a taskable ground vehicle, then 'RouteID' can be zero and this task will use current, known route for that vehicle. Otherwise, 'RouteID' must be an ID for a previously described '{@link LineOfInterest}'. */
      int64_t __RouteID;
      /** Waypoints that the supported entity is presumed to be following if 'RouteID' is zero */
      std::vector< afrl::cmasi::Waypoint* > __PrescribedWaypoints;
      /** Distance ahead (positive) or behind (negative) that the vehicle will provide surveillance relative to 'SupportedEntityID's location on route 'RouteID' */
      float __StandoffDistance;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_ESCORTTASK_H_
