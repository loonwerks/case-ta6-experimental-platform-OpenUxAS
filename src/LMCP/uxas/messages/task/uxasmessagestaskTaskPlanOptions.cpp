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
#include "uxas/messages/task/TaskPlanOptions.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskPlanOptions::Subscription = "uxas.messages.task.TaskPlanOptions";
   const std::string TaskPlanOptions::TypeName = "TaskPlanOptions";
   const std::string TaskPlanOptions::SeriesName = "UXTASK";
   const int64_t TaskPlanOptions::SeriesId = 6149757930721443840LL;
   const uint16_t TaskPlanOptions::SeriesVersion = 8;
   const uint32_t TaskPlanOptions::TypeId = 21;
   
   bool isTaskPlanOptions(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   bool isTaskPlanOptions(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   std::vector< std::string > TaskPlanOptionsDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskPlanOptions::TaskPlanOptions(void) : avtas::lmcp::Object()
   {
      __CorrespondingAutomationRequestID = 0LL;
      __TaskID = 0LL;
      __Composition = std::string("");

   }
     
   TaskPlanOptions::TaskPlanOptions(const TaskPlanOptions &that) : avtas::lmcp::Object(that)
   {
        __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
        __TaskID = that.__TaskID;
        __Composition = that.__Composition;
        __Options.clear();
        for (size_t i=0; i< that.__Options.size(); i++)
        {
           __Options.push_back( that.__Options[i] == nullptr ? nullptr : that.__Options[i]->clone());
        }

   }
   
   TaskPlanOptions & TaskPlanOptions::operator=(const TaskPlanOptions &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Options.size(); i++)
         {
            if (__Options[i] != nullptr) delete __Options[i];
         }

         __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
         __TaskID = that.__TaskID;
         __Composition = that.__Composition;
         __Options.clear();
         for (size_t i=0; i< that.__Options.size(); i++)
         {
            __Options.push_back( that.__Options[i] == nullptr ? nullptr : that.__Options[i]->clone());
         }

      }
      return *this;
   }

   TaskPlanOptions* TaskPlanOptions::clone() const
   {
        return new TaskPlanOptions(*this);
   }
   
   TaskPlanOptions::~TaskPlanOptions(void)
   {
      for (size_t i=0; i<__Options.size(); i++)
      {
         if (__Options[i] != nullptr) delete __Options[i];
      }

   }
  
   void TaskPlanOptions::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__CorrespondingAutomationRequestID);
      buf.putLong(__TaskID);
      buf.putString(__Composition);
      buf.putUShort( static_cast<uint16_t>(__Options.size()));
      for (size_t i=0; i<__Options.size(); i++)
      {
         assert(__Options[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Options[i], buf);
      }

   }
   
   void TaskPlanOptions::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __CorrespondingAutomationRequestID = buf.getLong();
      __TaskID = buf.getLong();
      __Composition = buf.getString();
      for (size_t i=0; i<__Options.size(); i++)
      {
         if (__Options[i] != nullptr)
            delete __Options[i];
      }
      __Options.clear();
      uint16_t __Options_length = buf.getUShort();
      for (uint32_t i=0; i< __Options_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::TaskOption* e = (uxas::messages::task::TaskOption*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Options.push_back(e);
         }
      }

   }

   uint32_t TaskPlanOptions::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2 + __Composition.length();
      size += 2;
      for (size_t i=0; i<__Options.size(); i++)
      {
         if (__Options[i] != nullptr)
         {
            size += __Options[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string TaskPlanOptions::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskPlanOptions ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CorrespondingAutomationRequestID (int64_t) = " << __CorrespondingAutomationRequestID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Composition (std::string) = " << __Composition << "\n";
      oss << indent << "Options (TaskOption [ " << __Options.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskPlanOptions::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskPlanOptions Series=\"UXTASK\">\n";
      str << ws << "   <CorrespondingAutomationRequestID>" << __CorrespondingAutomationRequestID << "</CorrespondingAutomationRequestID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <Composition>" << __Composition << "</Composition>\n";
      str << ws << "   <Options>\n";
      for (size_t i=0; i<__Options.size(); i++)
      {
         str << (__Options[i] == nullptr ? ( ws + "   <null/>\n") : (__Options[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Options>\n";
      str << ws << "</TaskPlanOptions>\n";

      return str.str();
   }

   bool TaskPlanOptions::operator==(const TaskPlanOptions & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__CorrespondingAutomationRequestID != that.__CorrespondingAutomationRequestID) return false;
      if(__TaskID != that.__TaskID) return false;
      if(__Composition != that.__Composition) return false;
      if(__Options.size() != that.__Options.size()) return false;
      for (size_t i=0; i<__Options.size(); i++)
      {
         if(__Options[i] && that.__Options[i])
         {
            if(__Options[i]->getSeriesNameAsLong() != that.__Options[i]->getSeriesNameAsLong()) return false;
            if(__Options[i]->getSeriesVersion() != that.__Options[i]->getSeriesVersion()) return false;
            if(__Options[i]->getLmcpType() != that.__Options[i]->getLmcpType()) return false;
            if( *(__Options[i]) != *(that.__Options[i]) ) return false;
         }
         else if(__Options[i] != that.__Options[i]) return false;
      }
      return true;

   }

   bool TaskPlanOptions::operator!=(const TaskPlanOptions & that)
   {
      return( !(operator==(that)) );
   }

   TaskPlanOptions& TaskPlanOptions::setCorrespondingAutomationRequestID(const int64_t val)
   {
      __CorrespondingAutomationRequestID = val;
      return *this;
   }

   TaskPlanOptions& TaskPlanOptions::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskPlanOptions& TaskPlanOptions::setComposition(const std::string val)
   {
      __Composition = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

