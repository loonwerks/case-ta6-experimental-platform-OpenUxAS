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
#include "afrl/cmasi/SearchTask.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SearchTask::Subscription = "afrl.cmasi.SearchTask";
   const std::string SearchTask::TypeName = "SearchTask";
   const std::string SearchTask::SeriesName = "CMASI";
   const int64_t SearchTask::SeriesId = 4849604199710720000LL;
   const uint16_t SearchTask::SeriesVersion = 3;
   const uint32_t SearchTask::TypeId = 9;
   
   bool isSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   bool isSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   std::vector< std::string > SearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.impact.ImpactPointSearchTask");
       descendants.push_back("afrl.impact.PatternSearchTask");
       descendants.push_back("afrl.impact.AngledAreaSearchTask");
       descendants.push_back("afrl.impact.ImpactLineSearchTask");
       descendants.push_back("afrl.impact.WatchTask");
       descendants.push_back("afrl.impact.MultiVehicleWatchTask");
       descendants.push_back("afrl.impact.EscortTask");
       descendants.push_back("afrl.cmasi.AreaSearchTask");
       descendants.push_back("afrl.cmasi.LineSearchTask");
       descendants.push_back("afrl.cmasi.PointSearchTask");

       return descendants;
   }
   
   SearchTask::SearchTask(void) : afrl::cmasi::Task()
   {
      __DwellTime = 0LL;
      __GroundSampleDistance = 0.f;

   }
     
   SearchTask::SearchTask(const SearchTask &that) : afrl::cmasi::Task(that)
   {
        __DesiredWavelengthBands.clear();
        for (size_t i=0; i< that.__DesiredWavelengthBands.size(); i++)
        {
           __DesiredWavelengthBands.push_back( that.__DesiredWavelengthBands[i]);
        }
        __DwellTime = that.__DwellTime;
        __GroundSampleDistance = that.__GroundSampleDistance;

   }
   
   SearchTask & SearchTask::operator=(const SearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);

         __DesiredWavelengthBands.clear();
         for (size_t i=0; i< that.__DesiredWavelengthBands.size(); i++)
         {
            __DesiredWavelengthBands.push_back( that.__DesiredWavelengthBands[i]);
         }
         __DwellTime = that.__DwellTime;
         __GroundSampleDistance = that.__GroundSampleDistance;

      }
      return *this;
   }

   SearchTask* SearchTask::clone() const
   {
        return new SearchTask(*this);
   }
   
   SearchTask::~SearchTask(void)
   {

   }
  
   void SearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__DesiredWavelengthBands.size()));
      for (size_t i=0; i<__DesiredWavelengthBands.size(); i++)
      {
         buf.putInt( (int32_t) __DesiredWavelengthBands[i]);
      }
      buf.putLong(__DwellTime);
      buf.putFloat(__GroundSampleDistance);

   }
   
   void SearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      __DesiredWavelengthBands.clear();
      uint16_t __DesiredWavelengthBands_length = buf.getUShort();
      for (uint32_t i=0; i< __DesiredWavelengthBands_length; i++)
      {
         __DesiredWavelengthBands.push_back( (afrl::cmasi::WavelengthBand::WavelengthBand) buf.getInt() );
      }
      __DwellTime = buf.getLong();
      __GroundSampleDistance = buf.getFloat();

   }

   uint32_t SearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += 2 + sizeof(afrl::cmasi::WavelengthBand::WavelengthBand) * __DesiredWavelengthBands.size();
      size += sizeof(int64_t);
      size += sizeof(float);

      return size;
   }

   std::string SearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SearchTask ) {\n";
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

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SearchTask Series=\"CMASI\">\n";
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
      str << ws << "</SearchTask>\n";

      return str.str();
   }

   bool SearchTask::operator==(const SearchTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__DesiredWavelengthBands.size() != that.__DesiredWavelengthBands.size()) return false;
      for (size_t i=0; i<__DesiredWavelengthBands.size(); i++)
      {
         if(__DesiredWavelengthBands[i] != that.__DesiredWavelengthBands[i]) return false;
      }
      if(__DwellTime != that.__DwellTime) return false;
      if(__GroundSampleDistance != that.__GroundSampleDistance) return false;
      return true;

   }

   bool SearchTask::operator!=(const SearchTask & that)
   {
      return( !(operator==(that)) );
   }


   SearchTask& SearchTask::setDwellTime(const int64_t val)
   {
      __DwellTime = val;
      return *this;
   }

   SearchTask& SearchTask::setGroundSampleDistance(const float val)
   {
      __GroundSampleDistance = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

