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
#include "uxas/messages/uxnative/IncrementWaypoint.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string IncrementWaypoint::Subscription = "uxas.messages.uxnative.IncrementWaypoint";
   const std::string IncrementWaypoint::TypeName = "IncrementWaypoint";
   const std::string IncrementWaypoint::SeriesName = "UXNATIVE";
   const int64_t IncrementWaypoint::SeriesId = 6149751333668345413LL;
   const uint16_t IncrementWaypoint::SeriesVersion = 9;
   const uint32_t IncrementWaypoint::TypeId = 5;
   
   bool isIncrementWaypoint(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   bool isIncrementWaypoint(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   std::vector< std::string > IncrementWaypointDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   IncrementWaypoint::IncrementWaypoint(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;

   }
     
   IncrementWaypoint::IncrementWaypoint(const IncrementWaypoint &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;

   }
   
   IncrementWaypoint & IncrementWaypoint::operator=(const IncrementWaypoint &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;

      }
      return *this;
   }

   IncrementWaypoint* IncrementWaypoint::clone() const
   {
        return new IncrementWaypoint(*this);
   }
   
   IncrementWaypoint::~IncrementWaypoint(void)
   {

   }
  
   void IncrementWaypoint::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);

   }
   
   void IncrementWaypoint::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();

   }

   uint32_t IncrementWaypoint::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string IncrementWaypoint::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( IncrementWaypoint ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string IncrementWaypoint::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<IncrementWaypoint Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "</IncrementWaypoint>\n";

      return str.str();
   }

   bool IncrementWaypoint::operator==(const IncrementWaypoint & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      return true;

   }

   bool IncrementWaypoint::operator!=(const IncrementWaypoint & that)
   {
      return( !(operator==(that)) );
   }

   IncrementWaypoint& IncrementWaypoint::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

