// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_VEHICLESUMMARY_H_
#define _AFRL_IMPACT_VEHICLESUMMARY_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Waypoint.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isVehicleSummary(avtas::lmcp::Object* obj);
   bool isVehicleSummary(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > VehicleSummaryDescendants();
   
   class VehicleSummary : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      VehicleSummary(void);

      // Copy Constructor
      VehicleSummary(const VehicleSummary &that);

      // Assignment Operator
      VehicleSummary & operator=(const VehicleSummary &that);

      // Destructor
      virtual ~VehicleSummary(void);

      // Equals overload
      bool operator==(const VehicleSummary & that);
      bool operator!=(const VehicleSummary & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual VehicleSummary* clone() const;

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
      /** ID of vehicle considered to complete 'DestinationTaskID' (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      VehicleSummary& setVehicleID(const int64_t val);

      /** ID of task for which 'VehicleID' is considered to perform (Units: None)*/
      int64_t getDestinationTaskID(void) const { return __DestinationTaskID; }
      VehicleSummary& setDestinationTaskID(const int64_t val);

      /** ID of task from which 'VehicleID' is considered leave from. If zero, from current position of vehicle (Units: None)*/
      int64_t getInitialTaskID(void) const { return __InitialTaskID; }
      VehicleSummary& setInitialTaskID(const int64_t val);

      /** Percentage along initial task that vehicle should plan from (Units: None)*/
      float getInitialTaskPercentage(void) const { return __InitialTaskPercentage; }
      VehicleSummary& setInitialTaskPercentage(const float val);

      /** Estimated time from start of task to task-percentage location (Units: milliseconds)*/
      int64_t getEstimateTimeToTaskPercentage(void) const { return __EstimateTimeToTaskPercentage; }
      VehicleSummary& setEstimateTimeToTaskPercentage(const int64_t val);

      /** Travel time from the current vehicle location to the start of the task. (Units: milliseconds)*/
      int64_t getTimeToArrive(void) const { return __TimeToArrive; }
      VehicleSummary& setTimeToArrive(const int64_t val);

      /** Time for this task to be completed by the specified vehicle (Units: milliseconds)*/
      int64_t getTimeOnTask(void) const { return __TimeOnTask; }
      VehicleSummary& setTimeOnTask(const int64_t val);

      /** Energy remaining for vehicle after task has been completed, expressed in terms of the percentage of maximum capacity (Units: %)*/
      float getEnergyRemaining(void) const { return __EnergyRemaining; }
      VehicleSummary& setEnergyRemaining(const float val);

      /** Flag for indicating that the vehicle will leave communication range either enroute or during the task (Units: None)*/
      bool getBeyondCommRange(void) const { return __BeyondCommRange; }
      VehicleSummary& setBeyondCommRange(const bool val);

      /** Flag for indicating that the vehicle will conflict with ROZ enroute or during the task (Units: None)*/
      bool getConflictsWithROZ(void) const { return __ConflictsWithROZ; }
      VehicleSummary& setConflictsWithROZ(const bool val);

      /** IDs of ROZs that the vehicle will conflict with (Units: None)*/
      std::vector<int64_t> & getROZIDs(void) { return __ROZIDs; }

      /** The list of waypoints associated with this mission task. Waypoints are linked, but the waypoint list may contain waypoints that are not necessarily linked. Multiple linked routes may be sent in a single waypoint list. Waypoints are not necessarily ordered in the list. (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getWaypointList(void) { return __WaypointList; }

      /** ID of the first waypoint in the plan. (Units: None)*/
      int64_t getFirstWaypoint(void) const { return __FirstWaypoint; }
      VehicleSummary& setFirstWaypoint(const int64_t val);



   protected:
      /** ID of vehicle considered to complete 'DestinationTaskID' */
      int64_t __VehicleID;
      /** ID of task for which 'VehicleID' is considered to perform */
      int64_t __DestinationTaskID;
      /** ID of task from which 'VehicleID' is considered leave from. If zero, from current position of vehicle */
      int64_t __InitialTaskID;
      /** Percentage along initial task that vehicle should plan from */
      float __InitialTaskPercentage;
      /** Estimated time from start of task to task-percentage location */
      int64_t __EstimateTimeToTaskPercentage;
      /** Travel time from the current vehicle location to the start of the task. */
      int64_t __TimeToArrive;
      /** Time for this task to be completed by the specified vehicle */
      int64_t __TimeOnTask;
      /** Energy remaining for vehicle after task has been completed, expressed in terms of the percentage of maximum capacity */
      float __EnergyRemaining;
      /** Flag for indicating that the vehicle will leave communication range either enroute or during the task */
      bool __BeyondCommRange;
      /** Flag for indicating that the vehicle will conflict with ROZ enroute or during the task */
      bool __ConflictsWithROZ;
      /** IDs of ROZs that the vehicle will conflict with */
      std::vector< int64_t > __ROZIDs;
      /** The list of waypoints associated with this mission task. Waypoints are linked, but the waypoint list may contain waypoints that are not necessarily linked. Multiple linked routes may be sent in a single waypoint list. Waypoints are not necessarily ordered in the list. */
      std::vector< afrl::cmasi::Waypoint* > __WaypointList;
      /** ID of the first waypoint in the plan. */
      int64_t __FirstWaypoint;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_VEHICLESUMMARY_H_
