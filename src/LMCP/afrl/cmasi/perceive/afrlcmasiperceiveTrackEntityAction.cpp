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
#include "afrl/cmasi/perceive/TrackEntityAction.h"


namespace afrl {
namespace cmasi {
namespace perceive {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TrackEntityAction::Subscription = "afrl.cmasi.perceive.TrackEntityAction";
   const std::string TrackEntityAction::TypeName = "TrackEntityAction";
   const std::string TrackEntityAction::SeriesName = "PERCEIVE";
   const int64_t TrackEntityAction::SeriesId = 5784119745305990725LL;
   const uint16_t TrackEntityAction::SeriesVersion = 1;
   const uint32_t TrackEntityAction::TypeId = 2;
   
   bool isTrackEntityAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isTrackEntityAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > TrackEntityActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TrackEntityAction::TrackEntityAction(void) : afrl::cmasi::VehicleAction()
   {
      __EntityID = 0;
      __SensorID = 0;
      __ReturnToWaypoint = 0;

   }
     
   TrackEntityAction::TrackEntityAction(const TrackEntityAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __EntityID = that.__EntityID;
        __SensorID = that.__SensorID;
        __ReturnToWaypoint = that.__ReturnToWaypoint;

   }
   
   TrackEntityAction & TrackEntityAction::operator=(const TrackEntityAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __EntityID = that.__EntityID;
         __SensorID = that.__SensorID;
         __ReturnToWaypoint = that.__ReturnToWaypoint;

      }
      return *this;
   }

   TrackEntityAction* TrackEntityAction::clone() const
   {
        return new TrackEntityAction(*this);
   }
   
   TrackEntityAction::~TrackEntityAction(void)
   {

   }
  
   void TrackEntityAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putUInt(__EntityID);
      buf.putUInt(__SensorID);
      buf.putUInt(__ReturnToWaypoint);

   }
   
   void TrackEntityAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getUInt();
      __SensorID = buf.getUInt();
      __ReturnToWaypoint = buf.getUInt();

   }

   uint32_t TrackEntityAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(uint32_t);
      size += sizeof(uint32_t);
      size += sizeof(uint32_t);

      return size;
   }

   std::string TrackEntityAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TrackEntityAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "EntityID (uint32_t) = " << __EntityID << "\n";
      oss << indent << "SensorID (uint32_t) = " << __SensorID << "\n";
      oss << indent << "ReturnToWaypoint (uint32_t) = " << __ReturnToWaypoint << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TrackEntityAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TrackEntityAction Series=\"PERCEIVE\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <SensorID>" << __SensorID << "</SensorID>\n";
      str << ws << "   <ReturnToWaypoint>" << __ReturnToWaypoint << "</ReturnToWaypoint>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</TrackEntityAction>\n";

      return str.str();
   }

   bool TrackEntityAction::operator==(const TrackEntityAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__SensorID != that.__SensorID) return false;
      if(__ReturnToWaypoint != that.__ReturnToWaypoint) return false;
      return true;

   }

   bool TrackEntityAction::operator!=(const TrackEntityAction & that)
   {
      return( !(operator==(that)) );
   }

   TrackEntityAction& TrackEntityAction::setEntityID(const uint32_t val)
   {
      __EntityID = val;
      return *this;
   }

   TrackEntityAction& TrackEntityAction::setSensorID(const uint32_t val)
   {
      __SensorID = val;
      return *this;
   }

   TrackEntityAction& TrackEntityAction::setReturnToWaypoint(const uint32_t val)
   {
      __ReturnToWaypoint = val;
      return *this;
   }


} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl

