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
#include "afrl/cmasi/Location3D.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Location3D::Subscription = "afrl.cmasi.Location3D";
   const std::string Location3D::TypeName = "Location3D";
   const std::string Location3D::SeriesName = "CMASI";
   const int64_t Location3D::SeriesId = 4849604199710720000LL;
   const uint16_t Location3D::SeriesVersion = 3;
   const uint32_t Location3D::TypeId = 3;
   
   bool isLocation3D(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isLocation3D(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > Location3DDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.Waypoint");
       descendants.push_back("afrl.cmasi.PathWaypoint");

       return descendants;
   }
   
   Location3D::Location3D(void) : avtas::lmcp::Object()
   {
      __Latitude = 0;
      __Longitude = 0;
      __Altitude = 0.f;
      __AltitudeType = afrl::cmasi::AltitudeType::MSL;

   }
     
   Location3D::Location3D(const Location3D &that) : avtas::lmcp::Object(that)
   {
        __Latitude = that.__Latitude;
        __Longitude = that.__Longitude;
        __Altitude = that.__Altitude;
        __AltitudeType = that.__AltitudeType;

   }
   
   Location3D & Location3D::operator=(const Location3D &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Latitude = that.__Latitude;
         __Longitude = that.__Longitude;
         __Altitude = that.__Altitude;
         __AltitudeType = that.__AltitudeType;

      }
      return *this;
   }

   Location3D* Location3D::clone() const
   {
        return new Location3D(*this);
   }
   
   Location3D::~Location3D(void)
   {

   }
  
   void Location3D::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putDouble(__Latitude);
      buf.putDouble(__Longitude);
      buf.putFloat(__Altitude);
      buf.putInt( (int32_t) __AltitudeType);

   }
   
   void Location3D::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Latitude = buf.getDouble();
      __Longitude = buf.getDouble();
      __Altitude = buf.getFloat();
      __AltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();

   }

   uint32_t Location3D::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(double);
      size += sizeof(double);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);

      return size;
   }

   std::string Location3D::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Location3D ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Latitude (double) = " << __Latitude << "\n";
      oss << indent << "Longitude (double) = " << __Longitude << "\n";
      oss << indent << "Altitude (float) = " << __Altitude << "\n";
      oss << indent << "AltitudeType (AltitudeType) = " << __AltitudeType << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Location3D::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Location3D Series=\"CMASI\">\n";
      str << ws << "   <Latitude>" << __Latitude << "</Latitude>\n";
      str << ws << "   <Longitude>" << __Longitude << "</Longitude>\n";
      str << ws << "   <Altitude>" << __Altitude << "</Altitude>\n";
      str << ws << "   <AltitudeType>" << afrl::cmasi::AltitudeType::get_string(__AltitudeType) << "</AltitudeType>\n";
      str << ws << "</Location3D>\n";

      return str.str();
   }

   bool Location3D::operator==(const Location3D & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Latitude != that.__Latitude) return false;
      if(__Longitude != that.__Longitude) return false;
      if(__Altitude != that.__Altitude) return false;
      if(__AltitudeType != that.__AltitudeType) return false;
      return true;

   }

   bool Location3D::operator!=(const Location3D & that)
   {
      return( !(operator==(that)) );
   }

   Location3D& Location3D::setLatitude(const double val)
   {
      __Latitude = val;
      return *this;
   }

   Location3D& Location3D::setLongitude(const double val)
   {
      __Longitude = val;
      return *this;
   }

   Location3D& Location3D::setAltitude(const float val)
   {
      __Altitude = val;
      return *this;
   }

   Location3D& Location3D::setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __AltitudeType = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

