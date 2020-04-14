// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WAYPOINTTRANSFERMODE_H_
#define _AFRL_CMASI_WAYPOINTTRANSFERMODE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace WaypointTransferMode {
   enum WaypointTransferMode {
       /**  Requests download of waypoints from the aircraft  */
       RequestWaypoints = 0,
       /**  Adds waypoints to the aircraft.  Waypoints with the same number are overwritten  */
       AddWaypoints = 1,
       /**  Commands the aircraft to clear its waypoints  */
       ClearWaypoints = 2,
       /**  Reports waypoints that are curretly in the aircraft computer  */
       ReportWaypoints = 3

   };

   // generates a new WaypointTransferMode value for the passed string
   inline WaypointTransferMode get_WaypointTransferMode(std::string str) {
       if ( str == "RequestWaypoints") return RequestWaypoints;
       if ( str == "AddWaypoints") return AddWaypoints;
       if ( str == "ClearWaypoints") return ClearWaypoints;
       if ( str == "ReportWaypoints") return ReportWaypoints;
        return RequestWaypoints;

   }


   // generates a string value for the given enum
   inline std::string get_string(WaypointTransferMode e) {
       switch(e) {
        case RequestWaypoints: return "RequestWaypoints";
        case AddWaypoints: return "AddWaypoints";
        case ClearWaypoints: return "ClearWaypoints";
        case ReportWaypoints: return "ReportWaypoints";
        default: return "RequestWaypoints";

       }
   }

   }  // namespace WaypointTransferMode

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WAYPOINTTRANSFERMODE_H_
