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
#include "uxas/messages/uxnative/FileTransfer.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FileTransfer::Subscription = "uxas.messages.uxnative.FileTransfer";
   const std::string FileTransfer::TypeName = "FileTransfer";
   const std::string FileTransfer::SeriesName = "UXNATIVE";
   const int64_t FileTransfer::SeriesId = 6149751333668345413LL;
   const uint16_t FileTransfer::SeriesVersion = 9;
   const uint32_t FileTransfer::TypeId = 24;
   
   bool isFileTransfer(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   bool isFileTransfer(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   std::vector< std::string > FileTransferDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FileTransfer::FileTransfer(void) : avtas::lmcp::Object()
   {
      __Nonce = 0LL;
      __DestinationEntityID = 0LL;

   }
     
   FileTransfer::FileTransfer(const FileTransfer &that) : avtas::lmcp::Object(that)
   {
        __Nonce = that.__Nonce;
        __DestinationEntityID = that.__DestinationEntityID;
        __Files.clear();
        for (size_t i=0; i< that.__Files.size(); i++)
        {
           __Files.push_back( that.__Files[i] == nullptr ? nullptr : that.__Files[i]->clone());
        }

   }
   
   FileTransfer & FileTransfer::operator=(const FileTransfer &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Files.size(); i++)
         {
            if (__Files[i] != nullptr) delete __Files[i];
         }

         __Nonce = that.__Nonce;
         __DestinationEntityID = that.__DestinationEntityID;
         __Files.clear();
         for (size_t i=0; i< that.__Files.size(); i++)
         {
            __Files.push_back( that.__Files[i] == nullptr ? nullptr : that.__Files[i]->clone());
         }

      }
      return *this;
   }

   FileTransfer* FileTransfer::clone() const
   {
        return new FileTransfer(*this);
   }
   
   FileTransfer::~FileTransfer(void)
   {
      for (size_t i=0; i<__Files.size(); i++)
      {
         if (__Files[i] != nullptr) delete __Files[i];
      }

   }
  
   void FileTransfer::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__Nonce);
      buf.putLong(__DestinationEntityID);
      buf.putUShort( static_cast<uint16_t>(__Files.size()));
      for (size_t i=0; i<__Files.size(); i++)
      {
         assert(__Files[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Files[i], buf);
      }

   }
   
   void FileTransfer::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Nonce = buf.getLong();
      __DestinationEntityID = buf.getLong();
      for (size_t i=0; i<__Files.size(); i++)
      {
         if (__Files[i] != nullptr)
            delete __Files[i];
      }
      __Files.clear();
      uint16_t __Files_length = buf.getUShort();
      for (uint32_t i=0; i< __Files_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::uxnative::File* e = (uxas::messages::uxnative::File*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Files.push_back(e);
         }
      }

   }

   uint32_t FileTransfer::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Files.size(); i++)
      {
         if (__Files[i] != nullptr)
         {
            size += __Files[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string FileTransfer::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FileTransfer ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Nonce (int64_t) = " << __Nonce << "\n";
      oss << indent << "DestinationEntityID (int64_t) = " << __DestinationEntityID << "\n";
      oss << indent << "Files (File [ " << __Files.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FileTransfer::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FileTransfer Series=\"UXNATIVE\">\n";
      str << ws << "   <Nonce>" << __Nonce << "</Nonce>\n";
      str << ws << "   <DestinationEntityID>" << __DestinationEntityID << "</DestinationEntityID>\n";
      str << ws << "   <Files>\n";
      for (size_t i=0; i<__Files.size(); i++)
      {
         str << (__Files[i] == nullptr ? ( ws + "   <null/>\n") : (__Files[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Files>\n";
      str << ws << "</FileTransfer>\n";

      return str.str();
   }

   bool FileTransfer::operator==(const FileTransfer & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Nonce != that.__Nonce) return false;
      if(__DestinationEntityID != that.__DestinationEntityID) return false;
      if(__Files.size() != that.__Files.size()) return false;
      for (size_t i=0; i<__Files.size(); i++)
      {
         if(__Files[i] && that.__Files[i])
         {
            if(__Files[i]->getSeriesNameAsLong() != that.__Files[i]->getSeriesNameAsLong()) return false;
            if(__Files[i]->getSeriesVersion() != that.__Files[i]->getSeriesVersion()) return false;
            if(__Files[i]->getLmcpType() != that.__Files[i]->getLmcpType()) return false;
            if( *(__Files[i]) != *(that.__Files[i]) ) return false;
         }
         else if(__Files[i] != that.__Files[i]) return false;
      }
      return true;

   }

   bool FileTransfer::operator!=(const FileTransfer & that)
   {
      return( !(operator==(that)) );
   }

   FileTransfer& FileTransfer::setNonce(const int64_t val)
   {
      __Nonce = val;
      return *this;
   }

   FileTransfer& FileTransfer::setDestinationEntityID(const int64_t val)
   {
      __DestinationEntityID = val;
      return *this;
   }



} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

