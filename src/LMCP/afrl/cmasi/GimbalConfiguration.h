// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_GIMBALCONFIGURATION_H_
#define _AFRL_CMASI_GIMBALCONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/PayloadConfiguration.h"
#include "afrl/cmasi/GimbalPointingMode.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isGimbalConfiguration(avtas::lmcp::Object* obj);
   bool isGimbalConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GimbalConfigurationDescendants();
   
   class GimbalConfiguration : public afrl::cmasi::PayloadConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GimbalConfiguration(void);

      // Copy Constructor
      GimbalConfiguration(const GimbalConfiguration &that);

      // Assignment Operator
      GimbalConfiguration & operator=(const GimbalConfiguration &that);

      // Destructor
      virtual ~GimbalConfiguration(void);

      // Equals overload
      bool operator==(const GimbalConfiguration & that);
      bool operator!=(const GimbalConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GimbalConfiguration* clone() const;

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
      /** The pointing modes supported by the gimbal (Units: None)*/
      std::vector<afrl::cmasi::GimbalPointingMode::GimbalPointingMode> & getSupportedPointingModes(void) { return __SupportedPointingModes; }

      /** Minimum azimuth that this sensor can slew in body axis (0 degrees out of nose, positive clockwise). If this is a fixed-azimuth sensor, then this should be set to the fixed azimuth value. (Units: degree)*/
      float getMinAzimuth(void) const { return __MinAzimuth; }
      GimbalConfiguration& setMinAzimuth(const float val);

      /** Maximum azimuth that this sensor can slew in body axis (0 degrees out of nose, positive clockwise). If this is a fixed-azimuth sensor, then this should be set to the fixed azimuth value. (Units: degree)*/
      float getMaxAzimuth(void) const { return __MaxAzimuth; }
      GimbalConfiguration& setMaxAzimuth(const float val);

      /** Determines whether there are any limits on the azimuth of the gimbal. If this is set to false, then MinAzimuth and MaxAzimuth are not used, and the gimbal is capable of continuously spinning in a 360 degree circle without hitting any stops. (Units: None)*/
      bool getIsAzimuthClamped(void) const { return __IsAzimuthClamped; }
      GimbalConfiguration& setIsAzimuthClamped(const bool val);

      /** Minimum elevation that this sensor can slew in body axis (0 degrees horizontal, positive upwards). If this is a fixed-elevation sensor, then this should be set to the fixed elevation value. (Units: degree)*/
      float getMinElevation(void) const { return __MinElevation; }
      GimbalConfiguration& setMinElevation(const float val);

      /** Maximum elevation that this sensor can slew in body axis (0 degrees horizontal, positive upwards). If this is a fixed-elevation sensor, then this should be set to the fixed elevation value. (Units: degree)*/
      float getMaxElevation(void) const { return __MaxElevation; }
      GimbalConfiguration& setMaxElevation(const float val);

      /** Determines whether there are any limits on the elevation of the gimbal. If this is set to false, then MinElevation and MaxElevation are not used, and the gimbal is capable of continuously spinning in a 360 degree circle without hitting any stops. (Units: None)*/
      bool getIsElevationClamped(void) const { return __IsElevationClamped; }
      GimbalConfiguration& setIsElevationClamped(const bool val);

      /** Minimum rotation that this sensor can slew in body axis (0 degrees aligned with aircraft normal, positive clockwise). If this is a fixed-rotation sensor, then this should be set to the fixed rotation value. (Units: degree)*/
      float getMinRotation(void) const { return __MinRotation; }
      GimbalConfiguration& setMinRotation(const float val);

      /** Maximum rotation that this sensor can slew in body axis (0 degrees aligned with aircraft normal, positive clockwise). If this is a fixed-rotation sensor, then this should be set to the fixed rotation value. (Units: degree)*/
      float getMaxRotation(void) const { return __MaxRotation; }
      GimbalConfiguration& setMaxRotation(const float val);

      /** Determines whether there are any limits on the rotation of the gimbal. If this is set to false, then MinRotation and MaxRotation are not used, and the gimbal is capable of continuously rotating in a 360 degree circle without hitting any stops. (Units: None)*/
      bool getIsRotationClamped(void) const { return __IsRotationClamped; }
      GimbalConfiguration& setIsRotationClamped(const bool val);

      /** Rate of maximum horizontal slew for this gimbal. (Units: degree/sec)*/
      float getMaxAzimuthSlewRate(void) const { return __MaxAzimuthSlewRate; }
      GimbalConfiguration& setMaxAzimuthSlewRate(const float val);

      /** Rate of maximum vertical slew for this gimbal. (Units: degree/sec)*/
      float getMaxElevationSlewRate(void) const { return __MaxElevationSlewRate; }
      GimbalConfiguration& setMaxElevationSlewRate(const float val);

      /** Rate of maximum rotation for this gimbal. (Units: degree/sec)*/
      float getMaxRotationRate(void) const { return __MaxRotationRate; }
      GimbalConfiguration& setMaxRotationRate(const float val);

      /** Lists the PayloadID of each sensor physically located within the gimbal and that shares the same gimbal angles. It is assumed that all sensors are boresighted. (Units: None)*/
      std::vector<int64_t> & getContainedPayloadList(void) { return __ContainedPayloadList; }



   protected:
      /** The pointing modes supported by the gimbal */
      std::vector< afrl::cmasi::GimbalPointingMode::GimbalPointingMode > __SupportedPointingModes;
      /** Minimum azimuth that this sensor can slew in body axis (0 degrees out of nose, positive clockwise). If this is a fixed-azimuth sensor, then this should be set to the fixed azimuth value. */
      float __MinAzimuth;
      /** Maximum azimuth that this sensor can slew in body axis (0 degrees out of nose, positive clockwise). If this is a fixed-azimuth sensor, then this should be set to the fixed azimuth value. */
      float __MaxAzimuth;
      /** Determines whether there are any limits on the azimuth of the gimbal. If this is set to false, then MinAzimuth and MaxAzimuth are not used, and the gimbal is capable of continuously spinning in a 360 degree circle without hitting any stops. */
      bool __IsAzimuthClamped;
      /** Minimum elevation that this sensor can slew in body axis (0 degrees horizontal, positive upwards). If this is a fixed-elevation sensor, then this should be set to the fixed elevation value. */
      float __MinElevation;
      /** Maximum elevation that this sensor can slew in body axis (0 degrees horizontal, positive upwards). If this is a fixed-elevation sensor, then this should be set to the fixed elevation value. */
      float __MaxElevation;
      /** Determines whether there are any limits on the elevation of the gimbal. If this is set to false, then MinElevation and MaxElevation are not used, and the gimbal is capable of continuously spinning in a 360 degree circle without hitting any stops. */
      bool __IsElevationClamped;
      /** Minimum rotation that this sensor can slew in body axis (0 degrees aligned with aircraft normal, positive clockwise). If this is a fixed-rotation sensor, then this should be set to the fixed rotation value. */
      float __MinRotation;
      /** Maximum rotation that this sensor can slew in body axis (0 degrees aligned with aircraft normal, positive clockwise). If this is a fixed-rotation sensor, then this should be set to the fixed rotation value. */
      float __MaxRotation;
      /** Determines whether there are any limits on the rotation of the gimbal. If this is set to false, then MinRotation and MaxRotation are not used, and the gimbal is capable of continuously rotating in a 360 degree circle without hitting any stops. */
      bool __IsRotationClamped;
      /** Rate of maximum horizontal slew for this gimbal. */
      float __MaxAzimuthSlewRate;
      /** Rate of maximum vertical slew for this gimbal. */
      float __MaxElevationSlewRate;
      /** Rate of maximum rotation for this gimbal. */
      float __MaxRotationRate;
      /** Lists the PayloadID of each sensor physically located within the gimbal and that shares the same gimbal angles. It is assumed that all sensors are boresighted. */
      std::vector< int64_t > __ContainedPayloadList;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_GIMBALCONFIGURATION_H_
