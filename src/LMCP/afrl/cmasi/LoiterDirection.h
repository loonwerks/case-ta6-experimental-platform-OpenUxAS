// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_LOITERDIRECTION_H_
#define _AFRL_CMASI_LOITERDIRECTION_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace LoiterDirection {
   enum LoiterDirection {
       /**  vehicle default  */
       VehicleDefault = 0,
       /**  counter-clockwise  */
       CounterClockwise = 1,
       /**  clockwise  */
       Clockwise = 2

   };

   // generates a new LoiterDirection value for the passed string
   inline LoiterDirection get_LoiterDirection(std::string str) {
       if ( str == "VehicleDefault") return VehicleDefault;
       if ( str == "CounterClockwise") return CounterClockwise;
       if ( str == "Clockwise") return Clockwise;
        return VehicleDefault;

   }


   // generates a string value for the given enum
   inline std::string get_string(LoiterDirection e) {
       switch(e) {
        case VehicleDefault: return "VehicleDefault";
        case CounterClockwise: return "CounterClockwise";
        case Clockwise: return "Clockwise";
        default: return "VehicleDefault";

       }
   }

   }  // namespace LoiterDirection

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_LOITERDIRECTION_H_
