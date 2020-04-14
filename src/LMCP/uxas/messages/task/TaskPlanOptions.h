// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKPLANOPTIONS_H_
#define _UXAS_MESSAGES_TASK_TASKPLANOPTIONS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/task/TaskOption.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskPlanOptions(avtas::lmcp::Object* obj);
   bool isTaskPlanOptions(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskPlanOptionsDescendants();
   
   class TaskPlanOptions : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskPlanOptions(void);

      // Copy Constructor
      TaskPlanOptions(const TaskPlanOptions &that);

      // Assignment Operator
      TaskPlanOptions & operator=(const TaskPlanOptions &that);

      // Destructor
      virtual ~TaskPlanOptions(void);

      // Equals overload
      bool operator==(const TaskPlanOptions & that);
      bool operator!=(const TaskPlanOptions & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskPlanOptions* clone() const;

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
      /** ID that matches this message with the appropriate unique automation request (Units: None)*/
      int64_t getCorrespondingAutomationRequestID(void) const { return __CorrespondingAutomationRequestID; }
      TaskPlanOptions& setCorrespondingAutomationRequestID(const int64_t val);

      /** Task ID (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskPlanOptions& setTaskID(const int64_t val);

      /** Process algebra string encoding all of the different options (Units: None)*/
      std::string getComposition(void) const { return __Composition; }
      TaskPlanOptions& setComposition(const std::string val);

      /** List of options. NOTE for computational reasons, the larger the number of options, the much greater the computation (Units: None)*/
      std::vector<uxas::messages::task::TaskOption*> & getOptions(void) { return __Options; }



   protected:
      /** ID that matches this message with the appropriate unique automation request */
      int64_t __CorrespondingAutomationRequestID;
      /** Task ID */
      int64_t __TaskID;
      /** Process algebra string encoding all of the different options */
      std::string __Composition;
      /** List of options. NOTE for computational reasons, the larger the number of options, the much greater the computation */
      std::vector< uxas::messages::task::TaskOption* > __Options;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKPLANOPTIONS_H_
