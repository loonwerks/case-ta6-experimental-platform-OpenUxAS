// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_TURNTYPE_H_
#define _AFRL_CMASI_TURNTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace TurnType {
   enum TurnType {
       /**  turn short, return to track  */
       TurnShort = 0,
       /**  fly over, return to track  */
       FlyOver = 1

   };

   // generates a new TurnType value for the passed string
   inline TurnType get_TurnType(std::string str) {
       if ( str == "TurnShort") return TurnShort;
       if ( str == "FlyOver") return FlyOver;
        return TurnShort;

   }


   // generates a string value for the given enum
   inline std::string get_string(TurnType e) {
       switch(e) {
        case TurnShort: return "TurnShort";
        case FlyOver: return "FlyOver";
        default: return "TurnShort";

       }
   }

   }  // namespace TurnType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_TURNTYPE_H_
