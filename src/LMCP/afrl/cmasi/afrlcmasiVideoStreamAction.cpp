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
#include "afrl/cmasi/VideoStreamAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VideoStreamAction::Subscription = "afrl.cmasi.VideoStreamAction";
   const std::string VideoStreamAction::TypeName = "VideoStreamAction";
   const std::string VideoStreamAction::SeriesName = "CMASI";
   const int64_t VideoStreamAction::SeriesId = 4849604199710720000LL;
   const uint16_t VideoStreamAction::SeriesVersion = 3;
   const uint32_t VideoStreamAction::TypeId = 48;
   
   bool isVideoStreamAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 48) return false;
      return true;
   }
   
   bool isVideoStreamAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 48) return false;
      return true;
   }
   
   std::vector< std::string > VideoStreamActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   VideoStreamAction::VideoStreamAction(void) : afrl::cmasi::VehicleAction()
   {
      __VideoStreamID = 0;
      __ActiveSensor = 0;

   }
     
   VideoStreamAction::VideoStreamAction(const VideoStreamAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __VideoStreamID = that.__VideoStreamID;
        __ActiveSensor = that.__ActiveSensor;

   }
   
   VideoStreamAction & VideoStreamAction::operator=(const VideoStreamAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __VideoStreamID = that.__VideoStreamID;
         __ActiveSensor = that.__ActiveSensor;

      }
      return *this;
   }

   VideoStreamAction* VideoStreamAction::clone() const
   {
        return new VideoStreamAction(*this);
   }
   
   VideoStreamAction::~VideoStreamAction(void)
   {

   }
  
   void VideoStreamAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putInt(__VideoStreamID);
      buf.putInt(__ActiveSensor);

   }
   
   void VideoStreamAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __VideoStreamID = buf.getInt();
      __ActiveSensor = buf.getInt();

   }

   uint32_t VideoStreamAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(int32_t);
      size += sizeof(int32_t);

      return size;
   }

   std::string VideoStreamAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VideoStreamAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "VideoStreamID (int32_t) = " << __VideoStreamID << "\n";
      oss << indent << "ActiveSensor (int32_t) = " << __ActiveSensor << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VideoStreamAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VideoStreamAction Series=\"CMASI\">\n";
      str << ws << "   <VideoStreamID>" << __VideoStreamID << "</VideoStreamID>\n";
      str << ws << "   <ActiveSensor>" << __ActiveSensor << "</ActiveSensor>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</VideoStreamAction>\n";

      return str.str();
   }

   bool VideoStreamAction::operator==(const VideoStreamAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__VideoStreamID != that.__VideoStreamID) return false;
      if(__ActiveSensor != that.__ActiveSensor) return false;
      return true;

   }

   bool VideoStreamAction::operator!=(const VideoStreamAction & that)
   {
      return( !(operator==(that)) );
   }

   VideoStreamAction& VideoStreamAction::setVideoStreamID(const int32_t val)
   {
      __VideoStreamID = val;
      return *this;
   }

   VideoStreamAction& VideoStreamAction::setActiveSensor(const int32_t val)
   {
      __ActiveSensor = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

