// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKRESUME_H_
#define _UXAS_MESSAGES_TASK_TASKRESUME_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/task/TaskAssignment.h"



namespace uxas {
namespace messages {
namespace task {


   bool isTaskResume(avtas::lmcp::Object* obj);
   bool isTaskResume(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskResumeDescendants();
   
   class TaskResume : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskResume(void);

      // Copy Constructor
      TaskResume(const TaskResume &that);

      // Assignment Operator
      TaskResume & operator=(const TaskResume &that);

      // Destructor
      virtual ~TaskResume(void);

      // Equals overload
      bool operator==(const TaskResume & that);
      bool operator!=(const TaskResume & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskResume* clone() const;

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
      TaskResume& setTaskID(const int64_t val);

      /** Instead of resuming from paused task state, re-start the complete task (Units: None)*/
      bool getRestartCompletely(void) const { return __RestartCompletely; }
      TaskResume& setRestartCompletely(const bool val);

      /** Instead of resuming from paused task state with the previously assigned entities, resume task with new assignment options. Only used when not null. (Units: None)*/
      uxas::messages::task::TaskAssignment* const getReAssign(void) { return __ReAssign; }
      TaskResume& setReAssign(const uxas::messages::task::TaskAssignment* const val);



   protected:
      /** Task ID */
      int64_t __TaskID;
      /** Instead of resuming from paused task state, re-start the complete task */
      bool __RestartCompletely;
      /** Instead of resuming from paused task state with the previously assigned entities, resume task with new assignment options. Only used when not null. */
      uxas::messages::task::TaskAssignment* __ReAssign;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKRESUME_H_
