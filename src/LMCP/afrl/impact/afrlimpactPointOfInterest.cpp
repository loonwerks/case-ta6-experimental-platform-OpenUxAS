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
#include "afrl/impact/PointOfInterest.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PointOfInterest::Subscription = "afrl.impact.PointOfInterest";
   const std::string PointOfInterest::TypeName = "PointOfInterest";
   const std::string PointOfInterest::SeriesName = "IMPACT";
   const int64_t PointOfInterest::SeriesId = 5281966179208134656LL;
   const uint16_t PointOfInterest::SeriesVersion = 14;
   const uint32_t PointOfInterest::TypeId = 19;
   
   bool isPointOfInterest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   bool isPointOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 19) return false;
      return true;
   }
   
   std::vector< std::string > PointOfInterestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PointOfInterest::PointOfInterest(void) : avtas::lmcp::Object()
   {
      __PointID = 0LL;
      __Location = new afrl::cmasi::Location3D();
      __PointAction = afrl::impact::AreaActionOptions::Created;
      __PointLabel = std::string("");
      __BackgroundBehaviorPoint = false;

   }
     
   PointOfInterest::PointOfInterest(const PointOfInterest &that) : avtas::lmcp::Object(that)
   {
        __PointID = that.__PointID;
        __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
        __PointAction = that.__PointAction;
        __PointLabel = that.__PointLabel;
        __BackgroundBehaviorPoint = that.__BackgroundBehaviorPoint;

   }
   
   PointOfInterest & PointOfInterest::operator=(const PointOfInterest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Location != nullptr) delete __Location;

         __PointID = that.__PointID;
         __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
         __PointAction = that.__PointAction;
         __PointLabel = that.__PointLabel;
         __BackgroundBehaviorPoint = that.__BackgroundBehaviorPoint;

      }
      return *this;
   }

   PointOfInterest* PointOfInterest::clone() const
   {
        return new PointOfInterest(*this);
   }
   
   PointOfInterest::~PointOfInterest(void)
   {
      if (__Location != nullptr) delete __Location;

   }
  
   void PointOfInterest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__PointID);
      assert(__Location != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Location, buf);
      buf.putInt( (int32_t) __PointAction);
      buf.putString(__PointLabel);
      buf.putBool(__BackgroundBehaviorPoint);

   }
   
   void PointOfInterest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __PointID = buf.getLong();
      {
         if (__Location != nullptr) delete __Location;
         __Location = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Location = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Location != nullptr) __Location->unpack(buf);
            else assert(__Location != nullptr);
         }
      }
      __PointAction = (afrl::impact::AreaActionOptions::AreaActionOptions) buf.getInt();
      __PointLabel = buf.getString();
      __BackgroundBehaviorPoint = buf.getBool();

   }

   uint32_t PointOfInterest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__Location != nullptr ? __Location->calculatePackedSize() + 15 : 1);
      size += sizeof(afrl::impact::AreaActionOptions::AreaActionOptions);
      size += 2 + __PointLabel.length();
      size += sizeof(bool);

      return size;
   }

   std::string PointOfInterest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PointOfInterest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PointID (int64_t) = " << __PointID << "\n";
      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "PointAction (AreaActionOptions) = " << __PointAction << "\n";
      oss << indent << "PointLabel (std::string) = " << __PointLabel << "\n";
      oss << indent << "BackgroundBehaviorPoint (bool) = " << __BackgroundBehaviorPoint << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PointOfInterest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PointOfInterest Series=\"IMPACT\">\n";
      str << ws << "   <PointID>" << __PointID << "</PointID>\n";
      if (__Location != nullptr)
      {
         str << ws << "   <Location>";
         str << "\n" + __Location->toXML(depth + 1) + ws + "   ";
         str << "</Location>\n";
      }
      str << ws << "   <PointAction>" << afrl::impact::AreaActionOptions::get_string(__PointAction) << "</PointAction>\n";
      str << ws << "   <PointLabel>" << __PointLabel << "</PointLabel>\n";
      str << ws << "   <BackgroundBehaviorPoint>" << (__BackgroundBehaviorPoint ? "true" : "false") << "</BackgroundBehaviorPoint>\n";
      str << ws << "</PointOfInterest>\n";

      return str.str();
   }

   bool PointOfInterest::operator==(const PointOfInterest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__PointID != that.__PointID) return false;
      if(__Location && that.__Location)
      {
         if(__Location->getSeriesNameAsLong() != that.__Location->getSeriesNameAsLong()) return false;
         if(__Location->getSeriesVersion() != that.__Location->getSeriesVersion()) return false;
         if(__Location->getLmcpType() != that.__Location->getLmcpType()) return false;
         if( *(__Location) != *(that.__Location) ) return false;
      }
      else if(__Location != that.__Location) return false;
      if(__PointAction != that.__PointAction) return false;
      if(__PointLabel != that.__PointLabel) return false;
      if(__BackgroundBehaviorPoint != that.__BackgroundBehaviorPoint) return false;
      return true;

   }

   bool PointOfInterest::operator!=(const PointOfInterest & that)
   {
      return( !(operator==(that)) );
   }

   PointOfInterest& PointOfInterest::setPointID(const int64_t val)
   {
      __PointID = val;
      return *this;
   }

   PointOfInterest& PointOfInterest::setLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__Location != nullptr) { delete __Location; __Location = nullptr; }
      if (val != nullptr) { __Location = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   PointOfInterest& PointOfInterest::setPointAction(const afrl::impact::AreaActionOptions::AreaActionOptions val)
   {
      __PointAction = val;
      return *this;
   }

   PointOfInterest& PointOfInterest::setPointLabel(const std::string val)
   {
      __PointLabel = val;
      return *this;
   }

   PointOfInterest& PointOfInterest::setBackgroundBehaviorPoint(const bool val)
   {
      __BackgroundBehaviorPoint = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

