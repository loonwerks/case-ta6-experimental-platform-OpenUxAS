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
#include "uxas/messages/uxnative/DownloadRequest.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string DownloadRequest::Subscription = "uxas.messages.uxnative.DownloadRequest";
   const std::string DownloadRequest::TypeName = "DownloadRequest";
   const std::string DownloadRequest::SeriesName = "UXNATIVE";
   const int64_t DownloadRequest::SeriesId = 6149751333668345413LL;
   const uint16_t DownloadRequest::SeriesVersion = 9;
   const uint32_t DownloadRequest::TypeId = 20;
   
   bool isDownloadRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   bool isDownloadRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   std::vector< std::string > DownloadRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   DownloadRequest::DownloadRequest(void) : avtas::lmcp::Object()
   {
      __RequestedLmcpTypeName = std::string("");

   }
     
   DownloadRequest::DownloadRequest(const DownloadRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestedLmcpTypeName = that.__RequestedLmcpTypeName;

   }
   
   DownloadRequest & DownloadRequest::operator=(const DownloadRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __RequestedLmcpTypeName = that.__RequestedLmcpTypeName;

      }
      return *this;
   }

   DownloadRequest* DownloadRequest::clone() const
   {
        return new DownloadRequest(*this);
   }
   
   DownloadRequest::~DownloadRequest(void)
   {

   }
  
   void DownloadRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putString(__RequestedLmcpTypeName);

   }
   
   void DownloadRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestedLmcpTypeName = buf.getString();

   }

   uint32_t DownloadRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + __RequestedLmcpTypeName.length();

      return size;
   }

   std::string DownloadRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( DownloadRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestedLmcpTypeName (std::string) = " << __RequestedLmcpTypeName << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string DownloadRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<DownloadRequest Series=\"UXNATIVE\">\n";
      str << ws << "   <RequestedLmcpTypeName>" << __RequestedLmcpTypeName << "</RequestedLmcpTypeName>\n";
      str << ws << "</DownloadRequest>\n";

      return str.str();
   }

   bool DownloadRequest::operator==(const DownloadRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestedLmcpTypeName != that.__RequestedLmcpTypeName) return false;
      return true;

   }

   bool DownloadRequest::operator!=(const DownloadRequest & that)
   {
      return( !(operator==(that)) );
   }

   DownloadRequest& DownloadRequest::setRequestedLmcpTypeName(const std::string val)
   {
      __RequestedLmcpTypeName = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

