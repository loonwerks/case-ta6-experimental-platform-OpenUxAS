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
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Circle::Subscription = "afrl.cmasi.Circle";
   const std::string Circle::TypeName = "Circle";
   const std::string Circle::SeriesName = "CMASI";
   const int64_t Circle::SeriesId = 4849604199710720000LL;
   const uint16_t Circle::SeriesVersion = 3;
   const uint32_t Circle::TypeId = 22;
   
   bool isCircle(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   bool isCircle(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   std::vector< std::string > CircleDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   Circle::Circle(void) : afrl::cmasi::AbstractGeometry()
   {
      __CenterPoint = new afrl::cmasi::Location3D();
      __Radius = 0.f;

   }
     
   Circle::Circle(const Circle &that) : afrl::cmasi::AbstractGeometry(that)
   {
        __CenterPoint = that.__CenterPoint == nullptr ? nullptr : that.__CenterPoint->clone();
        __Radius = that.__Radius;

   }
   
   Circle & Circle::operator=(const Circle &that)
   {
      if (this != &that)
      {
         afrl::cmasi::AbstractGeometry::operator=(that);
         if (__CenterPoint != nullptr) delete __CenterPoint;

         __CenterPoint = that.__CenterPoint == nullptr ? nullptr : that.__CenterPoint->clone();
         __Radius = that.__Radius;

      }
      return *this;
   }

   Circle* Circle::clone() const
   {
        return new Circle(*this);
   }
   
   Circle::~Circle(void)
   {
      if (__CenterPoint != nullptr) delete __CenterPoint;

   }
  
   void Circle::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::AbstractGeometry::pack(buf);
      // Copy the class into the buffer
      assert(__CenterPoint != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __CenterPoint, buf);
      buf.putFloat(__Radius);

   }
   
   void Circle::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::AbstractGeometry::unpack(buf);
      // Copy the buffer into the class
      {
         if (__CenterPoint != nullptr) delete __CenterPoint;
         __CenterPoint = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __CenterPoint = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__CenterPoint != nullptr) __CenterPoint->unpack(buf);
            else assert(__CenterPoint != nullptr);
         }
      }
      __Radius = buf.getFloat();

   }

   uint32_t Circle::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::AbstractGeometry::calculatePackedSize();
      size += (__CenterPoint != nullptr ? __CenterPoint->calculatePackedSize() + 15 : 1);
      size += sizeof(float);

      return size;
   }

   std::string Circle::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Circle ) {\n";
      indent = std::string((++depth)*3, ' ');

      oss << indent << "CenterPoint (Location3D)";
      if (__CenterPoint == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Radius (float) = " << __Radius << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Circle::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Circle Series=\"CMASI\">\n";
      if (__CenterPoint != nullptr)
      {
         str << ws << "   <CenterPoint>";
         str << "\n" + __CenterPoint->toXML(depth + 1) + ws + "   ";
         str << "</CenterPoint>\n";
      }
      str << ws << "   <Radius>" << __Radius << "</Radius>\n";
      str << ws << "</Circle>\n";

      return str.str();
   }

   bool Circle::operator==(const Circle & that)
   {
      if( afrl::cmasi::AbstractGeometry::operator!=(that) )
      {
          return false;
      }
      if(__CenterPoint && that.__CenterPoint)
      {
         if(__CenterPoint->getSeriesNameAsLong() != that.__CenterPoint->getSeriesNameAsLong()) return false;
         if(__CenterPoint->getSeriesVersion() != that.__CenterPoint->getSeriesVersion()) return false;
         if(__CenterPoint->getLmcpType() != that.__CenterPoint->getLmcpType()) return false;
         if( *(__CenterPoint) != *(that.__CenterPoint) ) return false;
      }
      else if(__CenterPoint != that.__CenterPoint) return false;
      if(__Radius != that.__Radius) return false;
      return true;

   }

   bool Circle::operator!=(const Circle & that)
   {
      return( !(operator==(that)) );
   }

   Circle& Circle::setCenterPoint(const afrl::cmasi::Location3D* const val)
   {
      if (__CenterPoint != nullptr) { delete __CenterPoint; __CenterPoint = nullptr; }
      if (val != nullptr) { __CenterPoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   Circle& Circle::setRadius(const float val)
   {
      __Radius = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

