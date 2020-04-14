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
#include "uxas/messages/uxnative/File.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string File::Subscription = "uxas.messages.uxnative.File";
   const std::string File::TypeName = "File";
   const std::string File::SeriesName = "UXNATIVE";
   const int64_t File::SeriesId = 6149751333668345413LL;
   const uint16_t File::SeriesVersion = 9;
   const uint32_t File::TypeId = 23;
   
   bool isFile(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   bool isFile(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   std::vector< std::string > FileDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   File::File(void) : avtas::lmcp::Object()
   {
      __FileName = std::string("");

   }
     
   File::File(const File &that) : avtas::lmcp::Object(that)
   {
        __FileName = that.__FileName;
        __FileContents.clear();
        for (size_t i=0; i< that.__FileContents.size(); i++)
        {
           __FileContents.push_back( that.__FileContents[i]);
        }

   }
   
   File & File::operator=(const File &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __FileName = that.__FileName;
         __FileContents.clear();
         for (size_t i=0; i< that.__FileContents.size(); i++)
         {
            __FileContents.push_back( that.__FileContents[i]);
         }

      }
      return *this;
   }

   File* File::clone() const
   {
        return new File(*this);
   }
   
   File::~File(void)
   {

   }
  
   void File::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putString(__FileName);
      buf.putUShort( static_cast<uint16_t>(__FileContents.size()));
      for (size_t i=0; i<__FileContents.size(); i++)
      {
         buf.putByte(__FileContents[i]);
      }

   }
   
   void File::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __FileName = buf.getString();
      __FileContents.clear();
      uint16_t __FileContents_length = buf.getUShort();
      for (uint32_t i=0; i< __FileContents_length; i++)
      {
         __FileContents.push_back(buf.getByte() );
      }

   }

   uint32_t File::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + __FileName.length();
      size += 2 + sizeof(uint8_t) * __FileContents.size();

      return size;
   }

   std::string File::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( File ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "FileName (std::string) = " << __FileName << "\n";
      oss << indent << "FileContents (byte [ " << __FileContents.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string File::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<File Series=\"UXNATIVE\">\n";
      str << ws << "   <FileName>" << __FileName << "</FileName>\n";
      str << ws << "   <FileContents>\n";
      for (size_t i=0; i<__FileContents.size(); i++)
      {
         str << ws << "   <byte>" << (int32_t) __FileContents[i] << "</byte>\n";
      }
      str << ws << "   </FileContents>\n";
      str << ws << "</File>\n";

      return str.str();
   }

   bool File::operator==(const File & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__FileName != that.__FileName) return false;
      if(__FileContents.size() != that.__FileContents.size()) return false;
      for (size_t i=0; i<__FileContents.size(); i++)
      {
         if(__FileContents[i] != that.__FileContents[i]) return false;
      }
      return true;

   }

   bool File::operator!=(const File & that)
   {
      return( !(operator==(that)) );
   }

   File& File::setFileName(const std::string val)
   {
      __FileName = val;
      return *this;
   }



} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

