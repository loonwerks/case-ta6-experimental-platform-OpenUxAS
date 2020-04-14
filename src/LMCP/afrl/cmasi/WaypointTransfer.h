// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WAYPOINTTRANSFER_H_
#define _AFRL_CMASI_WAYPOINTTRANSFER_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Waypoint.h"
#include "afrl/cmasi/WaypointTransferMode.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isWaypointTransfer(avtas::lmcp::Object* obj);
   bool isWaypointTransfer(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > WaypointTransferDescendants();
   
   class WaypointTransfer : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      WaypointTransfer(void);

      // Copy Constructor
      WaypointTransfer(const WaypointTransfer &that);

      // Assignment Operator
      WaypointTransfer & operator=(const WaypointTransfer &that);

      // Destructor
      virtual ~WaypointTransfer(void);

      // Equals overload
      bool operator==(const WaypointTransfer & that);
      bool operator!=(const WaypointTransfer & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual WaypointTransfer* clone() const;

      // Returns string representation of object
      virtual std::string toString(int32_t depth=0) const;

      // Returns an XML string representation of the object.
      virtual std::string toXML(int32_t depth=0);

      // Returns object type id
      virtual uint32_t getLmcpType(void) const { return TypeId; }
	  
      // Returns object type name string
      virtual std::string getLmcpTypeName(void) const { return TypeName; }
	  
      // Returns object type name string with full namespace prepended, same as subscription name
      virtual std::string getFullLmcpTypeName(void) const { return Subscription; }

      // Returns series name string
      virtual std::string getSeriesName(void) const { return SeriesName; }

      // gets the series name as a long value
      virtual int64_t getSeriesNameAsLong(void) const { return SeriesId; }

      //gets the version number of the series
      virtual uint16_t getSeriesVersion(void) const { return SeriesVersion; }

      // Accessors and Modifiers
      /** ID of the entity assoicated with the waypoints (Units: None)*/
      int64_t getEntityID(void) const { return __EntityID; }
      WaypointTransfer& setEntityID(const int64_t val);

      /** A list of wayppoints to transfer. This may be empty if the transfer type is "RequestWaypoints" or "ClearWaypoints" (Units: None)*/
      std::vector<afrl::cmasi::Waypoint*> & getWaypoints(void) { return __Waypoints; }

      /** describes the transfer action to take (Units: None)*/
      afrl::cmasi::WaypointTransferMode::WaypointTransferMode getTransferMode(void) const { return __TransferMode; }
      WaypointTransfer& setTransferMode(const afrl::cmasi::WaypointTransferMode::WaypointTransferMode val);



   protected:
      /** ID of the entity assoicated with the waypoints */
      int64_t __EntityID;
      /** A list of wayppoints to transfer. This may be empty if the transfer type is "RequestWaypoints" or "ClearWaypoints" */
      std::vector< afrl::cmasi::Waypoint* > __Waypoints;
      /** describes the transfer action to take */
      afrl::cmasi::WaypointTransferMode::WaypointTransferMode __TransferMode;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WAYPOINTTRANSFER_H_
