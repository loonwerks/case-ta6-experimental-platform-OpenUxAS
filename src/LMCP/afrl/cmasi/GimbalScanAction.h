// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_GIMBALSCANACTION_H_
#define _AFRL_CMASI_GIMBALSCANACTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/PayloadAction.h"



namespace afrl {
namespace cmasi {


   bool isGimbalScanAction(avtas::lmcp::Object* obj);
   bool isGimbalScanAction(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GimbalScanActionDescendants();
   
   class GimbalScanAction : public afrl::cmasi::PayloadAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GimbalScanAction(void);

      // Copy Constructor
      GimbalScanAction(const GimbalScanAction &that);

      // Assignment Operator
      GimbalScanAction & operator=(const GimbalScanAction &that);

      // Destructor
      virtual ~GimbalScanAction(void);

      // Equals overload
      bool operator==(const GimbalScanAction & that);
      bool operator!=(const GimbalScanAction & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GimbalScanAction* clone() const;

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
      /** sets the time-to-scan in the azimuthal direction. This is the time to complete one sweep through the the length of EndAzimuth - StartAzimuth. (Units: degree/second)*/
      float getAzimuthSlewRate(void) const { return __AzimuthSlewRate; }
      GimbalScanAction& setAzimuthSlewRate(const float val);

      /** sets the time-to-scan in the elevation direction. This is the time to complete one sweep through the the length of EndElevation - StartElevation. (Units: degree/second)*/
      float getElevationSlewRate(void) const { return __ElevationSlewRate; }
      GimbalScanAction& setElevationSlewRate(const float val);

      /** The starting azimuth for the sensor scan (boresight angle right of aircraft long axis)(Units: degree)*/
      float getStartAzimuth(void) const { return __StartAzimuth; }
      GimbalScanAction& setStartAzimuth(const float val);

      /** The ending azimuth for the sensor scan (boresight angle right of aircraft long axis) (Units: degree)*/
      float getEndAzimuth(void) const { return __EndAzimuth; }
      GimbalScanAction& setEndAzimuth(const float val);

      /** The starting elevation for the sensor scan (boresight angle positive from aircraft x-y plane)(Units: degree)*/
      float getStartElevation(void) const { return __StartElevation; }
      GimbalScanAction& setStartElevation(const float val);

      /** The ending elevation for the sensor scan (boresight angle positive from aircraft x-y plane)(Units: degree)*/
      float getEndElevation(void) const { return __EndElevation; }
      GimbalScanAction& setEndElevation(const float val);

      /** Number of sensor sweeps to perform. A zero value denotes indefinite number of sweeps. (Units: None)*/
      uint32_t getCycles(void) const { return __Cycles; }
      GimbalScanAction& setCycles(const uint32_t val);



   protected:
      /** sets the time-to-scan in the azimuthal direction. This is the time to complete one sweep through the the length of EndAzimuth - StartAzimuth. */
      float __AzimuthSlewRate;
      /** sets the time-to-scan in the elevation direction. This is the time to complete one sweep through the the length of EndElevation - StartElevation. */
      float __ElevationSlewRate;
      /** The starting azimuth for the sensor scan (boresight angle right of aircraft long axis)*/
      float __StartAzimuth;
      /** The ending azimuth for the sensor scan (boresight angle right of aircraft long axis) */
      float __EndAzimuth;
      /** The starting elevation for the sensor scan (boresight angle positive from aircraft x-y plane)*/
      float __StartElevation;
      /** The ending elevation for the sensor scan (boresight angle positive from aircraft x-y plane)*/
      float __EndElevation;
      /** Number of sensor sweeps to perform. A zero value denotes indefinite number of sweeps. */
      uint32_t __Cycles;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_GIMBALSCANACTION_H_
