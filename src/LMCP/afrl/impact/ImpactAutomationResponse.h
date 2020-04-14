// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_IMPACTAUTOMATIONRESPONSE_H_
#define _AFRL_IMPACT_IMPACTAUTOMATIONRESPONSE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AutomationResponse.h"
#include "afrl/impact/TaskSummary.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isImpactAutomationResponse(avtas::lmcp::Object* obj);
   bool isImpactAutomationResponse(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ImpactAutomationResponseDescendants();
   
   class ImpactAutomationResponse : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ImpactAutomationResponse(void);

      // Copy Constructor
      ImpactAutomationResponse(const ImpactAutomationResponse &that);

      // Assignment Operator
      ImpactAutomationResponse & operator=(const ImpactAutomationResponse &that);

      // Destructor
      virtual ~ImpactAutomationResponse(void);

      // Equals overload
      bool operator==(const ImpactAutomationResponse & that);
      bool operator!=(const ImpactAutomationResponse & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ImpactAutomationResponse* clone() const;

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
      /** Response ID matching request from ({@link ImpactAutomationRequest}) (Units: None)*/
      int64_t getResponseID(void) const { return __ResponseID; }
      ImpactAutomationResponse& setResponseID(const int64_t val);

      /** Automation response from the request. A valid ImpactAutomationResponse must define TrialResponse (null not allowed). (Units: None)*/
      afrl::cmasi::AutomationResponse* const getTrialResponse(void) { return __TrialResponse; }
      ImpactAutomationResponse& setTrialResponse(const afrl::cmasi::AutomationResponse* const val);

      /** Associated play ID (Units: None)*/
      int64_t getPlayID(void) const { return __PlayID; }
      ImpactAutomationResponse& setPlayID(const int64_t val);

      /** Associated solution ID (Units: None)*/
      int64_t getSolutionID(void) const { return __SolutionID; }
      ImpactAutomationResponse& setSolutionID(const int64_t val);

      /** Flag indicating 'sandbox', i.e. not to be implemented (Units: None)*/
      bool getSandbox(void) const { return __Sandbox; }
      ImpactAutomationResponse& setSandbox(const bool val);

      /** Set of vehicle-to-task summaries that will be implemented by this automation response. Including timing, communication, and remaining energy (Units: None)*/
      std::vector<afrl::impact::TaskSummary*> & getSummaries(void) { return __Summaries; }



   protected:
      /** Response ID matching request from ({@link ImpactAutomationRequest}) */
      int64_t __ResponseID;
      /** Automation response from the request. A valid ImpactAutomationResponse must define TrialResponse (null not allowed). */
      afrl::cmasi::AutomationResponse* __TrialResponse;
      /** Associated play ID */
      int64_t __PlayID;
      /** Associated solution ID */
      int64_t __SolutionID;
      /** Flag indicating 'sandbox', i.e. not to be implemented */
      bool __Sandbox;
      /** Set of vehicle-to-task summaries that will be implemented by this automation response. Including timing, communication, and remaining energy */
      std::vector< afrl::impact::TaskSummary* > __Summaries;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_IMPACTAUTOMATIONRESPONSE_H_
