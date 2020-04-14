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
#include "uxas/messages/uxnative/StartupComplete.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string StartupComplete::Subscription = "uxas.messages.uxnative.StartupComplete";
   const std::string StartupComplete::TypeName = "StartupComplete";
   const std::string StartupComplete::SeriesName = "UXNATIVE";
   const int64_t StartupComplete::SeriesId = 6149751333668345413LL;
   const uint16_t StartupComplete::SeriesVersion = 9;
   const uint32_t StartupComplete::TypeId = 2;
   
   bool isStartupComplete(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   bool isStartupComplete(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 2) return false;
      return true;
   }
   
   std::vector< std::string > StartupCompleteDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   StartupComplete::StartupComplete(void) : avtas::lmcp::Object()
   {

   }
     
   StartupComplete::StartupComplete(const StartupComplete &that) : avtas::lmcp::Object(that)
   {

   }
   
   StartupComplete & StartupComplete::operator=(const StartupComplete &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);


      }
      return *this;
   }

   StartupComplete* StartupComplete::clone() const
   {
        return new StartupComplete(*this);
   }
   
   StartupComplete::~StartupComplete(void)
   {

   }
  
   void StartupComplete::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer

   }
   
   void StartupComplete::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t StartupComplete::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();

      return size;
   }

   std::string StartupComplete::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( StartupComplete ) {\n";
      indent = std::string((++depth)*3, ' ');

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string StartupComplete::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<StartupComplete Series=\"UXNATIVE\">\n";
      str << ws << "</StartupComplete>\n";

      return str.str();
   }

   bool StartupComplete::operator==(const StartupComplete & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool StartupComplete::operator!=(const StartupComplete & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

