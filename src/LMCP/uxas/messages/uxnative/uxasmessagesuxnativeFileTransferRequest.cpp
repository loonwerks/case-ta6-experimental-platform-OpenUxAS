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
#include "uxas/messages/uxnative/FileTransferRequest.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FileTransferRequest::Subscription = "uxas.messages.uxnative.FileTransferRequest";
   const std::string FileTransferRequest::TypeName = "FileTransferRequest";
   const std::string FileTransferRequest::SeriesName = "UXNATIVE";
   const int64_t FileTransferRequest::SeriesId = 6149751333668345413LL;
   const uint16_t FileTransferRequest::SeriesVersion = 9;
   const uint32_t FileTransferRequest::TypeId = 22;
   
   bool isFileTransferRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   bool isFileTransferRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 22) return false;
      return true;
   }
   
   std::vector< std::string > FileTransferRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FileTransferRequest::FileTransferRequest(void) : avtas::lmcp::Object()
   {
      __Nonce = 0LL;
      __SourceEntityID = 0LL;
      __DestinationEntityID = 0LL;

   }
     
   FileTransferRequest::FileTransferRequest(const FileTransferRequest &that) : avtas::lmcp::Object(that)
   {
        __Nonce = that.__Nonce;
        __SourceEntityID = that.__SourceEntityID;
        __DestinationEntityID = that.__DestinationEntityID;
        __FileNames.clear();
        for (size_t i=0; i< that.__FileNames.size(); i++)
        {
           __FileNames.push_back( that.__FileNames[i]);
        }

   }
   
   FileTransferRequest & FileTransferRequest::operator=(const FileTransferRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Nonce = that.__Nonce;
         __SourceEntityID = that.__SourceEntityID;
         __DestinationEntityID = that.__DestinationEntityID;
         __FileNames.clear();
         for (size_t i=0; i< that.__FileNames.size(); i++)
         {
            __FileNames.push_back( that.__FileNames[i]);
         }

      }
      return *this;
   }

   FileTransferRequest* FileTransferRequest::clone() const
   {
        return new FileTransferRequest(*this);
   }
   
   FileTransferRequest::~FileTransferRequest(void)
   {

   }
  
   void FileTransferRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__Nonce);
      buf.putLong(__SourceEntityID);
      buf.putLong(__DestinationEntityID);
      buf.putUShort( static_cast<uint16_t>(__FileNames.size()));
      for (size_t i=0; i<__FileNames.size(); i++)
      {
         buf.putString(__FileNames[i]);
      }

   }
   
   void FileTransferRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Nonce = buf.getLong();
      __SourceEntityID = buf.getLong();
      __DestinationEntityID = buf.getLong();
      __FileNames.clear();
      uint16_t __FileNames_length = buf.getUShort();
      for (uint32_t i=0; i< __FileNames_length; i++)
      {
         __FileNames.push_back(buf.getString() );
      }

   }

   uint32_t FileTransferRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__FileNames.size(); i++)
      {
         size += __FileNames[i].length() + 2;
      }

      return size;
   }

   std::string FileTransferRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FileTransferRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Nonce (int64_t) = " << __Nonce << "\n";
      oss << indent << "SourceEntityID (int64_t) = " << __SourceEntityID << "\n";
      oss << indent << "DestinationEntityID (int64_t) = " << __DestinationEntityID << "\n";
      oss << indent << "FileNames (string [ " << __FileNames.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FileTransferRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FileTransferRequest Series=\"UXNATIVE\">\n";
      str << ws << "   <Nonce>" << __Nonce << "</Nonce>\n";
      str << ws << "   <SourceEntityID>" << __SourceEntityID << "</SourceEntityID>\n";
      str << ws << "   <DestinationEntityID>" << __DestinationEntityID << "</DestinationEntityID>\n";
      str << ws << "   <FileNames>\n";
      for (size_t i=0; i<__FileNames.size(); i++)
      {
         str << ws << "   <string>" << __FileNames[i] << "</string>\n";
      }
      str << ws << "   </FileNames>\n";
      str << ws << "</FileTransferRequest>\n";

      return str.str();
   }

   bool FileTransferRequest::operator==(const FileTransferRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Nonce != that.__Nonce) return false;
      if(__SourceEntityID != that.__SourceEntityID) return false;
      if(__DestinationEntityID != that.__DestinationEntityID) return false;
      if(__FileNames.size() != that.__FileNames.size()) return false;
      for (size_t i=0; i<__FileNames.size(); i++)
      {
         if(__FileNames[i] != that.__FileNames[i]) return false;
      }
      return true;

   }

   bool FileTransferRequest::operator!=(const FileTransferRequest & that)
   {
      return( !(operator==(that)) );
   }

   FileTransferRequest& FileTransferRequest::setNonce(const int64_t val)
   {
      __Nonce = val;
      return *this;
   }

   FileTransferRequest& FileTransferRequest::setSourceEntityID(const int64_t val)
   {
      __SourceEntityID = val;
      return *this;
   }

   FileTransferRequest& FileTransferRequest::setDestinationEntityID(const int64_t val)
   {
      __DestinationEntityID = val;
      return *this;
   }



} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

