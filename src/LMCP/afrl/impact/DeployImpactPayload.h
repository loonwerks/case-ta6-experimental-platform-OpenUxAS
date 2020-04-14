// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_DEPLOYIMPACTPAYLOAD_H_
#define _AFRL_IMPACT_DEPLOYIMPACTPAYLOAD_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/VehicleAction.h"
#include "afrl/impact/ImpactPayloadType.h"



namespace afrl {
namespace impact {


   bool isDeployImpactPayload(avtas::lmcp::Object* obj);
   bool isDeployImpactPayload(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > DeployImpactPayloadDescendants();
   
   class DeployImpactPayload : public afrl::cmasi::VehicleAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      DeployImpactPayload(void);

      // Copy Constructor
      DeployImpactPayload(const DeployImpactPayload &that);

      // Assignment Operator
      DeployImpactPayload & operator=(const DeployImpactPayload &that);

      // Destructor
      virtual ~DeployImpactPayload(void);

      // Equals overload
      bool operator==(const DeployImpactPayload & that);
      bool operator!=(const DeployImpactPayload & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual DeployImpactPayload* clone() const;

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
      /** IMPACT vehicle from which to deploy payload (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      DeployImpactPayload& setVehicleID(const int64_t val);

      /** Payload to deploy (Units: None)*/
      afrl::impact::ImpactPayloadType::ImpactPayloadType getDeployedPayload(void) const { return __DeployedPayload; }
      DeployImpactPayload& setDeployedPayload(const afrl::impact::ImpactPayloadType::ImpactPayloadType val);

      /** Entity to which the payload will be deployed. If zero, then payload is assumed deployed at the current position of the deploying vehicle. (Units: None)*/
      int64_t getTargetEntityID(void) const { return __TargetEntityID; }
      DeployImpactPayload& setTargetEntityID(const int64_t val);



   protected:
      /** IMPACT vehicle from which to deploy payload */
      int64_t __VehicleID;
      /** Payload to deploy */
      afrl::impact::ImpactPayloadType::ImpactPayloadType __DeployedPayload;
      /** Entity to which the payload will be deployed. If zero, then payload is assumed deployed at the current position of the deploying vehicle. */
      int64_t __TargetEntityID;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_DEPLOYIMPACTPAYLOAD_H_
