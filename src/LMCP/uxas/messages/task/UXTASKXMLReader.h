// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXTASK_XMLREADER_H_
#define _UXTASK_XMLREADER_H_

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Node.h"
#include "avtas/lmcp/NodeUtil.h"

#include <iostream>


using namespace avtas::lmcp;

namespace uxas {
namespace messages {
namespace task {


class UXTASKXMLReader {

    /** reads an LMCP XML Storage file and returns a list of LMCPObjects */
    public:

        UXTASKXMLReader(void) {}

        virtual ~UXTASKXMLReader(){}  

        static avtas::lmcp::Object * visitType(avtas::lmcp::Node* el );

};

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXTASK_XMLREADER_H_
