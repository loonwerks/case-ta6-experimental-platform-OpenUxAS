// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AVTAS_LMCP_LMCPXMLREADER_H_
#define _AVTAS_LMCP_LMCPXMLREADER_H_

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Node.h"
#include "avtas/lmcp/NodeUtil.h"
#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include "avtas/lmcp/XMLParser.h"

#include "uxas/messages/uxnative/UXNATIVEXMLReader.h"
#include "uxas/messages/task/UXTASKXMLReader.h"
#include "uxas/messages/route/ROUTEXMLReader.h"
#include "afrl/cmasi/perceive/PERCEIVEXMLReader.h"
#include "afrl/vehicles/VEHICLESXMLReader.h"
#include "afrl/impact/IMPACTXMLReader.h"
#include "afrl/cmasi/CMASIXMLReader.h"


namespace avtas {
namespace lmcp {
namespace xml {

        inline avtas::lmcp::Object* readXML(Node* node) {
            if (node == nullptr) return nullptr;
            if (node->getAttribute("Series") == "UXNATIVE") return uxas::messages::uxnative::UXNATIVEXMLReader::visitType(node);
            if (node->getAttribute("Series") == "UXTASK") return uxas::messages::task::UXTASKXMLReader::visitType(node);
            if (node->getAttribute("Series") == "ROUTE") return uxas::messages::route::ROUTEXMLReader::visitType(node);
            if (node->getAttribute("Series") == "PERCEIVE") return afrl::cmasi::perceive::PERCEIVEXMLReader::visitType(node);
            if (node->getAttribute("Series") == "VEHICLES") return afrl::vehicles::VEHICLESXMLReader::visitType(node);
            if (node->getAttribute("Series") == "IMPACT") return afrl::impact::IMPACTXMLReader::visitType(node);
            if (node->getAttribute("Series") == "CMASI") return afrl::cmasi::CMASIXMLReader::visitType(node);

            return nullptr;
        }

        /** reads an LMCP XML string and returns an LMCP object */
        inline avtas::lmcp::Object* readXML(std::string input) {
            Node* el = avtas::lmcp::XMLParser::parseString(input, false);
            return readXML(el);
        }

        inline bool get_bool(Node* node) {
            return node->getBool(false);
        }

        inline char get_byte(Node* node) {
            return (char) node->getInt(0);
        }
        
        inline char get_char(Node* node) {
            std::string str = node->getText();
            return (char) str.size() == 0 ? 0 : str[0];
        }

        inline int16_t get_int16(Node* node) {
            return (int16_t) node->getInt(0);
        }

        inline uint16_t get_uint16(Node* node) {
            return (uint16_t) node->getInt(0);
        }

        inline int32_t get_int32(Node* node) {
            return node->getInt(0);
        }

        inline uint32_t get_uint32(Node* node) {
            return (uint32_t) node->getLong(0);
        }

        inline int64_t get_int64(Node* node) {
            return node->getLong(0);
        }

        inline float get_real32(Node* node) {
            return node->getFloat(0);
        }

        inline double get_real64(Node* node) {
            return node->getDouble(0);
        }

        inline std::string get_string(Node* node) {
            return node->getText();
        }

} // end namespace xml
} // end namespace lmcp
} // end namespace avtas

#endif //_AVTAS_LMCP_LMCPXMLREADER_H

