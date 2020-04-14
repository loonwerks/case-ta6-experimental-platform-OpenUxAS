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
#include "afrl/impact/RadioConfiguration.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RadioConfiguration::Subscription = "afrl.impact.RadioConfiguration";
   const std::string RadioConfiguration::TypeName = "RadioConfiguration";
   const std::string RadioConfiguration::SeriesName = "IMPACT";
   const int64_t RadioConfiguration::SeriesId = 5281966179208134656LL;
   const uint16_t RadioConfiguration::SeriesVersion = 14;
   const uint32_t RadioConfiguration::TypeId = 2;
   
   bool isRadioConfiguration(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isRadioConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > RadioConfigurationDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RadioConfiguration::RadioConfiguration(void) : afrl::cmasi::PayloadConfiguration()
   {
      __Range = 1500.0f;
      __RallyPoint = nullptr;
      __Timeout = 120000LL;

   }
     
   RadioConfiguration::RadioConfiguration(const RadioConfiguration &that) : afrl::cmasi::PayloadConfiguration(that)
   {
        __Range = that.__Range;
        __RallyPoint = that.__RallyPoint == nullptr ? nullptr : that.__RallyPoint->clone();
        __Timeout = that.__Timeout;

   }
   
   RadioConfiguration & RadioConfiguration::operator=(const RadioConfiguration &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadConfiguration::operator=(that);
         if (__RallyPoint != nullptr) delete __RallyPoint;

         __Range = that.__Range;
         __RallyPoint = that.__RallyPoint == nullptr ? nullptr : that.__RallyPoint->clone();
         __Timeout = that.__Timeout;

      }
      return *this;
   }

   RadioConfiguration* RadioConfiguration::clone() const
   {
        return new RadioConfiguration(*this);
   }
   
   RadioConfiguration::~RadioConfiguration(void)
   {
      if (__RallyPoint != nullptr) delete __RallyPoint;

   }
  
   void RadioConfiguration::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadConfiguration::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__Range);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __RallyPoint, buf);
      buf.putLong(__Timeout);

   }
   
   void RadioConfiguration::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadConfiguration::unpack(buf);
      // Copy the buffer into the class
      __Range = buf.getFloat();
      {
         if (__RallyPoint != nullptr) delete __RallyPoint;
         __RallyPoint = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __RallyPoint = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__RallyPoint != nullptr) __RallyPoint->unpack(buf);
         }
      }
      __Timeout = buf.getLong();

   }

   uint32_t RadioConfiguration::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadConfiguration::calculatePackedSize();
      size += sizeof(float);
      size += (__RallyPoint != nullptr ? __RallyPoint->calculatePackedSize() + 15 : 1);
      size += sizeof(int64_t);

      return size;
   }

   std::string RadioConfiguration::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RadioConfiguration ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "PayloadKind (std::string) = " << __PayloadKind << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "Range (float) = " << __Range << "\n";
      oss << indent << "RallyPoint (Location3D)";
      if (__RallyPoint == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Timeout (int64_t) = " << __Timeout << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RadioConfiguration::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RadioConfiguration Series=\"IMPACT\">\n";
      str << ws << "   <Range>" << __Range << "</Range>\n";
      if (__RallyPoint != nullptr)
      {
         str << ws << "   <RallyPoint>";
         str << "\n" + __RallyPoint->toXML(depth + 1) + ws + "   ";
         str << "</RallyPoint>\n";
      }
      str << ws << "   <Timeout>" << __Timeout << "</Timeout>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <PayloadKind>" << __PayloadKind << "</PayloadKind>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</RadioConfiguration>\n";

      return str.str();
   }

   bool RadioConfiguration::operator==(const RadioConfiguration & that)
   {
      if( afrl::cmasi::PayloadConfiguration::operator!=(that) )
      {
          return false;
      }
      if(__Range != that.__Range) return false;
      if(__RallyPoint && that.__RallyPoint)
      {
         if(__RallyPoint->getSeriesNameAsLong() != that.__RallyPoint->getSeriesNameAsLong()) return false;
         if(__RallyPoint->getSeriesVersion() != that.__RallyPoint->getSeriesVersion()) return false;
         if(__RallyPoint->getLmcpType() != that.__RallyPoint->getLmcpType()) return false;
         if( *(__RallyPoint) != *(that.__RallyPoint) ) return false;
      }
      else if(__RallyPoint != that.__RallyPoint) return false;
      if(__Timeout != that.__Timeout) return false;
      return true;

   }

   bool RadioConfiguration::operator!=(const RadioConfiguration & that)
   {
      return( !(operator==(that)) );
   }

   RadioConfiguration& RadioConfiguration::setRange(const float val)
   {
      __Range = val;
      return *this;
   }

   RadioConfiguration& RadioConfiguration::setRallyPoint(const afrl::cmasi::Location3D* const val)
   {
      if (__RallyPoint != nullptr) { delete __RallyPoint; __RallyPoint = nullptr; }
      if (val != nullptr) { __RallyPoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   RadioConfiguration& RadioConfiguration::setTimeout(const int64_t val)
   {
      __Timeout = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

