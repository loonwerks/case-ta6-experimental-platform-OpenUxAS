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

from afrl.cmasi import KeepInZone
from afrl.cmasi import KeepOutZone
from afrl.cmasi import OperatingRegion


class ZeroizeCondition(LMCPObject.LMCPObject):

    def __init__(self):

        self.LMCP_TYPE = 19
        self.SERIES_NAME = "UXNATIVE"
        self.FULL_LMCP_TYPE_NAME = "uxas.messages.uxnative.ZeroizeCondition"
        #Series Name turned into a long for quick comparisons.
        self.SERIES_NAME_ID = 6149751333668345413
        self.SERIES_VERSION = 9

        #Define message fields
        self.VehicleID = 0   #int64
        self.ZeroizeOnLanding = False   #bool
        self.ZeroizeOnExitingOperationalArea = False   #bool
        self.ActiveOperationalArea = 0   #int64
        self.ZeroizeOnTasksComplete = False   #bool
        self.ZeroizeAccumulationTime = 10000   #int64
        self.ZeroizeHoldoffTime = 5000   #int64
        self.KeepInZones = []   #KeepInZone
        self.KeepOutZones = []   #KeepOutZone
        self.OperationalAreas = []   #OperatingRegion


    def pack(self):
        """
        Packs the object data and returns a string that contains all of the serialized
        members.
        """
        buffer = bytearray()
        buffer.extend(LMCPObject.LMCPObject.pack(self))
        buffer.extend(struct.pack(">q", self.VehicleID))
        boolChar = 1 if self.ZeroizeOnLanding == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        boolChar = 1 if self.ZeroizeOnExitingOperationalArea == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        buffer.extend(struct.pack(">q", self.ActiveOperationalArea))
        boolChar = 1 if self.ZeroizeOnTasksComplete == True else 0
        buffer.extend(struct.pack(">B",boolChar))
        buffer.extend(struct.pack(">q", self.ZeroizeAccumulationTime))
        buffer.extend(struct.pack(">q", self.ZeroizeHoldoffTime))
        buffer.extend(struct.pack(">H", len(self.KeepInZones) ))
        for x in self.KeepInZones:
           buffer.extend(struct.pack("B", x != None ))
           if x != None:
               buffer.extend(struct.pack(">q", x.SERIES_NAME_ID))
               buffer.extend(struct.pack(">I", x.LMCP_TYPE))
               buffer.extend(struct.pack(">H", x.SERIES_VERSION))
               buffer.extend(x.pack())
        buffer.extend(struct.pack(">H", len(self.KeepOutZones) ))
        for x in self.KeepOutZones:
           buffer.extend(struct.pack("B", x != None ))
           if x != None:
               buffer.extend(struct.pack(">q", x.SERIES_NAME_ID))
               buffer.extend(struct.pack(">I", x.LMCP_TYPE))
               buffer.extend(struct.pack(">H", x.SERIES_VERSION))
               buffer.extend(x.pack())
        buffer.extend(struct.pack(">H", len(self.OperationalAreas) ))
        for x in self.OperationalAreas:
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
        self.VehicleID = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeOnLanding = True if boolChar == 1 else False
        _pos += 1
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeOnExitingOperationalArea = True if boolChar == 1 else False
        _pos += 1
        self.ActiveOperationalArea = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        boolChar = struct.unpack_from(">B", buffer, _pos)[0]
        self.ZeroizeOnTasksComplete = True if boolChar == 1 else False
        _pos += 1
        self.ZeroizeAccumulationTime = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        self.ZeroizeHoldoffTime = struct.unpack_from(">q", buffer, _pos)[0]
        _pos += 8
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.KeepInZones = [None] * _arraylen
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
                self.KeepInZones[x] = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
                _pos = self.KeepInZones[x].unpack(buffer, _pos)
            else:
                self.KeepInZones[x] = None
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.KeepOutZones = [None] * _arraylen
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
                self.KeepOutZones[x] = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
                _pos = self.KeepOutZones[x].unpack(buffer, _pos)
            else:
                self.KeepOutZones[x] = None
        _arraylen = struct.unpack_from(">H", buffer, _pos )[0]
        _pos += 2
        self.OperationalAreas = [None] * _arraylen
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
                self.OperationalAreas[x] = LMCPFactory.LMCPFactory().createObject(_series, _version, _type )
                _pos = self.OperationalAreas[x].unpack(buffer, _pos)
            else:
                self.OperationalAreas[x] = None
        return _pos


    def unpackFromXMLNode(self, el, seriesFactory):
        LMCPObject.LMCPObject.unpackFromXMLNode(self, el, seriesFactory)
        for e in el.childNodes:
            if e.nodeType == xml.dom.Node.ELEMENT_NODE:
                if e.localName == "VehicleID" and len(e.childNodes) > 0 :
                    self.VehicleID = int(e.childNodes[0].nodeValue)
                elif e.localName == "ZeroizeOnLanding" and len(e.childNodes) > 0 :
                    self.ZeroizeOnLanding = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ZeroizeOnExitingOperationalArea" and len(e.childNodes) > 0 :
                    self.ZeroizeOnExitingOperationalArea = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ActiveOperationalArea" and len(e.childNodes) > 0 :
                    self.ActiveOperationalArea = int(e.childNodes[0].nodeValue)
                elif e.localName == "ZeroizeOnTasksComplete" and len(e.childNodes) > 0 :
                    self.ZeroizeOnTasksComplete = e.childNodes[0].nodeValue.lower() == 'true'
                elif e.localName == "ZeroizeAccumulationTime" and len(e.childNodes) > 0 :
                    self.ZeroizeAccumulationTime = int(e.childNodes[0].nodeValue)
                elif e.localName == "ZeroizeHoldoffTime" and len(e.childNodes) > 0 :
                    self.ZeroizeHoldoffTime = int(e.childNodes[0].nodeValue)
                elif e.localName == "KeepInZones" and len(e.childNodes) > 0 :
                    self.KeepInZones = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            obj = seriesFactory.createObjectByName(c.getAttribute('Series'), c.localName)
                            if obj != None:
                                obj.unpackFromXMLNode(c, seriesFactory)
                                self.KeepInZones.append(obj)
                elif e.localName == "KeepOutZones" and len(e.childNodes) > 0 :
                    self.KeepOutZones = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            obj = seriesFactory.createObjectByName(c.getAttribute('Series'), c.localName)
                            if obj != None:
                                obj.unpackFromXMLNode(c, seriesFactory)
                                self.KeepOutZones.append(obj)
                elif e.localName == "OperationalAreas" and len(e.childNodes) > 0 :
                    self.OperationalAreas = []
                    for c in e.childNodes:
                        if c.nodeType == xml.dom.Node.ELEMENT_NODE:
                            obj = seriesFactory.createObjectByName(c.getAttribute('Series'), c.localName)
                            if obj != None:
                                obj.unpackFromXMLNode(c, seriesFactory)
                                self.OperationalAreas.append(obj)

        return

    def unpackFromDict(self, d, seriesFactory):
        LMCPObject.LMCPObject.unpackFromDict(self, d, seriesFactory)
        for key in d:
            if key == "VehicleID":
                self.VehicleID = d[key]
            elif key == "ZeroizeOnLanding":
                self.ZeroizeOnLanding = d[key]
            elif key == "ZeroizeOnExitingOperationalArea":
                self.ZeroizeOnExitingOperationalArea = d[key]
            elif key == "ActiveOperationalArea":
                self.ActiveOperationalArea = d[key]
            elif key == "ZeroizeOnTasksComplete":
                self.ZeroizeOnTasksComplete = d[key]
            elif key == "ZeroizeAccumulationTime":
                self.ZeroizeAccumulationTime = d[key]
            elif key == "ZeroizeHoldoffTime":
                self.ZeroizeHoldoffTime = d[key]
            elif key == "KeepInZones":
                self.KeepInZones = []
                for c in d[key]:
                    obj = seriesFactory.unpackFromDict(c)
                    if obj != None:
                        self.KeepInZones.append(obj)
            elif key == "KeepOutZones":
                self.KeepOutZones = []
                for c in d[key]:
                    obj = seriesFactory.unpackFromDict(c)
                    if obj != None:
                        self.KeepOutZones.append(obj)
            elif key == "OperationalAreas":
                self.OperationalAreas = []
                for c in d[key]:
                    obj = seriesFactory.unpackFromDict(c)
                    if obj != None:
                        self.OperationalAreas.append(obj)

        return

    def get_VehicleID(self):
        return self.VehicleID

    def set_VehicleID(self, value):
        self.VehicleID = int( value )

    def get_ZeroizeOnLanding(self):
        return self.ZeroizeOnLanding

    def set_ZeroizeOnLanding(self, value):
        self.ZeroizeOnLanding = bool( value )

    def get_ZeroizeOnExitingOperationalArea(self):
        return self.ZeroizeOnExitingOperationalArea

    def set_ZeroizeOnExitingOperationalArea(self, value):
        self.ZeroizeOnExitingOperationalArea = bool( value )

    def get_ActiveOperationalArea(self):
        return self.ActiveOperationalArea

    def set_ActiveOperationalArea(self, value):
        self.ActiveOperationalArea = int( value )

    def get_ZeroizeOnTasksComplete(self):
        return self.ZeroizeOnTasksComplete

    def set_ZeroizeOnTasksComplete(self, value):
        self.ZeroizeOnTasksComplete = bool( value )

    def get_ZeroizeAccumulationTime(self):
        return self.ZeroizeAccumulationTime

    def set_ZeroizeAccumulationTime(self, value):
        self.ZeroizeAccumulationTime = int( value )

    def get_ZeroizeHoldoffTime(self):
        return self.ZeroizeHoldoffTime

    def set_ZeroizeHoldoffTime(self, value):
        self.ZeroizeHoldoffTime = int( value )

    def get_KeepInZones(self):
        return self.KeepInZones

    def get_KeepOutZones(self):
        return self.KeepOutZones

    def get_OperationalAreas(self):
        return self.OperationalAreas



    def toString(self):
        """
        Returns a string representation of all variables
        """
        buf = LMCPObject.LMCPObject.toString(self)
        buf += "From ZeroizeCondition:\n"
        buf +=    "VehicleID = " + str( self.VehicleID ) + "\n" 
        buf +=    "ZeroizeOnLanding = " + str( self.ZeroizeOnLanding ) + "\n" 
        buf +=    "ZeroizeOnExitingOperationalArea = " + str( self.ZeroizeOnExitingOperationalArea ) + "\n" 
        buf +=    "ActiveOperationalArea = " + str( self.ActiveOperationalArea ) + "\n" 
        buf +=    "ZeroizeOnTasksComplete = " + str( self.ZeroizeOnTasksComplete ) + "\n" 
        buf +=    "ZeroizeAccumulationTime = " + str( self.ZeroizeAccumulationTime ) + "\n" 
        buf +=    "ZeroizeHoldoffTime = " + str( self.ZeroizeHoldoffTime ) + "\n" 
        buf +=    "KeepInZones = " + str( self.KeepInZones ) + "\n" 
        buf +=    "KeepOutZones = " + str( self.KeepOutZones ) + "\n" 
        buf +=    "OperationalAreas = " + str( self.OperationalAreas ) + "\n" 

        return buf;

    def toDict(self):
        m = {}
        self.toDictMembers(m)
        d = {}
        if ("UXNATIVE" is None) or ("UXNATIVE" is ""): # this should never happen
            # need to fill this with error message
            d["datatype"] = str("DEBUG_PROBLEM_HERE" + "/ZeroizeCondition")
            d["datastring"] = str(m)
        else:
            d['datatype'] = str("UXNATIVE" + "/ZeroizeCondition")
            d['datastring'] = str(m)
        return d

    def toDictMembers(self, d):
        LMCPObject.LMCPObject.toDictMembers(self, d)
        d['VehicleID'] = self.VehicleID
        d['ZeroizeOnLanding'] = self.ZeroizeOnLanding
        d['ZeroizeOnExitingOperationalArea'] = self.ZeroizeOnExitingOperationalArea
        d['ActiveOperationalArea'] = self.ActiveOperationalArea
        d['ZeroizeOnTasksComplete'] = self.ZeroizeOnTasksComplete
        d['ZeroizeAccumulationTime'] = self.ZeroizeAccumulationTime
        d['ZeroizeHoldoffTime'] = self.ZeroizeHoldoffTime
        d['KeepInZones'] = []
        for x in self.KeepInZones:
            if x == None:
                d['KeepInZones'].append(None)
            else:
                d['KeepInZones'].append(x.toDict())
        d['KeepOutZones'] = []
        for x in self.KeepOutZones:
            if x == None:
                d['KeepOutZones'].append(None)
            else:
                d['KeepOutZones'].append(x.toDict())
        d['OperationalAreas'] = []
        for x in self.OperationalAreas:
            if x == None:
                d['OperationalAreas'].append(None)
            else:
                d['OperationalAreas'].append(x.toDict())

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
        str = ws + '<ZeroizeCondition Series="UXNATIVE" >\n';
        #str +=LMCPObject.LMCPObject.toXMLMembersStr(self, ws + "  ")
        str += self.toXMLMembersStr(ws + "  ")
        str += ws + "</ZeroizeCondition>\n";
        return str

    def toXMLMembersStr(self, ws):
        buf = ""
        buf += LMCPObject.LMCPObject.toXMLMembersStr(self, ws)
        buf += ws + "<VehicleID>" + str(self.VehicleID) + "</VehicleID>\n"
        buf += ws + "<ZeroizeOnLanding>" + ('True' if self.ZeroizeOnLanding else 'False') + "</ZeroizeOnLanding>\n"
        buf += ws + "<ZeroizeOnExitingOperationalArea>" + ('True' if self.ZeroizeOnExitingOperationalArea else 'False') + "</ZeroizeOnExitingOperationalArea>\n"
        buf += ws + "<ActiveOperationalArea>" + str(self.ActiveOperationalArea) + "</ActiveOperationalArea>\n"
        buf += ws + "<ZeroizeOnTasksComplete>" + ('True' if self.ZeroizeOnTasksComplete else 'False') + "</ZeroizeOnTasksComplete>\n"
        buf += ws + "<ZeroizeAccumulationTime>" + str(self.ZeroizeAccumulationTime) + "</ZeroizeAccumulationTime>\n"
        buf += ws + "<ZeroizeHoldoffTime>" + str(self.ZeroizeHoldoffTime) + "</ZeroizeHoldoffTime>\n"
        buf += ws + "<KeepInZones>\n"
        for x in self.KeepInZones:
            if x == None:
                buf += ws + "    <null/>\n"
            else:
                buf += x.toXMLStr(ws + "    ") 
        buf += ws + "</KeepInZones>\n"
        buf += ws + "<KeepOutZones>\n"
        for x in self.KeepOutZones:
            if x == None:
                buf += ws + "    <null/>\n"
            else:
                buf += x.toXMLStr(ws + "    ") 
        buf += ws + "</KeepOutZones>\n"
        buf += ws + "<OperationalAreas>\n"
        for x in self.OperationalAreas:
            if x == None:
                buf += ws + "    <null/>\n"
            else:
                buf += x.toXMLStr(ws + "    ") 
        buf += ws + "</OperationalAreas>\n"

        return buf
        
