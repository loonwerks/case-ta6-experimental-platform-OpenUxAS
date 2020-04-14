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
#include "uxas/messages/route/GraphEdge.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GraphEdge::Subscription = "uxas.messages.route.GraphEdge";
   const std::string GraphEdge::TypeName = "GraphEdge";
   const std::string GraphEdge::SeriesName = "ROUTE";
   const int64_t GraphEdge::SeriesId = 5931053054693474304LL;
   const uint16_t GraphEdge::SeriesVersion = 4;
   const uint32_t GraphEdge::TypeId = 2;
   
   bool isGraphEdge(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isGraphEdge(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > GraphEdgeDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GraphEdge::GraphEdge(void) : avtas::lmcp::Object()
   {
      __EdgeID = 0LL;
      __StartNode = 0LL;
      __EndNode = 0LL;

   }
     
   GraphEdge::GraphEdge(const GraphEdge &that) : avtas::lmcp::Object(that)
   {
        __EdgeID = that.__EdgeID;
        __StartNode = that.__StartNode;
        __EndNode = that.__EndNode;
        __Waypoints.clear();
        for (size_t i=0; i< that.__Waypoints.size(); i++)
        {
           __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
        }

   }
   
   GraphEdge & GraphEdge::operator=(const GraphEdge &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Waypoints.size(); i++)
         {
            if (__Waypoints[i] != nullptr) delete __Waypoints[i];
         }

         __EdgeID = that.__EdgeID;
         __StartNode = that.__StartNode;
         __EndNode = that.__EndNode;
         __Waypoints.clear();
         for (size_t i=0; i< that.__Waypoints.size(); i++)
         {
            __Waypoints.push_back( that.__Waypoints[i] == nullptr ? nullptr : that.__Waypoints[i]->clone());
         }

      }
      return *this;
   }

   GraphEdge* GraphEdge::clone() const
   {
        return new GraphEdge(*this);
   }
   
   GraphEdge::~GraphEdge(void)
   {
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         if (__Waypoints[i] != nullptr) delete __Waypoints[i];
      }

   }
  
   void GraphEdge::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__EdgeID);
      buf.putLong(__StartNode);
      buf.putLong(__EndNode);
      buf.putUShort( static_cast<uint16_t>(__Waypoints.size()));
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         assert(__Waypoints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Waypoints[i], buf);
      }

   }
   
   void GraphEdge::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EdgeID = buf.getLong();
      __StartNode = buf.getLong();
      __EndNode = buf.getLong();
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
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Waypoints.push_back(e);
         }
      }

   }

   uint32_t GraphEdge::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
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

      return size;
   }

   std::string GraphEdge::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GraphEdge ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EdgeID (int64_t) = " << __EdgeID << "\n";
      oss << indent << "StartNode (int64_t) = " << __StartNode << "\n";
      oss << indent << "EndNode (int64_t) = " << __EndNode << "\n";
      oss << indent << "Waypoints (Location3D [ " << __Waypoints.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GraphEdge::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GraphEdge Series=\"ROUTE\">\n";
      str << ws << "   <EdgeID>" << __EdgeID << "</EdgeID>\n";
      str << ws << "   <StartNode>" << __StartNode << "</StartNode>\n";
      str << ws << "   <EndNode>" << __EndNode << "</EndNode>\n";
      str << ws << "   <Waypoints>\n";
      for (size_t i=0; i<__Waypoints.size(); i++)
      {
         str << (__Waypoints[i] == nullptr ? ( ws + "   <null/>\n") : (__Waypoints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Waypoints>\n";
      str << ws << "</GraphEdge>\n";

      return str.str();
   }

   bool GraphEdge::operator==(const GraphEdge & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EdgeID != that.__EdgeID) return false;
      if(__StartNode != that.__StartNode) return false;
      if(__EndNode != that.__EndNode) return false;
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
      return true;

   }

   bool GraphEdge::operator!=(const GraphEdge & that)
   {
      return( !(operator==(that)) );
   }

   GraphEdge& GraphEdge::setEdgeID(const int64_t val)
   {
      __EdgeID = val;
      return *this;
   }

   GraphEdge& GraphEdge::setStartNode(const int64_t val)
   {
      __StartNode = val;
      return *this;
   }

   GraphEdge& GraphEdge::setEndNode(const int64_t val)
   {
      __EndNode = val;
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

