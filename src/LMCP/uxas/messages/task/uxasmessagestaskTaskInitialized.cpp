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
#include "uxas/messages/task/TaskInitialized.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskInitialized::Subscription = "uxas.messages.task.TaskInitialized";
   const std::string TaskInitialized::TypeName = "TaskInitialized";
   const std::string TaskInitialized::SeriesName = "UXTASK";
   const int64_t TaskInitialized::SeriesId = 6149757930721443840LL;
   const uint16_t TaskInitialized::SeriesVersion = 8;
   const uint32_t TaskInitialized::TypeId = 26;
   
   bool isTaskInitialized(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 26) return false;
      return true;
   }
   
   bool isTaskInitialized(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 26) return false;
      return true;
   }
   
   std::vector< std::string > TaskInitializedDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskInitialized::TaskInitialized(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;

   }
     
   TaskInitialized::TaskInitialized(const TaskInitialized &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;

   }
   
   TaskInitialized & TaskInitialized::operator=(const TaskInitialized &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskID = that.__TaskID;

      }
      return *this;
   }

   TaskInitialized* TaskInitialized::clone() const
   {
        return new TaskInitialized(*this);
   }
   
   TaskInitialized::~TaskInitialized(void)
   {

   }
  
   void TaskInitialized::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);

   }
   
   void TaskInitialized::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();

   }

   uint32_t TaskInitialized::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskInitialized::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskInitialized ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskInitialized::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskInitialized Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "</TaskInitialized>\n";

      return str.str();
   }

   bool TaskInitialized::operator==(const TaskInitialized & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      return true;

   }

   bool TaskInitialized::operator!=(const TaskInitialized & that)
   {
      return( !(operator==(that)) );
   }

   TaskInitialized& TaskInitialized::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

