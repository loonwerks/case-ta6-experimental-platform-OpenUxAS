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
#include "uxas/messages/uxnative/CreateNewService.h"
#include "afrl/cmasi/AirVehicleConfiguration.h"
#include "afrl/cmasi/AirVehicleState.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CreateNewService::Subscription = "uxas.messages.uxnative.CreateNewService";
   const std::string CreateNewService::TypeName = "CreateNewService";
   const std::string CreateNewService::SeriesName = "UXNATIVE";
   const int64_t CreateNewService::SeriesId = 6149751333668345413LL;
   const uint16_t CreateNewService::SeriesVersion = 9;
   const uint32_t CreateNewService::TypeId = 3;
   
   bool isCreateNewService(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isCreateNewService(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > CreateNewServiceDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CreateNewService::CreateNewService(void) : avtas::lmcp::Object()
   {
      __ServiceID = 0LL;
      __XmlConfiguration = std::string("");

   }
     
   CreateNewService::CreateNewService(const CreateNewService &that) : avtas::lmcp::Object(that)
   {
        __ServiceID = that.__ServiceID;
        __XmlConfiguration = that.__XmlConfiguration;
        __EntityConfigurations.clear();
        for (size_t i=0; i< that.__EntityConfigurations.size(); i++)
        {
           __EntityConfigurations.push_back( that.__EntityConfigurations[i] == nullptr ? nullptr : that.__EntityConfigurations[i]->clone());
        }
        __EntityStates.clear();
        for (size_t i=0; i< that.__EntityStates.size(); i++)
        {
           __EntityStates.push_back( that.__EntityStates[i] == nullptr ? nullptr : that.__EntityStates[i]->clone());
        }
        __MissionCommands.clear();
        for (size_t i=0; i< that.__MissionCommands.size(); i++)
        {
           __MissionCommands.push_back( that.__MissionCommands[i] == nullptr ? nullptr : that.__MissionCommands[i]->clone());
        }
        __Areas.clear();
        for (size_t i=0; i< that.__Areas.size(); i++)
        {
           __Areas.push_back( that.__Areas[i] == nullptr ? nullptr : that.__Areas[i]->clone());
        }
        __Lines.clear();
        for (size_t i=0; i< that.__Lines.size(); i++)
        {
           __Lines.push_back( that.__Lines[i] == nullptr ? nullptr : that.__Lines[i]->clone());
        }
        __Points.clear();
        for (size_t i=0; i< that.__Points.size(); i++)
        {
           __Points.push_back( that.__Points[i] == nullptr ? nullptr : that.__Points[i]->clone());
        }
        __KeepInZones.clear();
        for (size_t i=0; i< that.__KeepInZones.size(); i++)
        {
           __KeepInZones.push_back( that.__KeepInZones[i] == nullptr ? nullptr : that.__KeepInZones[i]->clone());
        }
        __KeepOutZones.clear();
        for (size_t i=0; i< that.__KeepOutZones.size(); i++)
        {
           __KeepOutZones.push_back( that.__KeepOutZones[i] == nullptr ? nullptr : that.__KeepOutZones[i]->clone());
        }
        __OperatingRegions.clear();
        for (size_t i=0; i< that.__OperatingRegions.size(); i++)
        {
           __OperatingRegions.push_back( that.__OperatingRegions[i] == nullptr ? nullptr : that.__OperatingRegions[i]->clone());
        }

   }
   
   CreateNewService & CreateNewService::operator=(const CreateNewService &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__EntityConfigurations.size(); i++)
         {
            if (__EntityConfigurations[i] != nullptr) delete __EntityConfigurations[i];
         }
         for (size_t i=0; i<__EntityStates.size(); i++)
         {
            if (__EntityStates[i] != nullptr) delete __EntityStates[i];
         }
         for (size_t i=0; i<__MissionCommands.size(); i++)
         {
            if (__MissionCommands[i] != nullptr) delete __MissionCommands[i];
         }
         for (size_t i=0; i<__Areas.size(); i++)
         {
            if (__Areas[i] != nullptr) delete __Areas[i];
         }
         for (size_t i=0; i<__Lines.size(); i++)
         {
            if (__Lines[i] != nullptr) delete __Lines[i];
         }
         for (size_t i=0; i<__Points.size(); i++)
         {
            if (__Points[i] != nullptr) delete __Points[i];
         }
         for (size_t i=0; i<__KeepInZones.size(); i++)
         {
            if (__KeepInZones[i] != nullptr) delete __KeepInZones[i];
         }
         for (size_t i=0; i<__KeepOutZones.size(); i++)
         {
            if (__KeepOutZones[i] != nullptr) delete __KeepOutZones[i];
         }
         for (size_t i=0; i<__OperatingRegions.size(); i++)
         {
            if (__OperatingRegions[i] != nullptr) delete __OperatingRegions[i];
         }

         __ServiceID = that.__ServiceID;
         __XmlConfiguration = that.__XmlConfiguration;
         __EntityConfigurations.clear();
         for (size_t i=0; i< that.__EntityConfigurations.size(); i++)
         {
            __EntityConfigurations.push_back( that.__EntityConfigurations[i] == nullptr ? nullptr : that.__EntityConfigurations[i]->clone());
         }
         __EntityStates.clear();
         for (size_t i=0; i< that.__EntityStates.size(); i++)
         {
            __EntityStates.push_back( that.__EntityStates[i] == nullptr ? nullptr : that.__EntityStates[i]->clone());
         }
         __MissionCommands.clear();
         for (size_t i=0; i< that.__MissionCommands.size(); i++)
         {
            __MissionCommands.push_back( that.__MissionCommands[i] == nullptr ? nullptr : that.__MissionCommands[i]->clone());
         }
         __Areas.clear();
         for (size_t i=0; i< that.__Areas.size(); i++)
         {
            __Areas.push_back( that.__Areas[i] == nullptr ? nullptr : that.__Areas[i]->clone());
         }
         __Lines.clear();
         for (size_t i=0; i< that.__Lines.size(); i++)
         {
            __Lines.push_back( that.__Lines[i] == nullptr ? nullptr : that.__Lines[i]->clone());
         }
         __Points.clear();
         for (size_t i=0; i< that.__Points.size(); i++)
         {
            __Points.push_back( that.__Points[i] == nullptr ? nullptr : that.__Points[i]->clone());
         }
         __KeepInZones.clear();
         for (size_t i=0; i< that.__KeepInZones.size(); i++)
         {
            __KeepInZones.push_back( that.__KeepInZones[i] == nullptr ? nullptr : that.__KeepInZones[i]->clone());
         }
         __KeepOutZones.clear();
         for (size_t i=0; i< that.__KeepOutZones.size(); i++)
         {
            __KeepOutZones.push_back( that.__KeepOutZones[i] == nullptr ? nullptr : that.__KeepOutZones[i]->clone());
         }
         __OperatingRegions.clear();
         for (size_t i=0; i< that.__OperatingRegions.size(); i++)
         {
            __OperatingRegions.push_back( that.__OperatingRegions[i] == nullptr ? nullptr : that.__OperatingRegions[i]->clone());
         }

      }
      return *this;
   }

   CreateNewService* CreateNewService::clone() const
   {
        return new CreateNewService(*this);
   }
   
   CreateNewService::~CreateNewService(void)
   {
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         if (__EntityConfigurations[i] != nullptr) delete __EntityConfigurations[i];
      }
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         if (__EntityStates[i] != nullptr) delete __EntityStates[i];
      }
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         if (__MissionCommands[i] != nullptr) delete __MissionCommands[i];
      }
      for (size_t i=0; i<__Areas.size(); i++)
      {
         if (__Areas[i] != nullptr) delete __Areas[i];
      }
      for (size_t i=0; i<__Lines.size(); i++)
      {
         if (__Lines[i] != nullptr) delete __Lines[i];
      }
      for (size_t i=0; i<__Points.size(); i++)
      {
         if (__Points[i] != nullptr) delete __Points[i];
      }
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr) delete __KeepInZones[i];
      }
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr) delete __KeepOutZones[i];
      }
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         if (__OperatingRegions[i] != nullptr) delete __OperatingRegions[i];
      }

   }
  
   void CreateNewService::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ServiceID);
      buf.putString(__XmlConfiguration);
      buf.putUShort( static_cast<uint16_t>(__EntityConfigurations.size()));
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         assert(__EntityConfigurations[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EntityConfigurations[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__EntityStates.size()));
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         assert(__EntityStates[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EntityStates[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__MissionCommands.size()));
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         assert(__MissionCommands[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __MissionCommands[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Areas.size()));
      for (size_t i=0; i<__Areas.size(); i++)
      {
         assert(__Areas[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Areas[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Lines.size()));
      for (size_t i=0; i<__Lines.size(); i++)
      {
         assert(__Lines[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Lines[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__Points.size()));
      for (size_t i=0; i<__Points.size(); i++)
      {
         assert(__Points[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Points[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__KeepInZones.size()));
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         assert(__KeepInZones[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __KeepInZones[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__KeepOutZones.size()));
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         assert(__KeepOutZones[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __KeepOutZones[i], buf);
      }
      buf.putUShort( static_cast<uint16_t>(__OperatingRegions.size()));
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         assert(__OperatingRegions[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __OperatingRegions[i], buf);
      }

   }
   
   void CreateNewService::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ServiceID = buf.getLong();
      __XmlConfiguration = buf.getString();
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         if (__EntityConfigurations[i] != nullptr)
            delete __EntityConfigurations[i];
      }
      __EntityConfigurations.clear();
      uint16_t __EntityConfigurations_length = buf.getUShort();
      for (uint32_t i=0; i< __EntityConfigurations_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::EntityConfiguration* e = (afrl::cmasi::EntityConfiguration*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __EntityConfigurations.push_back(e);
         }
      }
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         if (__EntityStates[i] != nullptr)
            delete __EntityStates[i];
      }
      __EntityStates.clear();
      uint16_t __EntityStates_length = buf.getUShort();
      for (uint32_t i=0; i< __EntityStates_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::EntityState* e = (afrl::cmasi::EntityState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __EntityStates.push_back(e);
         }
      }
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         if (__MissionCommands[i] != nullptr)
            delete __MissionCommands[i];
      }
      __MissionCommands.clear();
      uint16_t __MissionCommands_length = buf.getUShort();
      for (uint32_t i=0; i< __MissionCommands_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::MissionCommand* e = (afrl::cmasi::MissionCommand*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __MissionCommands.push_back(e);
         }
      }
      for (size_t i=0; i<__Areas.size(); i++)
      {
         if (__Areas[i] != nullptr)
            delete __Areas[i];
      }
      __Areas.clear();
      uint16_t __Areas_length = buf.getUShort();
      for (uint32_t i=0; i< __Areas_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::AreaOfInterest* e = (afrl::impact::AreaOfInterest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Areas.push_back(e);
         }
      }
      for (size_t i=0; i<__Lines.size(); i++)
      {
         if (__Lines[i] != nullptr)
            delete __Lines[i];
      }
      __Lines.clear();
      uint16_t __Lines_length = buf.getUShort();
      for (uint32_t i=0; i< __Lines_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::LineOfInterest* e = (afrl::impact::LineOfInterest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Lines.push_back(e);
         }
      }
      for (size_t i=0; i<__Points.size(); i++)
      {
         if (__Points[i] != nullptr)
            delete __Points[i];
      }
      __Points.clear();
      uint16_t __Points_length = buf.getUShort();
      for (uint32_t i=0; i< __Points_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::impact::PointOfInterest* e = (afrl::impact::PointOfInterest*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Points.push_back(e);
         }
      }
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr)
            delete __KeepInZones[i];
      }
      __KeepInZones.clear();
      uint16_t __KeepInZones_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepInZones_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeepInZone* e = (afrl::cmasi::KeepInZone*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __KeepInZones.push_back(e);
         }
      }
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr)
            delete __KeepOutZones[i];
      }
      __KeepOutZones.clear();
      uint16_t __KeepOutZones_length = buf.getUShort();
      for (uint32_t i=0; i< __KeepOutZones_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeepOutZone* e = (afrl::cmasi::KeepOutZone*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __KeepOutZones.push_back(e);
         }
      }
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         if (__OperatingRegions[i] != nullptr)
            delete __OperatingRegions[i];
      }
      __OperatingRegions.clear();
      uint16_t __OperatingRegions_length = buf.getUShort();
      for (uint32_t i=0; i< __OperatingRegions_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::OperatingRegion* e = (afrl::cmasi::OperatingRegion*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __OperatingRegions.push_back(e);
         }
      }

   }

   uint32_t CreateNewService::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __XmlConfiguration.length();
      size += 2;
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         if (__EntityConfigurations[i] != nullptr)
         {
            size += __EntityConfigurations[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         if (__EntityStates[i] != nullptr)
         {
            size += __EntityStates[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         if (__MissionCommands[i] != nullptr)
         {
            size += __MissionCommands[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Areas.size(); i++)
      {
         if (__Areas[i] != nullptr)
         {
            size += __Areas[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Lines.size(); i++)
      {
         if (__Lines[i] != nullptr)
         {
            size += __Lines[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__Points.size(); i++)
      {
         if (__Points[i] != nullptr)
         {
            size += __Points[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if (__KeepInZones[i] != nullptr)
         {
            size += __KeepInZones[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if (__KeepOutZones[i] != nullptr)
         {
            size += __KeepOutZones[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += 2;
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         if (__OperatingRegions[i] != nullptr)
         {
            size += __OperatingRegions[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string CreateNewService::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CreateNewService ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ServiceID (int64_t) = " << __ServiceID << "\n";
      oss << indent << "XmlConfiguration (std::string) = " << __XmlConfiguration << "\n";
      oss << indent << "EntityConfigurations (EntityConfiguration [ " << __EntityConfigurations.size() << ", var ])\n";
      oss << indent << "EntityStates (EntityState [ " << __EntityStates.size() << ", var ])\n";
      oss << indent << "MissionCommands (MissionCommand [ " << __MissionCommands.size() << ", var ])\n";
      oss << indent << "Areas (AreaOfInterest [ " << __Areas.size() << ", var ])\n";
      oss << indent << "Lines (LineOfInterest [ " << __Lines.size() << ", var ])\n";
      oss << indent << "Points (PointOfInterest [ " << __Points.size() << ", var ])\n";
      oss << indent << "KeepInZones (KeepInZone [ " << __KeepInZones.size() << ", var ])\n";
      oss << indent << "KeepOutZones (KeepOutZone [ " << __KeepOutZones.size() << ", var ])\n";
      oss << indent << "OperatingRegions (OperatingRegion [ " << __OperatingRegions.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CreateNewService::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CreateNewService Series=\"UXNATIVE\">\n";
      str << ws << "   <ServiceID>" << __ServiceID << "</ServiceID>\n";
      str << ws << "   <XmlConfiguration>" << __XmlConfiguration << "</XmlConfiguration>\n";
      str << ws << "   <EntityConfigurations>\n";
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         str << (__EntityConfigurations[i] == nullptr ? ( ws + "   <null/>\n") : (__EntityConfigurations[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </EntityConfigurations>\n";
      str << ws << "   <EntityStates>\n";
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         str << (__EntityStates[i] == nullptr ? ( ws + "   <null/>\n") : (__EntityStates[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </EntityStates>\n";
      str << ws << "   <MissionCommands>\n";
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         str << (__MissionCommands[i] == nullptr ? ( ws + "   <null/>\n") : (__MissionCommands[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </MissionCommands>\n";
      str << ws << "   <Areas>\n";
      for (size_t i=0; i<__Areas.size(); i++)
      {
         str << (__Areas[i] == nullptr ? ( ws + "   <null/>\n") : (__Areas[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Areas>\n";
      str << ws << "   <Lines>\n";
      for (size_t i=0; i<__Lines.size(); i++)
      {
         str << (__Lines[i] == nullptr ? ( ws + "   <null/>\n") : (__Lines[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Lines>\n";
      str << ws << "   <Points>\n";
      for (size_t i=0; i<__Points.size(); i++)
      {
         str << (__Points[i] == nullptr ? ( ws + "   <null/>\n") : (__Points[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Points>\n";
      str << ws << "   <KeepInZones>\n";
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         str << (__KeepInZones[i] == nullptr ? ( ws + "   <null/>\n") : (__KeepInZones[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </KeepInZones>\n";
      str << ws << "   <KeepOutZones>\n";
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         str << (__KeepOutZones[i] == nullptr ? ( ws + "   <null/>\n") : (__KeepOutZones[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </KeepOutZones>\n";
      str << ws << "   <OperatingRegions>\n";
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         str << (__OperatingRegions[i] == nullptr ? ( ws + "   <null/>\n") : (__OperatingRegions[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </OperatingRegions>\n";
      str << ws << "</CreateNewService>\n";

      return str.str();
   }

   bool CreateNewService::operator==(const CreateNewService & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ServiceID != that.__ServiceID) return false;
      if(__XmlConfiguration != that.__XmlConfiguration) return false;
      if(__EntityConfigurations.size() != that.__EntityConfigurations.size()) return false;
      for (size_t i=0; i<__EntityConfigurations.size(); i++)
      {
         if(__EntityConfigurations[i] && that.__EntityConfigurations[i])
         {
            if(__EntityConfigurations[i]->getSeriesNameAsLong() != that.__EntityConfigurations[i]->getSeriesNameAsLong()) return false;
            if(__EntityConfigurations[i]->getSeriesVersion() != that.__EntityConfigurations[i]->getSeriesVersion()) return false;
            if(__EntityConfigurations[i]->getLmcpType() != that.__EntityConfigurations[i]->getLmcpType()) return false;
            if( *(__EntityConfigurations[i]) != *(that.__EntityConfigurations[i]) ) return false;
         }
         else if(__EntityConfigurations[i] != that.__EntityConfigurations[i]) return false;
      }
      if(__EntityStates.size() != that.__EntityStates.size()) return false;
      for (size_t i=0; i<__EntityStates.size(); i++)
      {
         if(__EntityStates[i] && that.__EntityStates[i])
         {
            if(__EntityStates[i]->getSeriesNameAsLong() != that.__EntityStates[i]->getSeriesNameAsLong()) return false;
            if(__EntityStates[i]->getSeriesVersion() != that.__EntityStates[i]->getSeriesVersion()) return false;
            if(__EntityStates[i]->getLmcpType() != that.__EntityStates[i]->getLmcpType()) return false;
            if( *(__EntityStates[i]) != *(that.__EntityStates[i]) ) return false;
         }
         else if(__EntityStates[i] != that.__EntityStates[i]) return false;
      }
      if(__MissionCommands.size() != that.__MissionCommands.size()) return false;
      for (size_t i=0; i<__MissionCommands.size(); i++)
      {
         if(__MissionCommands[i] && that.__MissionCommands[i])
         {
            if(__MissionCommands[i]->getSeriesNameAsLong() != that.__MissionCommands[i]->getSeriesNameAsLong()) return false;
            if(__MissionCommands[i]->getSeriesVersion() != that.__MissionCommands[i]->getSeriesVersion()) return false;
            if(__MissionCommands[i]->getLmcpType() != that.__MissionCommands[i]->getLmcpType()) return false;
            if( *(__MissionCommands[i]) != *(that.__MissionCommands[i]) ) return false;
         }
         else if(__MissionCommands[i] != that.__MissionCommands[i]) return false;
      }
      if(__Areas.size() != that.__Areas.size()) return false;
      for (size_t i=0; i<__Areas.size(); i++)
      {
         if(__Areas[i] && that.__Areas[i])
         {
            if(__Areas[i]->getSeriesNameAsLong() != that.__Areas[i]->getSeriesNameAsLong()) return false;
            if(__Areas[i]->getSeriesVersion() != that.__Areas[i]->getSeriesVersion()) return false;
            if(__Areas[i]->getLmcpType() != that.__Areas[i]->getLmcpType()) return false;
            if( *(__Areas[i]) != *(that.__Areas[i]) ) return false;
         }
         else if(__Areas[i] != that.__Areas[i]) return false;
      }
      if(__Lines.size() != that.__Lines.size()) return false;
      for (size_t i=0; i<__Lines.size(); i++)
      {
         if(__Lines[i] && that.__Lines[i])
         {
            if(__Lines[i]->getSeriesNameAsLong() != that.__Lines[i]->getSeriesNameAsLong()) return false;
            if(__Lines[i]->getSeriesVersion() != that.__Lines[i]->getSeriesVersion()) return false;
            if(__Lines[i]->getLmcpType() != that.__Lines[i]->getLmcpType()) return false;
            if( *(__Lines[i]) != *(that.__Lines[i]) ) return false;
         }
         else if(__Lines[i] != that.__Lines[i]) return false;
      }
      if(__Points.size() != that.__Points.size()) return false;
      for (size_t i=0; i<__Points.size(); i++)
      {
         if(__Points[i] && that.__Points[i])
         {
            if(__Points[i]->getSeriesNameAsLong() != that.__Points[i]->getSeriesNameAsLong()) return false;
            if(__Points[i]->getSeriesVersion() != that.__Points[i]->getSeriesVersion()) return false;
            if(__Points[i]->getLmcpType() != that.__Points[i]->getLmcpType()) return false;
            if( *(__Points[i]) != *(that.__Points[i]) ) return false;
         }
         else if(__Points[i] != that.__Points[i]) return false;
      }
      if(__KeepInZones.size() != that.__KeepInZones.size()) return false;
      for (size_t i=0; i<__KeepInZones.size(); i++)
      {
         if(__KeepInZones[i] && that.__KeepInZones[i])
         {
            if(__KeepInZones[i]->getSeriesNameAsLong() != that.__KeepInZones[i]->getSeriesNameAsLong()) return false;
            if(__KeepInZones[i]->getSeriesVersion() != that.__KeepInZones[i]->getSeriesVersion()) return false;
            if(__KeepInZones[i]->getLmcpType() != that.__KeepInZones[i]->getLmcpType()) return false;
            if( *(__KeepInZones[i]) != *(that.__KeepInZones[i]) ) return false;
         }
         else if(__KeepInZones[i] != that.__KeepInZones[i]) return false;
      }
      if(__KeepOutZones.size() != that.__KeepOutZones.size()) return false;
      for (size_t i=0; i<__KeepOutZones.size(); i++)
      {
         if(__KeepOutZones[i] && that.__KeepOutZones[i])
         {
            if(__KeepOutZones[i]->getSeriesNameAsLong() != that.__KeepOutZones[i]->getSeriesNameAsLong()) return false;
            if(__KeepOutZones[i]->getSeriesVersion() != that.__KeepOutZones[i]->getSeriesVersion()) return false;
            if(__KeepOutZones[i]->getLmcpType() != that.__KeepOutZones[i]->getLmcpType()) return false;
            if( *(__KeepOutZones[i]) != *(that.__KeepOutZones[i]) ) return false;
         }
         else if(__KeepOutZones[i] != that.__KeepOutZones[i]) return false;
      }
      if(__OperatingRegions.size() != that.__OperatingRegions.size()) return false;
      for (size_t i=0; i<__OperatingRegions.size(); i++)
      {
         if(__OperatingRegions[i] && that.__OperatingRegions[i])
         {
            if(__OperatingRegions[i]->getSeriesNameAsLong() != that.__OperatingRegions[i]->getSeriesNameAsLong()) return false;
            if(__OperatingRegions[i]->getSeriesVersion() != that.__OperatingRegions[i]->getSeriesVersion()) return false;
            if(__OperatingRegions[i]->getLmcpType() != that.__OperatingRegions[i]->getLmcpType()) return false;
            if( *(__OperatingRegions[i]) != *(that.__OperatingRegions[i]) ) return false;
         }
         else if(__OperatingRegions[i] != that.__OperatingRegions[i]) return false;
      }
      return true;

   }

   bool CreateNewService::operator!=(const CreateNewService & that)
   {
      return( !(operator==(that)) );
   }

   CreateNewService& CreateNewService::setServiceID(const int64_t val)
   {
      __ServiceID = val;
      return *this;
   }

   CreateNewService& CreateNewService::setXmlConfiguration(const std::string val)
   {
      __XmlConfiguration = val;
      return *this;
   }











} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

