// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_PAYLOADCONFIGURATION_H_
#define _AFRL_CMASI_PAYLOADCONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isPayloadConfiguration(avtas::lmcp::Object* obj);
   bool isPayloadConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PayloadConfigurationDescendants();
   
   class PayloadConfiguration : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PayloadConfiguration(void);

      // Copy Constructor
      PayloadConfiguration(const PayloadConfiguration &that);

      // Assignment Operator
      PayloadConfiguration & operator=(const PayloadConfiguration &that);

      // Destructor
      virtual ~PayloadConfiguration(void);

      // Equals overload
      bool operator==(const PayloadConfiguration & that);
      bool operator!=(const PayloadConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PayloadConfiguration* clone() const;

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
      /** The unique id for this payload item. (Units: None)*/
      int64_t getPayloadID(void) const { return __PayloadID; }
      PayloadConfiguration& setPayloadID(const int64_t val);

      /** A string uniquely identifying the kind of payload item (primarily to be used for debugging purposes). (Units: None)*/
      std::string getPayloadKind(void) const { return __PayloadKind; }
      PayloadConfiguration& setPayloadKind(const std::string val);

      /** Optional parameters associated with payload configuration (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getParameters(void) { return __Parameters; }



   protected:
      /** The unique id for this payload item. */
      int64_t __PayloadID;
      /** A string uniquely identifying the kind of payload item (primarily to be used for debugging purposes). */
      std::string __PayloadKind;
      /** Optional parameters associated with payload configuration */
      std::vector< afrl::cmasi::KeyValuePair* > __Parameters;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_PAYLOADCONFIGURATION_H_
