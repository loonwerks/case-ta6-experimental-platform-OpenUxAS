// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_TASK_FOOTPRINTREQUEST_H_
#define _UXAS_MESSAGES_TASK_FOOTPRINTREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXTASKEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/WavelengthBand.h"

#include <vector>


namespace uxas {
namespace messages {
namespace task {


   bool isFootprintRequest(avtas::lmcp::Object* obj);
   bool isFootprintRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > FootprintRequestDescendants();
   
   class FootprintRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      FootprintRequest(void);

      // Copy Constructor
      FootprintRequest(const FootprintRequest &that);

      // Assignment Operator
      FootprintRequest & operator=(const FootprintRequest &that);

      // Destructor
      virtual ~FootprintRequest(void);

      // Equals overload
      bool operator==(const FootprintRequest & that);
      bool operator!=(const FootprintRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual FootprintRequest* clone() const;

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
      /** ID corresponding to this specific footprint request (Units: None)*/
      int64_t getFootprintRequestID(void) const { return __FootprintRequestID; }
      FootprintRequest& setFootprintRequestID(const int64_t val);

      /** Single vehicle to be considered for sensor request. (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      FootprintRequest& setVehicleID(const int64_t val);

      /** Camera wavelength to be considered. If list is empty, planner should plan for all available sensors on each entity (Units: None)*/
      std::vector<afrl::cmasi::WavelengthBand::WavelengthBand> & getEligibleWavelengths(void) { return __EligibleWavelengths; }

      /** Desired ground sample distance for an eligible sensor. If list is empty, then footprint calculation uses the max ground sample distance for the specified altitude. (Units: None)*/
      std::vector<float> & getGroundSampleDistances(void) { return __GroundSampleDistances; }

      /** AGL Altitude to consider during sensor information calculation. If 'AglAltitudes' list is empty, sensor planner should use nominal altitude from entity configurations (Units: meters)*/
      std::vector<float> & getAglAltitudes(void) { return __AglAltitudes; }

      /** Desired camera elevation angles. If list is empty, then uses an optimal elevation angle for achieving max GSD (Units: deg)*/
      std::vector<float> & getElevationAngles(void) { return __ElevationAngles; }



   protected:
      /** ID corresponding to this specific footprint request */
      int64_t __FootprintRequestID;
      /** Single vehicle to be considered for sensor request. */
      int64_t __VehicleID;
      /** Camera wavelength to be considered. If list is empty, planner should plan for all available sensors on each entity */
      std::vector< afrl::cmasi::WavelengthBand::WavelengthBand > __EligibleWavelengths;
      /** Desired ground sample distance for an eligible sensor. If list is empty, then footprint calculation uses the max ground sample distance for the specified altitude. */
      std::vector< float > __GroundSampleDistances;
      /** AGL Altitude to consider during sensor information calculation. If 'AglAltitudes' list is empty, sensor planner should use nominal altitude from entity configurations */
      std::vector< float > __AglAltitudes;
      /** Desired camera elevation angles. If list is empty, then uses an optimal elevation angle for achieving max GSD */
      std::vector< float > __ElevationAngles;

   };

} // end namespace task
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_TASK_FOOTPRINTREQUEST_H_
