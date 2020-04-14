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
#include "afrl/cmasi/MissionCommand.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string MissionCommand::Subscription = "afrl.cmasi.MissionCommand";
   const std::string MissionCommand::TypeName = "MissionCommand";
   const std::string MissionCommand::SeriesName = "CMASI";
   const int64_t MissionCommand::SeriesId = 4849604199710720000LL;
   const uint16_t MissionCommand::SeriesVersion = 3;
   const uint32_t MissionCommand::TypeId = 36;
   
   bool isMissionCommand(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 36) return false;
      return true;
   }
   
   bool isMissionCommand(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 36) return false;
      return true;
   }
   
   std::vector< std::string > MissionCommandDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   MissionCommand::MissionCommand(void) : afrl::cmasi::VehicleActionCommand()
   {
      __FirstWaypoint = 0LL;

   }
     
   MissionCommand::MissionCommand(const MissionCommand &that) : afrl::cmasi::VehicleActionCommand(that)
   {
        __WaypointList.clear();
        for (size_t i=0; i< that.__WaypointList.size(); i++)
        {
           __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
        }
        __FirstWaypoint = that.__FirstWaypoint;

   }
   
   MissionCommand & MissionCommand::operator=(const MissionCommand &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleActionCommand::operator=(that);
         for (size_t i=0; i<__WaypointList.size(); i++)
         {
            if (__WaypointList[i] != nullptr) delete __WaypointList[i];
         }

         __WaypointList.clear();
         for (size_t i=0; i< that.__WaypointList.size(); i++)
         {
            __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
         }
         __FirstWaypoint = that.__FirstWaypoint;

      }
      return *this;
   }

   MissionCommand* MissionCommand::clone() const
   {
        return new MissionCommand(*this);
   }
   
   MissionCommand::~MissionCommand(void)
   {
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr) delete __WaypointList[i];
      }

   }
  
   void MissionCommand::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleActionCommand::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__WaypointList.size()));
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         assert(__WaypointList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __WaypointList[i], buf);
      }
      buf.putLong(__FirstWaypoint);

   }
   
   void MissionCommand::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleActionCommand::unpack(buf);
      // Copy the buffer into the class
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
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __WaypointList.push_back(e);
         }
      }
      __FirstWaypoint = buf.getLong();

   }

   uint32_t MissionCommand::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleActionCommand::calculatePackedSize();
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

      return size;
   }

   std::string MissionCommand::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( MissionCommand ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CommandID (int64_t) = " << __CommandID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "VehicleActionList (VehicleAction [ " << __VehicleActionList.size() << ", var ])\n";
      oss << indent << "Status (CommandStatusType) = " << __Status << "\n";

      oss << indent << "WaypointList (Waypoint [ " << __WaypointList.size() << ", var ])\n";
      oss << indent << "FirstWaypoint (int64_t) = " << __FirstWaypoint << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string MissionCommand::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<MissionCommand Series=\"CMASI\">\n";
      str << ws << "   <WaypointList>\n";
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         str << (__WaypointList[i] == nullptr ? ( ws + "   <null/>\n") : (__WaypointList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </WaypointList>\n";
      str << ws << "   <FirstWaypoint>" << __FirstWaypoint << "</FirstWaypoint>\n";
      str << ws << "   <CommandID>" << __CommandID << "</CommandID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <VehicleActionList>\n";
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         str << (__VehicleActionList[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleActionList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleActionList>\n";
      str << ws << "   <Status>" << afrl::cmasi::CommandStatusType::get_string(__Status) << "</Status>\n";
      str << ws << "</MissionCommand>\n";

      return str.str();
   }

   bool MissionCommand::operator==(const MissionCommand & that)
   {
      if( afrl::cmasi::VehicleActionCommand::operator!=(that) )
      {
          return false;
      }
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
      if(__FirstWaypoint != that.__FirstWaypoint) return false;
      return true;

   }

   bool MissionCommand::operator!=(const MissionCommand & that)
   {
      return( !(operator==(that)) );
   }


   MissionCommand& MissionCommand::setFirstWaypoint(const int64_t val)
   {
      __FirstWaypoint = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

