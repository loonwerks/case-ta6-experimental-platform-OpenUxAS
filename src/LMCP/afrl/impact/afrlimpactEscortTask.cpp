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
#include "afrl/impact/EscortTask.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EscortTask::Subscription = "afrl.impact.EscortTask";
   const std::string EscortTask::TypeName = "EscortTask";
   const std::string EscortTask::SeriesName = "IMPACT";
   const int64_t EscortTask::SeriesId = 5281966179208134656LL;
   const uint16_t EscortTask::SeriesVersion = 14;
   const uint32_t EscortTask::TypeId = 31;
   
   bool isEscortTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 31) return false;
      return true;
   }
   
   bool isEscortTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 31) return false;
      return true;
   }
   
   std::vector< std::string > EscortTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   EscortTask::EscortTask(void) : afrl::cmasi::SearchTask()
   {
      __SupportedEntityID = 0LL;
      __RouteID = 0LL;
      __StandoffDistance = 100.f;

   }
     
   EscortTask::EscortTask(const EscortTask &that) : afrl::cmasi::SearchTask(that)
   {
        __SupportedEntityID = that.__SupportedEntityID;
        __RouteID = that.__RouteID;
        __PrescribedWaypoints.clear();
        for (size_t i=0; i< that.__PrescribedWaypoints.size(); i++)
        {
           __PrescribedWaypoints.push_back( that.__PrescribedWaypoints[i] == nullptr ? nullptr : that.__PrescribedWaypoints[i]->clone());
        }
        __StandoffDistance = that.__StandoffDistance;

   }
   
   EscortTask & EscortTask::operator=(const EscortTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
         {
            if (__PrescribedWaypoints[i] != nullptr) delete __PrescribedWaypoints[i];
         }

         __SupportedEntityID = that.__SupportedEntityID;
         __RouteID = that.__RouteID;
         __PrescribedWaypoints.clear();
         for (size_t i=0; i< that.__PrescribedWaypoints.size(); i++)
         {
            __PrescribedWaypoints.push_back( that.__PrescribedWaypoints[i] == nullptr ? nullptr : that.__PrescribedWaypoints[i]->clone());
         }
         __StandoffDistance = that.__StandoffDistance;

      }
      return *this;
   }

   EscortTask* EscortTask::clone() const
   {
        return new EscortTask(*this);
   }
   
   EscortTask::~EscortTask(void)
   {
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         if (__PrescribedWaypoints[i] != nullptr) delete __PrescribedWaypoints[i];
      }

   }
  
   void EscortTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__SupportedEntityID);
      buf.putLong(__RouteID);
      buf.putUShort( static_cast<uint16_t>(__PrescribedWaypoints.size()));
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         assert(__PrescribedWaypoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PrescribedWaypoints[i], buf);
      }
      buf.putFloat(__StandoffDistance);

   }
   
   void EscortTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      __SupportedEntityID = buf.getLong();
      __RouteID = buf.getLong();
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         if (__PrescribedWaypoints[i] != nullptr)
            delete __PrescribedWaypoints[i];
      }
      __PrescribedWaypoints.clear();
      uint16_t __PrescribedWaypoints_length = buf.getUShort();
      for (uint32_t i=0; i< __PrescribedWaypoints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PrescribedWaypoints.push_back(e);
         }
      }
      __StandoffDistance = buf.getFloat();

   }

   uint32_t EscortTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         if (__PrescribedWaypoints[i] != nullptr)
         {
            size += __PrescribedWaypoints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(float);

      return size;
   }

   std::string EscortTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EscortTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "DesiredWavelengthBands (WavelengthBand [ " << __DesiredWavelengthBands.size() << ", var ])\n";
      oss << indent << "DwellTime (int64_t) = " << __DwellTime << "\n";
      oss << indent << "GroundSampleDistance (float) = " << __GroundSampleDistance << "\n";

      oss << indent << "SupportedEntityID (int64_t) = " << __SupportedEntityID << "\n";
      oss << indent << "RouteID (int64_t) = " << __RouteID << "\n";
      oss << indent << "PrescribedWaypoints (Waypoint [ " << __PrescribedWaypoints.size() << ", var ])\n";
      oss << indent << "StandoffDistance (float) = " << __StandoffDistance << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EscortTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EscortTask Series=\"IMPACT\">\n";
      str << ws << "   <SupportedEntityID>" << __SupportedEntityID << "</SupportedEntityID>\n";
      str << ws << "   <RouteID>" << __RouteID << "</RouteID>\n";
      str << ws << "   <PrescribedWaypoints>\n";
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         str << (__PrescribedWaypoints[i] == nullptr ? ( ws + "   <null/>\n") : (__PrescribedWaypoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PrescribedWaypoints>\n";
      str << ws << "   <StandoffDistance>" << __StandoffDistance << "</StandoffDistance>\n";
      str << ws << "   <DesiredWavelengthBands>\n";
      for (size_t i=0; i<__DesiredWavelengthBands.size(); i++)
      {
         str << ws << "   <WavelengthBand>" << afrl::cmasi::WavelengthBand::get_string(__DesiredWavelengthBands[i]) << "</WavelengthBand>\n";
      }
      str << ws << "   </DesiredWavelengthBands>\n";
      str << ws << "   <DwellTime>" << __DwellTime << "</DwellTime>\n";
      str << ws << "   <GroundSampleDistance>" << __GroundSampleDistance << "</GroundSampleDistance>\n";
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
      str << ws << "</EscortTask>\n";

      return str.str();
   }

   bool EscortTask::operator==(const EscortTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__SupportedEntityID != that.__SupportedEntityID) return false;
      if(__RouteID != that.__RouteID) return false;
      if(__PrescribedWaypoints.size() != that.__PrescribedWaypoints.size()) return false;
      for (size_t i=0; i<__PrescribedWaypoints.size(); i++)
      {
         if(__PrescribedWaypoints[i] && that.__PrescribedWaypoints[i])
         {
            if(__PrescribedWaypoints[i]->getSeriesNameAsLong() != that.__PrescribedWaypoints[i]->getSeriesNameAsLong()) return false;
            if(__PrescribedWaypoints[i]->getSeriesVersion() != that.__PrescribedWaypoints[i]->getSeriesVersion()) return false;
            if(__PrescribedWaypoints[i]->getLmcpType() != that.__PrescribedWaypoints[i]->getLmcpType()) return false;
            if( *(__PrescribedWaypoints[i]) != *(that.__PrescribedWaypoints[i]) ) return false;
         }
         else if(__PrescribedWaypoints[i] != that.__PrescribedWaypoints[i]) return false;
      }
      if(__StandoffDistance != that.__StandoffDistance) return false;
      return true;

   }

   bool EscortTask::operator!=(const EscortTask & that)
   {
      return( !(operator==(that)) );
   }

   EscortTask& EscortTask::setSupportedEntityID(const int64_t val)
   {
      __SupportedEntityID = val;
      return *this;
   }

   EscortTask& EscortTask::setRouteID(const int64_t val)
   {
      __RouteID = val;
      return *this;
   }


   EscortTask& EscortTask::setStandoffDistance(const float val)
   {
      __StandoffDistance = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

