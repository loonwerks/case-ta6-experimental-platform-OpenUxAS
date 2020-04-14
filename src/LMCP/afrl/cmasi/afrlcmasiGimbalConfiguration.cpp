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
#include "afrl/cmasi/GimbalConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GimbalConfiguration::Subscription = "afrl.cmasi.GimbalConfiguration";
   const std::string GimbalConfiguration::TypeName = "GimbalConfiguration";
   const std::string GimbalConfiguration::SeriesName = "CMASI";
   const int64_t GimbalConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t GimbalConfiguration::SeriesVersion = 3;
   const uint32_t GimbalConfiguration::TypeId = 24;
   
   bool isGimbalConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   bool isGimbalConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 24) return false;
      return true;
   }
   
   std::vector< std::string > GimbalConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GimbalConfiguration::GimbalConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {
      __MinAzimuth = -180.f;
      __MaxAzimuth = 180.f;
      __IsAzimuthClamped = false;
      __MinElevation = -180.f;
      __MaxElevation = 180.f;
      __IsElevationClamped = false;
      __MinRotation = 0.f;
      __MaxRotation = 0.f;
      __IsRotationClamped = true;
      __MaxAzimuthSlewRate = 0.f;
      __MaxElevationSlewRate = 0.f;
      __MaxRotationRate = 0.f;

   }
     
   GimbalConfiguration::GimbalConfiguration(const GimbalConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __SupportedPointingModes.clear();
        for (size_t i=0; i< that.__SupportedPointingModes.size(); i++)
        {
           __SupportedPointingModes.push_back( that.__SupportedPointingModes[i]);
        }
        __MinAzimuth = that.__MinAzimuth;
        __MaxAzimuth = that.__MaxAzimuth;
        __IsAzimuthClamped = that.__IsAzimuthClamped;
        __MinElevation = that.__MinElevation;
        __MaxElevation = that.__MaxElevation;
        __IsElevationClamped = that.__IsElevationClamped;
        __MinRotation = that.__MinRotation;
        __MaxRotation = that.__MaxRotation;
        __IsRotationClamped = that.__IsRotationClamped;
        __MaxAzimuthSlewRate = that.__MaxAzimuthSlewRate;
        __MaxElevationSlewRate = that.__MaxElevationSlewRate;
        __MaxRotationRate = that.__MaxRotationRate;
        __ContainedPayloadList.clear();
        for (size_t i=0; i< that.__ContainedPayloadList.size(); i++)
        {
           __ContainedPayloadList.push_back( that.__ContainedPayloadList[i]);
        }

   }
   
   GimbalConfiguration & GimbalConfiguration::operator=(const GimbalConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);

         __SupportedPointingModes.clear();
         for (size_t i=0; i< that.__SupportedPointingModes.size(); i++)
         {
            __SupportedPointingModes.push_back( that.__SupportedPointingModes[i]);
         }
         __MinAzimuth = that.__MinAzimuth;
         __MaxAzimuth = that.__MaxAzimuth;
         __IsAzimuthClamped = that.__IsAzimuthClamped;
         __MinElevation = that.__MinElevation;
         __MaxElevation = that.__MaxElevation;
         __IsElevationClamped = that.__IsElevationClamped;
         __MinRotation = that.__MinRotation;
         __MaxRotation = that.__MaxRotation;
         __IsRotationClamped = that.__IsRotationClamped;
         __MaxAzimuthSlewRate = that.__MaxAzimuthSlewRate;
         __MaxElevationSlewRate = that.__MaxElevationSlewRate;
         __MaxRotationRate = that.__MaxRotationRate;
         __ContainedPayloadList.clear();
         for (size_t i=0; i< that.__ContainedPayloadList.size(); i++)
         {
            __ContainedPayloadList.push_back( that.__ContainedPayloadList[i]);
         }

      }
      return *this;
   }

   GimbalConfiguration* GimbalConfiguration::clone() const
   {
        return new GimbalConfiguration(*this);
   }
   
   GimbalConfiguration::~GimbalConfiguration(void)
   {

   }
  
   void GimbalConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__SupportedPointingModes.size()));
      for (size_t i=0; i<__SupportedPointingModes.size(); i++)
      {
         buf.putInt( (int32_t) __SupportedPointingModes[i]);
      }
      buf.putFloat(__MinAzimuth);
      buf.putFloat(__MaxAzimuth);
      buf.putBool(__IsAzimuthClamped);
      buf.putFloat(__MinElevation);
      buf.putFloat(__MaxElevation);
      buf.putBool(__IsElevationClamped);
      buf.putFloat(__MinRotation);
      buf.putFloat(__MaxRotation);
      buf.putBool(__IsRotationClamped);
      buf.putFloat(__MaxAzimuthSlewRate);
      buf.putFloat(__MaxElevationSlewRate);
      buf.putFloat(__MaxRotationRate);
      buf.putUShort( static_cast<uint16_t>(__ContainedPayloadList.size()));
      for (size_t i=0; i<__ContainedPayloadList.size(); i++)
      {
         buf.putLong(__ContainedPayloadList[i]);
      }

   }
   
   void GimbalConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __SupportedPointingModes.clear();
      uint16_t __SupportedPointingModes_length = buf.getUShort();
      for (uint32_t i=0; i< __SupportedPointingModes_length; i++)
      {
         __SupportedPointingModes.push_back( (afrl::cmasi::GimbalPointingMode::GimbalPointingMode) buf.getInt() );
      }
      __MinAzimuth = buf.getFloat();
      __MaxAzimuth = buf.getFloat();
      __IsAzimuthClamped = buf.getBool();
      __MinElevation = buf.getFloat();
      __MaxElevation = buf.getFloat();
      __IsElevationClamped = buf.getBool();
      __MinRotation = buf.getFloat();
      __MaxRotation = buf.getFloat();
      __IsRotationClamped = buf.getBool();
      __MaxAzimuthSlewRate = buf.getFloat();
      __MaxElevationSlewRate = buf.getFloat();
      __MaxRotationRate = buf.getFloat();
      __ContainedPayloadList.clear();
      uint16_t __ContainedPayloadList_length = buf.getUShort();
      for (uint32_t i=0; i< __ContainedPayloadList_length; i++)
      {
         __ContainedPayloadList.push_back(buf.getLong() );
      }

   }

   uint32_t GimbalConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += 2 + sizeof(afrl::cmasi::GimbalPointingMode::GimbalPointingMode) * __SupportedPointingModes.size();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(bool);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(bool);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(bool);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += 2 + sizeof(int64_t) * __ContainedPayloadList.size();

      return size;
   }

   std::string GimbalConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GimbalConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "SupportedPointingModes (GimbalPointingMode [ " << __SupportedPointingModes.size() << ", var ])\n";
      oss << indent << "MinAzimuth (float) = " << __MinAzimuth << "\n";
      oss << indent << "MaxAzimuth (float) = " << __MaxAzimuth << "\n";
      oss << indent << "IsAzimuthClamped (bool) = " << __IsAzimuthClamped << "\n";
      oss << indent << "MinElevation (float) = " << __MinElevation << "\n";
      oss << indent << "MaxElevation (float) = " << __MaxElevation << "\n";
      oss << indent << "IsElevationClamped (bool) = " << __IsElevationClamped << "\n";
      oss << indent << "MinRotation (float) = " << __MinRotation << "\n";
      oss << indent << "MaxRotation (float) = " << __MaxRotation << "\n";
      oss << indent << "IsRotationClamped (bool) = " << __IsRotationClamped << "\n";
      oss << indent << "MaxAzimuthSlewRate (float) = " << __MaxAzimuthSlewRate << "\n";
      oss << indent << "MaxElevationSlewRate (float) = " << __MaxElevationSlewRate << "\n";
      oss << indent << "MaxRotationRate (float) = " << __MaxRotationRate << "\n";
      oss << indent << "ContainedPayloadList (int64 [ " << __ContainedPayloadList.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GimbalConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GimbalConfiguration Series=\"CMASI\">\n";
      str << ws << "   <SupportedPointingModes>\n";
      for (size_t i=0; i<__SupportedPointingModes.size(); i++)
      {
         str << ws << "   <GimbalPointingMode>" << afrl::cmasi::GimbalPointingMode::get_string(__SupportedPointingModes[i]) << "</GimbalPointingMode>\n";
      }
      str << ws << "   </SupportedPointingModes>\n";
      str << ws << "   <MinAzimuth>" << __MinAzimuth << "</MinAzimuth>\n";
      str << ws << "   <MaxAzimuth>" << __MaxAzimuth << "</MaxAzimuth>\n";
      str << ws << "   <IsAzimuthClamped>" << (__IsAzimuthClamped ? "true" : "false") << "</IsAzimuthClamped>\n";
      str << ws << "   <MinElevation>" << __MinElevation << "</MinElevation>\n";
      str << ws << "   <MaxElevation>" << __MaxElevation << "</MaxElevation>\n";
      str << ws << "   <IsElevationClamped>" << (__IsElevationClamped ? "true" : "false") << "</IsElevationClamped>\n";
      str << ws << "   <MinRotation>" << __MinRotation << "</MinRotation>\n";
      str << ws << "   <MaxRotation>" << __MaxRotation << "</MaxRotation>\n";
      str << ws << "   <IsRotationClamped>" << (__IsRotationClamped ? "true" : "false") << "</IsRotationClamped>\n";
      str << ws << "   <MaxAzimuthSlewRate>" << __MaxAzimuthSlewRate << "</MaxAzimuthSlewRate>\n";
      str << ws << "   <MaxElevationSlewRate>" << __MaxElevationSlewRate << "</MaxElevationSlewRate>\n";
      str << ws << "   <MaxRotationRate>" << __MaxRotationRate << "</MaxRotationRate>\n";
      str << ws << "   <ContainedPayloadList>\n";
      for (size_t i=0; i<__ContainedPayloadList.size(); i++)
      {
         str << ws << "   <int64>" << __ContainedPayloadList[i] << "</int64>\n";
      }
      str << ws << "   </ContainedPayloadList>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</GimbalConfiguration>\n";

      return str.str();
   }

   bool GimbalConfiguration::operator==(const GimbalConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__SupportedPointingModes.size() != that.__SupportedPointingModes.size()) return false;
      for (size_t i=0; i<__SupportedPointingModes.size(); i++)
      {
         if(__SupportedPointingModes[i] != that.__SupportedPointingModes[i]) return false;
      }
      if(__MinAzimuth != that.__MinAzimuth) return false;
      if(__MaxAzimuth != that.__MaxAzimuth) return false;
      if(__IsAzimuthClamped != that.__IsAzimuthClamped) return false;
      if(__MinElevation != that.__MinElevation) return false;
      if(__MaxElevation != that.__MaxElevation) return false;
      if(__IsElevationClamped != that.__IsElevationClamped) return false;
      if(__MinRotation != that.__MinRotation) return false;
      if(__MaxRotation != that.__MaxRotation) return false;
      if(__IsRotationClamped != that.__IsRotationClamped) return false;
      if(__MaxAzimuthSlewRate != that.__MaxAzimuthSlewRate) return false;
      if(__MaxElevationSlewRate != that.__MaxElevationSlewRate) return false;
      if(__MaxRotationRate != that.__MaxRotationRate) return false;
      if(__ContainedPayloadList.size() != that.__ContainedPayloadList.size()) return false;
      for (size_t i=0; i<__ContainedPayloadList.size(); i++)
      {
         if(__ContainedPayloadList[i] != that.__ContainedPayloadList[i]) return false;
      }
      return true;

   }

   bool GimbalConfiguration::operator!=(const GimbalConfiguration & that)
   {
      return( !(operator==(that)) );
   }


   GimbalConfiguration& GimbalConfiguration::setMinAzimuth(const float val)
   {
      __MinAzimuth = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxAzimuth(const float val)
   {
      __MaxAzimuth = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setIsAzimuthClamped(const bool val)
   {
      __IsAzimuthClamped = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMinElevation(const float val)
   {
      __MinElevation = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxElevation(const float val)
   {
      __MaxElevation = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setIsElevationClamped(const bool val)
   {
      __IsElevationClamped = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMinRotation(const float val)
   {
      __MinRotation = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxRotation(const float val)
   {
      __MaxRotation = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setIsRotationClamped(const bool val)
   {
      __IsRotationClamped = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxAzimuthSlewRate(const float val)
   {
      __MaxAzimuthSlewRate = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxElevationSlewRate(const float val)
   {
      __MaxElevationSlewRate = val;
      return *this;
   }

   GimbalConfiguration& GimbalConfiguration::setMaxRotationRate(const float val)
   {
      __MaxRotationRate = val;
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

