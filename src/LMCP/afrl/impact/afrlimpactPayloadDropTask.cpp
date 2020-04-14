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
#include "afrl/impact/PayloadDropTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PayloadDropTask::Subscription = "afrl.impact.PayloadDropTask";
   const std::string PayloadDropTask::TypeName = "PayloadDropTask";
   const std::string PayloadDropTask::SeriesName = "IMPACT";
   const int64_t PayloadDropTask::SeriesId = 5281966179208134656LL;
   const uint16_t PayloadDropTask::SeriesVersion = 14;
   const uint32_t PayloadDropTask::TypeId = 35;
   
   bool isPayloadDropTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 35) return false;
      return true;
   }
   
   bool isPayloadDropTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 35) return false;
      return true;
   }
   
   std::vector< std::string > PayloadDropTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PayloadDropTask::PayloadDropTask(void) : afrl::cmasi::Task()
   {
      __DropLocation = new afrl::cmasi::Location3D();
      __BDALocation = new afrl::cmasi::Location3D();

   }
     
   PayloadDropTask::PayloadDropTask(const PayloadDropTask &that) : afrl::cmasi::Task(that)
   {
        __DropLocation = that.__DropLocation == nullptr ? nullptr : that.__DropLocation->clone();
        __BDALocation = that.__BDALocation == nullptr ? nullptr : that.__BDALocation->clone();

   }
   
   PayloadDropTask & PayloadDropTask::operator=(const PayloadDropTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__DropLocation != nullptr) delete __DropLocation;
         if (__BDALocation != nullptr) delete __BDALocation;

         __DropLocation = that.__DropLocation == nullptr ? nullptr : that.__DropLocation->clone();
         __BDALocation = that.__BDALocation == nullptr ? nullptr : that.__BDALocation->clone();

      }
      return *this;
   }

   PayloadDropTask* PayloadDropTask::clone() const
   {
        return new PayloadDropTask(*this);
   }
   
   PayloadDropTask::~PayloadDropTask(void)
   {
      if (__DropLocation != nullptr) delete __DropLocation;
      if (__BDALocation != nullptr) delete __BDALocation;

   }
  
   void PayloadDropTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      assert(__DropLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __DropLocation, buf);
      assert(__BDALocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __BDALocation, buf);

   }
   
   void PayloadDropTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      {
         if (__DropLocation != nullptr) delete __DropLocation;
         __DropLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __DropLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__DropLocation != nullptr) __DropLocation->unpack(buf);
            else assert(__DropLocation != nullptr);
         }
      }
      {
         if (__BDALocation != nullptr) delete __BDALocation;
         __BDALocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __BDALocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__BDALocation != nullptr) __BDALocation->unpack(buf);
            else assert(__BDALocation != nullptr);
         }
      }

   }

   uint32_t PayloadDropTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += (__DropLocation != nullptr ? __DropLocation->calculatePackedSize() + 15 : 1);
      size += (__BDALocation != nullptr ? __BDALocation->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string PayloadDropTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PayloadDropTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "DropLocation (Location3D)";
      if (__DropLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "BDALocation (Location3D)";
      if (__BDALocation == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PayloadDropTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PayloadDropTask Series=\"IMPACT\">\n";
      if (__DropLocation != nullptr)
      {
         str << ws << "   <DropLocation>";
         str << "\n" + __DropLocation->toXML(depth + 1) + ws + "   ";
         str << "</DropLocation>\n";
      }
      if (__BDALocation != nullptr)
      {
         str << ws << "   <BDALocation>";
         str << "\n" + __BDALocation->toXML(depth + 1) + ws + "   ";
         str << "</BDALocation>\n";
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
      str << ws << "</PayloadDropTask>\n";

      return str.str();
   }

   bool PayloadDropTask::operator==(const PayloadDropTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__DropLocation && that.__DropLocation)
      {
         if(__DropLocation->getSeriesNameAsLong() != that.__DropLocation->getSeriesNameAsLong()) return false;
         if(__DropLocation->getSeriesVersion() != that.__DropLocation->getSeriesVersion()) return false;
         if(__DropLocation->getLmcpType() != that.__DropLocation->getLmcpType()) return false;
         if( *(__DropLocation) != *(that.__DropLocation) ) return false;
      }
      else if(__DropLocation != that.__DropLocation) return false;
      if(__BDALocation && that.__BDALocation)
      {
         if(__BDALocation->getSeriesNameAsLong() != that.__BDALocation->getSeriesNameAsLong()) return false;
         if(__BDALocation->getSeriesVersion() != that.__BDALocation->getSeriesVersion()) return false;
         if(__BDALocation->getLmcpType() != that.__BDALocation->getLmcpType()) return false;
         if( *(__BDALocation) != *(that.__BDALocation) ) return false;
      }
      else if(__BDALocation != that.__BDALocation) return false;
      return true;

   }

   bool PayloadDropTask::operator!=(const PayloadDropTask & that)
   {
      return( !(operator==(that)) );
   }

   PayloadDropTask& PayloadDropTask::setDropLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__DropLocation != nullptr) { delete __DropLocation; __DropLocation = nullptr; }
      if (val != nullptr) { __DropLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   PayloadDropTask& PayloadDropTask::setBDALocation(const afrl::cmasi::Location3D* const val)
   {
      if (__BDALocation != nullptr) { delete __BDALocation; __BDALocation = nullptr; }
      if (val != nullptr) { __BDALocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace impact
} // end namespace afrl

