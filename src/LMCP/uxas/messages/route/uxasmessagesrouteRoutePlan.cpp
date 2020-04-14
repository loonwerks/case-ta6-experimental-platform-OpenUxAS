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
#include "uxas/messages/route/RoutePlan.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoutePlan::Subscription = "uxas.messages.route.RoutePlan";
   const std::string RoutePlan::TypeName = "RoutePlan";
   const std::string RoutePlan::SeriesName = "ROUTE";
   const int64_t RoutePlan::SeriesId = 5931053054693474304LL;
   const uint16_t RoutePlan::SeriesVersion = 4;
   const uint32_t RoutePlan::TypeId = 7;
   
   bool isRoutePlan(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   bool isRoutePlan(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   std::vector< std::string > RoutePlanDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoutePlan::RoutePlan(void) : avtas::lmcp::Object()
   {
      __RouteID = 0LL;
      __RouteCost = -1LL;

   }
     
   RoutePlan::RoutePlan(const RoutePlan &that) : avtas::lmcp::Object(that)
   {
        __RouteID = that.__RouteID;
        __Waypoints.clear();
        for (size_t i=0; i< that.__Waypoints.size(); i++)
        {
           __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
        }
        __RouteCost = that.__RouteCost;
        __RouteError.clear();
        for (size_t i=0; i< that.__RouteError.size(); i++)
        {
           __RouteError.push_back( that.__RouteError[i] == nullptr ? nullptr : that.__RouteError[i]->clone());
        }

   }
   
   RoutePlan & RoutePlan::operator=(const RoutePlan &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Waypoints.size(); i++)
         {
            if (__Waypoints[i] != nullptr) delete __Waypoints[i];
         }
         for (size_t i=0; i<__RouteError.size(); i++)
         {
            if (__RouteError[i] != nullptr) delete __RouteError[i];
         }

         __RouteID = that.__RouteID;
         __Waypoints.clear();
         for (size_t i=0; i< that.__Waypoints.size(); i++)
         {
            __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
         }
         __RouteCost = that.__RouteCost;
         __RouteError.clear();
         for (size_t i=0; i< that.__RouteError.size(); i++)
         {
            __RouteError.push_back( that.__RouteError[i] == nullptr ? nullptr : that.__RouteError[i]->clone());
         }

      }
      return *this;
   }

   RoutePlan* RoutePlan::clone() const
   {
        return new RoutePlan(*this);
   }
   
   RoutePlan::~RoutePlan(void)
   {
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr) delete __Waypoints[i];
      }
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         if (__RouteError[i] != nullptr) delete __RouteError[i];
      }

   }
  
   void RoutePlan::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RouteID);
      buf.putUShort( static_cast<uint16_t>(__Waypoints.size()));
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         assert(__Waypoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Waypoints[i], buf);
      }
      buf.putLong(__RouteCost);
      buf.putUShort( static_cast<uint16_t>(__RouteError.size()));
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         assert(__RouteError[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RouteError[i], buf);
      }

   }
   
   void RoutePlan::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RouteID = buf.getLong();
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr)
            delete __Waypoints[i];
      }
      __Waypoints.clear();
      uint16_t __Waypoints_length = buf.getUShort();
      for (uint32_t i=0; i< __Waypoints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Waypoints.push_back(e);
         }
      }
      __RouteCost = buf.getLong();
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         if (__RouteError[i] != nullptr)
            delete __RouteError[i];
      }
      __RouteError.clear();
      uint16_t __RouteError_length = buf.getUShort();
      for (uint32_t i=0; i< __RouteError_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RouteError.push_back(e);
         }
      }

   }

   uint32_t RoutePlan::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr)
         {
            size += __Waypoints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         if (__RouteError[i] != nullptr)
         {
            size += __RouteError[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RoutePlan::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoutePlan ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RouteID (int64_t) = " << __RouteID << "\n";
      oss << indent << "Waypoints (Waypoint [ " << __Waypoints.size() << ", var ])\n";
      oss << indent << "RouteCost (int64_t) = " << __RouteCost << "\n";
      oss << indent << "RouteError (KeyValuePair [ " << __RouteError.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoutePlan::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoutePlan Series=\"ROUTE\">\n";
      str << ws << "   <RouteID>" << __RouteID << "</RouteID>\n";
      str << ws << "   <Waypoints>\n";
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         str << (__Waypoints[i] == nullptr ? ( ws + "   <null/>\n") : (__Waypoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Waypoints>\n";
      str << ws << "   <RouteCost>" << __RouteCost << "</RouteCost>\n";
      str << ws << "   <RouteError>\n";
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         str << (__RouteError[i] == nullptr ? ( ws + "   <null/>\n") : (__RouteError[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RouteError>\n";
      str << ws << "</RoutePlan>\n";

      return str.str();
   }

   bool RoutePlan::operator==(const RoutePlan & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RouteID != that.__RouteID) return false;
      if(__Waypoints.size() != that.__Waypoints.size()) return false;
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if(__Waypoints[i] && that.__Waypoints[i])
         {
            if(__Waypoints[i]->getSeriesNameAsLong() != that.__Waypoints[i]->getSeriesNameAsLong()) return false;
            if(__Waypoints[i]->getSeriesVersion() != that.__Waypoints[i]->getSeriesVersion()) return false;
            if(__Waypoints[i]->getLmcpType() != that.__Waypoints[i]->getLmcpType()) return false;
            if( *(__Waypoints[i]) != *(that.__Waypoints[i]) ) return false;
         }
         else if(__Waypoints[i] != that.__Waypoints[i]) return false;
      }
      if(__RouteCost != that.__RouteCost) return false;
      if(__RouteError.size() != that.__RouteError.size()) return false;
      for (size_t i=0; i<__RouteError.size(); i++)
      {
         if(__RouteError[i] && that.__RouteError[i])
         {
            if(__RouteError[i]->getSeriesNameAsLong() != that.__RouteError[i]->getSeriesNameAsLong()) return false;
            if(__RouteError[i]->getSeriesVersion() != that.__RouteError[i]->getSeriesVersion()) return false;
            if(__RouteError[i]->getLmcpType() != that.__RouteError[i]->getLmcpType()) return false;
            if( *(__RouteError[i]) != *(that.__RouteError[i]) ) return false;
         }
         else if(__RouteError[i] != that.__RouteError[i]) return false;
      }
      return true;

   }

   bool RoutePlan::operator!=(const RoutePlan & that)
   {
      return( !(operator==(that)) );
   }

   RoutePlan& RoutePlan::setRouteID(const int64_t val)
   {
      __RouteID = val;
      return *this;
   }


   RoutePlan& RoutePlan::setRouteCost(const int64_t val)
   {
      __RouteCost = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

