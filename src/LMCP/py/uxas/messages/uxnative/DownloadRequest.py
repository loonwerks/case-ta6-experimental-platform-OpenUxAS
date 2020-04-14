#! /usr/bin/python

import sys, struct
import xml.dom.minidom
from lmcp import LMCPObject

## ===============================================================================
## Authors: AFRL/RQQA
## Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
## 
## Copyright (c) 2017 Government of the United State of America, as represented by
## the Secretary of the Air Force.  No copyright is claimed in the United States under
## Title 17, U.S. Code.  All Other Rights Reserved.
## ===============================================================================

## This file was auto-created by LmcpGen. Modifications will be overwritten.



class DownloadRequest(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 20
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.DownloadRequest"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.RequestedLmcpTypeName = ""   #string


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">H", len(self.RequestedLmcpTypeName) ))
        if len(self.RequestedLmcpTypeName) > 0:
            if (sys.version_info > (3, 0)):
                buffer.extend(struct.pack( repr(len(self.RequestedLmcpTypeName)) + "s", bytearray(self.RequestedLmcpTypeName,'ascii')))
            else:
                buffer.extend(struct.pack( repr(len(self.RequestedLmcpTypeName)) + "s", self.RequestedLmcpTypeName))

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        _strlen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        if _strlen > 0:
            self.RequestedLmcpTypeName = struct.unpack_from( repr(_strlen) + "s", buffer, _pos )[0]
            _pos += _strlen
        else:
             self.RequestedLmcpTypeName = ""
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "RequestedLmcpTypeName" and len(e.childNodes) > 0 :
                    self.RequestedLmcpTypeName = str(e.childNodes[0].nodeValue)

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "RequestedLmcpTypeName":
                self.RequestedLmcpTypeName = d[key]

        return

    def get_RequestedLmcpTypeName(self):
        return self.RequestedLmcpTypeName

    def set_RequestedLmcpTypeName(self, value):
        self.RequestedLmcpTypeName = str( value )



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From DownloadRequest:\n"
        buf +=    "RequestedLmcpTypeName = " + str( self.RequestedLmcpTypeName ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/DownloadRequest")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/DownloadRequest")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['RequestedLmcpTypeName'] = self.RequestedLmcpTypeName

        return

    def getLMCPType(self):
        return self.LMCP_TYPE

    def getSeriesName(self):
        return self.SERIES_NAME

    def getSeriesNameID(self):
        return self.SERIES_NAME_ID

    def getSeriesVersion(self):
        return self.SERIES_VERSION

    def toXMLStr(self, ws):
        str = ws + '<DownloadRequest Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</DownloadRequest>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<RequestedLmcpTypeName>" + str(self.RequestedLmcpTypeName) + "</RequestedLmcpTypeName>\n"

        return buf
        
