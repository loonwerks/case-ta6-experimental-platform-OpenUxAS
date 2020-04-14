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
#include "afrl/impact/AngledAreaSearchTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AngledAreaSearchTask::Subscription = "afrl.impact.AngledAreaSearchTask";
   const std::string AngledAreaSearchTask::TypeName = "AngledAreaSearchTask";
   const std::string AngledAreaSearchTask::SeriesName = "IMPACT";
   const int64_t AngledAreaSearchTask::SeriesId = 5281966179208134656LL;
   const uint16_t AngledAreaSearchTask::SeriesVersion = 14;
   const uint32_t AngledAreaSearchTask::TypeId = 24;
   
   bool isAngledAreaSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   bool isAngledAreaSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   std::vector< std::string > AngledAreaSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AngledAreaSearchTask::AngledAreaSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __SearchAreaID = 0LL;
      __SweepAngle = 0.f;
      __StartPoint = nullptr;

   }
     
   AngledAreaSearchTask::AngledAreaSearchTask(const AngledAreaSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __SearchAreaID = that.__SearchAreaID;
        __SweepAngle = that.__SweepAngle;
        __StartPoint = that.__StartPoint == nullptr ? nullptr : that.__StartPoint->clone();

   }
   
   AngledAreaSearchTask & AngledAreaSearchTask::operator=(const AngledAreaSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         if (__StartPoint != nullptr) delete __StartPoint;

         __SearchAreaID = that.__SearchAreaID;
         __SweepAngle = that.__SweepAngle;
         __StartPoint = that.__StartPoint == nullptr ? nullptr : that.__StartPoint->clone();

      }
      return *this;
   }

   AngledAreaSearchTask* AngledAreaSearchTask::clone() const
   {
        return new AngledAreaSearchTask(*this);
   }
   
   AngledAreaSearchTask::~AngledAreaSearchTask(void)
   {
      if (__StartPoint != nullptr) delete __StartPoint;

   }
  
   void AngledAreaSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__SearchAreaID);
      buf.putFloat(__SweepAngle);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartPoint, buf);

   }
   
   void AngledAreaSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      __SearchAreaID = buf.getLong();
      __SweepAngle = buf.getFloat();
      {
         if (__StartPoint != nullptr) delete __StartPoint;
         __StartPoint = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __StartPoint = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__StartPoint != nullptr) __StartPoint->unpack(buf);
         }
      }

   }

   uint32_t AngledAreaSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += (__StartPoint != nullptr ? __StartPoint->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string AngledAreaSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AngledAreaSearchTask ) {\n";
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

      oss << indent << "SearchAreaID (int64_t) = " << __SearchAreaID << "\n";
      oss << indent << "SweepAngle (float) = " << __SweepAngle << "\n";
      oss << indent << "StartPoint (Location3D)";
      if (__StartPoint == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AngledAreaSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AngledAreaSearchTask Series=\"IMPACT\">\n";
      str << ws << "   <SearchAreaID>" << __SearchAreaID << "</SearchAreaID>\n";
      str << ws << "   <SweepAngle>" << __SweepAngle << "</SweepAngle>\n";
      if (__StartPoint != nullptr)
      {
         str << ws << "   <StartPoint>";
         str << "\n" + __StartPoint->toXML(depth + 1) + ws + "   ";
         str << "</StartPoint>\n";
      }
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
      str << ws << "</AngledAreaSearchTask>\n";

      return str.str();
   }

   bool AngledAreaSearchTask::operator==(const AngledAreaSearchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__SearchAreaID != that.__SearchAreaID) return false;
      if(__SweepAngle != that.__SweepAngle) return false;
      if(__StartPoint && that.__StartPoint)
      {
         if(__StartPoint->getSeriesNameAsLong() != that.__StartPoint->getSeriesNameAsLong()) return false;
         if(__StartPoint->getSeriesVersion() != that.__StartPoint->getSeriesVersion()) return false;
         if(__StartPoint->getLmcpType() != that.__StartPoint->getLmcpType()) return false;
         if( *(__StartPoint) != *(that.__StartPoint) ) return false;
      }
      else if(__StartPoint != that.__StartPoint) return false;
      return true;

   }

   bool AngledAreaSearchTask::operator!=(const AngledAreaSearchTask & that)
   {
      return( !(operator==(that)) );
   }

   AngledAreaSearchTask& AngledAreaSearchTask::setSearchAreaID(const int64_t val)
   {
      __SearchAreaID = val;
      return *this;
   }

   AngledAreaSearchTask& AngledAreaSearchTask::setSweepAngle(const float val)
   {
      __SweepAngle = val;
      return *this;
   }

   AngledAreaSearchTask& AngledAreaSearchTask::setStartPoint(const afrl::cmasi::Location3D* const val)
   {
      if (__StartPoint != nullptr) { delete __StartPoint; __StartPoint = nullptr; }
      if (val != nullptr) { __StartPoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace impact
} // end namespace afrl

