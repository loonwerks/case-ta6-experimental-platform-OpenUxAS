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
#include "uxas/messages/task/TaskComplete.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskComplete::Subscription = "uxas.messages.task.TaskComplete";
   const std::string TaskComplete::TypeName = "TaskComplete";
   const std::string TaskComplete::SeriesName = "UXTASK";
   const int64_t TaskComplete::SeriesId = 6149757930721443840LL;
   const uint16_t TaskComplete::SeriesVersion = 8;
   const uint32_t TaskComplete::TypeId = 28;
   
   bool isTaskComplete(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   bool isTaskComplete(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   std::vector< std::string > TaskCompleteDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskComplete::TaskComplete(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __TimeTaskCompleted = 0LL;

   }
     
   TaskComplete::TaskComplete(const TaskComplete &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __EntitiesInvolved.clear();
        for (size_t i=0; i< that.__EntitiesInvolved.size(); i++)
        {
           __EntitiesInvolved.push_back( that.__EntitiesInvolved[i]);
        }
        __TimeTaskCompleted = that.__TimeTaskCompleted;

   }
   
   TaskComplete & TaskComplete::operator=(const TaskComplete &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskID = that.__TaskID;
         __EntitiesInvolved.clear();
         for (size_t i=0; i< that.__EntitiesInvolved.size(); i++)
         {
            __EntitiesInvolved.push_back( that.__EntitiesInvolved[i]);
         }
         __TimeTaskCompleted = that.__TimeTaskCompleted;

      }
      return *this;
   }

   TaskComplete* TaskComplete::clone() const
   {
        return new TaskComplete(*this);
   }
   
   TaskComplete::~TaskComplete(void)
   {

   }
  
   void TaskComplete::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putUShort( static_cast<uint16_t>(__EntitiesInvolved.size()));
      for (size_t i=0; i<__EntitiesInvolved.size(); i++)
      {
         buf.putLong(__EntitiesInvolved[i]);
      }
      buf.putLong(__TimeTaskCompleted);

   }
   
   void TaskComplete::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __EntitiesInvolved.clear();
      uint16_t __EntitiesInvolved_length = buf.getUShort();
      for (uint32_t i=0; i< __EntitiesInvolved_length; i++)
      {
         __EntitiesInvolved.push_back(buf.getLong() );
      }
      __TimeTaskCompleted = buf.getLong();

   }

   uint32_t TaskComplete::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __EntitiesInvolved.size();
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskComplete::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskComplete ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "EntitiesInvolved (int64 [ " << __EntitiesInvolved.size() << ", var ])\n";
      oss << indent << "TimeTaskCompleted (int64_t) = " << __TimeTaskCompleted << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskComplete::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskComplete Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <EntitiesInvolved>\n";
      for (size_t i=0; i<__EntitiesInvolved.size(); i++)
      {
         str << ws << "   <int64>" << __EntitiesInvolved[i] << "</int64>\n";
      }
      str << ws << "   </EntitiesInvolved>\n";
      str << ws << "   <TimeTaskCompleted>" << __TimeTaskCompleted << "</TimeTaskCompleted>\n";
      str << ws << "</TaskComplete>\n";

      return str.str();
   }

   bool TaskComplete::operator==(const TaskComplete & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__EntitiesInvolved.size() != that.__EntitiesInvolved.size()) return false;
      for (size_t i=0; i<__EntitiesInvolved.size(); i++)
      {
         if(__EntitiesInvolved[i] != that.__EntitiesInvolved[i]) return false;
      }
      if(__TimeTaskCompleted != that.__TimeTaskCompleted) return false;
      return true;

   }

   bool TaskComplete::operator!=(const TaskComplete & that)
   {
      return( !(operator==(that)) );
   }

   TaskComplete& TaskComplete::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }


   TaskComplete& TaskComplete::setTimeTaskCompleted(const int64_t val)
   {
      __TimeTaskCompleted = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

