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
#include "afrl/cmasi/Task.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string Task::Subscription = "afrl.cmasi.Task";
   const std::string Task::TypeName = "Task";
   const std::string Task::SeriesName = "CMASI";
   const int64_t Task::SeriesId = 4849604199710720000LL;
   const uint16_t Task::SeriesVersion = 3;
   const uint32_t Task::TypeId = 8;
   
   bool isTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   bool isTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   std::vector< std::string > TaskDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("uxas.messages.task.AssignmentCoordinatorTask");
       descendants.push_back("uxas.messages.task.RendezvousTask");
       descendants.push_back("afrl.cmasi.perceive.TrackEntityTask");
       descendants.push_back("afrl.impact.CommRelayTask");
       descendants.push_back("afrl.impact.CordonTask");
       descendants.push_back("afrl.impact.BlockadeTask");
       descendants.push_back("afrl.impact.PayloadDropTask");
       descendants.push_back("afrl.cmasi.SearchTask");
       descendants.push_back("afrl.impact.ImpactPointSearchTask");
       descendants.push_back("afrl.impact.PatternSearchTask");
       descendants.push_back("afrl.impact.AngledAreaSearchTask");
       descendants.push_back("afrl.impact.ImpactLineSearchTask");
       descendants.push_back("afrl.impact.WatchTask");
       descendants.push_back("afrl.impact.MultiVehicleWatchTask");
       descendants.push_back("afrl.impact.EscortTask");
       descendants.push_back("afrl.cmasi.AreaSearchTask");
       descendants.push_back("afrl.cmasi.LineSearchTask");
       descendants.push_back("afrl.cmasi.PointSearchTask");
       descendants.push_back("afrl.cmasi.LoiterTask");
       descendants.push_back("afrl.cmasi.MustFlyTask");

       return descendants;
   }
   
   Task::Task(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __Label = std::string("");
      __RevisitRate = 0.f;
      __Priority = 0;
      __Required = true;

   }
     
   Task::Task(const Task &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __Label = that.__Label;
        __EligibleEntities.clear();
        for (size_t i=0; i< that.__EligibleEntities.size(); i++)
        {
           __EligibleEntities.push_back( that.__EligibleEntities[i]);
        }
        __RevisitRate = that.__RevisitRate;
        __Parameters.clear();
        for (size_t i=0; i< that.__Parameters.size(); i++)
        {
           __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
        }
        __Priority = that.__Priority;
        __Required = that.__Required;

   }
   
   Task & Task::operator=(const Task &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Parameters.size(); i++)
         {
            if (__Parameters[i] != nullptr) delete __Parameters[i];
         }

         __TaskID = that.__TaskID;
         __Label = that.__Label;
         __EligibleEntities.clear();
         for (size_t i=0; i< that.__EligibleEntities.size(); i++)
         {
            __EligibleEntities.push_back( that.__EligibleEntities[i]);
         }
         __RevisitRate = that.__RevisitRate;
         __Parameters.clear();
         for (size_t i=0; i< that.__Parameters.size(); i++)
         {
            __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
         }
         __Priority = that.__Priority;
         __Required = that.__Required;

      }
      return *this;
   }

   Task* Task::clone() const
   {
        return new Task(*this);
   }
   
   Task::~Task(void)
   {
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr) delete __Parameters[i];
      }

   }
  
   void Task::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putString(__Label);
      buf.putUShort( static_cast<uint16_t>(__EligibleEntities.size()));
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         buf.putLong(__EligibleEntities[i]);
      }
      buf.putFloat(__RevisitRate);
      buf.putUShort( static_cast<uint16_t>(__Parameters.size()));
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         assert(__Parameters[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Parameters[i], buf);
      }
      buf.putByte(__Priority);
      buf.putBool(__Required);

   }
   
   void Task::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __Label = buf.getString();
      __EligibleEntities.clear();
      uint16_t __EligibleEntities_length = buf.getUShort();
      for (uint32_t i=0; i< __EligibleEntities_length; i++)
      {
         __EligibleEntities.push_back(buf.getLong() );
      }
      __RevisitRate = buf.getFloat();
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr)
            delete __Parameters[i];
      }
      __Parameters.clear();
      uint16_t __Parameters_length = buf.getUShort();
      for (uint32_t i=0; i< __Parameters_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Parameters.push_back(e);
         }
      }
      __Priority = buf.getByte();
      __Required = buf.getBool();

   }

   uint32_t Task::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __Label.length();
      size += 2 + sizeof(int64_t) * __EligibleEntities.size();
      size += sizeof(float);
      size += 2;
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr)
         {
            size += __Parameters[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(uint8_t);
      size += sizeof(bool);

      return size;
   }

   std::string Task::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( Task ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string Task::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<Task Series=\"CMASI\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      str << ws << "   <EligibleEntities>\n";
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         str << ws << "   <int64>" << __EligibleEntities[i] << "</int64>\n";
      }
      str << ws << "   </EligibleEntities>\n";
      str << ws << "   <RevisitRate>" << __RevisitRate << "</RevisitRate>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "   <Priority>" << (int32_t) __Priority << "</Priority>\n";
      str << ws << "   <Required>" << (__Required ? "true" : "false") << "</Required>\n";
      str << ws << "</Task>\n";

      return str.str();
   }

   bool Task::operator==(const Task & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__Label != that.__Label) return false;
      if(__EligibleEntities.size() != that.__EligibleEntities.size()) return false;
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         if(__EligibleEntities[i] != that.__EligibleEntities[i]) return false;
      }
      if(__RevisitRate != that.__RevisitRate) return false;
      if(__Parameters.size() != that.__Parameters.size()) return false;
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if(__Parameters[i] && that.__Parameters[i])
         {
            if(__Parameters[i]->getSeriesNameAsLong() != that.__Parameters[i]->getSeriesNameAsLong()) return false;
            if(__Parameters[i]->getSeriesVersion() != that.__Parameters[i]->getSeriesVersion()) return false;
            if(__Parameters[i]->getLmcpType() != that.__Parameters[i]->getLmcpType()) return false;
            if( *(__Parameters[i]) != *(that.__Parameters[i]) ) return false;
         }
         else if(__Parameters[i] != that.__Parameters[i]) return false;
      }
      if(__Priority != that.__Priority) return false;
      if(__Required != that.__Required) return false;
      return true;

   }

   bool Task::operator!=(const Task & that)
   {
      return( !(operator==(that)) );
   }

   Task& Task::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   Task& Task::setLabel(const std::string val)
   {
      __Label = val;
      return *this;
   }


   Task& Task::setRevisitRate(const float val)
   {
      __RevisitRate = val;
      return *this;
   }


   Task& Task::setPriority(const uint8_t val)
   {
      __Priority = val;
      return *this;
   }

   Task& Task::setRequired(const bool val)
   {
      __Required = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

