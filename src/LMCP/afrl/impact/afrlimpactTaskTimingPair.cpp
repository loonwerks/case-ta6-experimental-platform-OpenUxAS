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
#include "afrl/impact/TaskTimingPair.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskTimingPair::Subscription = "afrl.impact.TaskTimingPair";
   const std::string TaskTimingPair::TypeName = "TaskTimingPair";
   const std::string TaskTimingPair::SeriesName = "IMPACT";
   const int64_t TaskTimingPair::SeriesId = 5281966179208134656LL;
   const uint16_t TaskTimingPair::SeriesVersion = 14;
   const uint32_t TaskTimingPair::TypeId = 11;
   
   bool isTaskTimingPair(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   bool isTaskTimingPair(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   std::vector< std::string > TaskTimingPairDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskTimingPair::TaskTimingPair(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __InitialTaskID = 0LL;
      __InitialTaskPercentage = 0.f;
      __DestinationTaskID = 0LL;
      __TimeToGo = 0LL;

   }
     
   TaskTimingPair::TaskTimingPair(const TaskTimingPair &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __InitialTaskID = that.__InitialTaskID;
        __InitialTaskPercentage = that.__InitialTaskPercentage;
        __DestinationTaskID = that.__DestinationTaskID;
        __TimeToGo = that.__TimeToGo;

   }
   
   TaskTimingPair & TaskTimingPair::operator=(const TaskTimingPair &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;
         __InitialTaskID = that.__InitialTaskID;
         __InitialTaskPercentage = that.__InitialTaskPercentage;
         __DestinationTaskID = that.__DestinationTaskID;
         __TimeToGo = that.__TimeToGo;

      }
      return *this;
   }

   TaskTimingPair* TaskTimingPair::clone() const
   {
        return new TaskTimingPair(*this);
   }
   
   TaskTimingPair::~TaskTimingPair(void)
   {

   }
  
   void TaskTimingPair::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__InitialTaskID);
      buf.putFloat(__InitialTaskPercentage);
      buf.putLong(__DestinationTaskID);
      buf.putLong(__TimeToGo);

   }
   
   void TaskTimingPair::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __InitialTaskID = buf.getLong();
      __InitialTaskPercentage = buf.getFloat();
      __DestinationTaskID = buf.getLong();
      __TimeToGo = buf.getLong();

   }

   uint32_t TaskTimingPair::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskTimingPair::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskTimingPair ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "InitialTaskID (int64_t) = " << __InitialTaskID << "\n";
      oss << indent << "InitialTaskPercentage (float) = " << __InitialTaskPercentage << "\n";
      oss << indent << "DestinationTaskID (int64_t) = " << __DestinationTaskID << "\n";
      oss << indent << "TimeToGo (int64_t) = " << __TimeToGo << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskTimingPair::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskTimingPair Series=\"IMPACT\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <InitialTaskID>" << __InitialTaskID << "</InitialTaskID>\n";
      str << ws << "   <InitialTaskPercentage>" << __InitialTaskPercentage << "</InitialTaskPercentage>\n";
      str << ws << "   <DestinationTaskID>" << __DestinationTaskID << "</DestinationTaskID>\n";
      str << ws << "   <TimeToGo>" << __TimeToGo << "</TimeToGo>\n";
      str << ws << "</TaskTimingPair>\n";

      return str.str();
   }

   bool TaskTimingPair::operator==(const TaskTimingPair & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__InitialTaskID != that.__InitialTaskID) return false;
      if(__InitialTaskPercentage != that.__InitialTaskPercentage) return false;
      if(__DestinationTaskID != that.__DestinationTaskID) return false;
      if(__TimeToGo != that.__TimeToGo) return false;
      return true;

   }

   bool TaskTimingPair::operator!=(const TaskTimingPair & that)
   {
      return( !(operator==(that)) );
   }

   TaskTimingPair& TaskTimingPair::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   TaskTimingPair& TaskTimingPair::setInitialTaskID(const int64_t val)
   {
      __InitialTaskID = val;
      return *this;
   }

   TaskTimingPair& TaskTimingPair::setInitialTaskPercentage(const float val)
   {
      __InitialTaskPercentage = val;
      return *this;
   }

   TaskTimingPair& TaskTimingPair::setDestinationTaskID(const int64_t val)
   {
      __DestinationTaskID = val;
      return *this;
   }

   TaskTimingPair& TaskTimingPair::setTimeToGo(const int64_t val)
   {
      __TimeToGo = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

