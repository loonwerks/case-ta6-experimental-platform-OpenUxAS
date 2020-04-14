// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_AREASEARCHPATTERN_H_
#define _AFRL_IMPACT_AREASEARCHPATTERN_H_

#include <string>

namespace afrl {
namespace impact {



   namespace AreaSearchPattern {
   enum AreaSearchPattern {
       /**  Spiral search  */
       Spiral = 0,
       /**  Sector  */
       Sector = 1,
       /**  Sweep  */
       Sweep = 2

   };

   // generates a new AreaSearchPattern value for the passed string
   inline AreaSearchPattern get_AreaSearchPattern(std::string str) {
       if ( str == "Spiral") return Spiral;
       if ( str == "Sector") return Sector;
       if ( str == "Sweep") return Sweep;
        return Spiral;

   }


   // generates a string value for the given enum
   inline std::string get_string(AreaSearchPattern e) {
       switch(e) {
        case Spiral: return "Spiral";
        case Sector: return "Sector";
        case Sweep: return "Sweep";
        default: return "Spiral";

       }
   }

   }  // namespace AreaSearchPattern

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_AREASEARCHPATTERN_H_
