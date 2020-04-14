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
#include "afrl/impact/LineOfInterest.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string LineOfInterest::Subscription = "afrl.impact.LineOfInterest";
   const std::string LineOfInterest::TypeName = "LineOfInterest";
   const std::string LineOfInterest::SeriesName = "IMPACT";
   const int64_t LineOfInterest::SeriesId = 5281966179208134656LL;
   const uint16_t LineOfInterest::SeriesVersion = 14;
   const uint32_t LineOfInterest::TypeId = 20;
   
   bool isLineOfInterest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   bool isLineOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 20) return false;
      return true;
   }
   
   std::vector< std::string > LineOfInterestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   LineOfInterest::LineOfInterest(void) : avtas::lmcp::Object()
   {
      __LineID = 0LL;
      __LineAction = afrl::impact::AreaActionOptions::Created;
      __LineLabel = std::string("");
      __BackgroundBehaviorLine = false;

   }
     
   LineOfInterest::LineOfInterest(const LineOfInterest &that) : avtas::lmcp::Object(that)
   {
        __LineID = that.__LineID;
        __Line.clear();
        for (size_t i=0; i< that.__Line.size(); i++)
        {
           __Line.push_back( that.__Line[i] == nullptr ? nullptr : that.__Line[i]->clone());
        }
        __LineAction = that.__LineAction;
        __LineLabel = that.__LineLabel;
        __BackgroundBehaviorLine = that.__BackgroundBehaviorLine;

   }
   
   LineOfInterest & LineOfInterest::operator=(const LineOfInterest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__Line.size(); i++)
         {
            if (__Line[i] != nullptr) delete __Line[i];
         }

         __LineID = that.__LineID;
         __Line.clear();
         for (size_t i=0; i< that.__Line.size(); i++)
         {
            __Line.push_back( that.__Line[i] == nullptr ? nullptr : that.__Line[i]->clone());
         }
         __LineAction = that.__LineAction;
         __LineLabel = that.__LineLabel;
         __BackgroundBehaviorLine = that.__BackgroundBehaviorLine;

      }
      return *this;
   }

   LineOfInterest* LineOfInterest::clone() const
   {
        return new LineOfInterest(*this);
   }
   
   LineOfInterest::~LineOfInterest(void)
   {
      for (size_t i=0; i<__Line.size(); i++)
      {
         if (__Line[i] != nullptr) delete __Line[i];
      }

   }
  
   void LineOfInterest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__LineID);
      buf.putUShort( static_cast<uint16_t>(__Line.size()));
      for (size_t i=0; i<__Line.size(); i++)
      {
         assert(__Line[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Line[i], buf);
      }
      buf.putInt( (int32_t) __LineAction);
      buf.putString(__LineLabel);
      buf.putBool(__BackgroundBehaviorLine);

   }
   
   void LineOfInterest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __LineID = buf.getLong();
      for (size_t i=0; i<__Line.size(); i++)
      {
         if (__Line[i] != nullptr)
            delete __Line[i];
      }
      __Line.clear();
      uint16_t __Line_length = buf.getUShort();
      for (uint32_t i=0; i< __Line_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::Location3D* e = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Line.push_back(e);
         }
      }
      __LineAction = (afrl::impact::AreaActionOptions::AreaActionOptions) buf.getInt();
      __LineLabel = buf.getString();
      __BackgroundBehaviorLine = buf.getBool();

   }

   uint32_t LineOfInterest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Line.size(); i++)
      {
         if (__Line[i] != nullptr)
         {
            size += __Line[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(afrl::impact::AreaActionOptions::AreaActionOptions);
      size += 2 + __LineLabel.length();
      size += sizeof(bool);

      return size;
   }

   std::string LineOfInterest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( LineOfInterest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "LineID (int64_t) = " << __LineID << "\n";
      oss << indent << "Line (Location3D [ " << __Line.size() << ", var ])\n";
      oss << indent << "LineAction (AreaActionOptions) = " << __LineAction << "\n";
      oss << indent << "LineLabel (std::string) = " << __LineLabel << "\n";
      oss << indent << "BackgroundBehaviorLine (bool) = " << __BackgroundBehaviorLine << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string LineOfInterest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<LineOfInterest Series=\"IMPACT\">\n";
      str << ws << "   <LineID>" << __LineID << "</LineID>\n";
      str << ws << "   <Line>\n";
      for (size_t i=0; i<__Line.size(); i++)
      {
         str << (__Line[i] == nullptr ? ( ws + "   <null/>\n") : (__Line[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Line>\n";
      str << ws << "   <LineAction>" << afrl::impact::AreaActionOptions::get_string(__LineAction) << "</LineAction>\n";
      str << ws << "   <LineLabel>" << __LineLabel << "</LineLabel>\n";
      str << ws << "   <BackgroundBehaviorLine>" << (__BackgroundBehaviorLine ? "true" : "false") << "</BackgroundBehaviorLine>\n";
      str << ws << "</LineOfInterest>\n";

      return str.str();
   }

   bool LineOfInterest::operator==(const LineOfInterest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__LineID != that.__LineID) return false;
      if(__Line.size() != that.__Line.size()) return false;
      for (size_t i=0; i<__Line.size(); i++)
      {
         if(__Line[i] && that.__Line[i])
         {
            if(__Line[i]->getSeriesNameAsLong() != that.__Line[i]->getSeriesNameAsLong()) return false;
            if(__Line[i]->getSeriesVersion() != that.__Line[i]->getSeriesVersion()) return false;
            if(__Line[i]->getLmcpType() != that.__Line[i]->getLmcpType()) return false;
            if( *(__Line[i]) != *(that.__Line[i]) ) return false;
         }
         else if(__Line[i] != that.__Line[i]) return false;
      }
      if(__LineAction != that.__LineAction) return false;
      if(__LineLabel != that.__LineLabel) return false;
      if(__BackgroundBehaviorLine != that.__BackgroundBehaviorLine) return false;
      return true;

   }

   bool LineOfInterest::operator!=(const LineOfInterest & that)
   {
      return( !(operator==(that)) );
   }

   LineOfInterest& LineOfInterest::setLineID(const int64_t val)
   {
      __LineID = val;
      return *this;
   }


   LineOfInterest& LineOfInterest::setLineAction(const afrl::impact::AreaActionOptions::AreaActionOptions val)
   {
      __LineAction = val;
      return *this;
   }

   LineOfInterest& LineOfInterest::setLineLabel(const std::string val)
   {
      __LineLabel = val;
      return *this;
   }

   LineOfInterest& LineOfInterest::setBackgroundBehaviorLine(const bool val)
   {
      __BackgroundBehaviorLine = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

