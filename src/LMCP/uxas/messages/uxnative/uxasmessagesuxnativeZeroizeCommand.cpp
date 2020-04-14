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
#include "uxas/messages/uxnative/ZeroizeCommand.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ZeroizeCommand::Subscription = "uxas.messages.uxnative.ZeroizeCommand";
   const std::string ZeroizeCommand::TypeName = "ZeroizeCommand";
   const std::string ZeroizeCommand::SeriesName = "UXNATIVE";
   const int64_t ZeroizeCommand::SeriesId = 6149751333668345413LL;
   const uint16_t ZeroizeCommand::SeriesVersion = 9;
   const uint32_t ZeroizeCommand::TypeId = 18;
   
   bool isZeroizeCommand(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   bool isZeroizeCommand(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   std::vector< std::string > ZeroizeCommandDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ZeroizeCommand::ZeroizeCommand(void) : avtas::lmcp::Object()
   {
      __EntityID = 0LL;
      __ZeroizeKeys = false;
      __ZeroizeLogs = false;
      __ZeroizeData = false;
      __ZeroizeTasks = false;

   }
     
   ZeroizeCommand::ZeroizeCommand(const ZeroizeCommand &that) : avtas::lmcp::Object(that)
   {
        __EntityID = that.__EntityID;
        __ZeroizeKeys = that.__ZeroizeKeys;
        __ZeroizeLogs = that.__ZeroizeLogs;
        __ZeroizeData = that.__ZeroizeData;
        __ZeroizeTasks = that.__ZeroizeTasks;

   }
   
   ZeroizeCommand & ZeroizeCommand::operator=(const ZeroizeCommand &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __EntityID = that.__EntityID;
         __ZeroizeKeys = that.__ZeroizeKeys;
         __ZeroizeLogs = that.__ZeroizeLogs;
         __ZeroizeData = that.__ZeroizeData;
         __ZeroizeTasks = that.__ZeroizeTasks;

      }
      return *this;
   }

   ZeroizeCommand* ZeroizeCommand::clone() const
   {
        return new ZeroizeCommand(*this);
   }
   
   ZeroizeCommand::~ZeroizeCommand(void)
   {

   }
  
   void ZeroizeCommand::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EntityID);
      buf.putBool(__ZeroizeKeys);
      buf.putBool(__ZeroizeLogs);
      buf.putBool(__ZeroizeData);
      buf.putBool(__ZeroizeTasks);

   }
   
   void ZeroizeCommand::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getLong();
      __ZeroizeKeys = buf.getBool();
      __ZeroizeLogs = buf.getBool();
      __ZeroizeData = buf.getBool();
      __ZeroizeTasks = buf.getBool();

   }

   uint32_t ZeroizeCommand::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(bool);

      return size;
   }

   std::string ZeroizeCommand::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ZeroizeCommand ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "ZeroizeKeys (bool) = " << __ZeroizeKeys << "\n";
      oss << indent << "ZeroizeLogs (bool) = " << __ZeroizeLogs << "\n";
      oss << indent << "ZeroizeData (bool) = " << __ZeroizeData << "\n";
      oss << indent << "ZeroizeTasks (bool) = " << __ZeroizeTasks << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ZeroizeCommand::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ZeroizeCommand Series=\"UXNATIVE\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <ZeroizeKeys>" << (__ZeroizeKeys ? "true" : "false") << "</ZeroizeKeys>\n";
      str << ws << "   <ZeroizeLogs>" << (__ZeroizeLogs ? "true" : "false") << "</ZeroizeLogs>\n";
      str << ws << "   <ZeroizeData>" << (__ZeroizeData ? "true" : "false") << "</ZeroizeData>\n";
      str << ws << "   <ZeroizeTasks>" << (__ZeroizeTasks ? "true" : "false") << "</ZeroizeTasks>\n";
      str << ws << "</ZeroizeCommand>\n";

      return str.str();
   }

   bool ZeroizeCommand::operator==(const ZeroizeCommand & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__ZeroizeKeys != that.__ZeroizeKeys) return false;
      if(__ZeroizeLogs != that.__ZeroizeLogs) return false;
      if(__ZeroizeData != that.__ZeroizeData) return false;
      if(__ZeroizeTasks != that.__ZeroizeTasks) return false;
      return true;

   }

   bool ZeroizeCommand::operator!=(const ZeroizeCommand & that)
   {
      return( !(operator==(that)) );
   }

   ZeroizeCommand& ZeroizeCommand::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }

   ZeroizeCommand& ZeroizeCommand::setZeroizeKeys(const bool val)
   {
      __ZeroizeKeys = val;
      return *this;
   }

   ZeroizeCommand& ZeroizeCommand::setZeroizeLogs(const bool val)
   {
      __ZeroizeLogs = val;
      return *this;
   }

   ZeroizeCommand& ZeroizeCommand::setZeroizeData(const bool val)
   {
      __ZeroizeData = val;
      return *this;
   }

   ZeroizeCommand& ZeroizeCommand::setZeroizeTasks(const bool val)
   {
      __ZeroizeTasks = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

