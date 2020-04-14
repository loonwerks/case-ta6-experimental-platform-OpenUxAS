// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WEATHERREPORT_H_
#define _AFRL_CMASI_WEATHERREPORT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AbstractZone.h"



namespace afrl {
namespace cmasi {


   bool isWeatherReport(avtas::lmcp::Object* obj);
   bool isWeatherReport(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > WeatherReportDescendants();
   
   class WeatherReport : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      WeatherReport(void);

      // Copy Constructor
      WeatherReport(const WeatherReport &that);

      // Assignment Operator
      WeatherReport & operator=(const WeatherReport &that);

      // Destructor
      virtual ~WeatherReport(void);

      // Equals overload
      bool operator==(const WeatherReport & that);
      bool operator!=(const WeatherReport & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual WeatherReport* clone() const;

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
      /** The area for which this report pertains. If this is null, then the report pertains to the entire mission area. (Units: None)*/
      afrl::cmasi::AbstractZone* const getArea(void) { return __Area; }
      WeatherReport& setArea(const afrl::cmasi::AbstractZone* const val);

      /** Windspeed value for this area (Units: meter/sec)*/
      float getWindSpeed(void) const { return __WindSpeed; }
      WeatherReport& setWindSpeed(const float val);

      /** Wind direction. Direction is the true heading from which the wind is blowing. (Units: degree)*/
      float getWindDirection(void) const { return __WindDirection; }
      WeatherReport& setWindDirection(const float val);

      /** Visibility, according to the <a href="http://en.wikipedia.org/wiki/Visibility">ICAO definition</a>. (Units: meter)*/
      float getVisibility(void) const { return __Visibility; }
      WeatherReport& setVisibility(const float val);

      /** Height of the bottom of a cloud layer, in MSL altitude. If there is more than one cloud layer, create WeatherReports for each zone that contains a cloud layer. A value of "0" denotes free-of-clouds (Units: meter)*/
      float getCloudCeiling(void) const { return __CloudCeiling; }
      WeatherReport& setCloudCeiling(const float val);

      /** Amount of cloud coverage for the given cloud layer. Values should be 0..1, 0 denoting free-of-clouds, and 1 denoting overcast. (Units: None)*/
      float getCloudCoverage(void) const { return __CloudCoverage; }
      WeatherReport& setCloudCoverage(const float val);



   protected:
      /** The area for which this report pertains. If this is null, then the report pertains to the entire mission area. */
      afrl::cmasi::AbstractZone* __Area;
      /** Windspeed value for this area */
      float __WindSpeed;
      /** Wind direction. Direction is the true heading from which the wind is blowing. */
      float __WindDirection;
      /** Visibility, according to the <a href="http://en.wikipedia.org/wiki/Visibility">ICAO definition</a>. */
      float __Visibility;
      /** Height of the bottom of a cloud layer, in MSL altitude. If there is more than one cloud layer, create WeatherReports for each zone that contains a cloud layer. A value of "0" denotes free-of-clouds */
      float __CloudCeiling;
      /** Amount of cloud coverage for the given cloud layer. Values should be 0..1, 0 denoting free-of-clouds, and 1 denoting overcast. */
      float __CloudCoverage;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WEATHERREPORT_H_
