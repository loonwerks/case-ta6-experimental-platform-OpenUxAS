// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_BANDWIDTHRECEIVEREPORT_H_
#define _UXAS_MESSAGES_UXNATIVE_BANDWIDTHRECEIVEREPORT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/uxnative/EntityLocation.h"
#include "uxas/messages/uxnative/EntityLocation.h"



namespace uxas {
namespace messages {
namespace uxnative {


   bool isBandwidthReceiveReport(avtas::lmcp::Object* obj);
   bool isBandwidthReceiveReport(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > BandwidthReceiveReportDescendants();
   
   class BandwidthReceiveReport : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      BandwidthReceiveReport(void);

      // Copy Constructor
      BandwidthReceiveReport(const BandwidthReceiveReport &that);

      // Assignment Operator
      BandwidthReceiveReport & operator=(const BandwidthReceiveReport &that);

      // Destructor
      virtual ~BandwidthReceiveReport(void);

      // Equals overload
      bool operator==(const BandwidthReceiveReport & that);
      bool operator!=(const BandwidthReceiveReport & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual BandwidthReceiveReport* clone() const;

      // Returns string representation of object
      virtual std::string toString(int32_t depth=0) const;

      // Returns an XML string representation of the object.
      virtual std::string toXML(int32_t depth=0);

      // Returns object type id
      virtual uint32_t getLmcpType(void) const { return TypeId; }
	  
      // Returns object type name string
      virtual std::string getLmcpTypeName(void) const { return TypeName; }
	  
      // Returns object type name string with full namespace prepended, same as subscription name
      virtual std::string getFullLmcpTypeName(void) const { return Subscription; }

      // Returns series name string
      virtual std::string getSeriesName(void) const { return SeriesName; }

      // gets the series name as a long value
      virtual int64_t getSeriesNameAsLong(void) const { return SeriesId; }

      //gets the version number of the series
      virtual uint16_t getSeriesVersion(void) const { return SeriesVersion; }

      // Accessors and Modifiers
      /** Entity from which the message was sent. A valid BandwidthReceiveReport must define EntitySender (null not allowed). (Units: None)*/
      uxas::messages::uxnative::EntityLocation* const getEntitySender(void) { return __EntitySender; }
      BandwidthReceiveReport& setEntitySender(const uxas::messages::uxnative::EntityLocation* const val);

      /** Entity which received the message. A valid BandwidthReceiveReport must define EntityReceiver (null not allowed). (Units: None)*/
      uxas::messages::uxnative::EntityLocation* const getEntityReceiver(void) { return __EntityReceiver; }
      BandwidthReceiveReport& setEntityReceiver(const uxas::messages::uxnative::EntityLocation* const val);

      /** Size of the message that was received (Units: None)*/
      uint32_t getTransferPayloadSize(void) const { return __TransferPayloadSize; }
      BandwidthReceiveReport& setTransferPayloadSize(const uint32_t val);



   protected:
      /** Entity from which the message was sent. A valid BandwidthReceiveReport must define EntitySender (null not allowed). */
      uxas::messages::uxnative::EntityLocation* __EntitySender;
      /** Entity which received the message. A valid BandwidthReceiveReport must define EntityReceiver (null not allowed). */
      uxas::messages::uxnative::EntityLocation* __EntityReceiver;
      /** Size of the message that was received */
      uint32_t __TransferPayloadSize;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_BANDWIDTHRECEIVEREPORT_H_
