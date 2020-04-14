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
#include "afrl/impact/AreaOfInterest.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AreaOfInterest::Subscription = "afrl.impact.AreaOfInterest";
   const std::string AreaOfInterest::TypeName = "AreaOfInterest";
   const std::string AreaOfInterest::SeriesName = "IMPACT";
   const int64_t AreaOfInterest::SeriesId = 5281966179208134656LL;
   const uint16_t AreaOfInterest::SeriesVersion = 14;
   const uint32_t AreaOfInterest::TypeId = 21;
   
   bool isAreaOfInterest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   bool isAreaOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 21) return false;
      return true;
   }
   
   std::vector< std::string > AreaOfInterestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AreaOfInterest::AreaOfInterest(void) : avtas::lmcp::Object()
   {
      __AreaID = 0LL;
      __Area = new afrl::cmasi::AbstractGeometry();
      __AreaAction = afrl::impact::AreaActionOptions::Created;
      __AreaLabel = std::string("");
      __BackgroundBehaviorArea = false;

   }
     
   AreaOfInterest::AreaOfInterest(const AreaOfInterest &that) : avtas::lmcp::Object(that)
   {
        __AreaID = that.__AreaID;
        __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
        __AreaAction = that.__AreaAction;
        __AreaLabel = that.__AreaLabel;
        __BackgroundBehaviorArea = that.__BackgroundBehaviorArea;

   }
   
   AreaOfInterest & AreaOfInterest::operator=(const AreaOfInterest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Area != nullptr) delete __Area;

         __AreaID = that.__AreaID;
         __Area = that.__Area == nullptr ? nullptr : that.__Area->clone();
         __AreaAction = that.__AreaAction;
         __AreaLabel = that.__AreaLabel;
         __BackgroundBehaviorArea = that.__BackgroundBehaviorArea;

      }
      return *this;
   }

   AreaOfInterest* AreaOfInterest::clone() const
   {
        return new AreaOfInterest(*this);
   }
   
   AreaOfInterest::~AreaOfInterest(void)
   {
      if (__Area != nullptr) delete __Area;

   }
  
   void AreaOfInterest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__AreaID);
      assert(__Area != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Area, buf);
      buf.putInt( (int32_t) __AreaAction);
      buf.putString(__AreaLabel);
      buf.putBool(__BackgroundBehaviorArea);

   }
   
   void AreaOfInterest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __AreaID = buf.getLong();
      {
         if (__Area != nullptr) delete __Area;
         __Area = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Area = (afrl::cmasi::AbstractGeometry*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Area != nullptr) __Area->unpack(buf);
            else assert(__Area != nullptr);
         }
      }
      __AreaAction = (afrl::impact::AreaActionOptions::AreaActionOptions) buf.getInt();
      __AreaLabel = buf.getString();
      __BackgroundBehaviorArea = buf.getBool();

   }

   uint32_t AreaOfInterest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += (__Area != nullptr ? __Area->calculatePackedSize() + 15 : 1);
      size += sizeof(afrl::impact::AreaActionOptions::AreaActionOptions);
      size += 2 + __AreaLabel.length();
      size += sizeof(bool);

      return size;
   }

   std::string AreaOfInterest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AreaOfInterest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AreaID (int64_t) = " << __AreaID << "\n";
      oss << indent << "Area (AbstractGeometry)";
      if (__Area == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "AreaAction (AreaActionOptions) = " << __AreaAction << "\n";
      oss << indent << "AreaLabel (std::string) = " << __AreaLabel << "\n";
      oss << indent << "BackgroundBehaviorArea (bool) = " << __BackgroundBehaviorArea << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AreaOfInterest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AreaOfInterest Series=\"IMPACT\">\n";
      str << ws << "   <AreaID>" << __AreaID << "</AreaID>\n";
      if (__Area != nullptr)
      {
         str << ws << "   <Area>";
         str << "\n" + __Area->toXML(depth + 1) + ws + "   ";
         str << "</Area>\n";
      }
      str << ws << "   <AreaAction>" << afrl::impact::AreaActionOptions::get_string(__AreaAction) << "</AreaAction>\n";
      str << ws << "   <AreaLabel>" << __AreaLabel << "</AreaLabel>\n";
      str << ws << "   <BackgroundBehaviorArea>" << (__BackgroundBehaviorArea ? "true" : "false") << "</BackgroundBehaviorArea>\n";
      str << ws << "</AreaOfInterest>\n";

      return str.str();
   }

   bool AreaOfInterest::operator==(const AreaOfInterest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__AreaID != that.__AreaID) return false;
      if(__Area && that.__Area)
      {
         if(__Area->getSeriesNameAsLong() != that.__Area->getSeriesNameAsLong()) return false;
         if(__Area->getSeriesVersion() != that.__Area->getSeriesVersion()) return false;
         if(__Area->getLmcpType() != that.__Area->getLmcpType()) return false;
         if( *(__Area) != *(that.__Area) ) return false;
      }
      else if(__Area != that.__Area) return false;
      if(__AreaAction != that.__AreaAction) return false;
      if(__AreaLabel != that.__AreaLabel) return false;
      if(__BackgroundBehaviorArea != that.__BackgroundBehaviorArea) return false;
      return true;

   }

   bool AreaOfInterest::operator!=(const AreaOfInterest & that)
   {
      return( !(operator==(that)) );
   }

   AreaOfInterest& AreaOfInterest::setAreaID(const int64_t val)
   {
      __AreaID = val;
      return *this;
   }

   AreaOfInterest& AreaOfInterest::setArea(const afrl::cmasi::AbstractGeometry* const val)
   {
      if (__Area != nullptr) { delete __Area; __Area = nullptr; }
      if (val != nullptr) { __Area = const_cast< afrl::cmasi::AbstractGeometry* > (val); }
      return *this;
   }

   AreaOfInterest& AreaOfInterest::setAreaAction(const afrl::impact::AreaActionOptions::AreaActionOptions val)
   {
      __AreaAction = val;
      return *this;
   }

   AreaOfInterest& AreaOfInterest::setAreaLabel(const std::string val)
   {
      __AreaLabel = val;
      return *this;
   }

   AreaOfInterest& AreaOfInterest::setBackgroundBehaviorArea(const bool val)
   {
      __BackgroundBehaviorArea = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

