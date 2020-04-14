// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_CAMERACONFIGURATION_H_
#define _AFRL_CMASI_CAMERACONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/PayloadConfiguration.h"
#include "afrl/cmasi/WavelengthBand.h"
#include "afrl/cmasi/FOVOperationMode.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isCameraConfiguration(avtas::lmcp::Object* obj);
   bool isCameraConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > CameraConfigurationDescendants();
   
   class CameraConfiguration : public afrl::cmasi::PayloadConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      CameraConfiguration(void);

      // Copy Constructor
      CameraConfiguration(const CameraConfiguration &that);

      // Assignment Operator
      CameraConfiguration & operator=(const CameraConfiguration &that);

      // Destructor
      virtual ~CameraConfiguration(void);

      // Equals overload
      bool operator==(const CameraConfiguration & that);
      bool operator!=(const CameraConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual CameraConfiguration* clone() const;

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
      /** The supported wavelength band of this camera (Units: None)*/
      afrl::cmasi::WavelengthBand::WavelengthBand getSupportedWavelengthBand(void) const { return __SupportedWavelengthBand; }
      CameraConfiguration& setSupportedWavelengthBand(const afrl::cmasi::WavelengthBand::WavelengthBand val);

      /** The manner in which field of views are commanded: Continuous (any FOV between MinHorizontalFieldOfView and MaxHorizontalFieldOfView can be commanded), or Discrete (the only supported FOVs are listed in DiscreteHorizontalFieldOfViewList). (Units: None)*/
      afrl::cmasi::FOVOperationMode::FOVOperationMode getFieldOfViewMode(void) const { return __FieldOfViewMode; }
      CameraConfiguration& setFieldOfViewMode(const afrl::cmasi::FOVOperationMode::FOVOperationMode val);

      /** The minimum horizontal field of view of the sensor. Only used if FieldOfViewMode is Continuous. (Units: degree)*/
      float getMinHorizontalFieldOfView(void) const { return __MinHorizontalFieldOfView; }
      CameraConfiguration& setMinHorizontalFieldOfView(const float val);

      /** The maximum horizontal field of view of the sensor. Only used if FieldOfViewMode is Continuous. (Units: degree)*/
      float getMaxHorizontalFieldOfView(void) const { return __MaxHorizontalFieldOfView; }
      CameraConfiguration& setMaxHorizontalFieldOfView(const float val);

      /** The horizontal field of views supported by the sensor. Only used if FieldOfViewMode is Discrete. (Units: degree)*/
      std::vector<float> & getDiscreteHorizontalFieldOfViewList(void) { return __DiscreteHorizontalFieldOfViewList; }

      /** The number of horizontal pixels in the output live-motion video stream. (Units: pixel)*/
      uint32_t getVideoStreamHorizontalResolution(void) const { return __VideoStreamHorizontalResolution; }
      CameraConfiguration& setVideoStreamHorizontalResolution(const uint32_t val);

      /** The number of vertical pixels in the output live-motion video stream. (Units: pixel)*/
      uint32_t getVideoStreamVerticalResolution(void) const { return __VideoStreamVerticalResolution; }
      CameraConfiguration& setVideoStreamVerticalResolution(const uint32_t val);



   protected:
      /** The supported wavelength band of this camera */
      afrl::cmasi::WavelengthBand::WavelengthBand __SupportedWavelengthBand;
      /** The manner in which field of views are commanded: Continuous (any FOV between MinHorizontalFieldOfView and MaxHorizontalFieldOfView can be commanded), or Discrete (the only supported FOVs are listed in DiscreteHorizontalFieldOfViewList). */
      afrl::cmasi::FOVOperationMode::FOVOperationMode __FieldOfViewMode;
      /** The minimum horizontal field of view of the sensor. Only used if FieldOfViewMode is Continuous. */
      float __MinHorizontalFieldOfView;
      /** The maximum horizontal field of view of the sensor. Only used if FieldOfViewMode is Continuous. */
      float __MaxHorizontalFieldOfView;
      /** The horizontal field of views supported by the sensor. Only used if FieldOfViewMode is Discrete. */
      std::vector< float > __DiscreteHorizontalFieldOfViewList;
      /** The number of horizontal pixels in the output live-motion video stream. */
      uint32_t __VideoStreamHorizontalResolution;
      /** The number of vertical pixels in the output live-motion video stream. */
      uint32_t __VideoStreamVerticalResolution;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_CAMERACONFIGURATION_H_
