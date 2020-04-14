// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROUTEENUM_H_
#define _UXAS_MESSAGES_ROUTE_ROUTEENUM_H_


namespace uxas {
namespace messages {
namespace route {


   namespace ROUTEEnum {

      enum LmcpType {
         GRAPHNODE = 1,
         GRAPHEDGE = 2,
         GRAPHREGION = 3,
         ROUTECONSTRAINTS = 4,
         ROUTEREQUEST = 5,
         ROUTEPLANREQUEST = 6,
         ROUTEPLAN = 7,
         ROUTEPLANRESPONSE = 8,
         ROUTERESPONSE = 9,
         EGRESSROUTEREQUEST = 10,
         EGRESSROUTERESPONSE = 11,
         ROADPOINTSCONSTRAINTS = 12,
         ROADPOINTSREQUEST = 13,
         ROADPOINTSRESPONSE = 14
      };

   }

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif //_UXAS_MESSAGES_ROUTE_ROUTEENUM_H_
