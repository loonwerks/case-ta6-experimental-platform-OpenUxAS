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
#include "uxas/messages/uxnative/ZeroizeCondition.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ZeroizeCondition::Subscription = "uxas.messages.uxnative.ZeroizeCondition";
   const std::string ZeroizeCondition::TypeName = "ZeroizeCondition";
   const std::string ZeroizeCondition::SeriesName = "UXNATIVE";
   const int64_t ZeroizeCondition::SeriesId = 6149751333668345413LL;
   const uint16_t ZeroizeCondition::SeriesVersion = 9;
   const uint32_t ZeroizeCondition::TypeId = 19;
   
   bool isZeroizeCondition(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   bool isZeroizeCondition(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   std::vector< std::string > ZeroizeConditionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ZeroizeCondition::ZeroizeCondition(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __ZeroizeOnLanding = false;
      __ZeroizeOnExitingOperationalArea = false;
      __ActiveOperationalArea = 0LL;
      __ZeroizeOnTasksComplete = false;
      __ZeroizeAccumulationTime = 10000LL;
      __ZeroizeHoldoffTime = 5000LL;

   }
     
   ZeroizeCondition::ZeroizeCondition(const ZeroizeCondition &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __ZeroizeOnLanding = that.__ZeroizeOnLanding;
        __ZeroizeOnExitingOperationalArea = that.__ZeroizeOnExitingOperationalArea;
        __ActiveOperationalArea = that.__ActiveOperationalArea;
        __ZeroizeOnTasksComplete = that.__ZeroizeOnTasksComplete;
        __ZeroizeAccumulationTime = that.__ZeroizeAccumulationTime;
        __ZeroizeHoldoffTime = that.__ZeroizeHoldoffTime;
        __KeepInZones.clear();
        for (size_t i=0; i< that.__KeepInZones.size(); i++)
        {
           __KeepInZones.push_back( that.__KeepInZones[i] == nullptr ? nullptr : that.__KeepInZones[i]->clone());
        }
        __KeepOutZones.clear();
        for (size_t i=0; i< that.__KeepOutZones.size(); i++)
        {
           __KeepOutZones.push_back( that.__KeepOutZones[i] == nullptr ? nullptr : that.__KeepOutZones[i]->clone());
        }
        __OperationalAreas.clear();
        for (size_t i=0; i< that.__OperationalAreas.size(); i++)
        {
           __OperationalAreas.push_back( that.__OperationalAreas[i] == nullptr ? nullptr : that.__OperationalAreas[i]->clone());
        }

   }
   
   ZeroizeCondition & ZeroizeCondition::operator=(const ZeroizeCondition &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__KeepInZones.size(); i++)
         {
            if (__KeepInZones[i] != nullptr) delete __KeepInZones[i];
         }
         for (size_t i=0; i<__KeepOutZones.size(); i++)
         {
            if (__KeepOutZones[i] != nullptr) delete __KeepOutZones[i];
         }
         for (size_t i=0; i<__OperationalAreas.size(); i++)
         {
            if (__OperationalAreas[i] != nullptr) delete __OperationalAreas[i];
         }

         __VehicleID = that.__VehicleID;
         __ZeroizeOnLanding = that.__ZeroizeOnLanding;
         __ZeroizeOnExitingOperationalArea = that.__ZeroizeOnExitingOperationalArea;
         __ActiveOperationalArea = that.__ActiveOperationalArea;
         __ZeroizeOnTasksComplete = that.__ZeroizeOnTasksComplete;
         __ZeroizeAccumulationTime = that.__ZeroizeAccumulationTime;
         __ZeroizeHoldoffTime = that.__ZeroizeHoldoffTime;
         __KeepInZones.clear();
         for (size_t i=0; i< that.__KeepInZones.size(); i++)
         {
            __KeepInZones.push_back( that.__KeepInZones[i] == nullptr ? nullptr : that.__KeepInZones[i]->clone());
         }
         __KeepOutZones.clear();
         for (size_t i=0; i< that.__KeepOutZones.size(); i++)
         {
            __KeepOutZones.push_back( that.__KeepOutZones[i] == nullptr ? nullptr : that.__KeepOutZones[i]->clone());
         }
         __OperationalAreas.clear();
         for (size_t i=0; i< that.__OperationalAreas.size(); i++)
         {
            __OperationalAreas.push_back( that.__OperationalAreas[i] == nullptr ? nullptr : that.__OperationalAreas[i]->clone());
         }

      }
      return *this;
   }

   ZeroizeCondition* ZeroizeCondition::clone() const
   {
        return new ZeroizeCondition(*this);
   }
   
   ZeroizeCondition::~ZeroizeCondition(void)
   {
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr) delete __KeepInZones[i];
      }
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr) delete __KeepOutZones[i];
      }
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         if (__OperationalAreas[i] != nullptr) delete __OperationalAreas[i];
      }

   }
  
   void ZeroizeCondition::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putBool(__ZeroizeOnLanding);
      buf.putBool(__ZeroizeOnExitingOperationalArea);
      buf.putLong(__ActiveOperationalArea);
      buf.putBool(__ZeroizeOnTasksComplete);
      buf.putLong(__ZeroizeAccumulationTime);
      buf.putLong(__ZeroizeHoldoffTime);
      buf.putUShort( static_cast<uint16_t>(__KeepInZones.size()));
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         assert(__KeepInZones[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __KeepInZones[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__KeepOutZones.size()));
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         assert(__KeepOutZones[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __KeepOutZones[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__OperationalAreas.size()));
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         assert(__OperationalAreas[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __OperationalAreas[i], buf);
      }

   }
   
   void ZeroizeCondition::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __ZeroizeOnLanding = buf.getBool();
      __ZeroizeOnExitingOperationalArea = buf.getBool();
      __ActiveOperationalArea = buf.getLong();
      __ZeroizeOnTasksComplete = buf.getBool();
      __ZeroizeAccumulationTime = buf.getLong();
      __ZeroizeHoldoffTime = buf.getLong();
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr)
            delete __KeepInZones[i];
      }
      __KeepInZones.clear();
      uint16_t __KeepInZones_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepInZones_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeepInZone* e = (afrl::cmasi::KeepInZone*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __KeepInZones.push_back(e);
         }
      }
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr)
            delete __KeepOutZones[i];
      }
      __KeepOutZones.clear();
      uint16_t __KeepOutZones_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepOutZones_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeepOutZone* e = (afrl::cmasi::KeepOutZone*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __KeepOutZones.push_back(e);
         }
      }
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         if (__OperationalAreas[i] != nullptr)
            delete __OperationalAreas[i];
      }
      __OperationalAreas.clear();
      uint16_t __OperationalAreas_length = buf.getUShort();
      for (uint32_t i=0; i< __OperationalAreas_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::OperatingRegion* e = (afrl::cmasi::OperatingRegion*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __OperationalAreas.push_back(e);
         }
      }

   }

   uint32_t ZeroizeCondition::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(int64_t);
      size += sizeof(bool);
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr)
         {
            size += __KeepInZones[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr)
         {
            size += __KeepOutZones[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         if (__OperationalAreas[i] != nullptr)
         {
            size += __OperationalAreas[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string ZeroizeCondition::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ZeroizeCondition ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "ZeroizeOnLanding (bool) = " << __ZeroizeOnLanding << "\n";
      oss << indent << "ZeroizeOnExitingOperationalArea (bool) = " << __ZeroizeOnExitingOperationalArea << "\n";
      oss << indent << "ActiveOperationalArea (int64_t) = " << __ActiveOperationalArea << "\n";
      oss << indent << "ZeroizeOnTasksComplete (bool) = " << __ZeroizeOnTasksComplete << "\n";
      oss << indent << "ZeroizeAccumulationTime (int64_t) = " << __ZeroizeAccumulationTime << "\n";
      oss << indent << "ZeroizeHoldoffTime (int64_t) = " << __ZeroizeHoldoffTime << "\n";
      oss << indent << "KeepInZones (KeepInZone [ " << __KeepInZones.size() << ", var ])\n";
      oss << indent << "KeepOutZones (KeepOutZone [ " << __KeepOutZones.size() << ", var ])\n";
      oss << indent << "OperationalAreas (OperatingRegion [ " << __OperationalAreas.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ZeroizeCondition::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ZeroizeCondition Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <ZeroizeOnLanding>" << (__ZeroizeOnLanding ? "true" : "false") << "</ZeroizeOnLanding>\n";
      str << ws << "   <ZeroizeOnExitingOperationalArea>" << (__ZeroizeOnExitingOperationalArea ? "true" : "false") << "</ZeroizeOnExitingOperationalArea>\n";
      str << ws << "   <ActiveOperationalArea>" << __ActiveOperationalArea << "</ActiveOperationalArea>\n";
      str << ws << "   <ZeroizeOnTasksComplete>" << (__ZeroizeOnTasksComplete ? "true" : "false") << "</ZeroizeOnTasksComplete>\n";
      str << ws << "   <ZeroizeAccumulationTime>" << __ZeroizeAccumulationTime << "</ZeroizeAccumulationTime>\n";
      str << ws << "   <ZeroizeHoldoffTime>" << __ZeroizeHoldoffTime << "</ZeroizeHoldoffTime>\n";
      str << ws << "   <KeepInZones>\n";
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         str << (__KeepInZones[i] == nullptr ? ( ws + "   <null/>\n") : (__KeepInZones[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </KeepInZones>\n";
      str << ws << "   <KeepOutZones>\n";
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         str << (__KeepOutZones[i] == nullptr ? ( ws + "   <null/>\n") : (__KeepOutZones[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </KeepOutZones>\n";
      str << ws << "   <OperationalAreas>\n";
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         str << (__OperationalAreas[i] == nullptr ? ( ws + "   <null/>\n") : (__OperationalAreas[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </OperationalAreas>\n";
      str << ws << "</ZeroizeCondition>\n";

      return str.str();
   }

   bool ZeroizeCondition::operator==(const ZeroizeCondition & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__ZeroizeOnLanding != that.__ZeroizeOnLanding) return false;
      if(__ZeroizeOnExitingOperationalArea != that.__ZeroizeOnExitingOperationalArea) return false;
      if(__ActiveOperationalArea != that.__ActiveOperationalArea) return false;
      if(__ZeroizeOnTasksComplete != that.__ZeroizeOnTasksComplete) return false;
      if(__ZeroizeAccumulationTime != that.__ZeroizeAccumulationTime) return false;
      if(__ZeroizeHoldoffTime != that.__ZeroizeHoldoffTime) return false;
      if(__KeepInZones.size() != that.__KeepInZones.size()) return false;
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if(__KeepInZones[i] && that.__KeepInZones[i])
         {
            if(__KeepInZones[i]->getSeriesNameAsLong() != that.__KeepInZones[i]->getSeriesNameAsLong()) return false;
            if(__KeepInZones[i]->getSeriesVersion() != that.__KeepInZones[i]->getSeriesVersion()) return false;
            if(__KeepInZones[i]->getLmcpType() != that.__KeepInZones[i]->getLmcpType()) return false;
            if( *(__KeepInZones[i]) != *(that.__KeepInZones[i]) ) return false;
         }
         else if(__KeepInZones[i] != that.__KeepInZones[i]) return false;
      }
      if(__KeepOutZones.size() != that.__KeepOutZones.size()) return false;
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if(__KeepOutZones[i] && that.__KeepOutZones[i])
         {
            if(__KeepOutZones[i]->getSeriesNameAsLong() != that.__KeepOutZones[i]->getSeriesNameAsLong()) return false;
            if(__KeepOutZones[i]->getSeriesVersion() != that.__KeepOutZones[i]->getSeriesVersion()) return false;
            if(__KeepOutZones[i]->getLmcpType() != that.__KeepOutZones[i]->getLmcpType()) return false;
            if( *(__KeepOutZones[i]) != *(that.__KeepOutZones[i]) ) return false;
         }
         else if(__KeepOutZones[i] != that.__KeepOutZones[i]) return false;
      }
      if(__OperationalAreas.size() != that.__OperationalAreas.size()) return false;
      for (size_t i=0; i<__OperationalAreas.size(); i++)
      {
         if(__OperationalAreas[i] && that.__OperationalAreas[i])
         {
            if(__OperationalAreas[i]->getSeriesNameAsLong() != that.__OperationalAreas[i]->getSeriesNameAsLong()) return false;
            if(__OperationalAreas[i]->getSeriesVersion() != that.__OperationalAreas[i]->getSeriesVersion()) return false;
            if(__OperationalAreas[i]->getLmcpType() != that.__OperationalAreas[i]->getLmcpType()) return false;
            if( *(__OperationalAreas[i]) != *(that.__OperationalAreas[i]) ) return false;
         }
         else if(__OperationalAreas[i] != that.__OperationalAreas[i]) return false;
      }
      return true;

   }

   bool ZeroizeCondition::operator!=(const ZeroizeCondition & that)
   {
      return( !(operator==(that)) );
   }

   ZeroizeCondition& ZeroizeCondition::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setZeroizeOnLanding(const bool val)
   {
      __ZeroizeOnLanding = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setZeroizeOnExitingOperationalArea(const bool val)
   {
      __ZeroizeOnExitingOperationalArea = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setActiveOperationalArea(const int64_t val)
   {
      __ActiveOperationalArea = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setZeroizeOnTasksComplete(const bool val)
   {
      __ZeroizeOnTasksComplete = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setZeroizeAccumulationTime(const int64_t val)
   {
      __ZeroizeAccumulationTime = val;
      return *this;
   }

   ZeroizeCondition& ZeroizeCondition::setZeroizeHoldoffTime(const int64_t val)
   {
      __ZeroizeHoldoffTime = val;
      return *this;
   }





} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

