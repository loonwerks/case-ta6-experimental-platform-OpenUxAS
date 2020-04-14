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
#include "uxas/messages/task/TaskActive.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskActive::Subscription = "uxas.messages.task.TaskActive";
   const std::string TaskActive::TypeName = "TaskActive";
   const std::string TaskActive::SeriesName = "UXTASK";
   const int64_t TaskActive::SeriesId = 6149757930721443840LL;
   const uint16_t TaskActive::SeriesVersion = 8;
   const uint32_t TaskActive::TypeId = 27;
   
   bool isTaskActive(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   bool isTaskActive(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   std::vector< std::string > TaskActiveDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskActive::TaskActive(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __EntityID = 0LL;
      __TimeTaskActivated = 0LL;

   }
     
   TaskActive::TaskActive(const TaskActive &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __EntityID = that.__EntityID;
        __TimeTaskActivated = that.__TimeTaskActivated;

   }
   
   TaskActive & TaskActive::operator=(const TaskActive &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskID = that.__TaskID;
         __EntityID = that.__EntityID;
         __TimeTaskActivated = that.__TimeTaskActivated;

      }
      return *this;
   }

   TaskActive* TaskActive::clone() const
   {
        return new TaskActive(*this);
   }
   
   TaskActive::~TaskActive(void)
   {

   }
  
   void TaskActive::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putLong(__EntityID);
      buf.putLong(__TimeTaskActivated);

   }
   
   void TaskActive::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __EntityID = buf.getLong();
      __TimeTaskActivated = buf.getLong();

   }

   uint32_t TaskActive::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskActive::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskActive ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "TimeTaskActivated (int64_t) = " << __TimeTaskActivated << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskActive::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskActive Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <TimeTaskActivated>" << __TimeTaskActivated << "</TimeTaskActivated>\n";
      str << ws << "</TaskActive>\n";

      return str.str();
   }

   bool TaskActive::operator==(const TaskActive & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__EntityID != that.__EntityID) return false;
      if(__TimeTaskActivated != that.__TimeTaskActivated) return false;
      return true;

   }

   bool TaskActive::operator!=(const TaskActive & that)
   {
      return( !(operator==(that)) );
   }

   TaskActive& TaskActive::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskActive& TaskActive::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }

   TaskActive& TaskActive::setTimeTaskActivated(const int64_t val)
   {
      __TimeTaskActivated = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

