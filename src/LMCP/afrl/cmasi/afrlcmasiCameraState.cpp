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
#include "afrl/cmasi/CameraState.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CameraState::Subscription = "afrl.cmasi.CameraState";
   const std::string CameraState::TypeName = "CameraState";
   const std::string CameraState::SeriesName = "CMASI";
   const int64_t CameraState::SeriesId = 4849604199710720000LL;
   const uint16_t CameraState::SeriesVersion = 3;
   const uint32_t CameraState::TypeId = 21;
   
   bool isCameraState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   bool isCameraState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   std::vector< std::string > CameraStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CameraState::CameraState(void) : afrl::cmasi::GimballedPayloadState()
   {
      __HorizontalFieldOfView = 0.f;
      __VerticalFieldOfView = 0.f;
      __Centerpoint = nullptr;

   }
     
   CameraState::CameraState(const CameraState &that) : afrl::cmasi::GimballedPayloadState(that)
   {
        __HorizontalFieldOfView = that.__HorizontalFieldOfView;
        __VerticalFieldOfView = that.__VerticalFieldOfView;
        __Footprint.clear();
        for (size_t i=0; i< that.__Footprint.size(); i++)
        {
           __Footprint.push_back( that.__Footprint[i] == nullptr ? nullptr : that.__Footprint[i]->clone());
        }
        __Centerpoint = that.__Centerpoint == nullptr ? nullptr : that.__Centerpoint->clone();

   }
   
   CameraState & CameraState::operator=(const CameraState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::GimballedPayloadState::operator=(that);
         for (size_t i=0; i<__Footprint.size(); i++)
         {
            if (__Footprint[i] != nullptr) delete __Footprint[i];
         }
         if (__Centerpoint != nullptr) delete __Centerpoint;

         __HorizontalFieldOfView = that.__HorizontalFieldOfView;
         __VerticalFieldOfView = that.__VerticalFieldOfView;
         __Footprint.clear();
         for (size_t i=0; i< that.__Footprint.size(); i++)
         {
            __Footprint.push_back( that.__Footprint[i] == nullptr ? nullptr : that.__Footprint[i]->clone());
         }
         __Centerpoint = that.__Centerpoint == nullptr ? nullptr : that.__Centerpoint->clone();

      }
      return *this;
   }

   CameraState* CameraState::clone() const
   {
        return new CameraState(*this);
   }
   
   CameraState::~CameraState(void)
   {
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         if (__Footprint[i] != nullptr) delete __Footprint[i];
      }
      if (__Centerpoint != nullptr) delete __Centerpoint;

   }
  
   void CameraState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::GimballedPayloadState::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__HorizontalFieldOfView);
      buf.putFloat(__VerticalFieldOfView);
      buf.putUShort( static_cast<uint16_t>(__Footprint.size()));
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         assert(__Footprint[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Footprint[i], buf);
      }
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Centerpoint, buf);

   }
   
   void CameraState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::GimballedPayloadState::unpack(buf);
      // Copy the buffer into the class
      __HorizontalFieldOfView = buf.getFloat();
      __VerticalFieldOfView = buf.getFloat();
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         if (__Footprint[i] != nullptr)
            delete __Footprint[i];
      }
      __Footprint.clear();
      uint16_t __Footprint_length = buf.getUShort();
      for (uint32_t i=0; i< __Footprint_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Footprint.push_back(e);
         }
      }
      {
         if (__Centerpoint != nullptr) delete __Centerpoint;
         __Centerpoint = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Centerpoint = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Centerpoint != nullptr) __Centerpoint->unpack(buf);
         }
      }

   }

   uint32_t CameraState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::GimballedPayloadState::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(float);
      size += 2;
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         if (__Footprint[i] != nullptr)
         {
            size += __Footprint[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += (__Centerpoint != nullptr ? __Centerpoint->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string CameraState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CameraState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "PointingMode (GimbalPointingMode) = " << __PointingMode << "\n";
      oss << indent << "Azimuth (float) = " << __Azimuth << "\n";
      oss << indent << "Elevation (float) = " << __Elevation << "\n";
      oss << indent << "Rotation (float) = " << __Rotation << "\n";

      oss << indent << "HorizontalFieldOfView (float) = " << __HorizontalFieldOfView << "\n";
      oss << indent << "VerticalFieldOfView (float) = " << __VerticalFieldOfView << "\n";
      oss << indent << "Footprint (Location3D [ " << __Footprint.size() << ", var ])\n";
      oss << indent << "Centerpoint (Location3D)";
      if (__Centerpoint == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CameraState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CameraState Series=\"CMASI\">\n";
      str << ws << "   <HorizontalFieldOfView>" << __HorizontalFieldOfView << "</HorizontalFieldOfView>\n";
      str << ws << "   <VerticalFieldOfView>" << __VerticalFieldOfView << "</VerticalFieldOfView>\n";
      str << ws << "   <Footprint>\n";
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         str << (__Footprint[i] == nullptr ? ( ws + "   <null/>\n") : (__Footprint[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Footprint>\n";
      if (__Centerpoint != nullptr)
      {
         str << ws << "   <Centerpoint>";
         str << "\n" + __Centerpoint->toXML(depth + 1) + ws + "   ";
         str << "</Centerpoint>\n";
      }
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
      str << ws << "</CameraState>\n";

      return str.str();
   }

   bool CameraState::operator==(const CameraState & that)
   {
      if( afrl::cmasi::GimballedPayloadState::operator!=(that) )
      {
          return false;
      }
      if(__HorizontalFieldOfView != that.__HorizontalFieldOfView) return false;
      if(__VerticalFieldOfView != that.__VerticalFieldOfView) return false;
      if(__Footprint.size() != that.__Footprint.size()) return false;
      for (size_t i=0; i<__Footprint.size(); i++)
      {
         if(__Footprint[i] && that.__Footprint[i])
         {
            if(__Footprint[i]->getSeriesNameAsLong() != that.__Footprint[i]->getSeriesNameAsLong()) return false;
            if(__Footprint[i]->getSeriesVersion() != that.__Footprint[i]->getSeriesVersion()) return false;
            if(__Footprint[i]->getLmcpType() != that.__Footprint[i]->getLmcpType()) return false;
            if( *(__Footprint[i]) != *(that.__Footprint[i]) ) return false;
         }
         else if(__Footprint[i] != that.__Footprint[i]) return false;
      }
      if(__Centerpoint && that.__Centerpoint)
      {
         if(__Centerpoint->getSeriesNameAsLong() != that.__Centerpoint->getSeriesNameAsLong()) return false;
         if(__Centerpoint->getSeriesVersion() != that.__Centerpoint->getSeriesVersion()) return false;
         if(__Centerpoint->getLmcpType() != that.__Centerpoint->getLmcpType()) return false;
         if( *(__Centerpoint) != *(that.__Centerpoint) ) return false;
      }
      else if(__Centerpoint != that.__Centerpoint) return false;
      return true;

   }

   bool CameraState::operator!=(const CameraState & that)
   {
      return( !(operator==(that)) );
   }

   CameraState& CameraState::setHorizontalFieldOfView(const float val)
   {
      __HorizontalFieldOfView = val;
      return *this;
   }

   CameraState& CameraState::setVerticalFieldOfView(const float val)
   {
      __VerticalFieldOfView = val;
      return *this;
   }


   CameraState& CameraState::setCenterpoint(const afrl::cmasi::Location3D* const val)
   {
      if (__Centerpoint != nullptr) { delete __Centerpoint; __Centerpoint = nullptr; }
      if (val != nullptr) { __Centerpoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

