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
#include "afrl/cmasi/StopMovementAction.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string StopMovementAction::Subscription = "afrl.cmasi.StopMovementAction";
   const std::string StopMovementAction::TypeName = "StopMovementAction";
   const std::string StopMovementAction::SeriesName = "CMASI";
   const int64_t StopMovementAction::SeriesId = 4849604199710720000LL;
   const uint16_t StopMovementAction::SeriesVersion = 3;
   const uint32_t StopMovementAction::TypeId = 58;
   
   bool isStopMovementAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 58) return false;
      return true;
   }
   
   bool isStopMovementAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 58) return false;
      return true;
   }
   
   std::vector< std::string > StopMovementActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   StopMovementAction::StopMovementAction(void) : afrl::cmasi::VehicleAction()
   {
      __Location = nullptr;

   }
     
   StopMovementAction::StopMovementAction(const StopMovementAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();

   }
   
   StopMovementAction & StopMovementAction::operator=(const StopMovementAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);
         if (__Location != nullptr) delete __Location;

         __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();

      }
      return *this;
   }

   StopMovementAction* StopMovementAction::clone() const
   {
        return new StopMovementAction(*this);
   }
   
   StopMovementAction::~StopMovementAction(void)
   {
      if (__Location != nullptr) delete __Location;

   }
  
   void StopMovementAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Location, buf);

   }
   
   void StopMovementAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
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
         }
      }

   }

   uint32_t StopMovementAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += (__Location != nullptr ? __Location->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string StopMovementAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( StopMovementAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string StopMovementAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<StopMovementAction Series=\"CMASI\">\n";
      if (__Location != nullptr)
      {
         str << ws << "   <Location>";
         str << "\n" + __Location->toXML(depth + 1) + ws + "   ";
         str << "</Location>\n";
      }
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</StopMovementAction>\n";

      return str.str();
   }

   bool StopMovementAction::operator==(const StopMovementAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__Location && that.__Location)
      {
         if(__Location->getSeriesNameAsLong() != that.__Location->getSeriesNameAsLong()) return false;
         if(__Location->getSeriesVersion() != that.__Location->getSeriesVersion()) return false;
         if(__Location->getLmcpType() != that.__Location->getLmcpType()) return false;
         if( *(__Location) != *(that.__Location) ) return false;
      }
      else if(__Location != that.__Location) return false;
      return true;

   }

   bool StopMovementAction::operator!=(const StopMovementAction & that)
   {
      return( !(operator==(that)) );
   }

   StopMovementAction& StopMovementAction::setLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__Location != nullptr) { delete __Location; __Location = nullptr; }
      if (val != nullptr) { __Location = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

