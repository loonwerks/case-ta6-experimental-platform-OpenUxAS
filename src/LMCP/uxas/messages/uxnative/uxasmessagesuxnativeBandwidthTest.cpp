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
#include "uxas/messages/uxnative/BandwidthTest.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BandwidthTest::Subscription = "uxas.messages.uxnative.BandwidthTest";
   const std::string BandwidthTest::TypeName = "BandwidthTest";
   const std::string BandwidthTest::SeriesName = "UXNATIVE";
   const int64_t BandwidthTest::SeriesId = 6149751333668345413LL;
   const uint16_t BandwidthTest::SeriesVersion = 9;
   const uint32_t BandwidthTest::TypeId = 8;
   
   bool isBandwidthTest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   bool isBandwidthTest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   std::vector< std::string > BandwidthTestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BandwidthTest::BandwidthTest(void) : uxas::messages::uxnative::EntityLocation()
   {
      __MessageID = 0LL;
      __Payload = std::string("");

   }
     
   BandwidthTest::BandwidthTest(const BandwidthTest &that) : uxas::messages::uxnative::EntityLocation(that)
   {
        __MessageID = that.__MessageID;
        __Payload = that.__Payload;

   }
   
   BandwidthTest & BandwidthTest::operator=(const BandwidthTest &that)
   {
      if (this != &that)
      {
         uxas::messages::uxnative::EntityLocation::operator=(that);

         __MessageID = that.__MessageID;
         __Payload = that.__Payload;

      }
      return *this;
   }

   BandwidthTest* BandwidthTest::clone() const
   {
        return new BandwidthTest(*this);
   }
   
   BandwidthTest::~BandwidthTest(void)
   {

   }
  
   void BandwidthTest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      uxas::messages::uxnative::EntityLocation::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__MessageID);
      buf.putString(__Payload);

   }
   
   void BandwidthTest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      uxas::messages::uxnative::EntityLocation::unpack(buf);
      // Copy the buffer into the class
      __MessageID = buf.getLong();
      __Payload = buf.getString();

   }

   uint32_t BandwidthTest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += uxas::messages::uxnative::EntityLocation::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __Payload.length();

      return size;
   }

   std::string BandwidthTest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BandwidthTest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityID (int64_t) = " << __EntityID << "\n";
      oss << indent << "Position (Location3D)";
      if (__Position == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "Time (int64_t) = " << __Time << "\n";

      oss << indent << "MessageID (int64_t) = " << __MessageID << "\n";
      oss << indent << "Payload (std::string) = " << __Payload << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BandwidthTest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BandwidthTest Series=\"UXNATIVE\">\n";
      str << ws << "   <MessageID>" << __MessageID << "</MessageID>\n";
      str << ws << "   <Payload>" << __Payload << "</Payload>\n";
      str << ws << "   <EntityID>" << __EntityID << "</EntityID>\n";
      if (__Position != nullptr)
      {
         str << ws << "   <Position>";
         str << "\n" + __Position->toXML(depth + 1) + ws + "   ";
         str << "</Position>\n";
      }
      str << ws << "   <Time>" << __Time << "</Time>\n";
      str << ws << "</BandwidthTest>\n";

      return str.str();
   }

   bool BandwidthTest::operator==(const BandwidthTest & that)
   {
      if( uxas::messages::uxnative::EntityLocation::operator!=(that) )
      {
          return false;
      }
      if(__MessageID != that.__MessageID) return false;
      if(__Payload != that.__Payload) return false;
      return true;

   }

   bool BandwidthTest::operator!=(const BandwidthTest & that)
   {
      return( !(operator==(that)) );
   }

   BandwidthTest& BandwidthTest::setMessageID(const int64_t val)
   {
      __MessageID = val;
      return *this;
   }

   BandwidthTest& BandwidthTest::setPayload(const std::string val)
   {
      __Payload = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

