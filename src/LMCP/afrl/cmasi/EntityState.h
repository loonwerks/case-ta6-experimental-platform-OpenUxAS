// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_ENTITYSTATE_H_
#define _AFRL_CMASI_ENTITYSTATE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/PayloadState.h"
#include "afrl/cmasi/NavigationMode.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isEntityState(avtas::lmcp::Object* obj);
   bool isEntityState(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > EntityStateDescendants();
   
   class EntityState : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      EntityState(void);

      // Copy Constructor
      EntityState(const EntityState &that);

      // Assignment Operator
      EntityState & operator=(const EntityState &that);

      // Destructor
      virtual ~EntityState(void);

      // Equals overload
      bool operator==(const EntityState & that);
      bool operator!=(const EntityState & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual EntityState* clone() const;

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
      /** A unique ID for this entity. IDs should be greater than zero (Units: None)*/
      int64_t getID(void) const { return __ID; }
      EntityState& setID(const int64_t val);

      /** Velocity in the body x-direction (postive out nose) (Units: meter/sec)*/
      float getU(void) const { return __u; }
      EntityState& setU(const float val);

      /** Velocity in the body y-direction (positive out right wing) (Units: meter/sec)*/
      float getV(void) const { return __v; }
      EntityState& setV(const float val);

      /** Velocity in the body z-direction (positve downward) (Units: meter/sec)*/
      float getW(void) const { return __w; }
      EntityState& setW(const float val);

      /** Acceleration in the body x-direction (postive out nose) (Units: meter/sec/sec)*/
      float getUdot(void) const { return __udot; }
      EntityState& setUdot(const float val);

      /** Acceleration in the body y-direction (positive out right wing) (Units: meter/sec/sec)*/
      float getVdot(void) const { return __vdot; }
      EntityState& setVdot(const float val);

      /** Acceleration in the body z-direction (positve downward) (Units: meter/sec/sec)*/
      float getWdot(void) const { return __wdot; }
      EntityState& setWdot(const float val);

      /** Angle between true North and the projection of the body x-axis in the North-East plane. (Units: degree)*/
      float getHeading(void) const { return __Heading; }
      EntityState& setHeading(const float val);

      /** Pitch of vehicle around body y-axis (positive upwards) (Units: degree)*/
      float getPitch(void) const { return __Pitch; }
      EntityState& setPitch(const float val);

      /** Roll angle of the vehicle around body x-axis (positive right wing down) (Units: degree)*/
      float getRoll(void) const { return __Roll; }
      EntityState& setRoll(const float val);

      /** roll-rate of vehicle (angular velocity around body x-axis). Positive right-wing down. (Units: degree/sec)*/
      float getP(void) const { return __p; }
      EntityState& setP(const float val);

      /** pitch rate of the vehicle (angular velocity around body y-axis). Positive nose-up.(Units: degree/sec)*/
      float getQ(void) const { return __q; }
      EntityState& setQ(const float val);

      /** yaw rate of the vehicle (angular velocity around body z-axis). Positive nose right. (Units: degree/sec)*/
      float getR(void) const { return __r; }
      EntityState& setR(const float val);

      /** Course/Groundtrack angle of the entity referenced to true North (Units: degrees)*/
      float getCourse(void) const { return __Course; }
      EntityState& setCourse(const float val);

      /** Current entity ground speed (Units: m/s)*/
      float getGroundspeed(void) const { return __Groundspeed; }
      EntityState& setGroundspeed(const float val);

      /** The perceived entity location. A valid EntityState must include Location (null not allowed) (Units: None)*/
      afrl::cmasi::Location3D* const getLocation(void) { return __Location; }
      EntityState& setLocation(const afrl::cmasi::Location3D* const val);

      /** The available energy remaining, expressed in terms of the percentage of maximum capacity (Units: %)*/
      float getEnergyAvailable(void) const { return __EnergyAvailable; }
      EntityState& setEnergyAvailable(const float val);

      /** The consumption rate of available energy, expressed in terms of the percentage of maximum capacity used per second. (Units: %/sec)*/
      float getActualEnergyRate(void) const { return __ActualEnergyRate; }
      EntityState& setActualEnergyRate(const float val);

      /** A list of states for any onboard payloads (Units: None)*/
      std::vector<afrl::cmasi::PayloadState*> & getPayloadStateList(void) { return __PayloadStateList; }

      /** The ID of the current waypoint. Only valid if the vehicle is in waypoint following mode. (Units: None)*/
      int64_t getCurrentWaypoint(void) const { return __CurrentWaypoint; }
      EntityState& setCurrentWaypoint(const int64_t val);

      /** Current command (VehicleActionCommand or MissionCommand) being executed. A value of zero denotes no command being executed, or that a command without an set identifier (CommandID) is being executed. (Units: None)*/
      int64_t getCurrentCommand(void) const { return __CurrentCommand; }
      EntityState& setCurrentCommand(const int64_t val);

      /** The current mode for this vehicle. (Units: None)*/
      afrl::cmasi::NavigationMode::NavigationMode getMode(void) const { return __Mode; }
      EntityState& setMode(const afrl::cmasi::NavigationMode::NavigationMode val);

      /** Tasks that this entity is currently executing. An empty list indicates no associated tasks. The task number should coincide with the task number in the task request. For instance, if a waypoint is associated with a search task, then the task number associated with that search should be included in this list. (Units: None)*/
      std::vector<int64_t> & getAssociatedTasks(void) { return __AssociatedTasks; }

      /** time stamp of this data. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 (Units: millisecond)*/
      int64_t getTime(void) const { return __Time; }
      EntityState& setTime(const int64_t val);

      /** A list that maps keys to values for the inclusion of extra, custom information about this entity (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getInfo(void) { return __Info; }



   protected:
      /** A unique ID for this entity. IDs should be greater than zero */
      int64_t __ID;
      /** Velocity in the body x-direction (postive out nose) */
      float __u;
      /** Velocity in the body y-direction (positive out right wing) */
      float __v;
      /** Velocity in the body z-direction (positve downward) */
      float __w;
      /** Acceleration in the body x-direction (postive out nose) */
      float __udot;
      /** Acceleration in the body y-direction (positive out right wing) */
      float __vdot;
      /** Acceleration in the body z-direction (positve downward) */
      float __wdot;
      /** Angle between true North and the projection of the body x-axis in the North-East plane. */
      float __Heading;
      /** Pitch of vehicle around body y-axis (positive upwards) */
      float __Pitch;
      /** Roll angle of the vehicle around body x-axis (positive right wing down) */
      float __Roll;
      /** roll-rate of vehicle (angular velocity around body x-axis). Positive right-wing down. */
      float __p;
      /** pitch rate of the vehicle (angular velocity around body y-axis). Positive nose-up.*/
      float __q;
      /** yaw rate of the vehicle (angular velocity around body z-axis). Positive nose right. */
      float __r;
      /** Course/Groundtrack angle of the entity referenced to true North */
      float __Course;
      /** Current entity ground speed */
      float __Groundspeed;
      /** The perceived entity location. A valid EntityState must include Location (null not allowed) */
      afrl::cmasi::Location3D* __Location;
      /** The available energy remaining, expressed in terms of the percentage of maximum capacity */
      float __EnergyAvailable;
      /** The consumption rate of available energy, expressed in terms of the percentage of maximum capacity used per second. */
      float __ActualEnergyRate;
      /** A list of states for any onboard payloads */
      std::vector< afrl::cmasi::PayloadState* > __PayloadStateList;
      /** The ID of the current waypoint. Only valid if the vehicle is in waypoint following mode. */
      int64_t __CurrentWaypoint;
      /** Current command (VehicleActionCommand or MissionCommand) being executed. A value of zero denotes no command being executed, or that a command without an set identifier (CommandID) is being executed. */
      int64_t __CurrentCommand;
      /** The current mode for this vehicle. */
      afrl::cmasi::NavigationMode::NavigationMode __Mode;
      /** Tasks that this entity is currently executing. An empty list indicates no associated tasks. The task number should coincide with the task number in the task request. For instance, if a waypoint is associated with a search task, then the task number associated with that search should be included in this list. */
      std::vector< int64_t > __AssociatedTasks;
      /** time stamp of this data. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 */
      int64_t __Time;
      /** A list that maps keys to values for the inclusion of extra, custom information about this entity */
      std::vector< afrl::cmasi::KeyValuePair* > __Info;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_ENTITYSTATE_H_
