// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_SAFEHEADINGACTION_H_
#define _UXAS_MESSAGES_UXNATIVE_SAFEHEADINGACTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "afrl/cmasi/VehicleAction.h"
#include "afrl/cmasi/AltitudeType.h"



namespace uxas {
namespace messages {
namespace uxnative {


   bool isSafeHeadingAction(avtas::lmcp::Object* obj);
   bool isSafeHeadingAction(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SafeHeadingActionDescendants();
   
   class SafeHeadingAction : public afrl::cmasi::VehicleAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SafeHeadingAction(void);

      // Copy Constructor
      SafeHeadingAction(const SafeHeadingAction &that);

      // Assignment Operator
      SafeHeadingAction & operator=(const SafeHeadingAction &that);

      // Destructor
      virtual ~SafeHeadingAction(void);

      // Equals overload
      bool operator==(const SafeHeadingAction & that);
      bool operator!=(const SafeHeadingAction & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SafeHeadingAction* clone() const;

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
      /** ID of vehicle which will be commanded to a safe waypoint that approximates the desired heading (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      SafeHeadingAction& setVehicleID(const int64_t val);

      /** Operating region ID indicating airspace constraints that must be respected (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      SafeHeadingAction& setOperatingRegion(const int64_t val);

      /** Lead-ahead distance for waypoint placement (Units: meters)*/
      float getLeadAheadDistance(void) const { return __LeadAheadDistance; }
      SafeHeadingAction& setLeadAheadDistance(const float val);

      /** Loiter radius on lead-ahead waypoint. If zero or negative, uses calcuated minimum turn radius from vehicle configuration (Units: meters)*/
      float getLoiterRadius(void) const { return __LoiterRadius; }
      SafeHeadingAction& setLoiterRadius(const float val);

      /** Desired heading that vehicle should attemtpt to reach in degress from true north (Units: degrees)*/
      float getDesiredHeading(void) const { return __DesiredHeading; }
      SafeHeadingAction& setDesiredHeading(const float val);

      /** Desired heading rate for the vehicle (Units: degrees/sec)*/
      float getDesiredHeadingRate(void) const { return __DesiredHeadingRate; }
      SafeHeadingAction& setDesiredHeadingRate(const float val);

      /** Flag indicating selecting between heading (false) or heading rate (true) commands (Units: None)*/
      bool getUseHeadingRate(void) const { return __UseHeadingRate; }
      SafeHeadingAction& setUseHeadingRate(const bool val);

      /** Commanded Altitude valid if {@link UseAltitude} == true (Units: meter)*/
      float getAltitude(void) const { return __Altitude; }
      SafeHeadingAction& setAltitude(const float val);

      /** Altitude type for specified altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getAltitudeType(void) const { return __AltitudeType; }
      SafeHeadingAction& setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** Denotes whether altitude should be used in the safe heading action. If false, the {@link NominalAltitude} and {@link NominalType} from the {@link CMASI/EntityConfiguration} will be used. (Units: None)*/
      bool getUseAltitude(void) const { return __UseAltitude; }
      SafeHeadingAction& setUseAltitude(const bool val);

      /** Commanded Speed valid if {@link UseSpeed} == true (Units: mps)*/
      float getSpeed(void) const { return __Speed; }
      SafeHeadingAction& setSpeed(const float val);

      /** Denotes whether speed should be used in the safe heading action. If false, the {@link NominalSpeed} from the {@link CMASI/EntityConfiguration} will be used. (Units: None)*/
      bool getUseSpeed(void) const { return __UseSpeed; }
      SafeHeadingAction& setUseSpeed(const bool val);



   protected:
      /** ID of vehicle which will be commanded to a safe waypoint that approximates the desired heading */
      int64_t __VehicleID;
      /** Operating region ID indicating airspace constraints that must be respected */
      int64_t __OperatingRegion;
      /** Lead-ahead distance for waypoint placement */
      float __LeadAheadDistance;
      /** Loiter radius on lead-ahead waypoint. If zero or negative, uses calcuated minimum turn radius from vehicle configuration */
      float __LoiterRadius;
      /** Desired heading that vehicle should attemtpt to reach in degress from true north */
      float __DesiredHeading;
      /** Desired heading rate for the vehicle */
      float __DesiredHeadingRate;
      /** Flag indicating selecting between heading (false) or heading rate (true) commands */
      bool __UseHeadingRate;
      /** Commanded Altitude valid if {@link UseAltitude} == true */
      float __Altitude;
      /** Altitude type for specified altitude */
      afrl::cmasi::AltitudeType::AltitudeType __AltitudeType;
      /** Denotes whether altitude should be used in the safe heading action. If false, the {@link NominalAltitude} and {@link NominalType} from the {@link CMASI/EntityConfiguration} will be used. */
      bool __UseAltitude;
      /** Commanded Speed valid if {@link UseSpeed} == true */
      float __Speed;
      /** Denotes whether speed should be used in the safe heading action. If false, the {@link NominalSpeed} from the {@link CMASI/EntityConfiguration} will be used. */
      bool __UseSpeed;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_SAFEHEADINGACTION_H_
