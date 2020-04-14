// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_BATCHSUMMARYREQUEST_H_
#define _AFRL_IMPACT_BATCHSUMMARYREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isBatchSummaryRequest(avtas::lmcp::Object* obj);
   bool isBatchSummaryRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > BatchSummaryRequestDescendants();
   
   class BatchSummaryRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      BatchSummaryRequest(void);

      // Copy Constructor
      BatchSummaryRequest(const BatchSummaryRequest &that);

      // Assignment Operator
      BatchSummaryRequest & operator=(const BatchSummaryRequest &that);

      // Destructor
      virtual ~BatchSummaryRequest(void);

      // Equals overload
      bool operator==(const BatchSummaryRequest & that);
      bool operator!=(const BatchSummaryRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual BatchSummaryRequest* clone() const;

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
      BatchSummaryRequest& setRequestID(const int64_t val);

      /** An array of vehicles (by ID) to consider when planning (Units: None)*/
      std::vector<int64_t> & getVehicles(void) { return __Vehicles; }

      /** List of task IDs to be planned to (Units: None)*/
      std::vector<int64_t> & getTaskList(void) { return __TaskList; }

      /** string containing the relationship between requested tasks. If empty, all tasks are to be completed in any order. The format of the string is specific to the automation service. This relationship string is the mechanism for incorporating task precedence, priority, timing, etc. (Units: None)*/
      std::string getTaskRelationships(void) const { return __TaskRelationships; }
      BatchSummaryRequest& setTaskRelationships(const std::string val);

      /** List of task percentages along task to plan from (Units: None)*/
      std::vector<float> & getInterTaskPercentage(void) { return __InterTaskPercentage; }

      /** Operating region to be considered during planning (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      BatchSummaryRequest& setOperatingRegion(const int64_t val);



   protected:
      /** Request ID for correlating with response */
      int64_t __RequestID;
      /** An array of vehicles (by ID) to consider when planning */
      std::vector< int64_t > __Vehicles;
      /** List of task IDs to be planned to */
      std::vector< int64_t > __TaskList;
      /** string containing the relationship between requested tasks. If empty, all tasks are to be completed in any order. The format of the string is specific to the automation service. This relationship string is the mechanism for incorporating task precedence, priority, timing, etc. */
      std::string __TaskRelationships;
      /** List of task percentages along task to plan from */
      std::vector< float > __InterTaskPercentage;
      /** Operating region to be considered during planning */
      int64_t __OperatingRegion;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_BATCHSUMMARYREQUEST_H_
