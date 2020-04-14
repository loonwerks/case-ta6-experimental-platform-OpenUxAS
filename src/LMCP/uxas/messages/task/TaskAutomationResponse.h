// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKAUTOMATIONRESPONSE_H_
#define _UXAS_MESSAGES_TASK_TASKAUTOMATIONRESPONSE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AutomationResponse.h"
#include "uxas/messages/task/PlanningState.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskAutomationResponse(avtas::lmcp::Object* obj);
   bool isTaskAutomationResponse(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskAutomationResponseDescendants();
   
   class TaskAutomationResponse : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskAutomationResponse(void);

      // Copy Constructor
      TaskAutomationResponse(const TaskAutomationResponse &that);

      // Assignment Operator
      TaskAutomationResponse & operator=(const TaskAutomationResponse &that);

      // Destructor
      virtual ~TaskAutomationResponse(void);

      // Equals overload
      bool operator==(const TaskAutomationResponse & that);
      bool operator!=(const TaskAutomationResponse & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskAutomationResponse* clone() const;

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
      /** Identifier for tracking requests and responses. Must match RequestID from corresponding TaskAutomationRequest (Units: None)*/
      int64_t getResponseID(void) const { return __ResponseID; }
      TaskAutomationResponse& setResponseID(const int64_t val);

      /** Original automation request without a unique identifier. A valid TaskAutomationResponse must define OriginalResponse (null not allowed). (Units: None)*/
      afrl::cmasi::AutomationResponse* const getOriginalResponse(void) { return __OriginalResponse; }
      TaskAutomationResponse& setOriginalResponse(const afrl::cmasi::AutomationResponse* const val);

      /** The final states of entities when the plan is completed. (Units: None)*/
      std::vector<uxas::messages::task::PlanningState*> & getFinalStates(void) { return __FinalStates; }



   protected:
      /** Identifier for tracking requests and responses. Must match RequestID from corresponding TaskAutomationRequest */
      int64_t __ResponseID;
      /** Original automation request without a unique identifier. A valid TaskAutomationResponse must define OriginalResponse (null not allowed). */
      afrl::cmasi::AutomationResponse* __OriginalResponse;
      /** The final states of entities when the plan is completed. */
      std::vector< uxas::messages::task::PlanningState* > __FinalStates;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKAUTOMATIONRESPONSE_H_
