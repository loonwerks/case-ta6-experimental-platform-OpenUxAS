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
#include "afrl/impact/RadioTowerConfiguration.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RadioTowerConfiguration::Subscription = "afrl.impact.RadioTowerConfiguration";
   const std::string RadioTowerConfiguration::TypeName = "RadioTowerConfiguration";
   const std::string RadioTowerConfiguration::SeriesName = "IMPACT";
   const int64_t RadioTowerConfiguration::SeriesId = 5281966179208134656LL;
   const uint16_t RadioTowerConfiguration::SeriesVersion = 14;
   const uint32_t RadioTowerConfiguration::TypeId = 3;
   
   bool isRadioTowerConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   bool isRadioTowerConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 3) return false;
      return true;
   }
   
   std::vector< std::string > RadioTowerConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RadioTowerConfiguration::RadioTowerConfiguration(void) : afrl::cmasi::EntityConfiguration()
   {
      __Position = new afrl::cmasi::Location3D();
      __Range = 1500.0f;
      __Enabled = true;

   }
     
   RadioTowerConfiguration::RadioTowerConfiguration(const RadioTowerConfiguration &that) : afrl::cmasi::EntityConfiguration(that)
   {
        __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
        __Range = that.__Range;
        __Enabled = that.__Enabled;

   }
   
   RadioTowerConfiguration & RadioTowerConfiguration::operator=(const RadioTowerConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::EntityConfiguration::operator=(that);
         if (__Position != nullptr) delete __Position;

         __Position = that.__Position == nullptr ? nullptr : that.__Position->clone();
         __Range = that.__Range;
         __Enabled = that.__Enabled;

      }
      return *this;
   }

   RadioTowerConfiguration* RadioTowerConfiguration::clone() const
   {
        return new RadioTowerConfiguration(*this);
   }
   
   RadioTowerConfiguration::~RadioTowerConfiguration(void)
   {
      if (__Position != nullptr) delete __Position;

   }
  
   void RadioTowerConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::EntityConfiguration::pack(buf);
      // Copy the class into the buffer
      assert(__Position != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Position, buf);
      buf.putFloat(__Range);
      buf.putBool(__Enabled);

   }
   
   void RadioTowerConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::EntityConfiguration::unpack(buf);
      // Copy the buffer into the class
      {
         if (__Position != nullptr) delete __Position;
         __Position = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Position = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Position != nullptr) __Position->unpack(buf);
            else assert(__Position != nullptr);
         }
      }
      __Range = buf.getFloat();
      __Enabled = buf.getBool();

   }

   uint32_t RadioTowerConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::EntityConfiguration::calculatePackedSize();
      size += (__Position != nullptr ? __Position->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(bool);

      return size;
   }

   std::string RadioTowerConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RadioTowerConfiguration ) {\n";
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

      oss << indent << "Position (Location3D)";
      if (__Position == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Range (float) = " << __Range << "\n";
      oss << indent << "Enabled (bool) = " << __Enabled << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RadioTowerConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RadioTowerConfiguration Series=\"IMPACT\">\n";
      if (__Position != nullptr)
      {
         str << ws << "   <Position>";
         str << "\n" + __Position->toXML(depth + 1) + ws + "   ";
         str << "</Position>\n";
      }
      str << ws << "   <Range>" << __Range << "</Range>\n";
      str << ws << "   <Enabled>" << (__Enabled ? "true" : "false") << "</Enabled>\n";
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
      str << ws << "</RadioTowerConfiguration>\n";

      return str.str();
   }

   bool RadioTowerConfiguration::operator==(const RadioTowerConfiguration & that)
   {
      if( afrl::cmasi::EntityConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__Position && that.__Position)
      {
         if(__Position->getSeriesNameAsLong() != that.__Position->getSeriesNameAsLong()) return false;
         if(__Position->getSeriesVersion() != that.__Position->getSeriesVersion()) return false;
         if(__Position->getLmcpType() != that.__Position->getLmcpType()) return false;
         if( *(__Position) != *(that.__Position) ) return false;
      }
      else if(__Position != that.__Position) return false;
      if(__Range != that.__Range) return false;
      if(__Enabled != that.__Enabled) return false;
      return true;

   }

   bool RadioTowerConfiguration::operator!=(const RadioTowerConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   RadioTowerConfiguration& RadioTowerConfiguration::setPosition(const afrl::cmasi::Location3D* const val)
   {
      if (__Position != nullptr) { delete __Position; __Position = nullptr; }
      if (val != nullptr) { __Position = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   RadioTowerConfiguration& RadioTowerConfiguration::setRange(const float val)
   {
      __Range = val;
      return *this;
   }

   RadioTowerConfiguration& RadioTowerConfiguration::setEnabled(const bool val)
   {
      __Enabled = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

