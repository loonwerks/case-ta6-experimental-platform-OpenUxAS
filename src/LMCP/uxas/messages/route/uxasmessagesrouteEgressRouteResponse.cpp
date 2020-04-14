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
#include "uxas/messages/route/EgressRouteResponse.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EgressRouteResponse::Subscription = "uxas.messages.route.EgressRouteResponse";
   const std::string EgressRouteResponse::TypeName = "EgressRouteResponse";
   const std::string EgressRouteResponse::SeriesName = "ROUTE";
   const int64_t EgressRouteResponse::SeriesId = 5931053054693474304LL;
   const uint16_t EgressRouteResponse::SeriesVersion = 4;
   const uint32_t EgressRouteResponse::TypeId = 11;
   
   bool isEgressRouteResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   bool isEgressRouteResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   std::vector< std::string > EgressRouteResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   EgressRouteResponse::EgressRouteResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   EgressRouteResponse::EgressRouteResponse(const EgressRouteResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __NodeLocations.clear();
        for (size_t i=0; i< that.__NodeLocations.size(); i++)
        {
           __NodeLocations.push_back( that.__NodeLocations[i] == nullptr ? nullptr : that.__NodeLocations[i]->clone());
        }
        __Headings.clear();
        for (size_t i=0; i< that.__Headings.size(); i++)
        {
           __Headings.push_back( that.__Headings[i]);
        }

   }
   
   EgressRouteResponse & EgressRouteResponse::operator=(const EgressRouteResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__NodeLocations.size(); i++)
         {
            if (__NodeLocations[i] != nullptr) delete __NodeLocations[i];
         }

         __ResponseID = that.__ResponseID;
         __NodeLocations.clear();
         for (size_t i=0; i< that.__NodeLocations.size(); i++)
         {
            __NodeLocations.push_back( that.__NodeLocations[i] == nullptr ? nullptr : that.__NodeLocations[i]->clone());
         }
         __Headings.clear();
         for (size_t i=0; i< that.__Headings.size(); i++)
         {
            __Headings.push_back( that.__Headings[i]);
         }

      }
      return *this;
   }

   EgressRouteResponse* EgressRouteResponse::clone() const
   {
        return new EgressRouteResponse(*this);
   }
   
   EgressRouteResponse::~EgressRouteResponse(void)
   {
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         if (__NodeLocations[i] != nullptr) delete __NodeLocations[i];
      }

   }
  
   void EgressRouteResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__NodeLocations.size()));
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         assert(__NodeLocations[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __NodeLocations[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Headings.size()));
      for (size_t i=0; i<__Headings.size(); i++)
      {
         buf.putFloat(__Headings[i]);
      }

   }
   
   void EgressRouteResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         if (__NodeLocations[i] != nullptr)
            delete __NodeLocations[i];
      }
      __NodeLocations.clear();
      uint16_t __NodeLocations_length = buf.getUShort();
      for (uint32_t i=0; i< __NodeLocations_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __NodeLocations.push_back(e);
         }
      }
      __Headings.clear();
      uint16_t __Headings_length = buf.getUShort();
      for (uint32_t i=0; i< __Headings_length; i++)
      {
         __Headings.push_back(buf.getFloat() );
      }

   }

   uint32_t EgressRouteResponse::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         if (__NodeLocations[i] != nullptr)
         {
            size += __NodeLocations[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2 + sizeof(float) * __Headings.size();

      return size;
   }

   std::string EgressRouteResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EgressRouteResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "NodeLocations (Location3D [ " << __NodeLocations.size() << ", var ])\n";
      oss << indent << "Headings (real32 [ " << __Headings.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EgressRouteResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EgressRouteResponse Series=\"ROUTE\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <NodeLocations>\n";
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         str << (__NodeLocations[i] == nullptr ? ( ws + "   <null/>\n") : (__NodeLocations[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </NodeLocations>\n";
      str << ws << "   <Headings>\n";
      for (size_t i=0; i<__Headings.size(); i++)
      {
         str << ws << "   <real32>" << __Headings[i] << "</real32>\n";
      }
      str << ws << "   </Headings>\n";
      str << ws << "</EgressRouteResponse>\n";

      return str.str();
   }

   bool EgressRouteResponse::operator==(const EgressRouteResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
      if(__NodeLocations.size() != that.__NodeLocations.size()) return false;
      for (size_t i=0; i<__NodeLocations.size(); i++)
      {
         if(__NodeLocations[i] && that.__NodeLocations[i])
         {
            if(__NodeLocations[i]->getSeriesNameAsLong() != that.__NodeLocations[i]->getSeriesNameAsLong()) return false;
            if(__NodeLocations[i]->getSeriesVersion() != that.__NodeLocations[i]->getSeriesVersion()) return false;
            if(__NodeLocations[i]->getLmcpType() != that.__NodeLocations[i]->getLmcpType()) return false;
            if( *(__NodeLocations[i]) != *(that.__NodeLocations[i]) ) return false;
         }
         else if(__NodeLocations[i] != that.__NodeLocations[i]) return false;
      }
      if(__Headings.size() != that.__Headings.size()) return false;
      for (size_t i=0; i<__Headings.size(); i++)
      {
         if(__Headings[i] != that.__Headings[i]) return false;
      }
      return true;

   }

   bool EgressRouteResponse::operator!=(const EgressRouteResponse & that)
   {
      return( !(operator==(that)) );
   }

   EgressRouteResponse& EgressRouteResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }




} // end namespace route
} // end namespace messages
} // end namespace uxas

