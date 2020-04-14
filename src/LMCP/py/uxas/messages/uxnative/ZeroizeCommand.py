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



class ZeroizeCommand(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 18
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.ZeroizeCommand"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.EntityID = 0   #int64
        self.ZeroizeKeys = False   #bool
        self.ZeroizeLogs = False   #bool
        self.ZeroizeData = False   #bool
        self.ZeroizeTasks = False   #bool


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.EntityID))
        boolChar = 1 if self.ZeroizeKeys == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        boolChar = 1 if self.ZeroizeLogs == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        boolChar = 1 if self.ZeroizeData == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        boolChar = 1 if self.ZeroizeTasks == True else 0
        buffer.extend(struct.pack(">B",boolChar))

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        self.EntityID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeKeys = True if boolChar == 1 else False
        _pos += 1
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeLogs = True if boolChar == 1 else False
        _pos += 1
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeData = True if boolChar == 1 else False
        _pos += 1
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeTasks = True if boolChar == 1 else False
        _pos += 1
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "EntityID" and len(e.childNodes) > 0 :
                    self.EntityID = int(e.childNodes[0].nodeValue)
                elif e.localName == "ZeroizeKeys" and len(e.childNodes) > 0 :
                    self.ZeroizeKeys = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ZeroizeLogs" and len(e.childNodes) > 0 :
                    self.ZeroizeLogs = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ZeroizeData" and len(e.childNodes) > 0 :
                    self.ZeroizeData = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ZeroizeTasks" and len(e.childNodes) > 0 :
                    self.ZeroizeTasks = e.childNodes[0].nodeValue.lower() == 'true'

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "EntityID":
                self.EntityID = d[key]
            elif key == "ZeroizeKeys":
                self.ZeroizeKeys = d[key]
            elif key == "ZeroizeLogs":
                self.ZeroizeLogs = d[key]
            elif key == "ZeroizeData":
                self.ZeroizeData = d[key]
            elif key == "ZeroizeTasks":
                self.ZeroizeTasks = d[key]

        return

    def get_EntityID(self):
        return self.EntityID

    def set_EntityID(self, value):
        self.EntityID = int( value )

    def get_ZeroizeKeys(self):
        return self.ZeroizeKeys

    def set_ZeroizeKeys(self, value):
        self.ZeroizeKeys = bool( value )

    def get_ZeroizeLogs(self):
        return self.ZeroizeLogs

    def set_ZeroizeLogs(self, value):
        self.ZeroizeLogs = bool( value )

    def get_ZeroizeData(self):
        return self.ZeroizeData

    def set_ZeroizeData(self, value):
        self.ZeroizeData = bool( value )

    def get_ZeroizeTasks(self):
        return self.ZeroizeTasks

    def set_ZeroizeTasks(self, value):
        self.ZeroizeTasks = bool( value )



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From ZeroizeCommand:\n"
        buf +=    "EntityID = " + str( self.EntityID ) + "\n" 
        buf +=    "ZeroizeKeys = " + str( self.ZeroizeKeys ) + "\n" 
        buf +=    "ZeroizeLogs = " + str( self.ZeroizeLogs ) + "\n" 
        buf +=    "ZeroizeData = " + str( self.ZeroizeData ) + "\n" 
        buf +=    "ZeroizeTasks = " + str( self.ZeroizeTasks ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/ZeroizeCommand")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/ZeroizeCommand")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['EntityID'] = self.EntityID
        d['ZeroizeKeys'] = self.ZeroizeKeys
        d['ZeroizeLogs'] = self.ZeroizeLogs
        d['ZeroizeData'] = self.ZeroizeData
        d['ZeroizeTasks'] = self.ZeroizeTasks

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
        str = ws + '<ZeroizeCommand Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</ZeroizeCommand>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<EntityID>" + str(self.EntityID) + "</EntityID>\n"
        buf += ws + "<ZeroizeKeys>" + ('True' if self.ZeroizeKeys else 'False') + "</ZeroizeKeys>\n"
        buf += ws + "<ZeroizeLogs>" + ('True' if self.ZeroizeLogs else 'False') + "</ZeroizeLogs>\n"
        buf += ws + "<ZeroizeData>" + ('True' if self.ZeroizeData else 'False') + "</ZeroizeData>\n"
        buf += ws + "<ZeroizeTasks>" + ('True' if self.ZeroizeTasks else 'False') + "</ZeroizeTasks>\n"

        return buf
        
