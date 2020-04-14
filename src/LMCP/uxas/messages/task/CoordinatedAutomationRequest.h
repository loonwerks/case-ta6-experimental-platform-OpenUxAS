// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_COORDINATEDAUTOMATIONREQUEST_H_
#define _UXAS_MESSAGES_TASK_COORDINATEDAUTOMATIONREQUEST_H_

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


   bool isCoordinatedAutomationRequest(avtas::lmcp::Object* obj);
   bool isCoordinatedAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > CoordinatedAutomationRequestDescendants();
   
   class CoordinatedAutomationRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      CoordinatedAutomationRequest(void);

      // Copy Constructor
      CoordinatedAutomationRequest(const CoordinatedAutomationRequest &that);

      // Assignment Operator
      CoordinatedAutomationRequest & operator=(const CoordinatedAutomationRequest &that);

      // Destructor
      virtual ~CoordinatedAutomationRequest(void);

      // Equals overload
      bool operator==(const CoordinatedAutomationRequest & that);
      bool operator!=(const CoordinatedAutomationRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual CoordinatedAutomationRequest* clone() const;

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
      /** Identifier for tracking requests and coordination (Units: None)*/
      int64_t getRequestID(void) const { return __RequestID; }
      CoordinatedAutomationRequest& setRequestID(const int64_t val);

      /** This is the maximum time to wait for {@link AssignmentCoordination} messages from the other eligible entities, before proceeding with the assignment. Note: the value of -1 indicates that there is no limit. If there are no eligble entites listed in the {@link CoordinatedAutomationRequest}, then {@link MaximumResponseTime} is the amount of time the {@link AssignmentCoordinatorTask} waits for {@link AssignmentCoordination} messages before proceeding with the assignment. Note: if there are no eligble entities and the {@link MaximumResponseTime} is -1, then the {@link AssignmentCoordination} proceeds with the assignment immediately. (Units: milliseconds)*/
      int64_t getMaximumResponseTime(void) const { return __MaximumResponseTime; }
      CoordinatedAutomationRequest& setMaximumResponseTime(const int64_t val);

      /** Original automation request without a unique identifier. A valid CoordinatedAutomationRequest must define OriginalRequest (null not allowed). (Units: None)*/
      afrl::cmasi::AutomationRequest* const getOriginalRequest(void) { return __OriginalRequest; }
      CoordinatedAutomationRequest& setOriginalRequest(const afrl::cmasi::AutomationRequest* const val);

      /** The initial states of entities used in planning. Note: if an eligible entity does not have a PlanningState, then it must be obtained from the entity in an {@link AssignmentCoordination} message. (Units: None)*/
      std::vector<uxas::messages::task::PlanningState*> & getPlanningStates(void) { return __PlanningStates; }



   protected:
      /** Identifier for tracking requests and coordination */
      int64_t __RequestID;
      /** This is the maximum time to wait for {@link AssignmentCoordination} messages from the other eligible entities, before proceeding with the assignment. Note: the value of -1 indicates that there is no limit. If there are no eligble entites listed in the {@link CoordinatedAutomationRequest}, then {@link MaximumResponseTime} is the amount of time the {@link AssignmentCoordinatorTask} waits for {@link AssignmentCoordination} messages before proceeding with the assignment. Note: if there are no eligble entities and the {@link MaximumResponseTime} is -1, then the {@link AssignmentCoordination} proceeds with the assignment immediately. */
      int64_t __MaximumResponseTime;
      /** Original automation request without a unique identifier. A valid CoordinatedAutomationRequest must define OriginalRequest (null not allowed). */
      afrl::cmasi::AutomationRequest* __OriginalRequest;
      /** The initial states of entities used in planning. Note: if an eligible entity does not have a PlanningState, then it must be obtained from the entity in an {@link AssignmentCoordination} message. */
      std::vector< uxas::messages::task::PlanningState* > __PlanningStates;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_COORDINATEDAUTOMATIONREQUEST_H_
