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
#include "afrl/cmasi/GimbalAngleAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GimbalAngleAction::Subscription = "afrl.cmasi.GimbalAngleAction";
   const std::string GimbalAngleAction::TypeName = "GimbalAngleAction";
   const std::string GimbalAngleAction::SeriesName = "CMASI";
   const int64_t GimbalAngleAction::SeriesId = 4849604199710720000LL;
   const uint16_t GimbalAngleAction::SeriesVersion = 3;
   const uint32_t GimbalAngleAction::TypeId = 23;
   
   bool isGimbalAngleAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   bool isGimbalAngleAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   std::vector< std::string > GimbalAngleActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GimbalAngleAction::GimbalAngleAction(void) : afrl::cmasi::PayloadAction()
   {
      __Azimuth = 0.f;
      __Elevation = 0.f;
      __Rotation = 0.f;

   }
     
   GimbalAngleAction::GimbalAngleAction(const GimbalAngleAction &that) : afrl::cmasi::PayloadAction(that)
   {
        __Azimuth = that.__Azimuth;
        __Elevation = that.__Elevation;
        __Rotation = that.__Rotation;

   }
   
   GimbalAngleAction & GimbalAngleAction::operator=(const GimbalAngleAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadAction::operator=(that);

         __Azimuth = that.__Azimuth;
         __Elevation = that.__Elevation;
         __Rotation = that.__Rotation;

      }
      return *this;
   }

   GimbalAngleAction* GimbalAngleAction::clone() const
   {
        return new GimbalAngleAction(*this);
   }
   
   GimbalAngleAction::~GimbalAngleAction(void)
   {

   }
  
   void GimbalAngleAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadAction::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__Azimuth);
      buf.putFloat(__Elevation);
      buf.putFloat(__Rotation);

   }
   
   void GimbalAngleAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadAction::unpack(buf);
      // Copy the buffer into the class
      __Azimuth = buf.getFloat();
      __Elevation = buf.getFloat();
      __Rotation = buf.getFloat();

   }

   uint32_t GimbalAngleAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadAction::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string GimbalAngleAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GimbalAngleAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      oss << indent << "Azimuth (float) = " << __Azimuth << "\n";
      oss << indent << "Elevation (float) = " << __Elevation << "\n";
      oss << indent << "Rotation (float) = " << __Rotation << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GimbalAngleAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GimbalAngleAction Series=\"CMASI\">\n";
      str << ws << "   <Azimuth>" << __Azimuth << "</Azimuth>\n";
      str << ws << "   <Elevation>" << __Elevation << "</Elevation>\n";
      str << ws << "   <Rotation>" << __Rotation << "</Rotation>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</GimbalAngleAction>\n";

      return str.str();
   }

   bool GimbalAngleAction::operator==(const GimbalAngleAction & that)
   {
      if( afrl::cmasi::PayloadAction::operator!=(that) )
      {
          return false;
      }
      if(__Azimuth != that.__Azimuth) return false;
      if(__Elevation != that.__Elevation) return false;
      if(__Rotation != that.__Rotation) return false;
      return true;

   }

   bool GimbalAngleAction::operator!=(const GimbalAngleAction & that)
   {
      return( !(operator==(that)) );
   }

   GimbalAngleAction& GimbalAngleAction::setAzimuth(const float val)
   {
      __Azimuth = val;
      return *this;
   }

   GimbalAngleAction& GimbalAngleAction::setElevation(const float val)
   {
      __Elevation = val;
      return *this;
   }

   GimbalAngleAction& GimbalAngleAction::setRotation(const float val)
   {
      __Rotation = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

