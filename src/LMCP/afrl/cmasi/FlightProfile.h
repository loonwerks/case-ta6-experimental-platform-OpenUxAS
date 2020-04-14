// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_FLIGHTPROFILE_H_
#define _AFRL_CMASI_FLIGHTPROFILE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"



namespace afrl {
namespace cmasi {


   bool isFlightProfile(avtas::lmcp::Object* obj);
   bool isFlightProfile(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > FlightProfileDescendants();
   
   class FlightProfile : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      FlightProfile(void);

      // Copy Constructor
      FlightProfile(const FlightProfile &that);

      // Assignment Operator
      FlightProfile & operator=(const FlightProfile &that);

      // Destructor
      virtual ~FlightProfile(void);

      // Equals overload
      bool operator==(const FlightProfile & that);
      bool operator!=(const FlightProfile & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual FlightProfile* clone() const;

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
      /** The unique name for this configuration (Units: None)*/
      std::string getName(void) const { return __Name; }
      FlightProfile& setName(const std::string val);

      /** True Airspeed (Units: meter/sec)*/
      float getAirspeed(void) const { return __Airspeed; }
      FlightProfile& setAirspeed(const float val);

      /** The pitch angle of the aircraft in this flight condition(assuming zero bank) (Units: degree)*/
      float getPitchAngle(void) const { return __PitchAngle; }
      FlightProfile& setPitchAngle(const float val);

      /** Vertical speed (positive upwards) of the vehicle (Units: meter/sec)*/
      float getVerticalSpeed(void) const { return __VerticalSpeed; }
      FlightProfile& setVerticalSpeed(const float val);

      /** The maximum angle that this vehicle will bank (Units: degree)*/
      float getMaxBankAngle(void) const { return __MaxBankAngle; }
      FlightProfile& setMaxBankAngle(const float val);

      /** The consumption rate of available energy, expressed in terms of the percentage of maximum capacity used per second. (Units: %/sec)*/
      float getEnergyRate(void) const { return __EnergyRate; }
      FlightProfile& setEnergyRate(const float val);



   protected:
      /** The unique name for this configuration */
      std::string __Name;
      /** True Airspeed */
      float __Airspeed;
      /** The pitch angle of the aircraft in this flight condition(assuming zero bank) */
      float __PitchAngle;
      /** Vertical speed (positive upwards) of the vehicle */
      float __VerticalSpeed;
      /** The maximum angle that this vehicle will bank */
      float __MaxBankAngle;
      /** The consumption rate of available energy, expressed in terms of the percentage of maximum capacity used per second. */
      float __EnergyRate;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_FLIGHTPROFILE_H_
