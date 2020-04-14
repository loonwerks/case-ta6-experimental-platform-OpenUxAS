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
#include "uxas/messages/task/TaskProgress.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskProgress::Subscription = "uxas.messages.task.TaskProgress";
   const std::string TaskProgress::TypeName = "TaskProgress";
   const std::string TaskProgress::SeriesName = "UXTASK";
   const int64_t TaskProgress::SeriesId = 6149757930721443840LL;
   const uint16_t TaskProgress::SeriesVersion = 8;
   const uint32_t TaskProgress::TypeId = 24;
   
   bool isTaskProgress(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   bool isTaskProgress(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   std::vector< std::string > TaskProgressDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskProgress::TaskProgress(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;
      __TaskID = 0LL;
      __PercentComplete = 0.f;

   }
     
   TaskProgress::TaskProgress(const TaskProgress &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __TaskID = that.__TaskID;
        __PercentComplete = that.__PercentComplete;
        __EntitiesEngaged.clear();
        for (size_t i=0; i< that.__EntitiesEngaged.size(); i++)
        {
           __EntitiesEngaged.push_back( that.__EntitiesEngaged[i]);
        }

   }
   
   TaskProgress & TaskProgress::operator=(const TaskProgress &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __ResponseID = that.__ResponseID;
         __TaskID = that.__TaskID;
         __PercentComplete = that.__PercentComplete;
         __EntitiesEngaged.clear();
         for (size_t i=0; i< that.__EntitiesEngaged.size(); i++)
         {
            __EntitiesEngaged.push_back( that.__EntitiesEngaged[i]);
         }

      }
      return *this;
   }

   TaskProgress* TaskProgress::clone() const
   {
        return new TaskProgress(*this);
   }
   
   TaskProgress::~TaskProgress(void)
   {

   }
  
   void TaskProgress::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putLong(__TaskID);
      buf.putFloat(__PercentComplete);
      buf.putUShort( static_cast<uint16_t>(__EntitiesEngaged.size()));
      for (size_t i=0; i<__EntitiesEngaged.size(); i++)
      {
         buf.putLong(__EntitiesEngaged[i]);
      }

   }
   
   void TaskProgress::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      __TaskID = buf.getLong();
      __PercentComplete = buf.getFloat();
      __EntitiesEngaged.clear();
      uint16_t __EntitiesEngaged_length = buf.getUShort();
      for (uint32_t i=0; i< __EntitiesEngaged_length; i++)
      {
         __EntitiesEngaged.push_back(buf.getLong() );
      }

   }

   uint32_t TaskProgress::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += 2 + sizeof(int64_t) * __EntitiesEngaged.size();

      return size;
   }

   std::string TaskProgress::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskProgress ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "PercentComplete (float) = " << __PercentComplete << "\n";
      oss << indent << "EntitiesEngaged (int64 [ " << __EntitiesEngaged.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskProgress::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskProgress Series=\"UXTASK\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <PercentComplete>" << __PercentComplete << "</PercentComplete>\n";
      str << ws << "   <EntitiesEngaged>\n";
      for (size_t i=0; i<__EntitiesEngaged.size(); i++)
      {
         str << ws << "   <int64>" << __EntitiesEngaged[i] << "</int64>\n";
      }
      str << ws << "   </EntitiesEngaged>\n";
      str << ws << "</TaskProgress>\n";

      return str.str();
   }

   bool TaskProgress::operator==(const TaskProgress & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__TaskID != that.__TaskID) return false;
      if(__PercentComplete != that.__PercentComplete) return false;
      if(__EntitiesEngaged.size() != that.__EntitiesEngaged.size()) return false;
      for (size_t i=0; i<__EntitiesEngaged.size(); i++)
      {
         if(__EntitiesEngaged[i] != that.__EntitiesEngaged[i]) return false;
      }
      return true;

   }

   bool TaskProgress::operator!=(const TaskProgress & that)
   {
      return( !(operator==(that)) );
   }

   TaskProgress& TaskProgress::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }

   TaskProgress& TaskProgress::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskProgress& TaskProgress::setPercentComplete(const float val)
   {
      __PercentComplete = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

