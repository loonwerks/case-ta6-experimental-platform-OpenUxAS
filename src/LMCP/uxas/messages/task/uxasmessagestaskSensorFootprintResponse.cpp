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
#include "uxas/messages/task/SensorFootprintResponse.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SensorFootprintResponse::Subscription = "uxas.messages.task.SensorFootprintResponse";
   const std::string SensorFootprintResponse::TypeName = "SensorFootprintResponse";
   const std::string SensorFootprintResponse::SeriesName = "UXTASK";
   const int64_t SensorFootprintResponse::SeriesId = 6149757930721443840LL;
   const uint16_t SensorFootprintResponse::SeriesVersion = 8;
   const uint32_t SensorFootprintResponse::TypeId = 13;
   
   bool isSensorFootprintResponse(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   bool isSensorFootprintResponse(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   std::vector< std::string > SensorFootprintResponseDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SensorFootprintResponse::SensorFootprintResponse(void) : avtas::lmcp::Object()
   {
      __ResponseID = 0LL;

   }
     
   SensorFootprintResponse::SensorFootprintResponse(const SensorFootprintResponse &that) : avtas::lmcp::Object(that)
   {
        __ResponseID = that.__ResponseID;
        __Footprints.clear();
        for (size_t i=0; i< that.__Footprints.size(); i++)
        {
           __Footprints.push_back( that.__Footprints[i] == nullptr ? nullptr : that.__Footprints[i]->clone());
        }

   }
   
   SensorFootprintResponse & SensorFootprintResponse::operator=(const SensorFootprintResponse &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Footprints.size(); i++)
         {
            if (__Footprints[i] != nullptr) delete __Footprints[i];
         }

         __ResponseID = that.__ResponseID;
         __Footprints.clear();
         for (size_t i=0; i< that.__Footprints.size(); i++)
         {
            __Footprints.push_back( that.__Footprints[i] == nullptr ? nullptr : that.__Footprints[i]->clone());
         }

      }
      return *this;
   }

   SensorFootprintResponse* SensorFootprintResponse::clone() const
   {
        return new SensorFootprintResponse(*this);
   }
   
   SensorFootprintResponse::~SensorFootprintResponse(void)
   {
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         if (__Footprints[i] != nullptr) delete __Footprints[i];
      }

   }
  
   void SensorFootprintResponse::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ResponseID);
      buf.putUShort( static_cast<uint16_t>(__Footprints.size()));
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         assert(__Footprints[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Footprints[i], buf);
      }

   }
   
   void SensorFootprintResponse::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ResponseID = buf.getLong();
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
            uxas::messages::task::SensorFootprint* e = (uxas::messages::task::SensorFootprint*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Footprints.push_back(e);
         }
      }

   }

   uint32_t SensorFootprintResponse::calculatePackedSize(void) const
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

   std::string SensorFootprintResponse::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SensorFootprintResponse ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ResponseID (int64_t) = " << __ResponseID << "\n";
      oss << indent << "Footprints (SensorFootprint [ " << __Footprints.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SensorFootprintResponse::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SensorFootprintResponse Series=\"UXTASK\">\n";
      str << ws << "   <ResponseID>" << __ResponseID << "</ResponseID>\n";
      str << ws << "   <Footprints>\n";
      for (size_t i=0; i<__Footprints.size(); i++)
      {
         str << (__Footprints[i] == nullptr ? ( ws + "   <null/>\n") : (__Footprints[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Footprints>\n";
      str << ws << "</SensorFootprintResponse>\n";

      return str.str();
   }

   bool SensorFootprintResponse::operator==(const SensorFootprintResponse & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ResponseID != that.__ResponseID) return false;
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

   bool SensorFootprintResponse::operator!=(const SensorFootprintResponse & that)
   {
      return( !(operator==(that)) );
   }

   SensorFootprintResponse& SensorFootprintResponse::setResponseID(const int64_t val)
   {
      __ResponseID = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

