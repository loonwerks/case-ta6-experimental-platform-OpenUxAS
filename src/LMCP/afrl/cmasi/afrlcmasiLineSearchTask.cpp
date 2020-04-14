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
#include "afrl/cmasi/LineSearchTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string LineSearchTask::Subscription = "afrl.cmasi.LineSearchTask";
   const std::string LineSearchTask::TypeName = "LineSearchTask";
   const std::string LineSearchTask::SeriesName = "CMASI";
   const int64_t LineSearchTask::SeriesId = 4849604199710720000LL;
   const uint16_t LineSearchTask::SeriesVersion = 3;
   const uint32_t LineSearchTask::TypeId = 31;
   
   bool isLineSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 31) return false;
      return true;
   }
   
   bool isLineSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 31) return false;
      return true;
   }
   
   std::vector< std::string > LineSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   LineSearchTask::LineSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __UseInertialViewAngles = false;

   }
     
   LineSearchTask::LineSearchTask(const LineSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __PointList.clear();
        for (size_t i=0; i< that.__PointList.size(); i++)
        {
           __PointList.push_back( that.__PointList[i] == nullptr ? nullptr : that.__PointList[i]->clone());
        }
        __ViewAngleList.clear();
        for (size_t i=0; i< that.__ViewAngleList.size(); i++)
        {
           __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
        }
        __UseInertialViewAngles = that.__UseInertialViewAngles;

   }
   
   LineSearchTask & LineSearchTask::operator=(const LineSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         for (size_t i=0; i<__PointList.size(); i++)
         {
            if (__PointList[i] != nullptr) delete __PointList[i];
         }
         for (size_t i=0; i<__ViewAngleList.size(); i++)
         {
            if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
         }

         __PointList.clear();
         for (size_t i=0; i< that.__PointList.size(); i++)
         {
            __PointList.push_back( that.__PointList[i] == nullptr ? nullptr : that.__PointList[i]->clone());
         }
         __ViewAngleList.clear();
         for (size_t i=0; i< that.__ViewAngleList.size(); i++)
         {
            __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
         }
         __UseInertialViewAngles = that.__UseInertialViewAngles;

      }
      return *this;
   }

   LineSearchTask* LineSearchTask::clone() const
   {
        return new LineSearchTask(*this);
   }
   
   LineSearchTask::~LineSearchTask(void)
   {
      for (size_t i=0; i<__PointList.size(); i++)
      {
         if (__PointList[i] != nullptr) delete __PointList[i];
      }
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
      }

   }
  
   void LineSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__PointList.size()));
      for (size_t i=0; i<__PointList.size(); i++)
      {
         assert(__PointList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PointList[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__ViewAngleList.size()));
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         assert(__ViewAngleList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ViewAngleList[i], buf);
      }
      buf.putBool(__UseInertialViewAngles);

   }
   
   void LineSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__PointList.size(); i++)
      {
         if (__PointList[i] != nullptr)
            delete __PointList[i];
      }
      __PointList.clear();
      uint16_t __PointList_length = buf.getUShort();
      for (uint32_t i=0; i< __PointList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PointList.push_back(e);
         }
      }
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr)
            delete __ViewAngleList[i];
      }
      __ViewAngleList.clear();
      uint16_t __ViewAngleList_length = buf.getUShort();
      for (uint32_t i=0; i< __ViewAngleList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Wedge* e = (afrl::cmasi::Wedge*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __ViewAngleList.push_back(e);
         }
      }
      __UseInertialViewAngles = buf.getBool();

   }

   uint32_t LineSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__PointList.size(); i++)
      {
         if (__PointList[i] != nullptr)
         {
            size += __PointList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr)
         {
            size += __ViewAngleList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(bool);

      return size;
   }

   std::string LineSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( LineSearchTask ) {\n";
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

      oss << indent << "PointList (Location3D [ " << __PointList.size() << ", var ])\n";
      oss << indent << "ViewAngleList (Wedge [ " << __ViewAngleList.size() << ", var ])\n";
      oss << indent << "UseInertialViewAngles (bool) = " << __UseInertialViewAngles << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string LineSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<LineSearchTask Series=\"CMASI\">\n";
      str << ws << "   <PointList>\n";
      for (size_t i=0; i<__PointList.size(); i++)
      {
         str << (__PointList[i] == nullptr ? ( ws + "   <null/>\n") : (__PointList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PointList>\n";
      str << ws << "   <ViewAngleList>\n";
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         str << (__ViewAngleList[i] == nullptr ? ( ws + "   <null/>\n") : (__ViewAngleList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </ViewAngleList>\n";
      str << ws << "   <UseInertialViewAngles>" << (__UseInertialViewAngles ? "true" : "false") << "</UseInertialViewAngles>\n";
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
      str << ws << "</LineSearchTask>\n";

      return str.str();
   }

   bool LineSearchTask::operator==(const LineSearchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__PointList.size() != that.__PointList.size()) return false;
      for (size_t i=0; i<__PointList.size(); i++)
      {
         if(__PointList[i] && that.__PointList[i])
         {
            if(__PointList[i]->getSeriesNameAsLong() != that.__PointList[i]->getSeriesNameAsLong()) return false;
            if(__PointList[i]->getSeriesVersion() != that.__PointList[i]->getSeriesVersion()) return false;
            if(__PointList[i]->getLmcpType() != that.__PointList[i]->getLmcpType()) return false;
            if( *(__PointList[i]) != *(that.__PointList[i]) ) return false;
         }
         else if(__PointList[i] != that.__PointList[i]) return false;
      }
      if(__ViewAngleList.size() != that.__ViewAngleList.size()) return false;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if(__ViewAngleList[i] && that.__ViewAngleList[i])
         {
            if(__ViewAngleList[i]->getSeriesNameAsLong() != that.__ViewAngleList[i]->getSeriesNameAsLong()) return false;
            if(__ViewAngleList[i]->getSeriesVersion() != that.__ViewAngleList[i]->getSeriesVersion()) return false;
            if(__ViewAngleList[i]->getLmcpType() != that.__ViewAngleList[i]->getLmcpType()) return false;
            if( *(__ViewAngleList[i]) != *(that.__ViewAngleList[i]) ) return false;
         }
         else if(__ViewAngleList[i] != that.__ViewAngleList[i]) return false;
      }
      if(__UseInertialViewAngles != that.__UseInertialViewAngles) return false;
      return true;

   }

   bool LineSearchTask::operator!=(const LineSearchTask & that)
   {
      return( !(operator==(that)) );
   }



   LineSearchTask& LineSearchTask::setUseInertialViewAngles(const bool val)
   {
      __UseInertialViewAngles = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

