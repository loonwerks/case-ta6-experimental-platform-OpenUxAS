// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _ROUTE_XMLREADER_H_
#define _ROUTE_XMLREADER_H_

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Node.h"
#include "avtas/lmcp/NodeUtil.h"

#include <iostream>


using namespace avtas::lmcp;

namespace uxas {
namespace messages {
namespace route {


class ROUTEXMLReader {

    /** reads an LMCP XML Storage file and returns a list of LMCPObjects */
    public:

        ROUTEXMLReader(void) {}

        virtual ~ROUTEXMLReader(){}  

        static avtas::lmcp::Object * visitType(avtas::lmcp::Node* el );

};

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _ROUTE_XMLREADER_H_
