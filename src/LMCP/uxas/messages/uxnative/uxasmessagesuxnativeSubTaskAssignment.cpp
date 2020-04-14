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
#include "uxas/messages/uxnative/SubTaskAssignment.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/AreaSearchTask.h"
#include "afrl/cmasi/LineSearchTask.h"
#include "afrl/cmasi/PointSearchTask.h"
#include "afrl/cmasi/LoiterTask.h"
#include "afrl/cmasi/MustFlyTask.h"
#include "afrl/cmasi/AirVehicleState.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SubTaskAssignment::Subscription = "uxas.messages.uxnative.SubTaskAssignment";
   const std::string SubTaskAssignment::TypeName = "SubTaskAssignment";
   const std::string SubTaskAssignment::SeriesName = "UXNATIVE";
   const int64_t SubTaskAssignment::SeriesId = 6149751333668345413LL;
   const uint16_t SubTaskAssignment::SeriesVersion = 9;
   const uint32_t SubTaskAssignment::TypeId = 11;
   
   bool isSubTaskAssignment(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   bool isSubTaskAssignment(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   std::vector< std::string > SubTaskAssignmentDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SubTaskAssignment::SubTaskAssignment(void) : avtas::lmcp::Object()
   {

   }
     
   SubTaskAssignment::SubTaskAssignment(const SubTaskAssignment &that) : avtas::lmcp::Object(that)
   {
        __SubTasks.clear();
        for (size_t i=0; i< that.__SubTasks.size(); i++)
        {
           __SubTasks.push_back( that.__SubTasks[i] == nullptr ? nullptr : that.__SubTasks[i]->clone());
        }
        __Neighbors.clear();
        for (size_t i=0; i< that.__Neighbors.size(); i++)
        {
           __Neighbors.push_back( that.__Neighbors[i] == nullptr ? nullptr : that.__Neighbors[i]->clone());
        }

   }
   
   SubTaskAssignment & SubTaskAssignment::operator=(const SubTaskAssignment &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__SubTasks.size(); i++)
         {
            if (__SubTasks[i] != nullptr) delete __SubTasks[i];
         }
         for (size_t i=0; i<__Neighbors.size(); i++)
         {
            if (__Neighbors[i] != nullptr) delete __Neighbors[i];
         }

         __SubTasks.clear();
         for (size_t i=0; i< that.__SubTasks.size(); i++)
         {
            __SubTasks.push_back( that.__SubTasks[i] == nullptr ? nullptr : that.__SubTasks[i]->clone());
         }
         __Neighbors.clear();
         for (size_t i=0; i< that.__Neighbors.size(); i++)
         {
            __Neighbors.push_back( that.__Neighbors[i] == nullptr ? nullptr : that.__Neighbors[i]->clone());
         }

      }
      return *this;
   }

   SubTaskAssignment* SubTaskAssignment::clone() const
   {
        return new SubTaskAssignment(*this);
   }
   
   SubTaskAssignment::~SubTaskAssignment(void)
   {
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         if (__SubTasks[i] != nullptr) delete __SubTasks[i];
      }
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         if (__Neighbors[i] != nullptr) delete __Neighbors[i];
      }

   }
  
   void SubTaskAssignment::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__SubTasks.size()));
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         assert(__SubTasks[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __SubTasks[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Neighbors.size()));
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         assert(__Neighbors[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Neighbors[i], buf);
      }

   }
   
   void SubTaskAssignment::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         if (__SubTasks[i] != nullptr)
            delete __SubTasks[i];
      }
      __SubTasks.clear();
      uint16_t __SubTasks_length = buf.getUShort();
      for (uint32_t i=0; i< __SubTasks_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Task* e = (afrl::cmasi::Task*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __SubTasks.push_back(e);
         }
      }
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         if (__Neighbors[i] != nullptr)
            delete __Neighbors[i];
      }
      __Neighbors.clear();
      uint16_t __Neighbors_length = buf.getUShort();
      for (uint32_t i=0; i< __Neighbors_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::EntityState* e = (afrl::cmasi::EntityState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Neighbors.push_back(e);
         }
      }

   }

   uint32_t SubTaskAssignment::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         if (__SubTasks[i] != nullptr)
         {
            size += __SubTasks[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         if (__Neighbors[i] != nullptr)
         {
            size += __Neighbors[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string SubTaskAssignment::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SubTaskAssignment ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "SubTasks (Task [ " << __SubTasks.size() << ", var ])\n";
      oss << indent << "Neighbors (EntityState [ " << __Neighbors.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SubTaskAssignment::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SubTaskAssignment Series=\"UXNATIVE\">\n";
      str << ws << "   <SubTasks>\n";
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         str << (__SubTasks[i] == nullptr ? ( ws + "   <null/>\n") : (__SubTasks[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </SubTasks>\n";
      str << ws << "   <Neighbors>\n";
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         str << (__Neighbors[i] == nullptr ? ( ws + "   <null/>\n") : (__Neighbors[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Neighbors>\n";
      str << ws << "</SubTaskAssignment>\n";

      return str.str();
   }

   bool SubTaskAssignment::operator==(const SubTaskAssignment & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__SubTasks.size() != that.__SubTasks.size()) return false;
      for (size_t i=0; i<__SubTasks.size(); i++)
      {
         if(__SubTasks[i] && that.__SubTasks[i])
         {
            if(__SubTasks[i]->getSeriesNameAsLong() != that.__SubTasks[i]->getSeriesNameAsLong()) return false;
            if(__SubTasks[i]->getSeriesVersion() != that.__SubTasks[i]->getSeriesVersion()) return false;
            if(__SubTasks[i]->getLmcpType() != that.__SubTasks[i]->getLmcpType()) return false;
            if( *(__SubTasks[i]) != *(that.__SubTasks[i]) ) return false;
         }
         else if(__SubTasks[i] != that.__SubTasks[i]) return false;
      }
      if(__Neighbors.size() != that.__Neighbors.size()) return false;
      for (size_t i=0; i<__Neighbors.size(); i++)
      {
         if(__Neighbors[i] && that.__Neighbors[i])
         {
            if(__Neighbors[i]->getSeriesNameAsLong() != that.__Neighbors[i]->getSeriesNameAsLong()) return false;
            if(__Neighbors[i]->getSeriesVersion() != that.__Neighbors[i]->getSeriesVersion()) return false;
            if(__Neighbors[i]->getLmcpType() != that.__Neighbors[i]->getLmcpType()) return false;
            if( *(__Neighbors[i]) != *(that.__Neighbors[i]) ) return false;
         }
         else if(__Neighbors[i] != that.__Neighbors[i]) return false;
      }
      return true;

   }

   bool SubTaskAssignment::operator!=(const SubTaskAssignment & that)
   {
      return( !(operator==(that)) );
   }




} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

