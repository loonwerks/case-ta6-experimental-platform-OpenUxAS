// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_SPEEDTYPE_H_
#define _AFRL_CMASI_SPEEDTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace SpeedType {
   enum SpeedType {
       /**  airspeed  */
       Airspeed = 0,
       /**  groundspeed  */
       Groundspeed = 1

   };

   // generates a new SpeedType value for the passed string
   inline SpeedType get_SpeedType(std::string str) {
       if ( str == "Airspeed") return Airspeed;
       if ( str == "Groundspeed") return Groundspeed;
        return Airspeed;

   }


   // generates a string value for the given enum
   inline std::string get_string(SpeedType e) {
       switch(e) {
        case Airspeed: return "Airspeed";
        case Groundspeed: return "Groundspeed";
        default: return "Airspeed";

       }
   }

   }  // namespace SpeedType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_SPEEDTYPE_H_
