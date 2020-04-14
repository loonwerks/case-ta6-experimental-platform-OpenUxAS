// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_SENSORFOOTPRINT_H_
#define _UXAS_MESSAGES_TASK_SENSORFOOTPRINT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/WavelengthBand.h"



namespace uxas {
namespace messages {
namespace task {


   bool isSensorFootprint(avtas::lmcp::Object* obj);
   bool isSensorFootprint(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SensorFootprintDescendants();
   
   class SensorFootprint : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SensorFootprint(void);

      // Copy Constructor
      SensorFootprint(const SensorFootprint &that);

      // Assignment Operator
      SensorFootprint & operator=(const SensorFootprint &that);

      // Destructor
      virtual ~SensorFootprint(void);

      // Equals overload
      bool operator==(const SensorFootprint & that);
      bool operator!=(const SensorFootprint & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SensorFootprint* clone() const;

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
      /** Response ID that matches corresponding request ID. Note that multiple responses may be generated from a single request (such as multiple cameras which all meet the specification). Each response must contain the matching request ID in it's FootprintResponseID field. (Units: None)*/
      int64_t getFootprintResponseID(void) const { return __FootprintResponseID; }
      SensorFootprint& setFootprintResponseID(const int64_t val);

      /** Vehicle for which the footprint calculation applies (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      SensorFootprint& setVehicleID(const int64_t val);

      /** Camera from which settings (such as zoom and field of view) were used in the footprint calculation (Units: None)*/
      int64_t getCameraID(void) const { return __CameraID; }
      SensorFootprint& setCameraID(const int64_t val);

      /** Gimbal from which parameters such as allowable steering angles were used in the footprint calculation (Units: None)*/
      int64_t getGimbalID(void) const { return __GimbalID; }
      SensorFootprint& setGimbalID(const int64_t val);

      /** The selected horizontal field of view of the camera necessary to get the reported footprint (equivalent to zoom) (Units: degrees)*/
      float getHorizontalFOV(void) const { return __HorizontalFOV; }
      SensorFootprint& setHorizontalFOV(const float val);

      /** Altitude above ground level for which the footprint was calculated (Units: meters)*/
      float getAglAltitude(void) const { return __AglAltitude; }
      SensorFootprint& setAglAltitude(const float val);

      /** Commanded gimbal elevation to achieve sensor footprint (Units: degrees)*/
      float getGimbalElevation(void) const { return __GimbalElevation; }
      SensorFootprint& setGimbalElevation(const float val);

      /** Aspect ratio (width/height) of the camera image used for footprint calculation. Note: combine with horizontal field of view to determine camera vertical field of view. (Units: None)*/
      float getAspectRatio(void) const { return __AspectRatio; }
      SensorFootprint& setAspectRatio(const float val);

      /** Ground sample distance obtained with this sensor footprint (Units: meters/pixel)*/
      float getAchievedGSD(void) const { return __AchievedGSD; }
      SensorFootprint& setAchievedGSD(const float val);

      /** Sensor wavelength used applicable to this footprint calculation (Units: None)*/
      afrl::cmasi::WavelengthBand::WavelengthBand getCameraWavelength(void) const { return __CameraWavelength; }
      SensorFootprint& setCameraWavelength(const afrl::cmasi::WavelengthBand::WavelengthBand val);

      /** Distance out front of the entity to the leading edge (Units: meters)*/
      float getHorizontalToLeadingEdge(void) const { return __HorizontalToLeadingEdge; }
      SensorFootprint& setHorizontalToLeadingEdge(const float val);

      /** Distance out front of the entity to the trailing edge (Units: meters)*/
      float getHorizontalToTrailingEdge(void) const { return __HorizontalToTrailingEdge; }
      SensorFootprint& setHorizontalToTrailingEdge(const float val);

      /** Distance out front of the entity to the center of the footprint (Units: meters)*/
      float getHorizontalToCenter(void) const { return __HorizontalToCenter; }
      SensorFootprint& setHorizontalToCenter(const float val);

      /** Width of the footprint at the vertical center (Units: meters)*/
      float getWidthCenter(void) const { return __WidthCenter; }
      SensorFootprint& setWidthCenter(const float val);

      /** At the prescribed settings (e.g. altitude, elevation angle, etc) the distance from the camera to the center of the footprint (Units: meters)*/
      float getSlantRangeToCenter(void) const { return __SlantRangeToCenter; }
      SensorFootprint& setSlantRangeToCenter(const float val);



   protected:
      /** Response ID that matches corresponding request ID. Note that multiple responses may be generated from a single request (such as multiple cameras which all meet the specification). Each response must contain the matching request ID in it's FootprintResponseID field. */
      int64_t __FootprintResponseID;
      /** Vehicle for which the footprint calculation applies */
      int64_t __VehicleID;
      /** Camera from which settings (such as zoom and field of view) were used in the footprint calculation */
      int64_t __CameraID;
      /** Gimbal from which parameters such as allowable steering angles were used in the footprint calculation */
      int64_t __GimbalID;
      /** The selected horizontal field of view of the camera necessary to get the reported footprint (equivalent to zoom) */
      float __HorizontalFOV;
      /** Altitude above ground level for which the footprint was calculated */
      float __AglAltitude;
      /** Commanded gimbal elevation to achieve sensor footprint */
      float __GimbalElevation;
      /** Aspect ratio (width/height) of the camera image used for footprint calculation. Note: combine with horizontal field of view to determine camera vertical field of view. */
      float __AspectRatio;
      /** Ground sample distance obtained with this sensor footprint */
      float __AchievedGSD;
      /** Sensor wavelength used applicable to this footprint calculation */
      afrl::cmasi::WavelengthBand::WavelengthBand __CameraWavelength;
      /** Distance out front of the entity to the leading edge */
      float __HorizontalToLeadingEdge;
      /** Distance out front of the entity to the trailing edge */
      float __HorizontalToTrailingEdge;
      /** Distance out front of the entity to the center of the footprint */
      float __HorizontalToCenter;
      /** Width of the footprint at the vertical center */
      float __WidthCenter;
      /** At the prescribed settings (e.g. altitude, elevation angle, etc) the distance from the camera to the center of the footprint */
      float __SlantRangeToCenter;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_SENSORFOOTPRINT_H_
