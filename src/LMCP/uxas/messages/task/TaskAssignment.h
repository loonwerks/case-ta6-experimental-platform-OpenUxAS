// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKASSIGNMENT_H_
#define _UXAS_MESSAGES_TASK_TASKASSIGNMENT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"



namespace uxas {
namespace messages {
namespace task {


   bool isTaskAssignment(avtas::lmcp::Object* obj);
   bool isTaskAssignment(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskAssignmentDescendants();
   
   class TaskAssignment : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskAssignment(void);

      // Copy Constructor
      TaskAssignment(const TaskAssignment &that);

      // Assignment Operator
      TaskAssignment & operator=(const TaskAssignment &that);

      // Destructor
      virtual ~TaskAssignment(void);

      // Equals overload
      bool operator==(const TaskAssignment & that);
      bool operator!=(const TaskAssignment & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskAssignment* clone() const;

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
      /** Task ID (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskAssignment& setTaskID(const int64_t val);

      /** Option ID that was selected for this task (Units: None)*/
      int64_t getOptionID(void) const { return __OptionID; }
      TaskAssignment& setOptionID(const int64_t val);

      /** Vehicle that is assigned to this task (Units: None)*/
      int64_t getAssignedVehicle(void) const { return __AssignedVehicle; }
      TaskAssignment& setAssignedVehicle(const int64_t val);

      /** Time before which this task cannot begin (Units: milliseconds since 1 Jan 1970)*/
      int64_t getTimeThreshold(void) const { return __TimeThreshold; }
      TaskAssignment& setTimeThreshold(const int64_t val);

      /** Time that this task is assigned to be completed. (Units: milliseconds since 1 Jan 1970)*/
      int64_t getTimeTaskCompleted(void) const { return __TimeTaskCompleted; }
      TaskAssignment& setTimeTaskCompleted(const int64_t val);



   protected:
      /** Task ID */
      int64_t __TaskID;
      /** Option ID that was selected for this task */
      int64_t __OptionID;
      /** Vehicle that is assigned to this task */
      int64_t __AssignedVehicle;
      /** Time before which this task cannot begin */
      int64_t __TimeThreshold;
      /** Time that this task is assigned to be completed. */
      int64_t __TimeTaskCompleted;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKASSIGNMENT_H_
