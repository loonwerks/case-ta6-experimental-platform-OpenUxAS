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
#include "uxas/messages/route/RoutePlanRequest.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoutePlanRequest::Subscription = "uxas.messages.route.RoutePlanRequest";
   const std::string RoutePlanRequest::TypeName = "RoutePlanRequest";
   const std::string RoutePlanRequest::SeriesName = "ROUTE";
   const int64_t RoutePlanRequest::SeriesId = 5931053054693474304LL;
   const uint16_t RoutePlanRequest::SeriesVersion = 4;
   const uint32_t RoutePlanRequest::TypeId = 6;
   
   bool isRoutePlanRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   bool isRoutePlanRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   std::vector< std::string > RoutePlanRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoutePlanRequest::RoutePlanRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __AssociatedTaskID = 0LL;
      __VehicleID = 0LL;
      __OperatingRegion = 0LL;
      __IsCostOnlyRequest = true;

   }
     
   RoutePlanRequest::RoutePlanRequest(const RoutePlanRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __AssociatedTaskID = that.__AssociatedTaskID;
        __VehicleID = that.__VehicleID;
        __OperatingRegion = that.__OperatingRegion;
        __RouteRequests.clear();
        for (size_t i=0; i< that.__RouteRequests.size(); i++)
        {
           __RouteRequests.push_back( that.__RouteRequests[i] == nullptr ? nullptr : that.__RouteRequests[i]->clone());
        }
        __IsCostOnlyRequest = that.__IsCostOnlyRequest;

   }
   
   RoutePlanRequest & RoutePlanRequest::operator=(const RoutePlanRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__RouteRequests.size(); i++)
         {
            if (__RouteRequests[i] != nullptr) delete __RouteRequests[i];
         }

         __RequestID = that.__RequestID;
         __AssociatedTaskID = that.__AssociatedTaskID;
         __VehicleID = that.__VehicleID;
         __OperatingRegion = that.__OperatingRegion;
         __RouteRequests.clear();
         for (size_t i=0; i< that.__RouteRequests.size(); i++)
         {
            __RouteRequests.push_back( that.__RouteRequests[i] == nullptr ? nullptr : that.__RouteRequests[i]->clone());
         }
         __IsCostOnlyRequest = that.__IsCostOnlyRequest;

      }
      return *this;
   }

   RoutePlanRequest* RoutePlanRequest::clone() const
   {
        return new RoutePlanRequest(*this);
   }
   
   RoutePlanRequest::~RoutePlanRequest(void)
   {
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         if (__RouteRequests[i] != nullptr) delete __RouteRequests[i];
      }

   }
  
   void RoutePlanRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putLong(__AssociatedTaskID);
      buf.putLong(__VehicleID);
      buf.putLong(__OperatingRegion);
      buf.putUShort( static_cast<uint16_t>(__RouteRequests.size()));
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         assert(__RouteRequests[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RouteRequests[i], buf);
      }
      buf.putBool(__IsCostOnlyRequest);

   }
   
   void RoutePlanRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      __AssociatedTaskID = buf.getLong();
      __VehicleID = buf.getLong();
      __OperatingRegion = buf.getLong();
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         if (__RouteRequests[i] != nullptr)
            delete __RouteRequests[i];
      }
      __RouteRequests.clear();
      uint16_t __RouteRequests_length = buf.getUShort();
      for (uint32_t i=0; i< __RouteRequests_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::RouteConstraints* e = (uxas::messages::route::RouteConstraints*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RouteRequests.push_back(e);
         }
      }
      __IsCostOnlyRequest = buf.getBool();

   }

   uint32_t RoutePlanRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         if (__RouteRequests[i] != nullptr)
         {
            size += __RouteRequests[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(bool);

      return size;
   }

   std::string RoutePlanRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoutePlanRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "AssociatedTaskID (int64_t) = " << __AssociatedTaskID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "RouteRequests (RouteConstraints [ " << __RouteRequests.size() << ", var ])\n";
      oss << indent << "IsCostOnlyRequest (bool) = " << __IsCostOnlyRequest << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoutePlanRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoutePlanRequest Series=\"ROUTE\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <AssociatedTaskID>" << __AssociatedTaskID << "</AssociatedTaskID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <RouteRequests>\n";
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         str << (__RouteRequests[i] == nullptr ? ( ws + "   <null/>\n") : (__RouteRequests[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RouteRequests>\n";
      str << ws << "   <IsCostOnlyRequest>" << (__IsCostOnlyRequest ? "true" : "false") << "</IsCostOnlyRequest>\n";
      str << ws << "</RoutePlanRequest>\n";

      return str.str();
   }

   bool RoutePlanRequest::operator==(const RoutePlanRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__AssociatedTaskID != that.__AssociatedTaskID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__RouteRequests.size() != that.__RouteRequests.size()) return false;
      for (size_t i=0; i<__RouteRequests.size(); i++)
      {
         if(__RouteRequests[i] && that.__RouteRequests[i])
         {
            if(__RouteRequests[i]->getSeriesNameAsLong() != that.__RouteRequests[i]->getSeriesNameAsLong()) return false;
            if(__RouteRequests[i]->getSeriesVersion() != that.__RouteRequests[i]->getSeriesVersion()) return false;
            if(__RouteRequests[i]->getLmcpType() != that.__RouteRequests[i]->getLmcpType()) return false;
            if( *(__RouteRequests[i]) != *(that.__RouteRequests[i]) ) return false;
         }
         else if(__RouteRequests[i] != that.__RouteRequests[i]) return false;
      }
      if(__IsCostOnlyRequest != that.__IsCostOnlyRequest) return false;
      return true;

   }

   bool RoutePlanRequest::operator!=(const RoutePlanRequest & that)
   {
      return( !(operator==(that)) );
   }

   RoutePlanRequest& RoutePlanRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   RoutePlanRequest& RoutePlanRequest::setAssociatedTaskID(const int64_t val)
   {
      __AssociatedTaskID = val;
      return *this;
   }

   RoutePlanRequest& RoutePlanRequest::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   RoutePlanRequest& RoutePlanRequest::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }


   RoutePlanRequest& RoutePlanRequest::setIsCostOnlyRequest(const bool val)
   {
      __IsCostOnlyRequest = val;
      return *this;
   }


} // end namespace route
} // end namespace messages
} // end namespace uxas

