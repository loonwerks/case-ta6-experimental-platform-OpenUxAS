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
#include "afrl/cmasi/perceive/TrackEntityTask.h"


namespace afrl {
namespace cmasi {
namespace perceive {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TrackEntityTask::Subscription = "afrl.cmasi.perceive.TrackEntityTask";
   const std::string TrackEntityTask::TypeName = "TrackEntityTask";
   const std::string TrackEntityTask::SeriesName = "PERCEIVE";
   const int64_t TrackEntityTask::SeriesId = 5784119745305990725LL;
   const uint16_t TrackEntityTask::SeriesVersion = 1;
   const uint32_t TrackEntityTask::TypeId = 3;
   
   bool isTrackEntityTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isTrackEntityTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > TrackEntityTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TrackEntityTask::TrackEntityTask(void) : afrl::cmasi::Task()
   {
      __EntityID = 0;
      __SensorModality = afrl::cmasi::WavelengthBand::AllAny;
      __GroundSampleDistance = 0.f;

   }
     
   TrackEntityTask::TrackEntityTask(const TrackEntityTask &that) : afrl::cmasi::Task(that)
   {
        __EntityID = that.__EntityID;
        __SensorModality = that.__SensorModality;
        __GroundSampleDistance = that.__GroundSampleDistance;

   }
   
   TrackEntityTask & TrackEntityTask::operator=(const TrackEntityTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);

         __EntityID = that.__EntityID;
         __SensorModality = that.__SensorModality;
         __GroundSampleDistance = that.__GroundSampleDistance;

      }
      return *this;
   }

   TrackEntityTask* TrackEntityTask::clone() const
   {
        return new TrackEntityTask(*this);
   }
   
   TrackEntityTask::~TrackEntityTask(void)
   {

   }
  
   void TrackEntityTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      buf.putUInt(__EntityID);
      buf.putInt( (int32_t) __SensorModality);
      buf.putFloat(__GroundSampleDistance);

   }
   
   void TrackEntityTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getUInt();
      __SensorModality = (afrl::cmasi::WavelengthBand::WavelengthBand) buf.getInt();
      __GroundSampleDistance = buf.getFloat();

   }

   uint32_t TrackEntityTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += sizeof(uint32_t);
      size += sizeof(afrl::cmasi::WavelengthBand::WavelengthBand);
      size += sizeof(float);

      return size;
   }

   std::string TrackEntityTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TrackEntityTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "EntityID (uint32_t) = " << __EntityID << "\n";
      oss << indent << "SensorModality (WavelengthBand) = " << __SensorModality << "\n";
      oss << indent << "GroundSampleDistance (float) = " << __GroundSampleDistance << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TrackEntityTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TrackEntityTask Series=\"PERCEIVE\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <SensorModality>" << afrl::cmasi::WavelengthBand::get_string(__SensorModality) << "</SensorModality>\n";
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
      str << ws << "</TrackEntityTask>\n";

      return str.str();
   }

   bool TrackEntityTask::operator==(const TrackEntityTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__SensorModality != that.__SensorModality) return false;
      if(__GroundSampleDistance != that.__GroundSampleDistance) return false;
      return true;

   }

   bool TrackEntityTask::operator!=(const TrackEntityTask & that)
   {
      return( !(operator==(that)) );
   }

   TrackEntityTask& TrackEntityTask::setEntityID(const uint32_t val)
   {
      __EntityID = val;
      return *this;
   }

   TrackEntityTask& TrackEntityTask::setSensorModality(const afrl::cmasi::WavelengthBand::WavelengthBand val)
   {
      __SensorModality = val;
      return *this;
   }

   TrackEntityTask& TrackEntityTask::setGroundSampleDistance(const float val)
   {
      __GroundSampleDistance = val;
      return *this;
   }


} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl

