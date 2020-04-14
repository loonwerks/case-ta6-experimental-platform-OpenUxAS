// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_TASKOPTION_H_
#define _UXAS_MESSAGES_TASK_TASKOPTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Location3D.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isTaskOption(avtas::lmcp::Object* obj);
   bool isTaskOption(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TaskOptionDescendants();
   
   class TaskOption : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TaskOption(void);

      // Copy Constructor
      TaskOption(const TaskOption &that);

      // Assignment Operator
      TaskOption & operator=(const TaskOption &that);

      // Destructor
      virtual ~TaskOption(void);

      // Equals overload
      bool operator==(const TaskOption & that);
      bool operator!=(const TaskOption & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TaskOption* clone() const;

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
      /** Task ID (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      TaskOption& setTaskID(const int64_t val);

      /** ID for this option (Units: None)*/
      int64_t getOptionID(void) const { return __OptionID; }
      TaskOption& setOptionID(const int64_t val);

      /** Eligible entities for completing this option with identical cost to complete. If list is empty, then all vehicles are assumed to be eligible. (Units: None)*/
      std::vector<int64_t> & getEligibleEntities(void) { return __EligibleEntities; }

      /** Cost to complete option in terms of time (given in milliseconds) (Units: milliseconds)*/
      int64_t getCost(void) const { return __Cost; }
      TaskOption& setCost(const int64_t val);

      /** Start location entering the option. A valid TaskOption must define StartLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getStartLocation(void) { return __StartLocation; }
      TaskOption& setStartLocation(const afrl::cmasi::Location3D* const val);

      /** Start heading entering the option (Units: degrees)*/
      float getStartHeading(void) const { return __StartHeading; }
      TaskOption& setStartHeading(const float val);

      /** Ending location for this option. A valid TaskOption must define EndLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getEndLocation(void) { return __EndLocation; }
      TaskOption& setEndLocation(const afrl::cmasi::Location3D* const val);

      /** Ending heading for this option (Units: degrees)*/
      float getEndHeading(void) const { return __EndHeading; }
      TaskOption& setEndHeading(const float val);



   protected:
      /** Task ID */
      int64_t __TaskID;
      /** ID for this option */
      int64_t __OptionID;
      /** Eligible entities for completing this option with identical cost to complete. If list is empty, then all vehicles are assumed to be eligible. */
      std::vector< int64_t > __EligibleEntities;
      /** Cost to complete option in terms of time (given in milliseconds) */
      int64_t __Cost;
      /** Start location entering the option. A valid TaskOption must define StartLocation (null not allowed). */
      afrl::cmasi::Location3D* __StartLocation;
      /** Start heading entering the option */
      float __StartHeading;
      /** Ending location for this option. A valid TaskOption must define EndLocation (null not allowed). */
      afrl::cmasi::Location3D* __EndLocation;
      /** Ending heading for this option */
      float __EndHeading;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_TASKOPTION_H_
