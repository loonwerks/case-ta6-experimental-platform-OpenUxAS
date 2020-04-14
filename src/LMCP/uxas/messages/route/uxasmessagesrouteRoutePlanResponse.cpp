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
#include "uxas/messages/route/RoutePlanResponse.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoutePlanResponse::Subscription = "uxas.messages.route.RoutePlanResponse";
   const std::string RoutePlanResponse::TypeName = "RoutePlanResponse";
   const std::string RoutePlanResponse::SeriesName = "ROUTE";
   const int64_t RoutePlanResponse::SeriesId = 5931053054693474304LL;
   const uint16_t RoutePlanResponse::SeriesVersion = 4;
   const uint32_t RoutePlanResponse::TypeId = 8;
   
   bool isRoutePlanResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   bool isRoutePlanResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   std::vector< std::string > RoutePlanResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoutePlanResponse::RoutePlanResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;
      __AssociatedTaskID = 0LL;
      __VehicleID = 0LL;
      __OperatingRegion = 0LL;

   }
     
   RoutePlanResponse::RoutePlanResponse(const RoutePlanResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __AssociatedTaskID = that.__AssociatedTaskID;
        __VehicleID = that.__VehicleID;
        __OperatingRegion = that.__OperatingRegion;
        __RouteResponses.clear();
        for (size_t i=0; i< that.__RouteResponses.size(); i++)
        {
           __RouteResponses.push_back( that.__RouteResponses[i] == nullptr ? nullptr : that.__RouteResponses[i]->clone());
        }

   }
   
   RoutePlanResponse & RoutePlanResponse::operator=(const RoutePlanResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__RouteResponses.size(); i++)
         {
            if (__RouteResponses[i] != nullptr) delete __RouteResponses[i];
         }

         __ResponseID = that.__ResponseID;
         __AssociatedTaskID = that.__AssociatedTaskID;
         __VehicleID = that.__VehicleID;
         __OperatingRegion = that.__OperatingRegion;
         __RouteResponses.clear();
         for (size_t i=0; i< that.__RouteResponses.size(); i++)
         {
            __RouteResponses.push_back( that.__RouteResponses[i] == nullptr ? nullptr : that.__RouteResponses[i]->clone());
         }

      }
      return *this;
   }

   RoutePlanResponse* RoutePlanResponse::clone() const
   {
        return new RoutePlanResponse(*this);
   }
   
   RoutePlanResponse::~RoutePlanResponse(void)
   {
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         if (__RouteResponses[i] != nullptr) delete __RouteResponses[i];
      }

   }
  
   void RoutePlanResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putLong(__AssociatedTaskID);
      buf.putLong(__VehicleID);
      buf.putLong(__OperatingRegion);
      buf.putUShort( static_cast<uint16_t>(__RouteResponses.size()));
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         assert(__RouteResponses[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RouteResponses[i], buf);
      }

   }
   
   void RoutePlanResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      __AssociatedTaskID = buf.getLong();
      __VehicleID = buf.getLong();
      __OperatingRegion = buf.getLong();
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         if (__RouteResponses[i] != nullptr)
            delete __RouteResponses[i];
      }
      __RouteResponses.clear();
      uint16_t __RouteResponses_length = buf.getUShort();
      for (uint32_t i=0; i< __RouteResponses_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::RoutePlan* e = (uxas::messages::route::RoutePlan*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RouteResponses.push_back(e);
         }
      }

   }

   uint32_t RoutePlanResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         if (__RouteResponses[i] != nullptr)
         {
            size += __RouteResponses[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RoutePlanResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoutePlanResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "AssociatedTaskID (int64_t) = " << __AssociatedTaskID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "RouteResponses (RoutePlan [ " << __RouteResponses.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoutePlanResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoutePlanResponse Series=\"ROUTE\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <AssociatedTaskID>" << __AssociatedTaskID << "</AssociatedTaskID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <RouteResponses>\n";
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         str << (__RouteResponses[i] == nullptr ? ( ws + "   <null/>\n") : (__RouteResponses[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RouteResponses>\n";
      str << ws << "</RoutePlanResponse>\n";

      return str.str();
   }

   bool RoutePlanResponse::operator==(const RoutePlanResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__AssociatedTaskID != that.__AssociatedTaskID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__RouteResponses.size() != that.__RouteResponses.size()) return false;
      for (size_t i=0; i<__RouteResponses.size(); i++)
      {
         if(__RouteResponses[i] && that.__RouteResponses[i])
         {
            if(__RouteResponses[i]->getSeriesNameAsLong() != that.__RouteResponses[i]->getSeriesNameAsLong()) return false;
            if(__RouteResponses[i]->getSeriesVersion() != that.__RouteResponses[i]->getSeriesVersion()) return false;
            if(__RouteResponses[i]->getLmcpType() != that.__RouteResponses[i]->getLmcpType()) return false;
            if( *(__RouteResponses[i]) != *(that.__RouteResponses[i]) ) return false;
         }
         else if(__RouteResponses[i] != that.__RouteResponses[i]) return false;
      }
      return true;

   }

   bool RoutePlanResponse::operator!=(const RoutePlanResponse & that)
   {
      return( !(operator==(that)) );
   }

   RoutePlanResponse& RoutePlanResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }

   RoutePlanResponse& RoutePlanResponse::setAssociatedTaskID(const int64_t val)
   {
      __AssociatedTaskID = val;
      return *this;
   }

   RoutePlanResponse& RoutePlanResponse::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   RoutePlanResponse& RoutePlanResponse::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

