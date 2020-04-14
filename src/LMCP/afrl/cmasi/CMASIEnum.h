// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_CMASIENUM_H_
#define _AFRL_CMASI_CMASIENUM_H_


namespace afrl {
namespace cmasi {


   namespace CMASIEnum {

      enum LmcpType {
         ABSTRACTGEOMETRY = 1,
         KEYVALUEPAIR = 2,
         LOCATION3D = 3,
         PAYLOADACTION = 4,
         PAYLOADCONFIGURATION = 5,
         PAYLOADSTATE = 6,
         VEHICLEACTION = 7,
         TASK = 8,
         SEARCHTASK = 9,
         ABSTRACTZONE = 10,
         ENTITYCONFIGURATION = 11,
         FLIGHTPROFILE = 12,
         AIRVEHICLECONFIGURATION = 13,
         ENTITYSTATE = 14,
         AIRVEHICLESTATE = 15,
         WEDGE = 16,
         AREASEARCHTASK = 17,
         CAMERAACTION = 18,
         CAMERACONFIGURATION = 19,
         GIMBALLEDPAYLOADSTATE = 20,
         CAMERASTATE = 21,
         CIRCLE = 22,
         GIMBALANGLEACTION = 23,
         GIMBALCONFIGURATION = 24,
         GIMBALSCANACTION = 25,
         GIMBALSTAREACTION = 26,
         GIMBALSTATE = 27,
         GOTOWAYPOINTACTION = 28,
         KEEPINZONE = 29,
         KEEPOUTZONE = 30,
         LINESEARCHTASK = 31,
         NAVIGATIONACTION = 32,
         LOITERACTION = 33,
         LOITERTASK = 34,
         WAYPOINT = 35,
         MISSIONCOMMAND = 36,
         MUSTFLYTASK = 37,
         OPERATORSIGNAL = 38,
         OPERATINGREGION = 39,
         AUTOMATIONREQUEST = 40,
         POINTSEARCHTASK = 41,
         POLYGON = 42,
         RECTANGLE = 43,
         REMOVETASKS = 44,
         SERVICESTATUS = 45,
         SESSIONSTATUS = 46,
         VEHICLEACTIONCOMMAND = 47,
         VIDEOSTREAMACTION = 48,
         VIDEOSTREAMCONFIGURATION = 49,
         VIDEOSTREAMSTATE = 50,
         AUTOMATIONRESPONSE = 51,
         REMOVEZONES = 52,
         REMOVEENTITIES = 53,
         FLIGHTDIRECTORACTION = 54,
         WEATHERREPORT = 55,
         FOLLOWPATHCOMMAND = 56,
         PATHWAYPOINT = 57,
         STOPMOVEMENTACTION = 58,
         WAYPOINTTRANSFER = 59,
         PAYLOADSTOWACTION = 60
      };

   }

} // end namespace cmasi
} // end namespace afrl


#endif //_AFRL_CMASI_CMASIENUM_H_
