// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_FLIGHTDIRECTORACTION_H_
#define _AFRL_CMASI_FLIGHTDIRECTORACTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/NavigationAction.h"
#include "afrl/cmasi/SpeedType.h"
#include "afrl/cmasi/AltitudeType.h"



namespace afrl {
namespace cmasi {


   bool isFlightDirectorAction(avtas::lmcp::Object* obj);
   bool isFlightDirectorAction(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > FlightDirectorActionDescendants();
   
   class FlightDirectorAction : public afrl::cmasi::NavigationAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      FlightDirectorAction(void);

      // Copy Constructor
      FlightDirectorAction(const FlightDirectorAction &that);

      // Assignment Operator
      FlightDirectorAction & operator=(const FlightDirectorAction &that);

      // Destructor
      virtual ~FlightDirectorAction(void);

      // Equals overload
      bool operator==(const FlightDirectorAction & that);
      bool operator!=(const FlightDirectorAction & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual FlightDirectorAction* clone() const;

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
      /** Speed to fly (Units: meter/sec)*/
      float getSpeed(void) const { return __Speed; }
      FlightDirectorAction& setSpeed(const float val);

      /** type of speed to fly (Units: None)*/
      afrl::cmasi::SpeedType::SpeedType getSpeedType(void) const { return __SpeedType; }
      FlightDirectorAction& setSpeedType(const afrl::cmasi::SpeedType::SpeedType val);

      /** True heading to fly (Units: degree)*/
      float getHeading(void) const { return __Heading; }
      FlightDirectorAction& setHeading(const float val);

      /** Altitude to maintain. (Units: meter)*/
      float getAltitude(void) const { return __Altitude; }
      FlightDirectorAction& setAltitude(const float val);

      /** Altitude type for specified altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getAltitudeType(void) const { return __AltitudeType; }
      FlightDirectorAction& setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** target climb/descent rate for changing altitude (Units: meter/sec)*/
      float getClimbRate(void) const { return __ClimbRate; }
      FlightDirectorAction& setClimbRate(const float val);



   protected:
      /** Speed to fly */
      float __Speed;
      /** type of speed to fly */
      afrl::cmasi::SpeedType::SpeedType __SpeedType;
      /** True heading to fly */
      float __Heading;
      /** Altitude to maintain. */
      float __Altitude;
      /** Altitude type for specified altitude */
      afrl::cmasi::AltitudeType::AltitudeType __AltitudeType;
      /** target climb/descent rate for changing altitude */
      float __ClimbRate;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_FLIGHTDIRECTORACTION_H_
