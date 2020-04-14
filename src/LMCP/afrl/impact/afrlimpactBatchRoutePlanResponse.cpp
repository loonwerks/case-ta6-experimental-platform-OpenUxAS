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
#include "afrl/impact/BatchRoutePlanResponse.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BatchRoutePlanResponse::Subscription = "afrl.impact.BatchRoutePlanResponse";
   const std::string BatchRoutePlanResponse::TypeName = "BatchRoutePlanResponse";
   const std::string BatchRoutePlanResponse::SeriesName = "IMPACT";
   const int64_t BatchRoutePlanResponse::SeriesId = 5281966179208134656LL;
   const uint16_t BatchRoutePlanResponse::SeriesVersion = 14;
   const uint32_t BatchRoutePlanResponse::TypeId = 10;
   
   bool isBatchRoutePlanResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   bool isBatchRoutePlanResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   std::vector< std::string > BatchRoutePlanResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BatchRoutePlanResponse::BatchRoutePlanResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   BatchRoutePlanResponse::BatchRoutePlanResponse(const BatchRoutePlanResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __VehicleTiming.clear();
        for (size_t i=0; i< that.__VehicleTiming.size(); i++)
        {
           __VehicleTiming.push_back( that.__VehicleTiming[i] == nullptr ? nullptr : that.__VehicleTiming[i]->clone());
        }

   }
   
   BatchRoutePlanResponse & BatchRoutePlanResponse::operator=(const BatchRoutePlanResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__VehicleTiming.size(); i++)
         {
            if (__VehicleTiming[i] != nullptr) delete __VehicleTiming[i];
         }

         __ResponseID = that.__ResponseID;
         __VehicleTiming.clear();
         for (size_t i=0; i< that.__VehicleTiming.size(); i++)
         {
            __VehicleTiming.push_back( that.__VehicleTiming[i] == nullptr ? nullptr : that.__VehicleTiming[i]->clone());
         }

      }
      return *this;
   }

   BatchRoutePlanResponse* BatchRoutePlanResponse::clone() const
   {
        return new BatchRoutePlanResponse(*this);
   }
   
   BatchRoutePlanResponse::~BatchRoutePlanResponse(void)
   {
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         if (__VehicleTiming[i] != nullptr) delete __VehicleTiming[i];
      }

   }
  
   void BatchRoutePlanResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__VehicleTiming.size()));
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         assert(__VehicleTiming[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __VehicleTiming[i], buf);
      }

   }
   
   void BatchRoutePlanResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         if (__VehicleTiming[i] != nullptr)
            delete __VehicleTiming[i];
      }
      __VehicleTiming.clear();
      uint16_t __VehicleTiming_length = buf.getUShort();
      for (uint32_t i=0; i< __VehicleTiming_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::TaskTimingPair* e = (afrl::impact::TaskTimingPair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __VehicleTiming.push_back(e);
         }
      }

   }

   uint32_t BatchRoutePlanResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         if (__VehicleTiming[i] != nullptr)
         {
            size += __VehicleTiming[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string BatchRoutePlanResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BatchRoutePlanResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "VehicleTiming (TaskTimingPair [ " << __VehicleTiming.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BatchRoutePlanResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BatchRoutePlanResponse Series=\"IMPACT\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <VehicleTiming>\n";
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         str << (__VehicleTiming[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleTiming[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleTiming>\n";
      str << ws << "</BatchRoutePlanResponse>\n";

      return str.str();
   }

   bool BatchRoutePlanResponse::operator==(const BatchRoutePlanResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__VehicleTiming.size() != that.__VehicleTiming.size()) return false;
      for (size_t i=0; i<__VehicleTiming.size(); i++)
      {
         if(__VehicleTiming[i] && that.__VehicleTiming[i])
         {
            if(__VehicleTiming[i]->getSeriesNameAsLong() != that.__VehicleTiming[i]->getSeriesNameAsLong()) return false;
            if(__VehicleTiming[i]->getSeriesVersion() != that.__VehicleTiming[i]->getSeriesVersion()) return false;
            if(__VehicleTiming[i]->getLmcpType() != that.__VehicleTiming[i]->getLmcpType()) return false;
            if( *(__VehicleTiming[i]) != *(that.__VehicleTiming[i]) ) return false;
         }
         else if(__VehicleTiming[i] != that.__VehicleTiming[i]) return false;
      }
      return true;

   }

   bool BatchRoutePlanResponse::operator!=(const BatchRoutePlanResponse & that)
   {
      return( !(operator==(that)) );
   }

   BatchRoutePlanResponse& BatchRoutePlanResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }



} // end namespace impact
} // end namespace afrl

