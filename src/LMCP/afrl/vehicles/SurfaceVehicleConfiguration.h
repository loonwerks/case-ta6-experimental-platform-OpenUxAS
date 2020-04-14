// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_VEHICLES_SURFACEVEHICLECONFIGURATION_H_
#define _AFRL_VEHICLES_SURFACEVEHICLECONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "VEHICLESEnum.h"
#include "afrl/cmasi/EntityConfiguration.h"



namespace afrl {
namespace vehicles {


   bool isSurfaceVehicleConfiguration(avtas::lmcp::Object* obj);
   bool isSurfaceVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SurfaceVehicleConfigurationDescendants();
   
   class SurfaceVehicleConfiguration : public afrl::cmasi::EntityConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SurfaceVehicleConfiguration(void);

      // Copy Constructor
      SurfaceVehicleConfiguration(const SurfaceVehicleConfiguration &that);

      // Assignment Operator
      SurfaceVehicleConfiguration & operator=(const SurfaceVehicleConfiguration &that);

      // Destructor
      virtual ~SurfaceVehicleConfiguration(void);

      // Equals overload
      bool operator==(const SurfaceVehicleConfiguration & that);
      bool operator!=(const SurfaceVehicleConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SurfaceVehicleConfiguration* clone() const;

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
      /** Valid operational water zone (by ID). USV adheres to this area (Units: None)*/
      int64_t getWaterArea(void) const { return __WaterArea; }
      SurfaceVehicleConfiguration& setWaterArea(const int64_t val);

      /** The minimum speed that should be commanded for this vehicle (Units: meter/sec)*/
      float getMinimumSpeed(void) const { return __MinimumSpeed; }
      SurfaceVehicleConfiguration& setMinimumSpeed(const float val);

      /** The maximum speed that should be commanded for this vehicle (Units: meter/sec)*/
      float getMaximumSpeed(void) const { return __MaximumSpeed; }
      SurfaceVehicleConfiguration& setMaximumSpeed(const float val);

      /** The consumption rate of available energy at nominal speed, expressed in terms of the percentage of maximum capacity used per second. (Units: %/sec)*/
      float getEnergyRate(void) const { return __EnergyRate; }
      SurfaceVehicleConfiguration& setEnergyRate(const float val);

      /** The maximum angle that this vehicle will bank (Units: degree)*/
      float getMaxBankAngle(void) const { return __MaxBankAngle; }
      SurfaceVehicleConfiguration& setMaxBankAngle(const float val);

      /** The maximum angular rate that this vehicle will bank (Units: degree/sec)*/
      float getMaxBankRate(void) const { return __MaxBankRate; }
      SurfaceVehicleConfiguration& setMaxBankRate(const float val);



   protected:
      /** Valid operational water zone (by ID). USV adheres to this area */
      int64_t __WaterArea;
      /** The minimum speed that should be commanded for this vehicle */
      float __MinimumSpeed;
      /** The maximum speed that should be commanded for this vehicle */
      float __MaximumSpeed;
      /** The consumption rate of available energy at nominal speed, expressed in terms of the percentage of maximum capacity used per second. */
      float __EnergyRate;
      /** The maximum angle that this vehicle will bank */
      float __MaxBankAngle;
      /** The maximum angular rate that this vehicle will bank */
      float __MaxBankRate;

   };

} // end namespace vehicles
} // end namespace afrl


#endif // _AFRL_VEHICLES_SURFACEVEHICLECONFIGURATION_H_
