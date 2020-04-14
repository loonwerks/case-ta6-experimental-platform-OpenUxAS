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
#include "afrl/cmasi/RemoveTasks.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RemoveTasks::Subscription = "afrl.cmasi.RemoveTasks";
   const std::string RemoveTasks::TypeName = "RemoveTasks";
   const std::string RemoveTasks::SeriesName = "CMASI";
   const int64_t RemoveTasks::SeriesId = 4849604199710720000LL;
   const uint16_t RemoveTasks::SeriesVersion = 3;
   const uint32_t RemoveTasks::TypeId = 44;
   
   bool isRemoveTasks(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 44) return false;
      return true;
   }
   
   bool isRemoveTasks(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 44) return false;
      return true;
   }
   
   std::vector< std::string > RemoveTasksDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RemoveTasks::RemoveTasks(void) : avtas::lmcp::Object()
   {

   }
     
   RemoveTasks::RemoveTasks(const RemoveTasks &that) : avtas::lmcp::Object(that)
   {
        __TaskList.clear();
        for (size_t i=0; i< that.__TaskList.size(); i++)
        {
           __TaskList.push_back( that.__TaskList[i]);
        }

   }
   
   RemoveTasks & RemoveTasks::operator=(const RemoveTasks &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __TaskList.clear();
         for (size_t i=0; i< that.__TaskList.size(); i++)
         {
            __TaskList.push_back( that.__TaskList[i]);
         }

      }
      return *this;
   }

   RemoveTasks* RemoveTasks::clone() const
   {
        return new RemoveTasks(*this);
   }
   
   RemoveTasks::~RemoveTasks(void)
   {

   }
  
   void RemoveTasks::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__TaskList.size()));
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         buf.putLong(__TaskList[i]);
      }

   }
   
   void RemoveTasks::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskList.clear();
      uint16_t __TaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskList_length; i++)
      {
         __TaskList.push_back(buf.getLong() );
      }

   }

   uint32_t RemoveTasks::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __TaskList.size();

      return size;
   }

   std::string RemoveTasks::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RemoveTasks ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskList (int64 [ " << __TaskList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RemoveTasks::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RemoveTasks Series=\"CMASI\">\n";
      str << ws << "   <TaskList>\n";
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         str << ws << "   <int64>" << __TaskList[i] << "</int64>\n";
      }
      str << ws << "   </TaskList>\n";
      str << ws << "</RemoveTasks>\n";

      return str.str();
   }

   bool RemoveTasks::operator==(const RemoveTasks & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskList.size() != that.__TaskList.size()) return false;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if(__TaskList[i] != that.__TaskList[i]) return false;
      }
      return true;

   }

   bool RemoveTasks::operator!=(const RemoveTasks & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

