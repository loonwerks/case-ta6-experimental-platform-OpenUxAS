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
#include "uxas/messages/route/EgressRouteRequest.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EgressRouteRequest::Subscription = "uxas.messages.route.EgressRouteRequest";
   const std::string EgressRouteRequest::TypeName = "EgressRouteRequest";
   const std::string EgressRouteRequest::SeriesName = "ROUTE";
   const int64_t EgressRouteRequest::SeriesId = 5931053054693474304LL;
   const uint16_t EgressRouteRequest::SeriesVersion = 4;
   const uint32_t EgressRouteRequest::TypeId = 10;
   
   bool isEgressRouteRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   bool isEgressRouteRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   std::vector< std::string > EgressRouteRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   EgressRouteRequest::EgressRouteRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __StartLocation = new afrl::cmasi::Location3D();
      __Radius = 60.f;

   }
     
   EgressRouteRequest::EgressRouteRequest(const EgressRouteRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
        __Radius = that.__Radius;

   }
   
   EgressRouteRequest & EgressRouteRequest::operator=(const EgressRouteRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__StartLocation != nullptr) delete __StartLocation;

         __RequestID = that.__RequestID;
         __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
         __Radius = that.__Radius;

      }
      return *this;
   }

   EgressRouteRequest* EgressRouteRequest::clone() const
   {
        return new EgressRouteRequest(*this);
   }
   
   EgressRouteRequest::~EgressRouteRequest(void)
   {
      if (__StartLocation != nullptr) delete __StartLocation;

   }
  
   void EgressRouteRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      assert(__StartLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartLocation, buf);
      buf.putFloat(__Radius);

   }
   
   void EgressRouteRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
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
      __Radius = buf.getFloat();

   }

   uint32_t EgressRouteRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__StartLocation != nullptr ? __StartLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);

      return size;
   }

   std::string EgressRouteRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EgressRouteRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "StartLocation (Location3D)";
      if (__StartLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Radius (float) = " << __Radius << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EgressRouteRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EgressRouteRequest Series=\"ROUTE\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      if (__StartLocation != nullptr)
      {
         str << ws << "   <StartLocation>";
         str << "\n" + __StartLocation->toXML(depth + 1) + ws + "   ";
         str << "</StartLocation>\n";
      }
      str << ws << "   <Radius>" << __Radius << "</Radius>\n";
      str << ws << "</EgressRouteRequest>\n";

      return str.str();
   }

   bool EgressRouteRequest::operator==(const EgressRouteRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__StartLocation && that.__StartLocation)
      {
         if(__StartLocation->getSeriesNameAsLong() != that.__StartLocation->getSeriesNameAsLong()) return false;
         if(__StartLocation->getSeriesVersion() != that.__StartLocation->getSeriesVersion()) return false;
         if(__StartLocation->getLmcpType() != that.__StartLocation->getLmcpType()) return false;
         if( *(__StartLocation) != *(that.__StartLocation) ) return false;
      }
      else if(__StartLocation != that.__StartLocation) return false;
      if(__Radius != that.__Radius) return false;
      return true;

   }

   bool EgressRouteRequest::operator!=(const EgressRouteRequest & that)
   {
      return( !(operator==(that)) );
   }

   EgressRouteRequest& EgressRouteRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }

   EgressRouteRequest& EgressRouteRequest::setStartLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__StartLocation != nullptr) { delete __StartLocation; __StartLocation = nullptr; }
      if (val != nullptr) { __StartLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   EgressRouteRequest& EgressRouteRequest::setRadius(const float val)
   {
      __Radius = val;
      return *this;
   }


} // end namespace route
} // end namespace messages
} // end namespace uxas

