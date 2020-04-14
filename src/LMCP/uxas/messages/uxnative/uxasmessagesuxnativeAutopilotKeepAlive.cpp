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
#include "uxas/messages/uxnative/AutopilotKeepAlive.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AutopilotKeepAlive::Subscription = "uxas.messages.uxnative.AutopilotKeepAlive";
   const std::string AutopilotKeepAlive::TypeName = "AutopilotKeepAlive";
   const std::string AutopilotKeepAlive::SeriesName = "UXNATIVE";
   const int64_t AutopilotKeepAlive::SeriesId = 6149751333668345413LL;
   const uint16_t AutopilotKeepAlive::SeriesVersion = 9;
   const uint32_t AutopilotKeepAlive::TypeId = 12;
   
   bool isAutopilotKeepAlive(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   bool isAutopilotKeepAlive(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   std::vector< std::string > AutopilotKeepAliveDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AutopilotKeepAlive::AutopilotKeepAlive(void) : avtas::lmcp::Object()
   {
      __AutopilotEnabled = true;
      __SpeedAuthorized = true;
      __GimbalEnabled = true;
      __TimeSent = 0LL;
      __SpeedOverride = -1.0f;
      __AltOverride = -1.0f;

   }
     
   AutopilotKeepAlive::AutopilotKeepAlive(const AutopilotKeepAlive &that) : avtas::lmcp::Object(that)
   {
        __AutopilotEnabled = that.__AutopilotEnabled;
        __SpeedAuthorized = that.__SpeedAuthorized;
        __GimbalEnabled = that.__GimbalEnabled;
        __TimeSent = that.__TimeSent;
        __SpeedOverride = that.__SpeedOverride;
        __AltOverride = that.__AltOverride;

   }
   
   AutopilotKeepAlive & AutopilotKeepAlive::operator=(const AutopilotKeepAlive &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __AutopilotEnabled = that.__AutopilotEnabled;
         __SpeedAuthorized = that.__SpeedAuthorized;
         __GimbalEnabled = that.__GimbalEnabled;
         __TimeSent = that.__TimeSent;
         __SpeedOverride = that.__SpeedOverride;
         __AltOverride = that.__AltOverride;

      }
      return *this;
   }

   AutopilotKeepAlive* AutopilotKeepAlive::clone() const
   {
        return new AutopilotKeepAlive(*this);
   }
   
   AutopilotKeepAlive::~AutopilotKeepAlive(void)
   {

   }
  
   void AutopilotKeepAlive::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putBool(__AutopilotEnabled);
      buf.putBool(__SpeedAuthorized);
      buf.putBool(__GimbalEnabled);
      buf.putLong(__TimeSent);
      buf.putFloat(__SpeedOverride);
      buf.putFloat(__AltOverride);

   }
   
   void AutopilotKeepAlive::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __AutopilotEnabled = buf.getBool();
      __SpeedAuthorized = buf.getBool();
      __GimbalEnabled = buf.getBool();
      __TimeSent = buf.getLong();
      __SpeedOverride = buf.getFloat();
      __AltOverride = buf.getFloat();

   }

   uint32_t AutopilotKeepAlive::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(int64_t);
      size += sizeof(float);
      size += sizeof(float);

      return size;
   }

   std::string AutopilotKeepAlive::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AutopilotKeepAlive ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AutopilotEnabled (bool) = " << __AutopilotEnabled << "\n";
      oss << indent << "SpeedAuthorized (bool) = " << __SpeedAuthorized << "\n";
      oss << indent << "GimbalEnabled (bool) = " << __GimbalEnabled << "\n";
      oss << indent << "TimeSent (int64_t) = " << __TimeSent << "\n";
      oss << indent << "SpeedOverride (float) = " << __SpeedOverride << "\n";
      oss << indent << "AltOverride (float) = " << __AltOverride << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AutopilotKeepAlive::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AutopilotKeepAlive Series=\"UXNATIVE\">\n";
      str << ws << "   <AutopilotEnabled>" << (__AutopilotEnabled ? "true" : "false") << "</AutopilotEnabled>\n";
      str << ws << "   <SpeedAuthorized>" << (__SpeedAuthorized ? "true" : "false") << "</SpeedAuthorized>\n";
      str << ws << "   <GimbalEnabled>" << (__GimbalEnabled ? "true" : "false") << "</GimbalEnabled>\n";
      str << ws << "   <TimeSent>" << __TimeSent << "</TimeSent>\n";
      str << ws << "   <SpeedOverride>" << __SpeedOverride << "</SpeedOverride>\n";
      str << ws << "   <AltOverride>" << __AltOverride << "</AltOverride>\n";
      str << ws << "</AutopilotKeepAlive>\n";

      return str.str();
   }

   bool AutopilotKeepAlive::operator==(const AutopilotKeepAlive & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__AutopilotEnabled != that.__AutopilotEnabled) return false;
      if(__SpeedAuthorized != that.__SpeedAuthorized) return false;
      if(__GimbalEnabled != that.__GimbalEnabled) return false;
      if(__TimeSent != that.__TimeSent) return false;
      if(__SpeedOverride != that.__SpeedOverride) return false;
      if(__AltOverride != that.__AltOverride) return false;
      return true;

   }

   bool AutopilotKeepAlive::operator!=(const AutopilotKeepAlive & that)
   {
      return( !(operator==(that)) );
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setAutopilotEnabled(const bool val)
   {
      __AutopilotEnabled = val;
      return *this;
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setSpeedAuthorized(const bool val)
   {
      __SpeedAuthorized = val;
      return *this;
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setGimbalEnabled(const bool val)
   {
      __GimbalEnabled = val;
      return *this;
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setTimeSent(const int64_t val)
   {
      __TimeSent = val;
      return *this;
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setSpeedOverride(const float val)
   {
      __SpeedOverride = val;
      return *this;
   }

   AutopilotKeepAlive& AutopilotKeepAlive::setAltOverride(const float val)
   {
      __AltOverride = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

