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
#include "afrl/cmasi/EntityConfiguration.h"
#include "afrl/cmasi/CameraConfiguration.h"
#include "afrl/cmasi/GimbalConfiguration.h"
#include "afrl/cmasi/VideoStreamConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EntityConfiguration::Subscription = "afrl.cmasi.EntityConfiguration";
   const std::string EntityConfiguration::TypeName = "EntityConfiguration";
   const std::string EntityConfiguration::SeriesName = "CMASI";
   const int64_t EntityConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t EntityConfiguration::SeriesVersion = 3;
   const uint32_t EntityConfiguration::TypeId = 11;
   
   bool isEntityConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   bool isEntityConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   std::vector< std::string > EntityConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.vehicles.GroundVehicleConfiguration");
       descendants.push_back("afrl.vehicles.SurfaceVehicleConfiguration");
       descendants.push_back("afrl.vehicles.StationarySensorConfiguration");
       descendants.push_back("afrl.impact.RadioTowerConfiguration");
       descendants.push_back("afrl.cmasi.AirVehicleConfiguration");

       return descendants;
   }
   
   EntityConfiguration::EntityConfiguration(void) : avtas::lmcp::Object()
   {
      __ID = 0LL;
      __Affiliation = std::string("Unknown");
      __EntityType = std::string("");
      __Label = std::string("");
      __NominalSpeed = 0.f;
      __NominalAltitude = 0.0f;
      __NominalAltitudeType = afrl::cmasi::AltitudeType::AGL;

   }
     
   EntityConfiguration::EntityConfiguration(const EntityConfiguration &that) : avtas::lmcp::Object(that)
   {
        __ID = that.__ID;
        __Affiliation = that.__Affiliation;
        __EntityType = that.__EntityType;
        __Label = that.__Label;
        __NominalSpeed = that.__NominalSpeed;
        __NominalAltitude = that.__NominalAltitude;
        __NominalAltitudeType = that.__NominalAltitudeType;
        __PayloadConfigurationList.clear();
        for (size_t i=0; i< that.__PayloadConfigurationList.size(); i++)
        {
           __PayloadConfigurationList.push_back( that.__PayloadConfigurationList[i] == nullptr ? nullptr : that.__PayloadConfigurationList[i]->clone());
        }
        __Info.clear();
        for (size_t i=0; i< that.__Info.size(); i++)
        {
           __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
        }

   }
   
   EntityConfiguration & EntityConfiguration::operator=(const EntityConfiguration &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
         {
            if (__PayloadConfigurationList[i] != nullptr) delete __PayloadConfigurationList[i];
         }
         for (size_t i=0; i<__Info.size(); i++)
         {
            if (__Info[i] != nullptr) delete __Info[i];
         }

         __ID = that.__ID;
         __Affiliation = that.__Affiliation;
         __EntityType = that.__EntityType;
         __Label = that.__Label;
         __NominalSpeed = that.__NominalSpeed;
         __NominalAltitude = that.__NominalAltitude;
         __NominalAltitudeType = that.__NominalAltitudeType;
         __PayloadConfigurationList.clear();
         for (size_t i=0; i< that.__PayloadConfigurationList.size(); i++)
         {
            __PayloadConfigurationList.push_back( that.__PayloadConfigurationList[i] == nullptr ? nullptr : that.__PayloadConfigurationList[i]->clone());
         }
         __Info.clear();
         for (size_t i=0; i< that.__Info.size(); i++)
         {
            __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
         }

      }
      return *this;
   }

   EntityConfiguration* EntityConfiguration::clone() const
   {
        return new EntityConfiguration(*this);
   }
   
   EntityConfiguration::~EntityConfiguration(void)
   {
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         if (__PayloadConfigurationList[i] != nullptr) delete __PayloadConfigurationList[i];
      }
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr) delete __Info[i];
      }

   }
  
   void EntityConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ID);
      buf.putString(__Affiliation);
      buf.putString(__EntityType);
      buf.putString(__Label);
      buf.putFloat(__NominalSpeed);
      buf.putFloat(__NominalAltitude);
      buf.putInt( (int32_t) __NominalAltitudeType);
      buf.putUShort( static_cast<uint16_t>(__PayloadConfigurationList.size()));
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         assert(__PayloadConfigurationList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PayloadConfigurationList[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Info.size()));
      for (size_t i=0; i<__Info.size(); i++)
      {
         assert(__Info[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Info[i], buf);
      }

   }
   
   void EntityConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ID = buf.getLong();
      __Affiliation = buf.getString();
      __EntityType = buf.getString();
      __Label = buf.getString();
      __NominalSpeed = buf.getFloat();
      __NominalAltitude = buf.getFloat();
      __NominalAltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         if (__PayloadConfigurationList[i] != nullptr)
            delete __PayloadConfigurationList[i];
      }
      __PayloadConfigurationList.clear();
      uint16_t __PayloadConfigurationList_length = buf.getUShort();
      for (uint32_t i=0; i< __PayloadConfigurationList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::PayloadConfiguration* e = (afrl::cmasi::PayloadConfiguration*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PayloadConfigurationList.push_back(e);
         }
      }
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

   }

   uint32_t EntityConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __Affiliation.length();
      size += 2 + __EntityType.length();
      size += 2 + __Label.length();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += 2;
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         if (__PayloadConfigurationList[i] != nullptr)
         {
            size += __PayloadConfigurationList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
         {
            size += __Info[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string EntityConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EntityConfiguration ) {\n";
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

   std::string EntityConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EntityConfiguration Series=\"CMASI\">\n";
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
      str << ws << "</EntityConfiguration>\n";

      return str.str();
   }

   bool EntityConfiguration::operator==(const EntityConfiguration & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ID != that.__ID) return false;
      if(__Affiliation != that.__Affiliation) return false;
      if(__EntityType != that.__EntityType) return false;
      if(__Label != that.__Label) return false;
      if(__NominalSpeed != that.__NominalSpeed) return false;
      if(__NominalAltitude != that.__NominalAltitude) return false;
      if(__NominalAltitudeType != that.__NominalAltitudeType) return false;
      if(__PayloadConfigurationList.size() != that.__PayloadConfigurationList.size()) return false;
      for (size_t i=0; i<__PayloadConfigurationList.size(); i++)
      {
         if(__PayloadConfigurationList[i] && that.__PayloadConfigurationList[i])
         {
            if(__PayloadConfigurationList[i]->getSeriesNameAsLong() != that.__PayloadConfigurationList[i]->getSeriesNameAsLong()) return false;
            if(__PayloadConfigurationList[i]->getSeriesVersion() != that.__PayloadConfigurationList[i]->getSeriesVersion()) return false;
            if(__PayloadConfigurationList[i]->getLmcpType() != that.__PayloadConfigurationList[i]->getLmcpType()) return false;
            if( *(__PayloadConfigurationList[i]) != *(that.__PayloadConfigurationList[i]) ) return false;
         }
         else if(__PayloadConfigurationList[i] != that.__PayloadConfigurationList[i]) return false;
      }
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
      return true;

   }

   bool EntityConfiguration::operator!=(const EntityConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   EntityConfiguration& EntityConfiguration::setID(const int64_t val)
   {
      __ID = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setAffiliation(const std::string val)
   {
      __Affiliation = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setEntityType(const std::string val)
   {
      __EntityType = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setLabel(const std::string val)
   {
      __Label = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setNominalSpeed(const float val)
   {
      __NominalSpeed = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setNominalAltitude(const float val)
   {
      __NominalAltitude = val;
      return *this;
   }

   EntityConfiguration& EntityConfiguration::setNominalAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __NominalAltitudeType = val;
      return *this;
   }




} // end namespace cmasi
} // end namespace afrl

