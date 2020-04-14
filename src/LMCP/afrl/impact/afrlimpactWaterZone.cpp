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
#include "afrl/impact/WaterZone.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string WaterZone::Subscription = "afrl.impact.WaterZone";
   const std::string WaterZone::TypeName = "WaterZone";
   const std::string WaterZone::SeriesName = "IMPACT";
   const int64_t WaterZone::SeriesId = 5281966179208134656LL;
   const uint16_t WaterZone::SeriesVersion = 14;
   const uint32_t WaterZone::TypeId = 34;
   
   bool isWaterZone(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 34) return false;
      return true;
   }
   
   bool isWaterZone(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 34) return false;
      return true;
   }
   
   std::vector< std::string > WaterZoneDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   WaterZone::WaterZone(void) : afrl::cmasi::AbstractZone()
   {

   }
     
   WaterZone::WaterZone(const WaterZone &that) : afrl::cmasi::AbstractZone(that)
   {

   }
   
   WaterZone & WaterZone::operator=(const WaterZone &that)
   {
      if (this != &that)
      {
         afrl::cmasi::AbstractZone::operator=(that);


      }
      return *this;
   }

   WaterZone* WaterZone::clone() const
   {
        return new WaterZone(*this);
   }
   
   WaterZone::~WaterZone(void)
   {

   }
  
   void WaterZone::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::AbstractZone::pack(buf);
      // Copy the class into the buffer

   }
   
   void WaterZone::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::AbstractZone::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t WaterZone::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::AbstractZone::calculatePackedSize();

      return size;
   }

   std::string WaterZone::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( WaterZone ) {\n";
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


      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string WaterZone::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<WaterZone Series=\"IMPACT\">\n";
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
      str << ws << "</WaterZone>\n";

      return str.str();
   }

   bool WaterZone::operator==(const WaterZone & that)
   {
      if( afrl::cmasi::AbstractZone::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool WaterZone::operator!=(const WaterZone & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace impact
} // end namespace afrl

