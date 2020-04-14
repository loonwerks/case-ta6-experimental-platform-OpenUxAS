// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_POWERPLANT_H_
#define _AFRL_IMPACT_POWERPLANT_H_

#include <string>

namespace afrl {
namespace impact {



   namespace PowerPlant {
   enum PowerPlant {
       /**  Conventional gasoline  */
       Gasoline = 0,
       /**  Heavy Fuel (JP5)  */
       JP5 = 1,
       /**  Heavy Fuel (JP8)  */
       JP8 = 2,
       /**  Fuel Cell (Hydrogen)  */
       FuelCell = 3,
       /**  Hybrid electric/gasoline  */
       Hybrid = 4,
       /**  Primarily electric  */
       Electric = 5

   };

   // generates a new PowerPlant value for the passed string
   inline PowerPlant get_PowerPlant(std::string str) {
       if ( str == "Gasoline") return Gasoline;
       if ( str == "JP5") return JP5;
       if ( str == "JP8") return JP8;
       if ( str == "FuelCell") return FuelCell;
       if ( str == "Hybrid") return Hybrid;
       if ( str == "Electric") return Electric;
        return Gasoline;

   }


   // generates a string value for the given enum
   inline std::string get_string(PowerPlant e) {
       switch(e) {
        case Gasoline: return "Gasoline";
        case JP5: return "JP5";
        case JP8: return "JP8";
        case FuelCell: return "FuelCell";
        case Hybrid: return "Hybrid";
        case Electric: return "Electric";
        default: return "Gasoline";

       }
   }

   }  // namespace PowerPlant

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_POWERPLANT_H_
