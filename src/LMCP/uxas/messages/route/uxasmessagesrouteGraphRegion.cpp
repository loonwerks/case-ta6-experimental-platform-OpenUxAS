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
#include "uxas/messages/route/GraphRegion.h"


namespace uxas {
namespace messages {
namespace route {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GraphRegion::Subscription = "uxas.messages.route.GraphRegion";
   const std::string GraphRegion::TypeName = "GraphRegion";
   const std::string GraphRegion::SeriesName = "ROUTE";
   const int64_t GraphRegion::SeriesId = 5931053054693474304LL;
   const uint16_t GraphRegion::SeriesVersion = 4;
   const uint32_t GraphRegion::TypeId = 3;
   
   bool isGraphRegion(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isGraphRegion(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5931053054693474304LL) return false;
      if(obj->getSeriesVersion() != 4) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > GraphRegionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GraphRegion::GraphRegion(void) : avtas::lmcp::Object()
   {
      __ID = 0LL;

   }
     
   GraphRegion::GraphRegion(const GraphRegion &that) : avtas::lmcp::Object(that)
   {
        __ID = that.__ID;
        __NodeList.clear();
        for (size_t i=0; i< that.__NodeList.size(); i++)
        {
           __NodeList.push_back( that.__NodeList[i] == nullptr ? nullptr : that.__NodeList[i]->clone());
        }
        __EdgeList.clear();
        for (size_t i=0; i< that.__EdgeList.size(); i++)
        {
           __EdgeList.push_back( that.__EdgeList[i] == nullptr ? nullptr : that.__EdgeList[i]->clone());
        }

   }
   
   GraphRegion & GraphRegion::operator=(const GraphRegion &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__NodeList.size(); i++)
         {
            if (__NodeList[i] != nullptr) delete __NodeList[i];
         }
         for (size_t i=0; i<__EdgeList.size(); i++)
         {
            if (__EdgeList[i] != nullptr) delete __EdgeList[i];
         }

         __ID = that.__ID;
         __NodeList.clear();
         for (size_t i=0; i< that.__NodeList.size(); i++)
         {
            __NodeList.push_back( that.__NodeList[i] == nullptr ? nullptr : that.__NodeList[i]->clone());
         }
         __EdgeList.clear();
         for (size_t i=0; i< that.__EdgeList.size(); i++)
         {
            __EdgeList.push_back( that.__EdgeList[i] == nullptr ? nullptr : that.__EdgeList[i]->clone());
         }

      }
      return *this;
   }

   GraphRegion* GraphRegion::clone() const
   {
        return new GraphRegion(*this);
   }
   
   GraphRegion::~GraphRegion(void)
   {
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         if (__NodeList[i] != nullptr) delete __NodeList[i];
      }
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         if (__EdgeList[i] != nullptr) delete __EdgeList[i];
      }

   }
  
   void GraphRegion::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ID);
      buf.putUInt( static_cast<uint32_t>(__NodeList.size()));
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         assert(__NodeList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __NodeList[i], buf);
      }
      buf.putUInt( static_cast<uint32_t>(__EdgeList.size()));
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         assert(__EdgeList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EdgeList[i], buf);
      }

   }
   
   void GraphRegion::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ID = buf.getLong();
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         if (__NodeList[i] != nullptr)
            delete __NodeList[i];
      }
      __NodeList.clear();
      uint32_t __NodeList_length = buf.getUInt();
      for (uint32_t i=0; i< __NodeList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::GraphNode* e = (uxas::messages::route::GraphNode*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __NodeList.push_back(e);
         }
      }
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         if (__EdgeList[i] != nullptr)
            delete __EdgeList[i];
      }
      __EdgeList.clear();
      uint32_t __EdgeList_length = buf.getUInt();
      for (uint32_t i=0; i< __EdgeList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::route::GraphEdge* e = (uxas::messages::route::GraphEdge*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __EdgeList.push_back(e);
         }
      }

   }

   uint32_t GraphRegion::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 4;
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         if (__NodeList[i] != nullptr)
         {
            size += __NodeList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 4;
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         if (__EdgeList[i] != nullptr)
         {
            size += __EdgeList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string GraphRegion::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GraphRegion ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ID (int64_t) = " << __ID << "\n";
      oss << indent << "NodeList (GraphNode [ " << __NodeList.size() << ", var ])\n";
      oss << indent << "EdgeList (GraphEdge [ " << __EdgeList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GraphRegion::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GraphRegion Series=\"ROUTE\">\n";
      str << ws << "   <ID>" << __ID << "</ID>\n";
      str << ws << "   <NodeList>\n";
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         str << (__NodeList[i] == nullptr ? ( ws + "   <null/>\n") : (__NodeList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </NodeList>\n";
      str << ws << "   <EdgeList>\n";
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         str << (__EdgeList[i] == nullptr ? ( ws + "   <null/>\n") : (__EdgeList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </EdgeList>\n";
      str << ws << "</GraphRegion>\n";

      return str.str();
   }

   bool GraphRegion::operator==(const GraphRegion & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ID != that.__ID) return false;
      if(__NodeList.size() != that.__NodeList.size()) return false;
      for (size_t i=0; i<__NodeList.size(); i++)
      {
         if(__NodeList[i] && that.__NodeList[i])
         {
            if(__NodeList[i]->getSeriesNameAsLong() != that.__NodeList[i]->getSeriesNameAsLong()) return false;
            if(__NodeList[i]->getSeriesVersion() != that.__NodeList[i]->getSeriesVersion()) return false;
            if(__NodeList[i]->getLmcpType() != that.__NodeList[i]->getLmcpType()) return false;
            if( *(__NodeList[i]) != *(that.__NodeList[i]) ) return false;
         }
         else if(__NodeList[i] != that.__NodeList[i]) return false;
      }
      if(__EdgeList.size() != that.__EdgeList.size()) return false;
      for (size_t i=0; i<__EdgeList.size(); i++)
      {
         if(__EdgeList[i] && that.__EdgeList[i])
         {
            if(__EdgeList[i]->getSeriesNameAsLong() != that.__EdgeList[i]->getSeriesNameAsLong()) return false;
            if(__EdgeList[i]->getSeriesVersion() != that.__EdgeList[i]->getSeriesVersion()) return false;
            if(__EdgeList[i]->getLmcpType() != that.__EdgeList[i]->getLmcpType()) return false;
            if( *(__EdgeList[i]) != *(that.__EdgeList[i]) ) return false;
         }
         else if(__EdgeList[i] != that.__EdgeList[i]) return false;
      }
      return true;

   }

   bool GraphRegion::operator!=(const GraphRegion & that)
   {
      return( !(operator==(that)) );
   }

   GraphRegion& GraphRegion::setID(const int64_t val)
   {
      __ID = val;
      return *this;
   }




} // end namespace route
} // end namespace messages
} // end namespace uxas

