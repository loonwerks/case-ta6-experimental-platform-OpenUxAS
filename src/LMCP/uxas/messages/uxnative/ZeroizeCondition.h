// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_ZEROIZECONDITION_H_
#define _UXAS_MESSAGES_UXNATIVE_ZEROIZECONDITION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"
#include "afrl/cmasi/OperatingRegion.h"

#include <vector>


namespace uxas {
namespace messages {
namespace uxnative {


   bool isZeroizeCondition(avtas::lmcp::Object* obj);
   bool isZeroizeCondition(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ZeroizeConditionDescendants();
   
   class ZeroizeCondition : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ZeroizeCondition(void);

      // Copy Constructor
      ZeroizeCondition(const ZeroizeCondition &that);

      // Assignment Operator
      ZeroizeCondition & operator=(const ZeroizeCondition &that);

      // Destructor
      virtual ~ZeroizeCondition(void);

      // Equals overload
      bool operator==(const ZeroizeCondition & that);
      bool operator!=(const ZeroizeCondition & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ZeroizeCondition* clone() const;

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
      /** The identity of the vehicle to be zeroized (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      ZeroizeCondition& setVehicleID(const int64_t val);

      /** Zeroize on aircraft landing? (Units: None)*/
      bool getZeroizeOnLanding(void) const { return __ZeroizeOnLanding; }
      ZeroizeCondition& setZeroizeOnLanding(const bool val);

      /** Zeroize on leaving the designated operational area? See CreateNewService message as to how the current operational is defined in terms of KeepInZones and KeepOutZones (Units: None)*/
      bool getZeroizeOnExitingOperationalArea(void) const { return __ZeroizeOnExitingOperationalArea; }
      ZeroizeCondition& setZeroizeOnExitingOperationalArea(const bool val);

      /** Selects the ID of the operational area apply (Units: None)*/
      int64_t getActiveOperationalArea(void) const { return __ActiveOperationalArea; }
      ZeroizeCondition& setActiveOperationalArea(const int64_t val);

      /** Zeroize on completion of all pending tasks? (Units: None)*/
      bool getZeroizeOnTasksComplete(void) const { return __ZeroizeOnTasksComplete; }
      ZeroizeCondition& setZeroizeOnTasksComplete(const bool val);

      /** The amount of time to wait after first detecting a zeroization condition prior to raising a zeroization command (milliseconds) (Units: None)*/
      int64_t getZeroizeAccumulationTime(void) const { return __ZeroizeAccumulationTime; }
      ZeroizeCondition& setZeroizeAccumulationTime(const int64_t val);

      /** While detecting a zeroization condition, the amount of time to prior to repeating a zeroization command (milliseconds) (Units: None)*/
      int64_t getZeroizeHoldoffTime(void) const { return __ZeroizeHoldoffTime; }
      ZeroizeCondition& setZeroizeHoldoffTime(const int64_t val);

      /** Defined keep in zones (Units: None)*/
      std::vector<afrl::cmasi::KeepInZone*> & getKeepInZones(void) { return __KeepInZones; }

      /** Defined keep out zones at (Units: None)*/
      std::vector<afrl::cmasi::KeepOutZone*> & getKeepOutZones(void) { return __KeepOutZones; }

      /** Defined opearting regions (Units: None)*/
      std::vector<afrl::cmasi::OperatingRegion*> & getOperationalAreas(void) { return __OperationalAreas; }



   protected:
      /** The identity of the vehicle to be zeroized */
      int64_t __VehicleID;
      /** Zeroize on aircraft landing? */
      bool __ZeroizeOnLanding;
      /** Zeroize on leaving the designated operational area? See CreateNewService message as to how the current operational is defined in terms of KeepInZones and KeepOutZones */
      bool __ZeroizeOnExitingOperationalArea;
      /** Selects the ID of the operational area apply */
      int64_t __ActiveOperationalArea;
      /** Zeroize on completion of all pending tasks? */
      bool __ZeroizeOnTasksComplete;
      /** The amount of time to wait after first detecting a zeroization condition prior to raising a zeroization command (milliseconds) */
      int64_t __ZeroizeAccumulationTime;
      /** While detecting a zeroization condition, the amount of time to prior to repeating a zeroization command (milliseconds) */
      int64_t __ZeroizeHoldoffTime;
      /** Defined keep in zones */
      std::vector< afrl::cmasi::KeepInZone* > __KeepInZones;
      /** Defined keep out zones at */
      std::vector< afrl::cmasi::KeepOutZone* > __KeepOutZones;
      /** Defined opearting regions */
      std::vector< afrl::cmasi::OperatingRegion* > __OperationalAreas;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_ZEROIZECONDITION_H_
