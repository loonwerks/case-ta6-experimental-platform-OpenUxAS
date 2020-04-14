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



class File(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 23
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.File"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.FileName = ""   #string
        self.FileContents = []   #byte


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">H", len(self.FileName) ))
        if len(self.FileName) > 0:
            if (sys.version_info > (3, 0)):
                buffer.extend(struct.pack( repr(len(self.FileName)) + "s", bytearray(self.FileName,'ascii')))
            else:
                buffer.extend(struct.pack( repr(len(self.FileName)) + "s", self.FileName))
        buffer.extend(struct.pack(">H", len(self.FileContents) ))
        for x in self.FileContents:
            buffer.extend(struct.pack(">B", x ))

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        _strlen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        if _strlen > 0:
            self.FileName = struct.unpack_from( repr(_strlen) + "s", buffer, _pos )[0]
            _pos += _strlen
        else:
             self.FileName = ""
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.FileContents = [None] * _arraylen
        if _arraylen > 0:
            self.FileContents = struct.unpack_from(">" + repr(_arraylen) + "B", buffer, _pos )
            _pos += 1 * _arraylen
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "FileName" and len(e.childNodes) > 0 :
                    self.FileName = str(e.childNodes[0].nodeValue)
                elif e.localName == "FileContents" and len(e.childNodes) > 0 :
                    self.FileContents = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            self.FileContents.append( int(c.childNodes[0].nodeValue) )

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "FileName":
                self.FileName = d[key]
            elif key == "FileContents":
                self.FileContents = []
                for c in d[key]:
                    self.FileContents.append( c )

        return

    def get_FileName(self):
        return self.FileName

    def set_FileName(self, value):
        self.FileName = str( value )

    def get_FileContents(self):
        return self.FileContents



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From File:\n"
        buf +=    "FileName = " + str( self.FileName ) + "\n" 
        buf +=    "FileContents = " + str( self.FileContents ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/File")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/File")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['FileName'] = self.FileName
        d['FileContents'] = []
        for x in self.FileContents:
            d['FileContents'].append(x)

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
        str = ws + '<File Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</File>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<FileName>" + str(self.FileName) + "</FileName>\n"
        buf += ws + "<FileContents>\n"
        for x in self.FileContents:
            buf += ws + "<byte>" + str(x) + "</byte>\n"
        buf += ws + "</FileContents>\n"

        return buf
        
