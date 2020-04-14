// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_ABSTRACTZONE_H_
#define _AFRL_CMASI_ABSTRACTZONE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AltitudeType.h"
#include "afrl/cmasi/AltitudeType.h"
#include "afrl/cmasi/AbstractGeometry.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isAbstractZone(avtas::lmcp::Object* obj);
   bool isAbstractZone(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AbstractZoneDescendants();
   
   class AbstractZone : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AbstractZone(void);

      // Copy Constructor
      AbstractZone(const AbstractZone &that);

      // Assignment Operator
      AbstractZone & operator=(const AbstractZone &that);

      // Destructor
      virtual ~AbstractZone(void);

      // Equals overload
      bool operator==(const AbstractZone & that);
      bool operator!=(const AbstractZone & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AbstractZone* clone() const;

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
      /** A globally unique reference number for this zone (Units: None)*/
      int64_t getZoneID(void) const { return __ZoneID; }
      AbstractZone& setZoneID(const int64_t val);

      /** Lower altitude bound for the zone (Units: meter)*/
      float getMinAltitude(void) const { return __MinAltitude; }
      AbstractZone& setMinAltitude(const float val);

      /** Altitude type for min altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getMinAltitudeType(void) const { return __MinAltitudeType; }
      AbstractZone& setMinAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** Maximum altitude for operations (Units: meter)*/
      float getMaxAltitude(void) const { return __MaxAltitude; }
      AbstractZone& setMaxAltitude(const float val);

      /** Altitude type for max altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getMaxAltitudeType(void) const { return __MaxAltitudeType; }
      AbstractZone& setMaxAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** A list of aircraft IDs that this zone applies to. If the list is empty, then it is assumed that the boundary applies to all aircraft. (Units: None)*/
      std::vector<int64_t> & getAffectedAircraft(void) { return __AffectedAircraft; }

      /** Time at which this zone becomes active. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 (Units: milliseconds)*/
      int64_t getStartTime(void) const { return __StartTime; }
      AbstractZone& setStartTime(const int64_t val);

      /** Time at which this zone becomes inactive. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 (Units: milliseconds)*/
      int64_t getEndTime(void) const { return __EndTime; }
      AbstractZone& setEndTime(const int64_t val);

      /** Buffer to add/subtract around the border of the zone (Units: meters)*/
      float getPadding(void) const { return __Padding; }
      AbstractZone& setPadding(const float val);

      /** Optional label for this zone (Units: None)*/
      std::string getLabel(void) const { return __Label; }
      AbstractZone& setLabel(const std::string val);

      /** Geometry object describing the boundary. This boundary is 2-dimensional. The zone boundary is defined as an extrusion of this boundary from MinAltitude to MaxAltitude. A valid zone must define a boundary (null not allowed). (Units: None)*/
      afrl::cmasi::AbstractGeometry* const getBoundary(void) { return __Boundary; }
      AbstractZone& setBoundary(const afrl::cmasi::AbstractGeometry* const val);



   protected:
      /** A globally unique reference number for this zone */
      int64_t __ZoneID;
      /** Lower altitude bound for the zone */
      float __MinAltitude;
      /** Altitude type for min altitude */
      afrl::cmasi::AltitudeType::AltitudeType __MinAltitudeType;
      /** Maximum altitude for operations */
      float __MaxAltitude;
      /** Altitude type for max altitude */
      afrl::cmasi::AltitudeType::AltitudeType __MaxAltitudeType;
      /** A list of aircraft IDs that this zone applies to. If the list is empty, then it is assumed that the boundary applies to all aircraft. */
      std::vector< int64_t > __AffectedAircraft;
      /** Time at which this zone becomes active. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 */
      int64_t __StartTime;
      /** Time at which this zone becomes inactive. Time datum is defined by the application, but unless otherwise specified is milliseconds since 1 Jan 1970 */
      int64_t __EndTime;
      /** Buffer to add/subtract around the border of the zone */
      float __Padding;
      /** Optional label for this zone */
      std::string __Label;
      /** Geometry object describing the boundary. This boundary is 2-dimensional. The zone boundary is defined as an extrusion of this boundary from MinAltitude to MaxAltitude. A valid zone must define a boundary (null not allowed). */
      afrl::cmasi::AbstractGeometry* __Boundary;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_ABSTRACTZONE_H_
