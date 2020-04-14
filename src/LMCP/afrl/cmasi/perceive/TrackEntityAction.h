// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_PERCEIVE_TRACKENTITYACTION_H_
#define _AFRL_CMASI_PERCEIVE_TRACKENTITYACTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "PERCEIVEEnum.h"
#include "afrl/cmasi/VehicleAction.h"



namespace afrl {
namespace cmasi {
namespace perceive {


   bool isTrackEntityAction(avtas::lmcp::Object* obj);
   bool isTrackEntityAction(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > TrackEntityActionDescendants();
   
   class TrackEntityAction : public afrl::cmasi::VehicleAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      TrackEntityAction(void);

      // Copy Constructor
      TrackEntityAction(const TrackEntityAction &that);

      // Assignment Operator
      TrackEntityAction & operator=(const TrackEntityAction &that);

      // Destructor
      virtual ~TrackEntityAction(void);

      // Equals overload
      bool operator==(const TrackEntityAction & that);
      bool operator!=(const TrackEntityAction & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual TrackEntityAction* clone() const;

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
      /** The unique identifier of the target to be tracked. (Units: None)*/
      uint32_t getEntityID(void) const { return __EntityID; }
      TrackEntityAction& setEntityID(const uint32_t val);

      /** The unique identifier of the sensor that is to be actively steered to track the target. (Units: None)*/
      uint32_t getSensorID(void) const { return __SensorID; }
      TrackEntityAction& setSensorID(const uint32_t val);

      /** The waypoint that this vehicle is to return to when complete (or lost track) (Units: None)*/
      uint32_t getReturnToWaypoint(void) const { return __ReturnToWaypoint; }
      TrackEntityAction& setReturnToWaypoint(const uint32_t val);



   protected:
      /** The unique identifier of the target to be tracked. */
      uint32_t __EntityID;
      /** The unique identifier of the sensor that is to be actively steered to track the target. */
      uint32_t __SensorID;
      /** The waypoint that this vehicle is to return to when complete (or lost track) */
      uint32_t __ReturnToWaypoint;

   };

} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_PERCEIVE_TRACKENTITYACTION_H_
