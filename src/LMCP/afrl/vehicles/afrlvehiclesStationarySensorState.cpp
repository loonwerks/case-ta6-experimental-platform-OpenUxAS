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
#include "afrl/vehicles/StationarySensorState.h"


namespace afrl {
namespace vehicles {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string StationarySensorState::Subscription = "afrl.vehicles.StationarySensorState";
   const std::string StationarySensorState::TypeName = "StationarySensorState";
   const std::string StationarySensorState::SeriesName = "VEHICLES";
   const int64_t StationarySensorState::SeriesId = 6216454340153722195LL;
   const uint16_t StationarySensorState::SeriesVersion = 1;
   const uint32_t StationarySensorState::TypeId = 6;
   
   bool isStationarySensorState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   bool isStationarySensorState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   std::vector< std::string > StationarySensorStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   StationarySensorState::StationarySensorState(void) : afrl::cmasi::EntityState()
   {

   }
     
   StationarySensorState::StationarySensorState(const StationarySensorState &that) : afrl::cmasi::EntityState(that)
   {

   }
   
   StationarySensorState & StationarySensorState::operator=(const StationarySensorState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityState::operator=(that);


      }
      return *this;
   }

   StationarySensorState* StationarySensorState::clone() const
   {
        return new StationarySensorState(*this);
   }
   
   StationarySensorState::~StationarySensorState(void)
   {

   }
  
   void StationarySensorState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityState::pack(buf);
      // Copy the class into the buffer

   }
   
   void StationarySensorState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityState::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t StationarySensorState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityState::calculatePackedSize();

      return size;
   }

   std::string StationarySensorState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( StationarySensorState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ID (int64_t) = " << __ID << "\n";
      oss << indent << "u (float) = " << __u << "\n";
      oss << indent << "v (float) = " << __v << "\n";
      oss << indent << "w (float) = " << __w << "\n";
      oss << indent << "udot (float) = " << __udot << "\n";
      oss << indent << "vdot (float) = " << __vdot << "\n";
      oss << indent << "wdot (float) = " << __wdot << "\n";
      oss << indent << "Heading (float) = " << __Heading << "\n";
      oss << indent << "Pitch (float) = " << __Pitch << "\n";
      oss << indent << "Roll (float) = " << __Roll << "\n";
      oss << indent << "p (float) = " << __p << "\n";
      oss << indent << "q (float) = " << __q << "\n";
      oss << indent << "r (float) = " << __r << "\n";
      oss << indent << "Course (float) = " << __Course << "\n";
      oss << indent << "Groundspeed (float) = " << __Groundspeed << "\n";
      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EnergyAvailable (float) = " << __EnergyAvailable << "\n";
      oss << indent << "ActualEnergyRate (float) = " << __ActualEnergyRate << "\n";
      oss << indent << "PayloadStateList (PayloadState [ " << __PayloadStateList.size() << ", var ])\n";
      oss << indent << "CurrentWaypoint (int64_t) = " << __CurrentWaypoint << "\n";
      oss << indent << "CurrentCommand (int64_t) = " << __CurrentCommand << "\n";
      oss << indent << "Mode (NavigationMode) = " << __Mode << "\n";
      oss << indent << "AssociatedTasks (int64 [ " << __AssociatedTasks.size() << ", var ])\n";
      oss << indent << "Time (int64_t) = " << __Time << "\n";
      oss << indent << "Info (KeyValuePair [ " << __Info.size() << ", var ])\n";


      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string StationarySensorState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<StationarySensorState Series=\"VEHICLES\">\n";
      str << ws << "   <ID>" << __ID << "</ID>\n";
      str << ws << "   <u>" << __u << "</u>\n";
      str << ws << "   <v>" << __v << "</v>\n";
      str << ws << "   <w>" << __w << "</w>\n";
      str << ws << "   <udot>" << __udot << "</udot>\n";
      str << ws << "   <vdot>" << __vdot << "</vdot>\n";
      str << ws << "   <wdot>" << __wdot << "</wdot>\n";
      str << ws << "   <Heading>" << __Heading << "</Heading>\n";
      str << ws << "   <Pitch>" << __Pitch << "</Pitch>\n";
      str << ws << "   <Roll>" << __Roll << "</Roll>\n";
      str << ws << "   <p>" << __p << "</p>\n";
      str << ws << "   <q>" << __q << "</q>\n";
      str << ws << "   <r>" << __r << "</r>\n";
      str << ws << "   <Course>" << __Course << "</Course>\n";
      str << ws << "   <Groundspeed>" << __Groundspeed << "</Groundspeed>\n";
      if (__Location != nullptr)
      {
         str << ws << "   <Location>";
         str << "\n" + __Location->toXML(depth + 1) + ws + "   ";
         str << "</Location>\n";
      }
      str << ws << "   <EnergyAvailable>" << __EnergyAvailable << "</EnergyAvailable>\n";
      str << ws << "   <ActualEnergyRate>" << __ActualEnergyRate << "</ActualEnergyRate>\n";
      str << ws << "   <PayloadStateList>\n";
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         str << (__PayloadStateList[i] == nullptr ? ( ws + "   <null/>\n") : (__PayloadStateList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PayloadStateList>\n";
      str << ws << "   <CurrentWaypoint>" << __CurrentWaypoint << "</CurrentWaypoint>\n";
      str << ws << "   <CurrentCommand>" << __CurrentCommand << "</CurrentCommand>\n";
      str << ws << "   <Mode>" << afrl::cmasi::NavigationMode::get_string(__Mode) << "</Mode>\n";
      str << ws << "   <AssociatedTasks>\n";
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTasks[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTasks>\n";
      str << ws << "   <Time>" << __Time << "</Time>\n";
      str << ws << "   <Info>\n";
      for (size_t i=0; i<__Info.size(); i++)
      {
         str << (__Info[i] == nullptr ? ( ws + "   <null/>\n") : (__Info[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Info>\n";
      str << ws << "</StationarySensorState>\n";

      return str.str();
   }

   bool StationarySensorState::operator==(const StationarySensorState & that)
   {
      if( afrl::cmasi::EntityState::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool StationarySensorState::operator!=(const StationarySensorState & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace vehicles
} // end namespace afrl

