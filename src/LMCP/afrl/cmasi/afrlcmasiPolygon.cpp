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
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Polygon::Subscription = "afrl.cmasi.Polygon";
   const std::string Polygon::TypeName = "Polygon";
   const std::string Polygon::SeriesName = "CMASI";
   const int64_t Polygon::SeriesId = 4849604199710720000LL;
   const uint16_t Polygon::SeriesVersion = 3;
   const uint32_t Polygon::TypeId = 42;
   
   bool isPolygon(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 42) return false;
      return true;
   }
   
   bool isPolygon(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 42) return false;
      return true;
   }
   
   std::vector< std::string > PolygonDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   Polygon::Polygon(void) : afrl::cmasi::AbstractGeometry()
   {

   }
     
   Polygon::Polygon(const Polygon &that) : afrl::cmasi::AbstractGeometry(that)
   {
        __BoundaryPoints.clear();
        for (size_t i=0; i< that.__BoundaryPoints.size(); i++)
        {
           __BoundaryPoints.push_back( that.__BoundaryPoints[i] == nullptr ? nullptr : that.__BoundaryPoints[i]->clone());
        }

   }
   
   Polygon & Polygon::operator=(const Polygon &that)
   {
      if (this != &that)
      {
         afrl::cmasi::AbstractGeometry::operator=(that);
         for (size_t i=0; i<__BoundaryPoints.size(); i++)
         {
            if (__BoundaryPoints[i] != nullptr) delete __BoundaryPoints[i];
         }

         __BoundaryPoints.clear();
         for (size_t i=0; i< that.__BoundaryPoints.size(); i++)
         {
            __BoundaryPoints.push_back( that.__BoundaryPoints[i] == nullptr ? nullptr : that.__BoundaryPoints[i]->clone());
         }

      }
      return *this;
   }

   Polygon* Polygon::clone() const
   {
        return new Polygon(*this);
   }
   
   Polygon::~Polygon(void)
   {
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         if (__BoundaryPoints[i] != nullptr) delete __BoundaryPoints[i];
      }

   }
  
   void Polygon::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::AbstractGeometry::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__BoundaryPoints.size()));
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         assert(__BoundaryPoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __BoundaryPoints[i], buf);
      }

   }
   
   void Polygon::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::AbstractGeometry::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         if (__BoundaryPoints[i] != nullptr)
            delete __BoundaryPoints[i];
      }
      __BoundaryPoints.clear();
      uint16_t __BoundaryPoints_length = buf.getUShort();
      for (uint32_t i=0; i< __BoundaryPoints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __BoundaryPoints.push_back(e);
         }
      }

   }

   uint32_t Polygon::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::AbstractGeometry::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         if (__BoundaryPoints[i] != nullptr)
         {
            size += __BoundaryPoints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string Polygon::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Polygon ) {\n";
      indent = std::string((++depth)*3, ' ');

      oss << indent << "BoundaryPoints (Location3D [ " << __BoundaryPoints.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Polygon::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Polygon Series=\"CMASI\">\n";
      str << ws << "   <BoundaryPoints>\n";
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         str << (__BoundaryPoints[i] == nullptr ? ( ws + "   <null/>\n") : (__BoundaryPoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </BoundaryPoints>\n";
      str << ws << "</Polygon>\n";

      return str.str();
   }

   bool Polygon::operator==(const Polygon & that)
   {
      if( afrl::cmasi::AbstractGeometry::operator!=(that) )
      {
          return false;
      }
      if(__BoundaryPoints.size() != that.__BoundaryPoints.size()) return false;
      for (size_t i=0; i<__BoundaryPoints.size(); i++)
      {
         if(__BoundaryPoints[i] && that.__BoundaryPoints[i])
         {
            if(__BoundaryPoints[i]->getSeriesNameAsLong() != that.__BoundaryPoints[i]->getSeriesNameAsLong()) return false;
            if(__BoundaryPoints[i]->getSeriesVersion() != that.__BoundaryPoints[i]->getSeriesVersion()) return false;
            if(__BoundaryPoints[i]->getLmcpType() != that.__BoundaryPoints[i]->getLmcpType()) return false;
            if( *(__BoundaryPoints[i]) != *(that.__BoundaryPoints[i]) ) return false;
         }
         else if(__BoundaryPoints[i] != that.__BoundaryPoints[i]) return false;
      }
      return true;

   }

   bool Polygon::operator!=(const Polygon & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

