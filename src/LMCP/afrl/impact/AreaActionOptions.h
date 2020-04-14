// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_AREAACTIONOPTIONS_H_
#define _AFRL_IMPACT_AREAACTIONOPTIONS_H_

#include <string>

namespace afrl {
namespace impact {



   namespace AreaActionOptions {
   enum AreaActionOptions {
       /**  Object of interest created  */
       Created = 0,
       /**  Object of interest destroyed  */
       Destroyed = 1,
       /**  Object of interest modified  */
       Modified = 2

   };

   // generates a new AreaActionOptions value for the passed string
   inline AreaActionOptions get_AreaActionOptions(std::string str) {
       if ( str == "Created") return Created;
       if ( str == "Destroyed") return Destroyed;
       if ( str == "Modified") return Modified;
        return Created;

   }


   // generates a string value for the given enum
   inline std::string get_string(AreaActionOptions e) {
       switch(e) {
        case Created: return "Created";
        case Destroyed: return "Destroyed";
        case Modified: return "Modified";
        default: return "Created";

       }
   }

   }  // namespace AreaActionOptions

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_AREAACTIONOPTIONS_H_
