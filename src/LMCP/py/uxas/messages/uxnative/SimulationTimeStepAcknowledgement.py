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



class SimulationTimeStepAcknowledgement(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 16
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.SimulationTimeStepAcknowledgement"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.VehicleID = 0   #int64
        self.ReportedTime = 0   #int64


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.VehicleID))
        buffer.extend(struct.pack(">q", self.ReportedTime))

        return buffer

    def unpack(self, buffer, _pos):
        """
        Unpacks data from a bytearray and sets class members
        """
        _pos = LMCPObject.LMCPObject.unpack(self, buffer, _pos)
        self.VehicleID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.ReportedTime = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "VehicleID" and len(e.childNodes) > 0 :
                    self.VehicleID = int(e.childNodes[0].nodeValue)
                elif e.localName == "ReportedTime" and len(e.childNodes) > 0 :
                    self.ReportedTime = int(e.childNodes[0].nodeValue)

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "VehicleID":
                self.VehicleID = d[key]
            elif key == "ReportedTime":
                self.ReportedTime = d[key]

        return

    def get_VehicleID(self):
        return self.VehicleID

    def set_VehicleID(self, value):
        self.VehicleID = int( value )

    def get_ReportedTime(self):
        return self.ReportedTime

    def set_ReportedTime(self, value):
        self.ReportedTime = int( value )



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From SimulationTimeStepAcknowledgement:\n"
        buf +=    "VehicleID = " + str( self.VehicleID ) + "\n" 
        buf +=    "ReportedTime = " + str( self.ReportedTime ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/SimulationTimeStepAcknowledgement")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/SimulationTimeStepAcknowledgement")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['VehicleID'] = self.VehicleID
        d['ReportedTime'] = self.ReportedTime

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
        str = ws + '<SimulationTimeStepAcknowledgement Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</SimulationTimeStepAcknowledgement>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<VehicleID>" + str(self.VehicleID) + "</VehicleID>\n"
        buf += ws + "<ReportedTime>" + str(self.ReportedTime) + "</ReportedTime>\n"

        return buf
        
