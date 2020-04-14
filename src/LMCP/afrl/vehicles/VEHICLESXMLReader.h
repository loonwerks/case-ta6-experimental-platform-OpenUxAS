// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _VEHICLES_XMLREADER_H_
#define _VEHICLES_XMLREADER_H_

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Node.h"
#include "avtas/lmcp/NodeUtil.h"

#include <iostream>


using namespace avtas::lmcp;

namespace afrl {
namespace vehicles {


class VEHICLESXMLReader {

    /** reads an LMCP XML Storage file and returns a list of LMCPObjects */
    public:

        VEHICLESXMLReader(void) {}

        virtual ~VEHICLESXMLReader(){}  

        static avtas::lmcp::Object * visitType(avtas::lmcp::Node* el );

};

} // end namespace vehicles
} // end namespace afrl


#endif // _VEHICLES_XMLREADER_H_
