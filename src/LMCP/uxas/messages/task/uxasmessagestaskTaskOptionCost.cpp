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
#include "uxas/messages/task/TaskOptionCost.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskOptionCost::Subscription = "uxas.messages.task.TaskOptionCost";
   const std::string TaskOptionCost::TypeName = "TaskOptionCost";
   const std::string TaskOptionCost::SeriesName = "UXTASK";
   const int64_t TaskOptionCost::SeriesId = 6149757930721443840LL;
   const uint16_t TaskOptionCost::SeriesVersion = 8;
   const uint32_t TaskOptionCost::TypeId = 17;
   
   bool isTaskOptionCost(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   bool isTaskOptionCost(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   std::vector< std::string > TaskOptionCostDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskOptionCost::TaskOptionCost(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __IntialTaskID = 0LL;
      __IntialTaskOption = 0LL;
      __DestinationTaskID = 0LL;
      __DestinationTaskOption = 0LL;
      __TimeToGo = 0LL;

   }
     
   TaskOptionCost::TaskOptionCost(const TaskOptionCost &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __IntialTaskID = that.__IntialTaskID;
        __IntialTaskOption = that.__IntialTaskOption;
        __DestinationTaskID = that.__DestinationTaskID;
        __DestinationTaskOption = that.__DestinationTaskOption;
        __TimeToGo = that.__TimeToGo;

   }
   
   TaskOptionCost & TaskOptionCost::operator=(const TaskOptionCost &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;
         __IntialTaskID = that.__IntialTaskID;
         __IntialTaskOption = that.__IntialTaskOption;
         __DestinationTaskID = that.__DestinationTaskID;
         __DestinationTaskOption = that.__DestinationTaskOption;
         __TimeToGo = that.__TimeToGo;

      }
      return *this;
   }

   TaskOptionCost* TaskOptionCost::clone() const
   {
        return new TaskOptionCost(*this);
   }
   
   TaskOptionCost::~TaskOptionCost(void)
   {

   }
  
   void TaskOptionCost::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__IntialTaskID);
      buf.putLong(__IntialTaskOption);
      buf.putLong(__DestinationTaskID);
      buf.putLong(__DestinationTaskOption);
      buf.putLong(__TimeToGo);

   }
   
   void TaskOptionCost::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __IntialTaskID = buf.getLong();
      __IntialTaskOption = buf.getLong();
      __DestinationTaskID = buf.getLong();
      __DestinationTaskOption = buf.getLong();
      __TimeToGo = buf.getLong();

   }

   uint32_t TaskOptionCost::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskOptionCost::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskOptionCost ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "IntialTaskID (int64_t) = " << __IntialTaskID << "\n";
      oss << indent << "IntialTaskOption (int64_t) = " << __IntialTaskOption << "\n";
      oss << indent << "DestinationTaskID (int64_t) = " << __DestinationTaskID << "\n";
      oss << indent << "DestinationTaskOption (int64_t) = " << __DestinationTaskOption << "\n";
      oss << indent << "TimeToGo (int64_t) = " << __TimeToGo << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskOptionCost::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskOptionCost Series=\"UXTASK\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <IntialTaskID>" << __IntialTaskID << "</IntialTaskID>\n";
      str << ws << "   <IntialTaskOption>" << __IntialTaskOption << "</IntialTaskOption>\n";
      str << ws << "   <DestinationTaskID>" << __DestinationTaskID << "</DestinationTaskID>\n";
      str << ws << "   <DestinationTaskOption>" << __DestinationTaskOption << "</DestinationTaskOption>\n";
      str << ws << "   <TimeToGo>" << __TimeToGo << "</TimeToGo>\n";
      str << ws << "</TaskOptionCost>\n";

      return str.str();
   }

   bool TaskOptionCost::operator==(const TaskOptionCost & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__IntialTaskID != that.__IntialTaskID) return false;
      if(__IntialTaskOption != that.__IntialTaskOption) return false;
      if(__DestinationTaskID != that.__DestinationTaskID) return false;
      if(__DestinationTaskOption != that.__DestinationTaskOption) return false;
      if(__TimeToGo != that.__TimeToGo) return false;
      return true;

   }

   bool TaskOptionCost::operator!=(const TaskOptionCost & that)
   {
      return( !(operator==(that)) );
   }

   TaskOptionCost& TaskOptionCost::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   TaskOptionCost& TaskOptionCost::setIntialTaskID(const int64_t val)
   {
      __IntialTaskID = val;
      return *this;
   }

   TaskOptionCost& TaskOptionCost::setIntialTaskOption(const int64_t val)
   {
      __IntialTaskOption = val;
      return *this;
   }

   TaskOptionCost& TaskOptionCost::setDestinationTaskID(const int64_t val)
   {
      __DestinationTaskID = val;
      return *this;
   }

   TaskOptionCost& TaskOptionCost::setDestinationTaskOption(const int64_t val)
   {
      __DestinationTaskOption = val;
      return *this;
   }

   TaskOptionCost& TaskOptionCost::setTimeToGo(const int64_t val)
   {
      __TimeToGo = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

