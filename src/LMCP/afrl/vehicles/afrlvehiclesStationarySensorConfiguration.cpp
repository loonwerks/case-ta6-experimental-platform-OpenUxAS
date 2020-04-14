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
#include "afrl/vehicles/StationarySensorConfiguration.h"


namespace afrl {
namespace vehicles {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string StationarySensorConfiguration::Subscription = "afrl.vehicles.StationarySensorConfiguration";
   const std::string StationarySensorConfiguration::TypeName = "StationarySensorConfiguration";
   const std::string StationarySensorConfiguration::SeriesName = "VEHICLES";
   const int64_t StationarySensorConfiguration::SeriesId = 6216454340153722195LL;
   const uint16_t StationarySensorConfiguration::SeriesVersion = 1;
   const uint32_t StationarySensorConfiguration::TypeId = 5;
   
   bool isStationarySensorConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   bool isStationarySensorConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 5) return false;
      return true;
   }
   
   std::vector< std::string > StationarySensorConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   StationarySensorConfiguration::StationarySensorConfiguration(void) : afrl::cmasi::EntityConfiguration()
   {

   }
     
   StationarySensorConfiguration::StationarySensorConfiguration(const StationarySensorConfiguration &that) : afrl::cmasi::EntityConfiguration(that)
   {

   }
   
   StationarySensorConfiguration & StationarySensorConfiguration::operator=(const StationarySensorConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityConfiguration::operator=(that);


      }
      return *this;
   }

   StationarySensorConfiguration* StationarySensorConfiguration::clone() const
   {
        return new StationarySensorConfiguration(*this);
   }
   
   StationarySensorConfiguration::~StationarySensorConfiguration(void)
   {

   }
  
   void StationarySensorConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityConfiguration::pack(buf);
      // Copy the class into the buffer

   }
   
   void StationarySensorConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityConfiguration::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t StationarySensorConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityConfiguration::calculatePackedSize();

      return size;
   }

   std::string StationarySensorConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( StationarySensorConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ID (int64_t) = " << __ID << "\n";
      oss << indent << "Affiliation (std::string) = " << __Affiliation << "\n";
      oss << indent << "EntityType (std::string) = " << __EntityType << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "NominalSpeed (float) = " << __NominalSpeed << "\n";
      oss << indent << "NominalAltitude (float) = " << __NominalAltitude << "\n";
      oss << indent << "NominalAltitudeType (AltitudeType) = " << __NominalAltitudeType << "\n";
      oss << indent << "PayloadConfigurationList (PayloadConfiguration [ " << __PayloadConfigurationList.size() << ", var ])\n";
      oss << indent << "Info (KeyValuePair [ " << __Info.size() << ", var ])\n";


      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string StationarySensorConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<StationarySensorConfiguration Series=\"VEHICLES\">\n";
      str << ws << "   <ID>" << __ID << "</ID>\n";
      str << ws << "   <Affiliation>" << __Affiliation << "</Affiliation>\n";
      str << ws << "   <EntityType>" << __EntityType << "</EntityType>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      str << ws << "   <NominalSpeed>" << __NominalSpeed << "</NominalSpeed>\n";
      str << ws << "   <NominalAltitude>" << __NominalAltitude << "</NominalAltitude>\n";
      str << ws << "   <NominalAltitudeType>" << afrl::cmasi::AltitudeType::get_string(__NominalAltitudeType) << "</NominalAltitudeType>\n";
      str << ws << "   <PayloadConfigurationList>\n";
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         str << (__PayloadConfigurationList[i] == nullptr ? ( ws + "   <null/>\n") : (__PayloadConfigurationList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PayloadConfigurationList>\n";
      str << ws << "   <Info>\n";
      for (size_t i=0; i<__Info.size(); i++)
      {
         str << (__Info[i] == nullptr ? ( ws + "   <null/>\n") : (__Info[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Info>\n";
      str << ws << "</StationarySensorConfiguration>\n";

      return str.str();
   }

   bool StationarySensorConfiguration::operator==(const StationarySensorConfiguration & that)
   {
      if( afrl::cmasi::EntityConfiguration::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool StationarySensorConfiguration::operator!=(const StationarySensorConfiguration & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace vehicles
} // end namespace afrl

