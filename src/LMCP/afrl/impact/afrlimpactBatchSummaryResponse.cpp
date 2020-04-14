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
#include "afrl/impact/BatchSummaryResponse.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BatchSummaryResponse::Subscription = "afrl.impact.BatchSummaryResponse";
   const std::string BatchSummaryResponse::TypeName = "BatchSummaryResponse";
   const std::string BatchSummaryResponse::SeriesName = "IMPACT";
   const int64_t BatchSummaryResponse::SeriesId = 5281966179208134656LL;
   const uint16_t BatchSummaryResponse::SeriesVersion = 14;
   const uint32_t BatchSummaryResponse::TypeId = 13;
   
   bool isBatchSummaryResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   bool isBatchSummaryResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   std::vector< std::string > BatchSummaryResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BatchSummaryResponse::BatchSummaryResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   BatchSummaryResponse::BatchSummaryResponse(const BatchSummaryResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __Summaries.clear();
        for (size_t i=0; i< that.__Summaries.size(); i++)
        {
           __Summaries.push_back( that.__Summaries[i] == nullptr ? nullptr : that.__Summaries[i]->clone());
        }

   }
   
   BatchSummaryResponse & BatchSummaryResponse::operator=(const BatchSummaryResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Summaries.size(); i++)
         {
            if (__Summaries[i] != nullptr) delete __Summaries[i];
         }

         __ResponseID = that.__ResponseID;
         __Summaries.clear();
         for (size_t i=0; i< that.__Summaries.size(); i++)
         {
            __Summaries.push_back( that.__Summaries[i] == nullptr ? nullptr : that.__Summaries[i]->clone());
         }

      }
      return *this;
   }

   BatchSummaryResponse* BatchSummaryResponse::clone() const
   {
        return new BatchSummaryResponse(*this);
   }
   
   BatchSummaryResponse::~BatchSummaryResponse(void)
   {
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         if (__Summaries[i] != nullptr) delete __Summaries[i];
      }

   }
  
   void BatchSummaryResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__Summaries.size()));
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         assert(__Summaries[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Summaries[i], buf);
      }

   }
   
   void BatchSummaryResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         if (__Summaries[i] != nullptr)
            delete __Summaries[i];
      }
      __Summaries.clear();
      uint16_t __Summaries_length = buf.getUShort();
      for (uint32_t i=0; i< __Summaries_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::TaskSummary* e = (afrl::impact::TaskSummary*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Summaries.push_back(e);
         }
      }

   }

   uint32_t BatchSummaryResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         if (__Summaries[i] != nullptr)
         {
            size += __Summaries[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string BatchSummaryResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BatchSummaryResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "Summaries (TaskSummary [ " << __Summaries.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BatchSummaryResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BatchSummaryResponse Series=\"IMPACT\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <Summaries>\n";
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         str << (__Summaries[i] == nullptr ? ( ws + "   <null/>\n") : (__Summaries[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Summaries>\n";
      str << ws << "</BatchSummaryResponse>\n";

      return str.str();
   }

   bool BatchSummaryResponse::operator==(const BatchSummaryResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__Summaries.size() != that.__Summaries.size()) return false;
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         if(__Summaries[i] && that.__Summaries[i])
         {
            if(__Summaries[i]->getSeriesNameAsLong() != that.__Summaries[i]->getSeriesNameAsLong()) return false;
            if(__Summaries[i]->getSeriesVersion() != that.__Summaries[i]->getSeriesVersion()) return false;
            if(__Summaries[i]->getLmcpType() != that.__Summaries[i]->getLmcpType()) return false;
            if( *(__Summaries[i]) != *(that.__Summaries[i]) ) return false;
         }
         else if(__Summaries[i] != that.__Summaries[i]) return false;
      }
      return true;

   }

   bool BatchSummaryResponse::operator!=(const BatchSummaryResponse & that)
   {
      return( !(operator==(that)) );
   }

   BatchSummaryResponse& BatchSummaryResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }



} // end namespace impact
} // end namespace afrl

