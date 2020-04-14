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
#include "afrl/impact/ImpactPointSearchTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ImpactPointSearchTask::Subscription = "afrl.impact.ImpactPointSearchTask";
   const std::string ImpactPointSearchTask::TypeName = "ImpactPointSearchTask";
   const std::string ImpactPointSearchTask::SeriesName = "IMPACT";
   const int64_t ImpactPointSearchTask::SeriesId = 5281966179208134656LL;
   const uint16_t ImpactPointSearchTask::SeriesVersion = 14;
   const uint32_t ImpactPointSearchTask::TypeId = 22;
   
   bool isImpactPointSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   bool isImpactPointSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   std::vector< std::string > ImpactPointSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ImpactPointSearchTask::ImpactPointSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __SearchLocationID = 0LL;
      __SearchLocation = nullptr;
      __StandoffDistance = 0.f;
      __DesiredAction = nullptr;

   }
     
   ImpactPointSearchTask::ImpactPointSearchTask(const ImpactPointSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __SearchLocationID = that.__SearchLocationID;
        __SearchLocation = that.__SearchLocation == nullptr ? nullptr : that.__SearchLocation->clone();
        __StandoffDistance = that.__StandoffDistance;
        __ViewAngleList.clear();
        for (size_t i=0; i< that.__ViewAngleList.size(); i++)
        {
           __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
        }
        __DesiredAction = that.__DesiredAction == nullptr ? nullptr : that.__DesiredAction->clone();

   }
   
   ImpactPointSearchTask & ImpactPointSearchTask::operator=(const ImpactPointSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         if (__SearchLocation != nullptr) delete __SearchLocation;
         for (size_t i=0; i<__ViewAngleList.size(); i++)
         {
            if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
         }
         if (__DesiredAction != nullptr) delete __DesiredAction;

         __SearchLocationID = that.__SearchLocationID;
         __SearchLocation = that.__SearchLocation == nullptr ? nullptr : that.__SearchLocation->clone();
         __StandoffDistance = that.__StandoffDistance;
         __ViewAngleList.clear();
         for (size_t i=0; i< that.__ViewAngleList.size(); i++)
         {
            __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
         }
         __DesiredAction = that.__DesiredAction == nullptr ? nullptr : that.__DesiredAction->clone();

      }
      return *this;
   }

   ImpactPointSearchTask* ImpactPointSearchTask::clone() const
   {
        return new ImpactPointSearchTask(*this);
   }
   
   ImpactPointSearchTask::~ImpactPointSearchTask(void)
   {
      if (__SearchLocation != nullptr) delete __SearchLocation;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
      }
      if (__DesiredAction != nullptr) delete __DesiredAction;

   }
  
   void ImpactPointSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__SearchLocationID);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __SearchLocation, buf);
      buf.putFloat(__StandoffDistance);
      buf.putUShort( static_cast<uint16_t>(__ViewAngleList.size()));
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         assert(__ViewAngleList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ViewAngleList[i], buf);
      }
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __DesiredAction, buf);

   }
   
   void ImpactPointSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
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
      __StandoffDistance = buf.getFloat();
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
      {
         if (__DesiredAction != nullptr) delete __DesiredAction;
         __DesiredAction = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __DesiredAction = (afrl::cmasi::LoiterAction*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__DesiredAction != nullptr) __DesiredAction->unpack(buf);
         }
      }

   }

   uint32_t ImpactPointSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__SearchLocation != nullptr ? __SearchLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += 2;
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr)
         {
            size += __ViewAngleList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += (__DesiredAction != nullptr ? __DesiredAction->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string ImpactPointSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ImpactPointSearchTask ) {\n";
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
      oss << indent << "StandoffDistance (float) = " << __StandoffDistance << "\n";
      oss << indent << "ViewAngleList (Wedge [ " << __ViewAngleList.size() << ", var ])\n";
      oss << indent << "DesiredAction (LoiterAction)";
      if (__DesiredAction == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ImpactPointSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ImpactPointSearchTask Series=\"IMPACT\">\n";
      str << ws << "   <SearchLocationID>" << __SearchLocationID << "</SearchLocationID>\n";
      if (__SearchLocation != nullptr)
      {
         str << ws << "   <SearchLocation>";
         str << "\n" + __SearchLocation->toXML(depth + 1) + ws + "   ";
         str << "</SearchLocation>\n";
      }
      str << ws << "   <StandoffDistance>" << __StandoffDistance << "</StandoffDistance>\n";
      str << ws << "   <ViewAngleList>\n";
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         str << (__ViewAngleList[i] == nullptr ? ( ws + "   <null/>\n") : (__ViewAngleList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </ViewAngleList>\n";
      if (__DesiredAction != nullptr)
      {
         str << ws << "   <DesiredAction>";
         str << "\n" + __DesiredAction->toXML(depth + 1) + ws + "   ";
         str << "</DesiredAction>\n";
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
      str << ws << "</ImpactPointSearchTask>\n";

      return str.str();
   }

   bool ImpactPointSearchTask::operator==(const ImpactPointSearchTask & that)
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
      if(__StandoffDistance != that.__StandoffDistance) return false;
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
      if(__DesiredAction && that.__DesiredAction)
      {
         if(__DesiredAction->getSeriesNameAsLong() != that.__DesiredAction->getSeriesNameAsLong()) return false;
         if(__DesiredAction->getSeriesVersion() != that.__DesiredAction->getSeriesVersion()) return false;
         if(__DesiredAction->getLmcpType() != that.__DesiredAction->getLmcpType()) return false;
         if( *(__DesiredAction) != *(that.__DesiredAction) ) return false;
      }
      else if(__DesiredAction != that.__DesiredAction) return false;
      return true;

   }

   bool ImpactPointSearchTask::operator!=(const ImpactPointSearchTask & that)
   {
      return( !(operator==(that)) );
   }

   ImpactPointSearchTask& ImpactPointSearchTask::setSearchLocationID(const int64_t val)
   {
      __SearchLocationID = val;
      return *this;
   }

   ImpactPointSearchTask& ImpactPointSearchTask::setSearchLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__SearchLocation != nullptr) { delete __SearchLocation; __SearchLocation = nullptr; }
      if (val != nullptr) { __SearchLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   ImpactPointSearchTask& ImpactPointSearchTask::setStandoffDistance(const float val)
   {
      __StandoffDistance = val;
      return *this;
   }


   ImpactPointSearchTask& ImpactPointSearchTask::setDesiredAction(const afrl::cmasi::LoiterAction* const val)
   {
      if (__DesiredAction != nullptr) { delete __DesiredAction; __DesiredAction = nullptr; }
      if (val != nullptr) { __DesiredAction = const_cast< afrl::cmasi::LoiterAction* > (val); }
      return *this;
   }


} // end namespace impact
} // end namespace afrl

