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
#include "uxas/messages/uxnative/KillService.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string KillService::Subscription = "uxas.messages.uxnative.KillService";
   const std::string KillService::TypeName = "KillService";
   const std::string KillService::SeriesName = "UXNATIVE";
   const int64_t KillService::SeriesId = 6149751333668345413LL;
   const uint16_t KillService::SeriesVersion = 9;
   const uint32_t KillService::TypeId = 4;
   
   bool isKillService(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   bool isKillService(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   std::vector< std::string > KillServiceDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   KillService::KillService(void) : avtas::lmcp::Object()
   {
      __ServiceID = 0LL;

   }
     
   KillService::KillService(const KillService &that) : avtas::lmcp::Object(that)
   {
        __ServiceID = that.__ServiceID;

   }
   
   KillService & KillService::operator=(const KillService &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __ServiceID = that.__ServiceID;

      }
      return *this;
   }

   KillService* KillService::clone() const
   {
        return new KillService(*this);
   }
   
   KillService::~KillService(void)
   {

   }
  
   void KillService::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__ServiceID);

   }
   
   void KillService::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __ServiceID = buf.getLong();

   }

   uint32_t KillService::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string KillService::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( KillService ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "ServiceID (int64_t) = " << __ServiceID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string KillService::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<KillService Series=\"UXNATIVE\">\n";
      str << ws << "   <ServiceID>" << __ServiceID << "</ServiceID>\n";
      str << ws << "</KillService>\n";

      return str.str();
   }

   bool KillService::operator==(const KillService & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__ServiceID != that.__ServiceID) return false;
      return true;

   }

   bool KillService::operator!=(const KillService & that)
   {
      return( !(operator==(that)) );
   }

   KillService& KillService::setServiceID(const int64_t val)
   {
      __ServiceID = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

