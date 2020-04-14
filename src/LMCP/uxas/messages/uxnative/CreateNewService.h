// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_CREATENEWSERVICE_H_
#define _UXAS_MESSAGES_UXNATIVE_CREATENEWSERVICE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/EntityConfiguration.h"
#include "afrl/cmasi/EntityState.h"
#include "afrl/cmasi/MissionCommand.h"
#include "afrl/impact/AreaOfInterest.h"
#include "afrl/impact/LineOfInterest.h"
#include "afrl/impact/PointOfInterest.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"
#include "afrl/cmasi/OperatingRegion.h"

#include <vector>


namespace uxas {
namespace messages {
namespace uxnative {


   bool isCreateNewService(avtas::lmcp::Object* obj);
   bool isCreateNewService(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > CreateNewServiceDescendants();
   
   class CreateNewService : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      CreateNewService(void);

      // Copy Constructor
      CreateNewService(const CreateNewService &that);

      // Assignment Operator
      CreateNewService & operator=(const CreateNewService &that);

      // Destructor
      virtual ~CreateNewService(void);

      // Equals overload
      bool operator==(const CreateNewService & that);
      bool operator!=(const CreateNewService & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual CreateNewService* clone() const;

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
      /** Globally unique ID for this service. Negative ServiceIDs are invalid. If ServiceID == 0, then a unique service ID will be generated. (Units: None)*/
      int64_t getServiceID(void) const { return __ServiceID; }
      CreateNewService& setServiceID(const int64_t val);

      /** XML configuration for this service (i.e. options in XML format) (Units: None)*/
      std::string getXmlConfiguration(void) const { return __XmlConfiguration; }
      CreateNewService& setXmlConfiguration(const std::string val);

      /** Existing entity configurations in the system when this new service is created (Units: None)*/
      std::vector<afrl::cmasi::EntityConfiguration*> & getEntityConfigurations(void) { return __EntityConfigurations; }

      /** Existing entity states in the system when this new service is created (Units: None)*/
      std::vector<afrl::cmasi::EntityState*> & getEntityStates(void) { return __EntityStates; }

      /** Existing mission commands for vehicles in the system when this new service is created (Units: None)*/
      std::vector<afrl::cmasi::MissionCommand*> & getMissionCommands(void) { return __MissionCommands; }

      /** Defined areas of interest at time of service creation (Units: None)*/
      std::vector<afrl::impact::AreaOfInterest*> & getAreas(void) { return __Areas; }

      /** Defined lines of interest at time of service creation (Units: None)*/
      std::vector<afrl::impact::LineOfInterest*> & getLines(void) { return __Lines; }

      /** Defined points of interest at time of service creation (Units: None)*/
      std::vector<afrl::impact::PointOfInterest*> & getPoints(void) { return __Points; }

      /** Defined keep in zones at time of service creation (Units: None)*/
      std::vector<afrl::cmasi::KeepInZone*> & getKeepInZones(void) { return __KeepInZones; }

      /** Defined keep out zones at time of service creation (Units: None)*/
      std::vector<afrl::cmasi::KeepOutZone*> & getKeepOutZones(void) { return __KeepOutZones; }

      /** Defined opearting regions at time of service creation (Units: None)*/
      std::vector<afrl::cmasi::OperatingRegion*> & getOperatingRegions(void) { return __OperatingRegions; }



   protected:
      /** Globally unique ID for this service. Negative ServiceIDs are invalid. If ServiceID == 0, then a unique service ID will be generated. */
      int64_t __ServiceID;
      /** XML configuration for this service (i.e. options in XML format) */
      std::string __XmlConfiguration;
      /** Existing entity configurations in the system when this new service is created */
      std::vector< afrl::cmasi::EntityConfiguration* > __EntityConfigurations;
      /** Existing entity states in the system when this new service is created */
      std::vector< afrl::cmasi::EntityState* > __EntityStates;
      /** Existing mission commands for vehicles in the system when this new service is created */
      std::vector< afrl::cmasi::MissionCommand* > __MissionCommands;
      /** Defined areas of interest at time of service creation */
      std::vector< afrl::impact::AreaOfInterest* > __Areas;
      /** Defined lines of interest at time of service creation */
      std::vector< afrl::impact::LineOfInterest* > __Lines;
      /** Defined points of interest at time of service creation */
      std::vector< afrl::impact::PointOfInterest* > __Points;
      /** Defined keep in zones at time of service creation */
      std::vector< afrl::cmasi::KeepInZone* > __KeepInZones;
      /** Defined keep out zones at time of service creation */
      std::vector< afrl::cmasi::KeepOutZone* > __KeepOutZones;
      /** Defined opearting regions at time of service creation */
      std::vector< afrl::cmasi::OperatingRegion* > __OperatingRegions;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_CREATENEWSERVICE_H_
