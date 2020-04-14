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
#include "afrl/impact/CordonTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CordonTask::Subscription = "afrl.impact.CordonTask";
   const std::string CordonTask::TypeName = "CordonTask";
   const std::string CordonTask::SeriesName = "IMPACT";
   const int64_t CordonTask::SeriesId = 5281966179208134656LL;
   const uint16_t CordonTask::SeriesVersion = 14;
   const uint32_t CordonTask::TypeId = 29;
   
   bool isCordonTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 29) return false;
      return true;
   }
   
   bool isCordonTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 29) return false;
      return true;
   }
   
   std::vector< std::string > CordonTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CordonTask::CordonTask(void) : afrl::cmasi::Task()
   {
      __CordonLocation = new afrl::cmasi::Location3D();
      __StandoffDistance = 100.f;

   }
     
   CordonTask::CordonTask(const CordonTask &that) : afrl::cmasi::Task(that)
   {
        __CordonLocation = that.__CordonLocation == nullptr ? nullptr : that.__CordonLocation->clone();
        __StandoffDistance = that.__StandoffDistance;

   }
   
   CordonTask & CordonTask::operator=(const CordonTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__CordonLocation != nullptr) delete __CordonLocation;

         __CordonLocation = that.__CordonLocation == nullptr ? nullptr : that.__CordonLocation->clone();
         __StandoffDistance = that.__StandoffDistance;

      }
      return *this;
   }

   CordonTask* CordonTask::clone() const
   {
        return new CordonTask(*this);
   }
   
   CordonTask::~CordonTask(void)
   {
      if (__CordonLocation != nullptr) delete __CordonLocation;

   }
  
   void CordonTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      assert(__CordonLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __CordonLocation, buf);
      buf.putFloat(__StandoffDistance);

   }
   
   void CordonTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      {
         if (__CordonLocation != nullptr) delete __CordonLocation;
         __CordonLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __CordonLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__CordonLocation != nullptr) __CordonLocation->unpack(buf);
            else assert(__CordonLocation != nullptr);
         }
      }
      __StandoffDistance = buf.getFloat();

   }

   uint32_t CordonTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += (__CordonLocation != nullptr ? __CordonLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);

      return size;
   }

   std::string CordonTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CordonTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "CordonLocation (Location3D)";
      if (__CordonLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "StandoffDistance (float) = " << __StandoffDistance << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CordonTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CordonTask Series=\"IMPACT\">\n";
      if (__CordonLocation != nullptr)
      {
         str << ws << "   <CordonLocation>";
         str << "\n" + __CordonLocation->toXML(depth + 1) + ws + "   ";
         str << "</CordonLocation>\n";
      }
      str << ws << "   <StandoffDistance>" << __StandoffDistance << "</StandoffDistance>\n";
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
      str << ws << "</CordonTask>\n";

      return str.str();
   }

   bool CordonTask::operator==(const CordonTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__CordonLocation && that.__CordonLocation)
      {
         if(__CordonLocation->getSeriesNameAsLong() != that.__CordonLocation->getSeriesNameAsLong()) return false;
         if(__CordonLocation->getSeriesVersion() != that.__CordonLocation->getSeriesVersion()) return false;
         if(__CordonLocation->getLmcpType() != that.__CordonLocation->getLmcpType()) return false;
         if( *(__CordonLocation) != *(that.__CordonLocation) ) return false;
      }
      else if(__CordonLocation != that.__CordonLocation) return false;
      if(__StandoffDistance != that.__StandoffDistance) return false;
      return true;

   }

   bool CordonTask::operator!=(const CordonTask & that)
   {
      return( !(operator==(that)) );
   }

   CordonTask& CordonTask::setCordonLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__CordonLocation != nullptr) { delete __CordonLocation; __CordonLocation = nullptr; }
      if (val != nullptr) { __CordonLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   CordonTask& CordonTask::setStandoffDistance(const float val)
   {
      __StandoffDistance = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

