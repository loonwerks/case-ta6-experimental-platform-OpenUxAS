// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_SIMULATIONSTATUSTYPE_H_
#define _AFRL_CMASI_SIMULATIONSTATUSTYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace SimulationStatusType {
   enum SimulationStatusType {
       /**  simulation is stopped  */
       Stopped = 0,
       /**  simulation is running  */
       Running = 1,
       /**  simulation paused  */
       Paused = 2,
       /**  simulation is reset  */
       Reset = 3

   };

   // generates a new SimulationStatusType value for the passed string
   inline SimulationStatusType get_SimulationStatusType(std::string str) {
       if ( str == "Stopped") return Stopped;
       if ( str == "Running") return Running;
       if ( str == "Paused") return Paused;
       if ( str == "Reset") return Reset;
        return Stopped;

   }


   // generates a string value for the given enum
   inline std::string get_string(SimulationStatusType e) {
       switch(e) {
        case Stopped: return "Stopped";
        case Running: return "Running";
        case Paused: return "Paused";
        case Reset: return "Reset";
        default: return "Stopped";

       }
   }

   }  // namespace SimulationStatusType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_SIMULATIONSTATUSTYPE_H_
