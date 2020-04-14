// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_CAMERASTATE_H_
#define _AFRL_CMASI_CAMERASTATE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/GimballedPayloadState.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Location3D.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isCameraState(avtas::lmcp::Object* obj);
   bool isCameraState(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > CameraStateDescendants();
   
   class CameraState : public afrl::cmasi::GimballedPayloadState {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      CameraState(void);

      // Copy Constructor
      CameraState(const CameraState &that);

      // Assignment Operator
      CameraState & operator=(const CameraState &that);

      // Destructor
      virtual ~CameraState(void);

      // Equals overload
      bool operator==(const CameraState & that);
      bool operator!=(const CameraState & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual CameraState* clone() const;

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
      /** The current horizontal field of view (in sensor axis). (Units: degree)*/
      float getHorizontalFieldOfView(void) const { return __HorizontalFieldOfView; }
      CameraState& setHorizontalFieldOfView(const float val);

      /** The current vertical field of view (in sensor axis). (Units: degree)*/
      float getVerticalFieldOfView(void) const { return __VerticalFieldOfView; }
      CameraState& setVerticalFieldOfView(const float val);

      /** The current sensor footprint of the camera represented as a polygon with n-vertices. If this field contains zero items then the footprint is unavailable or was not calculated. (Units: None)*/
      std::vector<afrl::cmasi::Location3D*> & getFootprint(void) { return __Footprint; }

      /** the current location according to the intersection of a ray along the center axis of the current camera field of view with the ground. If this field is null, then the location was not computed. (Units: None)*/
      afrl::cmasi::Location3D* const getCenterpoint(void) { return __Centerpoint; }
      CameraState& setCenterpoint(const afrl::cmasi::Location3D* const val);



   protected:
      /** The current horizontal field of view (in sensor axis). */
      float __HorizontalFieldOfView;
      /** The current vertical field of view (in sensor axis). */
      float __VerticalFieldOfView;
      /** The current sensor footprint of the camera represented as a polygon with n-vertices. If this field contains zero items then the footprint is unavailable or was not calculated. */
      std::vector< afrl::cmasi::Location3D* > __Footprint;
      /** the current location according to the intersection of a ray along the center axis of the current camera field of view with the ground. If this field is null, then the location was not computed. */
      afrl::cmasi::Location3D* __Centerpoint;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_CAMERASTATE_H_
