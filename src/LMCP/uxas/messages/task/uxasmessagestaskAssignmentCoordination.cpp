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
#include "uxas/messages/task/AssignmentCoordination.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AssignmentCoordination::Subscription = "uxas.messages.task.AssignmentCoordination";
   const std::string AssignmentCoordination::TypeName = "AssignmentCoordination";
   const std::string AssignmentCoordination::SeriesName = "UXTASK";
   const int64_t AssignmentCoordination::SeriesId = 6149757930721443840LL;
   const uint16_t AssignmentCoordination::SeriesVersion = 8;
   const uint32_t AssignmentCoordination::TypeId = 4;
   
   bool isAssignmentCoordination(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   bool isAssignmentCoordination(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   std::vector< std::string > AssignmentCoordinationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AssignmentCoordination::AssignmentCoordination(void) : avtas::lmcp::Object()
   {
      __CoordinatedAutomationRequestID = 0LL;
      __PlanningState = new uxas::messages::task::PlanningState();

   }
     
   AssignmentCoordination::AssignmentCoordination(const AssignmentCoordination &that) : avtas::lmcp::Object(that)
   {
        __CoordinatedAutomationRequestID = that.__CoordinatedAutomationRequestID;
        __PlanningState = that.__PlanningState == nullptr ? nullptr : that.__PlanningState->clone();

   }
   
   AssignmentCoordination & AssignmentCoordination::operator=(const AssignmentCoordination &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__PlanningState != nullptr) delete __PlanningState;

         __CoordinatedAutomationRequestID = that.__CoordinatedAutomationRequestID;
         __PlanningState = that.__PlanningState == nullptr ? nullptr : that.__PlanningState->clone();

      }
      return *this;
   }

   AssignmentCoordination* AssignmentCoordination::clone() const
   {
        return new AssignmentCoordination(*this);
   }
   
   AssignmentCoordination::~AssignmentCoordination(void)
   {
      if (__PlanningState != nullptr) delete __PlanningState;

   }
  
   void AssignmentCoordination::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__CoordinatedAutomationRequestID);
      assert(__PlanningState != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PlanningState, buf);

   }
   
   void AssignmentCoordination::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __CoordinatedAutomationRequestID = buf.getLong();
      {
         if (__PlanningState != nullptr) delete __PlanningState;
         __PlanningState = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __PlanningState = (uxas::messages::task::PlanningState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__PlanningState != nullptr) __PlanningState->unpack(buf);
            else assert(__PlanningState != nullptr);
         }
      }

   }

   uint32_t AssignmentCoordination::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__PlanningState != nullptr ? __PlanningState->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string AssignmentCoordination::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AssignmentCoordination ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CoordinatedAutomationRequestID (int64_t) = " << __CoordinatedAutomationRequestID << "\n";
      oss << indent << "PlanningState (PlanningState)";
      if (__PlanningState == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AssignmentCoordination::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AssignmentCoordination Series=\"UXTASK\">\n";
      str << ws << "   <CoordinatedAutomationRequestID>" << __CoordinatedAutomationRequestID << "</CoordinatedAutomationRequestID>\n";
      if (__PlanningState != nullptr)
      {
         str << ws << "   <PlanningState>";
         str << "\n" + __PlanningState->toXML(depth + 1) + ws + "   ";
         str << "</PlanningState>\n";
      }
      str << ws << "</AssignmentCoordination>\n";

      return str.str();
   }

   bool AssignmentCoordination::operator==(const AssignmentCoordination & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__CoordinatedAutomationRequestID != that.__CoordinatedAutomationRequestID) return false;
      if(__PlanningState && that.__PlanningState)
      {
         if(__PlanningState->getSeriesNameAsLong() != that.__PlanningState->getSeriesNameAsLong()) return false;
         if(__PlanningState->getSeriesVersion() != that.__PlanningState->getSeriesVersion()) return false;
         if(__PlanningState->getLmcpType() != that.__PlanningState->getLmcpType()) return false;
         if( *(__PlanningState) != *(that.__PlanningState) ) return false;
      }
      else if(__PlanningState != that.__PlanningState) return false;
      return true;

   }

   bool AssignmentCoordination::operator!=(const AssignmentCoordination & that)
   {
      return( !(operator==(that)) );
   }

   AssignmentCoordination& AssignmentCoordination::setCoordinatedAutomationRequestID(const int64_t val)
   {
      __CoordinatedAutomationRequestID = val;
      return *this;
   }

   AssignmentCoordination& AssignmentCoordination::setPlanningState(const uxas::messages::task::PlanningState* const val)
   {
      if (__PlanningState != nullptr) { delete __PlanningState; __PlanningState = nullptr; }
      if (val != nullptr) { __PlanningState = const_cast< uxas::messages::task::PlanningState* > (val); }
      return *this;
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

