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
#include "uxas/messages/task/PlanningState.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PlanningState::Subscription = "uxas.messages.task.PlanningState";
   const std::string PlanningState::TypeName = "PlanningState";
   const std::string PlanningState::SeriesName = "UXTASK";
   const int64_t PlanningState::SeriesId = 6149757930721443840LL;
   const uint16_t PlanningState::SeriesVersion = 8;
   const uint32_t PlanningState::TypeId = 3;
   
   bool isPlanningState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isPlanningState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > PlanningStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PlanningState::PlanningState(void) : avtas::lmcp::Object()
   {
      __EntityID = 0LL;
      __PlanningPosition = new afrl::cmasi::Location3D();
      __PlanningHeading = 0.f;

   }
     
   PlanningState::PlanningState(const PlanningState &that) : avtas::lmcp::Object(that)
   {
        __EntityID = that.__EntityID;
        __PlanningPosition = that.__PlanningPosition == nullptr ? nullptr : that.__PlanningPosition->clone();
        __PlanningHeading = that.__PlanningHeading;

   }
   
   PlanningState & PlanningState::operator=(const PlanningState &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__PlanningPosition != nullptr) delete __PlanningPosition;

         __EntityID = that.__EntityID;
         __PlanningPosition = that.__PlanningPosition == nullptr ? nullptr : that.__PlanningPosition->clone();
         __PlanningHeading = that.__PlanningHeading;

      }
      return *this;
   }

   PlanningState* PlanningState::clone() const
   {
        return new PlanningState(*this);
   }
   
   PlanningState::~PlanningState(void)
   {
      if (__PlanningPosition != nullptr) delete __PlanningPosition;

   }
  
   void PlanningState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EntityID);
      assert(__PlanningPosition != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PlanningPosition, buf);
      buf.putFloat(__PlanningHeading);

   }
   
   void PlanningState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getLong();
      {
         if (__PlanningPosition != nullptr) delete __PlanningPosition;
         __PlanningPosition = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __PlanningPosition = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__PlanningPosition != nullptr) __PlanningPosition->unpack(buf);
            else assert(__PlanningPosition != nullptr);
         }
      }
      __PlanningHeading = buf.getFloat();

   }

   uint32_t PlanningState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__PlanningPosition != nullptr ? __PlanningPosition->calculatePackedSize() + 15 : 1);
      size += sizeof(float);

      return size;
   }

   std::string PlanningState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PlanningState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "PlanningPosition (Location3D)";
      if (__PlanningPosition == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "PlanningHeading (float) = " << __PlanningHeading << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PlanningState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PlanningState Series=\"UXTASK\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      if (__PlanningPosition != nullptr)
      {
         str << ws << "   <PlanningPosition>";
         str << "\n" + __PlanningPosition->toXML(depth + 1) + ws + "   ";
         str << "</PlanningPosition>\n";
      }
      str << ws << "   <PlanningHeading>" << __PlanningHeading << "</PlanningHeading>\n";
      str << ws << "</PlanningState>\n";

      return str.str();
   }

   bool PlanningState::operator==(const PlanningState & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__PlanningPosition && that.__PlanningPosition)
      {
         if(__PlanningPosition->getSeriesNameAsLong() != that.__PlanningPosition->getSeriesNameAsLong()) return false;
         if(__PlanningPosition->getSeriesVersion() != that.__PlanningPosition->getSeriesVersion()) return false;
         if(__PlanningPosition->getLmcpType() != that.__PlanningPosition->getLmcpType()) return false;
         if( *(__PlanningPosition) != *(that.__PlanningPosition) ) return false;
      }
      else if(__PlanningPosition != that.__PlanningPosition) return false;
      if(__PlanningHeading != that.__PlanningHeading) return false;
      return true;

   }

   bool PlanningState::operator!=(const PlanningState & that)
   {
      return( !(operator==(that)) );
   }

   PlanningState& PlanningState::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }

   PlanningState& PlanningState::setPlanningPosition(const afrl::cmasi::Location3D* const val)
   {
      if (__PlanningPosition != nullptr) { delete __PlanningPosition; __PlanningPosition = nullptr; }
      if (val != nullptr) { __PlanningPosition = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   PlanningState& PlanningState::setPlanningHeading(const float val)
   {
      __PlanningHeading = val;
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

