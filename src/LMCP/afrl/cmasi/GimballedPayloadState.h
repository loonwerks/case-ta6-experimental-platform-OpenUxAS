// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_GIMBALLEDPAYLOADSTATE_H_
#define _AFRL_CMASI_GIMBALLEDPAYLOADSTATE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/PayloadState.h"
#include "afrl/cmasi/GimbalPointingMode.h"



namespace afrl {
namespace cmasi {


   bool isGimballedPayloadState(avtas::lmcp::Object* obj);
   bool isGimballedPayloadState(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GimballedPayloadStateDescendants();
   
   class GimballedPayloadState : public afrl::cmasi::PayloadState {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GimballedPayloadState(void);

      // Copy Constructor
      GimballedPayloadState(const GimballedPayloadState &that);

      // Assignment Operator
      GimballedPayloadState & operator=(const GimballedPayloadState &that);

      // Destructor
      virtual ~GimballedPayloadState(void);

      // Equals overload
      bool operator==(const GimballedPayloadState & that);
      bool operator!=(const GimballedPayloadState & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GimballedPayloadState* clone() const;

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
      /** Current pointing mode of the gimbal to which this payload is attached(Units: None)*/
      afrl::cmasi::GimbalPointingMode::GimbalPointingMode getPointingMode(void) const { return __PointingMode; }
      GimballedPayloadState& setPointingMode(const afrl::cmasi::GimbalPointingMode::GimbalPointingMode val);

      /** Current azimuth angle of the gimbal boresight (positive from vehicle x-axis). (Units: degree)*/
      float getAzimuth(void) const { return __Azimuth; }
      GimballedPayloadState& setAzimuth(const float val);

      /** Current elevation angle of the gimbal boresight (positive from vehicle x-y plane). (Units: degree)*/
      float getElevation(void) const { return __Elevation; }
      GimballedPayloadState& setElevation(const float val);

      /** Current rotation angle of the gimbal boresight (0 degrees aligned with aircraft normal, positive clockwise). (Units: degree)*/
      float getRotation(void) const { return __Rotation; }
      GimballedPayloadState& setRotation(const float val);



   protected:
      /** Current pointing mode of the gimbal to which this payload is attached*/
      afrl::cmasi::GimbalPointingMode::GimbalPointingMode __PointingMode;
      /** Current azimuth angle of the gimbal boresight (positive from vehicle x-axis). */
      float __Azimuth;
      /** Current elevation angle of the gimbal boresight (positive from vehicle x-y plane). */
      float __Elevation;
      /** Current rotation angle of the gimbal boresight (0 degrees aligned with aircraft normal, positive clockwise). */
      float __Rotation;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_GIMBALLEDPAYLOADSTATE_H_
