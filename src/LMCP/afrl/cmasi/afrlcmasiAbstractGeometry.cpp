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
#include "afrl/cmasi/AbstractGeometry.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AbstractGeometry::Subscription = "afrl.cmasi.AbstractGeometry";
   const std::string AbstractGeometry::TypeName = "AbstractGeometry";
   const std::string AbstractGeometry::SeriesName = "CMASI";
   const int64_t AbstractGeometry::SeriesId = 4849604199710720000LL;
   const uint16_t AbstractGeometry::SeriesVersion = 3;
   const uint32_t AbstractGeometry::TypeId = 1;
   
   bool isAbstractGeometry(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isAbstractGeometry(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > AbstractGeometryDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.Circle");
       descendants.push_back("afrl.cmasi.Polygon");
       descendants.push_back("afrl.cmasi.Rectangle");

       return descendants;
   }
   
   AbstractGeometry::AbstractGeometry(void) : avtas::lmcp::Object()
   {

   }
     
   AbstractGeometry::AbstractGeometry(const AbstractGeometry &that) : avtas::lmcp::Object(that)
   {

   }
   
   AbstractGeometry & AbstractGeometry::operator=(const AbstractGeometry &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);


      }
      return *this;
   }

   AbstractGeometry* AbstractGeometry::clone() const
   {
        return new AbstractGeometry(*this);
   }
   
   AbstractGeometry::~AbstractGeometry(void)
   {

   }
  
   void AbstractGeometry::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer

   }
   
   void AbstractGeometry::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t AbstractGeometry::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();

      return size;
   }

   std::string AbstractGeometry::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AbstractGeometry ) {\n";
      indent = std::string((++depth)*3, ' ');

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AbstractGeometry::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AbstractGeometry Series=\"CMASI\">\n";
      str << ws << "</AbstractGeometry>\n";

      return str.str();
   }

   bool AbstractGeometry::operator==(const AbstractGeometry & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool AbstractGeometry::operator!=(const AbstractGeometry & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace cmasi
} // end namespace afrl

