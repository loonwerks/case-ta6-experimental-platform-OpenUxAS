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
#include "uxas/messages/route/RouteResponse.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RouteResponse::Subscription = "uxas.messages.route.RouteResponse";
   const std::string RouteResponse::TypeName = "RouteResponse";
   const std::string RouteResponse::SeriesName = "ROUTE";
   const int64_t RouteResponse::SeriesId = 5931053054693474304LL;
   const uint16_t RouteResponse::SeriesVersion = 4;
   const uint32_t RouteResponse::TypeId = 9;
   
   bool isRouteResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   bool isRouteResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   std::vector< std::string > RouteResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RouteResponse::RouteResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   RouteResponse::RouteResponse(const RouteResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __Routes.clear();
        for (size_t i=0; i< that.__Routes.size(); i++)
        {
           __Routes.push_back( that.__Routes[i] == nullptr ? nullptr : that.__Routes[i]->clone());
        }

   }
   
   RouteResponse & RouteResponse::operator=(const RouteResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Routes.size(); i++)
         {
            if (__Routes[i] != nullptr) delete __Routes[i];
         }

         __ResponseID = that.__ResponseID;
         __Routes.clear();
         for (size_t i=0; i< that.__Routes.size(); i++)
         {
            __Routes.push_back( that.__Routes[i] == nullptr ? nullptr : that.__Routes[i]->clone());
         }

      }
      return *this;
   }

   RouteResponse* RouteResponse::clone() const
   {
        return new RouteResponse(*this);
   }
   
   RouteResponse::~RouteResponse(void)
   {
      for (size_t i=0; i<__Routes.size(); i++)
      {
         if (__Routes[i] != nullptr) delete __Routes[i];
      }

   }
  
   void RouteResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__Routes.size()));
      for (size_t i=0; i<__Routes.size(); i++)
      {
         assert(__Routes[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Routes[i], buf);
      }

   }
   
   void RouteResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      for (size_t i=0; i<__Routes.size(); i++)
      {
         if (__Routes[i] != nullptr)
            delete __Routes[i];
      }
      __Routes.clear();
      uint16_t __Routes_length = buf.getUShort();
      for (uint32_t i=0; i< __Routes_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::RoutePlanResponse* e = (uxas::messages::route::RoutePlanResponse*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Routes.push_back(e);
         }
      }

   }

   uint32_t RouteResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Routes.size(); i++)
      {
         if (__Routes[i] != nullptr)
         {
            size += __Routes[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RouteResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RouteResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "Routes (RoutePlanResponse [ " << __Routes.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RouteResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RouteResponse Series=\"ROUTE\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <Routes>\n";
      for (size_t i=0; i<__Routes.size(); i++)
      {
         str << (__Routes[i] == nullptr ? ( ws + "   <null/>\n") : (__Routes[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Routes>\n";
      str << ws << "</RouteResponse>\n";

      return str.str();
   }

   bool RouteResponse::operator==(const RouteResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__Routes.size() != that.__Routes.size()) return false;
      for (size_t i=0; i<__Routes.size(); i++)
      {
         if(__Routes[i] && that.__Routes[i])
         {
            if(__Routes[i]->getSeriesNameAsLong() != that.__Routes[i]->getSeriesNameAsLong()) return false;
            if(__Routes[i]->getSeriesVersion() != that.__Routes[i]->getSeriesVersion()) return false;
            if(__Routes[i]->getLmcpType() != that.__Routes[i]->getLmcpType()) return false;
            if( *(__Routes[i]) != *(that.__Routes[i]) ) return false;
         }
         else if(__Routes[i] != that.__Routes[i]) return false;
      }
      return true;

   }

   bool RouteResponse::operator!=(const RouteResponse & that)
   {
      return( !(operator==(that)) );
   }

   RouteResponse& RouteResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

