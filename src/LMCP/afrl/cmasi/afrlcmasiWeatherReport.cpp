// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include <cassert>
#include <sstream>
#include <iomanip>
#include "afrl/cmasi/WeatherReport.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string WeatherReport::Subscription = "afrl.cmasi.WeatherReport";
   const std::string WeatherReport::TypeName = "WeatherReport";
   const std::string WeatherReport::SeriesName = "CMASI";
   const int64_t WeatherReport::SeriesId = 4849604199710720000LL;
   const uint16_t WeatherReport::SeriesVersion = 3;
   const uint32_t WeatherReport::TypeId = 55;
   
   bool isWeatherReport(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 55) return false;
      return true;
   }
   
   bool isWeatherReport(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 55) return false;
      return true;
   }
   
   std::vector< std::string > WeatherReportDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   WeatherReport::WeatherReport(void) : avtas::lmcp::Object()
   {
      __Area = nullptr;
      __WindSpeed = 0.f;
      __WindDirection = 0.f;
      __Visibility = 0.f;
      __CloudCeiling = 0.f;
      __CloudCoverage = 0.f;

   }
     
   WeatherReport::WeatherReport(const WeatherReport &that) : avtas::lmcp::Object(that)
   {
        __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
        __WindSpeed = that.__WindSpeed;
        __WindDirection = that.__WindDirection;
        __Visibility = that.__Visibility;
        __CloudCeiling = that.__CloudCeiling;
        __CloudCoverage = that.__CloudCoverage;

   }
   
   WeatherReport & WeatherReport::operator=(const WeatherReport &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Area != nullptr) delete __Area;

         __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
         __WindSpeed = that.__WindSpeed;
         __WindDirection = that.__WindDirection;
         __Visibility = that.__Visibility;
         __CloudCeiling = that.__CloudCeiling;
         __CloudCoverage = that.__CloudCoverage;

      }
      return *this;
   }

   WeatherReport* WeatherReport::clone() const
   {
        return new WeatherReport(*this);
   }
   
   WeatherReport::~WeatherReport(void)
   {
      if (__Area != nullptr) delete __Area;

   }
  
   void WeatherReport::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Area, buf);
      buf.putFloat(__WindSpeed);
      buf.putFloat(__WindDirection);
      buf.putFloat(__Visibility);
      buf.putFloat(__CloudCeiling);
      buf.putFloat(__CloudCoverage);

   }
   
   void WeatherReport::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      {
         if (__Area != nullptr) delete __Area;
         __Area = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Area = (afrl::cmasi::AbstractZone*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Area != nullptr) __Area->unpack(buf);
         }
      }
      __WindSpeed = buf.getFloat();
      __WindDirection = buf.getFloat();
      __Visibility = buf.getFloat();
      __CloudCeiling = buf.getFloat();
      __CloudCoverage = buf.getFloat();

   }

   uint32_t WeatherReport::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += (__Area != nullptr ? __Area->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string WeatherReport::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( WeatherReport ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Area (AbstractZone)";
      if (__Area == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "WindSpeed (float) = " << __WindSpeed << "\n";
      oss << indent << "WindDirection (float) = " << __WindDirection << "\n";
      oss << indent << "Visibility (float) = " << __Visibility << "\n";
      oss << indent << "CloudCeiling (float) = " << __CloudCeiling << "\n";
      oss << indent << "CloudCoverage (float) = " << __CloudCoverage << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string WeatherReport::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<WeatherReport Series=\"CMASI\">\n";
      if (__Area != nullptr)
      {
         str << ws << "   <Area>";
         str << "\n" + __Area->toXML(depth + 1) + ws + "   ";
         str << "</Area>\n";
      }
      str << ws << "   <WindSpeed>" << __WindSpeed << "</WindSpeed>\n";
      str << ws << "   <WindDirection>" << __WindDirection << "</WindDirection>\n";
      str << ws << "   <Visibility>" << __Visibility << "</Visibility>\n";
      str << ws << "   <CloudCeiling>" << __CloudCeiling << "</CloudCeiling>\n";
      str << ws << "   <CloudCoverage>" << __CloudCoverage << "</CloudCoverage>\n";
      str << ws << "</WeatherReport>\n";

      return str.str();
   }

   bool WeatherReport::operator==(const WeatherReport & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Area && that.__Area)
      {
         if(__Area->getSeriesNameAsLong() != that.__Area->getSeriesNameAsLong()) return false;
         if(__Area->getSeriesVersion() != that.__Area->getSeriesVersion()) return false;
         if(__Area->getLmcpType() != that.__Area->getLmcpType()) return false;
         if( *(__Area) != *(that.__Area) ) return false;
      }
      else if(__Area != that.__Area) return false;
      if(__WindSpeed != that.__WindSpeed) return false;
      if(__WindDirection != that.__WindDirection) return false;
      if(__Visibility != that.__Visibility) return false;
      if(__CloudCeiling != that.__CloudCeiling) return false;
      if(__CloudCoverage != that.__CloudCoverage) return false;
      return true;

   }

   bool WeatherReport::operator!=(const WeatherReport & that)
   {
      return( !(operator==(that)) );
   }

   WeatherReport& WeatherReport::setArea(const afrl::cmasi::AbstractZone* const val)
   {
      if (__Area != nullptr) { delete __Area; __Area = nullptr; }
      if (val != nullptr) { __Area = const_cast< afrl::cmasi::AbstractZone* > (val); }
      return *this;
   }

   WeatherReport& WeatherReport::setWindSpeed(const float val)
   {
      __WindSpeed = val;
      return *this;
   }

   WeatherReport& WeatherReport::setWindDirection(const float val)
   {
      __WindDirection = val;
      return *this;
   }

   WeatherReport& WeatherReport::setVisibility(const float val)
   {
      __Visibility = val;
      return *this;
   }

   WeatherReport& WeatherReport::setCloudCeiling(const float val)
   {
      __CloudCeiling = val;
      return *this;
   }

   WeatherReport& WeatherReport::setCloudCoverage(const float val)
   {
      __CloudCoverage = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

