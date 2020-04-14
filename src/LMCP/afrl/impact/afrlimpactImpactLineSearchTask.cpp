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
#include "afrl/impact/ImpactLineSearchTask.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ImpactLineSearchTask::Subscription = "afrl.impact.ImpactLineSearchTask";
   const std::string ImpactLineSearchTask::TypeName = "ImpactLineSearchTask";
   const std::string ImpactLineSearchTask::SeriesName = "IMPACT";
   const int64_t ImpactLineSearchTask::SeriesId = 5281966179208134656LL;
   const uint16_t ImpactLineSearchTask::SeriesVersion = 14;
   const uint32_t ImpactLineSearchTask::TypeId = 25;
   
   bool isImpactLineSearchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   bool isImpactLineSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   std::vector< std::string > ImpactLineSearchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ImpactLineSearchTask::ImpactLineSearchTask(void) : afrl::cmasi::SearchTask()
   {
      __LineID = 0LL;
      __UseInertialViewAngles = false;

   }
     
   ImpactLineSearchTask::ImpactLineSearchTask(const ImpactLineSearchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __LineID = that.__LineID;
        __ViewAngleList.clear();
        for (size_t i=0; i< that.__ViewAngleList.size(); i++)
        {
           __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
        }
        __UseInertialViewAngles = that.__UseInertialViewAngles;

   }
   
   ImpactLineSearchTask & ImpactLineSearchTask::operator=(const ImpactLineSearchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);
         for (size_t i=0; i<__ViewAngleList.size(); i++)
         {
            if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
         }

         __LineID = that.__LineID;
         __ViewAngleList.clear();
         for (size_t i=0; i< that.__ViewAngleList.size(); i++)
         {
            __ViewAngleList.push_back( that.__ViewAngleList[i] == nullptr ? nullptr : that.__ViewAngleList[i]->clone());
         }
         __UseInertialViewAngles = that.__UseInertialViewAngles;

      }
      return *this;
   }

   ImpactLineSearchTask* ImpactLineSearchTask::clone() const
   {
        return new ImpactLineSearchTask(*this);
   }
   
   ImpactLineSearchTask::~ImpactLineSearchTask(void)
   {
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         if (__ViewAngleList[i] != nullptr) delete __ViewAngleList[i];
      }

   }
  
   void ImpactLineSearchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__LineID);
      buf.putUShort( static_cast<uint16_t>(__ViewAngleList.size()));
      for (size_t i=0; i<__ViewAngleList.size(); i++)
      {
         assert(__ViewAngleList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ViewAngleList[i], buf);
      }
      buf.putBool(__UseInertialViewAngles);

   }
   
   void ImpactLineSearchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      __LineID = buf.getLong();
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

   uint32_t ImpactLineSearchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
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

   std::string ImpactLineSearchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ImpactLineSearchTask ) {\n";
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

      oss << indent << "LineID (int64_t) = " << __LineID << "\n";
      oss << indent << "ViewAngleList (Wedge [ " << __ViewAngleList.size() << ", var ])\n";
      oss << indent << "UseInertialViewAngles (bool) = " << __UseInertialViewAngles << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ImpactLineSearchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ImpactLineSearchTask Series=\"IMPACT\">\n";
      str << ws << "   <LineID>" << __LineID << "</LineID>\n";
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
      str << ws << "</ImpactLineSearchTask>\n";

      return str.str();
   }

   bool ImpactLineSearchTask::operator==(const ImpactLineSearchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__LineID != that.__LineID) return false;
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

   bool ImpactLineSearchTask::operator!=(const ImpactLineSearchTask & that)
   {
      return( !(operator==(that)) );
   }

   ImpactLineSearchTask& ImpactLineSearchTask::setLineID(const int64_t val)
   {
      __LineID = val;
      return *this;
   }


   ImpactLineSearchTask& ImpactLineSearchTask::setUseInertialViewAngles(const bool val)
   {
      __UseInertialViewAngles = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

