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
#include "afrl/cmasi/LoiterTask.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string LoiterTask::Subscription = "afrl.cmasi.LoiterTask";
   const std::string LoiterTask::TypeName = "LoiterTask";
   const std::string LoiterTask::SeriesName = "CMASI";
   const int64_t LoiterTask::SeriesId = 4849604199710720000LL;
   const uint16_t LoiterTask::SeriesVersion = 3;
   const uint32_t LoiterTask::TypeId = 34;
   
   bool isLoiterTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 34) return false;
      return true;
   }
   
   bool isLoiterTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 34) return false;
      return true;
   }
   
   std::vector< std::string > LoiterTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   LoiterTask::LoiterTask(void) : afrl::cmasi::Task()
   {
      __DesiredAction = new afrl::cmasi::LoiterAction();

   }
     
   LoiterTask::LoiterTask(const LoiterTask &that) : afrl::cmasi::Task(that)
   {
        __DesiredAction = that.__DesiredAction == nullptr ? nullptr : that.__DesiredAction->clone();

   }
   
   LoiterTask & LoiterTask::operator=(const LoiterTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__DesiredAction != nullptr) delete __DesiredAction;

         __DesiredAction = that.__DesiredAction == nullptr ? nullptr : that.__DesiredAction->clone();

      }
      return *this;
   }

   LoiterTask* LoiterTask::clone() const
   {
        return new LoiterTask(*this);
   }
   
   LoiterTask::~LoiterTask(void)
   {
      if (__DesiredAction != nullptr) delete __DesiredAction;

   }
  
   void LoiterTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      assert(__DesiredAction != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __DesiredAction, buf);

   }
   
   void LoiterTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      {
         if (__DesiredAction != nullptr) delete __DesiredAction;
         __DesiredAction = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __DesiredAction = (afrl::cmasi::LoiterAction*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__DesiredAction != nullptr) __DesiredAction->unpack(buf);
            else assert(__DesiredAction != nullptr);
         }
      }

   }

   uint32_t LoiterTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += (__DesiredAction != nullptr ? __DesiredAction->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string LoiterTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( LoiterTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "DesiredAction (LoiterAction)";
      if (__DesiredAction == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string LoiterTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<LoiterTask Series=\"CMASI\">\n";
      if (__DesiredAction != nullptr)
      {
         str << ws << "   <DesiredAction>";
         str << "\n" + __DesiredAction->toXML(depth + 1) + ws + "   ";
         str << "</DesiredAction>\n";
      }
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
      str << ws << "</LoiterTask>\n";

      return str.str();
   }

   bool LoiterTask::operator==(const LoiterTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__DesiredAction && that.__DesiredAction)
      {
         if(__DesiredAction->getSeriesNameAsLong() != that.__DesiredAction->getSeriesNameAsLong()) return false;
         if(__DesiredAction->getSeriesVersion() != that.__DesiredAction->getSeriesVersion()) return false;
         if(__DesiredAction->getLmcpType() != that.__DesiredAction->getLmcpType()) return false;
         if( *(__DesiredAction) != *(that.__DesiredAction) ) return false;
      }
      else if(__DesiredAction != that.__DesiredAction) return false;
      return true;

   }

   bool LoiterTask::operator!=(const LoiterTask & that)
   {
      return( !(operator==(that)) );
   }

   LoiterTask& LoiterTask::setDesiredAction(const afrl::cmasi::LoiterAction* const val)
   {
      if (__DesiredAction != nullptr) { delete __DesiredAction; __DesiredAction = nullptr; }
      if (val != nullptr) { __DesiredAction = const_cast< afrl::cmasi::LoiterAction* > (val); }
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

