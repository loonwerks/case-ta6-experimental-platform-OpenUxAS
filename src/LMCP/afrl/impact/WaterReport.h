// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_WATERREPORT_H_
#define _AFRL_IMPACT_WATERREPORT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AbstractGeometry.h"



namespace afrl {
namespace impact {


   bool isWaterReport(avtas::lmcp::Object* obj);
   bool isWaterReport(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > WaterReportDescendants();
   
   class WaterReport : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      WaterReport(void);

      // Copy Constructor
      WaterReport(const WaterReport &that);

      // Assignment Operator
      WaterReport & operator=(const WaterReport &that);

      // Destructor
      virtual ~WaterReport(void);

      // Equals overload
      bool operator==(const WaterReport & that);
      bool operator!=(const WaterReport & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual WaterReport* clone() const;

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
      /** Area for which this report is valid. A valid WaterReport must define Area (null not allowed) (Units: None)*/
      afrl::cmasi::AbstractGeometry* const getArea(void) { return __Area; }
      WaterReport& setArea(const afrl::cmasi::AbstractGeometry* const val);

      /** Speed of the current, e.g. due to tides or river flow (Units: meters/sec)*/
      float getCurrentSpeed(void) const { return __CurrentSpeed; }
      WaterReport& setCurrentSpeed(const float val);

      /** Direction of the current (Units: degree)*/
      float getCurrentDirection(void) const { return __CurrentDirection; }
      WaterReport& setCurrentDirection(const float val);

      /** Wave direction of travel. Generally in the direction of the wind, except near sea coasts(Units: degree)*/
      float getWaveDirection(void) const { return __WaveDirection; }
      WaterReport& setWaveDirection(const float val);

      /** Average wave height (Units: meters)*/
      float getWaveHeight(void) const { return __WaveHeight; }
      WaterReport& setWaveHeight(const float val);



   protected:
      /** Area for which this report is valid. A valid WaterReport must define Area (null not allowed) */
      afrl::cmasi::AbstractGeometry* __Area;
      /** Speed of the current, e.g. due to tides or river flow */
      float __CurrentSpeed;
      /** Direction of the current */
      float __CurrentDirection;
      /** Wave direction of travel. Generally in the direction of the wind, except near sea coasts*/
      float __WaveDirection;
      /** Average wave height */
      float __WaveHeight;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_WATERREPORT_H_
