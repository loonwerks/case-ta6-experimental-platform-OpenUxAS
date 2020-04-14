// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_IMPACTAUTOMATIONREQUEST_H_
#define _AFRL_IMPACT_IMPACTAUTOMATIONREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AutomationRequest.h"
#include "afrl/impact/SpeedAltPair.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isImpactAutomationRequest(avtas::lmcp::Object* obj);
   bool isImpactAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ImpactAutomationRequestDescendants();
   
   class ImpactAutomationRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ImpactAutomationRequest(void);

      // Copy Constructor
      ImpactAutomationRequest(const ImpactAutomationRequest &that);

      // Assignment Operator
      ImpactAutomationRequest & operator=(const ImpactAutomationRequest &that);

      // Destructor
      virtual ~ImpactAutomationRequest(void);

      // Equals overload
      bool operator==(const ImpactAutomationRequest & that);
      bool operator!=(const ImpactAutomationRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ImpactAutomationRequest* clone() const;

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
      /** Request ID for correlating with response (Units: None)*/
      int64_t getRequestID(void) const { return __RequestID; }
      ImpactAutomationRequest& setRequestID(const int64_t val);

      /** Standard CMASI Automation request. A valid ImpactAutomationRequest must define TrialRequest (null not allowed). (Units: None)*/
      afrl::cmasi::AutomationRequest* const getTrialRequest(void) { return __TrialRequest; }
      ImpactAutomationRequest& setTrialRequest(const afrl::cmasi::AutomationRequest* const val);

      /** Override nominal speed/alt. If a vehicle is not in list, its nominal speed/alt is used (Units: None)*/
      std::vector<afrl::impact::SpeedAltPair*> & getOverridePlanningConditions(void) { return __OverridePlanningConditions; }

      /** Associated play ID (Units: None)*/
      int64_t getPlayID(void) const { return __PlayID; }
      ImpactAutomationRequest& setPlayID(const int64_t val);

      /** Associated solution ID (Units: None)*/
      int64_t getSolutionID(void) const { return __SolutionID; }
      ImpactAutomationRequest& setSolutionID(const int64_t val);

      /** Flag indicating 'sandbox', i.e. not to be implemented (Units: None)*/
      bool getSandbox(void) const { return __Sandbox; }
      ImpactAutomationRequest& setSandbox(const bool val);



   protected:
      /** Request ID for correlating with response */
      int64_t __RequestID;
      /** Standard CMASI Automation request. A valid ImpactAutomationRequest must define TrialRequest (null not allowed). */
      afrl::cmasi::AutomationRequest* __TrialRequest;
      /** Override nominal speed/alt. If a vehicle is not in list, its nominal speed/alt is used */
      std::vector< afrl::impact::SpeedAltPair* > __OverridePlanningConditions;
      /** Associated play ID */
      int64_t __PlayID;
      /** Associated solution ID */
      int64_t __SolutionID;
      /** Flag indicating 'sandbox', i.e. not to be implemented */
      bool __Sandbox;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_IMPACTAUTOMATIONREQUEST_H_
