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
#include "afrl/cmasi/AutomationResponse.h"
#include "afrl/cmasi/MissionCommand.h"
#include "afrl/cmasi/FollowPathCommand.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AutomationResponse::Subscription = "afrl.cmasi.AutomationResponse";
   const std::string AutomationResponse::TypeName = "AutomationResponse";
   const std::string AutomationResponse::SeriesName = "CMASI";
   const int64_t AutomationResponse::SeriesId = 4849604199710720000LL;
   const uint16_t AutomationResponse::SeriesVersion = 3;
   const uint32_t AutomationResponse::TypeId = 51;
   
   bool isAutomationResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 51) return false;
      return true;
   }
   
   bool isAutomationResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 51) return false;
      return true;
   }
   
   std::vector< std::string > AutomationResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AutomationResponse::AutomationResponse(void) : avtas::lmcp::Object()
   {

   }
     
   AutomationResponse::AutomationResponse(const AutomationResponse &that) : avtas::lmcp::Object(that)
   {
        __MissionCommandList.clear();
        for (size_t i=0; i< that.__MissionCommandList.size(); i++)
        {
           __MissionCommandList.push_back( that.__MissionCommandList[i] == nullptr ? nullptr : that.__MissionCommandList[i]->clone());
        }
        __VehicleCommandList.clear();
        for (size_t i=0; i< that.__VehicleCommandList.size(); i++)
        {
           __VehicleCommandList.push_back( that.__VehicleCommandList[i] == nullptr ? nullptr : that.__VehicleCommandList[i]->clone());
        }
        __Info.clear();
        for (size_t i=0; i< that.__Info.size(); i++)
        {
           __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
        }

   }
   
   AutomationResponse & AutomationResponse::operator=(const AutomationResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__MissionCommandList.size(); i++)
         {
            if (__MissionCommandList[i] != nullptr) delete __MissionCommandList[i];
         }
         for (size_t i=0; i<__VehicleCommandList.size(); i++)
         {
            if (__VehicleCommandList[i] != nullptr) delete __VehicleCommandList[i];
         }
         for (size_t i=0; i<__Info.size(); i++)
         {
            if (__Info[i] != nullptr) delete __Info[i];
         }

         __MissionCommandList.clear();
         for (size_t i=0; i< that.__MissionCommandList.size(); i++)
         {
            __MissionCommandList.push_back( that.__MissionCommandList[i] == nullptr ? nullptr : that.__MissionCommandList[i]->clone());
         }
         __VehicleCommandList.clear();
         for (size_t i=0; i< that.__VehicleCommandList.size(); i++)
         {
            __VehicleCommandList.push_back( that.__VehicleCommandList[i] == nullptr ? nullptr : that.__VehicleCommandList[i]->clone());
         }
         __Info.clear();
         for (size_t i=0; i< that.__Info.size(); i++)
         {
            __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
         }

      }
      return *this;
   }

   AutomationResponse* AutomationResponse::clone() const
   {
        return new AutomationResponse(*this);
   }
   
   AutomationResponse::~AutomationResponse(void)
   {
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         if (__MissionCommandList[i] != nullptr) delete __MissionCommandList[i];
      }
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         if (__VehicleCommandList[i] != nullptr) delete __VehicleCommandList[i];
      }
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr) delete __Info[i];
      }

   }
  
   void AutomationResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__MissionCommandList.size()));
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         assert(__MissionCommandList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __MissionCommandList[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__VehicleCommandList.size()));
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         assert(__VehicleCommandList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __VehicleCommandList[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Info.size()));
      for (size_t i=0; i<__Info.size(); i++)
      {
         assert(__Info[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Info[i], buf);
      }

   }
   
   void AutomationResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         if (__MissionCommandList[i] != nullptr)
            delete __MissionCommandList[i];
      }
      __MissionCommandList.clear();
      uint16_t __MissionCommandList_length = buf.getUShort();
      for (uint32_t i=0; i< __MissionCommandList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::MissionCommand* e = (afrl::cmasi::MissionCommand*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __MissionCommandList.push_back(e);
         }
      }
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         if (__VehicleCommandList[i] != nullptr)
            delete __VehicleCommandList[i];
      }
      __VehicleCommandList.clear();
      uint16_t __VehicleCommandList_length = buf.getUShort();
      for (uint32_t i=0; i< __VehicleCommandList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::VehicleActionCommand* e = (afrl::cmasi::VehicleActionCommand*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __VehicleCommandList.push_back(e);
         }
      }
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
            delete __Info[i];
      }
      __Info.clear();
      uint16_t __Info_length = buf.getUShort();
      for (uint32_t i=0; i< __Info_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Info.push_back(e);
         }
      }

   }

   uint32_t AutomationResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         if (__MissionCommandList[i] != nullptr)
         {
            size += __MissionCommandList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         if (__VehicleCommandList[i] != nullptr)
         {
            size += __VehicleCommandList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
         {
            size += __Info[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string AutomationResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AutomationResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "MissionCommandList (MissionCommand [ " << __MissionCommandList.size() << ", var ])\n";
      oss << indent << "VehicleCommandList (VehicleActionCommand [ " << __VehicleCommandList.size() << ", var ])\n";
      oss << indent << "Info (KeyValuePair [ " << __Info.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AutomationResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AutomationResponse Series=\"CMASI\">\n";
      str << ws << "   <MissionCommandList>\n";
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         str << (__MissionCommandList[i] == nullptr ? ( ws + "   <null/>\n") : (__MissionCommandList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </MissionCommandList>\n";
      str << ws << "   <VehicleCommandList>\n";
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         str << (__VehicleCommandList[i] == nullptr ? ( ws + "   <null/>\n") : (__VehicleCommandList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </VehicleCommandList>\n";
      str << ws << "   <Info>\n";
      for (size_t i=0; i<__Info.size(); i++)
      {
         str << (__Info[i] == nullptr ? ( ws + "   <null/>\n") : (__Info[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Info>\n";
      str << ws << "</AutomationResponse>\n";

      return str.str();
   }

   bool AutomationResponse::operator==(const AutomationResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__MissionCommandList.size() != that.__MissionCommandList.size()) return false;
      for (size_t i=0; i<__MissionCommandList.size(); i++)
      {
         if(__MissionCommandList[i] && that.__MissionCommandList[i])
         {
            if(__MissionCommandList[i]->getSeriesNameAsLong() != that.__MissionCommandList[i]->getSeriesNameAsLong()) return false;
            if(__MissionCommandList[i]->getSeriesVersion() != that.__MissionCommandList[i]->getSeriesVersion()) return false;
            if(__MissionCommandList[i]->getLmcpType() != that.__MissionCommandList[i]->getLmcpType()) return false;
            if( *(__MissionCommandList[i]) != *(that.__MissionCommandList[i]) ) return false;
         }
         else if(__MissionCommandList[i] != that.__MissionCommandList[i]) return false;
      }
      if(__VehicleCommandList.size() != that.__VehicleCommandList.size()) return false;
      for (size_t i=0; i<__VehicleCommandList.size(); i++)
      {
         if(__VehicleCommandList[i] && that.__VehicleCommandList[i])
         {
            if(__VehicleCommandList[i]->getSeriesNameAsLong() != that.__VehicleCommandList[i]->getSeriesNameAsLong()) return false;
            if(__VehicleCommandList[i]->getSeriesVersion() != that.__VehicleCommandList[i]->getSeriesVersion()) return false;
            if(__VehicleCommandList[i]->getLmcpType() != that.__VehicleCommandList[i]->getLmcpType()) return false;
            if( *(__VehicleCommandList[i]) != *(that.__VehicleCommandList[i]) ) return false;
         }
         else if(__VehicleCommandList[i] != that.__VehicleCommandList[i]) return false;
      }
      if(__Info.size() != that.__Info.size()) return false;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if(__Info[i] && that.__Info[i])
         {
            if(__Info[i]->getSeriesNameAsLong() != that.__Info[i]->getSeriesNameAsLong()) return false;
            if(__Info[i]->getSeriesVersion() != that.__Info[i]->getSeriesVersion()) return false;
            if(__Info[i]->getLmcpType() != that.__Info[i]->getLmcpType()) return false;
            if( *(__Info[i]) != *(that.__Info[i]) ) return false;
         }
         else if(__Info[i] != that.__Info[i]) return false;
      }
      return true;

   }

   bool AutomationResponse::operator!=(const AutomationResponse & that)
   {
      return( !(operator==(that)) );
   }





} // end namespace cmasi
} // end namespace afrl

