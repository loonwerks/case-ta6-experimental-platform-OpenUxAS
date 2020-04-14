// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WAYPOINT_H_
#define _AFRL_CMASI_WAYPOINT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/SpeedType.h"
#include "afrl/cmasi/TurnType.h"
#include "afrl/cmasi/VehicleAction.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isWaypoint(avtas::lmcp::Object* obj);
   bool isWaypoint(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > WaypointDescendants();
   
   class Waypoint : public afrl::cmasi::Location3D {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      Waypoint(void);

      // Copy Constructor
      Waypoint(const Waypoint &that);

      // Assignment Operator
      Waypoint & operator=(const Waypoint &that);

      // Destructor
      virtual ~Waypoint(void);

      // Equals overload
      bool operator==(const Waypoint & that);
      bool operator!=(const Waypoint & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual Waypoint* clone() const;

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
      /** A unique waypoint number (Units: None)*/
      int64_t getNumber(void) const { return __Number; }
      Waypoint& setNumber(const int64_t val);

      /** The index of the next waypoint in the list. Consecutively numbered waypoints are <b>not</b> considered linked, the link must be explicitly stated in this field. (Units: None)*/
      int64_t getNextWaypoint(void) const { return __NextWaypoint; }
      Waypoint& setNextWaypoint(const int64_t val);

      /** Commanded speed for this waypoint. See SpeedType for defintion of this field. (Units: meter/sec)*/
      float getSpeed(void) const { return __Speed; }
      Waypoint& setSpeed(const float val);

      /** Type of commanded speed (Units: None)*/
      afrl::cmasi::SpeedType::SpeedType getSpeedType(void) const { return __SpeedType; }
      Waypoint& setSpeedType(const afrl::cmasi::SpeedType::SpeedType val);

      /** The commanded climb rate. Positive values upwards. For surface (ground and sea) entities, this value is ignored. (Units: meter/sec)*/
      float getClimbRate(void) const { return __ClimbRate; }
      Waypoint& setClimbRate(const float val);

      /** The type of turn to execute (Units: None)*/
      afrl::cmasi::TurnType::TurnType getTurnType(void) const { return __TurnType; }
      Waypoint& setTurnType(const afrl::cmasi::TurnType::TurnType val);

      /** A list of actions to perform at this waypoint (Units: None)*/
      std::vector<afrl::cmasi::VehicleAction*> & getVehicleActionList(void) { return __VehicleActionList; }

      /** A waypoint for contingency (e.g. lost-comm, alternate mission) operations. A value of zero denotes that no contingency point is specified. (Units: None)*/
      int64_t getContingencyWaypointA(void) const { return __ContingencyWaypointA; }
      Waypoint& setContingencyWaypointA(const int64_t val);

      /** A waypoint for contingency (e.g. lost-comm, alternate mission) operations. A value of zero denotes that no contingency point is specified. (Units: None)*/
      int64_t getContingencyWaypointB(void) const { return __ContingencyWaypointB; }
      Waypoint& setContingencyWaypointB(const int64_t val);

      /** A list of tasks that are associated with this waypoint. A length of zero denotes no associated tasks. This field is for analysis purposes. The automation service should associate a list of tasks with each waypoint to enable analysis of the allocation of tasks to vehicles. (Units: None)*/
      std::vector<int64_t> & getAssociatedTasks(void) { return __AssociatedTasks; }



   protected:
      /** A unique waypoint number */
      int64_t __Number;
      /** The index of the next waypoint in the list. Consecutively numbered waypoints are <b>not</b> considered linked, the link must be explicitly stated in this field. */
      int64_t __NextWaypoint;
      /** Commanded speed for this waypoint. See SpeedType for defintion of this field. */
      float __Speed;
      /** Type of commanded speed */
      afrl::cmasi::SpeedType::SpeedType __SpeedType;
      /** The commanded climb rate. Positive values upwards. For surface (ground and sea) entities, this value is ignored. */
      float __ClimbRate;
      /** The type of turn to execute */
      afrl::cmasi::TurnType::TurnType __TurnType;
      /** A list of actions to perform at this waypoint */
      std::vector< afrl::cmasi::VehicleAction* > __VehicleActionList;
      /** A waypoint for contingency (e.g. lost-comm, alternate mission) operations. A value of zero denotes that no contingency point is specified. */
      int64_t __ContingencyWaypointA;
      /** A waypoint for contingency (e.g. lost-comm, alternate mission) operations. A value of zero denotes that no contingency point is specified. */
      int64_t __ContingencyWaypointB;
      /** A list of tasks that are associated with this waypoint. A length of zero denotes no associated tasks. This field is for analysis purposes. The automation service should associate a list of tasks with each waypoint to enable analysis of the allocation of tasks to vehicles. */
      std::vector< int64_t > __AssociatedTasks;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WAYPOINT_H_
