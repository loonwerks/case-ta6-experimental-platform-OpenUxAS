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
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PayloadAction.h"
#include "afrl/cmasi/CameraAction.h"
#include "afrl/cmasi/GimbalAngleAction.h"
#include "afrl/cmasi/GimbalScanAction.h"
#include "afrl/cmasi/GimbalStareAction.h"
#include "afrl/cmasi/NavigationAction.h"
#include "afrl/cmasi/GoToWaypointAction.h"
#include "afrl/cmasi/LoiterAction.h"
#include "afrl/cmasi/FlightDirectorAction.h"
#include "afrl/cmasi/VideoStreamAction.h"
#include "afrl/cmasi/StopMovementAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Waypoint::Subscription = "afrl.cmasi.Waypoint";
   const std::string Waypoint::TypeName = "Waypoint";
   const std::string Waypoint::SeriesName = "CMASI";
   const int64_t Waypoint::SeriesId = 4849604199710720000LL;
   const uint16_t Waypoint::SeriesVersion = 3;
   const uint32_t Waypoint::TypeId = 35;
   
   bool isWaypoint(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 35) return false;
      return true;
   }
   
   bool isWaypoint(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 35) return false;
      return true;
   }
   
   std::vector< std::string > WaypointDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.PathWaypoint");

       return descendants;
   }
   
   Waypoint::Waypoint(void) : afrl::cmasi::Location3D()
   {
      __Number = 0LL;
      __NextWaypoint = 0LL;
      __Speed = 0.f;
      __SpeedType = afrl::cmasi::SpeedType::Airspeed;
      __ClimbRate = 0.f;
      __TurnType = afrl::cmasi::TurnType::TurnShort;
      __ContingencyWaypointA = 0LL;
      __ContingencyWaypointB = 0LL;

   }
     
   Waypoint::Waypoint(const Waypoint &that) : afrl::cmasi::Location3D(that)
   {
        __Number = that.__Number;
        __NextWaypoint = that.__NextWaypoint;
        __Speed = that.__Speed;
        __SpeedType = that.__SpeedType;
        __ClimbRate = that.__ClimbRate;
        __TurnType = that.__TurnType;
        __VehicleActionList.clear();
        for (size_t i=0; i< that.__VehicleActionList.size(); i++)
        {
           __VehicleActionList.push_back( that.__VehicleActionList[i] == nullptr ? nullptr : that.__VehicleActionList[i]->clone());
        }
        __ContingencyWaypointA = that.__ContingencyWaypointA;
        __ContingencyWaypointB = that.__ContingencyWaypointB;
        __AssociatedTasks.clear();
        for (size_t i=0; i< that.__AssociatedTasks.size(); i++)
        {
           __AssociatedTasks.push_back( that.__AssociatedTasks[i]);
        }

   }
   
   Waypoint & Waypoint::operator=(const Waypoint &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Location3D::operator=(that);
         for (size_t i=0; i<__VehicleActionList.size(); i++)
         {
            if (__VehicleActionList[i] != nullptr) delete __VehicleActionList[i];
         }

         __Number = that.__Number;
         __NextWaypoint = that.__NextWaypoint;
         __Speed = that.__Speed;
         __SpeedType = that.__SpeedType;
         __ClimbRate = that.__ClimbRate;
         __TurnType = that.__TurnType;
         __VehicleActionList.clear();
         for (size_t i=0; i< that.__VehicleActionList.size(); i++)
         {
            __VehicleActionList.push_back( that.__VehicleActionList[i] == nullptr ? nullptr : that.__VehicleActionList[i]->clone());
         }
         __ContingencyWaypointA = that.__ContingencyWaypointA;
         __ContingencyWaypointB = that.__ContingencyWaypointB;
         __AssociatedTasks.clear();
         for (size_t i=0; i< that.__AssociatedTasks.size(); i++)
         {
            __AssociatedTasks.push_back( that.__AssociatedTasks[i]);
         }

      }
      return *this;
   }

   Waypoint* Waypoint::clone() const
   {
        return new Waypoint(*this);
   }
   
   Waypoint::~Waypoint(void)
   {
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr) delete __VehicleActionList[i];
      }

   }
  
   void Waypoint::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Location3D::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__Number);
      buf.putLong(__NextWaypoint);
      buf.putFloat(__Speed);
      buf.putInt( (int32_t) __SpeedType);
      buf.putFloat(__ClimbRate);
      buf.putInt( (int32_t) __TurnType);
      buf.putUShort( static_cast<uint16_t>(__VehicleActionList.size()));
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         assert(__VehicleActionList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __VehicleActionList[i], buf);
      }
      buf.putLong(__ContingencyWaypointA);
      buf.putLong(__ContingencyWaypointB);
      buf.putUShort( static_cast<uint16_t>(__AssociatedTasks.size()));
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         buf.putLong(__AssociatedTasks[i]);
      }

   }
   
   void Waypoint::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Location3D::unpack(buf);
      // Copy the buffer into the class
      __Number = buf.getLong();
      __NextWaypoint = buf.getLong();
      __Speed = buf.getFloat();
      __SpeedType = (afrl::cmasi::SpeedType::SpeedType) buf.getInt();
      __ClimbRate = buf.getFloat();
      __TurnType = (afrl::cmasi::TurnType::TurnType) buf.getInt();
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr)
            delete __VehicleActionList[i];
      }
      __VehicleActionList.clear();
      uint16_t __VehicleActionList_length = buf.getUShort();
      for (uint32_t i=0; i< __VehicleActionList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::VehicleAction* e = (afrl::cmasi::VehicleAction*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __VehicleActionList.push_back(e);
         }
      }
      __ContingencyWaypointA = buf.getLong();
      __ContingencyWaypointB = buf.getLong();
      __AssociatedTasks.clear();
      uint16_t __AssociatedTasks_length = buf.getUShort();
      for (uint32_t i=0; i< __AssociatedTasks_length; i++)
      {
         __AssociatedTasks.push_back(buf.getLong() );
      }

   }

   uint32_t Waypoint::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Location3D::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::SpeedType::SpeedType);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::TurnType::TurnType);
      size += 2;
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if (__VehicleActionList[i] != nullptr)
         {
            size += __VehicleActionList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __AssociatedTasks.size();

      return size;
   }

   std::string Waypoint::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Waypoint ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Latitude (double) = " << __Latitude << "\n";
      oss << indent << "Longitude (double) = " << __Longitude << "\n";
      oss << indent << "Altitude (float) = " << __Altitude << "\n";
      oss << indent << "AltitudeType (AltitudeType) = " << __AltitudeType << "\n";

      oss << indent << "Number (int64_t) = " << __Number << "\n";
      oss << indent << "NextWaypoint (int64_t) = " << __NextWaypoint << "\n";
      oss << indent << "Speed (float) = " << __Speed << "\n";
      oss << indent << "SpeedType (SpeedType) = " << __SpeedType << "\n";
      oss << indent << "ClimbRate (float) = " << __ClimbRate << "\n";
      oss << indent << "TurnType (TurnType) = " << __TurnType << "\n";
      oss << indent << "VehicleActionList (VehicleAction [ " << __VehicleActionList.size() << ", var ])\n";
      oss << indent << "ContingencyWaypointA (int64_t) = " << __ContingencyWaypointA << "\n";
      oss << indent << "ContingencyWaypointB (int64_t) = " << __ContingencyWaypointB << "\n";
      oss << indent << "AssociatedTasks (int64 [ " << __AssociatedTasks.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Waypoint::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Waypoint Series=\"CMASI\">\n";
      str << ws << "   <Number>" << __Number << "</Number>\n";
      str << ws << "   <NextWaypoint>" << __NextWaypoint << "</NextWaypoint>\n";
      str << ws << "   <Speed>" << __Speed << "</Speed>\n";
      str << ws << "   <SpeedType>" << afrl::cmasi::SpeedType::get_string(__SpeedType) << "</SpeedType>\n";
      str << ws << "   <ClimbRate>" << __ClimbRate << "</ClimbRate>\n";
      str << ws << "   <TurnType>" << afrl::cmasi::TurnType::get_string(__TurnType) << "</TurnType>\n";
      str << ws << "   <VehicleActionList>\n";
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         str << (__VehicleActionList[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleActionList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleActionList>\n";
      str << ws << "   <ContingencyWaypointA>" << __ContingencyWaypointA << "</ContingencyWaypointA>\n";
      str << ws << "   <ContingencyWaypointB>" << __ContingencyWaypointB << "</ContingencyWaypointB>\n";
      str << ws << "   <AssociatedTasks>\n";
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTasks[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTasks>\n";
      str << ws << "   <Latitude>" << __Latitude << "</Latitude>\n";
      str << ws << "   <Longitude>" << __Longitude << "</Longitude>\n";
      str << ws << "   <Altitude>" << __Altitude << "</Altitude>\n";
      str << ws << "   <AltitudeType>" << afrl::cmasi::AltitudeType::get_string(__AltitudeType) << "</AltitudeType>\n";
      str << ws << "</Waypoint>\n";

      return str.str();
   }

   bool Waypoint::operator==(const Waypoint & that)
   {
      if( afrl::cmasi::Location3D::operator!=(that) )
      {
          return false;
      }
      if(__Number != that.__Number) return false;
      if(__NextWaypoint != that.__NextWaypoint) return false;
      if(__Speed != that.__Speed) return false;
      if(__SpeedType != that.__SpeedType) return false;
      if(__ClimbRate != that.__ClimbRate) return false;
      if(__TurnType != that.__TurnType) return false;
      if(__VehicleActionList.size() != that.__VehicleActionList.size()) return false;
      for (size_t i=0; i<__VehicleActionList.size(); i++)
      {
         if(__VehicleActionList[i] && that.__VehicleActionList[i])
         {
            if(__VehicleActionList[i]->getSeriesNameAsLong() != that.__VehicleActionList[i]->getSeriesNameAsLong()) return false;
            if(__VehicleActionList[i]->getSeriesVersion() != that.__VehicleActionList[i]->getSeriesVersion()) return false;
            if(__VehicleActionList[i]->getLmcpType() != that.__VehicleActionList[i]->getLmcpType()) return false;
            if( *(__VehicleActionList[i]) != *(that.__VehicleActionList[i]) ) return false;
         }
         else if(__VehicleActionList[i] != that.__VehicleActionList[i]) return false;
      }
      if(__ContingencyWaypointA != that.__ContingencyWaypointA) return false;
      if(__ContingencyWaypointB != that.__ContingencyWaypointB) return false;
      if(__AssociatedTasks.size() != that.__AssociatedTasks.size()) return false;
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         if(__AssociatedTasks[i] != that.__AssociatedTasks[i]) return false;
      }
      return true;

   }

   bool Waypoint::operator!=(const Waypoint & that)
   {
      return( !(operator==(that)) );
   }

   Waypoint& Waypoint::setNumber(const int64_t val)
   {
      __Number = val;
      return *this;
   }

   Waypoint& Waypoint::setNextWaypoint(const int64_t val)
   {
      __NextWaypoint = val;
      return *this;
   }

   Waypoint& Waypoint::setSpeed(const float val)
   {
      __Speed = val;
      return *this;
   }

   Waypoint& Waypoint::setSpeedType(const afrl::cmasi::SpeedType::SpeedType val)
   {
      __SpeedType = val;
      return *this;
   }

   Waypoint& Waypoint::setClimbRate(const float val)
   {
      __ClimbRate = val;
      return *this;
   }

   Waypoint& Waypoint::setTurnType(const afrl::cmasi::TurnType::TurnType val)
   {
      __TurnType = val;
      return *this;
   }


   Waypoint& Waypoint::setContingencyWaypointA(const int64_t val)
   {
      __ContingencyWaypointA = val;
      return *this;
   }

   Waypoint& Waypoint::setContingencyWaypointB(const int64_t val)
   {
      __ContingencyWaypointB = val;
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

