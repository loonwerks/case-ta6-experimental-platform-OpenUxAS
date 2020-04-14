// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_ALTITUDETYPE_H_
#define _AFRL_CMASI_ALTITUDETYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace AltitudeType {
   enum AltitudeType {
       /**  Height above ground/survace level  */
       AGL = 0,
       /**  Height above WGS84 ellipsoid, mean sea level  */
       MSL = 1

   };

   // generates a new AltitudeType value for the passed string
   inline AltitudeType get_AltitudeType(std::string str) {
       if ( str == "AGL") return AGL;
       if ( str == "MSL") return MSL;
        return AGL;

   }


   // generates a string value for the given enum
   inline std::string get_string(AltitudeType e) {
       switch(e) {
        case AGL: return "AGL";
        case MSL: return "MSL";
        default: return "AGL";

       }
   }

   }  // namespace AltitudeType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_ALTITUDETYPE_H_
