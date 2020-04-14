// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_TASK_H_
#define _AFRL_CMASI_TASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isTask(avtas::lmcp::Object* obj);
   bool isTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskDescendants();
   
   class Task : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      Task(void);

      // Copy Constructor
      Task(const Task &that);

      // Assignment Operator
      Task & operator=(const Task &that);

      // Destructor
      virtual ~Task(void);

      // Equals overload
      bool operator==(const Task & that);
      bool operator!=(const Task & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual Task* clone() const;

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
      /** A unique identifier for this task. (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      Task& setTaskID(const int64_t val);

      /** An optional text string for the task. This is not necesarily unique, and is included for information only. TaskID should be used to uniquely identify tasks. (Units: None)*/
      std::string getLabel(void) const { return __Label; }
      Task& setLabel(const std::string val);

      /** A list of entity IDs that are eligible to accomplish this task. If the list is empty, then it is assumed all entities are eligible. (Units: None)*/
      std::vector<int64_t> & getEligibleEntities(void) { return __EligibleEntities; }

      /** If a task is to be repeatedly done, this field indicates how often. A value of zero means the task is complete on the first pass. (Units: sec)*/
      float getRevisitRate(void) const { return __RevisitRate; }
      Task& setRevisitRate(const float val);

      /** An optional text string for automation service task parameters. (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getParameters(void) { return __Parameters; }

      /** The priority value for this task. Priority is a relative value of this task compared to other tasks in the scenario. This field should be limited to the range[0..100], 100 being the highest level of priority. The exact interpretation priority may vary depending on algorithm implementation. (Units: None)*/
      uint8_t getPriority(void) const { return __Priority; }
      Task& setPriority(const uint8_t val);

      /** Indicates whether this task <i><b>must</b></i> be executed as part of a mission plan. (Units: None)*/
      bool getRequired(void) const { return __Required; }
      Task& setRequired(const bool val);



   protected:
      /** A unique identifier for this task. */
      int64_t __TaskID;
      /** An optional text string for the task. This is not necesarily unique, and is included for information only. TaskID should be used to uniquely identify tasks. */
      std::string __Label;
      /** A list of entity IDs that are eligible to accomplish this task. If the list is empty, then it is assumed all entities are eligible. */
      std::vector< int64_t > __EligibleEntities;
      /** If a task is to be repeatedly done, this field indicates how often. A value of zero means the task is complete on the first pass. */
      float __RevisitRate;
      /** An optional text string for automation service task parameters. */
      std::vector< afrl::cmasi::KeyValuePair* > __Parameters;
      /** The priority value for this task. Priority is a relative value of this task compared to other tasks in the scenario. This field should be limited to the range[0..100], 100 being the highest level of priority. The exact interpretation priority may vary depending on algorithm implementation. */
      uint8_t __Priority;
      /** Indicates whether this task <i><b>must</b></i> be executed as part of a mission plan. */
      bool __Required;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_TASK_H_
