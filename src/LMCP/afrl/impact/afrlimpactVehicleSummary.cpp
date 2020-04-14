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
#include "afrl/impact/VehicleSummary.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VehicleSummary::Subscription = "afrl.impact.VehicleSummary";
   const std::string VehicleSummary::TypeName = "VehicleSummary";
   const std::string VehicleSummary::SeriesName = "IMPACT";
   const int64_t VehicleSummary::SeriesId = 5281966179208134656LL;
   const uint16_t VehicleSummary::SeriesVersion = 14;
   const uint32_t VehicleSummary::TypeId = 15;
   
   bool isVehicleSummary(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 15) return false;
      return true;
   }
   
   bool isVehicleSummary(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 15) return false;
      return true;
   }
   
   std::vector< std::string > VehicleSummaryDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   VehicleSummary::VehicleSummary(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __DestinationTaskID = 0LL;
      __InitialTaskID = 0LL;
      __InitialTaskPercentage = 0.f;
      __EstimateTimeToTaskPercentage = 0LL;
      __TimeToArrive = 0LL;
      __TimeOnTask = 0LL;
      __EnergyRemaining = 0.f;
      __BeyondCommRange = false;
      __ConflictsWithROZ = false;
      __FirstWaypoint = 0LL;

   }
     
   VehicleSummary::VehicleSummary(const VehicleSummary &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __DestinationTaskID = that.__DestinationTaskID;
        __InitialTaskID = that.__InitialTaskID;
        __InitialTaskPercentage = that.__InitialTaskPercentage;
        __EstimateTimeToTaskPercentage = that.__EstimateTimeToTaskPercentage;
        __TimeToArrive = that.__TimeToArrive;
        __TimeOnTask = that.__TimeOnTask;
        __EnergyRemaining = that.__EnergyRemaining;
        __BeyondCommRange = that.__BeyondCommRange;
        __ConflictsWithROZ = that.__ConflictsWithROZ;
        __ROZIDs.clear();
        for (size_t i=0; i< that.__ROZIDs.size(); i++)
        {
           __ROZIDs.push_back( that.__ROZIDs[i]);
        }
        __WaypointList.clear();
        for (size_t i=0; i< that.__WaypointList.size(); i++)
        {
           __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
        }
        __FirstWaypoint = that.__FirstWaypoint;

   }
   
   VehicleSummary & VehicleSummary::operator=(const VehicleSummary &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__WaypointList.size(); i++)
         {
            if (__WaypointList[i] != nullptr) delete __WaypointList[i];
         }

         __VehicleID = that.__VehicleID;
         __DestinationTaskID = that.__DestinationTaskID;
         __InitialTaskID = that.__InitialTaskID;
         __InitialTaskPercentage = that.__InitialTaskPercentage;
         __EstimateTimeToTaskPercentage = that.__EstimateTimeToTaskPercentage;
         __TimeToArrive = that.__TimeToArrive;
         __TimeOnTask = that.__TimeOnTask;
         __EnergyRemaining = that.__EnergyRemaining;
         __BeyondCommRange = that.__BeyondCommRange;
         __ConflictsWithROZ = that.__ConflictsWithROZ;
         __ROZIDs.clear();
         for (size_t i=0; i< that.__ROZIDs.size(); i++)
         {
            __ROZIDs.push_back( that.__ROZIDs[i]);
         }
         __WaypointList.clear();
         for (size_t i=0; i< that.__WaypointList.size(); i++)
         {
            __WaypointList.push_back( that.__WaypointList[i] == nullptr ? nullptr : that.__WaypointList[i]->clone());
         }
         __FirstWaypoint = that.__FirstWaypoint;

      }
      return *this;
   }

   VehicleSummary* VehicleSummary::clone() const
   {
        return new VehicleSummary(*this);
   }
   
   VehicleSummary::~VehicleSummary(void)
   {
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr) delete __WaypointList[i];
      }

   }
  
   void VehicleSummary::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__DestinationTaskID);
      buf.putLong(__InitialTaskID);
      buf.putFloat(__InitialTaskPercentage);
      buf.putLong(__EstimateTimeToTaskPercentage);
      buf.putLong(__TimeToArrive);
      buf.putLong(__TimeOnTask);
      buf.putFloat(__EnergyRemaining);
      buf.putBool(__BeyondCommRange);
      buf.putBool(__ConflictsWithROZ);
      buf.putUShort( static_cast<uint16_t>(__ROZIDs.size()));
      for (size_t i=0; i<__ROZIDs.size(); i++)
      {
         buf.putLong(__ROZIDs[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__WaypointList.size()));
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         assert(__WaypointList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __WaypointList[i], buf);
      }
      buf.putLong(__FirstWaypoint);

   }
   
   void VehicleSummary::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __DestinationTaskID = buf.getLong();
      __InitialTaskID = buf.getLong();
      __InitialTaskPercentage = buf.getFloat();
      __EstimateTimeToTaskPercentage = buf.getLong();
      __TimeToArrive = buf.getLong();
      __TimeOnTask = buf.getLong();
      __EnergyRemaining = buf.getFloat();
      __BeyondCommRange = buf.getBool();
      __ConflictsWithROZ = buf.getBool();
      __ROZIDs.clear();
      uint16_t __ROZIDs_length = buf.getUShort();
      for (uint32_t i=0; i< __ROZIDs_length; i++)
      {
         __ROZIDs.push_back(buf.getLong() );
      }
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr)
            delete __WaypointList[i];
      }
      __WaypointList.clear();
      uint16_t __WaypointList_length = buf.getUShort();
      for (uint32_t i=0; i< __WaypointList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __WaypointList.push_back(e);
         }
      }
      __FirstWaypoint = buf.getLong();

   }

   uint32_t VehicleSummary::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(bool);
      size += sizeof(bool);
      size += 2 + sizeof(int64_t) * __ROZIDs.size();
      size += 2;
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if (__WaypointList[i] != nullptr)
         {
            size += __WaypointList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);

      return size;
   }

   std::string VehicleSummary::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VehicleSummary ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "DestinationTaskID (int64_t) = " << __DestinationTaskID << "\n";
      oss << indent << "InitialTaskID (int64_t) = " << __InitialTaskID << "\n";
      oss << indent << "InitialTaskPercentage (float) = " << __InitialTaskPercentage << "\n";
      oss << indent << "EstimateTimeToTaskPercentage (int64_t) = " << __EstimateTimeToTaskPercentage << "\n";
      oss << indent << "TimeToArrive (int64_t) = " << __TimeToArrive << "\n";
      oss << indent << "TimeOnTask (int64_t) = " << __TimeOnTask << "\n";
      oss << indent << "EnergyRemaining (float) = " << __EnergyRemaining << "\n";
      oss << indent << "BeyondCommRange (bool) = " << __BeyondCommRange << "\n";
      oss << indent << "ConflictsWithROZ (bool) = " << __ConflictsWithROZ << "\n";
      oss << indent << "ROZIDs (int64 [ " << __ROZIDs.size() << ", var ])\n";
      oss << indent << "WaypointList (Waypoint [ " << __WaypointList.size() << ", var ])\n";
      oss << indent << "FirstWaypoint (int64_t) = " << __FirstWaypoint << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VehicleSummary::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VehicleSummary Series=\"IMPACT\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <DestinationTaskID>" << __DestinationTaskID << "</DestinationTaskID>\n";
      str << ws << "   <InitialTaskID>" << __InitialTaskID << "</InitialTaskID>\n";
      str << ws << "   <InitialTaskPercentage>" << __InitialTaskPercentage << "</InitialTaskPercentage>\n";
      str << ws << "   <EstimateTimeToTaskPercentage>" << __EstimateTimeToTaskPercentage << "</EstimateTimeToTaskPercentage>\n";
      str << ws << "   <TimeToArrive>" << __TimeToArrive << "</TimeToArrive>\n";
      str << ws << "   <TimeOnTask>" << __TimeOnTask << "</TimeOnTask>\n";
      str << ws << "   <EnergyRemaining>" << __EnergyRemaining << "</EnergyRemaining>\n";
      str << ws << "   <BeyondCommRange>" << (__BeyondCommRange ? "true" : "false") << "</BeyondCommRange>\n";
      str << ws << "   <ConflictsWithROZ>" << (__ConflictsWithROZ ? "true" : "false") << "</ConflictsWithROZ>\n";
      str << ws << "   <ROZIDs>\n";
      for (size_t i=0; i<__ROZIDs.size(); i++)
      {
         str << ws << "   <int64>" << __ROZIDs[i] << "</int64>\n";
      }
      str << ws << "   </ROZIDs>\n";
      str << ws << "   <WaypointList>\n";
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         str << (__WaypointList[i] == nullptr ? ( ws + "   <null/>\n") : (__WaypointList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </WaypointList>\n";
      str << ws << "   <FirstWaypoint>" << __FirstWaypoint << "</FirstWaypoint>\n";
      str << ws << "</VehicleSummary>\n";

      return str.str();
   }

   bool VehicleSummary::operator==(const VehicleSummary & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__DestinationTaskID != that.__DestinationTaskID) return false;
      if(__InitialTaskID != that.__InitialTaskID) return false;
      if(__InitialTaskPercentage != that.__InitialTaskPercentage) return false;
      if(__EstimateTimeToTaskPercentage != that.__EstimateTimeToTaskPercentage) return false;
      if(__TimeToArrive != that.__TimeToArrive) return false;
      if(__TimeOnTask != that.__TimeOnTask) return false;
      if(__EnergyRemaining != that.__EnergyRemaining) return false;
      if(__BeyondCommRange != that.__BeyondCommRange) return false;
      if(__ConflictsWithROZ != that.__ConflictsWithROZ) return false;
      if(__ROZIDs.size() != that.__ROZIDs.size()) return false;
      for (size_t i=0; i<__ROZIDs.size(); i++)
      {
         if(__ROZIDs[i] != that.__ROZIDs[i]) return false;
      }
      if(__WaypointList.size() != that.__WaypointList.size()) return false;
      for (size_t i=0; i<__WaypointList.size(); i++)
      {
         if(__WaypointList[i] && that.__WaypointList[i])
         {
            if(__WaypointList[i]->getSeriesNameAsLong() != that.__WaypointList[i]->getSeriesNameAsLong()) return false;
            if(__WaypointList[i]->getSeriesVersion() != that.__WaypointList[i]->getSeriesVersion()) return false;
            if(__WaypointList[i]->getLmcpType() != that.__WaypointList[i]->getLmcpType()) return false;
            if( *(__WaypointList[i]) != *(that.__WaypointList[i]) ) return false;
         }
         else if(__WaypointList[i] != that.__WaypointList[i]) return false;
      }
      if(__FirstWaypoint != that.__FirstWaypoint) return false;
      return true;

   }

   bool VehicleSummary::operator!=(const VehicleSummary & that)
   {
      return( !(operator==(that)) );
   }

   VehicleSummary& VehicleSummary::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setDestinationTaskID(const int64_t val)
   {
      __DestinationTaskID = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setInitialTaskID(const int64_t val)
   {
      __InitialTaskID = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setInitialTaskPercentage(const float val)
   {
      __InitialTaskPercentage = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setEstimateTimeToTaskPercentage(const int64_t val)
   {
      __EstimateTimeToTaskPercentage = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setTimeToArrive(const int64_t val)
   {
      __TimeToArrive = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setTimeOnTask(const int64_t val)
   {
      __TimeOnTask = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setEnergyRemaining(const float val)
   {
      __EnergyRemaining = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setBeyondCommRange(const bool val)
   {
      __BeyondCommRange = val;
      return *this;
   }

   VehicleSummary& VehicleSummary::setConflictsWithROZ(const bool val)
   {
      __ConflictsWithROZ = val;
      return *this;
   }



   VehicleSummary& VehicleSummary::setFirstWaypoint(const int64_t val)
   {
      __FirstWaypoint = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

