// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_SERVICESTATUSTYPE_H_
#define _AFRL_CMASI_SERVICESTATUSTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace ServiceStatusType {
   enum ServiceStatusType {
       /**  informational note from automation service  */
       Information = 0,
       /**  warning from automation service  */
       Warning = 1,
       /**  error from automation service  */
       Error = 2

   };

   // generates a new ServiceStatusType value for the passed string
   inline ServiceStatusType get_ServiceStatusType(std::string str) {
       if ( str == "Information") return Information;
       if ( str == "Warning") return Warning;
       if ( str == "Error") return Error;
        return Information;

   }


   // generates a string value for the given enum
   inline std::string get_string(ServiceStatusType e) {
       switch(e) {
        case Information: return "Information";
        case Warning: return "Warning";
        case Error: return "Error";
        default: return "Information";

       }
   }

   }  // namespace ServiceStatusType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_SERVICESTATUSTYPE_H_
