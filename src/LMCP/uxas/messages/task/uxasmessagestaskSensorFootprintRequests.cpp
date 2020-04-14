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
#include "uxas/messages/task/SensorFootprintRequests.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SensorFootprintRequests::Subscription = "uxas.messages.task.SensorFootprintRequests";
   const std::string SensorFootprintRequests::TypeName = "SensorFootprintRequests";
   const std::string SensorFootprintRequests::SeriesName = "UXTASK";
   const int64_t SensorFootprintRequests::SeriesId = 6149757930721443840LL;
   const uint16_t SensorFootprintRequests::SeriesVersion = 8;
   const uint32_t SensorFootprintRequests::TypeId = 10;
   
   bool isSensorFootprintRequests(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   bool isSensorFootprintRequests(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   std::vector< std::string > SensorFootprintRequestsDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SensorFootprintRequests::SensorFootprintRequests(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;

   }
     
   SensorFootprintRequests::SensorFootprintRequests(const SensorFootprintRequests &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __Footprints.clear();
        for (size_t i=0; i< that.__Footprints.size(); i++)
        {
           __Footprints.push_back( that.__Footprints[i] == nullptr ? nullptr : that.__Footprints[i]->clone());
        }

   }
   
   SensorFootprintRequests & SensorFootprintRequests::operator=(const SensorFootprintRequests &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Footprints.size(); i++)
         {
            if (__Footprints[i] != nullptr) delete __Footprints[i];
         }

         __RequestID = that.__RequestID;
         __Footprints.clear();
         for (size_t i=0; i< that.__Footprints.size(); i++)
         {
            __Footprints.push_back( that.__Footprints[i] == nullptr ? nullptr : that.__Footprints[i]->clone());
         }

      }
      return *this;
   }

   SensorFootprintRequests* SensorFootprintRequests::clone() const
   {
        return new SensorFootprintRequests(*this);
   }
   
   SensorFootprintRequests::~SensorFootprintRequests(void)
   {
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         if (__Footprints[i] != nullptr) delete __Footprints[i];
      }

   }
  
   void SensorFootprintRequests::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putUShort( static_cast<uint16_t>(__Footprints.size()));
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         assert(__Footprints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Footprints[i], buf);
      }

   }
   
   void SensorFootprintRequests::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         if (__Footprints[i] != nullptr)
            delete __Footprints[i];
      }
      __Footprints.clear();
      uint16_t __Footprints_length = buf.getUShort();
      for (uint32_t i=0; i< __Footprints_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::FootprintRequest* e = (uxas::messages::task::FootprintRequest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Footprints.push_back(e);
         }
      }

   }

   uint32_t SensorFootprintRequests::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         if (__Footprints[i] != nullptr)
         {
            size += __Footprints[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string SensorFootprintRequests::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SensorFootprintRequests ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "Footprints (FootprintRequest [ " << __Footprints.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SensorFootprintRequests::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SensorFootprintRequests Series=\"UXTASK\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <Footprints>\n";
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         str << (__Footprints[i] == nullptr ? ( ws + "   <null/>\n") : (__Footprints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Footprints>\n";
      str << ws << "</SensorFootprintRequests>\n";

      return str.str();
   }

   bool SensorFootprintRequests::operator==(const SensorFootprintRequests & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__Footprints.size() != that.__Footprints.size()) return false;
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         if(__Footprints[i] && that.__Footprints[i])
         {
            if(__Footprints[i]->getSeriesNameAsLong() != that.__Footprints[i]->getSeriesNameAsLong()) return false;
            if(__Footprints[i]->getSeriesVersion() != that.__Footprints[i]->getSeriesVersion()) return false;
            if(__Footprints[i]->getLmcpType() != that.__Footprints[i]->getLmcpType()) return false;
            if( *(__Footprints[i]) != *(that.__Footprints[i]) ) return false;
         }
         else if(__Footprints[i] != that.__Footprints[i]) return false;
      }
      return true;

   }

   bool SensorFootprintRequests::operator!=(const SensorFootprintRequests & that)
   {
      return( !(operator==(that)) );
   }

   SensorFootprintRequests& SensorFootprintRequests::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

