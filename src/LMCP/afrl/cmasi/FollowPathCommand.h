// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_FOLLOWPATHCOMMAND_H_
#define _AFRL_CMASI_FOLLOWPATHCOMMAND_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/VehicleActionCommand.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/TravelMode.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isFollowPathCommand(avtas::lmcp::Object* obj);
   bool isFollowPathCommand(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > FollowPathCommandDescendants();
   
   class FollowPathCommand : public afrl::cmasi::VehicleActionCommand {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      FollowPathCommand(void);

      // Copy Constructor
      FollowPathCommand(const FollowPathCommand &that);

      // Assignment Operator
      FollowPathCommand & operator=(const FollowPathCommand &that);

      // Destructor
      virtual ~FollowPathCommand(void);

      // Equals overload
      bool operator==(const FollowPathCommand & that);
      bool operator!=(const FollowPathCommand & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual FollowPathCommand* clone() const;

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
      /** The first waypoint to follow. This should correspond to the number of a waypoint in the waypoint list. If this is zero, no waypoint will be followed. (Units: None)*/
      int64_t getFirstWaypoint(void) const { return __FirstWaypoint; }
      FollowPathCommand& setFirstWaypoint(const int64_t val);

      /** A list of waypoints to follow (Units: None)*/
      std::vector<afrl::cmasi::PathWaypoint*> & getWaypointList(void) { return __WaypointList; }

      /** Describes the start time for this action, in scenario time. If this field is zero, the action is completed immediately. (Units: milliseconds)*/
      int64_t getStartTime(void) const { return __StartTime; }
      FollowPathCommand& setStartTime(const int64_t val);

      /** Describes the end time for this action, in scenario time. If this field is zero, it should be ignored, otherwise The entity will travel until the stop time is reached. (Units: milliseconds)*/
      int64_t getStopTime(void) const { return __StopTime; }
      FollowPathCommand& setStopTime(const int64_t val);

      /** Describes how the entity should treat the end-of-path. Entities can complete the path once, or continuously.(Units: None)*/
      afrl::cmasi::TravelMode::TravelMode getRepeatMode(void) const { return __RepeatMode; }
      FollowPathCommand& setRepeatMode(const afrl::cmasi::TravelMode::TravelMode val);



   protected:
      /** The first waypoint to follow. This should correspond to the number of a waypoint in the waypoint list. If this is zero, no waypoint will be followed. */
      int64_t __FirstWaypoint;
      /** A list of waypoints to follow */
      std::vector< afrl::cmasi::PathWaypoint* > __WaypointList;
      /** Describes the start time for this action, in scenario time. If this field is zero, the action is completed immediately. */
      int64_t __StartTime;
      /** Describes the end time for this action, in scenario time. If this field is zero, it should be ignored, otherwise The entity will travel until the stop time is reached. */
      int64_t __StopTime;
      /** Describes how the entity should treat the end-of-path. Entities can complete the path once, or continuously.*/
      afrl::cmasi::TravelMode::TravelMode __RepeatMode;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_FOLLOWPATHCOMMAND_H_
