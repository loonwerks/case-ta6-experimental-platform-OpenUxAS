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
#include "uxas/messages/task/TaskAssignment.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskAssignment::Subscription = "uxas.messages.task.TaskAssignment";
   const std::string TaskAssignment::TypeName = "TaskAssignment";
   const std::string TaskAssignment::SeriesName = "UXTASK";
   const int64_t TaskAssignment::SeriesId = 6149757930721443840LL;
   const uint16_t TaskAssignment::SeriesVersion = 8;
   const uint32_t TaskAssignment::TypeId = 18;
   
   bool isTaskAssignment(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   bool isTaskAssignment(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   std::vector< std::string > TaskAssignmentDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskAssignment::TaskAssignment(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __OptionID = 0LL;
      __AssignedVehicle = 0LL;
      __TimeThreshold = 0LL;
      __TimeTaskCompleted = 0LL;

   }
     
   TaskAssignment::TaskAssignment(const TaskAssignment &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __OptionID = that.__OptionID;
        __AssignedVehicle = that.__AssignedVehicle;
        __TimeThreshold = that.__TimeThreshold;
        __TimeTaskCompleted = that.__TimeTaskCompleted;

   }
   
   TaskAssignment & TaskAssignment::operator=(const TaskAssignment &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskID = that.__TaskID;
         __OptionID = that.__OptionID;
         __AssignedVehicle = that.__AssignedVehicle;
         __TimeThreshold = that.__TimeThreshold;
         __TimeTaskCompleted = that.__TimeTaskCompleted;

      }
      return *this;
   }

   TaskAssignment* TaskAssignment::clone() const
   {
        return new TaskAssignment(*this);
   }
   
   TaskAssignment::~TaskAssignment(void)
   {

   }
  
   void TaskAssignment::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putLong(__OptionID);
      buf.putLong(__AssignedVehicle);
      buf.putLong(__TimeThreshold);
      buf.putLong(__TimeTaskCompleted);

   }
   
   void TaskAssignment::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __OptionID = buf.getLong();
      __AssignedVehicle = buf.getLong();
      __TimeThreshold = buf.getLong();
      __TimeTaskCompleted = buf.getLong();

   }

   uint32_t TaskAssignment::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskAssignment::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskAssignment ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "OptionID (int64_t) = " << __OptionID << "\n";
      oss << indent << "AssignedVehicle (int64_t) = " << __AssignedVehicle << "\n";
      oss << indent << "TimeThreshold (int64_t) = " << __TimeThreshold << "\n";
      oss << indent << "TimeTaskCompleted (int64_t) = " << __TimeTaskCompleted << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskAssignment::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskAssignment Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <OptionID>" << __OptionID << "</OptionID>\n";
      str << ws << "   <AssignedVehicle>" << __AssignedVehicle << "</AssignedVehicle>\n";
      str << ws << "   <TimeThreshold>" << __TimeThreshold << "</TimeThreshold>\n";
      str << ws << "   <TimeTaskCompleted>" << __TimeTaskCompleted << "</TimeTaskCompleted>\n";
      str << ws << "</TaskAssignment>\n";

      return str.str();
   }

   bool TaskAssignment::operator==(const TaskAssignment & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__OptionID != that.__OptionID) return false;
      if(__AssignedVehicle != that.__AssignedVehicle) return false;
      if(__TimeThreshold != that.__TimeThreshold) return false;
      if(__TimeTaskCompleted != that.__TimeTaskCompleted) return false;
      return true;

   }

   bool TaskAssignment::operator!=(const TaskAssignment & that)
   {
      return( !(operator==(that)) );
   }

   TaskAssignment& TaskAssignment::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskAssignment& TaskAssignment::setOptionID(const int64_t val)
   {
      __OptionID = val;
      return *this;
   }

   TaskAssignment& TaskAssignment::setAssignedVehicle(const int64_t val)
   {
      __AssignedVehicle = val;
      return *this;
   }

   TaskAssignment& TaskAssignment::setTimeThreshold(const int64_t val)
   {
      __TimeThreshold = val;
      return *this;
   }

   TaskAssignment& TaskAssignment::setTimeTaskCompleted(const int64_t val)
   {
      __TimeTaskCompleted = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

