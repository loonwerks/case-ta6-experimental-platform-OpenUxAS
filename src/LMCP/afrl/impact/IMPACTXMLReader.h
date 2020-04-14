// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _IMPACT_XMLREADER_H_
#define _IMPACT_XMLREADER_H_

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Node.h"
#include "avtas/lmcp/NodeUtil.h"

#include <iostream>


using namespace avtas::lmcp;

namespace afrl {
namespace impact {


class IMPACTXMLReader {

    /** reads an LMCP XML Storage file and returns a list of LMCPObjects */
    public:

        IMPACTXMLReader(void) {}

        virtual ~IMPACTXMLReader(){}  

        static avtas::lmcp::Object * visitType(avtas::lmcp::Node* el );

};

} // end namespace impact
} // end namespace afrl


#endif // _IMPACT_XMLREADER_H_
