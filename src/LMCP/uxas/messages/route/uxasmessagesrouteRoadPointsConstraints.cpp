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
#include "uxas/messages/route/RoadPointsConstraints.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RoadPointsConstraints::Subscription = "uxas.messages.route.RoadPointsConstraints";
   const std::string RoadPointsConstraints::TypeName = "RoadPointsConstraints";
   const std::string RoadPointsConstraints::SeriesName = "ROUTE";
   const int64_t RoadPointsConstraints::SeriesId = 5931053054693474304LL;
   const uint16_t RoadPointsConstraints::SeriesVersion = 4;
   const uint32_t RoadPointsConstraints::TypeId = 12;
   
   bool isRoadPointsConstraints(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   bool isRoadPointsConstraints(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   std::vector< std::string > RoadPointsConstraintsDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RoadPointsConstraints::RoadPointsConstraints(void) : avtas::lmcp::Object()
   {
      __RoadPointsID = 0LL;
      __StartLocation = new afrl::cmasi::Location3D();
      __EndLocation = new afrl::cmasi::Location3D();

   }
     
   RoadPointsConstraints::RoadPointsConstraints(const RoadPointsConstraints &that) : avtas::lmcp::Object(that)
   {
        __RoadPointsID = that.__RoadPointsID;
        __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
        __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();

   }
   
   RoadPointsConstraints & RoadPointsConstraints::operator=(const RoadPointsConstraints &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__StartLocation != nullptr) delete __StartLocation;
         if (__EndLocation != nullptr) delete __EndLocation;

         __RoadPointsID = that.__RoadPointsID;
         __StartLocation = that.__StartLocation == nullptr ? nullptr : that.__StartLocation->clone();
         __EndLocation = that.__EndLocation == nullptr ? nullptr : that.__EndLocation->clone();

      }
      return *this;
   }

   RoadPointsConstraints* RoadPointsConstraints::clone() const
   {
        return new RoadPointsConstraints(*this);
   }
   
   RoadPointsConstraints::~RoadPointsConstraints(void)
   {
      if (__StartLocation != nullptr) delete __StartLocation;
      if (__EndLocation != nullptr) delete __EndLocation;

   }
  
   void RoadPointsConstraints::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RoadPointsID);
      assert(__StartLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __StartLocation, buf);
      assert(__EndLocation != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EndLocation, buf);

   }
   
   void RoadPointsConstraints::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RoadPointsID = buf.getLong();
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

   }

   uint32_t RoadPointsConstraints::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__StartLocation != nullptr ? __StartLocation->calculatePackedSize() + 15 : 1);
      size += (__EndLocation != nullptr ? __EndLocation->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string RoadPointsConstraints::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RoadPointsConstraints ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RoadPointsID (int64_t) = " << __RoadPointsID << "\n";
      oss << indent << "StartLocation (Location3D)";
      if (__StartLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EndLocation (Location3D)";
      if (__EndLocation == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RoadPointsConstraints::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RoadPointsConstraints Series=\"ROUTE\">\n";
      str << ws << "   <RoadPointsID>" << __RoadPointsID << "</RoadPointsID>\n";
      if (__StartLocation != nullptr)
      {
         str << ws << "   <StartLocation>";
         str << "\n" + __StartLocation->toXML(depth + 1) + ws + "   ";
         str << "</StartLocation>\n";
      }
      if (__EndLocation != nullptr)
      {
         str << ws << "   <EndLocation>";
         str << "\n" + __EndLocation->toXML(depth + 1) + ws + "   ";
         str << "</EndLocation>\n";
      }
      str << ws << "</RoadPointsConstraints>\n";

      return str.str();
   }

   bool RoadPointsConstraints::operator==(const RoadPointsConstraints & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RoadPointsID != that.__RoadPointsID) return false;
      if(__StartLocation && that.__StartLocation)
      {
         if(__StartLocation->getSeriesNameAsLong() != that.__StartLocation->getSeriesNameAsLong()) return false;
         if(__StartLocation->getSeriesVersion() != that.__StartLocation->getSeriesVersion()) return false;
         if(__StartLocation->getLmcpType() != that.__StartLocation->getLmcpType()) return false;
         if( *(__StartLocation) != *(that.__StartLocation) ) return false;
      }
      else if(__StartLocation != that.__StartLocation) return false;
      if(__EndLocation && that.__EndLocation)
      {
         if(__EndLocation->getSeriesNameAsLong() != that.__EndLocation->getSeriesNameAsLong()) return false;
         if(__EndLocation->getSeriesVersion() != that.__EndLocation->getSeriesVersion()) return false;
         if(__EndLocation->getLmcpType() != that.__EndLocation->getLmcpType()) return false;
         if( *(__EndLocation) != *(that.__EndLocation) ) return false;
      }
      else if(__EndLocation != that.__EndLocation) return false;
      return true;

   }

   bool RoadPointsConstraints::operator!=(const RoadPointsConstraints & that)
   {
      return( !(operator==(that)) );
   }

   RoadPointsConstraints& RoadPointsConstraints::setRoadPointsID(const int64_t val)
   {
      __RoadPointsID = val;
      return *this;
   }

   RoadPointsConstraints& RoadPointsConstraints::setStartLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__StartLocation != nullptr) { delete __StartLocation; __StartLocation = nullptr; }
      if (val != nullptr) { __StartLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   RoadPointsConstraints& RoadPointsConstraints::setEndLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__EndLocation != nullptr) { delete __EndLocation; __EndLocation = nullptr; }
      if (val != nullptr) { __EndLocation = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace route
} // end namespace messages
} // end namespace uxas

