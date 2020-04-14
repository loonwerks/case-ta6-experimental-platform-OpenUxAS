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
#include "afrl/cmasi/KeepOutZone.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string KeepOutZone::Subscription = "afrl.cmasi.KeepOutZone";
   const std::string KeepOutZone::TypeName = "KeepOutZone";
   const std::string KeepOutZone::SeriesName = "CMASI";
   const int64_t KeepOutZone::SeriesId = 4849604199710720000LL;
   const uint16_t KeepOutZone::SeriesVersion = 3;
   const uint32_t KeepOutZone::TypeId = 30;
   
   bool isKeepOutZone(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 30) return false;
      return true;
   }
   
   bool isKeepOutZone(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 30) return false;
      return true;
   }
   
   std::vector< std::string > KeepOutZoneDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   KeepOutZone::KeepOutZone(void) : afrl::cmasi::AbstractZone()
   {
      __ZoneType = afrl::cmasi::ZoneAvoidanceType::Physical;

   }
     
   KeepOutZone::KeepOutZone(const KeepOutZone &that) : afrl::cmasi::AbstractZone(that)
   {
        __ZoneType = that.__ZoneType;

   }
   
   KeepOutZone & KeepOutZone::operator=(const KeepOutZone &that)
   {
      if (this != &that)
      {
         afrl::cmasi::AbstractZone::operator=(that);

         __ZoneType = that.__ZoneType;

      }
      return *this;
   }

   KeepOutZone* KeepOutZone::clone() const
   {
        return new KeepOutZone(*this);
   }
   
   KeepOutZone::~KeepOutZone(void)
   {

   }
  
   void KeepOutZone::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::AbstractZone::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __ZoneType);

   }
   
   void KeepOutZone::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::AbstractZone::unpack(buf);
      // Copy the buffer into the class
      __ZoneType = (afrl::cmasi::ZoneAvoidanceType::ZoneAvoidanceType) buf.getInt();

   }

   uint32_t KeepOutZone::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::AbstractZone::calculatePackedSize();
      size += sizeof(afrl::cmasi::ZoneAvoidanceType::ZoneAvoidanceType);

      return size;
   }

   std::string KeepOutZone::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( KeepOutZone ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ZoneID (int64_t) = " << __ZoneID << "\n";
      oss << indent << "MinAltitude (float) = " << __MinAltitude << "\n";
      oss << indent << "MinAltitudeType (AltitudeType) = " << __MinAltitudeType << "\n";
      oss << indent << "MaxAltitude (float) = " << __MaxAltitude << "\n";
      oss << indent << "MaxAltitudeType (AltitudeType) = " << __MaxAltitudeType << "\n";
      oss << indent << "AffectedAircraft (int64 [ " << __AffectedAircraft.size() << ", var ])\n";
      oss << indent << "StartTime (int64_t) = " << __StartTime << "\n";
      oss << indent << "EndTime (int64_t) = " << __EndTime << "\n";
      oss << indent << "Padding (float) = " << __Padding << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "Boundary (AbstractGeometry)";
      if (__Boundary == nullptr)
         oss << " = nullptr";
      oss << "\n";

      oss << indent << "ZoneType (ZoneAvoidanceType) = " << __ZoneType << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string KeepOutZone::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<KeepOutZone Series=\"CMASI\">\n";
      str << ws << "   <ZoneType>" << afrl::cmasi::ZoneAvoidanceType::get_string(__ZoneType) << "</ZoneType>\n";
      str << ws << "   <ZoneID>" << __ZoneID << "</ZoneID>\n";
      str << ws << "   <MinAltitude>" << __MinAltitude << "</MinAltitude>\n";
      str << ws << "   <MinAltitudeType>" << afrl::cmasi::AltitudeType::get_string(__MinAltitudeType) << "</MinAltitudeType>\n";
      str << ws << "   <MaxAltitude>" << __MaxAltitude << "</MaxAltitude>\n";
      str << ws << "   <MaxAltitudeType>" << afrl::cmasi::AltitudeType::get_string(__MaxAltitudeType) << "</MaxAltitudeType>\n";
      str << ws << "   <AffectedAircraft>\n";
      for (size_t i=0; i<__AffectedAircraft.size(); i++)
      {
         str << ws << "   <int64>" << __AffectedAircraft[i] << "</int64>\n";
      }
      str << ws << "   </AffectedAircraft>\n";
      str << ws << "   <StartTime>" << __StartTime << "</StartTime>\n";
      str << ws << "   <EndTime>" << __EndTime << "</EndTime>\n";
      str << ws << "   <Padding>" << __Padding << "</Padding>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      if (__Boundary != nullptr)
      {
         str << ws << "   <Boundary>";
         str << "\n" + __Boundary->toXML(depth + 1) + ws + "   ";
         str << "</Boundary>\n";
      }
      str << ws << "</KeepOutZone>\n";

      return str.str();
   }

   bool KeepOutZone::operator==(const KeepOutZone & that)
   {
      if( afrl::cmasi::AbstractZone::operator!=(that) )
      {
          return false;
      }
      if(__ZoneType != that.__ZoneType) return false;
      return true;

   }

   bool KeepOutZone::operator!=(const KeepOutZone & that)
   {
      return( !(operator==(that)) );
   }

   KeepOutZone& KeepOutZone::setZoneType(const afrl::cmasi::ZoneAvoidanceType::ZoneAvoidanceType val)
   {
      __ZoneType = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

