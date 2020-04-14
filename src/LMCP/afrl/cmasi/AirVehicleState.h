// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_AIRVEHICLESTATE_H_
#define _AFRL_CMASI_AIRVEHICLESTATE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/EntityState.h"



namespace afrl {
namespace cmasi {


   bool isAirVehicleState(avtas::lmcp::Object* obj);
   bool isAirVehicleState(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AirVehicleStateDescendants();
   
   class AirVehicleState : public afrl::cmasi::EntityState {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AirVehicleState(void);

      // Copy Constructor
      AirVehicleState(const AirVehicleState &that);

      // Assignment Operator
      AirVehicleState & operator=(const AirVehicleState &that);

      // Destructor
      virtual ~AirVehicleState(void);

      // Equals overload
      bool operator==(const AirVehicleState & that);
      bool operator!=(const AirVehicleState & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AirVehicleState* clone() const;

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
      /** vehicle true airspeed (Units: meter/sec)*/
      float getAirspeed(void) const { return __Airspeed; }
      AirVehicleState& setAirspeed(const float val);

      /** Vertical speed (positive upwards) of the vehicle in the inertial frame (rate of change of altitude) (Units: meter/sec)*/
      float getVerticalSpeed(void) const { return __VerticalSpeed; }
      AirVehicleState& setVerticalSpeed(const float val);

      /** Wind speed as detected or computed by the vehicle (Units: meter/sec)*/
      float getWindSpeed(void) const { return __WindSpeed; }
      AirVehicleState& setWindSpeed(const float val);

      /** Wind source direction (true) as detected or computed by the vehicle(Units: degree)*/
      float getWindDirection(void) const { return __WindDirection; }
      AirVehicleState& setWindDirection(const float val);



   protected:
      /** vehicle true airspeed */
      float __Airspeed;
      /** Vertical speed (positive upwards) of the vehicle in the inertial frame (rate of change of altitude) */
      float __VerticalSpeed;
      /** Wind speed as detected or computed by the vehicle */
      float __WindSpeed;
      /** Wind source direction (true) as detected or computed by the vehicle*/
      float __WindDirection;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_AIRVEHICLESTATE_H_
