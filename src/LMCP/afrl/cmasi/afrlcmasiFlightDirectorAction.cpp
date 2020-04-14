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
#include "afrl/cmasi/FlightDirectorAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FlightDirectorAction::Subscription = "afrl.cmasi.FlightDirectorAction";
   const std::string FlightDirectorAction::TypeName = "FlightDirectorAction";
   const std::string FlightDirectorAction::SeriesName = "CMASI";
   const int64_t FlightDirectorAction::SeriesId = 4849604199710720000LL;
   const uint16_t FlightDirectorAction::SeriesVersion = 3;
   const uint32_t FlightDirectorAction::TypeId = 54;
   
   bool isFlightDirectorAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 54) return false;
      return true;
   }
   
   bool isFlightDirectorAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 54) return false;
      return true;
   }
   
   std::vector< std::string > FlightDirectorActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FlightDirectorAction::FlightDirectorAction(void) : afrl::cmasi::NavigationAction()
   {
      __Speed = 0.f;
      __SpeedType = afrl::cmasi::SpeedType::Airspeed;
      __Heading = 0.f;
      __Altitude = 0.f;
      __AltitudeType = afrl::cmasi::AltitudeType::MSL;
      __ClimbRate = 0.f;

   }
     
   FlightDirectorAction::FlightDirectorAction(const FlightDirectorAction &that) : afrl::cmasi::NavigationAction(that)
   {
        __Speed = that.__Speed;
        __SpeedType = that.__SpeedType;
        __Heading = that.__Heading;
        __Altitude = that.__Altitude;
        __AltitudeType = that.__AltitudeType;
        __ClimbRate = that.__ClimbRate;

   }
   
   FlightDirectorAction & FlightDirectorAction::operator=(const FlightDirectorAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::NavigationAction::operator=(that);

         __Speed = that.__Speed;
         __SpeedType = that.__SpeedType;
         __Heading = that.__Heading;
         __Altitude = that.__Altitude;
         __AltitudeType = that.__AltitudeType;
         __ClimbRate = that.__ClimbRate;

      }
      return *this;
   }

   FlightDirectorAction* FlightDirectorAction::clone() const
   {
        return new FlightDirectorAction(*this);
   }
   
   FlightDirectorAction::~FlightDirectorAction(void)
   {

   }
  
   void FlightDirectorAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::NavigationAction::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__Speed);
      buf.putInt( (int32_t) __SpeedType);
      buf.putFloat(__Heading);
      buf.putFloat(__Altitude);
      buf.putInt( (int32_t) __AltitudeType);
      buf.putFloat(__ClimbRate);

   }
   
   void FlightDirectorAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::NavigationAction::unpack(buf);
      // Copy the buffer into the class
      __Speed = buf.getFloat();
      __SpeedType = (afrl::cmasi::SpeedType::SpeedType) buf.getInt();
      __Heading = buf.getFloat();
      __Altitude = buf.getFloat();
      __AltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      __ClimbRate = buf.getFloat();

   }

   uint32_t FlightDirectorAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::NavigationAction::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(afrl::cmasi::SpeedType::SpeedType);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += sizeof(float);

      return size;
   }

   std::string FlightDirectorAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FlightDirectorAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";


      oss << indent << "Speed (float) = " << __Speed << "\n";
      oss << indent << "SpeedType (SpeedType) = " << __SpeedType << "\n";
      oss << indent << "Heading (float) = " << __Heading << "\n";
      oss << indent << "Altitude (float) = " << __Altitude << "\n";
      oss << indent << "AltitudeType (AltitudeType) = " << __AltitudeType << "\n";
      oss << indent << "ClimbRate (float) = " << __ClimbRate << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FlightDirectorAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FlightDirectorAction Series=\"CMASI\">\n";
      str << ws << "   <Speed>" << __Speed << "</Speed>\n";
      str << ws << "   <SpeedType>" << afrl::cmasi::SpeedType::get_string(__SpeedType) << "</SpeedType>\n";
      str << ws << "   <Heading>" << __Heading << "</Heading>\n";
      str << ws << "   <Altitude>" << __Altitude << "</Altitude>\n";
      str << ws << "   <AltitudeType>" << afrl::cmasi::AltitudeType::get_string(__AltitudeType) << "</AltitudeType>\n";
      str << ws << "   <ClimbRate>" << __ClimbRate << "</ClimbRate>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</FlightDirectorAction>\n";

      return str.str();
   }

   bool FlightDirectorAction::operator==(const FlightDirectorAction & that)
   {
      if( afrl::cmasi::NavigationAction::operator!=(that) )
      {
          return false;
      }
      if(__Speed != that.__Speed) return false;
      if(__SpeedType != that.__SpeedType) return false;
      if(__Heading != that.__Heading) return false;
      if(__Altitude != that.__Altitude) return false;
      if(__AltitudeType != that.__AltitudeType) return false;
      if(__ClimbRate != that.__ClimbRate) return false;
      return true;

   }

   bool FlightDirectorAction::operator!=(const FlightDirectorAction & that)
   {
      return( !(operator==(that)) );
   }

   FlightDirectorAction& FlightDirectorAction::setSpeed(const float val)
   {
      __Speed = val;
      return *this;
   }

   FlightDirectorAction& FlightDirectorAction::setSpeedType(const afrl::cmasi::SpeedType::SpeedType val)
   {
      __SpeedType = val;
      return *this;
   }

   FlightDirectorAction& FlightDirectorAction::setHeading(const float val)
   {
      __Heading = val;
      return *this;
   }

   FlightDirectorAction& FlightDirectorAction::setAltitude(const float val)
   {
      __Altitude = val;
      return *this;
   }

   FlightDirectorAction& FlightDirectorAction::setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __AltitudeType = val;
      return *this;
   }

   FlightDirectorAction& FlightDirectorAction::setClimbRate(const float val)
   {
      __ClimbRate = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

