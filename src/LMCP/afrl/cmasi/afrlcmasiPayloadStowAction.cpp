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
#include "afrl/cmasi/PayloadStowAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PayloadStowAction::Subscription = "afrl.cmasi.PayloadStowAction";
   const std::string PayloadStowAction::TypeName = "PayloadStowAction";
   const std::string PayloadStowAction::SeriesName = "CMASI";
   const int64_t PayloadStowAction::SeriesId = 4849604199710720000LL;
   const uint16_t PayloadStowAction::SeriesVersion = 3;
   const uint32_t PayloadStowAction::TypeId = 60;
   
   bool isPayloadStowAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 60) return false;
      return true;
   }
   
   bool isPayloadStowAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 60) return false;
      return true;
   }
   
   std::vector< std::string > PayloadStowActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PayloadStowAction::PayloadStowAction(void) : avtas::lmcp::Object()
   {
      __PayloadID = 0LL;

   }
     
   PayloadStowAction::PayloadStowAction(const PayloadStowAction &that) : avtas::lmcp::Object(that)
   {
        __PayloadID = that.__PayloadID;

   }
   
   PayloadStowAction & PayloadStowAction::operator=(const PayloadStowAction &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __PayloadID = that.__PayloadID;

      }
      return *this;
   }

   PayloadStowAction* PayloadStowAction::clone() const
   {
        return new PayloadStowAction(*this);
   }
   
   PayloadStowAction::~PayloadStowAction(void)
   {

   }
  
   void PayloadStowAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__PayloadID);

   }
   
   void PayloadStowAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __PayloadID = buf.getLong();

   }

   uint32_t PayloadStowAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string PayloadStowAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PayloadStowAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PayloadStowAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PayloadStowAction Series=\"CMASI\">\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "</PayloadStowAction>\n";

      return str.str();
   }

   bool PayloadStowAction::operator==(const PayloadStowAction & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__PayloadID != that.__PayloadID) return false;
      return true;

   }

   bool PayloadStowAction::operator!=(const PayloadStowAction & that)
   {
      return( !(operator==(that)) );
   }

   PayloadStowAction& PayloadStowAction::setPayloadID(const int64_t val)
   {
      __PayloadID = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

