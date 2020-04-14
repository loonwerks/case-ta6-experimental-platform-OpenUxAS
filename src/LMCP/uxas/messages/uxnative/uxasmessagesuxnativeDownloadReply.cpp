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
#include "uxas/messages/uxnative/DownloadReply.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string DownloadReply::Subscription = "uxas.messages.uxnative.DownloadReply";
   const std::string DownloadReply::TypeName = "DownloadReply";
   const std::string DownloadReply::SeriesName = "UXNATIVE";
   const int64_t DownloadReply::SeriesId = 6149751333668345413LL;
   const uint16_t DownloadReply::SeriesVersion = 9;
   const uint32_t DownloadReply::TypeId = 21;
   
   bool isDownloadReply(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   bool isDownloadReply(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   std::vector< std::string > DownloadReplyDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   DownloadReply::DownloadReply(void) : avtas::lmcp::Object()
   {

   }
     
   DownloadReply::DownloadReply(const DownloadReply &that) : avtas::lmcp::Object(that)
   {
        __Contents.clear();
        for (size_t i=0; i< that.__Contents.size(); i++)
        {
           __Contents.push_back( that.__Contents[i] == nullptr ? nullptr : that.__Contents[i]->clone());
        }

   }
   
   DownloadReply & DownloadReply::operator=(const DownloadReply &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Contents.size(); i++)
         {
            if (__Contents[i] != nullptr) delete __Contents[i];
         }

         __Contents.clear();
         for (size_t i=0; i< that.__Contents.size(); i++)
         {
            __Contents.push_back( that.__Contents[i] == nullptr ? nullptr : that.__Contents[i]->clone());
         }

      }
      return *this;
   }

   DownloadReply* DownloadReply::clone() const
   {
        return new DownloadReply(*this);
   }
   
   DownloadReply::~DownloadReply(void)
   {
      for (size_t i=0; i<__Contents.size(); i++)
      {
         if (__Contents[i] != nullptr) delete __Contents[i];
      }

   }
  
   void DownloadReply::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__Contents.size()));
      for (size_t i=0; i<__Contents.size(); i++)
      {
         assert(__Contents[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Contents[i], buf);
      }

   }
   
   void DownloadReply::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__Contents.size(); i++)
      {
         if (__Contents[i] != nullptr)
            delete __Contents[i];
      }
      __Contents.clear();
      uint16_t __Contents_length = buf.getUShort();
      for (uint32_t i=0; i< __Contents_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            avtas::lmcp::Object* e = (avtas::lmcp::Object*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Contents.push_back(e);
         }
      }

   }

   uint32_t DownloadReply::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__Contents.size(); i++)
      {
         if (__Contents[i] != nullptr)
         {
            size += __Contents[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string DownloadReply::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( DownloadReply ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Contents (LmcpObject [ " << __Contents.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string DownloadReply::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<DownloadReply Series=\"UXNATIVE\">\n";
      str << ws << "   <Contents>\n";
      for (size_t i=0; i<__Contents.size(); i++)
      {
         str << (__Contents[i] == nullptr ? ( ws + "   <null/>\n") : (__Contents[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Contents>\n";
      str << ws << "</DownloadReply>\n";

      return str.str();
   }

   bool DownloadReply::operator==(const DownloadReply & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Contents.size() != that.__Contents.size()) return false;
      for (size_t i=0; i<__Contents.size(); i++)
      {
         if(__Contents[i] && that.__Contents[i])
         {
            if(__Contents[i]->getSeriesNameAsLong() != that.__Contents[i]->getSeriesNameAsLong()) return false;
            if(__Contents[i]->getSeriesVersion() != that.__Contents[i]->getSeriesVersion()) return false;
            if(__Contents[i]->getLmcpType() != that.__Contents[i]->getLmcpType()) return false;
            if( *(__Contents[i]) != *(that.__Contents[i]) ) return false;
         }
         else if(__Contents[i] != that.__Contents[i]) return false;
      }
      return true;

   }

   bool DownloadReply::operator!=(const DownloadReply & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

