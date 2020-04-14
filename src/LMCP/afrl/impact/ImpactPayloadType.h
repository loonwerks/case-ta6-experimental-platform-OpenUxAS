// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_IMPACTPAYLOADTYPE_H_
#define _AFRL_IMPACT_IMPACTPAYLOADTYPE_H_

#include <string>

namespace afrl {
namespace impact {



   namespace ImpactPayloadType {
   enum ImpactPayloadType {
       /**  Unknown  */
       Unknown = 0,
       /**  EO  */
       EO = 1,
       /**  Forward Looking Infra Red  */
       FLIR = 2,
       /**  Mid Wave Infra Red  */
       MWIR = 3,
       /**  LFIR  */
       LFIR = 4,
       /**  Auto-tracking payload  */
       Track = 5,
       /**  Placement of physical tag for tracking  */
       Tag = 6,
       /**  Megaphone  */
       Megaphone = 7,
       /**  Siren  */
       Siren = 8,
       /**  Search Light  */
       SearchLight = 9,
       /**  Browning .50 caliber weapon  */
       FiftyCal = 10,
       /**  M240B  */
       M240B = 11,
       /**  Flashbang  */
       Flashbang = 12,
       /**  Tear Gas  */
       TearGas = 13,
       /**  Taser  */
       Taser = 14,
       /**  Heat Beam  */
       HeatBeam = 15,
       /**  Scan Eagle Guided Munition  */
       SEGM = 16,
       /**  Comm Relay  */
       CommRelay = 17,
       /**  Ground Moving Target Indicator  */
       GMTI = 18,
       /**  Laser Designator  */
       LaserDesignator = 19,
       /**  LWIR  */
       LWIR = 20

   };

   // generates a new ImpactPayloadType value for the passed string
   inline ImpactPayloadType get_ImpactPayloadType(std::string str) {
       if ( str == "Unknown") return Unknown;
       if ( str == "EO") return EO;
       if ( str == "FLIR") return FLIR;
       if ( str == "MWIR") return MWIR;
       if ( str == "LFIR") return LFIR;
       if ( str == "Track") return Track;
       if ( str == "Tag") return Tag;
       if ( str == "Megaphone") return Megaphone;
       if ( str == "Siren") return Siren;
       if ( str == "SearchLight") return SearchLight;
       if ( str == "FiftyCal") return FiftyCal;
       if ( str == "M240B") return M240B;
       if ( str == "Flashbang") return Flashbang;
       if ( str == "TearGas") return TearGas;
       if ( str == "Taser") return Taser;
       if ( str == "HeatBeam") return HeatBeam;
       if ( str == "SEGM") return SEGM;
       if ( str == "CommRelay") return CommRelay;
       if ( str == "GMTI") return GMTI;
       if ( str == "LaserDesignator") return LaserDesignator;
       if ( str == "LWIR") return LWIR;
        return Unknown;

   }


   // generates a string value for the given enum
   inline std::string get_string(ImpactPayloadType e) {
       switch(e) {
        case Unknown: return "Unknown";
        case EO: return "EO";
        case FLIR: return "FLIR";
        case MWIR: return "MWIR";
        case LFIR: return "LFIR";
        case Track: return "Track";
        case Tag: return "Tag";
        case Megaphone: return "Megaphone";
        case Siren: return "Siren";
        case SearchLight: return "SearchLight";
        case FiftyCal: return "FiftyCal";
        case M240B: return "M240B";
        case Flashbang: return "Flashbang";
        case TearGas: return "TearGas";
        case Taser: return "Taser";
        case HeatBeam: return "HeatBeam";
        case SEGM: return "SEGM";
        case CommRelay: return "CommRelay";
        case GMTI: return "GMTI";
        case LaserDesignator: return "LaserDesignator";
        case LWIR: return "LWIR";
        default: return "Unknown";

       }
   }

   }  // namespace ImpactPayloadType

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_IMPACTPAYLOADTYPE_H_
