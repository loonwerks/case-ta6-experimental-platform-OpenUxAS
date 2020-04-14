// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_UXNATIVEENUM_H_
#define _UXAS_MESSAGES_UXNATIVE_UXNATIVEENUM_H_


namespace uxas {
namespace messages {
namespace uxnative {


   namespace UXNATIVEEnum {

      enum LmcpType {
         VIDEORECORD = 1,
         STARTUPCOMPLETE = 2,
         CREATENEWSERVICE = 3,
         KILLSERVICE = 4,
         INCREMENTWAYPOINT = 5,
         SAFEHEADINGACTION = 6,
         ENTITYLOCATION = 7,
         BANDWIDTHTEST = 8,
         BANDWIDTHRECEIVEREPORT = 9,
         SUBTASKEXECUTION = 10,
         SUBTASKASSIGNMENT = 11,
         AUTOPILOTKEEPALIVE = 12,
         ONBOARDSTATUSREPORT = 13,
         ENTITYJOIN = 14,
         ENTITYEXIT = 15,
         SIMULATIONTIMESTEPACKNOWLEDGEMENT = 16,
         SPEEDOVERRIDEACTION = 17,
         ZEROIZECOMMAND = 18,
         ZEROIZECONDITION = 19,
         DOWNLOADREQUEST = 20,
         DOWNLOADREPLY = 21,
         FILETRANSFERREQUEST = 22,
         FILE = 23,
         FILETRANSFER = 24
      };

   }

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif //_UXAS_MESSAGES_UXNATIVE_UXNATIVEENUM_H_
