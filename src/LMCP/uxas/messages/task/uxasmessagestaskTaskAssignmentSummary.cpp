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
#include "uxas/messages/task/TaskAssignmentSummary.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskAssignmentSummary::Subscription = "uxas.messages.task.TaskAssignmentSummary";
   const std::string TaskAssignmentSummary::TypeName = "TaskAssignmentSummary";
   const std::string TaskAssignmentSummary::SeriesName = "UXTASK";
   const int64_t TaskAssignmentSummary::SeriesId = 6149757930721443840LL;
   const uint16_t TaskAssignmentSummary::SeriesVersion = 8;
   const uint32_t TaskAssignmentSummary::TypeId = 19;
   
   bool isTaskAssignmentSummary(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   bool isTaskAssignmentSummary(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   std::vector< std::string > TaskAssignmentSummaryDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskAssignmentSummary::TaskAssignmentSummary(void) : avtas::lmcp::Object()
   {
      __CorrespondingAutomationRequestID = 0LL;
      __OperatingRegion = 0LL;

   }
     
   TaskAssignmentSummary::TaskAssignmentSummary(const TaskAssignmentSummary &that) : avtas::lmcp::Object(that)
   {
        __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
        __OperatingRegion = that.__OperatingRegion;
        __TaskList.clear();
        for (size_t i=0; i< that.__TaskList.size(); i++)
        {
           __TaskList.push_back( that.__TaskList[i] == nullptr ? nullptr : that.__TaskList[i]->clone());
        }

   }
   
   TaskAssignmentSummary & TaskAssignmentSummary::operator=(const TaskAssignmentSummary &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__TaskList.size(); i++)
         {
            if (__TaskList[i] != nullptr) delete __TaskList[i];
         }

         __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
         __OperatingRegion = that.__OperatingRegion;
         __TaskList.clear();
         for (size_t i=0; i< that.__TaskList.size(); i++)
         {
            __TaskList.push_back( that.__TaskList[i] == nullptr ? nullptr : that.__TaskList[i]->clone());
         }

      }
      return *this;
   }

   TaskAssignmentSummary* TaskAssignmentSummary::clone() const
   {
        return new TaskAssignmentSummary(*this);
   }
   
   TaskAssignmentSummary::~TaskAssignmentSummary(void)
   {
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if (__TaskList[i] != nullptr) delete __TaskList[i];
      }

   }
  
   void TaskAssignmentSummary::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__CorrespondingAutomationRequestID);
      buf.putLong(__OperatingRegion);
      buf.putUShort( static_cast<uint16_t>(__TaskList.size()));
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         assert(__TaskList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __TaskList[i], buf);
      }

   }
   
   void TaskAssignmentSummary::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __CorrespondingAutomationRequestID = buf.getLong();
      __OperatingRegion = buf.getLong();
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if (__TaskList[i] != nullptr)
            delete __TaskList[i];
      }
      __TaskList.clear();
      uint16_t __TaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::TaskAssignment* e = (uxas::messages::task::TaskAssignment*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __TaskList.push_back(e);
         }
      }

   }

   uint32_t TaskAssignmentSummary::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if (__TaskList[i] != nullptr)
         {
            size += __TaskList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string TaskAssignmentSummary::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskAssignmentSummary ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CorrespondingAutomationRequestID (int64_t) = " << __CorrespondingAutomationRequestID << "\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "TaskList (TaskAssignment [ " << __TaskList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskAssignmentSummary::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskAssignmentSummary Series=\"UXTASK\">\n";
      str << ws << "   <CorrespondingAutomationRequestID>" << __CorrespondingAutomationRequestID << "</CorrespondingAutomationRequestID>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <TaskList>\n";
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         str << (__TaskList[i] == nullptr ? ( ws + "   <null/>\n") : (__TaskList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </TaskList>\n";
      str << ws << "</TaskAssignmentSummary>\n";

      return str.str();
   }

   bool TaskAssignmentSummary::operator==(const TaskAssignmentSummary & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__CorrespondingAutomationRequestID != that.__CorrespondingAutomationRequestID) return false;
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__TaskList.size() != that.__TaskList.size()) return false;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if(__TaskList[i] && that.__TaskList[i])
         {
            if(__TaskList[i]->getSeriesNameAsLong() != that.__TaskList[i]->getSeriesNameAsLong()) return false;
            if(__TaskList[i]->getSeriesVersion() != that.__TaskList[i]->getSeriesVersion()) return false;
            if(__TaskList[i]->getLmcpType() != that.__TaskList[i]->getLmcpType()) return false;
            if( *(__TaskList[i]) != *(that.__TaskList[i]) ) return false;
         }
         else if(__TaskList[i] != that.__TaskList[i]) return false;
      }
      return true;

   }

   bool TaskAssignmentSummary::operator!=(const TaskAssignmentSummary & that)
   {
      return( !(operator==(that)) );
   }

   TaskAssignmentSummary& TaskAssignmentSummary::setCorrespondingAutomationRequestID(const int64_t val)
   {
      __CorrespondingAutomationRequestID = val;
      return *this;
   }

   TaskAssignmentSummary& TaskAssignmentSummary::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

