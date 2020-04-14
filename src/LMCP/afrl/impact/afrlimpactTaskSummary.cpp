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
#include "afrl/impact/TaskSummary.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskSummary::Subscription = "afrl.impact.TaskSummary";
   const std::string TaskSummary::TypeName = "TaskSummary";
   const std::string TaskSummary::SeriesName = "IMPACT";
   const int64_t TaskSummary::SeriesId = 5281966179208134656LL;
   const uint16_t TaskSummary::SeriesVersion = 14;
   const uint32_t TaskSummary::TypeId = 14;
   
   bool isTaskSummary(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   bool isTaskSummary(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   std::vector< std::string > TaskSummaryDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskSummary::TaskSummary(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __BestEffort = 100.0f;

   }
     
   TaskSummary::TaskSummary(const TaskSummary &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __PerformingVehicles.clear();
        for (size_t i=0; i< that.__PerformingVehicles.size(); i++)
        {
           __PerformingVehicles.push_back( that.__PerformingVehicles[i] == nullptr ? nullptr : that.__PerformingVehicles[i]->clone());
        }
        __BestEffort = that.__BestEffort;

   }
   
   TaskSummary & TaskSummary::operator=(const TaskSummary &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__PerformingVehicles.size(); i++)
         {
            if (__PerformingVehicles[i] != nullptr) delete __PerformingVehicles[i];
         }

         __TaskID = that.__TaskID;
         __PerformingVehicles.clear();
         for (size_t i=0; i< that.__PerformingVehicles.size(); i++)
         {
            __PerformingVehicles.push_back( that.__PerformingVehicles[i] == nullptr ? nullptr : that.__PerformingVehicles[i]->clone());
         }
         __BestEffort = that.__BestEffort;

      }
      return *this;
   }

   TaskSummary* TaskSummary::clone() const
   {
        return new TaskSummary(*this);
   }
   
   TaskSummary::~TaskSummary(void)
   {
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         if (__PerformingVehicles[i] != nullptr) delete __PerformingVehicles[i];
      }

   }
  
   void TaskSummary::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putUShort( static_cast<uint16_t>(__PerformingVehicles.size()));
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         assert(__PerformingVehicles[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PerformingVehicles[i], buf);
      }
      buf.putFloat(__BestEffort);

   }
   
   void TaskSummary::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         if (__PerformingVehicles[i] != nullptr)
            delete __PerformingVehicles[i];
      }
      __PerformingVehicles.clear();
      uint16_t __PerformingVehicles_length = buf.getUShort();
      for (uint32_t i=0; i< __PerformingVehicles_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::VehicleSummary* e = (afrl::impact::VehicleSummary*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PerformingVehicles.push_back(e);
         }
      }
      __BestEffort = buf.getFloat();

   }

   uint32_t TaskSummary::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         if (__PerformingVehicles[i] != nullptr)
         {
            size += __PerformingVehicles[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(float);

      return size;
   }

   std::string TaskSummary::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskSummary ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "PerformingVehicles (VehicleSummary [ " << __PerformingVehicles.size() << ", var ])\n";
      oss << indent << "BestEffort (float) = " << __BestEffort << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskSummary::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskSummary Series=\"IMPACT\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <PerformingVehicles>\n";
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         str << (__PerformingVehicles[i] == nullptr ? ( ws + "   <null/>\n") : (__PerformingVehicles[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PerformingVehicles>\n";
      str << ws << "   <BestEffort>" << __BestEffort << "</BestEffort>\n";
      str << ws << "</TaskSummary>\n";

      return str.str();
   }

   bool TaskSummary::operator==(const TaskSummary & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__PerformingVehicles.size() != that.__PerformingVehicles.size()) return false;
      for (size_t i=0; i<__PerformingVehicles.size(); i++)
      {
         if(__PerformingVehicles[i] && that.__PerformingVehicles[i])
         {
            if(__PerformingVehicles[i]->getSeriesNameAsLong() != that.__PerformingVehicles[i]->getSeriesNameAsLong()) return false;
            if(__PerformingVehicles[i]->getSeriesVersion() != that.__PerformingVehicles[i]->getSeriesVersion()) return false;
            if(__PerformingVehicles[i]->getLmcpType() != that.__PerformingVehicles[i]->getLmcpType()) return false;
            if( *(__PerformingVehicles[i]) != *(that.__PerformingVehicles[i]) ) return false;
         }
         else if(__PerformingVehicles[i] != that.__PerformingVehicles[i]) return false;
      }
      if(__BestEffort != that.__BestEffort) return false;
      return true;

   }

   bool TaskSummary::operator!=(const TaskSummary & that)
   {
      return( !(operator==(that)) );
   }

   TaskSummary& TaskSummary::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }


   TaskSummary& TaskSummary::setBestEffort(const float val)
   {
      __BestEffort = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

