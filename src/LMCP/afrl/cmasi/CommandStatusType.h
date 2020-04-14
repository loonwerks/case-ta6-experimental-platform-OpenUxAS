// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_COMMANDSTATUSTYPE_H_
#define _AFRL_CMASI_COMMANDSTATUSTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace CommandStatusType {
   enum CommandStatusType {
       /**  Pending authorization prior to execution  */
       Pending = 0,
       /**  Approved for execution by the aircraft  */
       Approved = 1,
       /**  Currently executing by an aircraft  */
       InProcess = 2,
       /**  Completed execution by an aircraft  */
       Executed = 3,
       /**  Cancelled by an operator, aircraft, or other entity  */
       Cancelled = 4

   };

   // generates a new CommandStatusType value for the passed string
   inline CommandStatusType get_CommandStatusType(std::string str) {
       if ( str == "Pending") return Pending;
       if ( str == "Approved") return Approved;
       if ( str == "InProcess") return InProcess;
       if ( str == "Executed") return Executed;
       if ( str == "Cancelled") return Cancelled;
        return Pending;

   }


   // generates a string value for the given enum
   inline std::string get_string(CommandStatusType e) {
       switch(e) {
        case Pending: return "Pending";
        case Approved: return "Approved";
        case InProcess: return "InProcess";
        case Executed: return "Executed";
        case Cancelled: return "Cancelled";
        default: return "Pending";

       }
   }

   }  // namespace CommandStatusType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_COMMANDSTATUSTYPE_H_
