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
#include "afrl/cmasi/Wedge.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Wedge::Subscription = "afrl.cmasi.Wedge";
   const std::string Wedge::TypeName = "Wedge";
   const std::string Wedge::SeriesName = "CMASI";
   const int64_t Wedge::SeriesId = 4849604199710720000LL;
   const uint16_t Wedge::SeriesVersion = 3;
   const uint32_t Wedge::TypeId = 16;
   
   bool isWedge(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   bool isWedge(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   std::vector< std::string > WedgeDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   Wedge::Wedge(void) : avtas::lmcp::Object()
   {
      __AzimuthCenterline = 0.f;
      __VerticalCenterline = 0.f;
      __AzimuthExtent = 0.f;
      __VerticalExtent = 0.f;

   }
     
   Wedge::Wedge(const Wedge &that) : avtas::lmcp::Object(that)
   {
        __AzimuthCenterline = that.__AzimuthCenterline;
        __VerticalCenterline = that.__VerticalCenterline;
        __AzimuthExtent = that.__AzimuthExtent;
        __VerticalExtent = that.__VerticalExtent;

   }
   
   Wedge & Wedge::operator=(const Wedge &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __AzimuthCenterline = that.__AzimuthCenterline;
         __VerticalCenterline = that.__VerticalCenterline;
         __AzimuthExtent = that.__AzimuthExtent;
         __VerticalExtent = that.__VerticalExtent;

      }
      return *this;
   }

   Wedge* Wedge::clone() const
   {
        return new Wedge(*this);
   }
   
   Wedge::~Wedge(void)
   {

   }
  
   void Wedge::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__AzimuthCenterline);
      buf.putFloat(__VerticalCenterline);
      buf.putFloat(__AzimuthExtent);
      buf.putFloat(__VerticalExtent);

   }
   
   void Wedge::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __AzimuthCenterline = buf.getFloat();
      __VerticalCenterline = buf.getFloat();
      __AzimuthExtent = buf.getFloat();
      __VerticalExtent = buf.getFloat();

   }

   uint32_t Wedge::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string Wedge::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Wedge ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AzimuthCenterline (float) = " << __AzimuthCenterline << "\n";
      oss << indent << "VerticalCenterline (float) = " << __VerticalCenterline << "\n";
      oss << indent << "AzimuthExtent (float) = " << __AzimuthExtent << "\n";
      oss << indent << "VerticalExtent (float) = " << __VerticalExtent << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Wedge::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Wedge Series=\"CMASI\">\n";
      str << ws << "   <AzimuthCenterline>" << __AzimuthCenterline << "</AzimuthCenterline>\n";
      str << ws << "   <VerticalCenterline>" << __VerticalCenterline << "</VerticalCenterline>\n";
      str << ws << "   <AzimuthExtent>" << __AzimuthExtent << "</AzimuthExtent>\n";
      str << ws << "   <VerticalExtent>" << __VerticalExtent << "</VerticalExtent>\n";
      str << ws << "</Wedge>\n";

      return str.str();
   }

   bool Wedge::operator==(const Wedge & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__AzimuthCenterline != that.__AzimuthCenterline) return false;
      if(__VerticalCenterline != that.__VerticalCenterline) return false;
      if(__AzimuthExtent != that.__AzimuthExtent) return false;
      if(__VerticalExtent != that.__VerticalExtent) return false;
      return true;

   }

   bool Wedge::operator!=(const Wedge & that)
   {
      return( !(operator==(that)) );
   }

   Wedge& Wedge::setAzimuthCenterline(const float val)
   {
      __AzimuthCenterline = val;
      return *this;
   }

   Wedge& Wedge::setVerticalCenterline(const float val)
   {
      __VerticalCenterline = val;
      return *this;
   }

   Wedge& Wedge::setAzimuthExtent(const float val)
   {
      __AzimuthExtent = val;
      return *this;
   }

   Wedge& Wedge::setVerticalExtent(const float val)
   {
      __VerticalExtent = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

