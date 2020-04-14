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
#include "afrl/cmasi/CameraConfiguration.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CameraConfiguration::Subscription = "afrl.cmasi.CameraConfiguration";
   const std::string CameraConfiguration::TypeName = "CameraConfiguration";
   const std::string CameraConfiguration::SeriesName = "CMASI";
   const int64_t CameraConfiguration::SeriesId = 4849604199710720000LL;
   const uint16_t CameraConfiguration::SeriesVersion = 3;
   const uint32_t CameraConfiguration::TypeId = 19;
   
   bool isCameraConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   bool isCameraConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   std::vector< std::string > CameraConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CameraConfiguration::CameraConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {
      __SupportedWavelengthBand = afrl::cmasi::WavelengthBand::EO;
      __FieldOfViewMode = afrl::cmasi::FOVOperationMode::Continuous;
      __MinHorizontalFieldOfView = 0.f;
      __MaxHorizontalFieldOfView = 0.f;
      __VideoStreamHorizontalResolution = 0;
      __VideoStreamVerticalResolution = 0;

   }
     
   CameraConfiguration::CameraConfiguration(const CameraConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __SupportedWavelengthBand = that.__SupportedWavelengthBand;
        __FieldOfViewMode = that.__FieldOfViewMode;
        __MinHorizontalFieldOfView = that.__MinHorizontalFieldOfView;
        __MaxHorizontalFieldOfView = that.__MaxHorizontalFieldOfView;
        __DiscreteHorizontalFieldOfViewList.clear();
        for (size_t i=0; i< that.__DiscreteHorizontalFieldOfViewList.size(); i++)
        {
           __DiscreteHorizontalFieldOfViewList.push_back( that.__DiscreteHorizontalFieldOfViewList[i]);
        }
        __VideoStreamHorizontalResolution = that.__VideoStreamHorizontalResolution;
        __VideoStreamVerticalResolution = that.__VideoStreamVerticalResolution;

   }
   
   CameraConfiguration & CameraConfiguration::operator=(const CameraConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);

         __SupportedWavelengthBand = that.__SupportedWavelengthBand;
         __FieldOfViewMode = that.__FieldOfViewMode;
         __MinHorizontalFieldOfView = that.__MinHorizontalFieldOfView;
         __MaxHorizontalFieldOfView = that.__MaxHorizontalFieldOfView;
         __DiscreteHorizontalFieldOfViewList.clear();
         for (size_t i=0; i< that.__DiscreteHorizontalFieldOfViewList.size(); i++)
         {
            __DiscreteHorizontalFieldOfViewList.push_back( that.__DiscreteHorizontalFieldOfViewList[i]);
         }
         __VideoStreamHorizontalResolution = that.__VideoStreamHorizontalResolution;
         __VideoStreamVerticalResolution = that.__VideoStreamVerticalResolution;

      }
      return *this;
   }

   CameraConfiguration* CameraConfiguration::clone() const
   {
        return new CameraConfiguration(*this);
   }
   
   CameraConfiguration::~CameraConfiguration(void)
   {

   }
  
   void CameraConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __SupportedWavelengthBand);
      buf.putInt( (int32_t) __FieldOfViewMode);
      buf.putFloat(__MinHorizontalFieldOfView);
      buf.putFloat(__MaxHorizontalFieldOfView);
      buf.putUShort( static_cast<uint16_t>(__DiscreteHorizontalFieldOfViewList.size()));
      for (size_t i=0; i<__DiscreteHorizontalFieldOfViewList.size(); i++)
      {
         buf.putFloat(__DiscreteHorizontalFieldOfViewList[i]);
      }
      buf.putUInt(__VideoStreamHorizontalResolution);
      buf.putUInt(__VideoStreamVerticalResolution);

   }
   
   void CameraConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __SupportedWavelengthBand = (afrl::cmasi::WavelengthBand::WavelengthBand) buf.getInt();
      __FieldOfViewMode = (afrl::cmasi::FOVOperationMode::FOVOperationMode) buf.getInt();
      __MinHorizontalFieldOfView = buf.getFloat();
      __MaxHorizontalFieldOfView = buf.getFloat();
      __DiscreteHorizontalFieldOfViewList.clear();
      uint16_t __DiscreteHorizontalFieldOfViewList_length = buf.getUShort();
      for (uint32_t i=0; i< __DiscreteHorizontalFieldOfViewList_length; i++)
      {
         __DiscreteHorizontalFieldOfViewList.push_back(buf.getFloat() );
      }
      __VideoStreamHorizontalResolution = buf.getUInt();
      __VideoStreamVerticalResolution = buf.getUInt();

   }

   uint32_t CameraConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += sizeof(afrl::cmasi::WavelengthBand::WavelengthBand);
      size += sizeof(afrl::cmasi::FOVOperationMode::FOVOperationMode);
      size += sizeof(float);
      size += sizeof(float);
      size += 2 + sizeof(float) * __DiscreteHorizontalFieldOfViewList.size();
      size += sizeof(uint32_t);
      size += sizeof(uint32_t);

      return size;
   }

   std::string CameraConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CameraConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "SupportedWavelengthBand (WavelengthBand) = " << __SupportedWavelengthBand << "\n";
      oss << indent << "FieldOfViewMode (FOVOperationMode) = " << __FieldOfViewMode << "\n";
      oss << indent << "MinHorizontalFieldOfView (float) = " << __MinHorizontalFieldOfView << "\n";
      oss << indent << "MaxHorizontalFieldOfView (float) = " << __MaxHorizontalFieldOfView << "\n";
      oss << indent << "DiscreteHorizontalFieldOfViewList (real32 [ " << __DiscreteHorizontalFieldOfViewList.size() << ", var ])\n";
      oss << indent << "VideoStreamHorizontalResolution (uint32_t) = " << __VideoStreamHorizontalResolution << "\n";
      oss << indent << "VideoStreamVerticalResolution (uint32_t) = " << __VideoStreamVerticalResolution << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CameraConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CameraConfiguration Series=\"CMASI\">\n";
      str << ws << "   <SupportedWavelengthBand>" << afrl::cmasi::WavelengthBand::get_string(__SupportedWavelengthBand) << "</SupportedWavelengthBand>\n";
      str << ws << "   <FieldOfViewMode>" << afrl::cmasi::FOVOperationMode::get_string(__FieldOfViewMode) << "</FieldOfViewMode>\n";
      str << ws << "   <MinHorizontalFieldOfView>" << __MinHorizontalFieldOfView << "</MinHorizontalFieldOfView>\n";
      str << ws << "   <MaxHorizontalFieldOfView>" << __MaxHorizontalFieldOfView << "</MaxHorizontalFieldOfView>\n";
      str << ws << "   <DiscreteHorizontalFieldOfViewList>\n";
      for (size_t i=0; i<__DiscreteHorizontalFieldOfViewList.size(); i++)
      {
         str << ws << "   <real32>" << __DiscreteHorizontalFieldOfViewList[i] << "</real32>\n";
      }
      str << ws << "   </DiscreteHorizontalFieldOfViewList>\n";
      str << ws << "   <VideoStreamHorizontalResolution>" << __VideoStreamHorizontalResolution << "</VideoStreamHorizontalResolution>\n";
      str << ws << "   <VideoStreamVerticalResolution>" << __VideoStreamVerticalResolution << "</VideoStreamVerticalResolution>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</CameraConfiguration>\n";

      return str.str();
   }

   bool CameraConfiguration::operator==(const CameraConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__SupportedWavelengthBand != that.__SupportedWavelengthBand) return false;
      if(__FieldOfViewMode != that.__FieldOfViewMode) return false;
      if(__MinHorizontalFieldOfView != that.__MinHorizontalFieldOfView) return false;
      if(__MaxHorizontalFieldOfView != that.__MaxHorizontalFieldOfView) return false;
      if(__DiscreteHorizontalFieldOfViewList.size() != that.__DiscreteHorizontalFieldOfViewList.size()) return false;
      for (size_t i=0; i<__DiscreteHorizontalFieldOfViewList.size(); i++)
      {
         if(__DiscreteHorizontalFieldOfViewList[i] != that.__DiscreteHorizontalFieldOfViewList[i]) return false;
      }
      if(__VideoStreamHorizontalResolution != that.__VideoStreamHorizontalResolution) return false;
      if(__VideoStreamVerticalResolution != that.__VideoStreamVerticalResolution) return false;
      return true;

   }

   bool CameraConfiguration::operator!=(const CameraConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   CameraConfiguration& CameraConfiguration::setSupportedWavelengthBand(const afrl::cmasi::WavelengthBand::WavelengthBand val)
   {
      __SupportedWavelengthBand = val;
      return *this;
   }

   CameraConfiguration& CameraConfiguration::setFieldOfViewMode(const afrl::cmasi::FOVOperationMode::FOVOperationMode val)
   {
      __FieldOfViewMode = val;
      return *this;
   }

   CameraConfiguration& CameraConfiguration::setMinHorizontalFieldOfView(const float val)
   {
      __MinHorizontalFieldOfView = val;
      return *this;
   }

   CameraConfiguration& CameraConfiguration::setMaxHorizontalFieldOfView(const float val)
   {
      __MaxHorizontalFieldOfView = val;
      return *this;
   }


   CameraConfiguration& CameraConfiguration::setVideoStreamHorizontalResolution(const uint32_t val)
   {
      __VideoStreamHorizontalResolution = val;
      return *this;
   }

   CameraConfiguration& CameraConfiguration::setVideoStreamVerticalResolution(const uint32_t val)
   {
      __VideoStreamVerticalResolution = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

