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

from afrl.cmasi import AutomationResponse
from afrl.impact import TaskSummary


class ImpactAutomationResponse(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 18
        self.SERIES_NAME = "IMPACT"
        self.FULL_LMCP_TYPE_NAME = "afrl.impact.ImpactAutomationResponse"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 5281966179208134656
        self.SERIES_VERSION = 14

        #Define message fields
        self.ResponseID = 0   #int64
        self.TrialResponse = AutomationResponse.AutomationResponse()   #AutomationResponse
        self.PlayID = 0   #int64
        self.SolutionID = 0   #int64
        self.Sandbox = False   #bool
        self.Summaries = []   #TaskSummary


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.ResponseID))
        buffer.extend(struct.pack("B", self.TrialResponse != None ))
        if self.TrialResponse != None:
            buffer.extend(struct.pack(">q", self.TrialResponse.SERIES_NAME_ID))
            buffer.extend(struct.pack(">I", self.TrialResponse.LMCP_TYPE))
            buffer.extend(struct.pack(">H", self.TrialResponse.SERIES_VERSION))
            buffer.extend(self.TrialResponse.pack())
        buffer.extend(struct.pack(">q", self.PlayID))
        buffer.extend(struct.pack(">q", self.SolutionID))
        boolChar = 1 if self.Sandbox == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        buffer.extend(struct.pack(">H", len(self.Summaries) ))
        for x in self.Summaries:
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
        self.ResponseID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
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
            self.TrialResponse = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
            _pos = self.TrialResponse.unpack(buffer, _pos)
        else:
            self.TrialResponse = None
        self.PlayID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.SolutionID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.Sandbox = True if boolChar == 1 else False
        _pos += 1
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.Summaries = [None] * _arraylen
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
                self.Summaries[x] = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
                _pos = self.Summaries[x].unpack(buffer, _pos)
            else:
                self.Summaries[x] = None
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "ResponseID" and len(e.childNodes) > 0 :
                    self.ResponseID = int(e.childNodes[0].nodeValue)
                elif e.localName == "TrialResponse" and len(e.childNodes) > 0 :
                    for n in e.childNodes:
                        if n.nodeType == xml.dom.Node.ELEMENT_NODE:
                            self.TrialResponse = seriesFactory.createObjectByName(n.getAttribute('Series'), n.localName)
                            if self.TrialResponse != None:
                                self.TrialResponse.unpackFromXMLNode(n, seriesFactory)
                elif e.localName == "PlayID" and len(e.childNodes) > 0 :
                    self.PlayID = int(e.childNodes[0].nodeValue)
                elif e.localName == "SolutionID" and len(e.childNodes) > 0 :
                    self.SolutionID = int(e.childNodes[0].nodeValue)
                elif e.localName == "Sandbox" and len(e.childNodes) > 0 :
                    self.Sandbox = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "Summaries" and len(e.childNodes) > 0 :
                    self.Summaries = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            obj = seriesFactory.createObjectByName(c.getAttribute('Series'), c.localName)
                            if obj != None:
                                obj.unpackFromXMLNode(c, seriesFactory)
                                self.Summaries.append(obj)

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "ResponseID":
                self.ResponseID = d[key]
            elif key == "TrialResponse":
                self.TrialResponse = seriesFactory.unpackFromDict(d[key])
            elif key == "PlayID":
                self.PlayID = d[key]
            elif key == "SolutionID":
                self.SolutionID = d[key]
            elif key == "Sandbox":
                self.Sandbox = d[key]
            elif key == "Summaries":
                self.Summaries = []
                for c in d[key]:
                    obj = seriesFactory.unpackFromDict(c)
                    if obj != None:
                        self.Summaries.append(obj)

        return

    def get_ResponseID(self):
        return self.ResponseID

    def set_ResponseID(self, value):
        self.ResponseID = int( value )

    def get_TrialResponse(self):
        return self.TrialResponse

    def set_TrialResponse(self, value):
        self.TrialResponse = value 

    def get_PlayID(self):
        return self.PlayID

    def set_PlayID(self, value):
        self.PlayID = int( value )

    def get_SolutionID(self):
        return self.SolutionID

    def set_SolutionID(self, value):
        self.SolutionID = int( value )

    def get_Sandbox(self):
        return self.Sandbox

    def set_Sandbox(self, value):
        self.Sandbox = bool( value )

    def get_Summaries(self):
        return self.Summaries



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From ImpactAutomationResponse:\n"
        buf +=    "ResponseID = " + str( self.ResponseID ) + "\n" 
        buf +=    "TrialResponse = " + str( self.TrialResponse ) + "\n" 
        buf +=    "PlayID = " + str( self.PlayID ) + "\n" 
        buf +=    "SolutionID = " + str( self.SolutionID ) + "\n" 
        buf +=    "Sandbox = " + str( self.Sandbox ) + "\n" 
        buf +=    "Summaries = " + str( self.Summaries ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("IMPACT" is None) or ("IMPACT" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/ImpactAutomationResponse")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("IMPACT" + "/ImpactAutomationResponse")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['ResponseID'] = self.ResponseID
        if self.TrialResponse == None:
            d['TrialResponse'] = None
        else:
            d['TrialResponse'] = self.TrialResponse.toDict()
        d['PlayID'] = self.PlayID
        d['SolutionID'] = self.SolutionID
        d['Sandbox'] = self.Sandbox
        d['Summaries'] = []
        for x in self.Summaries:
            if x == None:
                d['Summaries'].append(None)
            else:
                d['Summaries'].append(x.toDict())

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
        str = ws + '<ImpactAutomationResponse Series="IMPACT" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</ImpactAutomationResponse>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<ResponseID>" + str(self.ResponseID) + "</ResponseID>\n"
        buf += ws + "<TrialResponse>\n"
        if self.TrialResponse == None:
            buf += ws + "    <null/>\n"
        else:
            buf += ws + self.TrialResponse.toXMLStr(ws + "    ") 
        buf += ws + "</TrialResponse>\n"
        buf += ws + "<PlayID>" + str(self.PlayID) + "</PlayID>\n"
        buf += ws + "<SolutionID>" + str(self.SolutionID) + "</SolutionID>\n"
        buf += ws + "<Sandbox>" + ('True' if self.Sandbox else 'False') + "</Sandbox>\n"
        buf += ws + "<Summaries>\n"
        for x in self.Summaries:
            if x == None:
                buf += ws + "    <null/>\n"
            else:
                buf += x.toXMLStr(ws + "    ") 
        buf += ws + "</Summaries>\n"

        return buf
        
