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
#include "afrl/impact/ImpactAutomationRequest.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ImpactAutomationRequest::Subscription = "afrl.impact.ImpactAutomationRequest";
   const std::string ImpactAutomationRequest::TypeName = "ImpactAutomationRequest";
   const std::string ImpactAutomationRequest::SeriesName = "IMPACT";
   const int64_t ImpactAutomationRequest::SeriesId = 5281966179208134656LL;
   const uint16_t ImpactAutomationRequest::SeriesVersion = 14;
   const uint32_t ImpactAutomationRequest::TypeId = 17;
   
   bool isImpactAutomationRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   bool isImpactAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   std::vector< std::string > ImpactAutomationRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ImpactAutomationRequest::ImpactAutomationRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __TrialRequest = new afrl::cmasi::AutomationRequest();
      __PlayID = 0LL;
      __SolutionID = 0LL;
      __Sandbox = false;

   }
     
   ImpactAutomationRequest::ImpactAutomationRequest(const ImpactAutomationRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __TrialRequest = that.__TrialRequest == nullptr ? nullptr : that.__TrialRequest->clone();
        __OverridePlanningConditions.clear();
        for (size_t i=0; i< that.__OverridePlanningConditions.size(); i++)
        {
           __OverridePlanningConditions.push_back( that.__OverridePlanningConditions[i] == nullptr ? nullptr : that.__OverridePlanningConditions[i]->clone());
        }
        __PlayID = that.__PlayID;
        __SolutionID = that.__SolutionID;
        __Sandbox = that.__Sandbox;

   }
   
   ImpactAutomationRequest & ImpactAutomationRequest::operator=(const ImpactAutomationRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__TrialRequest != nullptr) delete __TrialRequest;
         for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
         {
            if (__OverridePlanningConditions[i] != nullptr) delete __OverridePlanningConditions[i];
         }

         __RequestID = that.__RequestID;
         __TrialRequest = that.__TrialRequest == nullptr ? nullptr : that.__TrialRequest->clone();
         __OverridePlanningConditions.clear();
         for (size_t i=0; i< that.__OverridePlanningConditions.size(); i++)
         {
            __OverridePlanningConditions.push_back( that.__OverridePlanningConditions[i] == nullptr ? nullptr : that.__OverridePlanningConditions[i]->clone());
         }
         __PlayID = that.__PlayID;
         __SolutionID = that.__SolutionID;
         __Sandbox = that.__Sandbox;

      }
      return *this;
   }

   ImpactAutomationRequest* ImpactAutomationRequest::clone() const
   {
        return new ImpactAutomationRequest(*this);
   }
   
   ImpactAutomationRequest::~ImpactAutomationRequest(void)
   {
      if (__TrialRequest != nullptr) delete __TrialRequest;
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         if (__OverridePlanningConditions[i] != nullptr) delete __OverridePlanningConditions[i];
      }

   }
  
   void ImpactAutomationRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      assert(__TrialRequest != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __TrialRequest, buf);
      buf.putUShort( static_cast<uint16_t>(__OverridePlanningConditions.size()));
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         assert(__OverridePlanningConditions[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __OverridePlanningConditions[i], buf);
      }
      buf.putLong(__PlayID);
      buf.putLong(__SolutionID);
      buf.putBool(__Sandbox);

   }
   
   void ImpactAutomationRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      {
         if (__TrialRequest != nullptr) delete __TrialRequest;
         __TrialRequest = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __TrialRequest = (afrl::cmasi::AutomationRequest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__TrialRequest != nullptr) __TrialRequest->unpack(buf);
            else assert(__TrialRequest != nullptr);
         }
      }
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         if (__OverridePlanningConditions[i] != nullptr)
            delete __OverridePlanningConditions[i];
      }
      __OverridePlanningConditions.clear();
      uint16_t __OverridePlanningConditions_length = buf.getUShort();
      for (uint32_t i=0; i< __OverridePlanningConditions_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::SpeedAltPair* e = (afrl::impact::SpeedAltPair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __OverridePlanningConditions.push_back(e);
         }
      }
      __PlayID = buf.getLong();
      __SolutionID = buf.getLong();
      __Sandbox = buf.getBool();

   }

   uint32_t ImpactAutomationRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__TrialRequest != nullptr ? __TrialRequest->calculatePackedSize() + 15 : 1);
      size += 2;
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         if (__OverridePlanningConditions[i] != nullptr)
         {
            size += __OverridePlanningConditions[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(bool);

      return size;
   }

   std::string ImpactAutomationRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ImpactAutomationRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "TrialRequest (AutomationRequest)";
      if (__TrialRequest == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "OverridePlanningConditions (SpeedAltPair [ " << __OverridePlanningConditions.size() << ", var ])\n";
      oss << indent << "PlayID (int64_t) = " << __PlayID << "\n";
      oss << indent << "SolutionID (int64_t) = " << __SolutionID << "\n";
      oss << indent << "Sandbox (bool) = " << __Sandbox << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ImpactAutomationRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ImpactAutomationRequest Series=\"IMPACT\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      if (__TrialRequest != nullptr)
      {
         str << ws << "   <TrialRequest>";
         str << "\n" + __TrialRequest->toXML(depth + 1) + ws + "   ";
         str << "</TrialRequest>\n";
      }
      str << ws << "   <OverridePlanningConditions>\n";
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         str << (__OverridePlanningConditions[i] == nullptr ? ( ws + "   <null/>\n") : (__OverridePlanningConditions[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </OverridePlanningConditions>\n";
      str << ws << "   <PlayID>" << __PlayID << "</PlayID>\n";
      str << ws << "   <SolutionID>" << __SolutionID << "</SolutionID>\n";
      str << ws << "   <Sandbox>" << (__Sandbox ? "true" : "false") << "</Sandbox>\n";
      str << ws << "</ImpactAutomationRequest>\n";

      return str.str();
   }

   bool ImpactAutomationRequest::operator==(const ImpactAutomationRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__TrialRequest && that.__TrialRequest)
      {
         if(__TrialRequest->getSeriesNameAsLong() != that.__TrialRequest->getSeriesNameAsLong()) return false;
         if(__TrialRequest->getSeriesVersion() != that.__TrialRequest->getSeriesVersion()) return false;
         if(__TrialRequest->getLmcpType() != that.__TrialRequest->getLmcpType()) return false;
         if( *(__TrialRequest) != *(that.__TrialRequest) ) return false;
      }
      else if(__TrialRequest != that.__TrialRequest) return false;
      if(__OverridePlanningConditions.size() != that.__OverridePlanningConditions.size()) return false;
      for (size_t i=0; i<__OverridePlanningConditions.size(); i++)
      {
         if(__OverridePlanningConditions[i] && that.__OverridePlanningConditions[i])
         {
            if(__OverridePlanningConditions[i]->getSeriesNameAsLong() != that.__OverridePlanningConditions[i]->getSeriesNameAsLong()) return false;
            if(__OverridePlanningConditions[i]->getSeriesVersion() != that.__OverridePlanningConditions[i]->getSeriesVersion()) return false;
            if(__OverridePlanningConditions[i]->getLmcpType() != that.__OverridePlanningConditions[i]->getLmcpType()) return false;
            if( *(__OverridePlanningConditions[i]) != *(that.__OverridePlanningConditions[i]) ) return false;
         }
         else if(__OverridePlanningConditions[i] != that.__OverridePlanningConditions[i]) return false;
      }
      if(__PlayID != that.__PlayID) return false;
      if(__SolutionID != that.__SolutionID) return false;
      if(__Sandbox != that.__Sandbox) return false;
      return true;

   }

   bool ImpactAutomationRequest::operator!=(const ImpactAutomationRequest & that)
   {
      return( !(operator==(that)) );
   }

   ImpactAutomationRequest& ImpactAutomationRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   ImpactAutomationRequest& ImpactAutomationRequest::setTrialRequest(const afrl::cmasi::AutomationRequest* const val)
   {
      if (__TrialRequest != nullptr) { delete __TrialRequest; __TrialRequest = nullptr; }
      if (val != nullptr) { __TrialRequest = const_cast< afrl::cmasi::AutomationRequest* > (val); }
      return *this;
   }


   ImpactAutomationRequest& ImpactAutomationRequest::setPlayID(const int64_t val)
   {
      __PlayID = val;
      return *this;
   }

   ImpactAutomationRequest& ImpactAutomationRequest::setSolutionID(const int64_t val)
   {
      __SolutionID = val;
      return *this;
   }

   ImpactAutomationRequest& ImpactAutomationRequest::setSandbox(const bool val)
   {
      __Sandbox = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

