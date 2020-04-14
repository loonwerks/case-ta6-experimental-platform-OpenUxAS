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
#include "afrl/cmasi/GimbalScanAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GimbalScanAction::Subscription = "afrl.cmasi.GimbalScanAction";
   const std::string GimbalScanAction::TypeName = "GimbalScanAction";
   const std::string GimbalScanAction::SeriesName = "CMASI";
   const int64_t GimbalScanAction::SeriesId = 4849604199710720000LL;
   const uint16_t GimbalScanAction::SeriesVersion = 3;
   const uint32_t GimbalScanAction::TypeId = 25;
   
   bool isGimbalScanAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   bool isGimbalScanAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 25) return false;
      return true;
   }
   
   std::vector< std::string > GimbalScanActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GimbalScanAction::GimbalScanAction(void) : afrl::cmasi::PayloadAction()
   {
      __AzimuthSlewRate = 0.f;
      __ElevationSlewRate = 0.f;
      __StartAzimuth = 0.f;
      __EndAzimuth = 0.f;
      __StartElevation = 0.f;
      __EndElevation = 0.f;
      __Cycles = 0;

   }
     
   GimbalScanAction::GimbalScanAction(const GimbalScanAction &that) : afrl::cmasi::PayloadAction(that)
   {
        __AzimuthSlewRate = that.__AzimuthSlewRate;
        __ElevationSlewRate = that.__ElevationSlewRate;
        __StartAzimuth = that.__StartAzimuth;
        __EndAzimuth = that.__EndAzimuth;
        __StartElevation = that.__StartElevation;
        __EndElevation = that.__EndElevation;
        __Cycles = that.__Cycles;

   }
   
   GimbalScanAction & GimbalScanAction::operator=(const GimbalScanAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadAction::operator=(that);

         __AzimuthSlewRate = that.__AzimuthSlewRate;
         __ElevationSlewRate = that.__ElevationSlewRate;
         __StartAzimuth = that.__StartAzimuth;
         __EndAzimuth = that.__EndAzimuth;
         __StartElevation = that.__StartElevation;
         __EndElevation = that.__EndElevation;
         __Cycles = that.__Cycles;

      }
      return *this;
   }

   GimbalScanAction* GimbalScanAction::clone() const
   {
        return new GimbalScanAction(*this);
   }
   
   GimbalScanAction::~GimbalScanAction(void)
   {

   }
  
   void GimbalScanAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadAction::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__AzimuthSlewRate);
      buf.putFloat(__ElevationSlewRate);
      buf.putFloat(__StartAzimuth);
      buf.putFloat(__EndAzimuth);
      buf.putFloat(__StartElevation);
      buf.putFloat(__EndElevation);
      buf.putUInt(__Cycles);

   }
   
   void GimbalScanAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadAction::unpack(buf);
      // Copy the buffer into the class
      __AzimuthSlewRate = buf.getFloat();
      __ElevationSlewRate = buf.getFloat();
      __StartAzimuth = buf.getFloat();
      __EndAzimuth = buf.getFloat();
      __StartElevation = buf.getFloat();
      __EndElevation = buf.getFloat();
      __Cycles = buf.getUInt();

   }

   uint32_t GimbalScanAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadAction::calculatePackedSize();
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(uint32_t);

      return size;
   }

   std::string GimbalScanAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GimbalScanAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      oss << indent << "AzimuthSlewRate (float) = " << __AzimuthSlewRate << "\n";
      oss << indent << "ElevationSlewRate (float) = " << __ElevationSlewRate << "\n";
      oss << indent << "StartAzimuth (float) = " << __StartAzimuth << "\n";
      oss << indent << "EndAzimuth (float) = " << __EndAzimuth << "\n";
      oss << indent << "StartElevation (float) = " << __StartElevation << "\n";
      oss << indent << "EndElevation (float) = " << __EndElevation << "\n";
      oss << indent << "Cycles (uint32_t) = " << __Cycles << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GimbalScanAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GimbalScanAction Series=\"CMASI\">\n";
      str << ws << "   <AzimuthSlewRate>" << __AzimuthSlewRate << "</AzimuthSlewRate>\n";
      str << ws << "   <ElevationSlewRate>" << __ElevationSlewRate << "</ElevationSlewRate>\n";
      str << ws << "   <StartAzimuth>" << __StartAzimuth << "</StartAzimuth>\n";
      str << ws << "   <EndAzimuth>" << __EndAzimuth << "</EndAzimuth>\n";
      str << ws << "   <StartElevation>" << __StartElevation << "</StartElevation>\n";
      str << ws << "   <EndElevation>" << __EndElevation << "</EndElevation>\n";
      str << ws << "   <Cycles>" << __Cycles << "</Cycles>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</GimbalScanAction>\n";

      return str.str();
   }

   bool GimbalScanAction::operator==(const GimbalScanAction & that)
   {
      if( afrl::cmasi::PayloadAction::operator!=(that) )
      {
          return false;
      }
      if(__AzimuthSlewRate != that.__AzimuthSlewRate) return false;
      if(__ElevationSlewRate != that.__ElevationSlewRate) return false;
      if(__StartAzimuth != that.__StartAzimuth) return false;
      if(__EndAzimuth != that.__EndAzimuth) return false;
      if(__StartElevation != that.__StartElevation) return false;
      if(__EndElevation != that.__EndElevation) return false;
      if(__Cycles != that.__Cycles) return false;
      return true;

   }

   bool GimbalScanAction::operator!=(const GimbalScanAction & that)
   {
      return( !(operator==(that)) );
   }

   GimbalScanAction& GimbalScanAction::setAzimuthSlewRate(const float val)
   {
      __AzimuthSlewRate = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setElevationSlewRate(const float val)
   {
      __ElevationSlewRate = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setStartAzimuth(const float val)
   {
      __StartAzimuth = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setEndAzimuth(const float val)
   {
      __EndAzimuth = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setStartElevation(const float val)
   {
      __StartElevation = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setEndElevation(const float val)
   {
      __EndElevation = val;
      return *this;
   }

   GimbalScanAction& GimbalScanAction::setCycles(const uint32_t val)
   {
      __Cycles = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

