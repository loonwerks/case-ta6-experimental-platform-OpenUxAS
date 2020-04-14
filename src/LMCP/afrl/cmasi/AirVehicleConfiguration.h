// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_AIRVEHICLECONFIGURATION_H_
#define _AFRL_CMASI_AIRVEHICLECONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/EntityConfiguration.h"
#include "afrl/cmasi/FlightProfile.h"
#include "afrl/cmasi/FlightProfile.h"
#include "afrl/cmasi/LoiterType.h"
#include "afrl/cmasi/TurnType.h"
#include "afrl/cmasi/AltitudeType.h"
#include "afrl/cmasi/AltitudeType.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isAirVehicleConfiguration(avtas::lmcp::Object* obj);
   bool isAirVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AirVehicleConfigurationDescendants();
   
   class AirVehicleConfiguration : public afrl::cmasi::EntityConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AirVehicleConfiguration(void);

      // Copy Constructor
      AirVehicleConfiguration(const AirVehicleConfiguration &that);

      // Assignment Operator
      AirVehicleConfiguration & operator=(const AirVehicleConfiguration &that);

      // Destructor
      virtual ~AirVehicleConfiguration(void);

      // Equals overload
      bool operator==(const AirVehicleConfiguration & that);
      bool operator!=(const AirVehicleConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AirVehicleConfiguration* clone() const;

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
      /** The minimum true airspeed that should be commanded for this aircraft (Units: meter/sec)*/
      float getMinimumSpeed(void) const { return __MinimumSpeed; }
      AirVehicleConfiguration& setMinimumSpeed(const float val);

      /** The maximum true airspeed that should be commanded for this aircraft (Units: meter/sec)*/
      float getMaximumSpeed(void) const { return __MaximumSpeed; }
      AirVehicleConfiguration& setMaximumSpeed(const float val);

      /** Describes the preferred operating mode for most planning purposes. This can be a max range or endurance speed profile, or any other operating point chosen by a user. This field may not be null. (Units: None)*/
      afrl::cmasi::FlightProfile* const getNominalFlightProfile(void) { return __NominalFlightProfile; }
      AirVehicleConfiguration& setNominalFlightProfile(const afrl::cmasi::FlightProfile* const val);

      /** A list of all flight configurations described for this vehicle. Each flight configuration specifies a different mode of flight, for instance: climb, cruise, dash, loiter. This list may be empty, and does not necessarily contain the nominal flight configuration. (Units: None)*/
      std::vector<afrl::cmasi::FlightProfile*> & getAlternateFlightProfiles(void) { return __AlternateFlightProfiles; }

      /** A list of available loiter types for this aircraft (Units: None)*/
      std::vector<afrl::cmasi::LoiterType::LoiterType> & getAvailableLoiterTypes(void) { return __AvailableLoiterTypes; }

      /** A list of available turning modes for this aircraft (Units: None)*/
      std::vector<afrl::cmasi::TurnType::TurnType> & getAvailableTurnTypes(void) { return __AvailableTurnTypes; }

      /** Minimum MSL altitude that this aircraft is allowed to fly. This value should be treated as a regulatory or safety-of-flight parameter and therefore takes precedence over other requests. (Units: meter)*/
      float getMinimumAltitude(void) const { return __MinimumAltitude; }
      AirVehicleConfiguration& setMinimumAltitude(const float val);

      /** Altitude type for min altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getMinAltitudeType(void) const { return __MinAltitudeType; }
      AirVehicleConfiguration& setMinAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** Maximum MSL altitude that this aircraft is allowed to fly. This value should be treated as a regulatory or safety-of-flight parameter and therefore takes precedence over other requests. (Units: meter)*/
      float getMaximumAltitude(void) const { return __MaximumAltitude; }
      AirVehicleConfiguration& setMaximumAltitude(const float val);

      /** Altitude type for max altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getMaxAltitudeType(void) const { return __MaxAltitudeType; }
      AirVehicleConfiguration& setMaxAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);



   protected:
      /** The minimum true airspeed that should be commanded for this aircraft */
      float __MinimumSpeed;
      /** The maximum true airspeed that should be commanded for this aircraft */
      float __MaximumSpeed;
      /** Describes the preferred operating mode for most planning purposes. This can be a max range or endurance speed profile, or any other operating point chosen by a user. This field may not be null. */
      afrl::cmasi::FlightProfile* __NominalFlightProfile;
      /** A list of all flight configurations described for this vehicle. Each flight configuration specifies a different mode of flight, for instance: climb, cruise, dash, loiter. This list may be empty, and does not necessarily contain the nominal flight configuration. */
      std::vector< afrl::cmasi::FlightProfile* > __AlternateFlightProfiles;
      /** A list of available loiter types for this aircraft */
      std::vector< afrl::cmasi::LoiterType::LoiterType > __AvailableLoiterTypes;
      /** A list of available turning modes for this aircraft */
      std::vector< afrl::cmasi::TurnType::TurnType > __AvailableTurnTypes;
      /** Minimum MSL altitude that this aircraft is allowed to fly. This value should be treated as a regulatory or safety-of-flight parameter and therefore takes precedence over other requests. */
      float __MinimumAltitude;
      /** Altitude type for min altitude */
      afrl::cmasi::AltitudeType::AltitudeType __MinAltitudeType;
      /** Maximum MSL altitude that this aircraft is allowed to fly. This value should be treated as a regulatory or safety-of-flight parameter and therefore takes precedence over other requests. */
      float __MaximumAltitude;
      /** Altitude type for max altitude */
      afrl::cmasi::AltitudeType::AltitudeType __MaxAltitudeType;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_AIRVEHICLECONFIGURATION_H_
