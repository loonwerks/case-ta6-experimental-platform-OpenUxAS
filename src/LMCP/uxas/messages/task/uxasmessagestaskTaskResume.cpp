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
#include "uxas/messages/task/TaskResume.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskResume::Subscription = "uxas.messages.task.TaskResume";
   const std::string TaskResume::TypeName = "TaskResume";
   const std::string TaskResume::SeriesName = "UXTASK";
   const int64_t TaskResume::SeriesId = 6149757930721443840LL;
   const uint16_t TaskResume::SeriesVersion = 8;
   const uint32_t TaskResume::TypeId = 23;
   
   bool isTaskResume(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   bool isTaskResume(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 23) return false;
      return true;
   }
   
   std::vector< std::string > TaskResumeDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskResume::TaskResume(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __RestartCompletely = false;
      __ReAssign = nullptr;

   }
     
   TaskResume::TaskResume(const TaskResume &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __RestartCompletely = that.__RestartCompletely;
        __ReAssign = that.__ReAssign == nullptr ? nullptr : that.__ReAssign->clone();

   }
   
   TaskResume & TaskResume::operator=(const TaskResume &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__ReAssign != nullptr) delete __ReAssign;

         __TaskID = that.__TaskID;
         __RestartCompletely = that.__RestartCompletely;
         __ReAssign = that.__ReAssign == nullptr ? nullptr : that.__ReAssign->clone();

      }
      return *this;
   }

   TaskResume* TaskResume::clone() const
   {
        return new TaskResume(*this);
   }
   
   TaskResume::~TaskResume(void)
   {
      if (__ReAssign != nullptr) delete __ReAssign;

   }
  
   void TaskResume::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putBool(__RestartCompletely);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __ReAssign, buf);

   }
   
   void TaskResume::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __RestartCompletely = buf.getBool();
      {
         if (__ReAssign != nullptr) delete __ReAssign;
         __ReAssign = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __ReAssign = (uxas::messages::task::TaskAssignment*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__ReAssign != nullptr) __ReAssign->unpack(buf);
         }
      }

   }

   uint32_t TaskResume::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(bool);
      size += (__ReAssign != nullptr ? __ReAssign->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string TaskResume::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskResume ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "RestartCompletely (bool) = " << __RestartCompletely << "\n";
      oss << indent << "ReAssign (TaskAssignment)";
      if (__ReAssign == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskResume::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskResume Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <RestartCompletely>" << (__RestartCompletely ? "true" : "false") << "</RestartCompletely>\n";
      if (__ReAssign != nullptr)
      {
         str << ws << "   <ReAssign>";
         str << "\n" + __ReAssign->toXML(depth + 1) + ws + "   ";
         str << "</ReAssign>\n";
      }
      str << ws << "</TaskResume>\n";

      return str.str();
   }

   bool TaskResume::operator==(const TaskResume & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__RestartCompletely != that.__RestartCompletely) return false;
      if(__ReAssign && that.__ReAssign)
      {
         if(__ReAssign->getSeriesNameAsLong() != that.__ReAssign->getSeriesNameAsLong()) return false;
         if(__ReAssign->getSeriesVersion() != that.__ReAssign->getSeriesVersion()) return false;
         if(__ReAssign->getLmcpType() != that.__ReAssign->getLmcpType()) return false;
         if( *(__ReAssign) != *(that.__ReAssign) ) return false;
      }
      else if(__ReAssign != that.__ReAssign) return false;
      return true;

   }

   bool TaskResume::operator!=(const TaskResume & that)
   {
      return( !(operator==(that)) );
   }

   TaskResume& TaskResume::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskResume& TaskResume::setRestartCompletely(const bool val)
   {
      __RestartCompletely = val;
      return *this;
   }

   TaskResume& TaskResume::setReAssign(const uxas::messages::task::TaskAssignment* const val)
   {
      if (__ReAssign != nullptr) { delete __ReAssign; __ReAssign = nullptr; }
      if (val != nullptr) { __ReAssign = const_cast< uxas::messages::task::TaskAssignment* > (val); }
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

