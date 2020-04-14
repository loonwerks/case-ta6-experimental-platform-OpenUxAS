// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_GIMBALPOINTINGMODE_H_
#define _AFRL_CMASI_GIMBALPOINTINGMODE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace GimbalPointingMode {
   enum GimbalPointingMode {
       /**  Unknown pointing mode or unavailable  */
       Unknown = 0,
       /**  angles are commanded relative to the vehicle  */
       AirVehicleRelativeAngle = 1,
       /**  angle rates are commanded relative to the vehicle  */
       AirVehicleRelativeSlewRate = 2,
       /**  gimbal aimed at an inertial location  */
       LatLonSlaved = 3,
       /**  gimbal rates are calculated relative to the inertial coordinate system  */
       InertialRelativeSlewRate = 4,
       /**  gimbal continuously scans in a pre-determined pattern  */
       Scan = 5,
       /**  indicates that the gimbal is stowed  */
       Stowed = 6

   };

   // generates a new GimbalPointingMode value for the passed string
   inline GimbalPointingMode get_GimbalPointingMode(std::string str) {
       if ( str == "Unknown") return Unknown;
       if ( str == "AirVehicleRelativeAngle") return AirVehicleRelativeAngle;
       if ( str == "AirVehicleRelativeSlewRate") return AirVehicleRelativeSlewRate;
       if ( str == "LatLonSlaved") return LatLonSlaved;
       if ( str == "InertialRelativeSlewRate") return InertialRelativeSlewRate;
       if ( str == "Scan") return Scan;
       if ( str == "Stowed") return Stowed;
        return Unknown;

   }


   // generates a string value for the given enum
   inline std::string get_string(GimbalPointingMode e) {
       switch(e) {
        case Unknown: return "Unknown";
        case AirVehicleRelativeAngle: return "AirVehicleRelativeAngle";
        case AirVehicleRelativeSlewRate: return "AirVehicleRelativeSlewRate";
        case LatLonSlaved: return "LatLonSlaved";
        case InertialRelativeSlewRate: return "InertialRelativeSlewRate";
        case Scan: return "Scan";
        case Stowed: return "Stowed";
        default: return "Unknown";

       }
   }

   }  // namespace GimbalPointingMode

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_GIMBALPOINTINGMODE_H_
