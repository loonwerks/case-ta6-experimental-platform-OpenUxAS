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



class FileTransferRequest(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 22
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.FileTransferRequest"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.Nonce = 0   #int64
        self.SourceEntityID = 0   #int64
        self.DestinationEntityID = 0   #int64
        self.FileNames = []   #string


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.Nonce))
        buffer.extend(struct.pack(">q", self.SourceEntityID))
        buffer.extend(struct.pack(">q", self.DestinationEntityID))
        buffer.extend(struct.pack(">H", len(self.FileNames) ))
        for x in self.FileNames:
            buffer.extend(struct.pack(">H", len(x) ))
            if len(x) > 0:
                if (sys.version_info > (3, 0)):
                    buffer.extend(struct.pack( repr(len(self.FileNames[x])) + "s", bytearray(self.FileNames[x],'ascii')))
                else:
                    buffer.extend(struct.pack( repr(len(self.FileNames[x])) + "s", self.FileNames[x]))

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        self.Nonce = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.SourceEntityID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.DestinationEntityID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.FileNames = [None] * _arraylen
        for x in range(_arraylen):
            _strlen = struct.unpack_from(">H", buffer, _pos )[0]
            _pos += 2
            if _strlen > 0:
                self.FileNames[x] = struct.unpack_from( repr(_strlen) + "s", buffer, _pos )[0]
                _pos += _strlen
            else:
                 self.FileNames[x] = ""
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "Nonce" and len(e.childNodes) > 0 :
                    self.Nonce = int(e.childNodes[0].nodeValue)
                elif e.localName == "SourceEntityID" and len(e.childNodes) > 0 :
                    self.SourceEntityID = int(e.childNodes[0].nodeValue)
                elif e.localName == "DestinationEntityID" and len(e.childNodes) > 0 :
                    self.DestinationEntityID = int(e.childNodes[0].nodeValue)
                elif e.localName == "FileNames" and len(e.childNodes) > 0 :
                    self.FileNames = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            self.FileNames.append( str(c.childNodes[0].nodeValue) )

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "Nonce":
                self.Nonce = d[key]
            elif key == "SourceEntityID":
                self.SourceEntityID = d[key]
            elif key == "DestinationEntityID":
                self.DestinationEntityID = d[key]
            elif key == "FileNames":
                self.FileNames = []
                for c in d[key]:
                    self.FileNames.append( c )

        return

    def get_Nonce(self):
        return self.Nonce

    def set_Nonce(self, value):
        self.Nonce = int( value )

    def get_SourceEntityID(self):
        return self.SourceEntityID

    def set_SourceEntityID(self, value):
        self.SourceEntityID = int( value )

    def get_DestinationEntityID(self):
        return self.DestinationEntityID

    def set_DestinationEntityID(self, value):
        self.DestinationEntityID = int( value )

    def get_FileNames(self):
        return self.FileNames



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From FileTransferRequest:\n"
        buf +=    "Nonce = " + str( self.Nonce ) + "\n" 
        buf +=    "SourceEntityID = " + str( self.SourceEntityID ) + "\n" 
        buf +=    "DestinationEntityID = " + str( self.DestinationEntityID ) + "\n" 
        buf +=    "FileNames = " + str( self.FileNames ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/FileTransferRequest")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/FileTransferRequest")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['Nonce'] = self.Nonce
        d['SourceEntityID'] = self.SourceEntityID
        d['DestinationEntityID'] = self.DestinationEntityID
        d['FileNames'] = []
        for x in self.FileNames:
            d['FileNames'].append(x)

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
        str = ws + '<FileTransferRequest Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</FileTransferRequest>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<Nonce>" + str(self.Nonce) + "</Nonce>\n"
        buf += ws + "<SourceEntityID>" + str(self.SourceEntityID) + "</SourceEntityID>\n"
        buf += ws + "<DestinationEntityID>" + str(self.DestinationEntityID) + "</DestinationEntityID>\n"
        buf += ws + "<FileNames>\n"
        for x in self.FileNames:
            buf += ws + "<string>" + str(x) + "</string>\n"
        buf += ws + "</FileNames>\n"

        return buf
        
