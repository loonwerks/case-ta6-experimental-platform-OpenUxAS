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
#include "afrl/impact/ImpactPayloadConfiguration.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ImpactPayloadConfiguration::Subscription = "afrl.impact.ImpactPayloadConfiguration";
   const std::string ImpactPayloadConfiguration::TypeName = "ImpactPayloadConfiguration";
   const std::string ImpactPayloadConfiguration::SeriesName = "IMPACT";
   const int64_t ImpactPayloadConfiguration::SeriesId = 5281966179208134656LL;
   const uint16_t ImpactPayloadConfiguration::SeriesVersion = 14;
   const uint32_t ImpactPayloadConfiguration::TypeId = 6;
   
   bool isImpactPayloadConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   bool isImpactPayloadConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 6) return false;
      return true;
   }
   
   std::vector< std::string > ImpactPayloadConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ImpactPayloadConfiguration::ImpactPayloadConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {

   }
     
   ImpactPayloadConfiguration::ImpactPayloadConfiguration(const ImpactPayloadConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __AvailablePayloads.clear();
        for (size_t i=0; i< that.__AvailablePayloads.size(); i++)
        {
           __AvailablePayloads.push_back( that.__AvailablePayloads[i]);
        }

   }
   
   ImpactPayloadConfiguration & ImpactPayloadConfiguration::operator=(const ImpactPayloadConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);

         __AvailablePayloads.clear();
         for (size_t i=0; i< that.__AvailablePayloads.size(); i++)
         {
            __AvailablePayloads.push_back( that.__AvailablePayloads[i]);
         }

      }
      return *this;
   }

   ImpactPayloadConfiguration* ImpactPayloadConfiguration::clone() const
   {
        return new ImpactPayloadConfiguration(*this);
   }
   
   ImpactPayloadConfiguration::~ImpactPayloadConfiguration(void)
   {

   }
  
   void ImpactPayloadConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__AvailablePayloads.size()));
      for (size_t i=0; i<__AvailablePayloads.size(); i++)
      {
         buf.putInt( (int32_t) __AvailablePayloads[i]);
      }

   }
   
   void ImpactPayloadConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __AvailablePayloads.clear();
      uint16_t __AvailablePayloads_length = buf.getUShort();
      for (uint32_t i=0; i< __AvailablePayloads_length; i++)
      {
         __AvailablePayloads.push_back( (afrl::impact::ImpactPayloadType::ImpactPayloadType) buf.getInt() );
      }

   }

   uint32_t ImpactPayloadConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += 2 + sizeof(afrl::impact::ImpactPayloadType::ImpactPayloadType) * __AvailablePayloads.size();

      return size;
   }

   std::string ImpactPayloadConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ImpactPayloadConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "AvailablePayloads (ImpactPayloadType [ " << __AvailablePayloads.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ImpactPayloadConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ImpactPayloadConfiguration Series=\"IMPACT\">\n";
      str << ws << "   <AvailablePayloads>\n";
      for (size_t i=0; i<__AvailablePayloads.size(); i++)
      {
         str << ws << "   <ImpactPayloadType>" << afrl::impact::ImpactPayloadType::get_string(__AvailablePayloads[i]) << "</ImpactPayloadType>\n";
      }
      str << ws << "   </AvailablePayloads>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</ImpactPayloadConfiguration>\n";

      return str.str();
   }

   bool ImpactPayloadConfiguration::operator==(const ImpactPayloadConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__AvailablePayloads.size() != that.__AvailablePayloads.size()) return false;
      for (size_t i=0; i<__AvailablePayloads.size(); i++)
      {
         if(__AvailablePayloads[i] != that.__AvailablePayloads[i]) return false;
      }
      return true;

   }

   bool ImpactPayloadConfiguration::operator!=(const ImpactPayloadConfiguration & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace impact
} // end namespace afrl

