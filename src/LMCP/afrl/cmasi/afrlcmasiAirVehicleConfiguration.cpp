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
#include "afrl/cmasi/AirVehicleConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AirVehicleConfiguration::Subscription = "afrl.cmasi.AirVehicleConfiguration";
   const std::string AirVehicleConfiguration::TypeName = "AirVehicleConfiguration";
   const std::string AirVehicleConfiguration::SeriesName = "CMASI";
   const int64_t AirVehicleConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t AirVehicleConfiguration::SeriesVersion = 3;
   const uint32_t AirVehicleConfiguration::TypeId = 13;
   
   bool isAirVehicleConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   bool isAirVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   std::vector< std::string > AirVehicleConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AirVehicleConfiguration::AirVehicleConfiguration(void) : afrl::cmasi::EntityConfiguration()
   {
      __MinimumSpeed = 0.f;
      __MaximumSpeed = 0.f;
      __NominalFlightProfile = new afrl::cmasi::FlightProfile();
      __MinimumAltitude = 0.f;
      __MinAltitudeType = afrl::cmasi::AltitudeType::AGL;
      __MaximumAltitude = 1000000.f;
      __MaxAltitudeType = afrl::cmasi::AltitudeType::MSL;

   }
     
   AirVehicleConfiguration::AirVehicleConfiguration(const AirVehicleConfiguration &that) : afrl::cmasi::EntityConfiguration(that)
   {
        __MinimumSpeed = that.__MinimumSpeed;
        __MaximumSpeed = that.__MaximumSpeed;
        __NominalFlightProfile = that.__NominalFlightProfile == nullptr ? nullptr : that.__NominalFlightProfile->clone();
        __AlternateFlightProfiles.clear();
        for (size_t i=0; i< that.__AlternateFlightProfiles.size(); i++)
        {
           __AlternateFlightProfiles.push_back( that.__AlternateFlightProfiles[i] == nullptr ? nullptr : that.__AlternateFlightProfiles[i]->clone());
        }
        __AvailableLoiterTypes.clear();
        for (size_t i=0; i< that.__AvailableLoiterTypes.size(); i++)
        {
           __AvailableLoiterTypes.push_back( that.__AvailableLoiterTypes[i]);
        }
        __AvailableTurnTypes.clear();
        for (size_t i=0; i< that.__AvailableTurnTypes.size(); i++)
        {
           __AvailableTurnTypes.push_back( that.__AvailableTurnTypes[i]);
        }
        __MinimumAltitude = that.__MinimumAltitude;
        __MinAltitudeType = that.__MinAltitudeType;
        __MaximumAltitude = that.__MaximumAltitude;
        __MaxAltitudeType = that.__MaxAltitudeType;

   }
   
   AirVehicleConfiguration & AirVehicleConfiguration::operator=(const AirVehicleConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityConfiguration::operator=(that);
         if (__NominalFlightProfile != nullptr) delete __NominalFlightProfile;
         for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
         {
            if (__AlternateFlightProfiles[i] != nullptr) delete __AlternateFlightProfiles[i];
         }

         __MinimumSpeed = that.__MinimumSpeed;
         __MaximumSpeed = that.__MaximumSpeed;
         __NominalFlightProfile = that.__NominalFlightProfile == nullptr ? nullptr : that.__NominalFlightProfile->clone();
         __AlternateFlightProfiles.clear();
         for (size_t i=0; i< that.__AlternateFlightProfiles.size(); i++)
         {
            __AlternateFlightProfiles.push_back( that.__AlternateFlightProfiles[i] == nullptr ? nullptr : that.__AlternateFlightProfiles[i]->clone());
         }
         __AvailableLoiterTypes.clear();
         for (size_t i=0; i< that.__AvailableLoiterTypes.size(); i++)
         {
            __AvailableLoiterTypes.push_back( that.__AvailableLoiterTypes[i]);
         }
         __AvailableTurnTypes.clear();
         for (size_t i=0; i< that.__AvailableTurnTypes.size(); i++)
         {
            __AvailableTurnTypes.push_back( that.__AvailableTurnTypes[i]);
         }
         __MinimumAltitude = that.__MinimumAltitude;
         __MinAltitudeType = that.__MinAltitudeType;
         __MaximumAltitude = that.__MaximumAltitude;
         __MaxAltitudeType = that.__MaxAltitudeType;

      }
      return *this;
   }

   AirVehicleConfiguration* AirVehicleConfiguration::clone() const
   {
        return new AirVehicleConfiguration(*this);
   }
   
   AirVehicleConfiguration::~AirVehicleConfiguration(void)
   {
      if (__NominalFlightProfile != nullptr) delete __NominalFlightProfile;
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         if (__AlternateFlightProfiles[i] != nullptr) delete __AlternateFlightProfiles[i];
      }

   }
  
   void AirVehicleConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__MinimumSpeed);
      buf.putFloat(__MaximumSpeed);
      assert(__NominalFlightProfile != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __NominalFlightProfile, buf);
      buf.putUShort( static_cast<uint16_t>(__AlternateFlightProfiles.size()));
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         assert(__AlternateFlightProfiles[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __AlternateFlightProfiles[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__AvailableLoiterTypes.size()));
      for (size_t i=0; i<__AvailableLoiterTypes.size(); i++)
      {
         buf.putInt( (int32_t) __AvailableLoiterTypes[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__AvailableTurnTypes.size()));
      for (size_t i=0; i<__AvailableTurnTypes.size(); i++)
      {
         buf.putInt( (int32_t) __AvailableTurnTypes[i]);
      }
      buf.putFloat(__MinimumAltitude);
      buf.putInt( (int32_t) __MinAltitudeType);
      buf.putFloat(__MaximumAltitude);
      buf.putInt( (int32_t) __MaxAltitudeType);

   }
   
   void AirVehicleConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityConfiguration::unpack(buf);
      // Copy the buffer into the class
      __MinimumSpeed = buf.getFloat();
      __MaximumSpeed = buf.getFloat();
      {
         if (__NominalFlightProfile != nullptr) delete __NominalFlightProfile;
         __NominalFlightProfile = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __NominalFlightProfile = (afrl::cmasi::FlightProfile*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__NominalFlightProfile != nullptr) __NominalFlightProfile->unpack(buf);
            else assert(__NominalFlightProfile != nullptr);
         }
      }
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         if (__AlternateFlightProfiles[i] != nullptr)
            delete __AlternateFlightProfiles[i];
      }
      __AlternateFlightProfiles.clear();
      uint16_t __AlternateFlightProfiles_length = buf.getUShort();
      for (uint32_t i=0; i< __AlternateFlightProfiles_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::FlightProfile* e = (afrl::cmasi::FlightProfile*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __AlternateFlightProfiles.push_back(e);
         }
      }
      __AvailableLoiterTypes.clear();
      uint16_t __AvailableLoiterTypes_length = buf.getUShort();
      for (uint32_t i=0; i< __AvailableLoiterTypes_length; i++)
      {
         __AvailableLoiterTypes.push_back( (afrl::cmasi::LoiterType::LoiterType) buf.getInt() );
      }
      __AvailableTurnTypes.clear();
      uint16_t __AvailableTurnTypes_length = buf.getUShort();
      for (uint32_t i=0; i< __AvailableTurnTypes_length; i++)
      {
         __AvailableTurnTypes.push_back( (afrl::cmasi::TurnType::TurnType) buf.getInt() );
      }
      __MinimumAltitude = buf.getFloat();
      __MinAltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      __MaximumAltitude = buf.getFloat();
      __MaxAltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();

   }

   uint32_t AirVehicleConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityConfiguration::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(float);
      size += (__NominalFlightProfile != nullptr ? __NominalFlightProfile->calculatePackedSize() + 15 : 1);
      size += 2;
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         if (__AlternateFlightProfiles[i] != nullptr)
         {
            size += __AlternateFlightProfiles[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2 + sizeof(afrl::cmasi::LoiterType::LoiterType) * __AvailableLoiterTypes.size();
      size += 2 + sizeof(afrl::cmasi::TurnType::TurnType) * __AvailableTurnTypes.size();
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);

      return size;
   }

   std::string AirVehicleConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AirVehicleConfiguration ) {\n";
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

      oss << indent << "MinimumSpeed (float) = " << __MinimumSpeed << "\n";
      oss << indent << "MaximumSpeed (float) = " << __MaximumSpeed << "\n";
      oss << indent << "NominalFlightProfile (FlightProfile)";
      if (__NominalFlightProfile == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "AlternateFlightProfiles (FlightProfile [ " << __AlternateFlightProfiles.size() << ", var ])\n";
      oss << indent << "AvailableLoiterTypes (LoiterType [ " << __AvailableLoiterTypes.size() << ", var ])\n";
      oss << indent << "AvailableTurnTypes (TurnType [ " << __AvailableTurnTypes.size() << ", var ])\n";
      oss << indent << "MinimumAltitude (float) = " << __MinimumAltitude << "\n";
      oss << indent << "MinAltitudeType (AltitudeType) = " << __MinAltitudeType << "\n";
      oss << indent << "MaximumAltitude (float) = " << __MaximumAltitude << "\n";
      oss << indent << "MaxAltitudeType (AltitudeType) = " << __MaxAltitudeType << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AirVehicleConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AirVehicleConfiguration Series=\"CMASI\">\n";
      str << ws << "   <MinimumSpeed>" << __MinimumSpeed << "</MinimumSpeed>\n";
      str << ws << "   <MaximumSpeed>" << __MaximumSpeed << "</MaximumSpeed>\n";
      if (__NominalFlightProfile != nullptr)
      {
         str << ws << "   <NominalFlightProfile>";
         str << "\n" + __NominalFlightProfile->toXML(depth + 1) + ws + "   ";
         str << "</NominalFlightProfile>\n";
      }
      str << ws << "   <AlternateFlightProfiles>\n";
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         str << (__AlternateFlightProfiles[i] == nullptr ? ( ws + "   <null/>\n") : (__AlternateFlightProfiles[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </AlternateFlightProfiles>\n";
      str << ws << "   <AvailableLoiterTypes>\n";
      for (size_t i=0; i<__AvailableLoiterTypes.size(); i++)
      {
         str << ws << "   <LoiterType>" << afrl::cmasi::LoiterType::get_string(__AvailableLoiterTypes[i]) << "</LoiterType>\n";
      }
      str << ws << "   </AvailableLoiterTypes>\n";
      str << ws << "   <AvailableTurnTypes>\n";
      for (size_t i=0; i<__AvailableTurnTypes.size(); i++)
      {
         str << ws << "   <TurnType>" << afrl::cmasi::TurnType::get_string(__AvailableTurnTypes[i]) << "</TurnType>\n";
      }
      str << ws << "   </AvailableTurnTypes>\n";
      str << ws << "   <MinimumAltitude>" << __MinimumAltitude << "</MinimumAltitude>\n";
      str << ws << "   <MinAltitudeType>" << afrl::cmasi::AltitudeType::get_string(__MinAltitudeType) << "</MinAltitudeType>\n";
      str << ws << "   <MaximumAltitude>" << __MaximumAltitude << "</MaximumAltitude>\n";
      str << ws << "   <MaxAltitudeType>" << afrl::cmasi::AltitudeType::get_string(__MaxAltitudeType) << "</MaxAltitudeType>\n";
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
      str << ws << "</AirVehicleConfiguration>\n";

      return str.str();
   }

   bool AirVehicleConfiguration::operator==(const AirVehicleConfiguration & that)
   {
      if( afrl::cmasi::EntityConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__MinimumSpeed != that.__MinimumSpeed) return false;
      if(__MaximumSpeed != that.__MaximumSpeed) return false;
      if(__NominalFlightProfile && that.__NominalFlightProfile)
      {
         if(__NominalFlightProfile->getSeriesNameAsLong() != that.__NominalFlightProfile->getSeriesNameAsLong()) return false;
         if(__NominalFlightProfile->getSeriesVersion() != that.__NominalFlightProfile->getSeriesVersion()) return false;
         if(__NominalFlightProfile->getLmcpType() != that.__NominalFlightProfile->getLmcpType()) return false;
         if( *(__NominalFlightProfile) != *(that.__NominalFlightProfile) ) return false;
      }
      else if(__NominalFlightProfile != that.__NominalFlightProfile) return false;
      if(__AlternateFlightProfiles.size() != that.__AlternateFlightProfiles.size()) return false;
      for (size_t i=0; i<__AlternateFlightProfiles.size(); i++)
      {
         if(__AlternateFlightProfiles[i] && that.__AlternateFlightProfiles[i])
         {
            if(__AlternateFlightProfiles[i]->getSeriesNameAsLong() != that.__AlternateFlightProfiles[i]->getSeriesNameAsLong()) return false;
            if(__AlternateFlightProfiles[i]->getSeriesVersion() != that.__AlternateFlightProfiles[i]->getSeriesVersion()) return false;
            if(__AlternateFlightProfiles[i]->getLmcpType() != that.__AlternateFlightProfiles[i]->getLmcpType()) return false;
            if( *(__AlternateFlightProfiles[i]) != *(that.__AlternateFlightProfiles[i]) ) return false;
         }
         else if(__AlternateFlightProfiles[i] != that.__AlternateFlightProfiles[i]) return false;
      }
      if(__AvailableLoiterTypes.size() != that.__AvailableLoiterTypes.size()) return false;
      for (size_t i=0; i<__AvailableLoiterTypes.size(); i++)
      {
         if(__AvailableLoiterTypes[i] != that.__AvailableLoiterTypes[i]) return false;
      }
      if(__AvailableTurnTypes.size() != that.__AvailableTurnTypes.size()) return false;
      for (size_t i=0; i<__AvailableTurnTypes.size(); i++)
      {
         if(__AvailableTurnTypes[i] != that.__AvailableTurnTypes[i]) return false;
      }
      if(__MinimumAltitude != that.__MinimumAltitude) return false;
      if(__MinAltitudeType != that.__MinAltitudeType) return false;
      if(__MaximumAltitude != that.__MaximumAltitude) return false;
      if(__MaxAltitudeType != that.__MaxAltitudeType) return false;
      return true;

   }

   bool AirVehicleConfiguration::operator!=(const AirVehicleConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setMinimumSpeed(const float val)
   {
      __MinimumSpeed = val;
      return *this;
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setMaximumSpeed(const float val)
   {
      __MaximumSpeed = val;
      return *this;
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setNominalFlightProfile(const afrl::cmasi::FlightProfile* const val)
   {
      if (__NominalFlightProfile != nullptr) { delete __NominalFlightProfile; __NominalFlightProfile = nullptr; }
      if (val != nullptr) { __NominalFlightProfile = const_cast< afrl::cmasi::FlightProfile* > (val); }
      return *this;
   }




   AirVehicleConfiguration& AirVehicleConfiguration::setMinimumAltitude(const float val)
   {
      __MinimumAltitude = val;
      return *this;
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setMinAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __MinAltitudeType = val;
      return *this;
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setMaximumAltitude(const float val)
   {
      __MaximumAltitude = val;
      return *this;
   }

   AirVehicleConfiguration& AirVehicleConfiguration::setMaxAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __MaxAltitudeType = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

