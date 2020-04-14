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
#include "uxas/messages/route/RoadPointsRequest.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoadPointsRequest::Subscription = "uxas.messages.route.RoadPointsRequest";
   const std::string RoadPointsRequest::TypeName = "RoadPointsRequest";
   const std::string RoadPointsRequest::SeriesName = "ROUTE";
   const int64_t RoadPointsRequest::SeriesId = 5931053054693474304LL;
   const uint16_t RoadPointsRequest::SeriesVersion = 4;
   const uint32_t RoadPointsRequest::TypeId = 13;
   
   bool isRoadPointsRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   bool isRoadPointsRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   std::vector< std::string > RoadPointsRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoadPointsRequest::RoadPointsRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;

   }
     
   RoadPointsRequest::RoadPointsRequest(const RoadPointsRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __RoadPointsRequests.clear();
        for (size_t i=0; i< that.__RoadPointsRequests.size(); i++)
        {
           __RoadPointsRequests.push_back( that.__RoadPointsRequests[i] == nullptr ? nullptr : that.__RoadPointsRequests[i]->clone());
        }

   }
   
   RoadPointsRequest & RoadPointsRequest::operator=(const RoadPointsRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__RoadPointsRequests.size(); i++)
         {
            if (__RoadPointsRequests[i] != nullptr) delete __RoadPointsRequests[i];
         }

         __RequestID = that.__RequestID;
         __RoadPointsRequests.clear();
         for (size_t i=0; i< that.__RoadPointsRequests.size(); i++)
         {
            __RoadPointsRequests.push_back( that.__RoadPointsRequests[i] == nullptr ? nullptr : that.__RoadPointsRequests[i]->clone());
         }

      }
      return *this;
   }

   RoadPointsRequest* RoadPointsRequest::clone() const
   {
        return new RoadPointsRequest(*this);
   }
   
   RoadPointsRequest::~RoadPointsRequest(void)
   {
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         if (__RoadPointsRequests[i] != nullptr) delete __RoadPointsRequests[i];
      }

   }
  
   void RoadPointsRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putUShort( static_cast<uint16_t>(__RoadPointsRequests.size()));
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         assert(__RoadPointsRequests[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RoadPointsRequests[i], buf);
      }

   }
   
   void RoadPointsRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         if (__RoadPointsRequests[i] != nullptr)
            delete __RoadPointsRequests[i];
      }
      __RoadPointsRequests.clear();
      uint16_t __RoadPointsRequests_length = buf.getUShort();
      for (uint32_t i=0; i< __RoadPointsRequests_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::RoadPointsConstraints* e = (uxas::messages::route::RoadPointsConstraints*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RoadPointsRequests.push_back(e);
         }
      }

   }

   uint32_t RoadPointsRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         if (__RoadPointsRequests[i] != nullptr)
         {
            size += __RoadPointsRequests[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RoadPointsRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoadPointsRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "RoadPointsRequests (RoadPointsConstraints [ " << __RoadPointsRequests.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoadPointsRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoadPointsRequest Series=\"ROUTE\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <RoadPointsRequests>\n";
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         str << (__RoadPointsRequests[i] == nullptr ? ( ws + "   <null/>\n") : (__RoadPointsRequests[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RoadPointsRequests>\n";
      str << ws << "</RoadPointsRequest>\n";

      return str.str();
   }

   bool RoadPointsRequest::operator==(const RoadPointsRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__RoadPointsRequests.size() != that.__RoadPointsRequests.size()) return false;
      for (size_t i=0; i<__RoadPointsRequests.size(); i++)
      {
         if(__RoadPointsRequests[i] && that.__RoadPointsRequests[i])
         {
            if(__RoadPointsRequests[i]->getSeriesNameAsLong() != that.__RoadPointsRequests[i]->getSeriesNameAsLong()) return false;
            if(__RoadPointsRequests[i]->getSeriesVersion() != that.__RoadPointsRequests[i]->getSeriesVersion()) return false;
            if(__RoadPointsRequests[i]->getLmcpType() != that.__RoadPointsRequests[i]->getLmcpType()) return false;
            if( *(__RoadPointsRequests[i]) != *(that.__RoadPointsRequests[i]) ) return false;
         }
         else if(__RoadPointsRequests[i] != that.__RoadPointsRequests[i]) return false;
      }
      return true;

   }

   bool RoadPointsRequest::operator!=(const RoadPointsRequest & that)
   {
      return( !(operator==(that)) );
   }

   RoadPointsRequest& RoadPointsRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

