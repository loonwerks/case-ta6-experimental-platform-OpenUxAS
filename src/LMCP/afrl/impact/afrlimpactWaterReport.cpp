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
#include "afrl/impact/WaterReport.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string WaterReport::Subscription = "afrl.impact.WaterReport";
   const std::string WaterReport::TypeName = "WaterReport";
   const std::string WaterReport::SeriesName = "IMPACT";
   const int64_t WaterReport::SeriesId = 5281966179208134656LL;
   const uint16_t WaterReport::SeriesVersion = 14;
   const uint32_t WaterReport::TypeId = 33;
   
   bool isWaterReport(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 33) return false;
      return true;
   }
   
   bool isWaterReport(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 33) return false;
      return true;
   }
   
   std::vector< std::string > WaterReportDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   WaterReport::WaterReport(void) : avtas::lmcp::Object()
   {
      __Area = new afrl::cmasi::AbstractGeometry();
      __CurrentSpeed = 0.f;
      __CurrentDirection = 0.f;
      __WaveDirection = 0.f;
      __WaveHeight = 0.f;

   }
     
   WaterReport::WaterReport(const WaterReport &that) : avtas::lmcp::Object(that)
   {
        __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
        __CurrentSpeed = that.__CurrentSpeed;
        __CurrentDirection = that.__CurrentDirection;
        __WaveDirection = that.__WaveDirection;
        __WaveHeight = that.__WaveHeight;

   }
   
   WaterReport & WaterReport::operator=(const WaterReport &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Area != nullptr) delete __Area;

         __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
         __CurrentSpeed = that.__CurrentSpeed;
         __CurrentDirection = that.__CurrentDirection;
         __WaveDirection = that.__WaveDirection;
         __WaveHeight = that.__WaveHeight;

      }
      return *this;
   }

   WaterReport* WaterReport::clone() const
   {
        return new WaterReport(*this);
   }
   
   WaterReport::~WaterReport(void)
   {
      if (__Area != nullptr) delete __Area;

   }
  
   void WaterReport::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      assert(__Area != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Area, buf);
      buf.putFloat(__CurrentSpeed);
      buf.putFloat(__CurrentDirection);
      buf.putFloat(__WaveDirection);
      buf.putFloat(__WaveHeight);

   }
   
   void WaterReport::unpack(avtas::lmcp::ByteBuffer & buf)
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
            __Area = (afrl::cmasi::AbstractGeometry*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Area != nullptr) __Area->unpack(buf);
            else assert(__Area != nullptr);
         }
      }
      __CurrentSpeed = buf.getFloat();
      __CurrentDirection = buf.getFloat();
      __WaveDirection = buf.getFloat();
      __WaveHeight = buf.getFloat();

   }

   uint32_t WaterReport::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += (__Area != nullptr ? __Area->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string WaterReport::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( WaterReport ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Area (AbstractGeometry)";
      if (__Area == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "CurrentSpeed (float) = " << __CurrentSpeed << "\n";
      oss << indent << "CurrentDirection (float) = " << __CurrentDirection << "\n";
      oss << indent << "WaveDirection (float) = " << __WaveDirection << "\n";
      oss << indent << "WaveHeight (float) = " << __WaveHeight << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string WaterReport::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<WaterReport Series=\"IMPACT\">\n";
      if (__Area != nullptr)
      {
         str << ws << "   <Area>";
         str << "\n" + __Area->toXML(depth + 1) + ws + "   ";
         str << "</Area>\n";
      }
      str << ws << "   <CurrentSpeed>" << __CurrentSpeed << "</CurrentSpeed>\n";
      str << ws << "   <CurrentDirection>" << __CurrentDirection << "</CurrentDirection>\n";
      str << ws << "   <WaveDirection>" << __WaveDirection << "</WaveDirection>\n";
      str << ws << "   <WaveHeight>" << __WaveHeight << "</WaveHeight>\n";
      str << ws << "</WaterReport>\n";

      return str.str();
   }

   bool WaterReport::operator==(const WaterReport & that)
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
      if(__CurrentSpeed != that.__CurrentSpeed) return false;
      if(__CurrentDirection != that.__CurrentDirection) return false;
      if(__WaveDirection != that.__WaveDirection) return false;
      if(__WaveHeight != that.__WaveHeight) return false;
      return true;

   }

   bool WaterReport::operator!=(const WaterReport & that)
   {
      return( !(operator==(that)) );
   }

   WaterReport& WaterReport::setArea(const afrl::cmasi::AbstractGeometry* const val)
   {
      if (__Area != nullptr) { delete __Area; __Area = nullptr; }
      if (val != nullptr) { __Area = const_cast< afrl::cmasi::AbstractGeometry* > (val); }
      return *this;
   }

   WaterReport& WaterReport::setCurrentSpeed(const float val)
   {
      __CurrentSpeed = val;
      return *this;
   }

   WaterReport& WaterReport::setCurrentDirection(const float val)
   {
      __CurrentDirection = val;
      return *this;
   }

   WaterReport& WaterReport::setWaveDirection(const float val)
   {
      __WaveDirection = val;
      return *this;
   }

   WaterReport& WaterReport::setWaveHeight(const float val)
   {
      __WaveHeight = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

