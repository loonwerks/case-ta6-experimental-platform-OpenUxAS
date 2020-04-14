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
#include "afrl/cmasi/GimbalState.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GimbalState::Subscription = "afrl.cmasi.GimbalState";
   const std::string GimbalState::TypeName = "GimbalState";
   const std::string GimbalState::SeriesName = "CMASI";
   const int64_t GimbalState::SeriesId = 4849604199710720000LL;
   const uint16_t GimbalState::SeriesVersion = 3;
   const uint32_t GimbalState::TypeId = 27;
   
   bool isGimbalState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   bool isGimbalState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 27) return false;
      return true;
   }
   
   std::vector< std::string > GimbalStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GimbalState::GimbalState(void) : afrl::cmasi::PayloadState()
   {
      __PointingMode = afrl::cmasi::GimbalPointingMode::Unknown;
      __Azimuth = 0.f;
      __Elevation = 0.f;
      __Rotation = 0.f;

   }
     
   GimbalState::GimbalState(const GimbalState &that) : afrl::cmasi::PayloadState(that)
   {
        __PointingMode = that.__PointingMode;
        __Azimuth = that.__Azimuth;
        __Elevation = that.__Elevation;
        __Rotation = that.__Rotation;

   }
   
   GimbalState & GimbalState::operator=(const GimbalState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadState::operator=(that);

         __PointingMode = that.__PointingMode;
         __Azimuth = that.__Azimuth;
         __Elevation = that.__Elevation;
         __Rotation = that.__Rotation;

      }
      return *this;
   }

   GimbalState* GimbalState::clone() const
   {
        return new GimbalState(*this);
   }
   
   GimbalState::~GimbalState(void)
   {

   }
  
   void GimbalState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadState::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __PointingMode);
      buf.putFloat(__Azimuth);
      buf.putFloat(__Elevation);
      buf.putFloat(__Rotation);

   }
   
   void GimbalState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadState::unpack(buf);
      // Copy the buffer into the class
      __PointingMode = (afrl::cmasi::GimbalPointingMode::GimbalPointingMode) buf.getInt();
      __Azimuth = buf.getFloat();
      __Elevation = buf.getFloat();
      __Rotation = buf.getFloat();

   }

   uint32_t GimbalState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadState::calculatePackedSize();
      size += sizeof(afrl::cmasi::GimbalPointingMode::GimbalPointingMode);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string GimbalState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GimbalState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "PointingMode (GimbalPointingMode) = " << __PointingMode << "\n";
      oss << indent << "Azimuth (float) = " << __Azimuth << "\n";
      oss << indent << "Elevation (float) = " << __Elevation << "\n";
      oss << indent << "Rotation (float) = " << __Rotation << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GimbalState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GimbalState Series=\"CMASI\">\n";
      str << ws << "   <PointingMode>" << afrl::cmasi::GimbalPointingMode::get_string(__PointingMode) << "</PointingMode>\n";
      str << ws << "   <Azimuth>" << __Azimuth << "</Azimuth>\n";
      str << ws << "   <Elevation>" << __Elevation << "</Elevation>\n";
      str << ws << "   <Rotation>" << __Rotation << "</Rotation>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</GimbalState>\n";

      return str.str();
   }

   bool GimbalState::operator==(const GimbalState & that)
   {
      if( afrl::cmasi::PayloadState::operator!=(that) )
      {
          return false;
      }
      if(__PointingMode != that.__PointingMode) return false;
      if(__Azimuth != that.__Azimuth) return false;
      if(__Elevation != that.__Elevation) return false;
      if(__Rotation != that.__Rotation) return false;
      return true;

   }

   bool GimbalState::operator!=(const GimbalState & that)
   {
      return( !(operator==(that)) );
   }

   GimbalState& GimbalState::setPointingMode(const afrl::cmasi::GimbalPointingMode::GimbalPointingMode val)
   {
      __PointingMode = val;
      return *this;
   }

   GimbalState& GimbalState::setAzimuth(const float val)
   {
      __Azimuth = val;
      return *this;
   }

   GimbalState& GimbalState::setElevation(const float val)
   {
      __Elevation = val;
      return *this;
   }

   GimbalState& GimbalState::setRotation(const float val)
   {
      __Rotation = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

