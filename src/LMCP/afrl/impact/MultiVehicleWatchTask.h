// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_MULTIVEHICLEWATCHTASK_H_
#define _AFRL_IMPACT_MULTIVEHICLEWATCHTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/SearchTask.h"



namespace afrl {
namespace impact {


   bool isMultiVehicleWatchTask(avtas::lmcp::Object* obj);
   bool isMultiVehicleWatchTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > MultiVehicleWatchTaskDescendants();
   
   class MultiVehicleWatchTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      MultiVehicleWatchTask(void);

      // Copy Constructor
      MultiVehicleWatchTask(const MultiVehicleWatchTask &that);

      // Assignment Operator
      MultiVehicleWatchTask & operator=(const MultiVehicleWatchTask &that);

      // Destructor
      virtual ~MultiVehicleWatchTask(void);

      // Equals overload
      bool operator==(const MultiVehicleWatchTask & that);
      bool operator!=(const MultiVehicleWatchTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual MultiVehicleWatchTask* clone() const;

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
      /** Entity ID to follow and watch (Units: None)*/
      int64_t getWatchedEntityID(void) const { return __WatchedEntityID; }
      MultiVehicleWatchTask& setWatchedEntityID(const int64_t val);

      /** Number of vehicles to simultaneously overwatch the target (Units: None)*/
      uint8_t getNumberVehicles(void) const { return __NumberVehicles; }
      MultiVehicleWatchTask& setNumberVehicles(const uint8_t val);



   protected:
      /** Entity ID to follow and watch */
      int64_t __WatchedEntityID;
      /** Number of vehicles to simultaneously overwatch the target */
      uint8_t __NumberVehicles;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_MULTIVEHICLEWATCHTASK_H_
