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
#include "uxas/messages/task/SensorFootprint.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SensorFootprint::Subscription = "uxas.messages.task.SensorFootprint";
   const std::string SensorFootprint::TypeName = "SensorFootprint";
   const std::string SensorFootprint::SeriesName = "UXTASK";
   const int64_t SensorFootprint::SeriesId = 6149757930721443840LL;
   const uint16_t SensorFootprint::SeriesVersion = 8;
   const uint32_t SensorFootprint::TypeId = 12;
   
   bool isSensorFootprint(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   bool isSensorFootprint(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   std::vector< std::string > SensorFootprintDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SensorFootprint::SensorFootprint(void) : avtas::lmcp::Object()
   {
      __FootprintResponseID = 0LL;
      __VehicleID = 0LL;
      __CameraID = 0LL;
      __GimbalID = 0LL;
      __HorizontalFOV = 0.f;
      __AglAltitude = 0.f;
      __GimbalElevation = 0.f;
      __AspectRatio = 0.f;
      __AchievedGSD = 0.f;
      __CameraWavelength = afrl::cmasi::WavelengthBand::AllAny;
      __HorizontalToLeadingEdge = 0.f;
      __HorizontalToTrailingEdge = 0.f;
      __HorizontalToCenter = 0.f;
      __WidthCenter = 0.f;
      __SlantRangeToCenter = 0.f;

   }
     
   SensorFootprint::SensorFootprint(const SensorFootprint &that) : avtas::lmcp::Object(that)
   {
        __FootprintResponseID = that.__FootprintResponseID;
        __VehicleID = that.__VehicleID;
        __CameraID = that.__CameraID;
        __GimbalID = that.__GimbalID;
        __HorizontalFOV = that.__HorizontalFOV;
        __AglAltitude = that.__AglAltitude;
        __GimbalElevation = that.__GimbalElevation;
        __AspectRatio = that.__AspectRatio;
        __AchievedGSD = that.__AchievedGSD;
        __CameraWavelength = that.__CameraWavelength;
        __HorizontalToLeadingEdge = that.__HorizontalToLeadingEdge;
        __HorizontalToTrailingEdge = that.__HorizontalToTrailingEdge;
        __HorizontalToCenter = that.__HorizontalToCenter;
        __WidthCenter = that.__WidthCenter;
        __SlantRangeToCenter = that.__SlantRangeToCenter;

   }
   
   SensorFootprint & SensorFootprint::operator=(const SensorFootprint &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __FootprintResponseID = that.__FootprintResponseID;
         __VehicleID = that.__VehicleID;
         __CameraID = that.__CameraID;
         __GimbalID = that.__GimbalID;
         __HorizontalFOV = that.__HorizontalFOV;
         __AglAltitude = that.__AglAltitude;
         __GimbalElevation = that.__GimbalElevation;
         __AspectRatio = that.__AspectRatio;
         __AchievedGSD = that.__AchievedGSD;
         __CameraWavelength = that.__CameraWavelength;
         __HorizontalToLeadingEdge = that.__HorizontalToLeadingEdge;
         __HorizontalToTrailingEdge = that.__HorizontalToTrailingEdge;
         __HorizontalToCenter = that.__HorizontalToCenter;
         __WidthCenter = that.__WidthCenter;
         __SlantRangeToCenter = that.__SlantRangeToCenter;

      }
      return *this;
   }

   SensorFootprint* SensorFootprint::clone() const
   {
        return new SensorFootprint(*this);
   }
   
   SensorFootprint::~SensorFootprint(void)
   {

   }
  
   void SensorFootprint::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__FootprintResponseID);
      buf.putLong(__VehicleID);
      buf.putLong(__CameraID);
      buf.putLong(__GimbalID);
      buf.putFloat(__HorizontalFOV);
      buf.putFloat(__AglAltitude);
      buf.putFloat(__GimbalElevation);
      buf.putFloat(__AspectRatio);
      buf.putFloat(__AchievedGSD);
      buf.putInt( (int32_t) __CameraWavelength);
      buf.putFloat(__HorizontalToLeadingEdge);
      buf.putFloat(__HorizontalToTrailingEdge);
      buf.putFloat(__HorizontalToCenter);
      buf.putFloat(__WidthCenter);
      buf.putFloat(__SlantRangeToCenter);

   }
   
   void SensorFootprint::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __FootprintResponseID = buf.getLong();
      __VehicleID = buf.getLong();
      __CameraID = buf.getLong();
      __GimbalID = buf.getLong();
      __HorizontalFOV = buf.getFloat();
      __AglAltitude = buf.getFloat();
      __GimbalElevation = buf.getFloat();
      __AspectRatio = buf.getFloat();
      __AchievedGSD = buf.getFloat();
      __CameraWavelength = (afrl::cmasi::WavelengthBand::WavelengthBand) buf.getInt();
      __HorizontalToLeadingEdge = buf.getFloat();
      __HorizontalToTrailingEdge = buf.getFloat();
      __HorizontalToCenter = buf.getFloat();
      __WidthCenter = buf.getFloat();
      __SlantRangeToCenter = buf.getFloat();

   }

   uint32_t SensorFootprint::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::WavelengthBand::WavelengthBand);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string SensorFootprint::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SensorFootprint ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "FootprintResponseID (int64_t) = " << __FootprintResponseID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "CameraID (int64_t) = " << __CameraID << "\n";
      oss << indent << "GimbalID (int64_t) = " << __GimbalID << "\n";
      oss << indent << "HorizontalFOV (float) = " << __HorizontalFOV << "\n";
      oss << indent << "AglAltitude (float) = " << __AglAltitude << "\n";
      oss << indent << "GimbalElevation (float) = " << __GimbalElevation << "\n";
      oss << indent << "AspectRatio (float) = " << __AspectRatio << "\n";
      oss << indent << "AchievedGSD (float) = " << __AchievedGSD << "\n";
      oss << indent << "CameraWavelength (WavelengthBand) = " << __CameraWavelength << "\n";
      oss << indent << "HorizontalToLeadingEdge (float) = " << __HorizontalToLeadingEdge << "\n";
      oss << indent << "HorizontalToTrailingEdge (float) = " << __HorizontalToTrailingEdge << "\n";
      oss << indent << "HorizontalToCenter (float) = " << __HorizontalToCenter << "\n";
      oss << indent << "WidthCenter (float) = " << __WidthCenter << "\n";
      oss << indent << "SlantRangeToCenter (float) = " << __SlantRangeToCenter << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SensorFootprint::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SensorFootprint Series=\"UXTASK\">\n";
      str << ws << "   <FootprintResponseID>" << __FootprintResponseID << "</FootprintResponseID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <CameraID>" << __CameraID << "</CameraID>\n";
      str << ws << "   <GimbalID>" << __GimbalID << "</GimbalID>\n";
      str << ws << "   <HorizontalFOV>" << __HorizontalFOV << "</HorizontalFOV>\n";
      str << ws << "   <AglAltitude>" << __AglAltitude << "</AglAltitude>\n";
      str << ws << "   <GimbalElevation>" << __GimbalElevation << "</GimbalElevation>\n";
      str << ws << "   <AspectRatio>" << __AspectRatio << "</AspectRatio>\n";
      str << ws << "   <AchievedGSD>" << __AchievedGSD << "</AchievedGSD>\n";
      str << ws << "   <CameraWavelength>" << afrl::cmasi::WavelengthBand::get_string(__CameraWavelength) << "</CameraWavelength>\n";
      str << ws << "   <HorizontalToLeadingEdge>" << __HorizontalToLeadingEdge << "</HorizontalToLeadingEdge>\n";
      str << ws << "   <HorizontalToTrailingEdge>" << __HorizontalToTrailingEdge << "</HorizontalToTrailingEdge>\n";
      str << ws << "   <HorizontalToCenter>" << __HorizontalToCenter << "</HorizontalToCenter>\n";
      str << ws << "   <WidthCenter>" << __WidthCenter << "</WidthCenter>\n";
      str << ws << "   <SlantRangeToCenter>" << __SlantRangeToCenter << "</SlantRangeToCenter>\n";
      str << ws << "</SensorFootprint>\n";

      return str.str();
   }

   bool SensorFootprint::operator==(const SensorFootprint & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__FootprintResponseID != that.__FootprintResponseID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__CameraID != that.__CameraID) return false;
      if(__GimbalID != that.__GimbalID) return false;
      if(__HorizontalFOV != that.__HorizontalFOV) return false;
      if(__AglAltitude != that.__AglAltitude) return false;
      if(__GimbalElevation != that.__GimbalElevation) return false;
      if(__AspectRatio != that.__AspectRatio) return false;
      if(__AchievedGSD != that.__AchievedGSD) return false;
      if(__CameraWavelength != that.__CameraWavelength) return false;
      if(__HorizontalToLeadingEdge != that.__HorizontalToLeadingEdge) return false;
      if(__HorizontalToTrailingEdge != that.__HorizontalToTrailingEdge) return false;
      if(__HorizontalToCenter != that.__HorizontalToCenter) return false;
      if(__WidthCenter != that.__WidthCenter) return false;
      if(__SlantRangeToCenter != that.__SlantRangeToCenter) return false;
      return true;

   }

   bool SensorFootprint::operator!=(const SensorFootprint & that)
   {
      return( !(operator==(that)) );
   }

   SensorFootprint& SensorFootprint::setFootprintResponseID(const int64_t val)
   {
      __FootprintResponseID = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setCameraID(const int64_t val)
   {
      __CameraID = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setGimbalID(const int64_t val)
   {
      __GimbalID = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setHorizontalFOV(const float val)
   {
      __HorizontalFOV = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setAglAltitude(const float val)
   {
      __AglAltitude = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setGimbalElevation(const float val)
   {
      __GimbalElevation = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setAspectRatio(const float val)
   {
      __AspectRatio = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setAchievedGSD(const float val)
   {
      __AchievedGSD = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setCameraWavelength(const afrl::cmasi::WavelengthBand::WavelengthBand val)
   {
      __CameraWavelength = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setHorizontalToLeadingEdge(const float val)
   {
      __HorizontalToLeadingEdge = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setHorizontalToTrailingEdge(const float val)
   {
      __HorizontalToTrailingEdge = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setHorizontalToCenter(const float val)
   {
      __HorizontalToCenter = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setWidthCenter(const float val)
   {
      __WidthCenter = val;
      return *this;
   }

   SensorFootprint& SensorFootprint::setSlantRangeToCenter(const float val)
   {
      __SlantRangeToCenter = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

