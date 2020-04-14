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

from uxas.messages.uxnative import File


class FileTransfer(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 24
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.FileTransfer"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.Nonce = 0   #int64
        self.DestinationEntityID = 0   #int64
        self.Files = []   #File


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.Nonce))
        buffer.extend(struct.pack(">q", self.DestinationEntityID))
        buffer.extend(struct.pack(">H", len(self.Files) ))
        for x in self.Files:
           buffer.extend(struct.pack("B", x != None ))
           if x != None:
               buffer.extend(struct.pack(">q", x.SERIES_NAME_ID))
               buffer.extend(struct.pack(">I", x.LMCP_TYPE))
               buffer.extend(struct.pack(">H", x.SERIES_VERSION))
               buffer.extend(x.pack())

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        self.Nonce = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.DestinationEntityID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.Files = [None] * _arraylen
        for x in range(_arraylen):
            _valid = struct.unpack_from("B", buffer, _pos )[0]
            _pos += 1
            if _valid:
                _series = struct.unpack_from(">q", buffer, _pos)[0]
                _pos += 8
                _type = struct.unpack_from(">I", buffer, _pos)[0]
                _pos += 4
                _version = struct.unpack_from(">H", buffer, _pos)[0]
                _pos += 2
                from lmcp import LMCPFactory
                self.Files[x] = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
                _pos = self.Files[x].unpack(buffer, _pos)
            else:
                self.Files[x] = None
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "Nonce" and len(e.childNodes) > 0 :
                    self.Nonce = int(e.childNodes[0].nodeValue)
                elif e.localName == "DestinationEntityID" and len(e.childNodes) > 0 :
                    self.DestinationEntityID = int(e.childNodes[0].nodeValue)
                elif e.localName == "Files" and len(e.childNodes) > 0 :
                    self.Files = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            obj = seriesFactory.createObjectByName(c.getAttribute('Series'), c.localName)
                            if obj != None:
                                obj.unpackFromXMLNode(c, seriesFactory)
                                self.Files.append(obj)

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "Nonce":
                self.Nonce = d[key]
            elif key == "DestinationEntityID":
                self.DestinationEntityID = d[key]
            elif key == "Files":
                self.Files = []
                for c in d[key]:
                    obj = seriesFactory.unpackFromDict(c)
                    if obj != None:
                        self.Files.append(obj)

        return

    def get_Nonce(self):
        return self.Nonce

    def set_Nonce(self, value):
        self.Nonce = int( value )

    def get_DestinationEntityID(self):
        return self.DestinationEntityID

    def set_DestinationEntityID(self, value):
        self.DestinationEntityID = int( value )

    def get_Files(self):
        return self.Files



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From FileTransfer:\n"
        buf +=    "Nonce = " + str( self.Nonce ) + "\n" 
        buf +=    "DestinationEntityID = " + str( self.DestinationEntityID ) + "\n" 
        buf +=    "Files = " + str( self.Files ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/FileTransfer")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/FileTransfer")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['Nonce'] = self.Nonce
        d['DestinationEntityID'] = self.DestinationEntityID
        d['Files'] = []
        for x in self.Files:
            if x == None:
                d['Files'].append(None)
            else:
                d['Files'].append(x.toDict())

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
        str = ws + '<FileTransfer Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</FileTransfer>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<Nonce>" + str(self.Nonce) + "</Nonce>\n"
        buf += ws + "<DestinationEntityID>" + str(self.DestinationEntityID) + "</DestinationEntityID>\n"
        buf += ws + "<Files>\n"
        for x in self.Files:
            if x == None:
                buf += ws + "    <null/>\n"
            else:
                buf += x.toXMLStr(ws + "    ") 
        buf += ws + "</Files>\n"

        return buf
        
