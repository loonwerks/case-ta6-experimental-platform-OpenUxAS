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
#include "afrl/vehicles/GroundVehicleConfiguration.h"


namespace afrl {
namespace vehicles {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GroundVehicleConfiguration::Subscription = "afrl.vehicles.GroundVehicleConfiguration";
   const std::string GroundVehicleConfiguration::TypeName = "GroundVehicleConfiguration";
   const std::string GroundVehicleConfiguration::SeriesName = "VEHICLES";
   const int64_t GroundVehicleConfiguration::SeriesId = 6216454340153722195LL;
   const uint16_t GroundVehicleConfiguration::SeriesVersion = 1;
   const uint32_t GroundVehicleConfiguration::TypeId = 1;
   
   bool isGroundVehicleConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isGroundVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > GroundVehicleConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GroundVehicleConfiguration::GroundVehicleConfiguration(void) : afrl::cmasi::EntityConfiguration()
   {
      __RoadGraphID = 0LL;
      __MinimumSpeed = 0.f;
      __MaximumSpeed = 0.f;
      __EnergyRate = 0.f;

   }
     
   GroundVehicleConfiguration::GroundVehicleConfiguration(const GroundVehicleConfiguration &that) : afrl::cmasi::EntityConfiguration(that)
   {
        __RoadGraphID = that.__RoadGraphID;
        __MinimumSpeed = that.__MinimumSpeed;
        __MaximumSpeed = that.__MaximumSpeed;
        __EnergyRate = that.__EnergyRate;

   }
   
   GroundVehicleConfiguration & GroundVehicleConfiguration::operator=(const GroundVehicleConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityConfiguration::operator=(that);

         __RoadGraphID = that.__RoadGraphID;
         __MinimumSpeed = that.__MinimumSpeed;
         __MaximumSpeed = that.__MaximumSpeed;
         __EnergyRate = that.__EnergyRate;

      }
      return *this;
   }

   GroundVehicleConfiguration* GroundVehicleConfiguration::clone() const
   {
        return new GroundVehicleConfiguration(*this);
   }
   
   GroundVehicleConfiguration::~GroundVehicleConfiguration(void)
   {

   }
  
   void GroundVehicleConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RoadGraphID);
      buf.putFloat(__MinimumSpeed);
      buf.putFloat(__MaximumSpeed);
      buf.putFloat(__EnergyRate);

   }
   
   void GroundVehicleConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityConfiguration::unpack(buf);
      // Copy the buffer into the class
      __RoadGraphID = buf.getLong();
      __MinimumSpeed = buf.getFloat();
      __MaximumSpeed = buf.getFloat();
      __EnergyRate = buf.getFloat();

   }

   uint32_t GroundVehicleConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityConfiguration::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string GroundVehicleConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GroundVehicleConfiguration ) {\n";
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

      oss << indent << "RoadGraphID (int64_t) = " << __RoadGraphID << "\n";
      oss << indent << "MinimumSpeed (float) = " << __MinimumSpeed << "\n";
      oss << indent << "MaximumSpeed (float) = " << __MaximumSpeed << "\n";
      oss << indent << "EnergyRate (float) = " << __EnergyRate << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GroundVehicleConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GroundVehicleConfiguration Series=\"VEHICLES\">\n";
      str << ws << "   <RoadGraphID>" << __RoadGraphID << "</RoadGraphID>\n";
      str << ws << "   <MinimumSpeed>" << __MinimumSpeed << "</MinimumSpeed>\n";
      str << ws << "   <MaximumSpeed>" << __MaximumSpeed << "</MaximumSpeed>\n";
      str << ws << "   <EnergyRate>" << __EnergyRate << "</EnergyRate>\n";
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
      str << ws << "</GroundVehicleConfiguration>\n";

      return str.str();
   }

   bool GroundVehicleConfiguration::operator==(const GroundVehicleConfiguration & that)
   {
      if( afrl::cmasi::EntityConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__RoadGraphID != that.__RoadGraphID) return false;
      if(__MinimumSpeed != that.__MinimumSpeed) return false;
      if(__MaximumSpeed != that.__MaximumSpeed) return false;
      if(__EnergyRate != that.__EnergyRate) return false;
      return true;

   }

   bool GroundVehicleConfiguration::operator!=(const GroundVehicleConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   GroundVehicleConfiguration& GroundVehicleConfiguration::setRoadGraphID(const int64_t val)
   {
      __RoadGraphID = val;
      return *this;
   }

   GroundVehicleConfiguration& GroundVehicleConfiguration::setMinimumSpeed(const float val)
   {
      __MinimumSpeed = val;
      return *this;
   }

   GroundVehicleConfiguration& GroundVehicleConfiguration::setMaximumSpeed(const float val)
   {
      __MaximumSpeed = val;
      return *this;
   }

   GroundVehicleConfiguration& GroundVehicleConfiguration::setEnergyRate(const float val)
   {
      __EnergyRate = val;
      return *this;
   }


} // end namespace vehicles
} // end namespace afrl

