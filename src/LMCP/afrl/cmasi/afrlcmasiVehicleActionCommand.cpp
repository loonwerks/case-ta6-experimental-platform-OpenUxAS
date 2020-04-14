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
#include "afrl/cmasi/VehicleActionCommand.h"
#include "afrl/cmasi/PayloadAction.h"
#include "afrl/cmasi/CameraAction.h"
#include "afrl/cmasi/GimbalAngleAction.h"
#include "afrl/cmasi/GimbalScanAction.h"
#include "afrl/cmasi/GimbalStareAction.h"
#include "afrl/cmasi/NavigationAction.h"
#include "afrl/cmasi/GoToWaypointAction.h"
#include "afrl/cmasi/LoiterAction.h"
#include "afrl/cmasi/FlightDirectorAction.h"
#include "afrl/cmasi/VideoStreamAction.h"
#include "afrl/cmasi/StopMovementAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VehicleActionCommand::Subscription = "afrl.cmasi.VehicleActionCommand";
   const std::string VehicleActionCommand::TypeName = "VehicleActionCommand";
   const std::string VehicleActionCommand::SeriesName = "CMASI";
   const int64_t VehicleActionCommand::SeriesId = 4849604199710720000LL;
   const uint16_t VehicleActionCommand::SeriesVersion = 3;
   const uint32_t VehicleActionCommand::TypeId = 47;
   
   bool isVehicleActionCommand(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 47) return false;
      return true;
   }
   
   bool isVehicleActionCommand(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 47) return false;
      return true;
   }
   
   std::vector< std::string > VehicleActionCommandDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.MissionCommand");
       descendants.push_back("afrl.cmasi.FollowPathCommand");

       return descendants;
   }
   
   VehicleActionCommand::VehicleActionCommand(void) : avtas::lmcp::Object()
   {
      __CommandID = 0LL;
      __VehicleID = 0LL;
      __Status = afrl::cmasi::CommandStatusType::Pending;

   }
     
   VehicleActionCommand::VehicleActionCommand(const VehicleActionCommand &that) : avtas::lmcp::Object(that)
   {
        __CommandID = that.__CommandID;
        __VehicleID = that.__VehicleID;
        __VehicleActionList.clear();
        for (size_t i=0; i< that.__VehicleActionList.size(); i++)
        {
           __VehicleActionList.push_back( that.__VehicleActionList[i] == nullptr ? nullptr : that.__VehicleActionList[i]->clone());
        }
        __Status = that.__Status;

   }
   
   VehicleActionCommand & VehicleActionCommand::operator=(const VehicleActionCommand &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__VehicleActionList.size(); i++)
         {
            if (__VehicleActionList[i] != nullptr) delete __VehicleActionList[i];
         }

         __CommandID = that.__CommandID;
         __VehicleID = that.__VehicleID;
         __VehicleActionList.clear();
         for (size_t i=0; i< that.__VehicleActionList.size(); i++)
         {
            __VehicleActionList.push_back( that.__VehicleActionList[i] == nullptr ? nullptr : that.__VehicleActionList[i]->clone());
         }
         __Status = that.__Status;

      }
      return *this;
   }

   VehicleActionCommand* VehicleActionCommand::clone() const
   {
        return new VehicleActionCommand(*this);
   }
   
   VehicleActionCommand::~VehicleActionCommand(void)
   {
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr) delete __VehicleActionList[i];
      }

   }
  
   void VehicleActionCommand::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__CommandID);
      buf.putLong(__VehicleID);
      buf.putUShort( static_cast<uint16_t>(__VehicleActionList.size()));
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         assert(__VehicleActionList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __VehicleActionList[i], buf);
      }
      buf.putInt( (int32_t) __Status);

   }
   
   void VehicleActionCommand::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __CommandID = buf.getLong();
      __VehicleID = buf.getLong();
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr)
            delete __VehicleActionList[i];
      }
      __VehicleActionList.clear();
      uint16_t __VehicleActionList_length = buf.getUShort();
      for (uint32_t i=0; i< __VehicleActionList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::VehicleAction* e = (afrl::cmasi::VehicleAction*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __VehicleActionList.push_back(e);
         }
      }
      __Status = (afrl::cmasi::CommandStatusType::CommandStatusType) buf.getInt();

   }

   uint32_t VehicleActionCommand::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr)
         {
            size += __VehicleActionList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(afrl::cmasi::CommandStatusType::CommandStatusType);

      return size;
   }

   std::string VehicleActionCommand::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VehicleActionCommand ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CommandID (int64_t) = " << __CommandID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "VehicleActionList (VehicleAction [ " << __VehicleActionList.size() << ", var ])\n";
      oss << indent << "Status (CommandStatusType) = " << __Status << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VehicleActionCommand::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VehicleActionCommand Series=\"CMASI\">\n";
      str << ws << "   <CommandID>" << __CommandID << "</CommandID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <VehicleActionList>\n";
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         str << (__VehicleActionList[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleActionList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleActionList>\n";
      str << ws << "   <Status>" << afrl::cmasi::CommandStatusType::get_string(__Status) << "</Status>\n";
      str << ws << "</VehicleActionCommand>\n";

      return str.str();
   }

   bool VehicleActionCommand::operator==(const VehicleActionCommand & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__CommandID != that.__CommandID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__VehicleActionList.size() != that.__VehicleActionList.size()) return false;
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if(__VehicleActionList[i] && that.__VehicleActionList[i])
         {
            if(__VehicleActionList[i]->getSeriesNameAsLong() != that.__VehicleActionList[i]->getSeriesNameAsLong()) return false;
            if(__VehicleActionList[i]->getSeriesVersion() != that.__VehicleActionList[i]->getSeriesVersion()) return false;
            if(__VehicleActionList[i]->getLmcpType() != that.__VehicleActionList[i]->getLmcpType()) return false;
            if( *(__VehicleActionList[i]) != *(that.__VehicleActionList[i]) ) return false;
         }
         else if(__VehicleActionList[i] != that.__VehicleActionList[i]) return false;
      }
      if(__Status != that.__Status) return false;
      return true;

   }

   bool VehicleActionCommand::operator!=(const VehicleActionCommand & that)
   {
      return( !(operator==(that)) );
   }

   VehicleActionCommand& VehicleActionCommand::setCommandID(const int64_t val)
   {
      __CommandID = val;
      return *this;
   }

   VehicleActionCommand& VehicleActionCommand::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }


   VehicleActionCommand& VehicleActionCommand::setStatus(const afrl::cmasi::CommandStatusType::CommandStatusType val)
   {
      __Status = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

