// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_TASKTIMINGPAIR_H_
#define _AFRL_IMPACT_TASKTIMINGPAIR_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"



namespace afrl {
namespace impact {


   bool isTaskTimingPair(avtas::lmcp::Object* obj);
   bool isTaskTimingPair(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskTimingPairDescendants();
   
   class TaskTimingPair : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskTimingPair(void);

      // Copy Constructor
      TaskTimingPair(const TaskTimingPair &that);

      // Assignment Operator
      TaskTimingPair & operator=(const TaskTimingPair &that);

      // Destructor
      virtual ~TaskTimingPair(void);

      // Equals overload
      bool operator==(const TaskTimingPair & that);
      bool operator!=(const TaskTimingPair & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskTimingPair* clone() const;

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
      TaskTimingPair& setVehicleID(const int64_t val);

      /** Initial task ID (if zero, corresponds to current vehicle location) (Units: None)*/
      int64_t getInitialTaskID(void) const { return __InitialTaskID; }
      TaskTimingPair& setInitialTaskID(const int64_t val);

      /** Normalized progress along initial task (0.0 .. 1.0) (Units: None)*/
      float getInitialTaskPercentage(void) const { return __InitialTaskPercentage; }
      TaskTimingPair& setInitialTaskPercentage(const float val);

      /** Destination task ID (Units: None)*/
      int64_t getDestinationTaskID(void) const { return __DestinationTaskID; }
      TaskTimingPair& setDestinationTaskID(const int64_t val);

      /** Timing corresponding to travel between tasks. If time is less than zero, no feasible path exists between tasks. If 'DestinationTaskID' is equal to 'InitialTaskID' then 'TimeToGo' is the time to complete the task when performed by 'VehicleID' (Units: milliseconds)*/
      int64_t getTimeToGo(void) const { return __TimeToGo; }
      TaskTimingPair& setTimeToGo(const int64_t val);



   protected:
      /** Corresponding Vehicle ID */
      int64_t __VehicleID;
      /** Initial task ID (if zero, corresponds to current vehicle location) */
      int64_t __InitialTaskID;
      /** Normalized progress along initial task (0.0 .. 1.0) */
      float __InitialTaskPercentage;
      /** Destination task ID */
      int64_t __DestinationTaskID;
      /** Timing corresponding to travel between tasks. If time is less than zero, no feasible path exists between tasks. If 'DestinationTaskID' is equal to 'InitialTaskID' then 'TimeToGo' is the time to complete the task when performed by 'VehicleID' */
      int64_t __TimeToGo;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_TASKTIMINGPAIR_H_
