// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WAVELENGTHBAND_H_
#define _AFRL_CMASI_WAVELENGTHBAND_H_

#include <string>

namespace afrl {
namespace cmasi {



   namespace WavelengthBand {
   enum WavelengthBand {
       /**  used in cases when wavelength is not applicable  */
       AllAny = 0,
       /**  Electro-optical.  Visible spectrum  */
       EO = 1,
       /**  Long-wave Infrared  */
       LWIR = 2,
       /**  Short-wave infrared  */
       SWIR = 3,
       /**  mid-wave infrared  */
       MWIR = 4,
       /**  Other or undefined wavelength band  */
       Other = 5

   };

   // generates a new WavelengthBand value for the passed string
   inline WavelengthBand get_WavelengthBand(std::string str) {
       if ( str == "AllAny") return AllAny;
       if ( str == "EO") return EO;
       if ( str == "LWIR") return LWIR;
       if ( str == "SWIR") return SWIR;
       if ( str == "MWIR") return MWIR;
       if ( str == "Other") return Other;
        return AllAny;

   }


   // generates a string value for the given enum
   inline std::string get_string(WavelengthBand e) {
       switch(e) {
        case AllAny: return "AllAny";
        case EO: return "EO";
        case LWIR: return "LWIR";
        case SWIR: return "SWIR";
        case MWIR: return "MWIR";
        case Other: return "Other";
        default: return "AllAny";

       }
   }

   }  // namespace WavelengthBand

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WAVELENGTHBAND_H_
