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
#include "uxas/messages/uxnative/EntityLocation.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EntityLocation::Subscription = "uxas.messages.uxnative.EntityLocation";
   const std::string EntityLocation::TypeName = "EntityLocation";
   const std::string EntityLocation::SeriesName = "UXNATIVE";
   const int64_t EntityLocation::SeriesId = 6149751333668345413LL;
   const uint16_t EntityLocation::SeriesVersion = 9;
   const uint32_t EntityLocation::TypeId = 7;
   
   bool isEntityLocation(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   bool isEntityLocation(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   std::vector< std::string > EntityLocationDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("uxas.messages.uxnative.BandwidthTest");

       return descendants;
   }
   
   EntityLocation::EntityLocation(void) : avtas::lmcp::Object()
   {
      __EntityID = 0LL;
      __Position = new afrl::cmasi::Location3D();
      __Time = 0LL;

   }
     
   EntityLocation::EntityLocation(const EntityLocation &that) : avtas::lmcp::Object(that)
   {
        __EntityID = that.__EntityID;
        __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
        __Time = that.__Time;

   }
   
   EntityLocation & EntityLocation::operator=(const EntityLocation &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Position != nullptr) delete __Position;

         __EntityID = that.__EntityID;
         __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
         __Time = that.__Time;

      }
      return *this;
   }

   EntityLocation* EntityLocation::clone() const
   {
        return new EntityLocation(*this);
   }
   
   EntityLocation::~EntityLocation(void)
   {
      if (__Position != nullptr) delete __Position;

   }
  
   void EntityLocation::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EntityID);
      assert(__Position != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Position, buf);
      buf.putLong(__Time);

   }
   
   void EntityLocation::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getLong();
      {
         if (__Position != nullptr) delete __Position;
         __Position = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Position = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Position != nullptr) __Position->unpack(buf);
            else assert(__Position != nullptr);
         }
      }
      __Time = buf.getLong();

   }

   uint32_t EntityLocation::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__Position != nullptr ? __Position->calculatePackedSize() + 15 : 1);
      size += sizeof(int64_t);

      return size;
   }

   std::string EntityLocation::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EntityLocation ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "Position (Location3D)";
      if (__Position == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Time (int64_t) = " << __Time << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EntityLocation::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EntityLocation Series=\"UXNATIVE\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      if (__Position != nullptr)
      {
         str << ws << "   <Position>";
         str << "\n" + __Position->toXML(depth + 1) + ws + "   ";
         str << "</Position>\n";
      }
      str << ws << "   <Time>" << __Time << "</Time>\n";
      str << ws << "</EntityLocation>\n";

      return str.str();
   }

   bool EntityLocation::operator==(const EntityLocation & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__Position && that.__Position)
      {
         if(__Position->getSeriesNameAsLong() != that.__Position->getSeriesNameAsLong()) return false;
         if(__Position->getSeriesVersion() != that.__Position->getSeriesVersion()) return false;
         if(__Position->getLmcpType() != that.__Position->getLmcpType()) return false;
         if( *(__Position) != *(that.__Position) ) return false;
      }
      else if(__Position != that.__Position) return false;
      if(__Time != that.__Time) return false;
      return true;

   }

   bool EntityLocation::operator!=(const EntityLocation & that)
   {
      return( !(operator==(that)) );
   }

   EntityLocation& EntityLocation::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }

   EntityLocation& EntityLocation::setPosition(const afrl::cmasi::Location3D* const val)
   {
      if (__Position != nullptr) { delete __Position; __Position = nullptr; }
      if (val != nullptr) { __Position = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   EntityLocation& EntityLocation::setTime(const int64_t val)
   {
      __Time = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

