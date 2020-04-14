// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_TRAVELMODE_H_
#define _AFRL_CMASI_TRAVELMODE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace TravelMode {
   enum TravelMode {
       /**  A path is traversed from beginning to end, then the entity stops  */
       SinglePass = 0,
       /**  Upon reaching the end of a route, the entity travels the waypoint list in reverse-direction.  */
       ReverseCourse = 1,
       /**  Upon reaching the end of a route, the entity travels to the first point and repeats the route.  */
       Loop = 2

   };

   // generates a new TravelMode value for the passed string
   inline TravelMode get_TravelMode(std::string str) {
       if ( str == "SinglePass") return SinglePass;
       if ( str == "ReverseCourse") return ReverseCourse;
       if ( str == "Loop") return Loop;
        return SinglePass;

   }


   // generates a string value for the given enum
   inline std::string get_string(TravelMode e) {
       switch(e) {
        case SinglePass: return "SinglePass";
        case ReverseCourse: return "ReverseCourse";
        case Loop: return "Loop";
        default: return "SinglePass";

       }
   }

   }  // namespace TravelMode

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_TRAVELMODE_H_
