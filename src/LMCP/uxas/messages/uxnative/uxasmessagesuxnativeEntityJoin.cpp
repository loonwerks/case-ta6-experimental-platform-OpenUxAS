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
#include "uxas/messages/uxnative/EntityJoin.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EntityJoin::Subscription = "uxas.messages.uxnative.EntityJoin";
   const std::string EntityJoin::TypeName = "EntityJoin";
   const std::string EntityJoin::SeriesName = "UXNATIVE";
   const int64_t EntityJoin::SeriesId = 6149751333668345413LL;
   const uint16_t EntityJoin::SeriesVersion = 9;
   const uint32_t EntityJoin::TypeId = 14;
   
   bool isEntityJoin(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   bool isEntityJoin(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   std::vector< std::string > EntityJoinDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   EntityJoin::EntityJoin(void) : avtas::lmcp::Object()
   {
      __EntityID = 0LL;
      __Label = std::string("");

   }
     
   EntityJoin::EntityJoin(const EntityJoin &that) : avtas::lmcp::Object(that)
   {
        __EntityID = that.__EntityID;
        __Label = that.__Label;

   }
   
   EntityJoin & EntityJoin::operator=(const EntityJoin &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __EntityID = that.__EntityID;
         __Label = that.__Label;

      }
      return *this;
   }

   EntityJoin* EntityJoin::clone() const
   {
        return new EntityJoin(*this);
   }
   
   EntityJoin::~EntityJoin(void)
   {

   }
  
   void EntityJoin::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EntityID);
      buf.putString(__Label);

   }
   
   void EntityJoin::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getLong();
      __Label = buf.getString();

   }

   uint32_t EntityJoin::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __Label.length();

      return size;
   }

   std::string EntityJoin::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EntityJoin ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EntityJoin::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EntityJoin Series=\"UXNATIVE\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      str << ws << "</EntityJoin>\n";

      return str.str();
   }

   bool EntityJoin::operator==(const EntityJoin & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__Label != that.__Label) return false;
      return true;

   }

   bool EntityJoin::operator!=(const EntityJoin & that)
   {
      return( !(operator==(that)) );
   }

   EntityJoin& EntityJoin::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }

   EntityJoin& EntityJoin::setLabel(const std::string val)
   {
      __Label = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

