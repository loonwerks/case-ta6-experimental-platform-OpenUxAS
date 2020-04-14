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
#include "afrl/impact/PatternSearchTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PatternSearchTask::Subscription = "afrl.impact.PatternSearchTask";
   const std::string PatternSearchTask::TypeName = "PatternSearchTask";
   const std::string PatternSearchTask::SeriesName = "IMPACT";
   const int64_t PatternSearchTask::SeriesId = 5281966179208134656LL;
   const uint16_t PatternSearchTask::SeriesVersion = 14;
   const uint32_t PatternSearchTask::TypeId = 23;
   
   bool isPatternSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   bool isPatternSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   std::vector< std::string > PatternSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PatternSearchTask::PatternSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __SearchLocationID = 0LL;
      __SearchLocation = nullptr;
      __Pattern = afrl::impact::AreaSearchPattern::Spiral;
      __Extent = 0.0f;

   }
     
   PatternSearchTask::PatternSearchTask(const PatternSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __SearchLocationID = that.__SearchLocationID;
        __SearchLocation = that.__SearchLocation == nullptr ? nullptr : that.__SearchLocation->clone();
        __Pattern = that.__Pattern;
        __Extent = that.__Extent;

   }
   
   PatternSearchTask & PatternSearchTask::operator=(const PatternSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         if (__SearchLocation != nullptr) delete __SearchLocation;

         __SearchLocationID = that.__SearchLocationID;
         __SearchLocation = that.__SearchLocation == nullptr ? nullptr : that.__SearchLocation->clone();
         __Pattern = that.__Pattern;
         __Extent = that.__Extent;

      }
      return *this;
   }

   PatternSearchTask* PatternSearchTask::clone() const
   {
        return new PatternSearchTask(*this);
   }
   
   PatternSearchTask::~PatternSearchTask(void)
   {
      if (__SearchLocation != nullptr) delete __SearchLocation;

   }
  
   void PatternSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__SearchLocationID);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __SearchLocation, buf);
      buf.putInt( (int32_t) __Pattern);
      buf.putFloat(__Extent);

   }
   
   void PatternSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      __SearchLocationID = buf.getLong();
      {
         if (__SearchLocation != nullptr) delete __SearchLocation;
         __SearchLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __SearchLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__SearchLocation != nullptr) __SearchLocation->unpack(buf);
         }
      }
      __Pattern = (afrl::impact::AreaSearchPattern::AreaSearchPattern) buf.getInt();
      __Extent = buf.getFloat();

   }

   uint32_t PatternSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__SearchLocation != nullptr ? __SearchLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(afrl::impact::AreaSearchPattern::AreaSearchPattern);
      size += sizeof(float);

      return size;
   }

   std::string PatternSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PatternSearchTask ) {\n";
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

      oss << indent << "SearchLocationID (int64_t) = " << __SearchLocationID << "\n";
      oss << indent << "SearchLocation (Location3D)";
      if (__SearchLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Pattern (AreaSearchPattern) = " << __Pattern << "\n";
      oss << indent << "Extent (float) = " << __Extent << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PatternSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PatternSearchTask Series=\"IMPACT\">\n";
      str << ws << "   <SearchLocationID>" << __SearchLocationID << "</SearchLocationID>\n";
      if (__SearchLocation != nullptr)
      {
         str << ws << "   <SearchLocation>";
         str << "\n" + __SearchLocation->toXML(depth + 1) + ws + "   ";
         str << "</SearchLocation>\n";
      }
      str << ws << "   <Pattern>" << afrl::impact::AreaSearchPattern::get_string(__Pattern) << "</Pattern>\n";
      str << ws << "   <Extent>" << __Extent << "</Extent>\n";
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
      str << ws << "</PatternSearchTask>\n";

      return str.str();
   }

   bool PatternSearchTask::operator==(const PatternSearchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__SearchLocationID != that.__SearchLocationID) return false;
      if(__SearchLocation && that.__SearchLocation)
      {
         if(__SearchLocation->getSeriesNameAsLong() != that.__SearchLocation->getSeriesNameAsLong()) return false;
         if(__SearchLocation->getSeriesVersion() != that.__SearchLocation->getSeriesVersion()) return false;
         if(__SearchLocation->getLmcpType() != that.__SearchLocation->getLmcpType()) return false;
         if( *(__SearchLocation) != *(that.__SearchLocation) ) return false;
      }
      else if(__SearchLocation != that.__SearchLocation) return false;
      if(__Pattern != that.__Pattern) return false;
      if(__Extent != that.__Extent) return false;
      return true;

   }

   bool PatternSearchTask::operator!=(const PatternSearchTask & that)
   {
      return( !(operator==(that)) );
   }

   PatternSearchTask& PatternSearchTask::setSearchLocationID(const int64_t val)
   {
      __SearchLocationID = val;
      return *this;
   }

   PatternSearchTask& PatternSearchTask::setSearchLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__SearchLocation != nullptr) { delete __SearchLocation; __SearchLocation = nullptr; }
      if (val != nullptr) { __SearchLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   PatternSearchTask& PatternSearchTask::setPattern(const afrl::impact::AreaSearchPattern::AreaSearchPattern val)
   {
      __Pattern = val;
      return *this;
   }

   PatternSearchTask& PatternSearchTask::setExtent(const float val)
   {
      __Extent = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

