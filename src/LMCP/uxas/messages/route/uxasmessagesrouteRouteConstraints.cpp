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
#include "uxas/messages/route/RouteConstraints.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RouteConstraints::Subscription = "uxas.messages.route.RouteConstraints";
   const std::string RouteConstraints::TypeName = "RouteConstraints";
   const std::string RouteConstraints::SeriesName = "ROUTE";
   const int64_t RouteConstraints::SeriesId = 5931053054693474304LL;
   const uint16_t RouteConstraints::SeriesVersion = 4;
   const uint32_t RouteConstraints::TypeId = 4;
   
   bool isRouteConstraints(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   bool isRouteConstraints(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   std::vector< std::string > RouteConstraintsDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RouteConstraints::RouteConstraints(void) : avtas::lmcp::Object()
   {
      __RouteID = 0LL;
      __StartLocation = new afrl::cmasi::Location3D();
      __StartHeading = 0.f;
      __UseStartHeading = true;
      __EndLocation = new afrl::cmasi::Location3D();
      __EndHeading = 0.f;
      __UseEndHeading = true;

   }
     
   RouteConstraints::RouteConstraints(const RouteConstraints &that) : avtas::lmcp::Object(that)
   {
        __RouteID = that.__RouteID;
        __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
        __StartHeading = that.__StartHeading;
        __UseStartHeading = that.__UseStartHeading;
        __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();
        __EndHeading = that.__EndHeading;
        __UseEndHeading = that.__UseEndHeading;

   }
   
   RouteConstraints & RouteConstraints::operator=(const RouteConstraints &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__StartLocation != nullptr) delete __StartLocation;
         if (__EndLocation != nullptr) delete __EndLocation;

         __RouteID = that.__RouteID;
         __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
         __StartHeading = that.__StartHeading;
         __UseStartHeading = that.__UseStartHeading;
         __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();
         __EndHeading = that.__EndHeading;
         __UseEndHeading = that.__UseEndHeading;

      }
      return *this;
   }

   RouteConstraints* RouteConstraints::clone() const
   {
        return new RouteConstraints(*this);
   }
   
   RouteConstraints::~RouteConstraints(void)
   {
      if (__StartLocation != nullptr) delete __StartLocation;
      if (__EndLocation != nullptr) delete __EndLocation;

   }
  
   void RouteConstraints::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RouteID);
      assert(__StartLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartLocation, buf);
      buf.putFloat(__StartHeading);
      buf.putBool(__UseStartHeading);
      assert(__EndLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EndLocation, buf);
      buf.putFloat(__EndHeading);
      buf.putBool(__UseEndHeading);

   }
   
   void RouteConstraints::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RouteID = buf.getLong();
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
      __UseStartHeading = buf.getBool();
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
      __UseEndHeading = buf.getBool();

   }

   uint32_t RouteConstraints::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__StartLocation != nullptr ? __StartLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(bool);
      size += (__EndLocation != nullptr ? __EndLocation->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(bool);

      return size;
   }

   std::string RouteConstraints::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RouteConstraints ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RouteID (int64_t) = " << __RouteID << "\n";
      oss << indent << "StartLocation (Location3D)";
      if (__StartLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "StartHeading (float) = " << __StartHeading << "\n";
      oss << indent << "UseStartHeading (bool) = " << __UseStartHeading << "\n";
      oss << indent << "EndLocation (Location3D)";
      if (__EndLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EndHeading (float) = " << __EndHeading << "\n";
      oss << indent << "UseEndHeading (bool) = " << __UseEndHeading << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RouteConstraints::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RouteConstraints Series=\"ROUTE\">\n";
      str << ws << "   <RouteID>" << __RouteID << "</RouteID>\n";
      if (__StartLocation != nullptr)
      {
         str << ws << "   <StartLocation>";
         str << "\n" + __StartLocation->toXML(depth + 1) + ws + "   ";
         str << "</StartLocation>\n";
      }
      str << ws << "   <StartHeading>" << __StartHeading << "</StartHeading>\n";
      str << ws << "   <UseStartHeading>" << (__UseStartHeading ? "true" : "false") << "</UseStartHeading>\n";
      if (__EndLocation != nullptr)
      {
         str << ws << "   <EndLocation>";
         str << "\n" + __EndLocation->toXML(depth + 1) + ws + "   ";
         str << "</EndLocation>\n";
      }
      str << ws << "   <EndHeading>" << __EndHeading << "</EndHeading>\n";
      str << ws << "   <UseEndHeading>" << (__UseEndHeading ? "true" : "false") << "</UseEndHeading>\n";
      str << ws << "</RouteConstraints>\n";

      return str.str();
   }

   bool RouteConstraints::operator==(const RouteConstraints & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RouteID != that.__RouteID) return false;
      if(__StartLocation && that.__StartLocation)
      {
         if(__StartLocation->getSeriesNameAsLong() != that.__StartLocation->getSeriesNameAsLong()) return false;
         if(__StartLocation->getSeriesVersion() != that.__StartLocation->getSeriesVersion()) return false;
         if(__StartLocation->getLmcpType() != that.__StartLocation->getLmcpType()) return false;
         if( *(__StartLocation) != *(that.__StartLocation) ) return false;
      }
      else if(__StartLocation != that.__StartLocation) return false;
      if(__StartHeading != that.__StartHeading) return false;
      if(__UseStartHeading != that.__UseStartHeading) return false;
      if(__EndLocation && that.__EndLocation)
      {
         if(__EndLocation->getSeriesNameAsLong() != that.__EndLocation->getSeriesNameAsLong()) return false;
         if(__EndLocation->getSeriesVersion() != that.__EndLocation->getSeriesVersion()) return false;
         if(__EndLocation->getLmcpType() != that.__EndLocation->getLmcpType()) return false;
         if( *(__EndLocation) != *(that.__EndLocation) ) return false;
      }
      else if(__EndLocation != that.__EndLocation) return false;
      if(__EndHeading != that.__EndHeading) return false;
      if(__UseEndHeading != that.__UseEndHeading) return false;
      return true;

   }

   bool RouteConstraints::operator!=(const RouteConstraints & that)
   {
      return( !(operator==(that)) );
   }

   RouteConstraints& RouteConstraints::setRouteID(const int64_t val)
   {
      __RouteID = val;
      return *this;
   }

   RouteConstraints& RouteConstraints::setStartLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__StartLocation != nullptr) { delete __StartLocation; __StartLocation = nullptr; }
      if (val != nullptr) { __StartLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   RouteConstraints& RouteConstraints::setStartHeading(const float val)
   {
      __StartHeading = val;
      return *this;
   }

   RouteConstraints& RouteConstraints::setUseStartHeading(const bool val)
   {
      __UseStartHeading = val;
      return *this;
   }

   RouteConstraints& RouteConstraints::setEndLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__EndLocation != nullptr) { delete __EndLocation; __EndLocation = nullptr; }
      if (val != nullptr) { __EndLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   RouteConstraints& RouteConstraints::setEndHeading(const float val)
   {
      __EndHeading = val;
      return *this;
   }

   RouteConstraints& RouteConstraints::setUseEndHeading(const bool val)
   {
      __UseEndHeading = val;
      return *this;
   }


} // end namespace route
} // end namespace messages
} // end namespace uxas

