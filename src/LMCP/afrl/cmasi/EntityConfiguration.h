// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_ENTITYCONFIGURATION_H_
#define _AFRL_CMASI_ENTITYCONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AltitudeType.h"
#include "afrl/cmasi/PayloadConfiguration.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isEntityConfiguration(avtas::lmcp::Object* obj);
   bool isEntityConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > EntityConfigurationDescendants();
   
   class EntityConfiguration : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      EntityConfiguration(void);

      // Copy Constructor
      EntityConfiguration(const EntityConfiguration &that);

      // Assignment Operator
      EntityConfiguration & operator=(const EntityConfiguration &that);

      // Destructor
      virtual ~EntityConfiguration(void);

      // Equals overload
      bool operator==(const EntityConfiguration & that);
      bool operator!=(const EntityConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual EntityConfiguration* clone() const;

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
      /** A unique id for this entity (Units: None)*/
      int64_t getID(void) const { return __ID; }
      EntityConfiguration& setID(const int64_t val);

      /** the team or "side" that an entity belongs to. This can be a name of a country, a "friend" or "foe" designation, or a team name (e.g. "red team"). (Units: None)*/
      std::string getAffiliation(void) const { return __Affiliation; }
      EntityConfiguration& setAffiliation(const std::string val);

      /** The type of this entity. The content of this field is dependent on the session. The value of this field is not specifically defined, so it is up to the simulation/session components to define a type system. For a common entity definition, see MIL STD 2525 or use DIS enumerations. (Units: None)*/
      std::string getEntityType(void) const { return __EntityType; }
      EntityConfiguration& setEntityType(const std::string val);

      /** An optional text string for the vehicle. This is not necessarily unique, and is included for information only. ID should be used to uniquely identify entities. (Units: None)*/
      std::string getLabel(void) const { return __Label; }
      EntityConfiguration& setLabel(const std::string val);

      /** The speed that is typically commanded for this entity (Units: meter/sec)*/
      float getNominalSpeed(void) const { return __NominalSpeed; }
      EntityConfiguration& setNominalSpeed(const float val);

      /** The altitude that is typically commanded for this entity (Units: meter)*/
      float getNominalAltitude(void) const { return __NominalAltitude; }
      EntityConfiguration& setNominalAltitude(const float val);

      /** Altitude type for nominal altitude (Units: None)*/
      afrl::cmasi::AltitudeType::AltitudeType getNominalAltitudeType(void) const { return __NominalAltitudeType; }
      EntityConfiguration& setNominalAltitudeType(const afrl::cmasi::AltitudeType::AltitudeType val);

      /** A list of all payload configurations for this vehicle. Examples of payloads include: gimbaled sensors, SAR radars (not yet supported), air-launched UAVs (not yet supported), and weapons (not yet supported). (Units: None)*/
      std::vector<afrl::cmasi::PayloadConfiguration*> & getPayloadConfigurationList(void) { return __PayloadConfigurationList; }

      /** A list that maps keys to values for the inclusion of extra, custom information about this entity (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getInfo(void) { return __Info; }



   protected:
      /** A unique id for this entity */
      int64_t __ID;
      /** the team or "side" that an entity belongs to. This can be a name of a country, a "friend" or "foe" designation, or a team name (e.g. "red team"). */
      std::string __Affiliation;
      /** The type of this entity. The content of this field is dependent on the session. The value of this field is not specifically defined, so it is up to the simulation/session components to define a type system. For a common entity definition, see MIL STD 2525 or use DIS enumerations. */
      std::string __EntityType;
      /** An optional text string for the vehicle. This is not necessarily unique, and is included for information only. ID should be used to uniquely identify entities. */
      std::string __Label;
      /** The speed that is typically commanded for this entity */
      float __NominalSpeed;
      /** The altitude that is typically commanded for this entity */
      float __NominalAltitude;
      /** Altitude type for nominal altitude */
      afrl::cmasi::AltitudeType::AltitudeType __NominalAltitudeType;
      /** A list of all payload configurations for this vehicle. Examples of payloads include: gimbaled sensors, SAR radars (not yet supported), air-launched UAVs (not yet supported), and weapons (not yet supported). */
      std::vector< afrl::cmasi::PayloadConfiguration* > __PayloadConfigurationList;
      /** A list that maps keys to values for the inclusion of extra, custom information about this entity */
      std::vector< afrl::cmasi::KeyValuePair* > __Info;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_ENTITYCONFIGURATION_H_
