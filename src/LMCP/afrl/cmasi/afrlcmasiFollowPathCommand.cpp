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
#include "afrl/cmasi/FollowPathCommand.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FollowPathCommand::Subscription = "afrl.cmasi.FollowPathCommand";
   const std::string FollowPathCommand::TypeName = "FollowPathCommand";
   const std::string FollowPathCommand::SeriesName = "CMASI";
   const int64_t FollowPathCommand::SeriesId = 4849604199710720000LL;
   const uint16_t FollowPathCommand::SeriesVersion = 3;
   const uint32_t FollowPathCommand::TypeId = 56;
   
   bool isFollowPathCommand(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 56) return false;
      return true;
   }
   
   bool isFollowPathCommand(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 56) return false;
      return true;
   }
   
   std::vector< std::string > FollowPathCommandDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FollowPathCommand::FollowPathCommand(void) : afrl::cmasi::VehicleActionCommand()
   {
      __FirstWaypoint = 0LL;
      __StartTime = 0LL;
      __StopTime = 0LL;
      __RepeatMode = afrl::cmasi::TravelMode::SinglePass;

   }
     
   FollowPathCommand::FollowPathCommand(const FollowPathCommand &that) : afrl::cmasi::VehicleActionCommand(that)
   {
        __FirstWaypoint = that.__FirstWaypoint;
        __WaypointList.clear();
        for (size_t i=0; i< that.__WaypointList.size(); i++)
        {
           __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
        }
        __StartTime = that.__StartTime;
        __StopTime = that.__StopTime;
        __RepeatMode = that.__RepeatMode;

   }
   
   FollowPathCommand & FollowPathCommand::operator=(const FollowPathCommand &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleActionCommand::operator=(that);
         for (size_t i=0; i<__WaypointList.size(); i++)
         {
            if (__WaypointList[i] != nullptr) delete __WaypointList[i];
         }

         __FirstWaypoint = that.__FirstWaypoint;
         __WaypointList.clear();
         for (size_t i=0; i< that.__WaypointList.size(); i++)
         {
            __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
         }
         __StartTime = that.__StartTime;
         __StopTime = that.__StopTime;
         __RepeatMode = that.__RepeatMode;

      }
      return *this;
   }

   FollowPathCommand* FollowPathCommand::clone() const
   {
        return new FollowPathCommand(*this);
   }
   
   FollowPathCommand::~FollowPathCommand(void)
   {
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr) delete __WaypointList[i];
      }

   }
  
   void FollowPathCommand::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleActionCommand::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__FirstWaypoint);
      buf.putUShort( static_cast<uint16_t>(__WaypointList.size()));
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         assert(__WaypointList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __WaypointList[i], buf);
      }
      buf.putLong(__StartTime);
      buf.putLong(__StopTime);
      buf.putInt( (int32_t) __RepeatMode);

   }
   
   void FollowPathCommand::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleActionCommand::unpack(buf);
      // Copy the buffer into the class
      __FirstWaypoint = buf.getLong();
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr)
            delete __WaypointList[i];
      }
      __WaypointList.clear();
      uint16_t __WaypointList_length = buf.getUShort();
      for (uint32_t i=0; i< __WaypointList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::PathWaypoint* e = (afrl::cmasi::PathWaypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __WaypointList.push_back(e);
         }
      }
      __StartTime = buf.getLong();
      __StopTime = buf.getLong();
      __RepeatMode = (afrl::cmasi::TravelMode::TravelMode) buf.getInt();

   }

   uint32_t FollowPathCommand::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleActionCommand::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr)
         {
            size += __WaypointList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(afrl::cmasi::TravelMode::TravelMode);

      return size;
   }

   std::string FollowPathCommand::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FollowPathCommand ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CommandID (int64_t) = " << __CommandID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "VehicleActionList (VehicleAction [ " << __VehicleActionList.size() << ", var ])\n";
      oss << indent << "Status (CommandStatusType) = " << __Status << "\n";

      oss << indent << "FirstWaypoint (int64_t) = " << __FirstWaypoint << "\n";
      oss << indent << "WaypointList (PathWaypoint [ " << __WaypointList.size() << ", var ])\n";
      oss << indent << "StartTime (int64_t) = " << __StartTime << "\n";
      oss << indent << "StopTime (int64_t) = " << __StopTime << "\n";
      oss << indent << "RepeatMode (TravelMode) = " << __RepeatMode << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FollowPathCommand::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FollowPathCommand Series=\"CMASI\">\n";
      str << ws << "   <FirstWaypoint>" << __FirstWaypoint << "</FirstWaypoint>\n";
      str << ws << "   <WaypointList>\n";
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         str << (__WaypointList[i] == nullptr ? ( ws + "   <null/>\n") : (__WaypointList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </WaypointList>\n";
      str << ws << "   <StartTime>" << __StartTime << "</StartTime>\n";
      str << ws << "   <StopTime>" << __StopTime << "</StopTime>\n";
      str << ws << "   <RepeatMode>" << afrl::cmasi::TravelMode::get_string(__RepeatMode) << "</RepeatMode>\n";
      str << ws << "   <CommandID>" << __CommandID << "</CommandID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <VehicleActionList>\n";
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         str << (__VehicleActionList[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleActionList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleActionList>\n";
      str << ws << "   <Status>" << afrl::cmasi::CommandStatusType::get_string(__Status) << "</Status>\n";
      str << ws << "</FollowPathCommand>\n";

      return str.str();
   }

   bool FollowPathCommand::operator==(const FollowPathCommand & that)
   {
      if( afrl::cmasi::VehicleActionCommand::operator!=(that) )
      {
          return false;
      }
      if(__FirstWaypoint != that.__FirstWaypoint) return false;
      if(__WaypointList.size() != that.__WaypointList.size()) return false;
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if(__WaypointList[i] && that.__WaypointList[i])
         {
            if(__WaypointList[i]->getSeriesNameAsLong() != that.__WaypointList[i]->getSeriesNameAsLong()) return false;
            if(__WaypointList[i]->getSeriesVersion() != that.__WaypointList[i]->getSeriesVersion()) return false;
            if(__WaypointList[i]->getLmcpType() != that.__WaypointList[i]->getLmcpType()) return false;
            if( *(__WaypointList[i]) != *(that.__WaypointList[i]) ) return false;
         }
         else if(__WaypointList[i] != that.__WaypointList[i]) return false;
      }
      if(__StartTime != that.__StartTime) return false;
      if(__StopTime != that.__StopTime) return false;
      if(__RepeatMode != that.__RepeatMode) return false;
      return true;

   }

   bool FollowPathCommand::operator!=(const FollowPathCommand & that)
   {
      return( !(operator==(that)) );
   }

   FollowPathCommand& FollowPathCommand::setFirstWaypoint(const int64_t val)
   {
      __FirstWaypoint = val;
      return *this;
   }


   FollowPathCommand& FollowPathCommand::setStartTime(const int64_t val)
   {
      __StartTime = val;
      return *this;
   }

   FollowPathCommand& FollowPathCommand::setStopTime(const int64_t val)
   {
      __StopTime = val;
      return *this;
   }

   FollowPathCommand& FollowPathCommand::setRepeatMode(const afrl::cmasi::TravelMode::TravelMode val)
   {
      __RepeatMode = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

