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
#include "afrl/cmasi/perceive/EntityPerception.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/PathWaypoint.h"


namespace afrl {
namespace cmasi {
namespace perceive {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string EntityPerception::Subscription = "afrl.cmasi.perceive.EntityPerception";
   const std::string EntityPerception::TypeName = "EntityPerception";
   const std::string EntityPerception::SeriesName = "PERCEIVE";
   const int64_t EntityPerception::SeriesId = 5784119745305990725LL;
   const uint16_t EntityPerception::SeriesVersion = 1;
   const uint32_t EntityPerception::TypeId = 1;
   
   bool isEntityPerception(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isEntityPerception(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5784119745305990725LL) return false;
      if(obj->getSeriesVersion() != 1) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > EntityPerceptionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   EntityPerception::EntityPerception(void) : avtas::lmcp::Object()
   {
      __PerceivedEntityID = 0;
      __PerceiverID = 0;
      for (uint32_t i=0; i<3; i++)
      {
         __Velocity[i] = 0.f;
      }
      for (uint32_t i=0; i<3; i++)
      {
         __VelocityError[i] = 0.f;
      }
      __VelocityValid = false;
      for (uint32_t i=0; i<3; i++)
      {
         __Attitude[i] = 0.f;
      }
      for (uint32_t i=0; i<3; i++)
      {
         __AttitudeError[i] = 0.f;
      }
      __AttitudeValid = false;
      __Location = new afrl::cmasi::Location3D();
      for (uint32_t i=0; i<3; i++)
      {
         __LocationError[i] = 0.f;
      }
      __TimeLastSeen = 0LL;

   }
     
   EntityPerception::EntityPerception(const EntityPerception &that) : avtas::lmcp::Object(that)
   {
        __PerceivedEntityID = that.__PerceivedEntityID;
        __PerceiverID = that.__PerceiverID;
        __PerceiverPayloads.clear();
        for (size_t i=0; i< that.__PerceiverPayloads.size(); i++)
        {
           __PerceiverPayloads.push_back( that.__PerceiverPayloads[i]);
        }
        for (uint32_t i=0; i<3; i++)
        {
           __Velocity[i] = that.__Velocity[i];
        }
        for (uint32_t i=0; i<3; i++)
        {
           __VelocityError[i] = that.__VelocityError[i];
        }
        __VelocityValid = that.__VelocityValid;
        for (uint32_t i=0; i<3; i++)
        {
           __Attitude[i] = that.__Attitude[i];
        }
        for (uint32_t i=0; i<3; i++)
        {
           __AttitudeError[i] = that.__AttitudeError[i];
        }
        __AttitudeValid = that.__AttitudeValid;
        __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
        for (uint32_t i=0; i<3; i++)
        {
           __LocationError[i] = that.__LocationError[i];
        }
        __TimeLastSeen = that.__TimeLastSeen;

   }
   
   EntityPerception & EntityPerception::operator=(const EntityPerception &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__Location != nullptr) delete __Location;

         __PerceivedEntityID = that.__PerceivedEntityID;
         __PerceiverID = that.__PerceiverID;
         __PerceiverPayloads.clear();
         for (size_t i=0; i< that.__PerceiverPayloads.size(); i++)
         {
            __PerceiverPayloads.push_back( that.__PerceiverPayloads[i]);
         }
         for (uint32_t i=0; i<3; i++)
         {
            __Velocity[i] = that.__Velocity[i];
         }
         for (uint32_t i=0; i<3; i++)
         {
            __VelocityError[i] = that.__VelocityError[i];
         }
         __VelocityValid = that.__VelocityValid;
         for (uint32_t i=0; i<3; i++)
         {
            __Attitude[i] = that.__Attitude[i];
         }
         for (uint32_t i=0; i<3; i++)
         {
            __AttitudeError[i] = that.__AttitudeError[i];
         }
         __AttitudeValid = that.__AttitudeValid;
         __Location = that.__Location == nullptr ? nullptr : that.__Location->clone();
         for (uint32_t i=0; i<3; i++)
         {
            __LocationError[i] = that.__LocationError[i];
         }
         __TimeLastSeen = that.__TimeLastSeen;

      }
      return *this;
   }

   EntityPerception* EntityPerception::clone() const
   {
        return new EntityPerception(*this);
   }
   
   EntityPerception::~EntityPerception(void)
   {
      if (__Location != nullptr) delete __Location;

   }
  
   void EntityPerception::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUInt(__PerceivedEntityID);
      buf.putUInt(__PerceiverID);
      buf.putUShort( static_cast<uint16_t>(__PerceiverPayloads.size()));
      for (size_t i=0; i<__PerceiverPayloads.size(); i++)
      {
         buf.putUInt(__PerceiverPayloads[i]);
      }
      for (uint32_t i=0; i<3; i++)
      {
         buf.putFloat(__Velocity[i]);
      }
      for (uint32_t i=0; i<3; i++)
      {
         buf.putFloat(__VelocityError[i]);
      }
      buf.putBool(__VelocityValid);
      for (uint32_t i=0; i<3; i++)
      {
         buf.putFloat(__Attitude[i]);
      }
      for (uint32_t i=0; i<3; i++)
      {
         buf.putFloat(__AttitudeError[i]);
      }
      buf.putBool(__AttitudeValid);
      assert(__Location != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __Location, buf);
      for (uint32_t i=0; i<3; i++)
      {
         buf.putFloat(__LocationError[i]);
      }
      buf.putLong(__TimeLastSeen);

   }
   
   void EntityPerception::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __PerceivedEntityID = buf.getUInt();
      __PerceiverID = buf.getUInt();
      __PerceiverPayloads.clear();
      uint16_t __PerceiverPayloads_length = buf.getUShort();
      for (uint32_t i=0; i< __PerceiverPayloads_length; i++)
      {
         __PerceiverPayloads.push_back(buf.getUInt() );
      }
      for (uint32_t i=0; i<3; i++)
      {
         __Velocity[i] = buf.getFloat();
      }
      for (uint32_t i=0; i<3; i++)
      {
         __VelocityError[i] = buf.getFloat();
      }
      __VelocityValid = buf.getBool();
      for (uint32_t i=0; i<3; i++)
      {
         __Attitude[i] = buf.getFloat();
      }
      for (uint32_t i=0; i<3; i++)
      {
         __AttitudeError[i] = buf.getFloat();
      }
      __AttitudeValid = buf.getBool();
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
      for (uint32_t i=0; i<3; i++)
      {
         __LocationError[i] = buf.getFloat();
      }
      __TimeLastSeen = buf.getLong();

   }

   uint32_t EntityPerception::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(uint32_t);
      size += sizeof(uint32_t);
      size += 2 + sizeof(uint32_t) * __PerceiverPayloads.size();
      size += sizeof(float) * 3;
      size += sizeof(float) * 3;
      size += sizeof(bool);
      size += sizeof(float) * 3;
      size += sizeof(float) * 3;
      size += sizeof(bool);
      size += (__Location != nullptr ? __Location->calculatePackedSize() + 15 : 1);
      size += sizeof(float) * 3;
      size += sizeof(int64_t);

      return size;
   }

   std::string EntityPerception::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( EntityPerception ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PerceivedEntityID (uint32_t) = " << __PerceivedEntityID << "\n";
      oss << indent << "PerceiverID (uint32_t) = " << __PerceiverID << "\n";
      oss << indent << "PerceiverPayloads (uint32 [ " << __PerceiverPayloads.size() << ", var ])\n";
      oss << indent << "Velocity (real32 [ " << __Velocity << " ])\n";
      oss << indent << "VelocityError (real32 [ " << __VelocityError << " ])\n";
      oss << indent << "VelocityValid (bool) = " << __VelocityValid << "\n";
      oss << indent << "Attitude (real32 [ " << __Attitude << " ])\n";
      oss << indent << "AttitudeError (real32 [ " << __AttitudeError << " ])\n";
      oss << indent << "AttitudeValid (bool) = " << __AttitudeValid << "\n";
      oss << indent << "Location (Location3D)";
      if (__Location == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "LocationError (real32 [ " << __LocationError << " ])\n";
      oss << indent << "TimeLastSeen (int64_t) = " << __TimeLastSeen << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string EntityPerception::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<EntityPerception Series=\"PERCEIVE\">\n";
      str << ws << "   <PerceivedEntityID>" << __PerceivedEntityID << "</PerceivedEntityID>\n";
      str << ws << "   <PerceiverID>" << __PerceiverID << "</PerceiverID>\n";
      str << ws << "   <PerceiverPayloads>\n";
      for (size_t i=0; i<__PerceiverPayloads.size(); i++)
      {
         str << ws << "   <uint32>" << __PerceiverPayloads[i] << "</uint32>\n";
      }
      str << ws << "   </PerceiverPayloads>\n";
      str << ws << "   <Velocity>\n";
      for (uint32_t i=0; i<3; i++)
      {
         str << ws << "   <real32>" << __Velocity[i] << "</real32>\n";
      }
      str << ws << "   </Velocity>\n";
      str << ws << "   <VelocityError>\n";
      for (uint32_t i=0; i<3; i++)
      {
         str << ws << "   <real32>" << __VelocityError[i] << "</real32>\n";
      }
      str << ws << "   </VelocityError>\n";
      str << ws << "   <VelocityValid>" << (__VelocityValid ? "true" : "false") << "</VelocityValid>\n";
      str << ws << "   <Attitude>\n";
      for (uint32_t i=0; i<3; i++)
      {
         str << ws << "   <real32>" << __Attitude[i] << "</real32>\n";
      }
      str << ws << "   </Attitude>\n";
      str << ws << "   <AttitudeError>\n";
      for (uint32_t i=0; i<3; i++)
      {
         str << ws << "   <real32>" << __AttitudeError[i] << "</real32>\n";
      }
      str << ws << "   </AttitudeError>\n";
      str << ws << "   <AttitudeValid>" << (__AttitudeValid ? "true" : "false") << "</AttitudeValid>\n";
      if (__Location != nullptr)
      {
         str << ws << "   <Location>";
         str << "\n" + __Location->toXML(depth + 1) + ws + "   ";
         str << "</Location>\n";
      }
      str << ws << "   <LocationError>\n";
      for (uint32_t i=0; i<3; i++)
      {
         str << ws << "   <real32>" << __LocationError[i] << "</real32>\n";
      }
      str << ws << "   </LocationError>\n";
      str << ws << "   <TimeLastSeen>" << __TimeLastSeen << "</TimeLastSeen>\n";
      str << ws << "</EntityPerception>\n";

      return str.str();
   }

   bool EntityPerception::operator==(const EntityPerception & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__PerceivedEntityID != that.__PerceivedEntityID) return false;
      if(__PerceiverID != that.__PerceiverID) return false;
      if(__PerceiverPayloads.size() != that.__PerceiverPayloads.size()) return false;
      for (size_t i=0; i<__PerceiverPayloads.size(); i++)
      {
         if(__PerceiverPayloads[i] != that.__PerceiverPayloads[i]) return false;
      }
      for (uint32_t i=0; i<3; i++)
      {
         if(__Velocity[i] != that.__Velocity[i]) return false;
      }
      for (uint32_t i=0; i<3; i++)
      {
         if(__VelocityError[i] != that.__VelocityError[i]) return false;
      }
      if(__VelocityValid != that.__VelocityValid) return false;
      for (uint32_t i=0; i<3; i++)
      {
         if(__Attitude[i] != that.__Attitude[i]) return false;
      }
      for (uint32_t i=0; i<3; i++)
      {
         if(__AttitudeError[i] != that.__AttitudeError[i]) return false;
      }
      if(__AttitudeValid != that.__AttitudeValid) return false;
      if(__Location && that.__Location)
      {
         if(__Location->getSeriesNameAsLong() != that.__Location->getSeriesNameAsLong()) return false;
         if(__Location->getSeriesVersion() != that.__Location->getSeriesVersion()) return false;
         if(__Location->getLmcpType() != that.__Location->getLmcpType()) return false;
         if( *(__Location) != *(that.__Location) ) return false;
      }
      else if(__Location != that.__Location) return false;
      for (uint32_t i=0; i<3; i++)
      {
         if(__LocationError[i] != that.__LocationError[i]) return false;
      }
      if(__TimeLastSeen != that.__TimeLastSeen) return false;
      return true;

   }

   bool EntityPerception::operator!=(const EntityPerception & that)
   {
      return( !(operator==(that)) );
   }

   EntityPerception& EntityPerception::setPerceivedEntityID(const uint32_t val)
   {
      __PerceivedEntityID = val;
      return *this;
   }

   EntityPerception& EntityPerception::setPerceiverID(const uint32_t val)
   {
      __PerceiverID = val;
      return *this;
   }




   EntityPerception& EntityPerception::setVelocityValid(const bool val)
   {
      __VelocityValid = val;
      return *this;
   }



   EntityPerception& EntityPerception::setAttitudeValid(const bool val)
   {
      __AttitudeValid = val;
      return *this;
   }

   EntityPerception& EntityPerception::setLocation(const afrl::cmasi::Location3D* const val)
   {
      if (__Location != nullptr) { delete __Location; __Location = nullptr; }
      if (val != nullptr) { __Location = const_cast< afrl::cmasi::Location3D* > (val); }
      return *this;
   }


   EntityPerception& EntityPerception::setTimeLastSeen(const int64_t val)
   {
      __TimeLastSeen = val;
      return *this;
   }


} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl

