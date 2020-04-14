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
#include "uxas/messages/task/TaskAutomationRequest.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskAutomationRequest::Subscription = "uxas.messages.task.TaskAutomationRequest";
   const std::string TaskAutomationRequest::TypeName = "TaskAutomationRequest";
   const std::string TaskAutomationRequest::SeriesName = "UXTASK";
   const int64_t TaskAutomationRequest::SeriesId = 6149757930721443840LL;
   const uint16_t TaskAutomationRequest::SeriesVersion = 8;
   const uint32_t TaskAutomationRequest::TypeId = 6;
   
   bool isTaskAutomationRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   bool isTaskAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   std::vector< std::string > TaskAutomationRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskAutomationRequest::TaskAutomationRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __OriginalRequest = new afrl::cmasi::AutomationRequest();
      __SandBoxRequest = false;

   }
     
   TaskAutomationRequest::TaskAutomationRequest(const TaskAutomationRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __OriginalRequest = that.__OriginalRequest == nullptr ? nullptr : that.__OriginalRequest->clone();
        __SandBoxRequest = that.__SandBoxRequest;
        __PlanningStates.clear();
        for (size_t i=0; i< that.__PlanningStates.size(); i++)
        {
           __PlanningStates.push_back( that.__PlanningStates[i] == nullptr ? nullptr : that.__PlanningStates[i]->clone());
        }

   }
   
   TaskAutomationRequest & TaskAutomationRequest::operator=(const TaskAutomationRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__OriginalRequest != nullptr) delete __OriginalRequest;
         for (size_t i=0; i<__PlanningStates.size(); i++)
         {
            if (__PlanningStates[i] != nullptr) delete __PlanningStates[i];
         }

         __RequestID = that.__RequestID;
         __OriginalRequest = that.__OriginalRequest == nullptr ? nullptr : that.__OriginalRequest->clone();
         __SandBoxRequest = that.__SandBoxRequest;
         __PlanningStates.clear();
         for (size_t i=0; i< that.__PlanningStates.size(); i++)
         {
            __PlanningStates.push_back( that.__PlanningStates[i] == nullptr ? nullptr : that.__PlanningStates[i]->clone());
         }

      }
      return *this;
   }

   TaskAutomationRequest* TaskAutomationRequest::clone() const
   {
        return new TaskAutomationRequest(*this);
   }
   
   TaskAutomationRequest::~TaskAutomationRequest(void)
   {
      if (__OriginalRequest != nullptr) delete __OriginalRequest;
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         if (__PlanningStates[i] != nullptr) delete __PlanningStates[i];
      }

   }
  
   void TaskAutomationRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      assert(__OriginalRequest != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __OriginalRequest, buf);
      buf.putBool(__SandBoxRequest);
      buf.putUShort( static_cast<uint16_t>(__PlanningStates.size()));
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         assert(__PlanningStates[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PlanningStates[i], buf);
      }

   }
   
   void TaskAutomationRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      {
         if (__OriginalRequest != nullptr) delete __OriginalRequest;
         __OriginalRequest = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __OriginalRequest = (afrl::cmasi::AutomationRequest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__OriginalRequest != nullptr) __OriginalRequest->unpack(buf);
            else assert(__OriginalRequest != nullptr);
         }
      }
      __SandBoxRequest = buf.getBool();
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         if (__PlanningStates[i] != nullptr)
            delete __PlanningStates[i];
      }
      __PlanningStates.clear();
      uint16_t __PlanningStates_length = buf.getUShort();
      for (uint32_t i=0; i< __PlanningStates_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::PlanningState* e = (uxas::messages::task::PlanningState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PlanningStates.push_back(e);
         }
      }

   }

   uint32_t TaskAutomationRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__OriginalRequest != nullptr ? __OriginalRequest->calculatePackedSize() + 15 : 1);
      size += sizeof(bool);
      size += 2;
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         if (__PlanningStates[i] != nullptr)
         {
            size += __PlanningStates[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string TaskAutomationRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskAutomationRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "OriginalRequest (AutomationRequest)";
      if (__OriginalRequest == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "SandBoxRequest (bool) = " << __SandBoxRequest << "\n";
      oss << indent << "PlanningStates (PlanningState [ " << __PlanningStates.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskAutomationRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskAutomationRequest Series=\"UXTASK\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      if (__OriginalRequest != nullptr)
      {
         str << ws << "   <OriginalRequest>";
         str << "\n" + __OriginalRequest->toXML(depth + 1) + ws + "   ";
         str << "</OriginalRequest>\n";
      }
      str << ws << "   <SandBoxRequest>" << (__SandBoxRequest ? "true" : "false") << "</SandBoxRequest>\n";
      str << ws << "   <PlanningStates>\n";
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         str << (__PlanningStates[i] == nullptr ? ( ws + "   <null/>\n") : (__PlanningStates[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PlanningStates>\n";
      str << ws << "</TaskAutomationRequest>\n";

      return str.str();
   }

   bool TaskAutomationRequest::operator==(const TaskAutomationRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__OriginalRequest && that.__OriginalRequest)
      {
         if(__OriginalRequest->getSeriesNameAsLong() != that.__OriginalRequest->getSeriesNameAsLong()) return false;
         if(__OriginalRequest->getSeriesVersion() != that.__OriginalRequest->getSeriesVersion()) return false;
         if(__OriginalRequest->getLmcpType() != that.__OriginalRequest->getLmcpType()) return false;
         if( *(__OriginalRequest) != *(that.__OriginalRequest) ) return false;
      }
      else if(__OriginalRequest != that.__OriginalRequest) return false;
      if(__SandBoxRequest != that.__SandBoxRequest) return false;
      if(__PlanningStates.size() != that.__PlanningStates.size()) return false;
      for (size_t i=0; i<__PlanningStates.size(); i++)
      {
         if(__PlanningStates[i] && that.__PlanningStates[i])
         {
            if(__PlanningStates[i]->getSeriesNameAsLong() != that.__PlanningStates[i]->getSeriesNameAsLong()) return false;
            if(__PlanningStates[i]->getSeriesVersion() != that.__PlanningStates[i]->getSeriesVersion()) return false;
            if(__PlanningStates[i]->getLmcpType() != that.__PlanningStates[i]->getLmcpType()) return false;
            if( *(__PlanningStates[i]) != *(that.__PlanningStates[i]) ) return false;
         }
         else if(__PlanningStates[i] != that.__PlanningStates[i]) return false;
      }
      return true;

   }

   bool TaskAutomationRequest::operator!=(const TaskAutomationRequest & that)
   {
      return( !(operator==(that)) );
   }

   TaskAutomationRequest& TaskAutomationRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   TaskAutomationRequest& TaskAutomationRequest::setOriginalRequest(const afrl::cmasi::AutomationRequest* const val)
   {
      if (__OriginalRequest != nullptr) { delete __OriginalRequest; __OriginalRequest = nullptr; }
      if (val != nullptr) { __OriginalRequest = const_cast< afrl::cmasi::AutomationRequest* > (val); }
      return *this;
   }

   TaskAutomationRequest& TaskAutomationRequest::setSandBoxRequest(const bool val)
   {
      __SandBoxRequest = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

