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
#include "afrl/impact/DeployImpactPayload.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string DeployImpactPayload::Subscription = "afrl.impact.DeployImpactPayload";
   const std::string DeployImpactPayload::TypeName = "DeployImpactPayload";
   const std::string DeployImpactPayload::SeriesName = "IMPACT";
   const int64_t DeployImpactPayload::SeriesId = 5281966179208134656LL;
   const uint16_t DeployImpactPayload::SeriesVersion = 14;
   const uint32_t DeployImpactPayload::TypeId = 7;
   
   bool isDeployImpactPayload(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   bool isDeployImpactPayload(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 7) return false;
      return true;
   }
   
   std::vector< std::string > DeployImpactPayloadDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   DeployImpactPayload::DeployImpactPayload(void) : afrl::cmasi::VehicleAction()
   {
      __VehicleID = 0LL;
      __DeployedPayload = afrl::impact::ImpactPayloadType::Unknown;
      __TargetEntityID = 0LL;

   }
     
   DeployImpactPayload::DeployImpactPayload(const DeployImpactPayload &that) : afrl::cmasi::VehicleAction(that)
   {
        __VehicleID = that.__VehicleID;
        __DeployedPayload = that.__DeployedPayload;
        __TargetEntityID = that.__TargetEntityID;

   }
   
   DeployImpactPayload & DeployImpactPayload::operator=(const DeployImpactPayload &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __VehicleID = that.__VehicleID;
         __DeployedPayload = that.__DeployedPayload;
         __TargetEntityID = that.__TargetEntityID;

      }
      return *this;
   }

   DeployImpactPayload* DeployImpactPayload::clone() const
   {
        return new DeployImpactPayload(*this);
   }
   
   DeployImpactPayload::~DeployImpactPayload(void)
   {

   }
  
   void DeployImpactPayload::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putInt( (int32_t) __DeployedPayload);
      buf.putLong(__TargetEntityID);

   }
   
   void DeployImpactPayload::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __DeployedPayload = (afrl::impact::ImpactPayloadType::ImpactPayloadType) buf.getInt();
      __TargetEntityID = buf.getLong();

   }

   uint32_t DeployImpactPayload::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(afrl::impact::ImpactPayloadType::ImpactPayloadType);
      size += sizeof(int64_t);

      return size;
   }

   std::string DeployImpactPayload::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( DeployImpactPayload ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "DeployedPayload (ImpactPayloadType) = " << __DeployedPayload << "\n";
      oss << indent << "TargetEntityID (int64_t) = " << __TargetEntityID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string DeployImpactPayload::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<DeployImpactPayload Series=\"IMPACT\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <DeployedPayload>" << afrl::impact::ImpactPayloadType::get_string(__DeployedPayload) << "</DeployedPayload>\n";
      str << ws << "   <TargetEntityID>" << __TargetEntityID << "</TargetEntityID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</DeployImpactPayload>\n";

      return str.str();
   }

   bool DeployImpactPayload::operator==(const DeployImpactPayload & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__DeployedPayload != that.__DeployedPayload) return false;
      if(__TargetEntityID != that.__TargetEntityID) return false;
      return true;

   }

   bool DeployImpactPayload::operator!=(const DeployImpactPayload & that)
   {
      return( !(operator==(that)) );
   }

   DeployImpactPayload& DeployImpactPayload::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   DeployImpactPayload& DeployImpactPayload::setDeployedPayload(const afrl::impact::ImpactPayloadType::ImpactPayloadType val)
   {
      __DeployedPayload = val;
      return *this;
   }

   DeployImpactPayload& DeployImpactPayload::setTargetEntityID(const int64_t val)
   {
      __TargetEntityID = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

