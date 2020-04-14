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
#include "afrl/cmasi/KeyValuePair.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string KeyValuePair::Subscription = "afrl.cmasi.KeyValuePair";
   const std::string KeyValuePair::TypeName = "KeyValuePair";
   const std::string KeyValuePair::SeriesName = "CMASI";
   const int64_t KeyValuePair::SeriesId = 4849604199710720000LL;
   const uint16_t KeyValuePair::SeriesVersion = 3;
   const uint32_t KeyValuePair::TypeId = 2;
   
   bool isKeyValuePair(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isKeyValuePair(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > KeyValuePairDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   KeyValuePair::KeyValuePair(void) : avtas::lmcp::Object()
   {
      __Key = std::string("");
      __Value = std::string("");

   }
     
   KeyValuePair::KeyValuePair(const KeyValuePair &that) : avtas::lmcp::Object(that)
   {
        __Key = that.__Key;
        __Value = that.__Value;

   }
   
   KeyValuePair & KeyValuePair::operator=(const KeyValuePair &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Key = that.__Key;
         __Value = that.__Value;

      }
      return *this;
   }

   KeyValuePair* KeyValuePair::clone() const
   {
        return new KeyValuePair(*this);
   }
   
   KeyValuePair::~KeyValuePair(void)
   {

   }
  
   void KeyValuePair::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putString(__Key);
      buf.putString(__Value);

   }
   
   void KeyValuePair::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Key = buf.getString();
      __Value = buf.getString();

   }

   uint32_t KeyValuePair::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + __Key.length();
      size += 2 + __Value.length();

      return size;
   }

   std::string KeyValuePair::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( KeyValuePair ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Key (std::string) = " << __Key << "\n";
      oss << indent << "Value (std::string) = " << __Value << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string KeyValuePair::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<KeyValuePair Series=\"CMASI\">\n";
      str << ws << "   <Key>" << __Key << "</Key>\n";
      str << ws << "   <Value>" << __Value << "</Value>\n";
      str << ws << "</KeyValuePair>\n";

      return str.str();
   }

   bool KeyValuePair::operator==(const KeyValuePair & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Key != that.__Key) return false;
      if(__Value != that.__Value) return false;
      return true;

   }

   bool KeyValuePair::operator!=(const KeyValuePair & that)
   {
      return( !(operator==(that)) );
   }

   KeyValuePair& KeyValuePair::setKey(const std::string val)
   {
      __Key = val;
      return *this;
   }

   KeyValuePair& KeyValuePair::setValue(const std::string val)
   {
      __Value = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

