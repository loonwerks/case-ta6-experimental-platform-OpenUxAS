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
#include "afrl/cmasi/VideoStreamConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VideoStreamConfiguration::Subscription = "afrl.cmasi.VideoStreamConfiguration";
   const std::string VideoStreamConfiguration::TypeName = "VideoStreamConfiguration";
   const std::string VideoStreamConfiguration::SeriesName = "CMASI";
   const int64_t VideoStreamConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t VideoStreamConfiguration::SeriesVersion = 3;
   const uint32_t VideoStreamConfiguration::TypeId = 49;
   
   bool isVideoStreamConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 49) return false;
      return true;
   }
   
   bool isVideoStreamConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 49) return false;
      return true;
   }
   
   std::vector< std::string > VideoStreamConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   VideoStreamConfiguration::VideoStreamConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {

   }
     
   VideoStreamConfiguration::VideoStreamConfiguration(const VideoStreamConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __AvailableSensorList.clear();
        for (size_t i=0; i< that.__AvailableSensorList.size(); i++)
        {
           __AvailableSensorList.push_back( that.__AvailableSensorList[i]);
        }

   }
   
   VideoStreamConfiguration & VideoStreamConfiguration::operator=(const VideoStreamConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);

         __AvailableSensorList.clear();
         for (size_t i=0; i< that.__AvailableSensorList.size(); i++)
         {
            __AvailableSensorList.push_back( that.__AvailableSensorList[i]);
         }

      }
      return *this;
   }

   VideoStreamConfiguration* VideoStreamConfiguration::clone() const
   {
        return new VideoStreamConfiguration(*this);
   }
   
   VideoStreamConfiguration::~VideoStreamConfiguration(void)
   {

   }
  
   void VideoStreamConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__AvailableSensorList.size()));
      for (size_t i=0; i<__AvailableSensorList.size(); i++)
      {
         buf.putLong(__AvailableSensorList[i]);
      }

   }
   
   void VideoStreamConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __AvailableSensorList.clear();
      uint16_t __AvailableSensorList_length = buf.getUShort();
      for (uint32_t i=0; i< __AvailableSensorList_length; i++)
      {
         __AvailableSensorList.push_back(buf.getLong() );
      }

   }

   uint32_t VideoStreamConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __AvailableSensorList.size();

      return size;
   }

   std::string VideoStreamConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VideoStreamConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "AvailableSensorList (int64 [ " << __AvailableSensorList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VideoStreamConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VideoStreamConfiguration Series=\"CMASI\">\n";
      str << ws << "   <AvailableSensorList>\n";
      for (size_t i=0; i<__AvailableSensorList.size(); i++)
      {
         str << ws << "   <int64>" << __AvailableSensorList[i] << "</int64>\n";
      }
      str << ws << "   </AvailableSensorList>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</VideoStreamConfiguration>\n";

      return str.str();
   }

   bool VideoStreamConfiguration::operator==(const VideoStreamConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__AvailableSensorList.size() != that.__AvailableSensorList.size()) return false;
      for (size_t i=0; i<__AvailableSensorList.size(); i++)
      {
         if(__AvailableSensorList[i] != that.__AvailableSensorList[i]) return false;
      }
      return true;

   }

   bool VideoStreamConfiguration::operator!=(const VideoStreamConfiguration & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

