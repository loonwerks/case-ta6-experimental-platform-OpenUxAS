// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_UXTASKENUM_H_
#define _UXAS_MESSAGES_TASK_UXTASKENUM_H_


namespace uxas {
namespace messages {
namespace task {


   namespace UXTASKEnum {

      enum LmcpType {
         ASSIGNMENTCOORDINATORTASK = 1,
         RENDEZVOUSTASK = 2,
         PLANNINGSTATE = 3,
         ASSIGNMENTCOORDINATION = 4,
         COORDINATEDAUTOMATIONREQUEST = 5,
         TASKAUTOMATIONREQUEST = 6,
         TASKAUTOMATIONRESPONSE = 7,
         UNIQUEAUTOMATIONREQUEST = 8,
         UNIQUEAUTOMATIONRESPONSE = 9,
         SENSORFOOTPRINTREQUESTS = 10,
         FOOTPRINTREQUEST = 11,
         SENSORFOOTPRINT = 12,
         SENSORFOOTPRINTRESPONSE = 13,
         TASKIMPLEMENTATIONREQUEST = 14,
         TASKIMPLEMENTATIONRESPONSE = 15,
         ASSIGNMENTCOSTMATRIX = 16,
         TASKOPTIONCOST = 17,
         TASKASSIGNMENT = 18,
         TASKASSIGNMENTSUMMARY = 19,
         TASKOPTION = 20,
         TASKPLANOPTIONS = 21,
         TASKPAUSE = 22,
         TASKRESUME = 23,
         TASKPROGRESS = 24,
         TASKPROGRESSREQUEST = 25,
         TASKINITIALIZED = 26,
         TASKACTIVE = 27,
         TASKCOMPLETE = 28,
         CANCELTASK = 29
      };

   }

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif //_UXAS_MESSAGES_TASK_UXTASKENUM_H_
