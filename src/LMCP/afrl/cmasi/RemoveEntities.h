// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_REMOVEENTITIES_H_
#define _AFRL_CMASI_REMOVEENTITIES_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isRemoveEntities(avtas::lmcp::Object* obj);
   bool isRemoveEntities(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RemoveEntitiesDescendants();
   
   class RemoveEntities : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RemoveEntities(void);

      // Copy Constructor
      RemoveEntities(const RemoveEntities &that);

      // Assignment Operator
      RemoveEntities & operator=(const RemoveEntities &that);

      // Destructor
      virtual ~RemoveEntities(void);

      // Equals overload
      bool operator==(const RemoveEntities & that);
      bool operator!=(const RemoveEntities & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RemoveEntities* clone() const;

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
      /** List of entities to remove (Units: None)*/
      std::vector<int64_t> & getEntityList(void) { return __EntityList; }



   protected:
      /** List of entities to remove */
      std::vector< int64_t > __EntityList;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_REMOVEENTITIES_H_
