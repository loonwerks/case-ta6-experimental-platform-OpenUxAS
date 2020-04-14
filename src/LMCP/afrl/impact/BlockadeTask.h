// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_BLOCKADETASK_H_
#define _AFRL_IMPACT_BLOCKADETASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/Task.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace impact {


   bool isBlockadeTask(avtas::lmcp::Object* obj);
   bool isBlockadeTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > BlockadeTaskDescendants();
   
   class BlockadeTask : public afrl::cmasi::Task {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      BlockadeTask(void);

      // Copy Constructor
      BlockadeTask(const BlockadeTask &that);

      // Assignment Operator
      BlockadeTask & operator=(const BlockadeTask &that);

      // Destructor
      virtual ~BlockadeTask(void);

      // Equals overload
      bool operator==(const BlockadeTask & that);
      bool operator!=(const BlockadeTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual BlockadeTask* clone() const;

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
      /** Entity to surround and deny access (Units: None)*/
      int64_t getBlockedEntityID(void) const { return __BlockedEntityID; }
      BlockadeTask& setBlockedEntityID(const int64_t val);

      /** When in blocking formation, the distance that vehicles should stand off. (Units: meters)*/
      float getStandoffDistance(void) const { return __StandoffDistance; }
      BlockadeTask& setStandoffDistance(const float val);

      /** Number of vehicles to simultaneously block the target (Units: None)*/
      uint8_t getNumberVehicles(void) const { return __NumberVehicles; }
      BlockadeTask& setNumberVehicles(const uint8_t val);

      /** Biases the blockade so that more vehicles are between enemy and protected location. If null location is given, then blockade attempts to block in direction of enemy travel (Units: None)*/
      afrl::cmasi::Location3D* const getProtectedLocation(void) { return __ProtectedLocation; }
      BlockadeTask& setProtectedLocation(const afrl::cmasi::Location3D* const val);



   protected:
      /** Entity to surround and deny access */
      int64_t __BlockedEntityID;
      /** When in blocking formation, the distance that vehicles should stand off. */
      float __StandoffDistance;
      /** Number of vehicles to simultaneously block the target */
      uint8_t __NumberVehicles;
      /** Biases the blockade so that more vehicles are between enemy and protected location. If null location is given, then blockade attempts to block in direction of enemy travel */
      afrl::cmasi::Location3D* __ProtectedLocation;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_BLOCKADETASK_H_
