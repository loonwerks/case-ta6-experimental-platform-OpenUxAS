// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_KEYVALUEPAIR_H_
#define _AFRL_CMASI_KEYVALUEPAIR_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"



namespace afrl {
namespace cmasi {


   bool isKeyValuePair(avtas::lmcp::Object* obj);
   bool isKeyValuePair(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > KeyValuePairDescendants();
   
   class KeyValuePair : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      KeyValuePair(void);

      // Copy Constructor
      KeyValuePair(const KeyValuePair &that);

      // Assignment Operator
      KeyValuePair & operator=(const KeyValuePair &that);

      // Destructor
      virtual ~KeyValuePair(void);

      // Equals overload
      bool operator==(const KeyValuePair & that);
      bool operator!=(const KeyValuePair & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual KeyValuePair* clone() const;

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
      /** A key (name) for the property (Units: None)*/
      std::string getKey(void) const { return __Key; }
      KeyValuePair& setKey(const std::string val);

      /** A value for the property (Units: None)*/
      std::string getValue(void) const { return __Value; }
      KeyValuePair& setValue(const std::string val);



   protected:
      /** A key (name) for the property */
      std::string __Key;
      /** A value for the property */
      std::string __Value;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_KEYVALUEPAIR_H_
