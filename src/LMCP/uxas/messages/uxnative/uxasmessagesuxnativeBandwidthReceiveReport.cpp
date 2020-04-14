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
#include "uxas/messages/uxnative/BandwidthReceiveReport.h"
#include "uxas/messages/uxnative/BandwidthTest.h"
#include "uxas/messages/uxnative/BandwidthTest.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BandwidthReceiveReport::Subscription = "uxas.messages.uxnative.BandwidthReceiveReport";
   const std::string BandwidthReceiveReport::TypeName = "BandwidthReceiveReport";
   const std::string BandwidthReceiveReport::SeriesName = "UXNATIVE";
   const int64_t BandwidthReceiveReport::SeriesId = 6149751333668345413LL;
   const uint16_t BandwidthReceiveReport::SeriesVersion = 9;
   const uint32_t BandwidthReceiveReport::TypeId = 9;
   
   bool isBandwidthReceiveReport(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   bool isBandwidthReceiveReport(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   std::vector< std::string > BandwidthReceiveReportDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BandwidthReceiveReport::BandwidthReceiveReport(void) : avtas::lmcp::Object()
   {
      __EntitySender = new uxas::messages::uxnative::EntityLocation();
      __EntityReceiver = new uxas::messages::uxnative::EntityLocation();
      __TransferPayloadSize = 0;

   }
     
   BandwidthReceiveReport::BandwidthReceiveReport(const BandwidthReceiveReport &that) : avtas::lmcp::Object(that)
   {
        __EntitySender = that.__EntitySender == nullptr ? nullptr : that.__EntitySender->clone();
        __EntityReceiver = that.__EntityReceiver == nullptr ? nullptr : that.__EntityReceiver->clone();
        __TransferPayloadSize = that.__TransferPayloadSize;

   }
   
   BandwidthReceiveReport & BandwidthReceiveReport::operator=(const BandwidthReceiveReport &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         if (__EntitySender != nullptr) delete __EntitySender;
         if (__EntityReceiver != nullptr) delete __EntityReceiver;

         __EntitySender = that.__EntitySender == nullptr ? nullptr : that.__EntitySender->clone();
         __EntityReceiver = that.__EntityReceiver == nullptr ? nullptr : that.__EntityReceiver->clone();
         __TransferPayloadSize = that.__TransferPayloadSize;

      }
      return *this;
   }

   BandwidthReceiveReport* BandwidthReceiveReport::clone() const
   {
        return new BandwidthReceiveReport(*this);
   }
   
   BandwidthReceiveReport::~BandwidthReceiveReport(void)
   {
      if (__EntitySender != nullptr) delete __EntitySender;
      if (__EntityReceiver != nullptr) delete __EntityReceiver;

   }
  
   void BandwidthReceiveReport::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      assert(__EntitySender != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EntitySender, buf);
      assert(__EntityReceiver != nullptr);
      avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __EntityReceiver, buf);
      buf.putUInt(__TransferPayloadSize);

   }
   
   void BandwidthReceiveReport::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      {
         if (__EntitySender != nullptr) delete __EntitySender;
         __EntitySender = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __EntitySender = (uxas::messages::uxnative::EntityLocation*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__EntitySender != nullptr) __EntitySender->unpack(buf);
            else assert(__EntitySender != nullptr);
         }
      }
      {
         if (__EntityReceiver != nullptr) delete __EntityReceiver;
         __EntityReceiver = nullptr;
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            __EntityReceiver = (uxas::messages::uxnative::EntityLocation*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if (__EntityReceiver != nullptr) __EntityReceiver->unpack(buf);
            else assert(__EntityReceiver != nullptr);
         }
      }
      __TransferPayloadSize = buf.getUInt();

   }

   uint32_t BandwidthReceiveReport::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += (__EntitySender != nullptr ? __EntitySender->calculatePackedSize() + 15 : 1);
      size += (__EntityReceiver != nullptr ? __EntityReceiver->calculatePackedSize() + 15 : 1);
      size += sizeof(uint32_t);

      return size;
   }

   std::string BandwidthReceiveReport::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BandwidthReceiveReport ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntitySender (EntityLocation)";
      if (__EntitySender == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "EntityReceiver (EntityLocation)";
      if (__EntityReceiver == nullptr)
         oss << " = nullptr";
      oss << "\n";
      oss << indent << "TransferPayloadSize (uint32_t) = " << __TransferPayloadSize << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BandwidthReceiveReport::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BandwidthReceiveReport Series=\"UXNATIVE\">\n";
      if (__EntitySender != nullptr)
      {
         str << ws << "   <EntitySender>";
         str << "\n" + __EntitySender->toXML(depth + 1) + ws + "   ";
         str << "</EntitySender>\n";
      }
      if (__EntityReceiver != nullptr)
      {
         str << ws << "   <EntityReceiver>";
         str << "\n" + __EntityReceiver->toXML(depth + 1) + ws + "   ";
         str << "</EntityReceiver>\n";
      }
      str << ws << "   <TransferPayloadSize>" << __TransferPayloadSize << "</TransferPayloadSize>\n";
      str << ws << "</BandwidthReceiveReport>\n";

      return str.str();
   }

   bool BandwidthReceiveReport::operator==(const BandwidthReceiveReport & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntitySender && that.__EntitySender)
      {
         if(__EntitySender->getSeriesNameAsLong() != that.__EntitySender->getSeriesNameAsLong()) return false;
         if(__EntitySender->getSeriesVersion() != that.__EntitySender->getSeriesVersion()) return false;
         if(__EntitySender->getLmcpType() != that.__EntitySender->getLmcpType()) return false;
         if( *(__EntitySender) != *(that.__EntitySender) ) return false;
      }
      else if(__EntitySender != that.__EntitySender) return false;
      if(__EntityReceiver && that.__EntityReceiver)
      {
         if(__EntityReceiver->getSeriesNameAsLong() != that.__EntityReceiver->getSeriesNameAsLong()) return false;
         if(__EntityReceiver->getSeriesVersion() != that.__EntityReceiver->getSeriesVersion()) return false;
         if(__EntityReceiver->getLmcpType() != that.__EntityReceiver->getLmcpType()) return false;
         if( *(__EntityReceiver) != *(that.__EntityReceiver) ) return false;
      }
      else if(__EntityReceiver != that.__EntityReceiver) return false;
      if(__TransferPayloadSize != that.__TransferPayloadSize) return false;
      return true;

   }

   bool BandwidthReceiveReport::operator!=(const BandwidthReceiveReport & that)
   {
      return( !(operator==(that)) );
   }

   BandwidthReceiveReport& BandwidthReceiveReport::setEntitySender(const uxas::messages::uxnative::EntityLocation* const val)
   {
      if (__EntitySender != nullptr) { delete __EntitySender; __EntitySender = nullptr; }
      if (val != nullptr) { __EntitySender = const_cast< uxas::messages::uxnative::EntityLocation* > (val); }
      return *this;
   }

   BandwidthReceiveReport& BandwidthReceiveReport::setEntityReceiver(const uxas::messages::uxnative::EntityLocation* const val)
   {
      if (__EntityReceiver != nullptr) { delete __EntityReceiver; __EntityReceiver = nullptr; }
      if (val != nullptr) { __EntityReceiver = const_cast< uxas::messages::uxnative::EntityLocation* > (val); }
      return *this;
   }

   BandwidthReceiveReport& BandwidthReceiveReport::setTransferPayloadSize(const uint32_t val)
   {
      __TransferPayloadSize = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

