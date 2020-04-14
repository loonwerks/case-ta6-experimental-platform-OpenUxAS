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
#include "uxas/messages/task/RendezvousTask.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RendezvousTask::Subscription = "uxas.messages.task.RendezvousTask";
   const std::string RendezvousTask::TypeName = "RendezvousTask";
   const std::string RendezvousTask::SeriesName = "UXTASK";
   const int64_t RendezvousTask::SeriesId = 6149757930721443840LL;
   const uint16_t RendezvousTask::SeriesVersion = 8;
   const uint32_t RendezvousTask::TypeId = 2;
   
   bool isRendezvousTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isRendezvousTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > RendezvousTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RendezvousTask::RendezvousTask(void) : afrl::cmasi::Task()
   {
      __NumberOfParticipants = 0;

   }
     
   RendezvousTask::RendezvousTask(const RendezvousTask &that) : afrl::cmasi::Task(that)
   {
        __NumberOfParticipants = that.__NumberOfParticipants;
        __RendezvousStates.clear();
        for (size_t i=0; i< that.__RendezvousStates.size(); i++)
        {
           __RendezvousStates.push_back( that.__RendezvousStates[i] == nullptr ? nullptr : that.__RendezvousStates[i]->clone());
        }

   }
   
   RendezvousTask & RendezvousTask::operator=(const RendezvousTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         for (size_t i=0; i<__RendezvousStates.size(); i++)
         {
            if (__RendezvousStates[i] != nullptr) delete __RendezvousStates[i];
         }

         __NumberOfParticipants = that.__NumberOfParticipants;
         __RendezvousStates.clear();
         for (size_t i=0; i< that.__RendezvousStates.size(); i++)
         {
            __RendezvousStates.push_back( that.__RendezvousStates[i] == nullptr ? nullptr : that.__RendezvousStates[i]->clone());
         }

      }
      return *this;
   }

   RendezvousTask* RendezvousTask::clone() const
   {
        return new RendezvousTask(*this);
   }
   
   RendezvousTask::~RendezvousTask(void)
   {
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         if (__RendezvousStates[i] != nullptr) delete __RendezvousStates[i];
      }

   }
  
   void RendezvousTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      buf.putByte(__NumberOfParticipants);
      buf.putUShort( static_cast<uint16_t>(__RendezvousStates.size()));
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         assert(__RendezvousStates[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RendezvousStates[i], buf);
      }

   }
   
   void RendezvousTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      __NumberOfParticipants = buf.getByte();
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         if (__RendezvousStates[i] != nullptr)
            delete __RendezvousStates[i];
      }
      __RendezvousStates.clear();
      uint16_t __RendezvousStates_length = buf.getUShort();
      for (uint32_t i=0; i< __RendezvousStates_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::PlanningState* e = (uxas::messages::task::PlanningState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __RendezvousStates.push_back(e);
         }
      }

   }

   uint32_t RendezvousTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += sizeof(uint8_t);
      size += 2;
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         if (__RendezvousStates[i] != nullptr)
         {
            size += __RendezvousStates[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string RendezvousTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RendezvousTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "NumberOfParticipants (uint8_t) = " << __NumberOfParticipants << "\n";
      oss << indent << "RendezvousStates (PlanningState [ " << __RendezvousStates.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RendezvousTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RendezvousTask Series=\"UXTASK\">\n";
      str << ws << "   <NumberOfParticipants>" << (int32_t) __NumberOfParticipants << "</NumberOfParticipants>\n";
      str << ws << "   <RendezvousStates>\n";
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         str << (__RendezvousStates[i] == nullptr ? ( ws + "   <null/>\n") : (__RendezvousStates[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </RendezvousStates>\n";
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
      str << ws << "</RendezvousTask>\n";

      return str.str();
   }

   bool RendezvousTask::operator==(const RendezvousTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__NumberOfParticipants != that.__NumberOfParticipants) return false;
      if(__RendezvousStates.size() != that.__RendezvousStates.size()) return false;
      for (size_t i=0; i<__RendezvousStates.size(); i++)
      {
         if(__RendezvousStates[i] && that.__RendezvousStates[i])
         {
            if(__RendezvousStates[i]->getSeriesNameAsLong() != that.__RendezvousStates[i]->getSeriesNameAsLong()) return false;
            if(__RendezvousStates[i]->getSeriesVersion() != that.__RendezvousStates[i]->getSeriesVersion()) return false;
            if(__RendezvousStates[i]->getLmcpType() != that.__RendezvousStates[i]->getLmcpType()) return false;
            if( *(__RendezvousStates[i]) != *(that.__RendezvousStates[i]) ) return false;
         }
         else if(__RendezvousStates[i] != that.__RendezvousStates[i]) return false;
      }
      return true;

   }

   bool RendezvousTask::operator!=(const RendezvousTask & that)
   {
      return( !(operator==(that)) );
   }

   RendezvousTask& RendezvousTask::setNumberOfParticipants(const uint8_t val)
   {
      __NumberOfParticipants = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

