// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_MISSIONCOMMAND_H_
#define _AFRL_CMASI_MISSIONCOMMAND_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/VehicleActionCommand.h"
#include "afrl/cmasi/Waypoint.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isMissionCommand(avtas::lmcp::Object* obj);
   bool isMissionCommand(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > MissionCommandDescendants();
   
   class MissionCommand : public afrl::cmasi::VehicleActionCommand {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      MissionCommand(void);

      // Copy Constructor
      MissionCommand(const MissionCommand &that);

      // Assignment Operator
      MissionCommand & operator=(const MissionCommand &that);

      // Destructor
      virtual ~MissionCommand(void);

      // Equals overload
      bool operator==(const MissionCommand & that);
      bool operator!=(const MissionCommand & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual MissionCommand* clone() const;

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
      /** The list of waypoints associated with this mission task. Waypoints are linked, but the waypoint list may contain waypoints that are not necessarily linked. Multiple linked routes may be sent in a single waypoint list. Waypoints are not necessarily ordered in the list. (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getWaypointList(void) { return __WaypointList; }

      /** ID of the first waypoint to follow. (Units: None)*/
      int64_t getFirstWaypoint(void) const { return __FirstWaypoint; }
      MissionCommand& setFirstWaypoint(const int64_t val);



   protected:
      /** The list of waypoints associated with this mission task. Waypoints are linked, but the waypoint list may contain waypoints that are not necessarily linked. Multiple linked routes may be sent in a single waypoint list. Waypoints are not necessarily ordered in the list. */
      std::vector< afrl::cmasi::Waypoint* > __WaypointList;
      /** ID of the first waypoint to follow. */
      int64_t __FirstWaypoint;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_MISSIONCOMMAND_H_
