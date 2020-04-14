// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_BATCHSUMMARYRESPONSE_H_
#define _AFRL_IMPACT_BATCHSUMMARYRESPONSE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/impact/TaskSummary.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isBatchSummaryResponse(avtas::lmcp::Object* obj);
   bool isBatchSummaryResponse(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > BatchSummaryResponseDescendants();
   
   class BatchSummaryResponse : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      BatchSummaryResponse(void);

      // Copy Constructor
      BatchSummaryResponse(const BatchSummaryResponse &that);

      // Assignment Operator
      BatchSummaryResponse & operator=(const BatchSummaryResponse &that);

      // Destructor
      virtual ~BatchSummaryResponse(void);

      // Equals overload
      bool operator==(const BatchSummaryResponse & that);
      bool operator!=(const BatchSummaryResponse & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual BatchSummaryResponse* clone() const;

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
      /** Response ID matching request from ({@link BatchSummaryRequest}) (Units: None)*/
      int64_t getResponseID(void) const { return __ResponseID; }
      BatchSummaryResponse& setResponseID(const int64_t val);

      /** Set of vehicle-to-task and task-to-task summaries including timing, communication, and remaining energy (Units: None)*/
      std::vector<afrl::impact::TaskSummary*> & getSummaries(void) { return __Summaries; }



   protected:
      /** Response ID matching request from ({@link BatchSummaryRequest}) */
      int64_t __ResponseID;
      /** Set of vehicle-to-task and task-to-task summaries including timing, communication, and remaining energy */
      std::vector< afrl::impact::TaskSummary* > __Summaries;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_BATCHSUMMARYRESPONSE_H_
