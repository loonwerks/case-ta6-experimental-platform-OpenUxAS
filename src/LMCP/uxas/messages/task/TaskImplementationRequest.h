// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONREQUEST_H_
#define _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "uxas/messages/task/PlanningState.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskImplementationRequest(avtas::lmcp::Object* obj);
   bool isTaskImplementationRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskImplementationRequestDescendants();
   
   class TaskImplementationRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskImplementationRequest(void);

      // Copy Constructor
      TaskImplementationRequest(const TaskImplementationRequest &that);

      // Assignment Operator
      TaskImplementationRequest & operator=(const TaskImplementationRequest &that);

      // Destructor
      virtual ~TaskImplementationRequest(void);

      // Equals overload
      bool operator==(const TaskImplementationRequest & that);
      bool operator!=(const TaskImplementationRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskImplementationRequest* clone() const;

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
      /** Request ID for correlating to matching response (Units: None)*/
      int64_t getRequestID(void) const { return __RequestID; }
      TaskImplementationRequest& setRequestID(const int64_t val);

      /** This task implementation request is part of fulfilling a unique automation request (Units: None)*/
      int64_t getCorrespondingAutomationRequestID(void) const { return __CorrespondingAutomationRequestID; }
      TaskImplementationRequest& setCorrespondingAutomationRequestID(const int64_t val);

      /** Starting waypoint ID that task must use when building response. Note that Plan Builder reserves all values greater than 1,000,000,000. Therefore all *internal* task waypoints must be less than 1e9 and can be obtained from the reported waypoint number by "waypoint->getNumber()%1e9" .(Units: None)*/
      int64_t getStartingWaypointID(void) const { return __StartingWaypointID; }
      TaskImplementationRequest& setStartingWaypointID(const int64_t val);

      /** Assigned vehicle ID (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      TaskImplementationRequest& setVehicleID(const int64_t val);

      /** Initial position of entity before task. A valid TaskImplementationRequest must define StartPosition (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getStartPosition(void) { return __StartPosition; }
      TaskImplementationRequest& setStartPosition(const afrl::cmasi::Location3D* const val);

      /** Initial heading of entity before task (Units: degrees)*/
      float getStartHeading(void) const { return __StartHeading; }
      TaskImplementationRequest& setStartHeading(const float val);

      /** Time when vehicle is at the starting location (Units: milliseconds since 1 Jan 1970)*/
      int64_t getStartTime(void) const { return __StartTime; }
      TaskImplementationRequest& setStartTime(const int64_t val);

      /** ID for full region in which entity should plan (Units: None)*/
      int64_t getRegionID(void) const { return __RegionID; }
      TaskImplementationRequest& setRegionID(const int64_t val);

      /** Task ID to be completed (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskImplementationRequest& setTaskID(const int64_t val);

      /** Using option ID to complete this task (Units: None)*/
      int64_t getOptionID(void) const { return __OptionID; }
      TaskImplementationRequest& setOptionID(const int64_t val);

      /** Time before which this task cannot begin (Units: milliseconds since 1 Jan 1970)*/
      int64_t getTimeThreshold(void) const { return __TimeThreshold; }
      TaskImplementationRequest& setTimeThreshold(const int64_t val);

      /** Predicted locations and headings of all other entities at the point in the mission when this option is to be conducted. (Units: None)*/
      std::vector<uxas::messages::task::PlanningState*> & getNeighborLocations(void) { return __NeighborLocations; }



   protected:
      /** Request ID for correlating to matching response */
      int64_t __RequestID;
      /** This task implementation request is part of fulfilling a unique automation request */
      int64_t __CorrespondingAutomationRequestID;
      /** Starting waypoint ID that task must use when building response. Note that Plan Builder reserves all values greater than 1,000,000,000. Therefore all *internal* task waypoints must be less than 1e9 and can be obtained from the reported waypoint number by "waypoint->getNumber()%1e9" .*/
      int64_t __StartingWaypointID;
      /** Assigned vehicle ID */
      int64_t __VehicleID;
      /** Initial position of entity before task. A valid TaskImplementationRequest must define StartPosition (null not allowed). */
      afrl::cmasi::Location3D* __StartPosition;
      /** Initial heading of entity before task */
      float __StartHeading;
      /** Time when vehicle is at the starting location */
      int64_t __StartTime;
      /** ID for full region in which entity should plan */
      int64_t __RegionID;
      /** Task ID to be completed */
      int64_t __TaskID;
      /** Using option ID to complete this task */
      int64_t __OptionID;
      /** Time before which this task cannot begin */
      int64_t __TimeThreshold;
      /** Predicted locations and headings of all other entities at the point in the mission when this option is to be conducted. */
      std::vector< uxas::messages::task::PlanningState* > __NeighborLocations;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONREQUEST_H_
