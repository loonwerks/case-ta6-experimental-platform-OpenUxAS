// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_BATCHROUTEPLANREQUEST_H_
#define _AFRL_IMPACT_BATCHROUTEPLANREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isBatchRoutePlanRequest(avtas::lmcp::Object* obj);
   bool isBatchRoutePlanRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > BatchRoutePlanRequestDescendants();
   
   class BatchRoutePlanRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      BatchRoutePlanRequest(void);

      // Copy Constructor
      BatchRoutePlanRequest(const BatchRoutePlanRequest &that);

      // Assignment Operator
      BatchRoutePlanRequest & operator=(const BatchRoutePlanRequest &that);

      // Destructor
      virtual ~BatchRoutePlanRequest(void);

      // Equals overload
      bool operator==(const BatchRoutePlanRequest & that);
      bool operator!=(const BatchRoutePlanRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual BatchRoutePlanRequest* clone() const;

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
      BatchRoutePlanRequest& setRequestID(const int64_t val);

      /** An array of vehicles (by ID) to consider when planning (Units: None)*/
      std::vector<int64_t> & getVehicles(void) { return __Vehicles; }

      /** List of task IDs to be planned to (Units: None)*/
      std::vector<int64_t> & getTaskList(void) { return __TaskList; }

      /** Operating region to be considered during planning (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      BatchRoutePlanRequest& setOperatingRegion(const int64_t val);

      /** Flag to report timing between tasks (Units: None)*/
      bool getComputeTaskToTaskTiming(void) const { return __ComputeTaskToTaskTiming; }
      BatchRoutePlanRequest& setComputeTaskToTaskTiming(const bool val);

      /** Flag to report timing between incremental progress on task and subsequent tasks (Units: None)*/
      bool getComputeInterTaskToTaskTiming(void) const { return __ComputeInterTaskToTaskTiming; }
      BatchRoutePlanRequest& setComputeInterTaskToTaskTiming(const bool val);

      /** List of task percentages along task to plan from (Units: None)*/
      std::vector<float> & getInterTaskPercentage(void) { return __InterTaskPercentage; }



   protected:
      /** Request ID for correlating with response */
      int64_t __RequestID;
      /** An array of vehicles (by ID) to consider when planning */
      std::vector< int64_t > __Vehicles;
      /** List of task IDs to be planned to */
      std::vector< int64_t > __TaskList;
      /** Operating region to be considered during planning */
      int64_t __OperatingRegion;
      /** Flag to report timing between tasks */
      bool __ComputeTaskToTaskTiming;
      /** Flag to report timing between incremental progress on task and subsequent tasks */
      bool __ComputeInterTaskToTaskTiming;
      /** List of task percentages along task to plan from */
      std::vector< float > __InterTaskPercentage;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_BATCHROUTEPLANREQUEST_H_