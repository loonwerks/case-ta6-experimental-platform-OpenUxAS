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
#include "afrl/cmasi/EntityState.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"
#include "afrl/cmasi/GimballedPayloadState.h"
#include "afrl/cmasi/CameraState.h"
#include "afrl/cmasi/GimbalState.h"
#include "afrl/cmasi/VideoStreamState.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EntityState::Subscription = "afrl.cmasi.EntityState";
   const std::string EntityState::TypeName = "EntityState";
   const std::string EntityState::SeriesName = "CMASI";
   const int64_t EntityState::SeriesId = 4849604199710720000LL;
   const uint16_t EntityState::SeriesVersion = 3;
   const uint32_t EntityState::TypeId = 14;
   
   bool isEntityState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   bool isEntityState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 14) return false;
      return true;
   }
   
   std::vector< std::string > EntityStateDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.vehicles.GroundVehicleState");
       descendants.push_back("afrl.vehicles.SurfaceVehicleState");
       descendants.push_back("afrl.vehicles.StationarySensorState");
       descendants.push_back("afrl.impact.RadioTowerState");
       descendants.push_back("afrl.cmasi.AirVehicleState");

       return descendants;
   }
   
   EntityState::EntityState(void) : avtas::lmcp::Object()
   {
      __ID = 0LL;
      __u = 0.f;
      __v = 0.f;
      __w = 0.f;
      __udot = 0.f;
      __vdot = 0.f;
      __wdot = 0.f;
      __Heading = 0.f;
      __Pitch = 0.f;
      __Roll = 0.f;
      __p = 0.f;
      __q = 0.f;
      __r = 0.f;
      __Course = 0.f;
      __Groundspeed = 0.f;
      __Location = new afrl::cmasi::Location3D();
      __EnergyAvailable = 0.f;
      __ActualEnergyRate = 0.f;
      __CurrentWaypoint = 0LL;
      __CurrentCommand = 0LL;
      __Mode = afrl::cmasi::NavigationMode::Waypoint;
      __Time = 0LL;

   }
     
   EntityState::EntityState(const EntityState &that) : avtas::lmcp::Object(that)
   {
        __ID = that.__ID;
        __u = that.__u;
        __v = that.__v;
        __w = that.__w;
        __udot = that.__udot;
        __vdot = that.__vdot;
        __wdot = that.__wdot;
        __Heading = that.__Heading;
        __Pitch = that.__Pitch;
        __Roll = that.__Roll;
        __p = that.__p;
        __q = that.__q;
        __r = that.__r;
        __Course = that.__Course;
        __Groundspeed = that.__Groundspeed;
        __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
        __EnergyAvailable = that.__EnergyAvailable;
        __ActualEnergyRate = that.__ActualEnergyRate;
        __PayloadStateList.clear();
        for (size_t i=0; i< that.__PayloadStateList.size(); i++)
        {
           __PayloadStateList.push_back( that.__PayloadStateList[i] == nullptr ? nullptr : that.__PayloadStateList[i]->clone());
        }
        __CurrentWaypoint = that.__CurrentWaypoint;
        __CurrentCommand = that.__CurrentCommand;
        __Mode = that.__Mode;
        __AssociatedTasks.clear();
        for (size_t i=0; i< that.__AssociatedTasks.size(); i++)
        {
           __AssociatedTasks.push_back( that.__AssociatedTasks[i]);
        }
        __Time = that.__Time;
        __Info.clear();
        for (size_t i=0; i< that.__Info.size(); i++)
        {
           __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
        }

   }
   
   EntityState & EntityState::operator=(const EntityState &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Location != nullptr) delete __Location;
         for (size_t i=0; i<__PayloadStateList.size(); i++)
         {
            if (__PayloadStateList[i] != nullptr) delete __PayloadStateList[i];
         }
         for (size_t i=0; i<__Info.size(); i++)
         {
            if (__Info[i] != nullptr) delete __Info[i];
         }

         __ID = that.__ID;
         __u = that.__u;
         __v = that.__v;
         __w = that.__w;
         __udot = that.__udot;
         __vdot = that.__vdot;
         __wdot = that.__wdot;
         __Heading = that.__Heading;
         __Pitch = that.__Pitch;
         __Roll = that.__Roll;
         __p = that.__p;
         __q = that.__q;
         __r = that.__r;
         __Course = that.__Course;
         __Groundspeed = that.__Groundspeed;
         __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
         __EnergyAvailable = that.__EnergyAvailable;
         __ActualEnergyRate = that.__ActualEnergyRate;
         __PayloadStateList.clear();
         for (size_t i=0; i< that.__PayloadStateList.size(); i++)
         {
            __PayloadStateList.push_back( that.__PayloadStateList[i] == nullptr ? nullptr : that.__PayloadStateList[i]->clone());
         }
         __CurrentWaypoint = that.__CurrentWaypoint;
         __CurrentCommand = that.__CurrentCommand;
         __Mode = that.__Mode;
         __AssociatedTasks.clear();
         for (size_t i=0; i< that.__AssociatedTasks.size(); i++)
         {
            __AssociatedTasks.push_back( that.__AssociatedTasks[i]);
         }
         __Time = that.__Time;
         __Info.clear();
         for (size_t i=0; i< that.__Info.size(); i++)
         {
            __Info.push_back( that.__Info[i] == nullptr ? nullptr : that.__Info[i]->clone());
         }

      }
      return *this;
   }

   EntityState* EntityState::clone() const
   {
        return new EntityState(*this);
   }
   
   EntityState::~EntityState(void)
   {
      if (__Location != nullptr) delete __Location;
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         if (__PayloadStateList[i] != nullptr) delete __PayloadStateList[i];
      }
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr) delete __Info[i];
      }

   }
  
   void EntityState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ID);
      buf.putFloat(__u);
      buf.putFloat(__v);
      buf.putFloat(__w);
      buf.putFloat(__udot);
      buf.putFloat(__vdot);
      buf.putFloat(__wdot);
      buf.putFloat(__Heading);
      buf.putFloat(__Pitch);
      buf.putFloat(__Roll);
      buf.putFloat(__p);
      buf.putFloat(__q);
      buf.putFloat(__r);
      buf.putFloat(__Course);
      buf.putFloat(__Groundspeed);
      assert(__Location != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Location, buf);
      buf.putFloat(__EnergyAvailable);
      buf.putFloat(__ActualEnergyRate);
      buf.putUShort( static_cast<uint16_t>(__PayloadStateList.size()));
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         assert(__PayloadStateList[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __PayloadStateList[i], buf);
      }
      buf.putLong(__CurrentWaypoint);
      buf.putLong(__CurrentCommand);
      buf.putInt( (int32_t) __Mode);
      buf.putUShort( static_cast<uint16_t>(__AssociatedTasks.size()));
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         buf.putLong(__AssociatedTasks[i]);
      }
      buf.putLong(__Time);
      buf.putUShort( static_cast<uint16_t>(__Info.size()));
      for (size_t i=0; i<__Info.size(); i++)
      {
         assert(__Info[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Info[i], buf);
      }

   }
   
   void EntityState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ID = buf.getLong();
      __u = buf.getFloat();
      __v = buf.getFloat();
      __w = buf.getFloat();
      __udot = buf.getFloat();
      __vdot = buf.getFloat();
      __wdot = buf.getFloat();
      __Heading = buf.getFloat();
      __Pitch = buf.getFloat();
      __Roll = buf.getFloat();
      __p = buf.getFloat();
      __q = buf.getFloat();
      __r = buf.getFloat();
      __Course = buf.getFloat();
      __Groundspeed = buf.getFloat();
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
      __EnergyAvailable = buf.getFloat();
      __ActualEnergyRate = buf.getFloat();
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         if (__PayloadStateList[i] != nullptr)
            delete __PayloadStateList[i];
      }
      __PayloadStateList.clear();
      uint16_t __PayloadStateList_length = buf.getUShort();
      for (uint32_t i=0; i< __PayloadStateList_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::PayloadState* e = (afrl::cmasi::PayloadState*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __PayloadStateList.push_back(e);
         }
      }
      __CurrentWaypoint = buf.getLong();
      __CurrentCommand = buf.getLong();
      __Mode = (afrl::cmasi::NavigationMode::NavigationMode) buf.getInt();
      __AssociatedTasks.clear();
      uint16_t __AssociatedTasks_length = buf.getUShort();
      for (uint32_t i=0; i< __AssociatedTasks_length; i++)
      {
         __AssociatedTasks.push_back(buf.getLong() );
      }
      __Time = buf.getLong();
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
            delete __Info[i];
      }
      __Info.clear();
      uint16_t __Info_length = buf.getUShort();
      for (uint32_t i=0; i< __Info_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            afrl::cmasi::KeyValuePair* e = (afrl::cmasi::KeyValuePair*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __Info.push_back(e);
         }
      }

   }

   uint32_t EntityState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += sizeof(float);
      size += (__Location != nullptr ? __Location->calculatePackedSize() + 15 : 1);
      size += sizeof(float);
      size += sizeof(float);
      size += 2;
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         if (__PayloadStateList[i] != nullptr)
         {
            size += __PayloadStateList[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += sizeof(afrl::cmasi::NavigationMode::NavigationMode);
      size += 2 + sizeof(int64_t) * __AssociatedTasks.size();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if (__Info[i] != nullptr)
         {
            size += __Info[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string EntityState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EntityState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ID (int64_t) = " << __ID << "\n";
      oss << indent << "u (float) = " << __u << "\n";
      oss << indent << "v (float) = " << __v << "\n";
      oss << indent << "w (float) = " << __w << "\n";
      oss << indent << "udot (float) = " << __udot << "\n";
      oss << indent << "vdot (float) = " << __vdot << "\n";
      oss << indent << "wdot (float) = " << __wdot << "\n";
      oss << indent << "Heading (float) = " << __Heading << "\n";
      oss << indent << "Pitch (float) = " << __Pitch << "\n";
      oss << indent << "Roll (float) = " << __Roll << "\n";
      oss << indent << "p (float) = " << __p << "\n";
      oss << indent << "q (float) = " << __q << "\n";
      oss << indent << "r (float) = " << __r << "\n";
      oss << indent << "Course (float) = " << __Course << "\n";
      oss << indent << "Groundspeed (float) = " << __Groundspeed << "\n";
      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EnergyAvailable (float) = " << __EnergyAvailable << "\n";
      oss << indent << "ActualEnergyRate (float) = " << __ActualEnergyRate << "\n";
      oss << indent << "PayloadStateList (PayloadState [ " << __PayloadStateList.size() << ", var ])\n";
      oss << indent << "CurrentWaypoint (int64_t) = " << __CurrentWaypoint << "\n";
      oss << indent << "CurrentCommand (int64_t) = " << __CurrentCommand << "\n";
      oss << indent << "Mode (NavigationMode) = " << __Mode << "\n";
      oss << indent << "AssociatedTasks (int64 [ " << __AssociatedTasks.size() << ", var ])\n";
      oss << indent << "Time (int64_t) = " << __Time << "\n";
      oss << indent << "Info (KeyValuePair [ " << __Info.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EntityState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EntityState Series=\"CMASI\">\n";
      str << ws << "   <ID>" << __ID << "</ID>\n";
      str << ws << "   <u>" << __u << "</u>\n";
      str << ws << "   <v>" << __v << "</v>\n";
      str << ws << "   <w>" << __w << "</w>\n";
      str << ws << "   <udot>" << __udot << "</udot>\n";
      str << ws << "   <vdot>" << __vdot << "</vdot>\n";
      str << ws << "   <wdot>" << __wdot << "</wdot>\n";
      str << ws << "   <Heading>" << __Heading << "</Heading>\n";
      str << ws << "   <Pitch>" << __Pitch << "</Pitch>\n";
      str << ws << "   <Roll>" << __Roll << "</Roll>\n";
      str << ws << "   <p>" << __p << "</p>\n";
      str << ws << "   <q>" << __q << "</q>\n";
      str << ws << "   <r>" << __r << "</r>\n";
      str << ws << "   <Course>" << __Course << "</Course>\n";
      str << ws << "   <Groundspeed>" << __Groundspeed << "</Groundspeed>\n";
      if (__Location != nullptr)
      {
         str << ws << "   <Location>";
         str << "\n" + __Location->toXML(depth + 1) + ws + "   ";
         str << "</Location>\n";
      }
      str << ws << "   <EnergyAvailable>" << __EnergyAvailable << "</EnergyAvailable>\n";
      str << ws << "   <ActualEnergyRate>" << __ActualEnergyRate << "</ActualEnergyRate>\n";
      str << ws << "   <PayloadStateList>\n";
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         str << (__PayloadStateList[i] == nullptr ? ( ws + "   <null/>\n") : (__PayloadStateList[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </PayloadStateList>\n";
      str << ws << "   <CurrentWaypoint>" << __CurrentWaypoint << "</CurrentWaypoint>\n";
      str << ws << "   <CurrentCommand>" << __CurrentCommand << "</CurrentCommand>\n";
      str << ws << "   <Mode>" << afrl::cmasi::NavigationMode::get_string(__Mode) << "</Mode>\n";
      str << ws << "   <AssociatedTasks>\n";
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTasks[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTasks>\n";
      str << ws << "   <Time>" << __Time << "</Time>\n";
      str << ws << "   <Info>\n";
      for (size_t i=0; i<__Info.size(); i++)
      {
         str << (__Info[i] == nullptr ? ( ws + "   <null/>\n") : (__Info[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Info>\n";
      str << ws << "</EntityState>\n";

      return str.str();
   }

   bool EntityState::operator==(const EntityState & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ID != that.__ID) return false;
      if(__u != that.__u) return false;
      if(__v != that.__v) return false;
      if(__w != that.__w) return false;
      if(__udot != that.__udot) return false;
      if(__vdot != that.__vdot) return false;
      if(__wdot != that.__wdot) return false;
      if(__Heading != that.__Heading) return false;
      if(__Pitch != that.__Pitch) return false;
      if(__Roll != that.__Roll) return false;
      if(__p != that.__p) return false;
      if(__q != that.__q) return false;
      if(__r != that.__r) return false;
      if(__Course != that.__Course) return false;
      if(__Groundspeed != that.__Groundspeed) return false;
      if(__Location && that.__Location)
      {
         if(__Location->getSeriesNameAsLong() != that.__Location->getSeriesNameAsLong()) return false;
         if(__Location->getSeriesVersion() != that.__Location->getSeriesVersion()) return false;
         if(__Location->getLmcpType() != that.__Location->getLmcpType()) return false;
         if( *(__Location) != *(that.__Location) ) return false;
      }
      else if(__Location != that.__Location) return false;
      if(__EnergyAvailable != that.__EnergyAvailable) return false;
      if(__ActualEnergyRate != that.__ActualEnergyRate) return false;
      if(__PayloadStateList.size() != that.__PayloadStateList.size()) return false;
      for (size_t i=0; i<__PayloadStateList.size(); i++)
      {
         if(__PayloadStateList[i] && that.__PayloadStateList[i])
         {
            if(__PayloadStateList[i]->getSeriesNameAsLong() != that.__PayloadStateList[i]->getSeriesNameAsLong()) return false;
            if(__PayloadStateList[i]->getSeriesVersion() != that.__PayloadStateList[i]->getSeriesVersion()) return false;
            if(__PayloadStateList[i]->getLmcpType() != that.__PayloadStateList[i]->getLmcpType()) return false;
            if( *(__PayloadStateList[i]) != *(that.__PayloadStateList[i]) ) return false;
         }
         else if(__PayloadStateList[i] != that.__PayloadStateList[i]) return false;
      }
      if(__CurrentWaypoint != that.__CurrentWaypoint) return false;
      if(__CurrentCommand != that.__CurrentCommand) return false;
      if(__Mode != that.__Mode) return false;
      if(__AssociatedTasks.size() != that.__AssociatedTasks.size()) return false;
      for (size_t i=0; i<__AssociatedTasks.size(); i++)
      {
         if(__AssociatedTasks[i] != that.__AssociatedTasks[i]) return false;
      }
      if(__Time != that.__Time) return false;
      if(__Info.size() != that.__Info.size()) return false;
      for (size_t i=0; i<__Info.size(); i++)
      {
         if(__Info[i] && that.__Info[i])
         {
            if(__Info[i]->getSeriesNameAsLong() != that.__Info[i]->getSeriesNameAsLong()) return false;
            if(__Info[i]->getSeriesVersion() != that.__Info[i]->getSeriesVersion()) return false;
            if(__Info[i]->getLmcpType() != that.__Info[i]->getLmcpType()) return false;
            if( *(__Info[i]) != *(that.__Info[i]) ) return false;
         }
         else if(__Info[i] != that.__Info[i]) return false;
      }
      return true;

   }

   bool EntityState::operator!=(const EntityState & that)
   {
      return( !(operator==(that)) );
   }

   EntityState& EntityState::setID(const int64_t val)
   {
      __ID = val;
      return *this;
   }

   EntityState& EntityState::setU(const float val)
   {
      __u = val;
      return *this;
   }

   EntityState& EntityState::setV(const float val)
   {
      __v = val;
      return *this;
   }

   EntityState& EntityState::setW(const float val)
   {
      __w = val;
      return *this;
   }

   EntityState& EntityState::setUdot(const float val)
   {
      __udot = val;
      return *this;
   }

   EntityState& EntityState::setVdot(const float val)
   {
      __vdot = val;
      return *this;
   }

   EntityState& EntityState::setWdot(const float val)
   {
      __wdot = val;
      return *this;
   }

   EntityState& EntityState::setHeading(const float val)
   {
      __Heading = val;
      return *this;
   }

   EntityState& EntityState::setPitch(const float val)
   {
      __Pitch = val;
      return *this;
   }

   EntityState& EntityState::setRoll(const float val)
   {
      __Roll = val;
      return *this;
   }

   EntityState& EntityState::setP(const float val)
   {
      __p = val;
      return *this;
   }

   EntityState& EntityState::setQ(const float val)
   {
      __q = val;
      return *this;
   }

   EntityState& EntityState::setR(const float val)
   {
      __r = val;
      return *this;
   }

   EntityState& EntityState::setCourse(const float val)
   {
      __Course = val;
      return *this;
   }

   EntityState& EntityState::setGroundspeed(const float val)
   {
      __Groundspeed = val;
      return *this;
   }

   EntityState& EntityState::setLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__Location != nullptr) { delete __Location; __Location = nullptr; }
      if (val != nullptr) { __Location = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }

   EntityState& EntityState::setEnergyAvailable(const float val)
   {
      __EnergyAvailable = val;
      return *this;
   }

   EntityState& EntityState::setActualEnergyRate(const float val)
   {
      __ActualEnergyRate = val;
      return *this;
   }


   EntityState& EntityState::setCurrentWaypoint(const int64_t val)
   {
      __CurrentWaypoint = val;
      return *this;
   }

   EntityState& EntityState::setCurrentCommand(const int64_t val)
   {
      __CurrentCommand = val;
      return *this;
   }

   EntityState& EntityState::setMode(const afrl::cmasi::NavigationMode::NavigationMode val)
   {
      __Mode = val;
      return *this;
   }


   EntityState& EntityState::setTime(const int64_t val)
   {
      __Time = val;
      return *this;
   }



} // end namespace cmasi
} // end namespace afrl

