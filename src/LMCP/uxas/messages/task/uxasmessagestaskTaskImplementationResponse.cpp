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
#include "uxas/messages/task/TaskImplementationResponse.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskImplementationResponse::Subscription = "uxas.messages.task.TaskImplementationResponse";
   const std::string TaskImplementationResponse::TypeName = "TaskImplementationResponse";
   const std::string TaskImplementationResponse::SeriesName = "UXTASK";
   const int64_t TaskImplementationResponse::SeriesId = 6149757930721443840LL;
   const uint16_t TaskImplementationResponse::SeriesVersion = 8;
   const uint32_t TaskImplementationResponse::TypeId = 15;
   
   bool isTaskImplementationResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 15) return false;
      return true;
   }
   
   bool isTaskImplementationResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 15) return false;
      return true;
   }
   
   std::vector< std::string > TaskImplementationResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskImplementationResponse::TaskImplementationResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;
      __CorrespondingAutomationRequestID = 0LL;
      __TaskID = 0LL;
      __OptionID = 0LL;
      __VehicleID = 0LL;
      __FinalLocation = new afrl::cmasi::Location3D();
      __FinalHeading = 0.f;
      __FinalTime = 0LL;

   }
     
   TaskImplementationResponse::TaskImplementationResponse(const TaskImplementationResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
        __TaskID = that.__TaskID;
        __OptionID = that.__OptionID;
        __VehicleID = that.__VehicleID;
        __TaskWaypoints.clear();
        for (size_t i=0; i< that.__TaskWaypoints.size(); i++)
        {
           __TaskWaypoints.push_back( that.__TaskWaypoints[i] == nullptr ? nullptr : that.__TaskWaypoints[i]->clone());
        }
        __FinalLocation = that.__FinalLocation == nullptr ? nullptr : that.__FinalLocation->clone();
        __FinalHeading = that.__FinalHeading;
        __FinalTime = that.__FinalTime;

   }
   
   TaskImplementationResponse & TaskImplementationResponse::operator=(const TaskImplementationResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__TaskWaypoints.size(); i++)
         {
            if (__TaskWaypoints[i] != nullptr) delete __TaskWaypoints[i];
         }
         if (__FinalLocation != nullptr) delete __FinalLocation;

         __ResponseID = that.__ResponseID;
         __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
         __TaskID = that.__TaskID;
         __OptionID = that.__OptionID;
         __VehicleID = that.__VehicleID;
         __TaskWaypoints.clear();
         for (size_t i=0; i< that.__TaskWaypoints.size(); i++)
         {
            __TaskWaypoints.push_back( that.__TaskWaypoints[i] == nullptr ? nullptr : that.__TaskWaypoints[i]->clone());
         }
         __FinalLocation = that.__FinalLocation == nullptr ? nullptr : that.__FinalLocation->clone();
         __FinalHeading = that.__FinalHeading;
         __FinalTime = that.__FinalTime;

      }
      return *this;
   }

   TaskImplementationResponse* TaskImplementationResponse::clone() const
   {
        return new TaskImplementationResponse(*this);
   }
   
   TaskImplementationResponse::~TaskImplementationResponse(void)
   {
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         if (__TaskWaypoints[i] != nullptr) delete __TaskWaypoints[i];
      }
      if (__FinalLocation != nullptr) delete __FinalLocation;

   }
  
   void TaskImplementationResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putLong(__CorrespondingAutomationRequestID);
      buf.putLong(__TaskID);
      buf.putLong(__OptionID);
      buf.putLong(__VehicleID);
      buf.putUShort( static_cast<uint16_t>(__TaskWaypoints.size()));
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         assert(__TaskWaypoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __TaskWaypoints[i], buf);
      }
      assert(__FinalLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __FinalLocation, buf);
      buf.putFloat(__FinalHeading);
      buf.putLong(__FinalTime);

   }
   
   void TaskImplementationResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      __CorrespondingAutomationRequestID = buf.getLong();
      __TaskID = buf.getLong();
      __OptionID = buf.getLong();
      __VehicleID = buf.getLong();
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         if (__TaskWaypoints[i] != nullptr)
            delete __TaskWaypoints[i];
      }
      __TaskWaypoints.clear();
      uint16_t __TaskWaypoints_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskWaypoints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __TaskWaypoints.push_back(e);
         }
      }
      {
         if (__FinalLocation != nullptr) delete __FinalLocation;
         __FinalLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __FinalLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__FinalLocation != nullptr) __FinalLocation->unpack(buf);
            else assert(__FinalLocation != nullptr);
         }
      }
      __FinalHeading = buf.getFloat();
      __FinalTime = buf.getLong();

   }

   uint32_t TaskImplementationResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         if (__TaskWaypoints[i] != nullptr)
         {
            size += __TaskWaypoints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += (__FinalLocation != nullptr ? __FinalLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(int64_t);

      return size;
   }

   std::string TaskImplementationResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskImplementationResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "CorrespondingAutomationRequestID (int64_t) = " << __CorrespondingAutomationRequestID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "OptionID (int64_t) = " << __OptionID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "TaskWaypoints (Waypoint [ " << __TaskWaypoints.size() << ", var ])\n";
      oss << indent << "FinalLocation (Location3D)";
      if (__FinalLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "FinalHeading (float) = " << __FinalHeading << "\n";
      oss << indent << "FinalTime (int64_t) = " << __FinalTime << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskImplementationResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskImplementationResponse Series=\"UXTASK\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <CorrespondingAutomationRequestID>" << __CorrespondingAutomationRequestID << "</CorrespondingAutomationRequestID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <OptionID>" << __OptionID << "</OptionID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <TaskWaypoints>\n";
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         str << (__TaskWaypoints[i] == nullptr ? ( ws + "   <null/>\n") : (__TaskWaypoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </TaskWaypoints>\n";
      if (__FinalLocation != nullptr)
      {
         str << ws << "   <FinalLocation>";
         str << "\n" + __FinalLocation->toXML(depth + 1) + ws + "   ";
         str << "</FinalLocation>\n";
      }
      str << ws << "   <FinalHeading>" << __FinalHeading << "</FinalHeading>\n";
      str << ws << "   <FinalTime>" << __FinalTime << "</FinalTime>\n";
      str << ws << "</TaskImplementationResponse>\n";

      return str.str();
   }

   bool TaskImplementationResponse::operator==(const TaskImplementationResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__CorrespondingAutomationRequestID != that.__CorrespondingAutomationRequestID) return false;
      if(__TaskID != that.__TaskID) return false;
      if(__OptionID != that.__OptionID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__TaskWaypoints.size() != that.__TaskWaypoints.size()) return false;
      for (size_t i=0; i<__TaskWaypoints.size(); i++)
      {
         if(__TaskWaypoints[i] && that.__TaskWaypoints[i])
         {
            if(__TaskWaypoints[i]->getSeriesNameAsLong() != that.__TaskWaypoints[i]->getSeriesNameAsLong()) return false;
            if(__TaskWaypoints[i]->getSeriesVersion() != that.__TaskWaypoints[i]->getSeriesVersion()) return false;
            if(__TaskWaypoints[i]->getLmcpType() != that.__TaskWaypoints[i]->getLmcpType()) return false;
            if( *(__TaskWaypoints[i]) != *(that.__TaskWaypoints[i]) ) return false;
         }
         else if(__TaskWaypoints[i] != that.__TaskWaypoints[i]) return false;
      }
      if(__FinalLocation && that.__FinalLocation)
      {
         if(__FinalLocation->getSeriesNameAsLong() != that.__FinalLocation->getSeriesNameAsLong()) return false;
         if(__FinalLocation->getSeriesVersion() != that.__FinalLocation->getSeriesVersion()) return false;
         if(__FinalLocation->getLmcpType() != that.__FinalLocation->getLmcpType()) return false;
         if( *(__FinalLocation) != *(that.__FinalLocation) ) return false;
      }
      else if(__FinalLocation != that.__FinalLocation) return false;
      if(__FinalHeading != that.__FinalHeading) return false;
      if(__FinalTime != that.__FinalTime) return false;
      return true;

   }

   bool TaskImplementationResponse::operator!=(const TaskImplementationResponse & that)
   {
      return( !(operator==(that)) );
   }

   TaskImplementationResponse& TaskImplementationResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setCorrespondingAutomationRequestID(const int64_t val)
   {
      __CorrespondingAutomationRequestID = val;
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setOptionID(const int64_t val)
   {
      __OptionID = val;
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }


   TaskImplementationResponse& TaskImplementationResponse::setFinalLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__FinalLocation != nullptr) { delete __FinalLocation; __FinalLocation = nullptr; }
      if (val != nullptr) { __FinalLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setFinalHeading(const float val)
   {
      __FinalHeading = val;
      return *this;
   }

   TaskImplementationResponse& TaskImplementationResponse::setFinalTime(const int64_t val)
   {
      __FinalTime = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

