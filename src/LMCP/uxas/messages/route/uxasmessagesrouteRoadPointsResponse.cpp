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
#include "uxas/messages/route/RoadPointsResponse.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoadPointsResponse::Subscription = "uxas.messages.route.RoadPointsResponse";
   const std::string RoadPointsResponse::TypeName = "RoadPointsResponse";
   const std::string RoadPointsResponse::SeriesName = "ROUTE";
   const int64_t RoadPointsResponse::SeriesId = 5931053054693474304LL;
   const uint16_t RoadPointsResponse::SeriesVersion = 4;
   const uint32_t RoadPointsResponse::TypeId = 14;
   
   bool isRoadPointsResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   bool isRoadPointsResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   std::vector< std::string > RoadPointsResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoadPointsResponse::RoadPointsResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   RoadPointsResponse::RoadPointsResponse(const RoadPointsResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __RoadPointsResponses.clear();
        for (size_t i=0; i< that.__RoadPointsResponses.size(); i++)
        {
           __RoadPointsResponses.push_back( that.__RoadPointsResponses[i] == nullptr ? nullptr : that.__RoadPointsResponses[i]->clone());
        }

   }
   
   RoadPointsResponse & RoadPointsResponse::operator=(const RoadPointsResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__RoadPointsResponses.size(); i++)
         {
            if (__RoadPointsResponses[i] != nullptr) delete __RoadPointsResponses[i];
         }

         __ResponseID = that.__ResponseID;
         __RoadPointsResponses.clear();
         for (size_t i=0; i< that.__RoadPointsResponses.size(); i++)
         {
            __RoadPointsResponses.push_back( that.__RoadPointsResponses[i] == nullptr ? nullptr : that.__RoadPointsResponses[i]->clone());
         }

      }
      return *this;
   }

   RoadPointsResponse* RoadPointsResponse::clone() const
   {
        return new RoadPointsResponse(*this);
   }
   
   RoadPointsResponse::~RoadPointsResponse(void)
   {
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         if (__RoadPointsResponses[i] != nullptr) delete __RoadPointsResponses[i];
      }

   }
  
   void RoadPointsResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__RoadPointsResponses.size()));
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         assert(__RoadPointsResponses[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RoadPointsResponses[i], buf);
      }

   }
   
   void RoadPointsResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         if (__RoadPointsResponses[i] != nullptr)
            delete __RoadPointsResponses[i];
      }
      __RoadPointsResponses.clear();
      uint16_t __RoadPointsResponses_length = buf.getUShort();
      for (uint32_t i=0; i< __RoadPointsResponses_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::LineOfInterest* e = (afrl::impact::LineOfInterest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RoadPointsResponses.push_back(e);
         }
      }

   }

   uint32_t RoadPointsResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         if (__RoadPointsResponses[i] != nullptr)
         {
            size += __RoadPointsResponses[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RoadPointsResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoadPointsResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "RoadPointsResponses (LineOfInterest [ " << __RoadPointsResponses.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoadPointsResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoadPointsResponse Series=\"ROUTE\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <RoadPointsResponses>\n";
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         str << (__RoadPointsResponses[i] == nullptr ? ( ws + "   <null/>\n") : (__RoadPointsResponses[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RoadPointsResponses>\n";
      str << ws << "</RoadPointsResponse>\n";

      return str.str();
   }

   bool RoadPointsResponse::operator==(const RoadPointsResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__RoadPointsResponses.size() != that.__RoadPointsResponses.size()) return false;
      for (size_t i=0; i<__RoadPointsResponses.size(); i++)
      {
         if(__RoadPointsResponses[i] && that.__RoadPointsResponses[i])
         {
            if(__RoadPointsResponses[i]->getSeriesNameAsLong() != that.__RoadPointsResponses[i]->getSeriesNameAsLong()) return false;
            if(__RoadPointsResponses[i]->getSeriesVersion() != that.__RoadPointsResponses[i]->getSeriesVersion()) return false;
            if(__RoadPointsResponses[i]->getLmcpType() != that.__RoadPointsResponses[i]->getLmcpType()) return false;
            if( *(__RoadPointsResponses[i]) != *(that.__RoadPointsResponses[i]) ) return false;
         }
         else if(__RoadPointsResponses[i] != that.__RoadPointsResponses[i]) return false;
      }
      return true;

   }

   bool RoadPointsResponse::operator!=(const RoadPointsResponse & that)
   {
      return( !(operator==(that)) );
   }

   RoadPointsResponse& RoadPointsResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

