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
#include "afrl/cmasi/LoiterAction.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string LoiterAction::Subscription = "afrl.cmasi.LoiterAction";
   const std::string LoiterAction::TypeName = "LoiterAction";
   const std::string LoiterAction::SeriesName = "CMASI";
   const int64_t LoiterAction::SeriesId = 4849604199710720000LL;
   const uint16_t LoiterAction::SeriesVersion = 3;
   const uint32_t LoiterAction::TypeId = 33;
   
   bool isLoiterAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 33) return false;
      return true;
   }
   
   bool isLoiterAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 33) return false;
      return true;
   }
   
   std::vector< std::string > LoiterActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   LoiterAction::LoiterAction(void) : afrl::cmasi::NavigationAction()
   {
      __LoiterType = afrl::cmasi::LoiterType::VehicleDefault;
      __Radius = 0.f;
      __Axis = 0.f;
      __Length = 0.f;
      __Direction = afrl::cmasi::LoiterDirection::VehicleDefault;
      __Duration = 0LL;
      __Airspeed = 0.f;
      __Location = new afrl::cmasi::Location3D();

   }
     
   LoiterAction::LoiterAction(const LoiterAction &that) : afrl::cmasi::NavigationAction(that)
   {
        __LoiterType = that.__LoiterType;
        __Radius = that.__Radius;
        __Axis = that.__Axis;
        __Length = that.__Length;
        __Direction = that.__Direction;
        __Duration = that.__Duration;
        __Airspeed = that.__Airspeed;
        __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();

   }
   
   LoiterAction & LoiterAction::operator=(const LoiterAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::NavigationAction::operator=(that);
         if (__Location != nullptr) delete __Location;

         __LoiterType = that.__LoiterType;
         __Radius = that.__Radius;
         __Axis = that.__Axis;
         __Length = that.__Length;
         __Direction = that.__Direction;
         __Duration = that.__Duration;
         __Airspeed = that.__Airspeed;
         __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();

      }
      return *this;
   }

   LoiterAction* LoiterAction::clone() const
   {
        return new LoiterAction(*this);
   }
   
   LoiterAction::~LoiterAction(void)
   {
      if (__Location != nullptr) delete __Location;

   }
  
   void LoiterAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::NavigationAction::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __LoiterType);
      buf.putFloat(__Radius);
      buf.putFloat(__Axis);
      buf.putFloat(__Length);
      buf.putInt( (int32_t) __Direction);
      buf.putLong(__Duration);
      buf.putFloat(__Airspeed);
      assert(__Location != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Location, buf);

   }
   
   void LoiterAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::NavigationAction::unpack(buf);
      // Copy the buffer into the class
      __LoiterType = (afrl::cmasi::LoiterType::LoiterType) buf.getInt();
      __Radius = buf.getFloat();
      __Axis = buf.getFloat();
      __Length = buf.getFloat();
      __Direction = (afrl::cmasi::LoiterDirection::LoiterDirection) buf.getInt();
      __Duration = buf.getLong();
      __Airspeed = buf.getFloat();
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

   }

   uint32_t LoiterAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::NavigationAction::calculatePackedSize();
      size += sizeof(afrl::cmasi::LoiterType::LoiterType);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(afrl::cmasi::LoiterDirection::LoiterDirection);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += (__Location != nullptr ? __Location->calculatePackedSize() + 15 : 1);

      return size;
   }

   std::string LoiterAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( LoiterAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";


      oss << indent << "LoiterType (LoiterType) = " << __LoiterType << "\n";
      oss << indent << "Radius (float) = " << __Radius << "\n";
      oss << indent << "Axis (float) = " << __Axis << "\n";
      oss << indent << "Length (float) = " << __Length << "\n";
      oss << indent << "Direction (LoiterDirection) = " << __Direction << "\n";
      oss << indent << "Duration (int64_t) = " << __Duration << "\n";
      oss << indent << "Airspeed (float) = " << __Airspeed << "\n";
      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string LoiterAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<LoiterAction Series=\"CMASI\">\n";
      str << ws << "   <LoiterType>" << afrl::cmasi::LoiterType::get_string(__LoiterType) << "</LoiterType>\n";
      str << ws << "   <Radius>" << __Radius << "</Radius>\n";
      str << ws << "   <Axis>" << __Axis << "</Axis>\n";
      str << ws << "   <Length>" << __Length << "</Length>\n";
      str << ws << "   <Direction>" << afrl::cmasi::LoiterDirection::get_string(__Direction) << "</Direction>\n";
      str << ws << "   <Duration>" << __Duration << "</Duration>\n";
      str << ws << "   <Airspeed>" << __Airspeed << "</Airspeed>\n";
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
      str << ws << "</LoiterAction>\n";

      return str.str();
   }

   bool LoiterAction::operator==(const LoiterAction & that)
   {
      if( afrl::cmasi::NavigationAction::operator!=(that) )
      {
          return false;
      }
      if(__LoiterType != that.__LoiterType) return false;
      if(__Radius != that.__Radius) return false;
      if(__Axis != that.__Axis) return false;
      if(__Length != that.__Length) return false;
      if(__Direction != that.__Direction) return false;
      if(__Duration != that.__Duration) return false;
      if(__Airspeed != that.__Airspeed) return false;
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

   bool LoiterAction::operator!=(const LoiterAction & that)
   {
      return( !(operator==(that)) );
   }

   LoiterAction& LoiterAction::setLoiterType(const afrl::cmasi::LoiterType::LoiterType val)
   {
      __LoiterType = val;
      return *this;
   }

   LoiterAction& LoiterAction::setRadius(const float val)
   {
      __Radius = val;
      return *this;
   }

   LoiterAction& LoiterAction::setAxis(const float val)
   {
      __Axis = val;
      return *this;
   }

   LoiterAction& LoiterAction::setLength(const float val)
   {
      __Length = val;
      return *this;
   }

   LoiterAction& LoiterAction::setDirection(const afrl::cmasi::LoiterDirection::LoiterDirection val)
   {
      __Direction = val;
      return *this;
   }

   LoiterAction& LoiterAction::setDuration(const int64_t val)
   {
      __Duration = val;
      return *this;
   }

   LoiterAction& LoiterAction::setAirspeed(const float val)
   {
      __Airspeed = val;
      return *this;
   }

   LoiterAction& LoiterAction::setLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__Location != nullptr) { delete __Location; __Location = nullptr; }
      if (val != nullptr) { __Location = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

