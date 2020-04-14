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
#include "afrl/cmasi/OperatingRegion.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string OperatingRegion::Subscription = "afrl.cmasi.OperatingRegion";
   const std::string OperatingRegion::TypeName = "OperatingRegion";
   const std::string OperatingRegion::SeriesName = "CMASI";
   const int64_t OperatingRegion::SeriesId = 4849604199710720000LL;
   const uint16_t OperatingRegion::SeriesVersion = 3;
   const uint32_t OperatingRegion::TypeId = 39;
   
   bool isOperatingRegion(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 39) return false;
      return true;
   }
   
   bool isOperatingRegion(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 39) return false;
      return true;
   }
   
   std::vector< std::string > OperatingRegionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   OperatingRegion::OperatingRegion(void) : avtas::lmcp::Object()
   {
      __ID = 0LL;

   }
     
   OperatingRegion::OperatingRegion(const OperatingRegion &that) : avtas::lmcp::Object(that)
   {
        __ID = that.__ID;
        __KeepInAreas.clear();
        for (size_t i=0; i< that.__KeepInAreas.size(); i++)
        {
           __KeepInAreas.push_back( that.__KeepInAreas[i]);
        }
        __KeepOutAreas.clear();
        for (size_t i=0; i< that.__KeepOutAreas.size(); i++)
        {
           __KeepOutAreas.push_back( that.__KeepOutAreas[i]);
        }

   }
   
   OperatingRegion & OperatingRegion::operator=(const OperatingRegion &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __ID = that.__ID;
         __KeepInAreas.clear();
         for (size_t i=0; i< that.__KeepInAreas.size(); i++)
         {
            __KeepInAreas.push_back( that.__KeepInAreas[i]);
         }
         __KeepOutAreas.clear();
         for (size_t i=0; i< that.__KeepOutAreas.size(); i++)
         {
            __KeepOutAreas.push_back( that.__KeepOutAreas[i]);
         }

      }
      return *this;
   }

   OperatingRegion* OperatingRegion::clone() const
   {
        return new OperatingRegion(*this);
   }
   
   OperatingRegion::~OperatingRegion(void)
   {

   }
  
   void OperatingRegion::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ID);
      buf.putUShort( static_cast<uint16_t>(__KeepInAreas.size()));
      for (size_t i=0; i<__KeepInAreas.size(); i++)
      {
         buf.putLong(__KeepInAreas[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__KeepOutAreas.size()));
      for (size_t i=0; i<__KeepOutAreas.size(); i++)
      {
         buf.putLong(__KeepOutAreas[i]);
      }

   }
   
   void OperatingRegion::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ID = buf.getLong();
      __KeepInAreas.clear();
      uint16_t __KeepInAreas_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepInAreas_length; i++)
      {
         __KeepInAreas.push_back(buf.getLong() );
      }
      __KeepOutAreas.clear();
      uint16_t __KeepOutAreas_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepOutAreas_length; i++)
      {
         __KeepOutAreas.push_back(buf.getLong() );
      }

   }

   uint32_t OperatingRegion::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __KeepInAreas.size();
      size += 2 + sizeof(int64_t) * __KeepOutAreas.size();

      return size;
   }

   std::string OperatingRegion::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( OperatingRegion ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ID (int64_t) = " << __ID << "\n";
      oss << indent << "KeepInAreas (int64 [ " << __KeepInAreas.size() << ", var ])\n";
      oss << indent << "KeepOutAreas (int64 [ " << __KeepOutAreas.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string OperatingRegion::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<OperatingRegion Series=\"CMASI\">\n";
      str << ws << "   <ID>" << __ID << "</ID>\n";
      str << ws << "   <KeepInAreas>\n";
      for (size_t i=0; i<__KeepInAreas.size(); i++)
      {
         str << ws << "   <int64>" << __KeepInAreas[i] << "</int64>\n";
      }
      str << ws << "   </KeepInAreas>\n";
      str << ws << "   <KeepOutAreas>\n";
      for (size_t i=0; i<__KeepOutAreas.size(); i++)
      {
         str << ws << "   <int64>" << __KeepOutAreas[i] << "</int64>\n";
      }
      str << ws << "   </KeepOutAreas>\n";
      str << ws << "</OperatingRegion>\n";

      return str.str();
   }

   bool OperatingRegion::operator==(const OperatingRegion & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ID != that.__ID) return false;
      if(__KeepInAreas.size() != that.__KeepInAreas.size()) return false;
      for (size_t i=0; i<__KeepInAreas.size(); i++)
      {
         if(__KeepInAreas[i] != that.__KeepInAreas[i]) return false;
      }
      if(__KeepOutAreas.size() != that.__KeepOutAreas.size()) return false;
      for (size_t i=0; i<__KeepOutAreas.size(); i++)
      {
         if(__KeepOutAreas[i] != that.__KeepOutAreas[i]) return false;
      }
      return true;

   }

   bool OperatingRegion::operator!=(const OperatingRegion & that)
   {
      return( !(operator==(that)) );
   }

   OperatingRegion& OperatingRegion::setID(const int64_t val)
   {
      __ID = val;
      return *this;
   }




} // end namespace cmasi
} // end namespace afrl

