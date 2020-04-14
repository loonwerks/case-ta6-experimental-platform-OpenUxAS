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
#include "afrl/cmasi/ServiceStatus.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ServiceStatus::Subscription = "afrl.cmasi.ServiceStatus";
   const std::string ServiceStatus::TypeName = "ServiceStatus";
   const std::string ServiceStatus::SeriesName = "CMASI";
   const int64_t ServiceStatus::SeriesId = 4849604199710720000LL;
   const uint16_t ServiceStatus::SeriesVersion = 3;
   const uint32_t ServiceStatus::TypeId = 45;
   
   bool isServiceStatus(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 45) return false;
      return true;
   }
   
   bool isServiceStatus(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 45) return false;
      return true;
   }
   
   std::vector< std::string > ServiceStatusDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ServiceStatus::ServiceStatus(void) : avtas::lmcp::Object()
   {
      __PercentComplete = 0.f;
      __StatusType = afrl::cmasi::ServiceStatusType::Information;

   }
     
   ServiceStatus::ServiceStatus(const ServiceStatus &that) : avtas::lmcp::Object(that)
   {
        __PercentComplete = that.__PercentComplete;
        __Info.clear();
        for (size_t i=0; i< that.__Info.size(); i++)
        {
           __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
        }
        __StatusType = that.__StatusType;

   }
   
   ServiceStatus & ServiceStatus::operator=(const ServiceStatus &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Info.size(); i++)
         {
            if (__Info[i] != nullptr) delete __Info[i];
         }

         __PercentComplete = that.__PercentComplete;
         __Info.clear();
         for (size_t i=0; i< that.__Info.size(); i++)
         {
            __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
         }
         __StatusType = that.__StatusType;

      }
      return *this;
   }

   ServiceStatus* ServiceStatus::clone() const
   {
        return new ServiceStatus(*this);
   }
   
   ServiceStatus::~ServiceStatus(void)
   {
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr) delete __Info[i];
      }

   }
  
   void ServiceStatus::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__PercentComplete);
      buf.putUShort( static_cast<uint16_t>(__Info.size()));
      for (size_t i=0; i<__Info.size(); i++)
      {
         assert(__Info[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Info[i], buf);
      }
      buf.putInt( (int32_t) __StatusType);

   }
   
   void ServiceStatus::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __PercentComplete = buf.getFloat();
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
            delete __Info[i];
      }
      __Info.clear();
      uint16_t __Info_length = buf.getUShort();
      for (uint32_t i=0; i< __Info_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Info.push_back(e);
         }
      }
      __StatusType = (afrl::cmasi::ServiceStatusType::ServiceStatusType) buf.getInt();

   }

   uint32_t ServiceStatus::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(float);
      size += 2;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
         {
            size += __Info[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(afrl::cmasi::ServiceStatusType::ServiceStatusType);

      return size;
   }

   std::string ServiceStatus::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ServiceStatus ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PercentComplete (float) = " << __PercentComplete << "\n";
      oss << indent << "Info (KeyValuePair [ " << __Info.size() << ", var ])\n";
      oss << indent << "StatusType (ServiceStatusType) = " << __StatusType << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ServiceStatus::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ServiceStatus Series=\"CMASI\">\n";
      str << ws << "   <PercentComplete>" << __PercentComplete << "</PercentComplete>\n";
      str << ws << "   <Info>\n";
      for (size_t i=0; i<__Info.size(); i++)
      {
         str << (__Info[i] == nullptr ? ( ws + "   <null/>\n") : (__Info[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Info>\n";
      str << ws << "   <StatusType>" << afrl::cmasi::ServiceStatusType::get_string(__StatusType) << "</StatusType>\n";
      str << ws << "</ServiceStatus>\n";

      return str.str();
   }

   bool ServiceStatus::operator==(const ServiceStatus & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__PercentComplete != that.__PercentComplete) return false;
      if(__Info.size() != that.__Info.size()) return false;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if(__Info[i] && that.__Info[i])
         {
            if(__Info[i]->getSeriesNameAsLong() != that.__Info[i]->getSeriesNameAsLong()) return false;
            if(__Info[i]->getSeriesVersion() != that.__Info[i]->getSeriesVersion()) return false;
            if(__Info[i]->getLmcpType() != that.__Info[i]->getLmcpType()) return false;
            if( *(__Info[i]) != *(that.__Info[i]) ) return false;
         }
         else if(__Info[i] != that.__Info[i]) return false;
      }
      if(__StatusType != that.__StatusType) return false;
      return true;

   }

   bool ServiceStatus::operator!=(const ServiceStatus & that)
   {
      return( !(operator==(that)) );
   }

   ServiceStatus& ServiceStatus::setPercentComplete(const float val)
   {
      __PercentComplete = val;
      return *this;
   }


   ServiceStatus& ServiceStatus::setStatusType(const afrl::cmasi::ServiceStatusType::ServiceStatusType val)
   {
      __StatusType = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

