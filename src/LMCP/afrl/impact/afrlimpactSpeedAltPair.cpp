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
#include "afrl/impact/SpeedAltPair.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SpeedAltPair::Subscription = "afrl.impact.SpeedAltPair";
   const std::string SpeedAltPair::TypeName = "SpeedAltPair";
   const std::string SpeedAltPair::SeriesName = "IMPACT";
   const int64_t SpeedAltPair::SeriesId = 5281966179208134656LL;
   const uint16_t SpeedAltPair::SeriesVersion = 14;
   const uint32_t SpeedAltPair::TypeId = 16;
   
   bool isSpeedAltPair(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   bool isSpeedAltPair(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   std::vector< std::string > SpeedAltPairDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SpeedAltPair::SpeedAltPair(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __TaskID = 0LL;
      __Speed = 0.f;
      __Altitude = 0.f;
      __AltitudeType = afrl::cmasi::AltitudeType::AGL;

   }
     
   SpeedAltPair::SpeedAltPair(const SpeedAltPair &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __TaskID = that.__TaskID;
        __Speed = that.__Speed;
        __Altitude = that.__Altitude;
        __AltitudeType = that.__AltitudeType;

   }
   
   SpeedAltPair & SpeedAltPair::operator=(const SpeedAltPair &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;
         __TaskID = that.__TaskID;
         __Speed = that.__Speed;
         __Altitude = that.__Altitude;
         __AltitudeType = that.__AltitudeType;

      }
      return *this;
   }

   SpeedAltPair* SpeedAltPair::clone() const
   {
        return new SpeedAltPair(*this);
   }
   
   SpeedAltPair::~SpeedAltPair(void)
   {

   }
  
   void SpeedAltPair::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__TaskID);
      buf.putFloat(__Speed);
      buf.putFloat(__Altitude);
      buf.putInt( (int32_t) __AltitudeType);

   }
   
   void SpeedAltPair::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __TaskID = buf.getLong();
      __Speed = buf.getFloat();
      __Altitude = buf.getFloat();
      __AltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();

   }

   uint32_t SpeedAltPair::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);

      return size;
   }

   std::string SpeedAltPair::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SpeedAltPair ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Speed (float) = " << __Speed << "\n";
      oss << indent << "Altitude (float) = " << __Altitude << "\n";
      oss << indent << "AltitudeType (AltitudeType) = " << __AltitudeType << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SpeedAltPair::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SpeedAltPair Series=\"IMPACT\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <Speed>" << __Speed << "</Speed>\n";
      str << ws << "   <Altitude>" << __Altitude << "</Altitude>\n";
      str << ws << "   <AltitudeType>" << afrl::cmasi::AltitudeType::get_string(__AltitudeType) << "</AltitudeType>\n";
      str << ws << "</SpeedAltPair>\n";

      return str.str();
   }

   bool SpeedAltPair::operator==(const SpeedAltPair & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__TaskID != that.__TaskID) return false;
      if(__Speed != that.__Speed) return false;
      if(__Altitude != that.__Altitude) return false;
      if(__AltitudeType != that.__AltitudeType) return false;
      return true;

   }

   bool SpeedAltPair::operator!=(const SpeedAltPair & that)
   {
      return( !(operator==(that)) );
   }

   SpeedAltPair& SpeedAltPair::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   SpeedAltPair& SpeedAltPair::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   SpeedAltPair& SpeedAltPair::setSpeed(const float val)
   {
      __Speed = val;
      return *this;
   }

   SpeedAltPair& SpeedAltPair::setAltitude(const float val)
   {
      __Altitude = val;
      return *this;
   }

   SpeedAltPair& SpeedAltPair::setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __AltitudeType = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

