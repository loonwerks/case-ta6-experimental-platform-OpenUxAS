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
#include "afrl/cmasi/RemoveEntities.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RemoveEntities::Subscription = "afrl.cmasi.RemoveEntities";
   const std::string RemoveEntities::TypeName = "RemoveEntities";
   const std::string RemoveEntities::SeriesName = "CMASI";
   const int64_t RemoveEntities::SeriesId = 4849604199710720000LL;
   const uint16_t RemoveEntities::SeriesVersion = 3;
   const uint32_t RemoveEntities::TypeId = 53;
   
   bool isRemoveEntities(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 53) return false;
      return true;
   }
   
   bool isRemoveEntities(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 53) return false;
      return true;
   }
   
   std::vector< std::string > RemoveEntitiesDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RemoveEntities::RemoveEntities(void) : avtas::lmcp::Object()
   {

   }
     
   RemoveEntities::RemoveEntities(const RemoveEntities &that) : avtas::lmcp::Object(that)
   {
        __EntityList.clear();
        for (size_t i=0; i< that.__EntityList.size(); i++)
        {
           __EntityList.push_back( that.__EntityList[i]);
        }

   }
   
   RemoveEntities & RemoveEntities::operator=(const RemoveEntities &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __EntityList.clear();
         for (size_t i=0; i< that.__EntityList.size(); i++)
         {
            __EntityList.push_back( that.__EntityList[i]);
         }

      }
      return *this;
   }

   RemoveEntities* RemoveEntities::clone() const
   {
        return new RemoveEntities(*this);
   }
   
   RemoveEntities::~RemoveEntities(void)
   {

   }
  
   void RemoveEntities::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__EntityList.size()));
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         buf.putLong(__EntityList[i]);
      }

   }
   
   void RemoveEntities::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityList.clear();
      uint16_t __EntityList_length = buf.getUShort();
      for (uint32_t i=0; i< __EntityList_length; i++)
      {
         __EntityList.push_back(buf.getLong() );
      }

   }

   uint32_t RemoveEntities::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __EntityList.size();

      return size;
   }

   std::string RemoveEntities::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RemoveEntities ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityList (int64 [ " << __EntityList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RemoveEntities::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RemoveEntities Series=\"CMASI\">\n";
      str << ws << "   <EntityList>\n";
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         str << ws << "   <int64>" << __EntityList[i] << "</int64>\n";
      }
      str << ws << "   </EntityList>\n";
      str << ws << "</RemoveEntities>\n";

      return str.str();
   }

   bool RemoveEntities::operator==(const RemoveEntities & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityList.size() != that.__EntityList.size()) return false;
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         if(__EntityList[i] != that.__EntityList[i]) return false;
      }
      return true;

   }

   bool RemoveEntities::operator!=(const RemoveEntities & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

