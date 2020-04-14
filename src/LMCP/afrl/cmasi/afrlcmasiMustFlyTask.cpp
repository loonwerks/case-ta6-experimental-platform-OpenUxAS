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
#include "afrl/cmasi/MustFlyTask.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string MustFlyTask::Subscription = "afrl.cmasi.MustFlyTask";
   const std::string MustFlyTask::TypeName = "MustFlyTask";
   const std::string MustFlyTask::SeriesName = "CMASI";
   const int64_t MustFlyTask::SeriesId = 4849604199710720000LL;
   const uint16_t MustFlyTask::SeriesVersion = 3;
   const uint32_t MustFlyTask::TypeId = 37;
   
   bool isMustFlyTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 37) return false;
      return true;
   }
   
   bool isMustFlyTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 37) return false;
      return true;
   }
   
   std::vector< std::string > MustFlyTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   MustFlyTask::MustFlyTask(void) : afrl::cmasi::Task()
   {
      __Position = new afrl::cmasi::Location3D();
      __UseAltitude = true;

   }
     
   MustFlyTask::MustFlyTask(const MustFlyTask &that) : afrl::cmasi::Task(that)
   {
        __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
        __UseAltitude = that.__UseAltitude;

   }
   
   MustFlyTask & MustFlyTask::operator=(const MustFlyTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);
         if (__Position != nullptr) delete __Position;

         __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
         __UseAltitude = that.__UseAltitude;

      }
      return *this;
   }

   MustFlyTask* MustFlyTask::clone() const
   {
        return new MustFlyTask(*this);
   }
   
   MustFlyTask::~MustFlyTask(void)
   {
      if (__Position != nullptr) delete __Position;

   }
  
   void MustFlyTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer
      assert(__Position != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Position, buf);
      buf.putBool(__UseAltitude);

   }
   
   void MustFlyTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class
      {
         if (__Position != nullptr) delete __Position;
         __Position = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Position = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Position != nullptr) __Position->unpack(buf);
            else assert(__Position != nullptr);
         }
      }
      __UseAltitude = buf.getBool();

   }

   uint32_t MustFlyTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();
      size += (__Position != nullptr ? __Position->calculatePackedSize() + 15 : 1);
      size += sizeof(bool);

      return size;
   }

   std::string MustFlyTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( MustFlyTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";

      oss << indent << "Position (Location3D)";
      if (__Position == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "UseAltitude (bool) = " << __UseAltitude << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string MustFlyTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<MustFlyTask Series=\"CMASI\">\n";
      if (__Position != nullptr)
      {
         str << ws << "   <Position>";
         str << "\n" + __Position->toXML(depth + 1) + ws + "   ";
         str << "</Position>\n";
      }
      str << ws << "   <UseAltitude>" << (__UseAltitude ? "true" : "false") << "</UseAltitude>\n";
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
      str << ws << "</MustFlyTask>\n";

      return str.str();
   }

   bool MustFlyTask::operator==(const MustFlyTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      if(__Position && that.__Position)
      {
         if(__Position->getSeriesNameAsLong() != that.__Position->getSeriesNameAsLong()) return false;
         if(__Position->getSeriesVersion() != that.__Position->getSeriesVersion()) return false;
         if(__Position->getLmcpType() != that.__Position->getLmcpType()) return false;
         if( *(__Position) != *(that.__Position) ) return false;
      }
      else if(__Position != that.__Position) return false;
      if(__UseAltitude != that.__UseAltitude) return false;
      return true;

   }

   bool MustFlyTask::operator!=(const MustFlyTask & that)
   {
      return( !(operator==(that)) );
   }

   MustFlyTask& MustFlyTask::setPosition(const afrl::cmasi::Location3D* const val)
   {
      if (__Position != nullptr) { delete __Position; __Position = nullptr; }
      if (val != nullptr) { __Position = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   MustFlyTask& MustFlyTask::setUseAltitude(const bool val)
   {
      __UseAltitude = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

