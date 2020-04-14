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
#include "afrl/impact/PowerConfiguration.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PowerConfiguration::Subscription = "afrl.impact.PowerConfiguration";
   const std::string PowerConfiguration::TypeName = "PowerConfiguration";
   const std::string PowerConfiguration::SeriesName = "IMPACT";
   const int64_t PowerConfiguration::SeriesId = 5281966179208134656LL;
   const uint16_t PowerConfiguration::SeriesVersion = 14;
   const uint32_t PowerConfiguration::TypeId = 1;
   
   bool isPowerConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isPowerConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > PowerConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PowerConfiguration::PowerConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {
      __NominalPowerConfiguration = afrl::impact::PowerPlant::Gasoline;

   }
     
   PowerConfiguration::PowerConfiguration(const PowerConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __NominalPowerConfiguration = that.__NominalPowerConfiguration;

   }
   
   PowerConfiguration & PowerConfiguration::operator=(const PowerConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);

         __NominalPowerConfiguration = that.__NominalPowerConfiguration;

      }
      return *this;
   }

   PowerConfiguration* PowerConfiguration::clone() const
   {
        return new PowerConfiguration(*this);
   }
   
   PowerConfiguration::~PowerConfiguration(void)
   {

   }
  
   void PowerConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __NominalPowerConfiguration);

   }
   
   void PowerConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __NominalPowerConfiguration = (afrl::impact::PowerPlant::PowerPlant) buf.getInt();

   }

   uint32_t PowerConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += sizeof(afrl::impact::PowerPlant::PowerPlant);

      return size;
   }

   std::string PowerConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PowerConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "NominalPowerConfiguration (PowerPlant) = " << __NominalPowerConfiguration << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PowerConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PowerConfiguration Series=\"IMPACT\">\n";
      str << ws << "   <NominalPowerConfiguration>" << afrl::impact::PowerPlant::get_string(__NominalPowerConfiguration) << "</NominalPowerConfiguration>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</PowerConfiguration>\n";

      return str.str();
   }

   bool PowerConfiguration::operator==(const PowerConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__NominalPowerConfiguration != that.__NominalPowerConfiguration) return false;
      return true;

   }

   bool PowerConfiguration::operator!=(const PowerConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   PowerConfiguration& PowerConfiguration::setNominalPowerConfiguration(const afrl::impact::PowerPlant::PowerPlant val)
   {
      __NominalPowerConfiguration = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

