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
#include "uxas/messages/task/TaskOption.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string TaskOption::Subscription = "uxas.messages.task.TaskOption";
   const std::string TaskOption::TypeName = "TaskOption";
   const std::string TaskOption::SeriesName = "UXTASK";
   const int64_t TaskOption::SeriesId = 6149757930721443840LL;
   const uint16_t TaskOption::SeriesVersion = 8;
   const uint32_t TaskOption::TypeId = 20;
   
   bool isTaskOption(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   bool isTaskOption(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   std::vector< std::string > TaskOptionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   TaskOption::TaskOption(void) : avtas::lmcp::Object()
   {
      __TaskID = 0LL;
      __OptionID = 0LL;
      __Cost = 0LL;
      __StartLocation = new afrl::cmasi::Location3D();
      __StartHeading = 0.f;
      __EndLocation = new afrl::cmasi::Location3D();
      __EndHeading = 0.f;

   }
     
   TaskOption::TaskOption(const TaskOption &that) : avtas::lmcp::Object(that)
   {
        __TaskID = that.__TaskID;
        __OptionID = that.__OptionID;
        __EligibleEntities.clear();
        for (size_t i=0; i< that.__EligibleEntities.size(); i++)
        {
           __EligibleEntities.push_back( that.__EligibleEntities[i]);
        }
        __Cost = that.__Cost;
        __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
        __StartHeading = that.__StartHeading;
        __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();
        __EndHeading = that.__EndHeading;

   }
   
   TaskOption & TaskOption::operator=(const TaskOption &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__StartLocation != nullptr) delete __StartLocation;
         if (__EndLocation != nullptr) delete __EndLocation;

         __TaskID = that.__TaskID;
         __OptionID = that.__OptionID;
         __EligibleEntities.clear();
         for (size_t i=0; i< that.__EligibleEntities.size(); i++)
         {
            __EligibleEntities.push_back( that.__EligibleEntities[i]);
         }
         __Cost = that.__Cost;
         __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
         __StartHeading = that.__StartHeading;
         __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();
         __EndHeading = that.__EndHeading;

      }
      return *this;
   }

   TaskOption* TaskOption::clone() const
   {
        return new TaskOption(*this);
   }
   
   TaskOption::~TaskOption(void)
   {
      if (__StartLocation != nullptr) delete __StartLocation;
      if (__EndLocation != nullptr) delete __EndLocation;

   }
  
   void TaskOption::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__TaskID);
      buf.putLong(__OptionID);
      buf.putUShort( static_cast<uint16_t>(__EligibleEntities.size()));
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         buf.putLong(__EligibleEntities[i]);
      }
      buf.putLong(__Cost);
      assert(__StartLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartLocation, buf);
      buf.putFloat(__StartHeading);
      assert(__EndLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EndLocation, buf);
      buf.putFloat(__EndHeading);

   }
   
   void TaskOption::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __TaskID = buf.getLong();
      __OptionID = buf.getLong();
      __EligibleEntities.clear();
      uint16_t __EligibleEntities_length = buf.getUShort();
      for (uint32_t i=0; i< __EligibleEntities_length; i++)
      {
         __EligibleEntities.push_back(buf.getLong() );
      }
      __Cost = buf.getLong();
      {
         if (__StartLocation != nullptr) delete __StartLocation;
         __StartLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __StartLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__StartLocation != nullptr) __StartLocation->unpack(buf);
            else assert(__StartLocation != nullptr);
         }
      }
      __StartHeading = buf.getFloat();
      {
         if (__EndLocation != nullptr) delete __EndLocation;
         __EndLocation = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __EndLocation = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__EndLocation != nullptr) __EndLocation->unpack(buf);
            else assert(__EndLocation != nullptr);
         }
      }
      __EndHeading = buf.getFloat();

   }

   uint32_t TaskOption::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __EligibleEntities.size();
      size += sizeof(int64_t);
      size += (__StartLocation != nullptr ? __StartLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += (__EndLocation != nullptr ? __EndLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);

      return size;
   }

   std::string TaskOption::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( TaskOption ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "OptionID (int64_t) = " << __OptionID << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "Cost (int64_t) = " << __Cost << "\n";
      oss << indent << "StartLocation (Location3D)";
      if (__StartLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "StartHeading (float) = " << __StartHeading << "\n";
      oss << indent << "EndLocation (Location3D)";
      if (__EndLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EndHeading (float) = " << __EndHeading << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string TaskOption::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<TaskOption Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <OptionID>" << __OptionID << "</OptionID>\n";
      str << ws << "   <EligibleEntities>\n";
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         str << ws << "   <int64>" << __EligibleEntities[i] << "</int64>\n";
      }
      str << ws << "   </EligibleEntities>\n";
      str << ws << "   <Cost>" << __Cost << "</Cost>\n";
      if (__StartLocation != nullptr)
      {
         str << ws << "   <StartLocation>";
         str << "\n" + __StartLocation->toXML(depth + 1) + ws + "   ";
         str << "</StartLocation>\n";
      }
      str << ws << "   <StartHeading>" << __StartHeading << "</StartHeading>\n";
      if (__EndLocation != nullptr)
      {
         str << ws << "   <EndLocation>";
         str << "\n" + __EndLocation->toXML(depth + 1) + ws + "   ";
         str << "</EndLocation>\n";
      }
      str << ws << "   <EndHeading>" << __EndHeading << "</EndHeading>\n";
      str << ws << "</TaskOption>\n";

      return str.str();
   }

   bool TaskOption::operator==(const TaskOption & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__TaskID != that.__TaskID) return false;
      if(__OptionID != that.__OptionID) return false;
      if(__EligibleEntities.size() != that.__EligibleEntities.size()) return false;
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         if(__EligibleEntities[i] != that.__EligibleEntities[i]) return false;
      }
      if(__Cost != that.__Cost) return false;
      if(__StartLocation && that.__StartLocation)
      {
         if(__StartLocation->getSeriesNameAsLong() != that.__StartLocation->getSeriesNameAsLong()) return false;
         if(__StartLocation->getSeriesVersion() != that.__StartLocation->getSeriesVersion()) return false;
         if(__StartLocation->getLmcpType() != that.__StartLocation->getLmcpType()) return false;
         if( *(__StartLocation) != *(that.__StartLocation) ) return false;
      }
      else if(__StartLocation != that.__StartLocation) return false;
      if(__StartHeading != that.__StartHeading) return false;
      if(__EndLocation && that.__EndLocation)
      {
         if(__EndLocation->getSeriesNameAsLong() != that.__EndLocation->getSeriesNameAsLong()) return false;
         if(__EndLocation->getSeriesVersion() != that.__EndLocation->getSeriesVersion()) return false;
         if(__EndLocation->getLmcpType() != that.__EndLocation->getLmcpType()) return false;
         if( *(__EndLocation) != *(that.__EndLocation) ) return false;
      }
      else if(__EndLocation != that.__EndLocation) return false;
      if(__EndHeading != that.__EndHeading) return false;
      return true;

   }

   bool TaskOption::operator!=(const TaskOption & that)
   {
      return( !(operator==(that)) );
   }

   TaskOption& TaskOption::setTaskID(const int64_t val)
   {
      __TaskID = val;
      return *this;
   }

   TaskOption& TaskOption::setOptionID(const int64_t val)
   {
      __OptionID = val;
      return *this;
   }


   TaskOption& TaskOption::setCost(const int64_t val)
   {
      __Cost = val;
      return *this;
   }

   TaskOption& TaskOption::setStartLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__StartLocation != nullptr) { delete __StartLocation; __StartLocation = nullptr; }
      if (val != nullptr) { __StartLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   TaskOption& TaskOption::setStartHeading(const float val)
   {
      __StartHeading = val;
      return *this;
   }

   TaskOption& TaskOption::setEndLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__EndLocation != nullptr) { delete __EndLocation; __EndLocation = nullptr; }
      if (val != nullptr) { __EndLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   TaskOption& TaskOption::setEndHeading(const float val)
   {
      __EndHeading = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

