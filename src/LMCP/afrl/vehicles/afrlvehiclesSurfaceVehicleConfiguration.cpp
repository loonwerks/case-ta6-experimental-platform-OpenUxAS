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
#include "afrl/vehicles/SurfaceVehicleConfiguration.h"


namespace afrl {
namespace vehicles {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SurfaceVehicleConfiguration::Subscription = "afrl.vehicles.SurfaceVehicleConfiguration";
   const std::string SurfaceVehicleConfiguration::TypeName = "SurfaceVehicleConfiguration";
   const std::string SurfaceVehicleConfiguration::SeriesName = "VEHICLES";
   const int64_t SurfaceVehicleConfiguration::SeriesId = 6216454340153722195LL;
   const uint16_t SurfaceVehicleConfiguration::SeriesVersion = 1;
   const uint32_t SurfaceVehicleConfiguration::TypeId = 3;
   
   bool isSurfaceVehicleConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isSurfaceVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6216454340153722195LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > SurfaceVehicleConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SurfaceVehicleConfiguration::SurfaceVehicleConfiguration(void) : afrl::cmasi::EntityConfiguration()
   {
      __WaterArea = 0LL;
      __MinimumSpeed = 0.f;
      __MaximumSpeed = 0.f;
      __EnergyRate = 0.f;
      __MaxBankAngle = 0.f;
      __MaxBankRate = 0.f;

   }
     
   SurfaceVehicleConfiguration::SurfaceVehicleConfiguration(const SurfaceVehicleConfiguration &that) : afrl::cmasi::EntityConfiguration(that)
   {
        __WaterArea = that.__WaterArea;
        __MinimumSpeed = that.__MinimumSpeed;
        __MaximumSpeed = that.__MaximumSpeed;
        __EnergyRate = that.__EnergyRate;
        __MaxBankAngle = that.__MaxBankAngle;
        __MaxBankRate = that.__MaxBankRate;

   }
   
   SurfaceVehicleConfiguration & SurfaceVehicleConfiguration::operator=(const SurfaceVehicleConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityConfiguration::operator=(that);

         __WaterArea = that.__WaterArea;
         __MinimumSpeed = that.__MinimumSpeed;
         __MaximumSpeed = that.__MaximumSpeed;
         __EnergyRate = that.__EnergyRate;
         __MaxBankAngle = that.__MaxBankAngle;
         __MaxBankRate = that.__MaxBankRate;

      }
      return *this;
   }

   SurfaceVehicleConfiguration* SurfaceVehicleConfiguration::clone() const
   {
        return new SurfaceVehicleConfiguration(*this);
   }
   
   SurfaceVehicleConfiguration::~SurfaceVehicleConfiguration(void)
   {

   }
  
   void SurfaceVehicleConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__WaterArea);
      buf.putFloat(__MinimumSpeed);
      buf.putFloat(__MaximumSpeed);
      buf.putFloat(__EnergyRate);
      buf.putFloat(__MaxBankAngle);
      buf.putFloat(__MaxBankRate);

   }
   
   void SurfaceVehicleConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityConfiguration::unpack(buf);
      // Copy the buffer into the class
      __WaterArea = buf.getLong();
      __MinimumSpeed = buf.getFloat();
      __MaximumSpeed = buf.getFloat();
      __EnergyRate = buf.getFloat();
      __MaxBankAngle = buf.getFloat();
      __MaxBankRate = buf.getFloat();

   }

   uint32_t SurfaceVehicleConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityConfiguration::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string SurfaceVehicleConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SurfaceVehicleConfiguration ) {\n";
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

      oss << indent << "WaterArea (int64_t) = " << __WaterArea << "\n";
      oss << indent << "MinimumSpeed (float) = " << __MinimumSpeed << "\n";
      oss << indent << "MaximumSpeed (float) = " << __MaximumSpeed << "\n";
      oss << indent << "EnergyRate (float) = " << __EnergyRate << "\n";
      oss << indent << "MaxBankAngle (float) = " << __MaxBankAngle << "\n";
      oss << indent << "MaxBankRate (float) = " << __MaxBankRate << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SurfaceVehicleConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SurfaceVehicleConfiguration Series=\"VEHICLES\">\n";
      str << ws << "   <WaterArea>" << __WaterArea << "</WaterArea>\n";
      str << ws << "   <MinimumSpeed>" << __MinimumSpeed << "</MinimumSpeed>\n";
      str << ws << "   <MaximumSpeed>" << __MaximumSpeed << "</MaximumSpeed>\n";
      str << ws << "   <EnergyRate>" << __EnergyRate << "</EnergyRate>\n";
      str << ws << "   <MaxBankAngle>" << __MaxBankAngle << "</MaxBankAngle>\n";
      str << ws << "   <MaxBankRate>" << __MaxBankRate << "</MaxBankRate>\n";
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
      str << ws << "</SurfaceVehicleConfiguration>\n";

      return str.str();
   }

   bool SurfaceVehicleConfiguration::operator==(const SurfaceVehicleConfiguration & that)
   {
      if( afrl::cmasi::EntityConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__WaterArea != that.__WaterArea) return false;
      if(__MinimumSpeed != that.__MinimumSpeed) return false;
      if(__MaximumSpeed != that.__MaximumSpeed) return false;
      if(__EnergyRate != that.__EnergyRate) return false;
      if(__MaxBankAngle != that.__MaxBankAngle) return false;
      if(__MaxBankRate != that.__MaxBankRate) return false;
      return true;

   }

   bool SurfaceVehicleConfiguration::operator!=(const SurfaceVehicleConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setWaterArea(const int64_t val)
   {
      __WaterArea = val;
      return *this;
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setMinimumSpeed(const float val)
   {
      __MinimumSpeed = val;
      return *this;
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setMaximumSpeed(const float val)
   {
      __MaximumSpeed = val;
      return *this;
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setEnergyRate(const float val)
   {
      __EnergyRate = val;
      return *this;
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setMaxBankAngle(const float val)
   {
      __MaxBankAngle = val;
      return *this;
   }

   SurfaceVehicleConfiguration& SurfaceVehicleConfiguration::setMaxBankRate(const float val)
   {
      __MaxBankRate = val;
      return *this;
   }


} // end namespace vehicles
} // end namespace afrl

