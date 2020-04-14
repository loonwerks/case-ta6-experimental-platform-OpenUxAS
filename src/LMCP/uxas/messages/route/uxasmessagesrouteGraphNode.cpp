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
#include "uxas/messages/route/GraphNode.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GraphNode::Subscription = "uxas.messages.route.GraphNode";
   const std::string GraphNode::TypeName = "GraphNode";
   const std::string GraphNode::SeriesName = "ROUTE";
   const int64_t GraphNode::SeriesId = 5931053054693474304LL;
   const uint16_t GraphNode::SeriesVersion = 4;
   const uint32_t GraphNode::TypeId = 1;
   
   bool isGraphNode(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isGraphNode(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > GraphNodeDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GraphNode::GraphNode(void) : avtas::lmcp::Object()
   {
      __NodeID = 0LL;
      __Coordinates = new afrl::cmasi::Location3D();

   }
     
   GraphNode::GraphNode(const GraphNode &that) : avtas::lmcp::Object(that)
   {
        __NodeID = that.__NodeID;
        __Coordinates = that.__Coordinates == nullptr ? nullptr : that.__Coordinates->clone();
        __AssociatedEdges.clear();
        for (size_t i=0; i< that.__AssociatedEdges.size(); i++)
        {
           __AssociatedEdges.push_back( that.__AssociatedEdges[i]);
        }

   }
   
   GraphNode & GraphNode::operator=(const GraphNode &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Coordinates != nullptr) delete __Coordinates;

         __NodeID = that.__NodeID;
         __Coordinates = that.__Coordinates == nullptr ? nullptr : that.__Coordinates->clone();
         __AssociatedEdges.clear();
         for (size_t i=0; i< that.__AssociatedEdges.size(); i++)
         {
            __AssociatedEdges.push_back( that.__AssociatedEdges[i]);
         }

      }
      return *this;
   }

   GraphNode* GraphNode::clone() const
   {
        return new GraphNode(*this);
   }
   
   GraphNode::~GraphNode(void)
   {
      if (__Coordinates != nullptr) delete __Coordinates;

   }
  
   void GraphNode::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__NodeID);
      assert(__Coordinates != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Coordinates, buf);
      buf.putUShort( static_cast<uint16_t>(__AssociatedEdges.size()));
      for (size_t i=0; i<__AssociatedEdges.size(); i++)
      {
         buf.putLong(__AssociatedEdges[i]);
      }

   }
   
   void GraphNode::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __NodeID = buf.getLong();
      {
         if (__Coordinates != nullptr) delete __Coordinates;
         __Coordinates = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Coordinates = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Coordinates != nullptr) __Coordinates->unpack(buf);
            else assert(__Coordinates != nullptr);
         }
      }
      __AssociatedEdges.clear();
      uint16_t __AssociatedEdges_length = buf.getUShort();
      for (uint32_t i=0; i< __AssociatedEdges_length; i++)
      {
         __AssociatedEdges.push_back(buf.getLong() );
      }

   }

   uint32_t GraphNode::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__Coordinates != nullptr ? __Coordinates->calculatePackedSize() + 15 : 1);
      size += 2 + sizeof(int64_t) * __AssociatedEdges.size();

      return size;
   }

   std::string GraphNode::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GraphNode ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "NodeID (int64_t) = " << __NodeID << "\n";
      oss << indent << "Coordinates (Location3D)";
      if (__Coordinates == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "AssociatedEdges (int64 [ " << __AssociatedEdges.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GraphNode::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GraphNode Series=\"ROUTE\">\n";
      str << ws << "   <NodeID>" << __NodeID << "</NodeID>\n";
      if (__Coordinates != nullptr)
      {
         str << ws << "   <Coordinates>";
         str << "\n" + __Coordinates->toXML(depth + 1) + ws + "   ";
         str << "</Coordinates>\n";
      }
      str << ws << "   <AssociatedEdges>\n";
      for (size_t i=0; i<__AssociatedEdges.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedEdges[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedEdges>\n";
      str << ws << "</GraphNode>\n";

      return str.str();
   }

   bool GraphNode::operator==(const GraphNode & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__NodeID != that.__NodeID) return false;
      if(__Coordinates && that.__Coordinates)
      {
         if(__Coordinates->getSeriesNameAsLong() != that.__Coordinates->getSeriesNameAsLong()) return false;
         if(__Coordinates->getSeriesVersion() != that.__Coordinates->getSeriesVersion()) return false;
         if(__Coordinates->getLmcpType() != that.__Coordinates->getLmcpType()) return false;
         if( *(__Coordinates) != *(that.__Coordinates) ) return false;
      }
      else if(__Coordinates != that.__Coordinates) return false;
      if(__AssociatedEdges.size() != that.__AssociatedEdges.size()) return false;
      for (size_t i=0; i<__AssociatedEdges.size(); i++)
      {
         if(__AssociatedEdges[i] != that.__AssociatedEdges[i]) return false;
      }
      return true;

   }

   bool GraphNode::operator!=(const GraphNode & that)
   {
      return( !(operator==(that)) );
   }

   GraphNode& GraphNode::setNodeID(const int64_t val)
   {
      __NodeID = val;
      return *this;
   }

   GraphNode& GraphNode::setCoordinates(const afrl::cmasi::Location3D* const val)
   {
      if (__Coordinates != nullptr) { delete __Coordinates; __Coordinates = nullptr; }
      if (val != nullptr) { __Coordinates = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }



} // end namespace route
} // end namespace messages
} // end namespace uxas

