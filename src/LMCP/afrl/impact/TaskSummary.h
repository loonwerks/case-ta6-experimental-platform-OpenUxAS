// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_TASKSUMMARY_H_
#define _AFRL_IMPACT_TASKSUMMARY_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/impact/VehicleSummary.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isTaskSummary(avtas::lmcp::Object* obj);
   bool isTaskSummary(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskSummaryDescendants();
   
   class TaskSummary : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskSummary(void);

      // Copy Constructor
      TaskSummary(const TaskSummary &that);

      // Assignment Operator
      TaskSummary & operator=(const TaskSummary &that);

      // Destructor
      virtual ~TaskSummary(void);

      // Equals overload
      bool operator==(const TaskSummary & that);
      bool operator!=(const TaskSummary & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskSummary* clone() const;

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
      /** ID of task in consideration (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskSummary& setTaskID(const int64_t val);

      /** Summary of information for each vehicle used simultaneously to complete this task. If there are zero performing vehicles, then 'TaskID' cannot be completed with any set of available vehicles in the system. (Units: None)*/
      std::vector<afrl::impact::VehicleSummary*> & getPerformingVehicles(void) { return __PerformingVehicles; }

      /** Task cannot be completed as specified and is using best effort. Estimated percent achieved while using best effort strategy. (Units: %)*/
      float getBestEffort(void) const { return __BestEffort; }
      TaskSummary& setBestEffort(const float val);



   protected:
      /** ID of task in consideration */
      int64_t __TaskID;
      /** Summary of information for each vehicle used simultaneously to complete this task. If there are zero performing vehicles, then 'TaskID' cannot be completed with any set of available vehicles in the system. */
      std::vector< afrl::impact::VehicleSummary* > __PerformingVehicles;
      /** Task cannot be completed as specified and is using best effort. Estimated percent achieved while using best effort strategy. */
      float __BestEffort;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_TASKSUMMARY_H_
