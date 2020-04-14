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
#include "afrl/cmasi/AreaSearchTask.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AreaSearchTask::Subscription = "afrl.cmasi.AreaSearchTask";
   const std::string AreaSearchTask::TypeName = "AreaSearchTask";
   const std::string AreaSearchTask::SeriesName = "CMASI";
   const int64_t AreaSearchTask::SeriesId = 4849604199710720000LL;
   const uint16_t AreaSearchTask::SeriesVersion = 3;
   const uint32_t AreaSearchTask::TypeId = 17;
   
   bool isAreaSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   bool isAreaSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   std::vector< std::string > AreaSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AreaSearchTask::AreaSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __SearchArea = new afrl::cmasi::AbstractGeometry();

   }
     
   AreaSearchTask::AreaSearchTask(const AreaSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __SearchArea = that.__SearchArea == nullptr ? nullptr : that.__SearchArea->clone();
        __ViewAngleList.clear();
        for (size_t i=0; i< that.__ViewAngleList.size(); i++)
        {
           __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
        }

   }
   
   AreaSearchTask & AreaSearchTask::operator=(const AreaSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         if (__SearchArea != nullptr) delete __SearchArea;
         for (size_t i=0; i<__ViewAngleList.size(); i++)
         {
            if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
         }

         __SearchArea = that.__SearchArea == nullptr ? nullptr : that.__SearchArea->clone();
         __ViewAngleList.clear();
         for (size_t i=0; i< that.__ViewAngleList.size(); i++)
         {
            __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
         }

      }
      return *this;
   }

   AreaSearchTask* AreaSearchTask::clone() const
   {
        return new AreaSearchTask(*this);
   }
   
   AreaSearchTask::~AreaSearchTask(void)
   {
      if (__SearchArea != nullptr) delete __SearchArea;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
      }

   }
  
   void AreaSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      assert(__SearchArea != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __SearchArea, buf);
      buf.putUShort( static_cast<uint16_t>(__ViewAngleList.size()));
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         assert(__ViewAngleList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ViewAngleList[i], buf);
      }

   }
   
   void AreaSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      {
         if (__SearchArea != nullptr) delete __SearchArea;
         __SearchArea = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __SearchArea = (afrl::cmasi::AbstractGeometry*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__SearchArea != nullptr) __SearchArea->unpack(buf);
            else assert(__SearchArea != nullptr);
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

   }

   uint32_t AreaSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += (__SearchArea != nullptr ? __SearchArea->calculatePackedSize() + 15 : 1);
      size += 2;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr)
         {
            size += __ViewAngleList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string AreaSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AreaSearchTask ) {\n";
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

      oss << indent << "SearchArea (AbstractGeometry)";
      if (__SearchArea == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "ViewAngleList (Wedge [ " << __ViewAngleList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AreaSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AreaSearchTask Series=\"CMASI\">\n";
      if (__SearchArea != nullptr)
      {
         str << ws << "   <SearchArea>";
         str << "\n" + __SearchArea->toXML(depth + 1) + ws + "   ";
         str << "</SearchArea>\n";
      }
      str << ws << "   <ViewAngleList>\n";
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         str << (__ViewAngleList[i] == nullptr ? ( ws + "   <null/>\n") : (__ViewAngleList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </ViewAngleList>\n";
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
      str << ws << "</AreaSearchTask>\n";

      return str.str();
   }

   bool AreaSearchTask::operator==(const AreaSearchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__SearchArea && that.__SearchArea)
      {
         if(__SearchArea->getSeriesNameAsLong() != that.__SearchArea->getSeriesNameAsLong()) return false;
         if(__SearchArea->getSeriesVersion() != that.__SearchArea->getSeriesVersion()) return false;
         if(__SearchArea->getLmcpType() != that.__SearchArea->getLmcpType()) return false;
         if( *(__SearchArea) != *(that.__SearchArea) ) return false;
      }
      else if(__SearchArea != that.__SearchArea) return false;
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
      return true;

   }

   bool AreaSearchTask::operator!=(const AreaSearchTask & that)
   {
      return( !(operator==(that)) );
   }

   AreaSearchTask& AreaSearchTask::setSearchArea(const afrl::cmasi::AbstractGeometry* const val)
   {
      if (__SearchArea != nullptr) { delete __SearchArea; __SearchArea = nullptr; }
      if (val != nullptr) { __SearchArea = const_cast< afrl::cmasi::AbstractGeometry* > (val); }
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

