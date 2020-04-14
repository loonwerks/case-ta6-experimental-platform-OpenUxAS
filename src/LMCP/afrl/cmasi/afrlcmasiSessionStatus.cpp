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
#include "afrl/cmasi/SessionStatus.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SessionStatus::Subscription = "afrl.cmasi.SessionStatus";
   const std::string SessionStatus::TypeName = "SessionStatus";
   const std::string SessionStatus::SeriesName = "CMASI";
   const int64_t SessionStatus::SeriesId = 4849604199710720000LL;
   const uint16_t SessionStatus::SeriesVersion = 3;
   const uint32_t SessionStatus::TypeId = 46;
   
   bool isSessionStatus(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 46) return false;
      return true;
   }
   
   bool isSessionStatus(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 46) return false;
      return true;
   }
   
   std::vector< std::string > SessionStatusDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SessionStatus::SessionStatus(void) : avtas::lmcp::Object()
   {
      __State = afrl::cmasi::SimulationStatusType::Stopped;
      __StartTime = 0LL;
      __ScenarioTime = 0LL;
      __RealTimeMultiple = 0.f;

   }
     
   SessionStatus::SessionStatus(const SessionStatus &that) : avtas::lmcp::Object(that)
   {
        __State = that.__State;
        __StartTime = that.__StartTime;
        __ScenarioTime = that.__ScenarioTime;
        __RealTimeMultiple = that.__RealTimeMultiple;
        __Parameters.clear();
        for (size_t i=0; i< that.__Parameters.size(); i++)
        {
           __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
        }

   }
   
   SessionStatus & SessionStatus::operator=(const SessionStatus &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Parameters.size(); i++)
         {
            if (__Parameters[i] != nullptr) delete __Parameters[i];
         }

         __State = that.__State;
         __StartTime = that.__StartTime;
         __ScenarioTime = that.__ScenarioTime;
         __RealTimeMultiple = that.__RealTimeMultiple;
         __Parameters.clear();
         for (size_t i=0; i< that.__Parameters.size(); i++)
         {
            __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
         }

      }
      return *this;
   }

   SessionStatus* SessionStatus::clone() const
   {
        return new SessionStatus(*this);
   }
   
   SessionStatus::~SessionStatus(void)
   {
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr) delete __Parameters[i];
      }

   }
  
   void SessionStatus::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __State);
      buf.putLong(__StartTime);
      buf.putLong(__ScenarioTime);
      buf.putFloat(__RealTimeMultiple);
      buf.putUShort( static_cast<uint16_t>(__Parameters.size()));
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         assert(__Parameters[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Parameters[i], buf);
      }

   }
   
   void SessionStatus::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __State = (afrl::cmasi::SimulationStatusType::SimulationStatusType) buf.getInt();
      __StartTime = buf.getLong();
      __ScenarioTime = buf.getLong();
      __RealTimeMultiple = buf.getFloat();
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

   }

   uint32_t SessionStatus::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(afrl::cmasi::SimulationStatusType::SimulationStatusType);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
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

      return size;
   }

   std::string SessionStatus::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SessionStatus ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "State (SimulationStatusType) = " << __State << "\n";
      oss << indent << "StartTime (int64_t) = " << __StartTime << "\n";
      oss << indent << "ScenarioTime (int64_t) = " << __ScenarioTime << "\n";
      oss << indent << "RealTimeMultiple (float) = " << __RealTimeMultiple << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SessionStatus::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SessionStatus Series=\"CMASI\">\n";
      str << ws << "   <State>" << afrl::cmasi::SimulationStatusType::get_string(__State) << "</State>\n";
      str << ws << "   <StartTime>" << __StartTime << "</StartTime>\n";
      str << ws << "   <ScenarioTime>" << __ScenarioTime << "</ScenarioTime>\n";
      str << ws << "   <RealTimeMultiple>" << __RealTimeMultiple << "</RealTimeMultiple>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</SessionStatus>\n";

      return str.str();
   }

   bool SessionStatus::operator==(const SessionStatus & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__State != that.__State) return false;
      if(__StartTime != that.__StartTime) return false;
      if(__ScenarioTime != that.__ScenarioTime) return false;
      if(__RealTimeMultiple != that.__RealTimeMultiple) return false;
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
      return true;

   }

   bool SessionStatus::operator!=(const SessionStatus & that)
   {
      return( !(operator==(that)) );
   }

   SessionStatus& SessionStatus::setState(const afrl::cmasi::SimulationStatusType::SimulationStatusType val)
   {
      __State = val;
      return *this;
   }

   SessionStatus& SessionStatus::setStartTime(const int64_t val)
   {
      __StartTime = val;
      return *this;
   }

   SessionStatus& SessionStatus::setScenarioTime(const int64_t val)
   {
      __ScenarioTime = val;
      return *this;
   }

   SessionStatus& SessionStatus::setRealTimeMultiple(const float val)
   {
      __RealTimeMultiple = val;
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

