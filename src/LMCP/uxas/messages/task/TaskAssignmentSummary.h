// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKASSIGNMENTSUMMARY_H_
#define _UXAS_MESSAGES_TASK_TASKASSIGNMENTSUMMARY_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/task/TaskAssignment.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskAssignmentSummary(avtas::lmcp::Object* obj);
   bool isTaskAssignmentSummary(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskAssignmentSummaryDescendants();
   
   class TaskAssignmentSummary : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskAssignmentSummary(void);

      // Copy Constructor
      TaskAssignmentSummary(const TaskAssignmentSummary &that);

      // Assignment Operator
      TaskAssignmentSummary & operator=(const TaskAssignmentSummary &that);

      // Destructor
      virtual ~TaskAssignmentSummary(void);

      // Equals overload
      bool operator==(const TaskAssignmentSummary & that);
      bool operator!=(const TaskAssignmentSummary & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskAssignmentSummary* clone() const;

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
      /** ID that matches this summary with the appropriate unique automation request (Units: None)*/
      int64_t getCorrespondingAutomationRequestID(void) const { return __CorrespondingAutomationRequestID; }
      TaskAssignmentSummary& setCorrespondingAutomationRequestID(const int64_t val);

      /** Operating region which was considered during this assignment (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      TaskAssignmentSummary& setOperatingRegion(const int64_t val);

      /** Ordered list of tasks to be completed (Units: None)*/
      std::vector<uxas::messages::task::TaskAssignment*> & getTaskList(void) { return __TaskList; }



   protected:
      /** ID that matches this summary with the appropriate unique automation request */
      int64_t __CorrespondingAutomationRequestID;
      /** Operating region which was considered during this assignment */
      int64_t __OperatingRegion;
      /** Ordered list of tasks to be completed */
      std::vector< uxas::messages::task::TaskAssignment* > __TaskList;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKASSIGNMENTSUMMARY_H_
