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
#include "uxas/messages/task/TaskAutomationResponse.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskAutomationResponse::Subscription = "uxas.messages.task.TaskAutomationResponse";
   const std::string TaskAutomationResponse::TypeName = "TaskAutomationResponse";
   const std::string TaskAutomationResponse::SeriesName = "UXTASK";
   const int64_t TaskAutomationResponse::SeriesId = 6149757930721443840LL;
   const uint16_t TaskAutomationResponse::SeriesVersion = 8;
   const uint32_t TaskAutomationResponse::TypeId = 7;
   
   bool isTaskAutomationResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   bool isTaskAutomationResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   std::vector< std::string > TaskAutomationResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskAutomationResponse::TaskAutomationResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;
      __OriginalResponse = new afrl::cmasi::AutomationResponse();

   }
     
   TaskAutomationResponse::TaskAutomationResponse(const TaskAutomationResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __OriginalResponse = that.__OriginalResponse == nullptr ? nullptr : that.__OriginalResponse->clone();
        __FinalStates.clear();
        for (size_t i=0; i< that.__FinalStates.size(); i++)
        {
           __FinalStates.push_back( that.__FinalStates[i] == nullptr ? nullptr : that.__FinalStates[i]->clone());
        }

   }
   
   TaskAutomationResponse & TaskAutomationResponse::operator=(const TaskAutomationResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__OriginalResponse != nullptr) delete __OriginalResponse;
         for (size_t i=0; i<__FinalStates.size(); i++)
         {
            if (__FinalStates[i] != nullptr) delete __FinalStates[i];
         }

         __ResponseID = that.__ResponseID;
         __OriginalResponse = that.__OriginalResponse == nullptr ? nullptr : that.__OriginalResponse->clone();
         __FinalStates.clear();
         for (size_t i=0; i< that.__FinalStates.size(); i++)
         {
            __FinalStates.push_back( that.__FinalStates[i] == nullptr ? nullptr : that.__FinalStates[i]->clone());
         }

      }
      return *this;
   }

   TaskAutomationResponse* TaskAutomationResponse::clone() const
   {
        return new TaskAutomationResponse(*this);
   }
   
   TaskAutomationResponse::~TaskAutomationResponse(void)
   {
      if (__OriginalResponse != nullptr) delete __OriginalResponse;
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         if (__FinalStates[i] != nullptr) delete __FinalStates[i];
      }

   }
  
   void TaskAutomationResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      assert(__OriginalResponse != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __OriginalResponse, buf);
      buf.putUShort( static_cast<uint16_t>(__FinalStates.size()));
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         assert(__FinalStates[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __FinalStates[i], buf);
      }

   }
   
   void TaskAutomationResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      {
         if (__OriginalResponse != nullptr) delete __OriginalResponse;
         __OriginalResponse = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __OriginalResponse = (afrl::cmasi::AutomationResponse*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__OriginalResponse != nullptr) __OriginalResponse->unpack(buf);
            else assert(__OriginalResponse != nullptr);
         }
      }
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         if (__FinalStates[i] != nullptr)
            delete __FinalStates[i];
      }
      __FinalStates.clear();
      uint16_t __FinalStates_length = buf.getUShort();
      for (uint32_t i=0; i< __FinalStates_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::PlanningState* e = (uxas::messages::task::PlanningState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __FinalStates.push_back(e);
         }
      }

   }

   uint32_t TaskAutomationResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__OriginalResponse != nullptr ? __OriginalResponse->calculatePackedSize() + 15 : 1);
      size += 2;
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         if (__FinalStates[i] != nullptr)
         {
            size += __FinalStates[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string TaskAutomationResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskAutomationResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "OriginalResponse (AutomationResponse)";
      if (__OriginalResponse == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "FinalStates (PlanningState [ " << __FinalStates.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskAutomationResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskAutomationResponse Series=\"UXTASK\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      if (__OriginalResponse != nullptr)
      {
         str << ws << "   <OriginalResponse>";
         str << "\n" + __OriginalResponse->toXML(depth + 1) + ws + "   ";
         str << "</OriginalResponse>\n";
      }
      str << ws << "   <FinalStates>\n";
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         str << (__FinalStates[i] == nullptr ? ( ws + "   <null/>\n") : (__FinalStates[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </FinalStates>\n";
      str << ws << "</TaskAutomationResponse>\n";

      return str.str();
   }

   bool TaskAutomationResponse::operator==(const TaskAutomationResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__OriginalResponse && that.__OriginalResponse)
      {
         if(__OriginalResponse->getSeriesNameAsLong() != that.__OriginalResponse->getSeriesNameAsLong()) return false;
         if(__OriginalResponse->getSeriesVersion() != that.__OriginalResponse->getSeriesVersion()) return false;
         if(__OriginalResponse->getLmcpType() != that.__OriginalResponse->getLmcpType()) return false;
         if( *(__OriginalResponse) != *(that.__OriginalResponse) ) return false;
      }
      else if(__OriginalResponse != that.__OriginalResponse) return false;
      if(__FinalStates.size() != that.__FinalStates.size()) return false;
      for (size_t i=0; i<__FinalStates.size(); i++)
      {
         if(__FinalStates[i] && that.__FinalStates[i])
         {
            if(__FinalStates[i]->getSeriesNameAsLong() != that.__FinalStates[i]->getSeriesNameAsLong()) return false;
            if(__FinalStates[i]->getSeriesVersion() != that.__FinalStates[i]->getSeriesVersion()) return false;
            if(__FinalStates[i]->getLmcpType() != that.__FinalStates[i]->getLmcpType()) return false;
            if( *(__FinalStates[i]) != *(that.__FinalStates[i]) ) return false;
         }
         else if(__FinalStates[i] != that.__FinalStates[i]) return false;
      }
      return true;

   }

   bool TaskAutomationResponse::operator!=(const TaskAutomationResponse & that)
   {
      return( !(operator==(that)) );
   }

   TaskAutomationResponse& TaskAutomationResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }

   TaskAutomationResponse& TaskAutomationResponse::setOriginalResponse(const afrl::cmasi::AutomationResponse* const val)
   {
      if (__OriginalResponse != nullptr) { delete __OriginalResponse; __OriginalResponse = nullptr; }
      if (val != nullptr) { __OriginalResponse = const_cast< afrl::cmasi::AutomationResponse* > (val); }
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

