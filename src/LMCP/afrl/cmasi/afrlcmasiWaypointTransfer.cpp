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
#include "afrl/cmasi/WaypointTransfer.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string WaypointTransfer::Subscription = "afrl.cmasi.WaypointTransfer";
   const std::string WaypointTransfer::TypeName = "WaypointTransfer";
   const std::string WaypointTransfer::SeriesName = "CMASI";
   const int64_t WaypointTransfer::SeriesId = 4849604199710720000LL;
   const uint16_t WaypointTransfer::SeriesVersion = 3;
   const uint32_t WaypointTransfer::TypeId = 59;
   
   bool isWaypointTransfer(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 59) return false;
      return true;
   }
   
   bool isWaypointTransfer(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 59) return false;
      return true;
   }
   
   std::vector< std::string > WaypointTransferDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   WaypointTransfer::WaypointTransfer(void) : avtas::lmcp::Object()
   {
      __EntityID = 0LL;
      __TransferMode = afrl::cmasi::WaypointTransferMode::AddWaypoints;

   }
     
   WaypointTransfer::WaypointTransfer(const WaypointTransfer &that) : avtas::lmcp::Object(that)
   {
        __EntityID = that.__EntityID;
        __Waypoints.clear();
        for (size_t i=0; i< that.__Waypoints.size(); i++)
        {
           __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
        }
        __TransferMode = that.__TransferMode;

   }
   
   WaypointTransfer & WaypointTransfer::operator=(const WaypointTransfer &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Waypoints.size(); i++)
         {
            if (__Waypoints[i] != nullptr) delete __Waypoints[i];
         }

         __EntityID = that.__EntityID;
         __Waypoints.clear();
         for (size_t i=0; i< that.__Waypoints.size(); i++)
         {
            __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
         }
         __TransferMode = that.__TransferMode;

      }
      return *this;
   }

   WaypointTransfer* WaypointTransfer::clone() const
   {
        return new WaypointTransfer(*this);
   }
   
   WaypointTransfer::~WaypointTransfer(void)
   {
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr) delete __Waypoints[i];
      }

   }
  
   void WaypointTransfer::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EntityID);
      buf.putUShort( static_cast<uint16_t>(__Waypoints.size()));
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         assert(__Waypoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Waypoints[i], buf);
      }
      buf.putInt( (int32_t) __TransferMode);

   }
   
   void WaypointTransfer::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityID = buf.getLong();
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr)
            delete __Waypoints[i];
      }
      __Waypoints.clear();
      uint16_t __Waypoints_length = buf.getUShort();
      for (uint32_t i=0; i< __Waypoints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Waypoint* e = (afrl::cmasi::Waypoint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Waypoints.push_back(e);
         }
      }
      __TransferMode = (afrl::cmasi::WaypointTransferMode::WaypointTransferMode) buf.getInt();

   }

   uint32_t WaypointTransfer::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr)
         {
            size += __Waypoints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(afrl::cmasi::WaypointTransferMode::WaypointTransferMode);

      return size;
   }

   std::string WaypointTransfer::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( WaypointTransfer ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "Waypoints (Waypoint [ " << __Waypoints.size() << ", var ])\n";
      oss << indent << "TransferMode (WaypointTransferMode) = " << __TransferMode << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string WaypointTransfer::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<WaypointTransfer Series=\"CMASI\">\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      str << ws << "   <Waypoints>\n";
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         str << (__Waypoints[i] == nullptr ? ( ws + "   <null/>\n") : (__Waypoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Waypoints>\n";
      str << ws << "   <TransferMode>" << afrl::cmasi::WaypointTransferMode::get_string(__TransferMode) << "</TransferMode>\n";
      str << ws << "</WaypointTransfer>\n";

      return str.str();
   }

   bool WaypointTransfer::operator==(const WaypointTransfer & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityID != that.__EntityID) return false;
      if(__Waypoints.size() != that.__Waypoints.size()) return false;
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if(__Waypoints[i] && that.__Waypoints[i])
         {
            if(__Waypoints[i]->getSeriesNameAsLong() != that.__Waypoints[i]->getSeriesNameAsLong()) return false;
            if(__Waypoints[i]->getSeriesVersion() != that.__Waypoints[i]->getSeriesVersion()) return false;
            if(__Waypoints[i]->getLmcpType() != that.__Waypoints[i]->getLmcpType()) return false;
            if( *(__Waypoints[i]) != *(that.__Waypoints[i]) ) return false;
         }
         else if(__Waypoints[i] != that.__Waypoints[i]) return false;
      }
      if(__TransferMode != that.__TransferMode) return false;
      return true;

   }

   bool WaypointTransfer::operator!=(const WaypointTransfer & that)
   {
      return( !(operator==(that)) );
   }

   WaypointTransfer& WaypointTransfer::setEntityID(const int64_t val)
   {
      __EntityID = val;
      return *this;
   }


   WaypointTransfer& WaypointTransfer::setTransferMode(const afrl::cmasi::WaypointTransferMode::WaypointTransferMode val)
   {
      __TransferMode = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

