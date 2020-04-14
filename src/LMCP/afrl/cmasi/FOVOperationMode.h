// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_FOVOPERATIONMODE_H_
#define _AFRL_CMASI_FOVOPERATIONMODE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace FOVOperationMode {
   enum FOVOperationMode {
       /**  field of view can be continuously changed  */
       Continuous = 0,
       /**  field of view can only be set to certian, discrete values  */
       Discrete = 1

   };

   // generates a new FOVOperationMode value for the passed string
   inline FOVOperationMode get_FOVOperationMode(std::string str) {
       if ( str == "Continuous") return Continuous;
       if ( str == "Discrete") return Discrete;
        return Continuous;

   }


   // generates a string value for the given enum
   inline std::string get_string(FOVOperationMode e) {
       switch(e) {
        case Continuous: return "Continuous";
        case Discrete: return "Discrete";
        default: return "Continuous";

       }
   }

   }  // namespace FOVOperationMode

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_FOVOPERATIONMODE_H_
