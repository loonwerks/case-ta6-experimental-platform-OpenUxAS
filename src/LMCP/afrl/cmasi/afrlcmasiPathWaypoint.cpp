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
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PathWaypoint::Subscription = "afrl.cmasi.PathWaypoint";
   const std::string PathWaypoint::TypeName = "PathWaypoint";
   const std::string PathWaypoint::SeriesName = "CMASI";
   const int64_t PathWaypoint::SeriesId = 4849604199710720000LL;
   const uint16_t PathWaypoint::SeriesVersion = 3;
   const uint32_t PathWaypoint::TypeId = 57;
   
   bool isPathWaypoint(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 57) return false;
      return true;
   }
   
   bool isPathWaypoint(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 57) return false;
      return true;
   }
   
   std::vector< std::string > PathWaypointDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PathWaypoint::PathWaypoint(void) : afrl::cmasi::Waypoint()
   {
      __PauseTime = 0LL;

   }
     
   PathWaypoint::PathWaypoint(const PathWaypoint &that) : afrl::cmasi::Waypoint(that)
   {
        __PauseTime = that.__PauseTime;

   }
   
   PathWaypoint & PathWaypoint::operator=(const PathWaypoint &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Waypoint::operator=(that);

         __PauseTime = that.__PauseTime;

      }
      return *this;
   }

   PathWaypoint* PathWaypoint::clone() const
   {
        return new PathWaypoint(*this);
   }
   
   PathWaypoint::~PathWaypoint(void)
   {

   }
  
   void PathWaypoint::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Waypoint::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__PauseTime);

   }
   
   void PathWaypoint::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Waypoint::unpack(buf);
      // Copy the buffer into the class
      __PauseTime = buf.getLong();

   }

   uint32_t PathWaypoint::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Waypoint::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string PathWaypoint::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PathWaypoint ) {\n";
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

      oss << indent << "PauseTime (int64_t) = " << __PauseTime << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PathWaypoint::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PathWaypoint Series=\"CMASI\">\n";
      str << ws << "   <PauseTime>" << __PauseTime << "</PauseTime>\n";
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
      str << ws << "</PathWaypoint>\n";

      return str.str();
   }

   bool PathWaypoint::operator==(const PathWaypoint & that)
   {
      if( afrl::cmasi::Waypoint::operator!=(that) )
      {
          return false;
      }
      if(__PauseTime != that.__PauseTime) return false;
      return true;

   }

   bool PathWaypoint::operator!=(const PathWaypoint & that)
   {
      return( !(operator==(that)) );
   }

   PathWaypoint& PathWaypoint::setPauseTime(const int64_t val)
   {
      __PauseTime = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

