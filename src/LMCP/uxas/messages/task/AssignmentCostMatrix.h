// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_ASSIGNMENTCOSTMATRIX_H_
#define _UXAS_MESSAGES_TASK_ASSIGNMENTCOSTMATRIX_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/task/TaskOptionCost.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isAssignmentCostMatrix(avtas::lmcp::Object* obj);
   bool isAssignmentCostMatrix(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AssignmentCostMatrixDescendants();
   
   class AssignmentCostMatrix : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AssignmentCostMatrix(void);

      // Copy Constructor
      AssignmentCostMatrix(const AssignmentCostMatrix &that);

      // Assignment Operator
      AssignmentCostMatrix & operator=(const AssignmentCostMatrix &that);

      // Destructor
      virtual ~AssignmentCostMatrix(void);

      // Equals overload
      bool operator==(const AssignmentCostMatrix & that);
      bool operator!=(const AssignmentCostMatrix & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AssignmentCostMatrix* clone() const;

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
      /** ID that matches this cost matrix with the appropriate unique automation request (Units: None)*/
      int64_t getCorrespondingAutomationRequestID(void) const { return __CorrespondingAutomationRequestID; }
      AssignmentCostMatrix& setCorrespondingAutomationRequestID(const int64_t val);

      /** Over-arching task relationship description (directly from automation request). A process algebra string with only task IDs. (Units: None)*/
      std::string getTaskLevelRelationship(void) const { return __TaskLevelRelationship; }
      AssignmentCostMatrix& setTaskLevelRelationship(const std::string val);

      /** List of all tasks that this cost matrix includes (Units: None)*/
      std::vector<int64_t> & getTaskList(void) { return __TaskList; }

      /** Operating region that was used during matrix calculation (Units: None)*/
      int64_t getOperatingRegion(void) const { return __OperatingRegion; }
      AssignmentCostMatrix& setOperatingRegion(const int64_t val);

      /** Set of task-to-task timings for each requested vehicle. Assume 'T' max tasks [16], 'O' max options per task [8], 'V' max vehicles [16]: then max number of elements in matrix is 'V*T*O + (T*O)^2' [18432] (Units: None)*/
      std::vector<uxas::messages::task::TaskOptionCost*> & getCostMatrix(void) { return __CostMatrix; }



   protected:
      /** ID that matches this cost matrix with the appropriate unique automation request */
      int64_t __CorrespondingAutomationRequestID;
      /** Over-arching task relationship description (directly from automation request). A process algebra string with only task IDs. */
      std::string __TaskLevelRelationship;
      /** List of all tasks that this cost matrix includes */
      std::vector< int64_t > __TaskList;
      /** Operating region that was used during matrix calculation */
      int64_t __OperatingRegion;
      /** Set of task-to-task timings for each requested vehicle. Assume 'T' max tasks [16], 'O' max options per task [8], 'V' max vehicles [16]: then max number of elements in matrix is 'V*T*O + (T*O)^2' [18432] */
      std::vector< uxas::messages::task::TaskOptionCost* > __CostMatrix;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_ASSIGNMENTCOSTMATRIX_H_
