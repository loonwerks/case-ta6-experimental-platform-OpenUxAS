// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_LOITERTYPE_H_
#define _AFRL_CMASI_LOITERTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace LoiterType {
   enum LoiterType {
       /**  vehicle default  */
       VehicleDefault = 0,
       /**  circular  */
       Circular = 1,
       /**  racetrack  */
       Racetrack = 2,
       /**  figure eight */
       FigureEight = 3,
       /**  Hovering. */
       Hover = 4

   };

   // generates a new LoiterType value for the passed string
   inline LoiterType get_LoiterType(std::string str) {
       if ( str == "VehicleDefault") return VehicleDefault;
       if ( str == "Circular") return Circular;
       if ( str == "Racetrack") return Racetrack;
       if ( str == "FigureEight") return FigureEight;
       if ( str == "Hover") return Hover;
        return VehicleDefault;

   }


   // generates a string value for the given enum
   inline std::string get_string(LoiterType e) {
       switch(e) {
        case VehicleDefault: return "VehicleDefault";
        case Circular: return "Circular";
        case Racetrack: return "Racetrack";
        case FigureEight: return "FigureEight";
        case Hover: return "Hover";
        default: return "VehicleDefault";

       }
   }

   }  // namespace LoiterType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_LOITERTYPE_H_
