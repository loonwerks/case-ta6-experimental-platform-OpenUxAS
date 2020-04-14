// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_SPEEDALTPAIR_H_
#define _AFRL_IMPACT_SPEEDALTPAIR_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AltitudeType.h"



namespace afrl {
namespace impact {


   bool isSpeedAltPair(avtas::lmcp::Object* obj);
   bool isSpeedAltPair(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SpeedAltPairDescendants();
   
   class SpeedAltPair : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SpeedAltPair(void);

      // Copy Constructor
      SpeedAltPair(const SpeedAltPair &that);

      // Assignment Operator
      SpeedAltPair & operator=(const SpeedAltPair &that);

      // Destructor
      virtual ~SpeedAltPair(void);

      // Equals overload
      bool operator==(const SpeedAltPair & that);
      bool operator!=(const SpeedAltPair & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SpeedAltPair* clone() const;

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
      /** ID of vehicle for which altitude and speed is attached (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      SpeedAltPair& setVehicleID(const int64_t val);

      /** ID of task for which altitude and speed is attached. If TaskID is zero, then alt/speed setting applies to all tasks in the automation request (Units: None)*/
      int64_t getTaskID(void) const { return __TaskID; }
      SpeedAltPair& setTaskID(const int64_t val);

      /** The speed attached to this vehicle (Units: meter/sec)*/
      float getSpeed(void) const { return __Speed; }
      SpeedAltPair& setSpeed(const float val);

      /** Altitude attached to this vehicle (Units: meter)*/
      float getAltitude(void) const { return __Altitude; }
      SpeedAltPair& setAltitude(const float val);

      /** Altitude type for specified altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getAltitudeType(void) const { return __AltitudeType; }
      SpeedAltPair& setAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);



   protected:
      /** ID of vehicle for which altitude and speed is attached */
      int64_t __VehicleID;
      /** ID of task for which altitude and speed is attached. If TaskID is zero, then alt/speed setting applies to all tasks in the automation request */
      int64_t __TaskID;
      /** The speed attached to this vehicle */
      float __Speed;
      /** Altitude attached to this vehicle */
      float __Altitude;
      /** Altitude type for specified altitude */
      afrl::cmasi::AltitudeType::AltitudeType __AltitudeType;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_SPEEDALTPAIR_H_
