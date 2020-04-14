// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_NAVIGATIONMODE_H_
#define _AFRL_CMASI_NAVIGATIONMODE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace NavigationMode {
   enum NavigationMode {
       /**  standard waypoint following mode  */
       Waypoint = 0,
       /**  loiter mode, vehicle in constant orbit  */
       Loiter = 1,
       /**  flight director, vehicle following specific heading and spedd commands without regard to waypoints  */
       FlightDirector = 2,
       /**  track target, vehicle adjusts path to maintain current target track  */
       TargetTrack = 3,
       /**  follow leader, vehicle path is maintained to remain in formation with a leader  */
       FollowLeader = 4,
       /**  lost comm, vehicle is out of comm range and should be executing lost-comm behavior  */
       LostComm = 5

   };

   // generates a new NavigationMode value for the passed string
   inline NavigationMode get_NavigationMode(std::string str) {
       if ( str == "Waypoint") return Waypoint;
       if ( str == "Loiter") return Loiter;
       if ( str == "FlightDirector") return FlightDirector;
       if ( str == "TargetTrack") return TargetTrack;
       if ( str == "FollowLeader") return FollowLeader;
       if ( str == "LostComm") return LostComm;
        return Waypoint;

   }


   // generates a string value for the given enum
   inline std::string get_string(NavigationMode e) {
       switch(e) {
        case Waypoint: return "Waypoint";
        case Loiter: return "Loiter";
        case FlightDirector: return "FlightDirector";
        case TargetTrack: return "TargetTrack";
        case FollowLeader: return "FollowLeader";
        case LostComm: return "LostComm";
        default: return "Waypoint";

       }
   }

   }  // namespace NavigationMode

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_NAVIGATIONMODE_H_
