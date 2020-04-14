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
#include "afrl/cmasi/OperatorSignal.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string OperatorSignal::Subscription = "afrl.cmasi.OperatorSignal";
   const std::string OperatorSignal::TypeName = "OperatorSignal";
   const std::string OperatorSignal::SeriesName = "CMASI";
   const int64_t OperatorSignal::SeriesId = 4849604199710720000LL;
   const uint16_t OperatorSignal::SeriesVersion = 3;
   const uint32_t OperatorSignal::TypeId = 38;
   
   bool isOperatorSignal(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 38) return false;
      return true;
   }
   
   bool isOperatorSignal(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 38) return false;
      return true;
   }
   
   std::vector< std::string > OperatorSignalDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   OperatorSignal::OperatorSignal(void) : avtas::lmcp::Object()
   {

   }
     
   OperatorSignal::OperatorSignal(const OperatorSignal &that) : avtas::lmcp::Object(that)
   {
        __Signals.clear();
        for (size_t i=0; i< that.__Signals.size(); i++)
        {
           __Signals.push_back( that.__Signals[i] == nullptr ? nullptr : that.__Signals[i]->clone());
        }

   }
   
   OperatorSignal & OperatorSignal::operator=(const OperatorSignal &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Signals.size(); i++)
         {
            if (__Signals[i] != nullptr) delete __Signals[i];
         }

         __Signals.clear();
         for (size_t i=0; i< that.__Signals.size(); i++)
         {
            __Signals.push_back( that.__Signals[i] == nullptr ? nullptr : that.__Signals[i]->clone());
         }

      }
      return *this;
   }

   OperatorSignal* OperatorSignal::clone() const
   {
        return new OperatorSignal(*this);
   }
   
   OperatorSignal::~OperatorSignal(void)
   {
      for (size_t i=0; i<__Signals.size(); i++)
      {
         if (__Signals[i] != nullptr) delete __Signals[i];
      }

   }
  
   void OperatorSignal::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__Signals.size()));
      for (size_t i=0; i<__Signals.size(); i++)
      {
         assert(__Signals[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Signals[i], buf);
      }

   }
   
   void OperatorSignal::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      for (size_t i=0; i<__Signals.size(); i++)
      {
         if (__Signals[i] != nullptr)
            delete __Signals[i];
      }
      __Signals.clear();
      uint16_t __Signals_length = buf.getUShort();
      for (uint32_t i=0; i< __Signals_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Signals.push_back(e);
         }
      }

   }

   uint32_t OperatorSignal::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2;
      for (size_t i=0; i<__Signals.size(); i++)
      {
         if (__Signals[i] != nullptr)
         {
            size += __Signals[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string OperatorSignal::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( OperatorSignal ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Signals (KeyValuePair [ " << __Signals.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string OperatorSignal::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<OperatorSignal Series=\"CMASI\">\n";
      str << ws << "   <Signals>\n";
      for (size_t i=0; i<__Signals.size(); i++)
      {
         str << (__Signals[i] == nullptr ? ( ws + "   <null/>\n") : (__Signals[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Signals>\n";
      str << ws << "</OperatorSignal>\n";

      return str.str();
   }

   bool OperatorSignal::operator==(const OperatorSignal & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Signals.size() != that.__Signals.size()) return false;
      for (size_t i=0; i<__Signals.size(); i++)
      {
         if(__Signals[i] && that.__Signals[i])
         {
            if(__Signals[i]->getSeriesNameAsLong() != that.__Signals[i]->getSeriesNameAsLong()) return false;
            if(__Signals[i]->getSeriesVersion() != that.__Signals[i]->getSeriesVersion()) return false;
            if(__Signals[i]->getLmcpType() != that.__Signals[i]->getLmcpType()) return false;
            if( *(__Signals[i]) != *(that.__Signals[i]) ) return false;
         }
         else if(__Signals[i] != that.__Signals[i]) return false;
      }
      return true;

   }

   bool OperatorSignal::operator!=(const OperatorSignal & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace cmasi
} // end namespace afrl

