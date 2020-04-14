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
#include "uxas/messages/uxnative/SpeedOverrideAction.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SpeedOverrideAction::Subscription = "uxas.messages.uxnative.SpeedOverrideAction";
   const std::string SpeedOverrideAction::TypeName = "SpeedOverrideAction";
   const std::string SpeedOverrideAction::SeriesName = "UXNATIVE";
   const int64_t SpeedOverrideAction::SeriesId = 6149751333668345413LL;
   const uint16_t SpeedOverrideAction::SeriesVersion = 9;
   const uint32_t SpeedOverrideAction::TypeId = 17;
   
   bool isSpeedOverrideAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   bool isSpeedOverrideAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 17) return false;
      return true;
   }
   
   std::vector< std::string > SpeedOverrideActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SpeedOverrideAction::SpeedOverrideAction(void) : afrl::cmasi::VehicleAction()
   {
      __VehicleID = 0LL;
      __Speed = 0.f;

   }
     
   SpeedOverrideAction::SpeedOverrideAction(const SpeedOverrideAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __VehicleID = that.__VehicleID;
        __Speed = that.__Speed;

   }
   
   SpeedOverrideAction & SpeedOverrideAction::operator=(const SpeedOverrideAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __VehicleID = that.__VehicleID;
         __Speed = that.__Speed;

      }
      return *this;
   }

   SpeedOverrideAction* SpeedOverrideAction::clone() const
   {
        return new SpeedOverrideAction(*this);
   }
   
   SpeedOverrideAction::~SpeedOverrideAction(void)
   {

   }
  
   void SpeedOverrideAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putFloat(__Speed);

   }
   
   void SpeedOverrideAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __Speed = buf.getFloat();

   }

   uint32_t SpeedOverrideAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);

      return size;
   }

   std::string SpeedOverrideAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SpeedOverrideAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "Speed (float) = " << __Speed << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SpeedOverrideAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SpeedOverrideAction Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <Speed>" << __Speed << "</Speed>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</SpeedOverrideAction>\n";

      return str.str();
   }

   bool SpeedOverrideAction::operator==(const SpeedOverrideAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__Speed != that.__Speed) return false;
      return true;

   }

   bool SpeedOverrideAction::operator!=(const SpeedOverrideAction & that)
   {
      return( !(operator==(that)) );
   }

   SpeedOverrideAction& SpeedOverrideAction::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   SpeedOverrideAction& SpeedOverrideAction::setSpeed(const float val)
   {
      __Speed = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

