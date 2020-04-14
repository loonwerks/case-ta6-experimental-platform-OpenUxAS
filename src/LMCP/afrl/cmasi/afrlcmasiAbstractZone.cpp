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
#include "afrl/cmasi/AbstractZone.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AbstractZone::Subscription = "afrl.cmasi.AbstractZone";
   const std::string AbstractZone::TypeName = "AbstractZone";
   const std::string AbstractZone::SeriesName = "CMASI";
   const int64_t AbstractZone::SeriesId = 4849604199710720000LL;
   const uint16_t AbstractZone::SeriesVersion = 3;
   const uint32_t AbstractZone::TypeId = 10;
   
   bool isAbstractZone(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   bool isAbstractZone(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 10) return false;
      return true;
   }
   
   std::vector< std::string > AbstractZoneDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.impact.WaterZone");
       descendants.push_back("afrl.cmasi.KeepInZone");
       descendants.push_back("afrl.cmasi.KeepOutZone");

       return descendants;
   }
   
   AbstractZone::AbstractZone(void) : avtas::lmcp::Object()
   {
      __ZoneID = 0LL;
      __MinAltitude = 0.f;
      __MinAltitudeType = afrl::cmasi::AltitudeType::AGL;
      __MaxAltitude = 0.f;
      __MaxAltitudeType = afrl::cmasi::AltitudeType::MSL;
      __StartTime = 0LL;
      __EndTime = 0LL;
      __Padding = 0.f;
      __Label = std::string("");
      __Boundary = new afrl::cmasi::AbstractGeometry();

   }
     
   AbstractZone::AbstractZone(const AbstractZone &that) : avtas::lmcp::Object(that)
   {
        __ZoneID = that.__ZoneID;
        __MinAltitude = that.__MinAltitude;
        __MinAltitudeType = that.__MinAltitudeType;
        __MaxAltitude = that.__MaxAltitude;
        __MaxAltitudeType = that.__MaxAltitudeType;
        __AffectedAircraft.clear();
        for (size_t i=0; i< that.__AffectedAircraft.size(); i++)
        {
           __AffectedAircraft.push_back( that.__AffectedAircraft[i]);
        }
        __StartTime = that.__StartTime;
        __EndTime = that.__EndTime;
        __Padding = that.__Padding;
        __Label = that.__Label;
        __Boundary = that.__Boundary == nullptr ? nullptr : that.__Boundary->clone();

   }
   
   AbstractZone & AbstractZone::operator=(const AbstractZone &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Boundary != nullptr) delete __Boundary;

         __ZoneID = that.__ZoneID;
         __MinAltitude = that.__MinAltitude;
         __MinAltitudeType = that.__MinAltitudeType;
         __MaxAltitude = that.__MaxAltitude;
         __MaxAltitudeType = that.__MaxAltitudeType;
         __AffectedAircraft.clear();
         for (size_t i=0; i< that.__AffectedAircraft.size(); i++)
         {
            __AffectedAircraft.push_back( that.__AffectedAircraft[i]);
         }
         __StartTime = that.__StartTime;
         __EndTime = that.__EndTime;
         __Padding = that.__Padding;
         __Label = that.__Label;
         __Boundary = that.__Boundary == nullptr ? nullptr : that.__Boundary->clone();

      }
      return *this;
   }

   AbstractZone* AbstractZone::clone() const
   {
        return new AbstractZone(*this);
   }
   
   AbstractZone::~AbstractZone(void)
   {
      if (__Boundary != nullptr) delete __Boundary;

   }
  
   void AbstractZone::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ZoneID);
      buf.putFloat(__MinAltitude);
      buf.putInt( (int32_t) __MinAltitudeType);
      buf.putFloat(__MaxAltitude);
      buf.putInt( (int32_t) __MaxAltitudeType);
      buf.putUShort( static_cast<uint16_t>(__AffectedAircraft.size()));
      for (size_t i=0; i<__AffectedAircraft.size(); i++)
      {
         buf.putLong(__AffectedAircraft[i]);
      }
      buf.putLong(__StartTime);
      buf.putLong(__EndTime);
      buf.putFloat(__Padding);
      buf.putString(__Label);
      assert(__Boundary != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Boundary, buf);

   }
   
   void AbstractZone::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ZoneID = buf.getLong();
      __MinAltitude = buf.getFloat();
      __MinAltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      __MaxAltitude = buf.getFloat();
      __MaxAltitudeType = (afrl::cmasi::AltitudeType::AltitudeType) buf.getInt();
      __AffectedAircraft.clear();
      uint16_t __AffectedAircraft_length = buf.getUShort();
      for (uint32_t i=0; i< __AffectedAircraft_length; i++)
      {
         __AffectedAircraft.push_back(buf.getLong() );
      }
      __StartTime = buf.getLong();
      __EndTime = buf.getLong();
      __Padding = buf.getFloat();
      __Label = buf.getString();
      {
         if (__Boundary != nullptr) delete __Boundary;
         __Boundary = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Boundary = (afrl::cmasi::AbstractGeometry*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Boundary != nullptr) __Boundary->unpack(buf);
            else assert(__Boundary != nullptr);
         }
      }

   }

   uint32_t AbstractZone::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::AltitudeType::AltitudeType);
      size += 2 + sizeof(int64_t) * __AffectedAircraft.size();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += 2 + __Label.length();
      size += (__Boundary != nullptr ? __Boundary->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string AbstractZone::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AbstractZone ) {\n";
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

   std::string AbstractZone::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AbstractZone Series=\"CMASI\">\n";
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
      str << ws << "</AbstractZone>\n";

      return str.str();
   }

   bool AbstractZone::operator==(const AbstractZone & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ZoneID != that.__ZoneID) return false;
      if(__MinAltitude != that.__MinAltitude) return false;
      if(__MinAltitudeType != that.__MinAltitudeType) return false;
      if(__MaxAltitude != that.__MaxAltitude) return false;
      if(__MaxAltitudeType != that.__MaxAltitudeType) return false;
      if(__AffectedAircraft.size() != that.__AffectedAircraft.size()) return false;
      for (size_t i=0; i<__AffectedAircraft.size(); i++)
      {
         if(__AffectedAircraft[i] != that.__AffectedAircraft[i]) return false;
      }
      if(__StartTime != that.__StartTime) return false;
      if(__EndTime != that.__EndTime) return false;
      if(__Padding != that.__Padding) return false;
      if(__Label != that.__Label) return false;
      if(__Boundary && that.__Boundary)
      {
         if(__Boundary->getSeriesNameAsLong() != that.__Boundary->getSeriesNameAsLong()) return false;
         if(__Boundary->getSeriesVersion() != that.__Boundary->getSeriesVersion()) return false;
         if(__Boundary->getLmcpType() != that.__Boundary->getLmcpType()) return false;
         if( *(__Boundary) != *(that.__Boundary) ) return false;
      }
      else if(__Boundary != that.__Boundary) return false;
      return true;

   }

   bool AbstractZone::operator!=(const AbstractZone & that)
   {
      return( !(operator==(that)) );
   }

   AbstractZone& AbstractZone::setZoneID(const int64_t val)
   {
      __ZoneID = val;
      return *this;
   }

   AbstractZone& AbstractZone::setMinAltitude(const float val)
   {
      __MinAltitude = val;
      return *this;
   }

   AbstractZone& AbstractZone::setMinAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __MinAltitudeType = val;
      return *this;
   }

   AbstractZone& AbstractZone::setMaxAltitude(const float val)
   {
      __MaxAltitude = val;
      return *this;
   }

   AbstractZone& AbstractZone::setMaxAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val)
   {
      __MaxAltitudeType = val;
      return *this;
   }


   AbstractZone& AbstractZone::setStartTime(const int64_t val)
   {
      __StartTime = val;
      return *this;
   }

   AbstractZone& AbstractZone::setEndTime(const int64_t val)
   {
      __EndTime = val;
      return *this;
   }

   AbstractZone& AbstractZone::setPadding(const float val)
   {
      __Padding = val;
      return *this;
   }

   AbstractZone& AbstractZone::setLabel(const std::string val)
   {
      __Label = val;
      return *this;
   }

   AbstractZone& AbstractZone::setBoundary(const afrl::cmasi::AbstractGeometry* const val)
   {
      if (__Boundary != nullptr) { delete __Boundary; __Boundary = nullptr; }
      if (val != nullptr) { __Boundary = const_cast< afrl::cmasi::AbstractGeometry* > (val); }
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

