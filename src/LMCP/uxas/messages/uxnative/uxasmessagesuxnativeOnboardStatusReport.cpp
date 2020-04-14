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
#include "uxas/messages/uxnative/OnboardStatusReport.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string OnboardStatusReport::Subscription = "uxas.messages.uxnative.OnboardStatusReport";
   const std::string OnboardStatusReport::TypeName = "OnboardStatusReport";
   const std::string OnboardStatusReport::SeriesName = "UXNATIVE";
   const int64_t OnboardStatusReport::SeriesId = 6149751333668345413LL;
   const uint16_t OnboardStatusReport::SeriesVersion = 9;
   const uint32_t OnboardStatusReport::TypeId = 13;
   
   bool isOnboardStatusReport(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   bool isOnboardStatusReport(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 13) return false;
      return true;
   }
   
   std::vector< std::string > OnboardStatusReportDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   OnboardStatusReport::OnboardStatusReport(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __ValidState = false;
      __ValidAuthorization = false;
      __SpeedAuthorization = false;
      __GimbalAuthorization = false;
      __VehicleTime = 0LL;

   }
     
   OnboardStatusReport::OnboardStatusReport(const OnboardStatusReport &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __ConnectedEntities.clear();
        for (size_t i=0; i< that.__ConnectedEntities.size(); i++)
        {
           __ConnectedEntities.push_back( that.__ConnectedEntities[i]);
        }
        __CurrentTaskList.clear();
        for (size_t i=0; i< that.__CurrentTaskList.size(); i++)
        {
           __CurrentTaskList.push_back( that.__CurrentTaskList[i]);
        }
        __ValidState = that.__ValidState;
        __ValidAuthorization = that.__ValidAuthorization;
        __SpeedAuthorization = that.__SpeedAuthorization;
        __GimbalAuthorization = that.__GimbalAuthorization;
        __VehicleTime = that.__VehicleTime;

   }
   
   OnboardStatusReport & OnboardStatusReport::operator=(const OnboardStatusReport &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;
         __ConnectedEntities.clear();
         for (size_t i=0; i< that.__ConnectedEntities.size(); i++)
         {
            __ConnectedEntities.push_back( that.__ConnectedEntities[i]);
         }
         __CurrentTaskList.clear();
         for (size_t i=0; i< that.__CurrentTaskList.size(); i++)
         {
            __CurrentTaskList.push_back( that.__CurrentTaskList[i]);
         }
         __ValidState = that.__ValidState;
         __ValidAuthorization = that.__ValidAuthorization;
         __SpeedAuthorization = that.__SpeedAuthorization;
         __GimbalAuthorization = that.__GimbalAuthorization;
         __VehicleTime = that.__VehicleTime;

      }
      return *this;
   }

   OnboardStatusReport* OnboardStatusReport::clone() const
   {
        return new OnboardStatusReport(*this);
   }
   
   OnboardStatusReport::~OnboardStatusReport(void)
   {

   }
  
   void OnboardStatusReport::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putUShort( static_cast<uint16_t>(__ConnectedEntities.size()));
      for (size_t i=0; i<__ConnectedEntities.size(); i++)
      {
         buf.putLong(__ConnectedEntities[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__CurrentTaskList.size()));
      for (size_t i=0; i<__CurrentTaskList.size(); i++)
      {
         buf.putLong(__CurrentTaskList[i]);
      }
      buf.putBool(__ValidState);
      buf.putBool(__ValidAuthorization);
      buf.putBool(__SpeedAuthorization);
      buf.putBool(__GimbalAuthorization);
      buf.putLong(__VehicleTime);

   }
   
   void OnboardStatusReport::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __ConnectedEntities.clear();
      uint16_t __ConnectedEntities_length = buf.getUShort();
      for (uint32_t i=0; i< __ConnectedEntities_length; i++)
      {
         __ConnectedEntities.push_back(buf.getLong() );
      }
      __CurrentTaskList.clear();
      uint16_t __CurrentTaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __CurrentTaskList_length; i++)
      {
         __CurrentTaskList.push_back(buf.getLong() );
      }
      __ValidState = buf.getBool();
      __ValidAuthorization = buf.getBool();
      __SpeedAuthorization = buf.getBool();
      __GimbalAuthorization = buf.getBool();
      __VehicleTime = buf.getLong();

   }

   uint32_t OnboardStatusReport::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __ConnectedEntities.size();
      size += 2 + sizeof(int64_t) * __CurrentTaskList.size();
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(bool);
      size += sizeof(int64_t);

      return size;
   }

   std::string OnboardStatusReport::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( OnboardStatusReport ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "ConnectedEntities (int64 [ " << __ConnectedEntities.size() << ", var ])\n";
      oss << indent << "CurrentTaskList (int64 [ " << __CurrentTaskList.size() << ", var ])\n";
      oss << indent << "ValidState (bool) = " << __ValidState << "\n";
      oss << indent << "ValidAuthorization (bool) = " << __ValidAuthorization << "\n";
      oss << indent << "SpeedAuthorization (bool) = " << __SpeedAuthorization << "\n";
      oss << indent << "GimbalAuthorization (bool) = " << __GimbalAuthorization << "\n";
      oss << indent << "VehicleTime (int64_t) = " << __VehicleTime << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string OnboardStatusReport::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<OnboardStatusReport Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <ConnectedEntities>\n";
      for (size_t i=0; i<__ConnectedEntities.size(); i++)
      {
         str << ws << "   <int64>" << __ConnectedEntities[i] << "</int64>\n";
      }
      str << ws << "   </ConnectedEntities>\n";
      str << ws << "   <CurrentTaskList>\n";
      for (size_t i=0; i<__CurrentTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __CurrentTaskList[i] << "</int64>\n";
      }
      str << ws << "   </CurrentTaskList>\n";
      str << ws << "   <ValidState>" << (__ValidState ? "true" : "false") << "</ValidState>\n";
      str << ws << "   <ValidAuthorization>" << (__ValidAuthorization ? "true" : "false") << "</ValidAuthorization>\n";
      str << ws << "   <SpeedAuthorization>" << (__SpeedAuthorization ? "true" : "false") << "</SpeedAuthorization>\n";
      str << ws << "   <GimbalAuthorization>" << (__GimbalAuthorization ? "true" : "false") << "</GimbalAuthorization>\n";
      str << ws << "   <VehicleTime>" << __VehicleTime << "</VehicleTime>\n";
      str << ws << "</OnboardStatusReport>\n";

      return str.str();
   }

   bool OnboardStatusReport::operator==(const OnboardStatusReport & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__ConnectedEntities.size() != that.__ConnectedEntities.size()) return false;
      for (size_t i=0; i<__ConnectedEntities.size(); i++)
      {
         if(__ConnectedEntities[i] != that.__ConnectedEntities[i]) return false;
      }
      if(__CurrentTaskList.size() != that.__CurrentTaskList.size()) return false;
      for (size_t i=0; i<__CurrentTaskList.size(); i++)
      {
         if(__CurrentTaskList[i] != that.__CurrentTaskList[i]) return false;
      }
      if(__ValidState != that.__ValidState) return false;
      if(__ValidAuthorization != that.__ValidAuthorization) return false;
      if(__SpeedAuthorization != that.__SpeedAuthorization) return false;
      if(__GimbalAuthorization != that.__GimbalAuthorization) return false;
      if(__VehicleTime != that.__VehicleTime) return false;
      return true;

   }

   bool OnboardStatusReport::operator!=(const OnboardStatusReport & that)
   {
      return( !(operator==(that)) );
   }

   OnboardStatusReport& OnboardStatusReport::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }



   OnboardStatusReport& OnboardStatusReport::setValidState(const bool val)
   {
      __ValidState = val;
      return *this;
   }

   OnboardStatusReport& OnboardStatusReport::setValidAuthorization(const bool val)
   {
      __ValidAuthorization = val;
      return *this;
   }

   OnboardStatusReport& OnboardStatusReport::setSpeedAuthorization(const bool val)
   {
      __SpeedAuthorization = val;
      return *this;
   }

   OnboardStatusReport& OnboardStatusReport::setGimbalAuthorization(const bool val)
   {
      __GimbalAuthorization = val;
      return *this;
   }

   OnboardStatusReport& OnboardStatusReport::setVehicleTime(const int64_t val)
   {
      __VehicleTime = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

