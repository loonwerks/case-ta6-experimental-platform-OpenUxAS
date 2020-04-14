// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONRESPONSE_H_
#define _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONRESPONSE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/Location3D.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskImplementationResponse(avtas::lmcp::Object* obj);
   bool isTaskImplementationResponse(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskImplementationResponseDescendants();
   
   class TaskImplementationResponse : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskImplementationResponse(void);

      // Copy Constructor
      TaskImplementationResponse(const TaskImplementationResponse &that);

      // Assignment Operator
      TaskImplementationResponse & operator=(const TaskImplementationResponse &that);

      // Destructor
      virtual ~TaskImplementationResponse(void);

      // Equals overload
      bool operator==(const TaskImplementationResponse & that);
      bool operator!=(const TaskImplementationResponse & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskImplementationResponse* clone() const;

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
      /** Response ID that matches the initial request (Units: None)*/
      int64_t getResponseID(void) const { return __ResponseID; }
      TaskImplementationResponse& setResponseID(const int64_t val);

      /** This task implementation response is part of fulfilling a unique automation request (Units: None)*/
      int64_t getCorrespondingAutomationRequestID(void) const { return __CorrespondingAutomationRequestID; }
      TaskImplementationResponse& setCorrespondingAutomationRequestID(const int64_t val);

      /** Task ID (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskImplementationResponse& setTaskID(const int64_t val);

      /** Option ID that was selected for this task (Units: None)*/
      int64_t getOptionID(void) const { return __OptionID; }
      TaskImplementationResponse& setOptionID(const int64_t val);

      /** Vehicle ID (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      TaskImplementationResponse& setVehicleID(const int64_t val);

      /** Waypoints that implement this task for the indicated vehicle (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getTaskWaypoints(void) { return __TaskWaypoints; }

      /** Vehicle location when this task is complete. A valid TaskImplementationResponse must define FinalLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getFinalLocation(void) { return __FinalLocation; }
      TaskImplementationResponse& setFinalLocation(const afrl::cmasi::Location3D* const val);

      /** Vehicle heading when this task is complete (Units: degrees)*/
      float getFinalHeading(void) const { return __FinalHeading; }
      TaskImplementationResponse& setFinalHeading(const float val);

      /** Time when vehicle is at the final location (Units: milliseconds since 1 Jan 1970)*/
      int64_t getFinalTime(void) const { return __FinalTime; }
      TaskImplementationResponse& setFinalTime(const int64_t val);



   protected:
      /** Response ID that matches the initial request */
      int64_t __ResponseID;
      /** This task implementation response is part of fulfilling a unique automation request */
      int64_t __CorrespondingAutomationRequestID;
      /** Task ID */
      int64_t __TaskID;
      /** Option ID that was selected for this task */
      int64_t __OptionID;
      /** Vehicle ID */
      int64_t __VehicleID;
      /** Waypoints that implement this task for the indicated vehicle */
      std::vector< afrl::cmasi::Waypoint* > __TaskWaypoints;
      /** Vehicle location when this task is complete. A valid TaskImplementationResponse must define FinalLocation (null not allowed). */
      afrl::cmasi::Location3D* __FinalLocation;
      /** Vehicle heading when this task is complete */
      float __FinalHeading;
      /** Time when vehicle is at the final location */
      int64_t __FinalTime;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKIMPLEMENTATIONRESPONSE_H_
