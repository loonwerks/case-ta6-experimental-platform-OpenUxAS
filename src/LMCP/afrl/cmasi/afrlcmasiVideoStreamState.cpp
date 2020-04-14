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
#include "afrl/cmasi/VideoStreamState.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VideoStreamState::Subscription = "afrl.cmasi.VideoStreamState";
   const std::string VideoStreamState::TypeName = "VideoStreamState";
   const std::string VideoStreamState::SeriesName = "CMASI";
   const int64_t VideoStreamState::SeriesId = 4849604199710720000LL;
   const uint16_t VideoStreamState::SeriesVersion = 3;
   const uint32_t VideoStreamState::TypeId = 50;
   
   bool isVideoStreamState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 50) return false;
      return true;
   }
   
   bool isVideoStreamState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 50) return false;
      return true;
   }
   
   std::vector< std::string > VideoStreamStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   VideoStreamState::VideoStreamState(void) : afrl::cmasi::PayloadState()
   {
      __ActiveSensor = 0LL;

   }
     
   VideoStreamState::VideoStreamState(const VideoStreamState &that) : afrl::cmasi::PayloadState(that)
   {
        __ActiveSensor = that.__ActiveSensor;

   }
   
   VideoStreamState & VideoStreamState::operator=(const VideoStreamState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadState::operator=(that);

         __ActiveSensor = that.__ActiveSensor;

      }
      return *this;
   }

   VideoStreamState* VideoStreamState::clone() const
   {
        return new VideoStreamState(*this);
   }
   
   VideoStreamState::~VideoStreamState(void)
   {

   }
  
   void VideoStreamState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadState::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ActiveSensor);

   }
   
   void VideoStreamState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadState::unpack(buf);
      // Copy the buffer into the class
      __ActiveSensor = buf.getLong();

   }

   uint32_t VideoStreamState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadState::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string VideoStreamState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VideoStreamState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "ActiveSensor (int64_t) = " << __ActiveSensor << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VideoStreamState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VideoStreamState Series=\"CMASI\">\n";
      str << ws << "   <ActiveSensor>" << __ActiveSensor << "</ActiveSensor>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</VideoStreamState>\n";

      return str.str();
   }

   bool VideoStreamState::operator==(const VideoStreamState & that)
   {
      if( afrl::cmasi::PayloadState::operator!=(that) )
      {
          return false;
      }
      if(__ActiveSensor != that.__ActiveSensor) return false;
      return true;

   }

   bool VideoStreamState::operator!=(const VideoStreamState & that)
   {
      return( !(operator==(that)) );
   }

   VideoStreamState& VideoStreamState::setActiveSensor(const int64_t val)
   {
      __ActiveSensor = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

