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
#include "afrl/impact/BlockadeTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BlockadeTask::Subscription = "afrl.impact.BlockadeTask";
   const std::string BlockadeTask::TypeName = "BlockadeTask";
   const std::string BlockadeTask::SeriesName = "IMPACT";
   const int64_t BlockadeTask::SeriesId = 5281966179208134656LL;
   const uint16_t BlockadeTask::SeriesVersion = 14;
   const uint32_t BlockadeTask::TypeId = 30;
   
   bool isBlockadeTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 30) return false;
      return true;
   }
   
   bool isBlockadeTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 30) return false;
      return true;
   }
   
   std::vector< std::string > BlockadeTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BlockadeTask::BlockadeTask(void) : afrl::cmasi::Task()
   {
      __BlockedEntityID = 0LL;
      __StandoffDistance = 0.f;
      __NumberVehicles = 1;
      __ProtectedLocation = nullptr;

   }
     
   BlockadeTask::BlockadeTask(const BlockadeTask &that) : afrl::cmasi::Task(that)
   {
        __BlockedEntityID = that.__BlockedEntityID;
        __StandoffDistance = that.__StandoffDistance;
        __NumberVehicles = that.__NumberVehicles;
        __ProtectedLocation = that.__ProtectedLocation == nullptr ? nullptr : that.__ProtectedLocation->clone();

   }
   
   BlockadeTask & BlockadeTask::operator=(const BlockadeTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__ProtectedLocation != nullptr) delete __ProtectedLocation;

         __BlockedEntityID = that.__BlockedEntityID;
         __StandoffDistance = that.__StandoffDistance;
         __NumberVehicles = that.__NumberVehicles;
         __ProtectedLocation = that.__ProtectedLocation == nullptr ? nullptr : that.__ProtectedLocation->clone();

      }
      return *this;
   }

   BlockadeTask* BlockadeTask::clone() const
   {
        return new BlockadeTask(*this);
   }
   
   BlockadeTask::~BlockadeTask(void)
   {
      if (__ProtectedLocation != nullptr) delete __ProtectedLocation;

   }
  
   void BlockadeTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__BlockedEntityID);
      buf.putFloat(__StandoffDistance);
      buf.putByte(__NumberVehicles);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ProtectedLocation, buf);

   }
   
   void BlockadeTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      __BlockedEntityID = buf.getLong();
      __StandoffDistance = buf.getFloat();
      __NumberVehicles = buf.getByte();
      {
         if (__ProtectedLocation != nullptr) delete __ProtectedLocation;
         __ProtectedLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __ProtectedLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__ProtectedLocation != nullptr) __ProtectedLocation->unpack(buf);
         }
      }

   }

   uint32_t BlockadeTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(uint8_t);
      size += (__ProtectedLocation != nullptr ? __ProtectedLocation->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string BlockadeTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BlockadeTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "BlockedEntityID (int64_t) = " << __BlockedEntityID << "\n";
      oss << indent << "StandoffDistance (float) = " << __StandoffDistance << "\n";
      oss << indent << "NumberVehicles (uint8_t) = " << __NumberVehicles << "\n";
      oss << indent << "ProtectedLocation (Location3D)";
      if (__ProtectedLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BlockadeTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BlockadeTask Series=\"IMPACT\">\n";
      str << ws << "   <BlockedEntityID>" << __BlockedEntityID << "</BlockedEntityID>\n";
      str << ws << "   <StandoffDistance>" << __StandoffDistance << "</StandoffDistance>\n";
      str << ws << "   <NumberVehicles>" << (int32_t) __NumberVehicles << "</NumberVehicles>\n";
      if (__ProtectedLocation != nullptr)
      {
         str << ws << "   <ProtectedLocation>";
         str << "\n" + __ProtectedLocation->toXML(depth + 1) + ws + "   ";
         str << "</ProtectedLocation>\n";
      }
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      str << ws << "   <EligibleEntities>\n";
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         str << ws << "   <int64>" << __EligibleEntities[i] << "</int64>\n";
      }
      str << ws << "   </EligibleEntities>\n";
      str << ws << "   <RevisitRate>" << __RevisitRate << "</RevisitRate>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "   <Priority>" << (int32_t) __Priority << "</Priority>\n";
      str << ws << "   <Required>" << (__Required ? "true" : "false") << "</Required>\n";
      str << ws << "</BlockadeTask>\n";

      return str.str();
   }

   bool BlockadeTask::operator==(const BlockadeTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__BlockedEntityID != that.__BlockedEntityID) return false;
      if(__StandoffDistance != that.__StandoffDistance) return false;
      if(__NumberVehicles != that.__NumberVehicles) return false;
      if(__ProtectedLocation && that.__ProtectedLocation)
      {
         if(__ProtectedLocation->getSeriesNameAsLong() != that.__ProtectedLocation->getSeriesNameAsLong()) return false;
         if(__ProtectedLocation->getSeriesVersion() != that.__ProtectedLocation->getSeriesVersion()) return false;
         if(__ProtectedLocation->getLmcpType() != that.__ProtectedLocation->getLmcpType()) return false;
         if( *(__ProtectedLocation) != *(that.__ProtectedLocation) ) return false;
      }
      else if(__ProtectedLocation != that.__ProtectedLocation) return false;
      return true;

   }

   bool BlockadeTask::operator!=(const BlockadeTask & that)
   {
      return( !(operator==(that)) );
   }

   BlockadeTask& BlockadeTask::setBlockedEntityID(const int64_t val)
   {
      __BlockedEntityID = val;
      return *this;
   }

   BlockadeTask& BlockadeTask::setStandoffDistance(const float val)
   {
      __StandoffDistance = val;
      return *this;
   }

   BlockadeTask& BlockadeTask::setNumberVehicles(const uint8_t val)
   {
      __NumberVehicles = val;
      return *this;
   }

   BlockadeTask& BlockadeTask::setProtectedLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__ProtectedLocation != nullptr) { delete __ProtectedLocation; __ProtectedLocation = nullptr; }
      if (val != nullptr) { __ProtectedLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace impact
} // end namespace afrl

