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
#include "uxas/messages/task/TaskPause.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskPause::Subscription = "uxas.messages.task.TaskPause";
   const std::string TaskPause::TypeName = "TaskPause";
   const std::string TaskPause::SeriesName = "UXTASK";
   const int64_t TaskPause::SeriesId = 6149757930721443840LL;
   const uint16_t TaskPause::SeriesVersion = 8;
   const uint32_t TaskPause::TypeId = 22;
   
   bool isTaskPause(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   bool isTaskPause(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   std::vector< std::string > TaskPauseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskPause::TaskPause(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;

   }
     
   TaskPause::TaskPause(const TaskPause &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;

   }
   
   TaskPause & TaskPause::operator=(const TaskPause &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskID = that.__TaskID;

      }
      return *this;
   }

   TaskPause* TaskPause::clone() const
   {
        return new TaskPause(*this);
   }
   
   TaskPause::~TaskPause(void)
   {

   }
  
   void TaskPause::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);

   }
   
   void TaskPause::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();

   }

   uint32_t TaskPause::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskPause::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskPause ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskPause::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskPause Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "</TaskPause>\n";

      return str.str();
   }

   bool TaskPause::operator==(const TaskPause & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      return true;

   }

   bool TaskPause::operator!=(const TaskPause & that)
   {
      return( !(operator==(that)) );
   }

   TaskPause& TaskPause::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

