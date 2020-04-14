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
#include "afrl/cmasi/FlightProfile.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FlightProfile::Subscription = "afrl.cmasi.FlightProfile";
   const std::string FlightProfile::TypeName = "FlightProfile";
   const std::string FlightProfile::SeriesName = "CMASI";
   const int64_t FlightProfile::SeriesId = 4849604199710720000LL;
   const uint16_t FlightProfile::SeriesVersion = 3;
   const uint32_t FlightProfile::TypeId = 12;
   
   bool isFlightProfile(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   bool isFlightProfile(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   std::vector< std::string > FlightProfileDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FlightProfile::FlightProfile(void) : avtas::lmcp::Object()
   {
      __Name = std::string("");
      __Airspeed = 0.f;
      __PitchAngle = 0.f;
      __VerticalSpeed = 0.f;
      __MaxBankAngle = 0.f;
      __EnergyRate = 0.f;

   }
     
   FlightProfile::FlightProfile(const FlightProfile &that) : avtas::lmcp::Object(that)
   {
        __Name = that.__Name;
        __Airspeed = that.__Airspeed;
        __PitchAngle = that.__PitchAngle;
        __VerticalSpeed = that.__VerticalSpeed;
        __MaxBankAngle = that.__MaxBankAngle;
        __EnergyRate = that.__EnergyRate;

   }
   
   FlightProfile & FlightProfile::operator=(const FlightProfile &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Name = that.__Name;
         __Airspeed = that.__Airspeed;
         __PitchAngle = that.__PitchAngle;
         __VerticalSpeed = that.__VerticalSpeed;
         __MaxBankAngle = that.__MaxBankAngle;
         __EnergyRate = that.__EnergyRate;

      }
      return *this;
   }

   FlightProfile* FlightProfile::clone() const
   {
        return new FlightProfile(*this);
   }
   
   FlightProfile::~FlightProfile(void)
   {

   }
  
   void FlightProfile::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putString(__Name);
      buf.putFloat(__Airspeed);
      buf.putFloat(__PitchAngle);
      buf.putFloat(__VerticalSpeed);
      buf.putFloat(__MaxBankAngle);
      buf.putFloat(__EnergyRate);

   }
   
   void FlightProfile::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Name = buf.getString();
      __Airspeed = buf.getFloat();
      __PitchAngle = buf.getFloat();
      __VerticalSpeed = buf.getFloat();
      __MaxBankAngle = buf.getFloat();
      __EnergyRate = buf.getFloat();

   }

   uint32_t FlightProfile::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + __Name.length();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string FlightProfile::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FlightProfile ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Name (std::string) = " << __Name << "\n";
      oss << indent << "Airspeed (float) = " << __Airspeed << "\n";
      oss << indent << "PitchAngle (float) = " << __PitchAngle << "\n";
      oss << indent << "VerticalSpeed (float) = " << __VerticalSpeed << "\n";
      oss << indent << "MaxBankAngle (float) = " << __MaxBankAngle << "\n";
      oss << indent << "EnergyRate (float) = " << __EnergyRate << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FlightProfile::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FlightProfile Series=\"CMASI\">\n";
      str << ws << "   <Name>" << __Name << "</Name>\n";
      str << ws << "   <Airspeed>" << __Airspeed << "</Airspeed>\n";
      str << ws << "   <PitchAngle>" << __PitchAngle << "</PitchAngle>\n";
      str << ws << "   <VerticalSpeed>" << __VerticalSpeed << "</VerticalSpeed>\n";
      str << ws << "   <MaxBankAngle>" << __MaxBankAngle << "</MaxBankAngle>\n";
      str << ws << "   <EnergyRate>" << __EnergyRate << "</EnergyRate>\n";
      str << ws << "</FlightProfile>\n";

      return str.str();
   }

   bool FlightProfile::operator==(const FlightProfile & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Name != that.__Name) return false;
      if(__Airspeed != that.__Airspeed) return false;
      if(__PitchAngle != that.__PitchAngle) return false;
      if(__VerticalSpeed != that.__VerticalSpeed) return false;
      if(__MaxBankAngle != that.__MaxBankAngle) return false;
      if(__EnergyRate != that.__EnergyRate) return false;
      return true;

   }

   bool FlightProfile::operator!=(const FlightProfile & that)
   {
      return( !(operator==(that)) );
   }

   FlightProfile& FlightProfile::setName(const std::string val)
   {
      __Name = val;
      return *this;
   }

   FlightProfile& FlightProfile::setAirspeed(const float val)
   {
      __Airspeed = val;
      return *this;
   }

   FlightProfile& FlightProfile::setPitchAngle(const float val)
   {
      __PitchAngle = val;
      return *this;
   }

   FlightProfile& FlightProfile::setVerticalSpeed(const float val)
   {
      __VerticalSpeed = val;
      return *this;
   }

   FlightProfile& FlightProfile::setMaxBankAngle(const float val)
   {
      __MaxBankAngle = val;
      return *this;
   }

   FlightProfile& FlightProfile::setEnergyRate(const float val)
   {
      __EnergyRate = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

