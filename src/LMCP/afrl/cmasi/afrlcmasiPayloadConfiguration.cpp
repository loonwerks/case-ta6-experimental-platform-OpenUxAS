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
#include "afrl/cmasi/PayloadConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PayloadConfiguration::Subscription = "afrl.cmasi.PayloadConfiguration";
   const std::string PayloadConfiguration::TypeName = "PayloadConfiguration";
   const std::string PayloadConfiguration::SeriesName = "CMASI";
   const int64_t PayloadConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t PayloadConfiguration::SeriesVersion = 3;
   const uint32_t PayloadConfiguration::TypeId = 5;
   
   bool isPayloadConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   bool isPayloadConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   std::vector< std::string > PayloadConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.impact.PowerConfiguration");
       descendants.push_back("afrl.impact.RadioConfiguration");
       descendants.push_back("afrl.impact.ImpactPayloadConfiguration");
       descendants.push_back("afrl.cmasi.CameraConfiguration");
       descendants.push_back("afrl.cmasi.GimbalConfiguration");
       descendants.push_back("afrl.cmasi.VideoStreamConfiguration");

       return descendants;
   }
   
   PayloadConfiguration::PayloadConfiguration(void) : avtas::lmcp::Object()
   {
      __PayloadID = 0LL;
      __PayloadKind = std::string("");

   }
     
   PayloadConfiguration::PayloadConfiguration(const PayloadConfiguration &that) : avtas::lmcp::Object(that)
   {
        __PayloadID = that.__PayloadID;
        __PayloadKind = that.__PayloadKind;
        __Parameters.clear();
        for (size_t i=0; i< that.__Parameters.size(); i++)
        {
           __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
        }

   }
   
   PayloadConfiguration & PayloadConfiguration::operator=(const PayloadConfiguration &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Parameters.size(); i++)
         {
            if (__Parameters[i] != nullptr) delete __Parameters[i];
         }

         __PayloadID = that.__PayloadID;
         __PayloadKind = that.__PayloadKind;
         __Parameters.clear();
         for (size_t i=0; i< that.__Parameters.size(); i++)
         {
            __Parameters.push_back( that.__Parameters[i] == nullptr ? nullptr : that.__Parameters[i]->clone());
         }

      }
      return *this;
   }

   PayloadConfiguration* PayloadConfiguration::clone() const
   {
        return new PayloadConfiguration(*this);
   }
   
   PayloadConfiguration::~PayloadConfiguration(void)
   {
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr) delete __Parameters[i];
      }

   }
  
   void PayloadConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__PayloadID);
      buf.putString(__PayloadKind);
      buf.putUShort( static_cast<uint16_t>(__Parameters.size()));
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         assert(__Parameters[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Parameters[i], buf);
      }

   }
   
   void PayloadConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __PayloadID = buf.getLong();
      __PayloadKind = buf.getString();
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr)
            delete __Parameters[i];
      }
      __Parameters.clear();
      uint16_t __Parameters_length = buf.getUShort();
      for (uint32_t i=0; i< __Parameters_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Parameters.push_back(e);
         }
      }

   }

   uint32_t PayloadConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __PayloadKind.length();
      size += 2;
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if (__Parameters[i] != nullptr)
         {
            size += __Parameters[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string PayloadConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PayloadConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PayloadConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PayloadConfiguration Series=\"CMASI\">\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</PayloadConfiguration>\n";

      return str.str();
   }

   bool PayloadConfiguration::operator==(const PayloadConfiguration & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__PayloadID != that.__PayloadID) return false;
      if(__PayloadKind != that.__PayloadKind) return false;
      if(__Parameters.size() != that.__Parameters.size()) return false;
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         if(__Parameters[i] && that.__Parameters[i])
         {
            if(__Parameters[i]->getSeriesNameAsLong() != that.__Parameters[i]->getSeriesNameAsLong()) return false;
            if(__Parameters[i]->getSeriesVersion() != that.__Parameters[i]->getSeriesVersion()) return false;
            if(__Parameters[i]->getLmcpType() != that.__Parameters[i]->getLmcpType()) return false;
            if( *(__Parameters[i]) != *(that.__Parameters[i]) ) return false;
         }
         else if(__Parameters[i] != that.__Parameters[i]) return false;
      }
      return true;

   }

   bool PayloadConfiguration::operator!=(const PayloadConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   PayloadConfiguration& PayloadConfiguration::setPayloadID(const int64_t val)
   {
      __PayloadID = val;
      return *this;
   }

   PayloadConfiguration& PayloadConfiguration::setPayloadKind(const std::string val)
   {
      __PayloadKind = val;
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

