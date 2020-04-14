// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKOPTIONCOST_H_
#define _UXAS_MESSAGES_TASK_TASKOPTIONCOST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"



namespace uxas {
namespace messages {
namespace task {


   bool isTaskOptionCost(avtas::lmcp::Object* obj);
   bool isTaskOptionCost(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskOptionCostDescendants();
   
   class TaskOptionCost : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskOptionCost(void);

      // Copy Constructor
      TaskOptionCost(const TaskOptionCost &that);

      // Assignment Operator
      TaskOptionCost & operator=(const TaskOptionCost &that);

      // Destructor
      virtual ~TaskOptionCost(void);

      // Equals overload
      bool operator==(const TaskOptionCost & that);
      bool operator!=(const TaskOptionCost & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskOptionCost* clone() const;

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
      /** Corresponding Vehicle ID (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      TaskOptionCost& setVehicleID(const int64_t val);

      /** Initial task ID (if zero, corresponds to current vehicle location) (Units: None)*/
      int64_t getIntialTaskID(void) const { return __IntialTaskID; }
      TaskOptionCost& setIntialTaskID(const int64_t val);

      /** Initial task option (Units: None)*/
      int64_t getIntialTaskOption(void) const { return __IntialTaskOption; }
      TaskOptionCost& setIntialTaskOption(const int64_t val);

      /** Destination task ID (Units: None)*/
      int64_t getDestinationTaskID(void) const { return __DestinationTaskID; }
      TaskOptionCost& setDestinationTaskID(const int64_t val);

      /** Destination task option (Units: None)*/
      int64_t getDestinationTaskOption(void) const { return __DestinationTaskOption; }
      TaskOptionCost& setDestinationTaskOption(const int64_t val);

      /** Timing corresponding to travel between ('InitialTask' using 'InitialTaskOption') and ('DestinationTask' using 'DestinationTaskOption'). If time is less than zero, no feasible path exists between tasks. (Units: milliseconds)*/
      int64_t getTimeToGo(void) const { return __TimeToGo; }
      TaskOptionCost& setTimeToGo(const int64_t val);



   protected:
      /** Corresponding Vehicle ID */
      int64_t __VehicleID;
      /** Initial task ID (if zero, corresponds to current vehicle location) */
      int64_t __IntialTaskID;
      /** Initial task option */
      int64_t __IntialTaskOption;
      /** Destination task ID */
      int64_t __DestinationTaskID;
      /** Destination task option */
      int64_t __DestinationTaskOption;
      /** Timing corresponding to travel between ('InitialTask' using 'InitialTaskOption') and ('DestinationTask' using 'DestinationTaskOption'). If time is less than zero, no feasible path exists between tasks. */
      int64_t __TimeToGo;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKOPTIONCOST_H_
