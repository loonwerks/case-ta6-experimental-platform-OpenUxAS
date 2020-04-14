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
#include "afrl/cmasi/VehicleAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VehicleAction::Subscription = "afrl.cmasi.VehicleAction";
   const std::string VehicleAction::TypeName = "VehicleAction";
   const std::string VehicleAction::SeriesName = "CMASI";
   const int64_t VehicleAction::SeriesId = 4849604199710720000LL;
   const uint16_t VehicleAction::SeriesVersion = 3;
   const uint32_t VehicleAction::TypeId = 7;
   
   bool isVehicleAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   bool isVehicleAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   std::vector< std::string > VehicleActionDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("uxas.messages.uxnative.SafeHeadingAction");
       descendants.push_back("uxas.messages.uxnative.SpeedOverrideAction");
       descendants.push_back("afrl.cmasi.perceive.TrackEntityAction");
       descendants.push_back("afrl.impact.DeployImpactPayload");
       descendants.push_back("afrl.cmasi.PayloadAction");
       descendants.push_back("afrl.cmasi.CameraAction");
       descendants.push_back("afrl.cmasi.GimbalAngleAction");
       descendants.push_back("afrl.cmasi.GimbalScanAction");
       descendants.push_back("afrl.cmasi.GimbalStareAction");
       descendants.push_back("afrl.cmasi.NavigationAction");
       descendants.push_back("afrl.cmasi.GoToWaypointAction");
       descendants.push_back("afrl.cmasi.LoiterAction");
       descendants.push_back("afrl.cmasi.FlightDirectorAction");
       descendants.push_back("afrl.cmasi.VideoStreamAction");
       descendants.push_back("afrl.cmasi.StopMovementAction");

       return descendants;
   }
   
   VehicleAction::VehicleAction(void) : avtas::lmcp::Object()
   {

   }
     
   VehicleAction::VehicleAction(const VehicleAction &that) : avtas::lmcp::Object(that)
   {
        __AssociatedTaskList.clear();
        for (size_t i=0; i< that.__AssociatedTaskList.size(); i++)
        {
           __AssociatedTaskList.push_back( that.__AssociatedTaskList[i]);
        }

   }
   
   VehicleAction & VehicleAction::operator=(const VehicleAction &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __AssociatedTaskList.clear();
         for (size_t i=0; i< that.__AssociatedTaskList.size(); i++)
         {
            __AssociatedTaskList.push_back( that.__AssociatedTaskList[i]);
         }

      }
      return *this;
   }

   VehicleAction* VehicleAction::clone() const
   {
        return new VehicleAction(*this);
   }
   
   VehicleAction::~VehicleAction(void)
   {

   }
  
   void VehicleAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__AssociatedTaskList.size()));
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         buf.putLong(__AssociatedTaskList[i]);
      }

   }
   
   void VehicleAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __AssociatedTaskList.clear();
      uint16_t __AssociatedTaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __AssociatedTaskList_length; i++)
      {
         __AssociatedTaskList.push_back(buf.getLong() );
      }

   }

   uint32_t VehicleAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __AssociatedTaskList.size();

      return size;
   }

   std::string VehicleAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VehicleAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VehicleAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VehicleAction Series=\"CMASI\">\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</VehicleAction>\n";

      return str.str();
   }

   bool VehicleAction::operator==(const VehicleAction & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__AssociatedTaskList.size() != that.__AssociatedTaskList.size()) return false;
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         if(__AssociatedTaskList[i] != that.__AssociatedTaskList[i]) return false;
      }
      return true;

   }

   bool VehicleAction::operator!=(const VehicleAction & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

