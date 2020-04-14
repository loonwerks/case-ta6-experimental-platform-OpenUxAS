// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_SERVICESTATUS_H_
#define _AFRL_CMASI_SERVICESTATUS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/KeyValuePair.h"
#include "afrl/cmasi/ServiceStatusType.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isServiceStatus(avtas::lmcp::Object* obj);
   bool isServiceStatus(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ServiceStatusDescendants();
   
   class ServiceStatus : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ServiceStatus(void);

      // Copy Constructor
      ServiceStatus(const ServiceStatus &that);

      // Assignment Operator
      ServiceStatus & operator=(const ServiceStatus &that);

      // Destructor
      virtual ~ServiceStatus(void);

      // Equals overload
      bool operator==(const ServiceStatus & that);
      bool operator!=(const ServiceStatus & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ServiceStatus* clone() const;

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
      /** The estimated percentage completed for an automation process. (Units: None)*/
      float getPercentComplete(void) const { return __PercentComplete; }
      ServiceStatus& setPercentComplete(const float val);

      /** Status from the automation service to the simulation regarding errors or conditions. (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getInfo(void) { return __Info; }

      /** Describes the type of message conveyed. 
      *<br/> Information. Used to note normal progress updates 
      *<br/> Warning. Notes non-fatal problem(s) in data or processing 
      *<br/> Error. Notes fatal problem(s) 
      *<br/> (Units: None)*/
      afrl::cmasi::ServiceStatusType::ServiceStatusType getStatusType(void) const { return __StatusType; }
      ServiceStatus& setStatusType(const afrl::cmasi::ServiceStatusType::ServiceStatusType val);



   protected:
      /** The estimated percentage completed for an automation process. */
      float __PercentComplete;
      /** Status from the automation service to the simulation regarding errors or conditions. */
      std::vector< afrl::cmasi::KeyValuePair* > __Info;
      /** Describes the type of message conveyed. 
      *<br/> Information. Used to note normal progress updates 
      *<br/> Warning. Notes non-fatal problem(s) in data or processing 
      *<br/> Error. Notes fatal problem(s) 
      *<br/> */
      afrl::cmasi::ServiceStatusType::ServiceStatusType __StatusType;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_SERVICESTATUS_H_
