// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_VEHICLES_GROUNDVEHICLECONFIGURATION_H_
#define _AFRL_VEHICLES_GROUNDVEHICLECONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "VEHICLESEnum.h"
#include "afrl/cmasi/EntityConfiguration.h"



namespace afrl {
namespace vehicles {


   bool isGroundVehicleConfiguration(avtas::lmcp::Object* obj);
   bool isGroundVehicleConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GroundVehicleConfigurationDescendants();
   
   class GroundVehicleConfiguration : public afrl::cmasi::EntityConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GroundVehicleConfiguration(void);

      // Copy Constructor
      GroundVehicleConfiguration(const GroundVehicleConfiguration &that);

      // Assignment Operator
      GroundVehicleConfiguration & operator=(const GroundVehicleConfiguration &that);

      // Destructor
      virtual ~GroundVehicleConfiguration(void);

      // Equals overload
      bool operator==(const GroundVehicleConfiguration & that);
      bool operator!=(const GroundVehicleConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GroundVehicleConfiguration* clone() const;

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
      /** Valid operational road network. UGV adheres to positions defined in this graph. Indicated by previously sent GraphRegion's ID (Units: None)*/
      int64_t getRoadGraphID(void) const { return __RoadGraphID; }
      GroundVehicleConfiguration& setRoadGraphID(const int64_t val);

      /** The minimum speed that should be commanded for this vehicle (Units: meter/sec)*/
      float getMinimumSpeed(void) const { return __MinimumSpeed; }
      GroundVehicleConfiguration& setMinimumSpeed(const float val);

      /** The maximum speed that should be commanded for this vehicle (Units: meter/sec)*/
      float getMaximumSpeed(void) const { return __MaximumSpeed; }
      GroundVehicleConfiguration& setMaximumSpeed(const float val);

      /** The consumption rate of available energy at nominal speed, expressed in terms of the percentage of maximum capacity used per second. (Units: %/sec)*/
      float getEnergyRate(void) const { return __EnergyRate; }
      GroundVehicleConfiguration& setEnergyRate(const float val);



   protected:
      /** Valid operational road network. UGV adheres to positions defined in this graph. Indicated by previously sent GraphRegion's ID */
      int64_t __RoadGraphID;
      /** The minimum speed that should be commanded for this vehicle */
      float __MinimumSpeed;
      /** The maximum speed that should be commanded for this vehicle */
      float __MaximumSpeed;
      /** The consumption rate of available energy at nominal speed, expressed in terms of the percentage of maximum capacity used per second. */
      float __EnergyRate;

   };

} // end namespace vehicles
} // end namespace afrl


#endif // _AFRL_VEHICLES_GROUNDVEHICLECONFIGURATION_H_
