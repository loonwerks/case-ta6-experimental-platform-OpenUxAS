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
#include "afrl/impact/ConfigurationRequest.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string ConfigurationRequest::Subscription = "afrl.impact.ConfigurationRequest";
   const std::string ConfigurationRequest::TypeName = "ConfigurationRequest";
   const std::string ConfigurationRequest::SeriesName = "IMPACT";
   const int64_t ConfigurationRequest::SeriesId = 5281966179208134656LL;
   const uint16_t ConfigurationRequest::SeriesVersion = 14;
   const uint32_t ConfigurationRequest::TypeId = 32;
   
   bool isConfigurationRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 32) return false;
      return true;
   }
   
   bool isConfigurationRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 32) return false;
      return true;
   }
   
   std::vector< std::string > ConfigurationRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   ConfigurationRequest::ConfigurationRequest(void) : avtas::lmcp::Object()
   {

   }
     
   ConfigurationRequest::ConfigurationRequest(const ConfigurationRequest &that) : avtas::lmcp::Object(that)
   {
        __VehicleID.clear();
        for (size_t i=0; i< that.__VehicleID.size(); i++)
        {
           __VehicleID.push_back( that.__VehicleID[i]);
        }

   }
   
   ConfigurationRequest & ConfigurationRequest::operator=(const ConfigurationRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID.clear();
         for (size_t i=0; i< that.__VehicleID.size(); i++)
         {
            __VehicleID.push_back( that.__VehicleID[i]);
         }

      }
      return *this;
   }

   ConfigurationRequest* ConfigurationRequest::clone() const
   {
        return new ConfigurationRequest(*this);
   }
   
   ConfigurationRequest::~ConfigurationRequest(void)
   {

   }
  
   void ConfigurationRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__VehicleID.size()));
      for (size_t i=0; i<__VehicleID.size(); i++)
      {
         buf.putLong(__VehicleID[i]);
      }

   }
   
   void ConfigurationRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID.clear();
      uint16_t __VehicleID_length = buf.getUShort();
      for (uint32_t i=0; i< __VehicleID_length; i++)
      {
         __VehicleID.push_back(buf.getLong() );
      }

   }

   uint32_t ConfigurationRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __VehicleID.size();

      return size;
   }

   std::string ConfigurationRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( ConfigurationRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64 [ " << __VehicleID.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string ConfigurationRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<ConfigurationRequest Series=\"IMPACT\">\n";
      str << ws << "   <VehicleID>\n";
      for (size_t i=0; i<__VehicleID.size(); i++)
      {
         str << ws << "   <int64>" << __VehicleID[i] << "</int64>\n";
      }
      str << ws << "   </VehicleID>\n";
      str << ws << "</ConfigurationRequest>\n";

      return str.str();
   }

   bool ConfigurationRequest::operator==(const ConfigurationRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID.size() != that.__VehicleID.size()) return false;
      for (size_t i=0; i<__VehicleID.size(); i++)
      {
         if(__VehicleID[i] != that.__VehicleID[i]) return false;
      }
      return true;

   }

   bool ConfigurationRequest::operator!=(const ConfigurationRequest & that)
   {
      return( !(operator==(that)) );
   }



} // end namespace impact
} // end namespace afrl

