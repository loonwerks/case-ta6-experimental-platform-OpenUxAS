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
#include "uxas/messages/task/TaskImplementationRequest.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskImplementationRequest::Subscription = "uxas.messages.task.TaskImplementationRequest";
   const std::string TaskImplementationRequest::TypeName = "TaskImplementationRequest";
   const std::string TaskImplementationRequest::SeriesName = "UXTASK";
   const int64_t TaskImplementationRequest::SeriesId = 6149757930721443840LL;
   const uint16_t TaskImplementationRequest::SeriesVersion = 8;
   const uint32_t TaskImplementationRequest::TypeId = 14;
   
   bool isTaskImplementationRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   bool isTaskImplementationRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   std::vector< std::string > TaskImplementationRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskImplementationRequest::TaskImplementationRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __CorrespondingAutomationRequestID = 0LL;
      __StartingWaypointID = 0LL;
      __VehicleID = 0LL;
      __StartPosition = new afrl::cmasi::Location3D();
      __StartHeading = 0.f;
      __StartTime = 0LL;
      __RegionID = 0LL;
      __TaskID = 0LL;
      __OptionID = 0LL;
      __TimeThreshold = 0LL;

   }
     
   TaskImplementationRequest::TaskImplementationRequest(const TaskImplementationRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
        __StartingWaypointID = that.__StartingWaypointID;
        __VehicleID = that.__VehicleID;
        __StartPosition = that.__StartPosition == nullptr ? nullptr : that.__StartPosition->clone();
        __StartHeading = that.__StartHeading;
        __StartTime = that.__StartTime;
        __RegionID = that.__RegionID;
        __TaskID = that.__TaskID;
        __OptionID = that.__OptionID;
        __TimeThreshold = that.__TimeThreshold;
        __NeighborLocations.clear();
        for (size_t i=0; i< that.__NeighborLocations.size(); i++)
        {
           __NeighborLocations.push_back( that.__NeighborLocations[i] == nullptr ? nullptr : that.__NeighborLocations[i]->clone());
        }

   }
   
   TaskImplementationRequest & TaskImplementationRequest::operator=(const TaskImplementationRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__StartPosition != nullptr) delete __StartPosition;
         for (size_t i=0; i<__NeighborLocations.size(); i++)
         {
            if (__NeighborLocations[i] != nullptr) delete __NeighborLocations[i];
         }

         __RequestID = that.__RequestID;
         __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
         __StartingWaypointID = that.__StartingWaypointID;
         __VehicleID = that.__VehicleID;
         __StartPosition = that.__StartPosition == nullptr ? nullptr : that.__StartPosition->clone();
         __StartHeading = that.__StartHeading;
         __StartTime = that.__StartTime;
         __RegionID = that.__RegionID;
         __TaskID = that.__TaskID;
         __OptionID = that.__OptionID;
         __TimeThreshold = that.__TimeThreshold;
         __NeighborLocations.clear();
         for (size_t i=0; i< that.__NeighborLocations.size(); i++)
         {
            __NeighborLocations.push_back( that.__NeighborLocations[i] == nullptr ? nullptr : that.__NeighborLocations[i]->clone());
         }

      }
      return *this;
   }

   TaskImplementationRequest* TaskImplementationRequest::clone() const
   {
        return new TaskImplementationRequest(*this);
   }
   
   TaskImplementationRequest::~TaskImplementationRequest(void)
   {
      if (__StartPosition != nullptr) delete __StartPosition;
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         if (__NeighborLocations[i] != nullptr) delete __NeighborLocations[i];
      }

   }
  
   void TaskImplementationRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putLong(__CorrespondingAutomationRequestID);
      buf.putLong(__StartingWaypointID);
      buf.putLong(__VehicleID);
      assert(__StartPosition != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartPosition, buf);
      buf.putFloat(__StartHeading);
      buf.putLong(__StartTime);
      buf.putLong(__RegionID);
      buf.putLong(__TaskID);
      buf.putLong(__OptionID);
      buf.putLong(__TimeThreshold);
      buf.putUShort( static_cast<uint16_t>(__NeighborLocations.size()));
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         assert(__NeighborLocations[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __NeighborLocations[i], buf);
      }

   }
   
   void TaskImplementationRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      __CorrespondingAutomationRequestID = buf.getLong();
      __StartingWaypointID = buf.getLong();
      __VehicleID = buf.getLong();
      {
         if (__StartPosition != nullptr) delete __StartPosition;
         __StartPosition = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __StartPosition = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__StartPosition != nullptr) __StartPosition->unpack(buf);
            else assert(__StartPosition != nullptr);
         }
      }
      __StartHeading = buf.getFloat();
      __StartTime = buf.getLong();
      __RegionID = buf.getLong();
      __TaskID = buf.getLong();
      __OptionID = buf.getLong();
      __TimeThreshold = buf.getLong();
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         if (__NeighborLocations[i] != nullptr)
            delete __NeighborLocations[i];
      }
      __NeighborLocations.clear();
      uint16_t __NeighborLocations_length = buf.getUShort();
      for (uint32_t i=0; i< __NeighborLocations_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::PlanningState* e = (uxas::messages::task::PlanningState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __NeighborLocations.push_back(e);
         }
      }

   }

   uint32_t TaskImplementationRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += (__StartPosition != nullptr ? __StartPosition->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         if (__NeighborLocations[i] != nullptr)
         {
            size += __NeighborLocations[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string TaskImplementationRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskImplementationRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "CorrespondingAutomationRequestID (int64_t) = " << __CorrespondingAutomationRequestID << "\n";
      oss << indent << "StartingWaypointID (int64_t) = " << __StartingWaypointID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "StartPosition (Location3D)";
      if (__StartPosition == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "StartHeading (float) = " << __StartHeading << "\n";
      oss << indent << "StartTime (int64_t) = " << __StartTime << "\n";
      oss << indent << "RegionID (int64_t) = " << __RegionID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "OptionID (int64_t) = " << __OptionID << "\n";
      oss << indent << "TimeThreshold (int64_t) = " << __TimeThreshold << "\n";
      oss << indent << "NeighborLocations (PlanningState [ " << __NeighborLocations.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskImplementationRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskImplementationRequest Series=\"UXTASK\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <CorrespondingAutomationRequestID>" << __CorrespondingAutomationRequestID << "</CorrespondingAutomationRequestID>\n";
      str << ws << "   <StartingWaypointID>" << __StartingWaypointID << "</StartingWaypointID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      if (__StartPosition != nullptr)
      {
         str << ws << "   <StartPosition>";
         str << "\n" + __StartPosition->toXML(depth + 1) + ws + "   ";
         str << "</StartPosition>\n";
      }
      str << ws << "   <StartHeading>" << __StartHeading << "</StartHeading>\n";
      str << ws << "   <StartTime>" << __StartTime << "</StartTime>\n";
      str << ws << "   <RegionID>" << __RegionID << "</RegionID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <OptionID>" << __OptionID << "</OptionID>\n";
      str << ws << "   <TimeThreshold>" << __TimeThreshold << "</TimeThreshold>\n";
      str << ws << "   <NeighborLocations>\n";
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         str << (__NeighborLocations[i] == nullptr ? ( ws + "   <null/>\n") : (__NeighborLocations[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </NeighborLocations>\n";
      str << ws << "</TaskImplementationRequest>\n";

      return str.str();
   }

   bool TaskImplementationRequest::operator==(const TaskImplementationRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__CorrespondingAutomationRequestID != that.__CorrespondingAutomationRequestID) return false;
      if(__StartingWaypointID != that.__StartingWaypointID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__StartPosition && that.__StartPosition)
      {
         if(__StartPosition->getSeriesNameAsLong() != that.__StartPosition->getSeriesNameAsLong()) return false;
         if(__StartPosition->getSeriesVersion() != that.__StartPosition->getSeriesVersion()) return false;
         if(__StartPosition->getLmcpType() != that.__StartPosition->getLmcpType()) return false;
         if( *(__StartPosition) != *(that.__StartPosition) ) return false;
      }
      else if(__StartPosition != that.__StartPosition) return false;
      if(__StartHeading != that.__StartHeading) return false;
      if(__StartTime != that.__StartTime) return false;
      if(__RegionID != that.__RegionID) return false;
      if(__TaskID != that.__TaskID) return false;
      if(__OptionID != that.__OptionID) return false;
      if(__TimeThreshold != that.__TimeThreshold) return false;
      if(__NeighborLocations.size() != that.__NeighborLocations.size()) return false;
      for (size_t i=0; i<__NeighborLocations.size(); i++)
      {
         if(__NeighborLocations[i] && that.__NeighborLocations[i])
         {
            if(__NeighborLocations[i]->getSeriesNameAsLong() != that.__NeighborLocations[i]->getSeriesNameAsLong()) return false;
            if(__NeighborLocations[i]->getSeriesVersion() != that.__NeighborLocations[i]->getSeriesVersion()) return false;
            if(__NeighborLocations[i]->getLmcpType() != that.__NeighborLocations[i]->getLmcpType()) return false;
            if( *(__NeighborLocations[i]) != *(that.__NeighborLocations[i]) ) return false;
         }
         else if(__NeighborLocations[i] != that.__NeighborLocations[i]) return false;
      }
      return true;

   }

   bool TaskImplementationRequest::operator!=(const TaskImplementationRequest & that)
   {
      return( !(operator==(that)) );
   }

   TaskImplementationRequest& TaskImplementationRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setCorrespondingAutomationRequestID(const int64_t val)
   {
      __CorrespondingAutomationRequestID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setStartingWaypointID(const int64_t val)
   {
      __StartingWaypointID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setStartPosition(const afrl::cmasi::Location3D* const val)
   {
      if (__StartPosition != nullptr) { delete __StartPosition; __StartPosition = nullptr; }
      if (val != nullptr) { __StartPosition = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setStartHeading(const float val)
   {
      __StartHeading = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setStartTime(const int64_t val)
   {
      __StartTime = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setRegionID(const int64_t val)
   {
      __RegionID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setOptionID(const int64_t val)
   {
      __OptionID = val;
      return *this;
   }

   TaskImplementationRequest& TaskImplementationRequest::setTimeThreshold(const int64_t val)
   {
      __TimeThreshold = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

