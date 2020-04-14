// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_PATHWAYPOINT_H_
#define _AFRL_CMASI_PATHWAYPOINT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/Waypoint.h"



namespace afrl {
namespace cmasi {


   bool isPathWaypoint(avtas::lmcp::Object* obj);
   bool isPathWaypoint(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PathWaypointDescendants();
   
   class PathWaypoint : public afrl::cmasi::Waypoint {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PathWaypoint(void);

      // Copy Constructor
      PathWaypoint(const PathWaypoint &that);

      // Assignment Operator
      PathWaypoint & operator=(const PathWaypoint &that);

      // Destructor
      virtual ~PathWaypoint(void);

      // Equals overload
      bool operator==(const PathWaypoint & that);
      bool operator!=(const PathWaypoint & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PathWaypoint* clone() const;

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
      /** The amount of time that an entity should pause before moving to the next waypoint. (Units: milliseconds)*/
      int64_t getPauseTime(void) const { return __PauseTime; }
      PathWaypoint& setPauseTime(const int64_t val);



   protected:
      /** The amount of time that an entity should pause before moving to the next waypoint. */
      int64_t __PauseTime;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_PATHWAYPOINT_H_
