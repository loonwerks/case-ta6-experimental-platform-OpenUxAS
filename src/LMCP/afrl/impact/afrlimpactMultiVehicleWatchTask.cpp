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
#include "afrl/impact/MultiVehicleWatchTask.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string MultiVehicleWatchTask::Subscription = "afrl.impact.MultiVehicleWatchTask";
   const std::string MultiVehicleWatchTask::TypeName = "MultiVehicleWatchTask";
   const std::string MultiVehicleWatchTask::SeriesName = "IMPACT";
   const int64_t MultiVehicleWatchTask::SeriesId = 5281966179208134656LL;
   const uint16_t MultiVehicleWatchTask::SeriesVersion = 14;
   const uint32_t MultiVehicleWatchTask::TypeId = 27;
   
   bool isMultiVehicleWatchTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   bool isMultiVehicleWatchTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   std::vector< std::string > MultiVehicleWatchTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   MultiVehicleWatchTask::MultiVehicleWatchTask(void) : afrl::cmasi::SearchTask()
   {
      __WatchedEntityID = 0LL;
      __NumberVehicles = 1;

   }
     
   MultiVehicleWatchTask::MultiVehicleWatchTask(const MultiVehicleWatchTask &that) : afrl::cmasi::SearchTask(that)
   {
        __WatchedEntityID = that.__WatchedEntityID;
        __NumberVehicles = that.__NumberVehicles;

   }
   
   MultiVehicleWatchTask & MultiVehicleWatchTask::operator=(const MultiVehicleWatchTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::SearchTask::operator=(that);

         __WatchedEntityID = that.__WatchedEntityID;
         __NumberVehicles = that.__NumberVehicles;

      }
      return *this;
   }

   MultiVehicleWatchTask* MultiVehicleWatchTask::clone() const
   {
        return new MultiVehicleWatchTask(*this);
   }
   
   MultiVehicleWatchTask::~MultiVehicleWatchTask(void)
   {

   }
  
   void MultiVehicleWatchTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::SearchTask::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__WatchedEntityID);
      buf.putByte(__NumberVehicles);

   }
   
   void MultiVehicleWatchTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::SearchTask::unpack(buf);
      // Copy the buffer into the class
      __WatchedEntityID = buf.getLong();
      __NumberVehicles = buf.getByte();

   }

   uint32_t MultiVehicleWatchTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::SearchTask::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(uint8_t);

      return size;
   }

   std::string MultiVehicleWatchTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( MultiVehicleWatchTask ) {\n";
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

      oss << indent << "WatchedEntityID (int64_t) = " << __WatchedEntityID << "\n";
      oss << indent << "NumberVehicles (uint8_t) = " << __NumberVehicles << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string MultiVehicleWatchTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<MultiVehicleWatchTask Series=\"IMPACT\">\n";
      str << ws << "   <WatchedEntityID>" << __WatchedEntityID << "</WatchedEntityID>\n";
      str << ws << "   <NumberVehicles>" << (int32_t) __NumberVehicles << "</NumberVehicles>\n";
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
      str << ws << "</MultiVehicleWatchTask>\n";

      return str.str();
   }

   bool MultiVehicleWatchTask::operator==(const MultiVehicleWatchTask & that)
   {
      if( afrl::cmasi::SearchTask::operator!=(that) )
      {
          return false;
      }
      if(__WatchedEntityID != that.__WatchedEntityID) return false;
      if(__NumberVehicles != that.__NumberVehicles) return false;
      return true;

   }

   bool MultiVehicleWatchTask::operator!=(const MultiVehicleWatchTask & that)
   {
      return( !(operator==(that)) );
   }

   MultiVehicleWatchTask& MultiVehicleWatchTask::setWatchedEntityID(const int64_t val)
   {
      __WatchedEntityID = val;
      return *this;
   }

   MultiVehicleWatchTask& MultiVehicleWatchTask::setNumberVehicles(const uint8_t val)
   {
      __NumberVehicles = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

