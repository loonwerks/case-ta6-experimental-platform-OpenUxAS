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
#include "afrl/cmasi/GimbalStareAction.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GimbalStareAction::Subscription = "afrl.cmasi.GimbalStareAction";
   const std::string GimbalStareAction::TypeName = "GimbalStareAction";
   const std::string GimbalStareAction::SeriesName = "CMASI";
   const int64_t GimbalStareAction::SeriesId = 4849604199710720000LL;
   const uint16_t GimbalStareAction::SeriesVersion = 3;
   const uint32_t GimbalStareAction::TypeId = 26;
   
   bool isGimbalStareAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 26) return false;
      return true;
   }
   
   bool isGimbalStareAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 26) return false;
      return true;
   }
   
   std::vector< std::string > GimbalStareActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GimbalStareAction::GimbalStareAction(void) : afrl::cmasi::PayloadAction()
   {
      __Starepoint = new afrl::cmasi::Location3D();
      __Duration = 0LL;

   }
     
   GimbalStareAction::GimbalStareAction(const GimbalStareAction &that) : afrl::cmasi::PayloadAction(that)
   {
        __Starepoint = that.__Starepoint == nullptr ? nullptr : that.__Starepoint->clone();
        __Duration = that.__Duration;

   }
   
   GimbalStareAction & GimbalStareAction::operator=(const GimbalStareAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadAction::operator=(that);
         if (__Starepoint != nullptr) delete __Starepoint;

         __Starepoint = that.__Starepoint == nullptr ? nullptr : that.__Starepoint->clone();
         __Duration = that.__Duration;

      }
      return *this;
   }

   GimbalStareAction* GimbalStareAction::clone() const
   {
        return new GimbalStareAction(*this);
   }
   
   GimbalStareAction::~GimbalStareAction(void)
   {
      if (__Starepoint != nullptr) delete __Starepoint;

   }
  
   void GimbalStareAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadAction::pack(buf);
      // Copy the class into the buffer
      assert(__Starepoint != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Starepoint, buf);
      buf.putLong(__Duration);

   }
   
   void GimbalStareAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadAction::unpack(buf);
      // Copy the buffer into the class
      {
         if (__Starepoint != nullptr) delete __Starepoint;
         __Starepoint = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __Starepoint = (afrl::cmasi::Location3D*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__Starepoint != nullptr) __Starepoint->unpack(buf);
            else assert(__Starepoint != nullptr);
         }
      }
      __Duration = buf.getLong();

   }

   uint32_t GimbalStareAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadAction::calculatePackedSize();
      size += (__Starepoint != nullptr ? __Starepoint->calculatePackedSize() + 15 : 1);
      size += sizeof(int64_t);

      return size;
   }

   std::string GimbalStareAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GimbalStareAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      oss << indent << "Starepoint (Location3D)";
      if (__Starepoint == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Duration (int64_t) = " << __Duration << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GimbalStareAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GimbalStareAction Series=\"CMASI\">\n";
      if (__Starepoint != nullptr)
      {
         str << ws << "   <Starepoint>";
         str << "\n" + __Starepoint->toXML(depth + 1) + ws + "   ";
         str << "</Starepoint>\n";
      }
      str << ws << "   <Duration>" << __Duration << "</Duration>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</GimbalStareAction>\n";

      return str.str();
   }

   bool GimbalStareAction::operator==(const GimbalStareAction & that)
   {
      if( afrl::cmasi::PayloadAction::operator!=(that) )
      {
          return false;
      }
      if(__Starepoint && that.__Starepoint)
      {
         if(__Starepoint->getSeriesNameAsLong() != that.__Starepoint->getSeriesNameAsLong()) return false;
         if(__Starepoint->getSeriesVersion() != that.__Starepoint->getSeriesVersion()) return false;
         if(__Starepoint->getLmcpType() != that.__Starepoint->getLmcpType()) return false;
         if( *(__Starepoint) != *(that.__Starepoint) ) return false;
      }
      else if(__Starepoint != that.__Starepoint) return false;
      if(__Duration != that.__Duration) return false;
      return true;

   }

   bool GimbalStareAction::operator!=(const GimbalStareAction & that)
   {
      return( !(operator==(that)) );
   }

   GimbalStareAction& GimbalStareAction::setStarepoint(const afrl::cmasi::Location3D* const val)
   {
      if (__Starepoint != nullptr) { delete __Starepoint; __Starepoint = nullptr; }
      if (val != nullptr) { __Starepoint = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   GimbalStareAction& GimbalStareAction::setDuration(const int64_t val)
   {
      __Duration = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

