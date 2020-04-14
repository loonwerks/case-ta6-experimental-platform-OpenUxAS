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
#include "uxas/messages/task/TaskProgressRequest.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskProgressRequest::Subscription = "uxas.messages.task.TaskProgressRequest";
   const std::string TaskProgressRequest::TypeName = "TaskProgressRequest";
   const std::string TaskProgressRequest::SeriesName = "UXTASK";
   const int64_t TaskProgressRequest::SeriesId = 6149757930721443840LL;
   const uint16_t TaskProgressRequest::SeriesVersion = 8;
   const uint32_t TaskProgressRequest::TypeId = 25;
   
   bool isTaskProgressRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   bool isTaskProgressRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   std::vector< std::string > TaskProgressRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskProgressRequest::TaskProgressRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __TaskID = 0LL;

   }
     
   TaskProgressRequest::TaskProgressRequest(const TaskProgressRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __TaskID = that.__TaskID;

   }
   
   TaskProgressRequest & TaskProgressRequest::operator=(const TaskProgressRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __RequestID = that.__RequestID;
         __TaskID = that.__TaskID;

      }
      return *this;
   }

   TaskProgressRequest* TaskProgressRequest::clone() const
   {
        return new TaskProgressRequest(*this);
   }
   
   TaskProgressRequest::~TaskProgressRequest(void)
   {

   }
  
   void TaskProgressRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putLong(__TaskID);

   }
   
   void TaskProgressRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      __TaskID = buf.getLong();

   }

   uint32_t TaskProgressRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskProgressRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskProgressRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskProgressRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskProgressRequest Series=\"UXTASK\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "</TaskProgressRequest>\n";

      return str.str();
   }

   bool TaskProgressRequest::operator==(const TaskProgressRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__TaskID != that.__TaskID) return false;
      return true;

   }

   bool TaskProgressRequest::operator!=(const TaskProgressRequest & that)
   {
      return( !(operator==(that)) );
   }

   TaskProgressRequest& TaskProgressRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   TaskProgressRequest& TaskProgressRequest::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

