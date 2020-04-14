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
#include "afrl/cmasi/RemoveZones.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RemoveZones::Subscription = "afrl.cmasi.RemoveZones";
   const std::string RemoveZones::TypeName = "RemoveZones";
   const std::string RemoveZones::SeriesName = "CMASI";
   const int64_t RemoveZones::SeriesId = 4849604199710720000LL;
   const uint16_t RemoveZones::SeriesVersion = 3;
   const uint32_t RemoveZones::TypeId = 52;
   
   bool isRemoveZones(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 52) return false;
      return true;
   }
   
   bool isRemoveZones(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 52) return false;
      return true;
   }
   
   std::vector< std::string > RemoveZonesDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RemoveZones::RemoveZones(void) : avtas::lmcp::Object()
   {

   }
     
   RemoveZones::RemoveZones(const RemoveZones &that) : avtas::lmcp::Object(that)
   {
        __ZoneList.clear();
        for (size_t i=0; i< that.__ZoneList.size(); i++)
        {
           __ZoneList.push_back( that.__ZoneList[i]);
        }

   }
   
   RemoveZones & RemoveZones::operator=(const RemoveZones &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __ZoneList.clear();
         for (size_t i=0; i< that.__ZoneList.size(); i++)
         {
            __ZoneList.push_back( that.__ZoneList[i]);
         }

      }
      return *this;
   }

   RemoveZones* RemoveZones::clone() const
   {
        return new RemoveZones(*this);
   }
   
   RemoveZones::~RemoveZones(void)
   {

   }
  
   void RemoveZones::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__ZoneList.size()));
      for (size_t i=0; i<__ZoneList.size(); i++)
      {
         buf.putLong(__ZoneList[i]);
      }

   }
   
   void RemoveZones::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ZoneList.clear();
      uint16_t __ZoneList_length = buf.getUShort();
      for (uint32_t i=0; i< __ZoneList_length; i++)
      {
         __ZoneList.push_back(buf.getLong() );
      }

   }

   uint32_t RemoveZones::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __ZoneList.size();

      return size;
   }

   std::string RemoveZones::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RemoveZones ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ZoneList (int64 [ " << __ZoneList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RemoveZones::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RemoveZones Series=\"CMASI\">\n";
      str << ws << "   <ZoneList>\n";
      for (size_t i=0; i<__ZoneList.size(); i++)
      {
         str << ws << "   <int64>" << __ZoneList[i] << "</int64>\n";
      }
      str << ws << "   </ZoneList>\n";
      str << ws << "</RemoveZones>\n";

      return str.str();
   }

   bool RemoveZones::operator==(const RemoveZones & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ZoneList.size() != that.__ZoneList.size()) return false;
      for (size_t i=0; i<__ZoneList.size(); i++)
      {
         if(__ZoneList[i] != that.__ZoneList[i]) return false;
      }
      return true;

   }

   bool RemoveZones::operator!=(const RemoveZones & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

