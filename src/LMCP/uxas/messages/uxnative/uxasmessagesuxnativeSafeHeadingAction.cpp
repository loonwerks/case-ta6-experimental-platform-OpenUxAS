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
#include "uxas/messages/uxnative/SafeHeadingAction.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SafeHeadingAction::Subscription = "uxas.messages.uxnative.SafeHeadingAction";
   const std::string SafeHeadingAction::TypeName = "SafeHeadingAction";
   const std::string SafeHeadingAction::SeriesName = "UXNATIVE";
   const int64_t SafeHeadingAction::SeriesId = 6149751333668345413LL;
   const uint16_t SafeHeadingAction::SeriesVersion = 9;
   const uint32_t SafeHeadingAction::TypeId = 6;
   
   bool isSafeHeadingAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   bool isSafeHeadingAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   std::vector< std::string > SafeHeadingActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SafeHeadingAction::SafeHeadingAction(void) : afrl::cmasi::VehicleAction()
   {
      __VehicleID = 0LL;
      __OperatingRegion = 0LL;
      __LeadAheadDistance = 1000.0f;
      __LoiterRadius = 0.0f;
      __DesiredHeading = 0.f;
      __DesiredHeadingRate = 0.f;
      __UseHeadingRate = false;
      __Altitude = 0.f;
      __AltitudeType = afrl::cmasi::AltitudeType::MSL;
      __UseAltitude = false;
      __Speed = 0.f;
      __UseSpeed = false;

   }
     
   SafeHeadingAction::SafeHeadingAction(const SafeHeadingAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __VehicleID = that.__VehicleID;
        __OperatingRegion = that.__OperatingRegion;
        __LeadAheadDistance = that.__LeadAheadDistance;
        __LoiterRadius = that.__LoiterRadius;
        __DesiredHeading = that.__DesiredHeading;
        __DesiredHeadingRate = that.__DesiredHeadingRate;
        __UseHeadingRate = that.__UseHeadingRate;
        __Altitude = that.__Altitude;
        __AltitudeType = that.__AltitudeType;
        __UseAltitude = that.__UseAltitude;
        __Speed = that.__Speed;
        __UseSpeed = that.__UseSpeed;

   }
   
   SafeHeadingAction & SafeHeadingAction::operator=(const SafeHeadingAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __VehicleID = that.__VehicleID;
         __OperatingRegion = that.__OperatingRegion;
         __LeadAheadDistance = that.__LeadAheadDistance;
         __LoiterRadius = that.__LoiterRadius;
         __DesiredHeading = that.__DesiredHeading;
         __DesiredHeadingRate = that.__DesiredHeadingRate;
         __UseHeadingRate = that.__UseHeadingRate;
         __Altitude = that.__Altitude;
         __AltitudeType = that.__AltitudeType;
         __UseAltitude = that.__UseAltitude;
         __Speed = that.__Speed;
         __UseSpeed = that.__UseSpeed;

      }
      return *this;
   }

   SafeHeadingAction* SafeHeadingAction::clone() const
   {
        return new SafeHeadingAction(*this);
   }
   
   SafeHeadingAction::~SafeHeadingAction(void)
   {

   }
  
   void SafeHeadingAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__OperatingRegion);
      buf.putFloat(__LeadAheadDistance);
      buf.putFloat(__LoiterRadius);
      buf.putFloat(__DesiredHeading);
      buf.putFloat(__DesiredHeadingRate);
      buf.putBool(__UseHeadingRate);
      buf.putFloat(__Altitude);
      buf.putInt( (int32_t) __AltitudeType);
      buf.putBool(__UseAltitude);
      buf.putFloat(__Speed);
      buf.putBool(__UseSpeed);

   }
   
   void SafeHeadingAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __OperatingRegion = buf.getLong();
      __LeadAheadDistance = buf.getFloat();
      __LoiterRadius = buf.getFloat();
      __DesiredHeading = buf.getFloat();
      __DesiredHeadingRate = buf.getFloat();
      __UseHeadingRate = buf.getBool();
      __Altitude = buf.getFloat();
      __AltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      __UseAltitude = buf.getBool();
      __Speed = buf.getFloat();
      __UseSpeed = buf.getBool();

   }

   uint32_t SafeHeadingAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(bool);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += sizeof(bool);
      size += sizeof(float);
      size += sizeof(bool);

      return size;
   }

   std::string SafeHeadingAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SafeHeadingAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "LeadAheadDistance (float) = " << __LeadAheadDistance << "\n";
      oss << indent << "LoiterRadius (float) = " << __LoiterRadius << "\n";
      oss << indent << "DesiredHeading (float) = " << __DesiredHeading << "\n";
      oss << indent << "DesiredHeadingRate (float) = " << __DesiredHeadingRate << "\n";
      oss << indent << "UseHeadingRate (bool) = " << __UseHeadingRate << "\n";
      oss << indent << "Altitude (float) = " << __Altitude << "\n";
      oss << indent << "AltitudeType (AltitudeType) = " << __AltitudeType << "\n";
      oss << indent << "UseAltitude (bool) = " << __UseAltitude << "\n";
      oss << indent << "Speed (float) = " << __Speed << "\n";
      oss << indent << "UseSpeed (bool) = " << __UseSpeed << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SafeHeadingAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SafeHeadingAction Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <LeadAheadDistance>" << __LeadAheadDistance << "</LeadAheadDistance>\n";
      str << ws << "   <LoiterRadius>" << __LoiterRadius << "</LoiterRadius>\n";
      str << ws << "   <DesiredHeading>" << __DesiredHeading << "</DesiredHeading>\n";
      str << ws << "   <DesiredHeadingRate>" << __DesiredHeadingRate << "</DesiredHeadingRate>\n";
      str << ws << "   <UseHeadingRate>" << (__UseHeadingRate ? "true" : "false") << "</UseHeadingRate>\n";
      str << ws << "   <Altitude>" << __Altitude << "</Altitude>\n";
      str << ws << "   <AltitudeType>" << afrl::cmasi::AltitudeType::get_string(__AltitudeType) << "</AltitudeType>\n";
      str << ws << "   <UseAltitude>" << (__UseAltitude ? "true" : "false") << "</UseAltitude>\n";
      str << ws << "   <Speed>" << __Speed << "</Speed>\n";
      str << ws << "   <UseSpeed>" << (__UseSpeed ? "true" : "false") << "</UseSpeed>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</SafeHeadingAction>\n";

      return str.str();
   }

   bool SafeHeadingAction::operator==(const SafeHeadingAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__LeadAheadDistance != that.__LeadAheadDistance) return false;
      if(__LoiterRadius != that.__LoiterRadius) return false;
      if(__DesiredHeading != that.__DesiredHeading) return false;
      if(__DesiredHeadingRate != that.__DesiredHeadingRate) return false;
      if(__UseHeadingRate != that.__UseHeadingRate) return false;
      if(__Altitude != that.__Altitude) return false;
      if(__AltitudeType != that.__AltitudeType) return false;
      if(__UseAltitude != that.__UseAltitude) return false;
      if(__Speed != that.__Speed) return false;
      if(__UseSpeed != that.__UseSpeed) return false;
      return true;

   }

   bool SafeHeadingAction::operator!=(const SafeHeadingAction & that)
   {
      return( !(operator==(that)) );
   }

   SafeHeadingAction& SafeHeadingAction::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setLeadAheadDistance(const float val)
   {
      __LeadAheadDistance = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setLoiterRadius(const float val)
   {
      __LoiterRadius = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setDesiredHeading(const float val)
   {
      __DesiredHeading = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setDesiredHeadingRate(const float val)
   {
      __DesiredHeadingRate = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setUseHeadingRate(const bool val)
   {
      __UseHeadingRate = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setAltitude(const float val)
   {
      __Altitude = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __AltitudeType = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setUseAltitude(const bool val)
   {
      __UseAltitude = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setSpeed(const float val)
   {
      __Speed = val;
      return *this;
   }

   SafeHeadingAction& SafeHeadingAction::setUseSpeed(const bool val)
   {
      __UseSpeed = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

