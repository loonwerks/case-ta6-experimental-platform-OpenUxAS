// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_ZONEAVOIDANCETYPE_H_
#define _AFRL_CMASI_ZONEAVOIDANCETYPE_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace ZoneAvoidanceType {
   enum ZoneAvoidanceType {
       /**  zone corresponds to a physical boundary (e.g. terrain, buildings)  */
       Physical = 1,
       /**  zone corresponds to a regulatory boundary (e.g. flight control corridor)  */
       Regulatory = 2,
       /**  zone corresponds to an area that is sensitive to acoustic intrusion  */
       Acoustic = 3,
       /**  zone contains a threat */
       Threat = 4,
       /**  zone defines an area that is sensitive to visual detection.  The threshold of visual detection                is not defined by this standard. */
       Visual = 5

   };

   // generates a new ZoneAvoidanceType value for the passed string
   inline ZoneAvoidanceType get_ZoneAvoidanceType(std::string str) {
       if ( str == "Physical") return Physical;
       if ( str == "Regulatory") return Regulatory;
       if ( str == "Acoustic") return Acoustic;
       if ( str == "Threat") return Threat;
       if ( str == "Visual") return Visual;
        return Physical;

   }


   // generates a string value for the given enum
   inline std::string get_string(ZoneAvoidanceType e) {
       switch(e) {
        case Physical: return "Physical";
        case Regulatory: return "Regulatory";
        case Acoustic: return "Acoustic";
        case Threat: return "Threat";
        case Visual: return "Visual";
        default: return "Physical";

       }
   }

   }  // namespace ZoneAvoidanceType

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_ZONEAVOIDANCETYPE_H_
