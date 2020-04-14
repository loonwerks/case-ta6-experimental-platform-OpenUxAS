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
#include "uxas/messages/uxnative/VideoRecord.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string VideoRecord::Subscription = "uxas.messages.uxnative.VideoRecord";
   const std::string VideoRecord::TypeName = "VideoRecord";
   const std::string VideoRecord::SeriesName = "UXNATIVE";
   const int64_t VideoRecord::SeriesId = 6149751333668345413LL;
   const uint16_t VideoRecord::SeriesVersion = 9;
   const uint32_t VideoRecord::TypeId = 1;
   
   bool isVideoRecord(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isVideoRecord(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > VideoRecordDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   VideoRecord::VideoRecord(void) : avtas::lmcp::Object()
   {
      __Record = false;

   }
     
   VideoRecord::VideoRecord(const VideoRecord &that) : avtas::lmcp::Object(that)
   {
        __Record = that.__Record;

   }
   
   VideoRecord & VideoRecord::operator=(const VideoRecord &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Record = that.__Record;

      }
      return *this;
   }

   VideoRecord* VideoRecord::clone() const
   {
        return new VideoRecord(*this);
   }
   
   VideoRecord::~VideoRecord(void)
   {

   }
  
   void VideoRecord::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putBool(__Record);

   }
   
   void VideoRecord::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Record = buf.getBool();

   }

   uint32_t VideoRecord::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(bool);

      return size;
   }

   std::string VideoRecord::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( VideoRecord ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Record (bool) = " << __Record << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string VideoRecord::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<VideoRecord Series=\"UXNATIVE\">\n";
      str << ws << "   <Record>" << (__Record ? "true" : "false") << "</Record>\n";
      str << ws << "</VideoRecord>\n";

      return str.str();
   }

   bool VideoRecord::operator==(const VideoRecord & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Record != that.__Record) return false;
      return true;

   }

   bool VideoRecord::operator!=(const VideoRecord & that)
   {
      return( !(operator==(that)) );
   }

   VideoRecord& VideoRecord::setRecord(const bool val)
   {
      __Record = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

