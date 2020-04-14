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
#include "afrl/impact/ImpactAutomationResponse.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ImpactAutomationResponse::Subscription = "afrl.impact.ImpactAutomationResponse";
   const std::string ImpactAutomationResponse::TypeName = "ImpactAutomationResponse";
   const std::string ImpactAutomationResponse::SeriesName = "IMPACT";
   const int64_t ImpactAutomationResponse::SeriesId = 5281966179208134656LL;
   const uint16_t ImpactAutomationResponse::SeriesVersion = 14;
   const uint32_t ImpactAutomationResponse::TypeId = 18;
   
   bool isImpactAutomationResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   bool isImpactAutomationResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   std::vector< std::string > ImpactAutomationResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ImpactAutomationResponse::ImpactAutomationResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;
      __TrialResponse = new afrl::cmasi::AutomationResponse();
      __PlayID = 0LL;
      __SolutionID = 0LL;
      __Sandbox = false;

   }
     
   ImpactAutomationResponse::ImpactAutomationResponse(const ImpactAutomationResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __TrialResponse = that.__TrialResponse == nullptr ? nullptr : that.__TrialResponse->clone();
        __PlayID = that.__PlayID;
        __SolutionID = that.__SolutionID;
        __Sandbox = that.__Sandbox;
        __Summaries.clear();
        for (size_t i=0; i< that.__Summaries.size(); i++)
        {
           __Summaries.push_back( that.__Summaries[i] == nullptr ? nullptr : that.__Summaries[i]->clone());
        }

   }
   
   ImpactAutomationResponse & ImpactAutomationResponse::operator=(const ImpactAutomationResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__TrialResponse != nullptr) delete __TrialResponse;
         for (size_t i=0; i<__Summaries.size(); i++)
         {
            if (__Summaries[i] != nullptr) delete __Summaries[i];
         }

         __ResponseID = that.__ResponseID;
         __TrialResponse = that.__TrialResponse == nullptr ? nullptr : that.__TrialResponse->clone();
         __PlayID = that.__PlayID;
         __SolutionID = that.__SolutionID;
         __Sandbox = that.__Sandbox;
         __Summaries.clear();
         for (size_t i=0; i< that.__Summaries.size(); i++)
         {
            __Summaries.push_back( that.__Summaries[i] == nullptr ? nullptr : that.__Summaries[i]->clone());
         }

      }
      return *this;
   }

   ImpactAutomationResponse* ImpactAutomationResponse::clone() const
   {
        return new ImpactAutomationResponse(*this);
   }
   
   ImpactAutomationResponse::~ImpactAutomationResponse(void)
   {
      if (__TrialResponse != nullptr) delete __TrialResponse;
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         if (__Summaries[i] != nullptr) delete __Summaries[i];
      }

   }
  
   void ImpactAutomationResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      assert(__TrialResponse != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __TrialResponse, buf);
      buf.putLong(__PlayID);
      buf.putLong(__SolutionID);
      buf.putBool(__Sandbox);
      buf.putUShort( static_cast<uint16_t>(__Summaries.size()));
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         assert(__Summaries[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Summaries[i], buf);
      }

   }
   
   void ImpactAutomationResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      {
         if (__TrialResponse != nullptr) delete __TrialResponse;
         __TrialResponse = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __TrialResponse = (afrl::cmasi::AutomationResponse*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__TrialResponse != nullptr) __TrialResponse->unpack(buf);
            else assert(__TrialResponse != nullptr);
         }
      }
      __PlayID = buf.getLong();
      __SolutionID = buf.getLong();
      __Sandbox = buf.getBool();
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

   uint32_t ImpactAutomationResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__TrialResponse != nullptr ? __TrialResponse->calculatePackedSize() + 15 : 1);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(bool);
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

   std::string ImpactAutomationResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ImpactAutomationResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "TrialResponse (AutomationResponse)";
      if (__TrialResponse == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "PlayID (int64_t) = " << __PlayID << "\n";
      oss << indent << "SolutionID (int64_t) = " << __SolutionID << "\n";
      oss << indent << "Sandbox (bool) = " << __Sandbox << "\n";
      oss << indent << "Summaries (TaskSummary [ " << __Summaries.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ImpactAutomationResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ImpactAutomationResponse Series=\"IMPACT\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      if (__TrialResponse != nullptr)
      {
         str << ws << "   <TrialResponse>";
         str << "\n" + __TrialResponse->toXML(depth + 1) + ws + "   ";
         str << "</TrialResponse>\n";
      }
      str << ws << "   <PlayID>" << __PlayID << "</PlayID>\n";
      str << ws << "   <SolutionID>" << __SolutionID << "</SolutionID>\n";
      str << ws << "   <Sandbox>" << (__Sandbox ? "true" : "false") << "</Sandbox>\n";
      str << ws << "   <Summaries>\n";
      for (size_t i=0; i<__Summaries.size(); i++)
      {
         str << (__Summaries[i] == nullptr ? ( ws + "   <null/>\n") : (__Summaries[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Summaries>\n";
      str << ws << "</ImpactAutomationResponse>\n";

      return str.str();
   }

   bool ImpactAutomationResponse::operator==(const ImpactAutomationResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__TrialResponse && that.__TrialResponse)
      {
         if(__TrialResponse->getSeriesNameAsLong() != that.__TrialResponse->getSeriesNameAsLong()) return false;
         if(__TrialResponse->getSeriesVersion() != that.__TrialResponse->getSeriesVersion()) return false;
         if(__TrialResponse->getLmcpType() != that.__TrialResponse->getLmcpType()) return false;
         if( *(__TrialResponse) != *(that.__TrialResponse) ) return false;
      }
      else if(__TrialResponse != that.__TrialResponse) return false;
      if(__PlayID != that.__PlayID) return false;
      if(__SolutionID != that.__SolutionID) return false;
      if(__Sandbox != that.__Sandbox) return false;
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

   bool ImpactAutomationResponse::operator!=(const ImpactAutomationResponse & that)
   {
      return( !(operator==(that)) );
   }

   ImpactAutomationResponse& ImpactAutomationResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }

   ImpactAutomationResponse& ImpactAutomationResponse::setTrialResponse(const afrl::cmasi::AutomationResponse* const val)
   {
      if (__TrialResponse != nullptr) { delete __TrialResponse; __TrialResponse = nullptr; }
      if (val != nullptr) { __TrialResponse = const_cast< afrl::cmasi::AutomationResponse* > (val); }
      return *this;
   }

   ImpactAutomationResponse& ImpactAutomationResponse::setPlayID(const int64_t val)
   {
      __PlayID = val;
      return *this;
   }

   ImpactAutomationResponse& ImpactAutomationResponse::setSolutionID(const int64_t val)
   {
      __SolutionID = val;
      return *this;
   }

   ImpactAutomationResponse& ImpactAutomationResponse::setSandbox(const bool val)
   {
      __Sandbox = val;
      return *this;
   }



} // end namespace impact
} // end namespace afrl

