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
#include "afrl/impact/CommRelayTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CommRelayTask::Subscription = "afrl.impact.CommRelayTask";
   const std::string CommRelayTask::TypeName = "CommRelayTask";
   const std::string CommRelayTask::SeriesName = "IMPACT";
   const int64_t CommRelayTask::SeriesId = 5281966179208134656LL;
   const uint16_t CommRelayTask::SeriesVersion = 14;
   const uint32_t CommRelayTask::TypeId = 28;
   
   bool isCommRelayTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   bool isCommRelayTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   std::vector< std::string > CommRelayTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CommRelayTask::CommRelayTask(void) : afrl::cmasi::Task()
   {
      __SupportedEntityID = 0LL;
      __DestinationLocation = nullptr;
      __TowerID = 0LL;

   }
     
   CommRelayTask::CommRelayTask(const CommRelayTask &that) : afrl::cmasi::Task(that)
   {
        __SupportedEntityID = that.__SupportedEntityID;
        __DestinationLocation = that.__DestinationLocation == nullptr ? nullptr : that.__DestinationLocation->clone();
        __TowerID = that.__TowerID;

   }
   
   CommRelayTask & CommRelayTask::operator=(const CommRelayTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__DestinationLocation != nullptr) delete __DestinationLocation;

         __SupportedEntityID = that.__SupportedEntityID;
         __DestinationLocation = that.__DestinationLocation == nullptr ? nullptr : that.__DestinationLocation->clone();
         __TowerID = that.__TowerID;

      }
      return *this;
   }

   CommRelayTask* CommRelayTask::clone() const
   {
        return new CommRelayTask(*this);
   }
   
   CommRelayTask::~CommRelayTask(void)
   {
      if (__DestinationLocation != nullptr) delete __DestinationLocation;

   }
  
   void CommRelayTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__SupportedEntityID);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __DestinationLocation, buf);
      buf.putLong(__TowerID);

   }
   
   void CommRelayTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      __SupportedEntityID = buf.getLong();
      {
         if (__DestinationLocation != nullptr) delete __DestinationLocation;
         __DestinationLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __DestinationLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__DestinationLocation != nullptr) __DestinationLocation->unpack(buf);
         }
      }
      __TowerID = buf.getLong();

   }

   uint32_t CommRelayTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__DestinationLocation != nullptr ? __DestinationLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(int64_t);

      return size;
   }

   std::string CommRelayTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CommRelayTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "SupportedEntityID (int64_t) = " << __SupportedEntityID << "\n";
      oss << indent << "DestinationLocation (Location3D)";
      if (__DestinationLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "TowerID (int64_t) = " << __TowerID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CommRelayTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CommRelayTask Series=\"IMPACT\">\n";
      str << ws << "   <SupportedEntityID>" << __SupportedEntityID << "</SupportedEntityID>\n";
      if (__DestinationLocation != nullptr)
      {
         str << ws << "   <DestinationLocation>";
         str << "\n" + __DestinationLocation->toXML(depth + 1) + ws + "   ";
         str << "</DestinationLocation>\n";
      }
      str << ws << "   <TowerID>" << __TowerID << "</TowerID>\n";
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
      str << ws << "</CommRelayTask>\n";

      return str.str();
   }

   bool CommRelayTask::operator==(const CommRelayTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__SupportedEntityID != that.__SupportedEntityID) return false;
      if(__DestinationLocation && that.__DestinationLocation)
      {
         if(__DestinationLocation->getSeriesNameAsLong() != that.__DestinationLocation->getSeriesNameAsLong()) return false;
         if(__DestinationLocation->getSeriesVersion() != that.__DestinationLocation->getSeriesVersion()) return false;
         if(__DestinationLocation->getLmcpType() != that.__DestinationLocation->getLmcpType()) return false;
         if( *(__DestinationLocation) != *(that.__DestinationLocation) ) return false;
      }
      else if(__DestinationLocation != that.__DestinationLocation) return false;
      if(__TowerID != that.__TowerID) return false;
      return true;

   }

   bool CommRelayTask::operator!=(const CommRelayTask & that)
   {
      return( !(operator==(that)) );
   }

   CommRelayTask& CommRelayTask::setSupportedEntityID(const int64_t val)
   {
      __SupportedEntityID = val;
      return *this;
   }

   CommRelayTask& CommRelayTask::setDestinationLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__DestinationLocation != nullptr) { delete __DestinationLocation; __DestinationLocation = nullptr; }
      if (val != nullptr) { __DestinationLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   CommRelayTask& CommRelayTask::setTowerID(const int64_t val)
   {
      __TowerID = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

