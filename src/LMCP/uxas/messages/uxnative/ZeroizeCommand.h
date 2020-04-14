// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_ZEROIZECOMMAND_H_
#define _UXAS_MESSAGES_UXNATIVE_ZEROIZECOMMAND_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"



namespace uxas {
namespace messages {
namespace uxnative {


   bool isZeroizeCommand(avtas::lmcp::Object* obj);
   bool isZeroizeCommand(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ZeroizeCommandDescendants();
   
   class ZeroizeCommand : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ZeroizeCommand(void);

      // Copy Constructor
      ZeroizeCommand(const ZeroizeCommand &that);

      // Assignment Operator
      ZeroizeCommand & operator=(const ZeroizeCommand &that);

      // Destructor
      virtual ~ZeroizeCommand(void);

      // Equals overload
      bool operator==(const ZeroizeCommand & that);
      bool operator!=(const ZeroizeCommand & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ZeroizeCommand* clone() const;

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
      /** The identity of the entity to be zeroized (Units: None)*/
      int64_t getEntityID(void) const { return __EntityID; }
      ZeroizeCommand& setEntityID(const int64_t val);

      /** Zeroize cryptographic key stores? (Units: None)*/
      bool getZeroizeKeys(void) const { return __ZeroizeKeys; }
      ZeroizeCommand& setZeroizeKeys(const bool val);

      /** Zeroize vehicle log stores? (Units: None)*/
      bool getZeroizeLogs(void) const { return __ZeroizeLogs; }
      ZeroizeCommand& setZeroizeLogs(const bool val);

      /** Zeroize collected data stores? (Units: None)*/
      bool getZeroizeData(void) const { return __ZeroizeData; }
      ZeroizeCommand& setZeroizeData(const bool val);

      /** Zeroize task queues? (Units: None)*/
      bool getZeroizeTasks(void) const { return __ZeroizeTasks; }
      ZeroizeCommand& setZeroizeTasks(const bool val);



   protected:
      /** The identity of the entity to be zeroized */
      int64_t __EntityID;
      /** Zeroize cryptographic key stores? */
      bool __ZeroizeKeys;
      /** Zeroize vehicle log stores? */
      bool __ZeroizeLogs;
      /** Zeroize collected data stores? */
      bool __ZeroizeData;
      /** Zeroize task queues? */
      bool __ZeroizeTasks;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_ZEROIZECOMMAND_H_
