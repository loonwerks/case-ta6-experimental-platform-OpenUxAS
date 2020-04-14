// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKAUTOMATIONREQUEST_H_
#define _UXAS_MESSAGES_TASK_TASKAUTOMATIONREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AutomationRequest.h"
#include "uxas/messages/task/PlanningState.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskAutomationRequest(avtas::lmcp::Object* obj);
   bool isTaskAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskAutomationRequestDescendants();
   
   class TaskAutomationRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskAutomationRequest(void);

      // Copy Constructor
      TaskAutomationRequest(const TaskAutomationRequest &that);

      // Assignment Operator
      TaskAutomationRequest & operator=(const TaskAutomationRequest &that);

      // Destructor
      virtual ~TaskAutomationRequest(void);

      // Equals overload
      bool operator==(const TaskAutomationRequest & that);
      bool operator!=(const TaskAutomationRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskAutomationRequest* clone() const;

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
      /** Identifier for tracking requests and responses (Units: None)*/
      int64_t getRequestID(void) const { return __RequestID; }
      TaskAutomationRequest& setRequestID(const int64_t val);

      /** Original automation request without a unique identifier. A valid TaskAutomationRequest must define OriginalRequest (null not allowed). (Units: None)*/
      afrl::cmasi::AutomationRequest* const getOriginalRequest(void) { return __OriginalRequest; }
      TaskAutomationRequest& setOriginalRequest(const afrl::cmasi::AutomationRequest* const val);

      /** If this boolean is true, then the resulting plans based on this automation request will not be directly implemented, for example, tasks should not expect the waypoints generated for this request to be active (Units: None)*/
      bool getSandBoxRequest(void) const { return __SandBoxRequest; }
      TaskAutomationRequest& setSandBoxRequest(const bool val);

      /** The initial states of entities used in planning. Note: if an eligible entity does not have a PlanningState, then it's most recent EntityState is used for plannning. (Units: None)*/
      std::vector<uxas::messages::task::PlanningState*> & getPlanningStates(void) { return __PlanningStates; }



   protected:
      /** Identifier for tracking requests and responses */
      int64_t __RequestID;
      /** Original automation request without a unique identifier. A valid TaskAutomationRequest must define OriginalRequest (null not allowed). */
      afrl::cmasi::AutomationRequest* __OriginalRequest;
      /** If this boolean is true, then the resulting plans based on this automation request will not be directly implemented, for example, tasks should not expect the waypoints generated for this request to be active */
      bool __SandBoxRequest;
      /** The initial states of entities used in planning. Note: if an eligible entity does not have a PlanningState, then it's most recent EntityState is used for plannning. */
      std::vector< uxas::messages::task::PlanningState* > __PlanningStates;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKAUTOMATIONREQUEST_H_
