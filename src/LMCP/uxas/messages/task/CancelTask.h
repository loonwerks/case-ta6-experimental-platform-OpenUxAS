// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_CANCELTASK_H_
#define _UXAS_MESSAGES_TASK_CANCELTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isCancelTask(avtas::lmcp::Object* obj);
   bool isCancelTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > CancelTaskDescendants();
   
   class CancelTask : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      CancelTask(void);

      // Copy Constructor
      CancelTask(const CancelTask &that);

      // Assignment Operator
      CancelTask & operator=(const CancelTask &that);

      // Destructor
      virtual ~CancelTask(void);

      // Equals overload
      bool operator==(const CancelTask & that);
      bool operator!=(const CancelTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual CancelTask* clone() const;

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
      /** List of vehicle IDs that are directed to cancel tasks. If empty, all vehicles currently on a listed task will be directed to cancel. (Units: None)*/
      std::vector<int64_t> & getVehicles(void) { return __Vehicles; }

      /** Task ID(s) to be removed from task lists of indicated vehicles. If empty, then only the current task is removed. (Units: None)*/
      std::vector<int64_t> & getCanceledTasks(void) { return __CanceledTasks; }



   protected:
      /** List of vehicle IDs that are directed to cancel tasks. If empty, all vehicles currently on a listed task will be directed to cancel. */
      std::vector< int64_t > __Vehicles;
      /** Task ID(s) to be removed from task lists of indicated vehicles. If empty, then only the current task is removed. */
      std::vector< int64_t > __CanceledTasks;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_CANCELTASK_H_
