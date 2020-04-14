// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_RENDEZVOUSTASK_H_
#define _UXAS_MESSAGES_TASK_RENDEZVOUSTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "afrl/cmasi/Task.h"
#include "uxas/messages/task/PlanningState.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isRendezvousTask(avtas::lmcp::Object* obj);
   bool isRendezvousTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RendezvousTaskDescendants();
   
   class RendezvousTask : public afrl::cmasi::Task {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RendezvousTask(void);

      // Copy Constructor
      RendezvousTask(const RendezvousTask &that);

      // Assignment Operator
      RendezvousTask & operator=(const RendezvousTask &that);

      // Destructor
      virtual ~RendezvousTask(void);

      // Equals overload
      bool operator==(const RendezvousTask & that);
      bool operator!=(const RendezvousTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RendezvousTask* clone() const;

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
      /** Number of vehicles that will participate in the rendezvous. To restrict the available participants, use the 'EligibleEntities' field. If the number of participants is exactly equal to the number of eligible entities, then this task will only produce a single option that ensures those exact entities meet at the rendezvous location. (Units: None)*/
      uint8_t getNumberOfParticipants(void) const { return __NumberOfParticipants; }
      RendezvousTask& setNumberOfParticipants(const uint8_t val);

      /** The desired rendezvous states of the entities. If the EntityID fields are set to 0, then any eligible vehicle can be used at that location. Only used when 'MultiLocationRendezvous' is set to 'true'. If the EntityID fields are non-zero, they must correspond to an eligible vehicle and only that particular entity will be used at that position. (Units: None)*/
      std::vector<uxas::messages::task::PlanningState*> & getRendezvousStates(void) { return __RendezvousStates; }



   protected:
      /** Number of vehicles that will participate in the rendezvous. To restrict the available participants, use the 'EligibleEntities' field. If the number of participants is exactly equal to the number of eligible entities, then this task will only produce a single option that ensures those exact entities meet at the rendezvous location. */
      uint8_t __NumberOfParticipants;
      /** The desired rendezvous states of the entities. If the EntityID fields are set to 0, then any eligible vehicle can be used at that location. Only used when 'MultiLocationRendezvous' is set to 'true'. If the EntityID fields are non-zero, they must correspond to an eligible vehicle and only that particular entity will be used at that position. */
      std::vector< uxas::messages::task::PlanningState* > __RendezvousStates;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_RENDEZVOUSTASK_H_
