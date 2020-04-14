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
#include "afrl/cmasi/Rectangle.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Rectangle::Subscription = "afrl.cmasi.Rectangle";
   const std::string Rectangle::TypeName = "Rectangle";
   const std::string Rectangle::SeriesName = "CMASI";
   const int64_t Rectangle::SeriesId = 4849604199710720000LL;
   const uint16_t Rectangle::SeriesVersion = 3;
   const uint32_t Rectangle::TypeId = 43;
   
   bool isRectangle(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 43) return false;
      return true;
   }
   
   bool isRectangle(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 43) return false;
      return true;
   }
   
   std::vector< std::string > RectangleDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   Rectangle::Rectangle(void) : afrl::cmasi::AbstractGeometry()
   {
      __CenterPoint = new afrl::cmasi::Location3D();
      __Width = 0.f;
      __Height = 0.f;
      __Rotation = 0.f;

   }
     
   Rectangle::Rectangle(const Rectangle &that) : afrl::cmasi::AbstractGeometry(that)
   {
        __CenterPoint = that.__CenterPoint == nullptr ? nullptr : that.__CenterPoint->clone();
        __Width = that.__Width;
        __Height = that.__Height;
        __Rotation = that.__Rotation;

   }
   
   Rectangle & Rectangle::operator=(const Rectangle &that)
   {
      if (this != &that)
      {
         afrl::cmasi::AbstractGeometry::operator=(that);
         if (__CenterPoint != nullptr) delete __CenterPoint;

         __CenterPoint = that.__CenterPoint == nullptr ? nullptr : that.__CenterPoint->clone();
         __Width = that.__Width;
         __Height = that.__Height;
         __Rotation = that.__Rotation;

      }
      return *this;
   }

   Rectangle* Rectangle::clone() const
   {
        return new Rectangle(*this);
   }
   
   Rectangle::~Rectangle(void)
   {
      if (__CenterPoint != nullptr) delete __CenterPoint;

   }
  
   void Rectangle::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::AbstractGeometry::pack(buf);
      // Copy the class into the buffer
      assert(__CenterPoint != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __CenterPoint, buf);
      buf.putFloat(__Width);
      buf.putFloat(__Height);
      buf.putFloat(__Rotation);

   }
   
   void Rectangle::unpack(avtas::lmcp::ByteBuffer & buf)
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
      __Width = buf.getFloat();
      __Height = buf.getFloat();
      __Rotation = buf.getFloat();

   }

   uint32_t Rectangle::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::AbstractGeometry::calculatePackedSize();
      size += (__CenterPoint != nullptr ? __CenterPoint->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string Rectangle::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Rectangle ) {\n";
      indent = std::string((++depth)*3, ' ');

      oss << indent << "CenterPoint (Location3D)";
      if (__CenterPoint == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Width (float) = " << __Width << "\n";
      oss << indent << "Height (float) = " << __Height << "\n";
      oss << indent << "Rotation (float) = " << __Rotation << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Rectangle::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Rectangle Series=\"CMASI\">\n";
      if (__CenterPoint != nullptr)
      {
         str << ws << "   <CenterPoint>";
         str << "\n" + __CenterPoint->toXML(depth + 1) + ws + "   ";
         str << "</CenterPoint>\n";
      }
      str << ws << "   <Width>" << __Width << "</Width>\n";
      str << ws << "   <Height>" << __Height << "</Height>\n";
      str << ws << "   <Rotation>" << __Rotation << "</Rotation>\n";
      str << ws << "</Rectangle>\n";

      return str.str();
   }

   bool Rectangle::operator==(const Rectangle & that)
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
      if(__Width != that.__Width) return false;
      if(__Height != that.__Height) return false;
      if(__Rotation != that.__Rotation) return false;
      return true;

   }

   bool Rectangle::operator!=(const Rectangle & that)
   {
      return( !(operator==(that)) );
   }

   Rectangle& Rectangle::setCenterPoint(const afrl::cmasi::Location3D* const val)
   {
      if (__CenterPoint != nullptr) { delete __CenterPoint; __CenterPoint = nullptr; }
      if (val != nullptr) { __CenterPoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   Rectangle& Rectangle::setWidth(const float val)
   {
      __Width = val;
      return *this;
   }

   Rectangle& Rectangle::setHeight(const float val)
   {
      __Height = val;
      return *this;
   }

   Rectangle& Rectangle::setRotation(const float val)
   {
      __Rotation = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

