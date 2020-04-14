// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_VEHICLEACTIONCOMMAND_H_
#define _AFRL_CMASI_VEHICLEACTIONCOMMAND_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/VehicleAction.h"
#include "afrl/cmasi/CommandStatusType.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isVehicleActionCommand(avtas::lmcp::Object* obj);
   bool isVehicleActionCommand(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > VehicleActionCommandDescendants();
   
   class VehicleActionCommand : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      VehicleActionCommand(void);

      // Copy Constructor
      VehicleActionCommand(const VehicleActionCommand &that);

      // Assignment Operator
      VehicleActionCommand & operator=(const VehicleActionCommand &that);

      // Destructor
      virtual ~VehicleActionCommand(void);

      // Equals overload
      bool operator==(const VehicleActionCommand & that);
      bool operator!=(const VehicleActionCommand & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual VehicleActionCommand* clone() const;

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
      /** A unique id for this command. automation services should issue new ids with every new command (Units: None)*/
      int64_t getCommandID(void) const { return __CommandID; }
      VehicleActionCommand& setCommandID(const int64_t val);

      /** The id of the vehicle for this command. (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      VehicleActionCommand& setVehicleID(const int64_t val);

      /** a set of actions to be performed immediately by the vehicle. (Units: None)*/
      std::vector<afrl::cmasi::VehicleAction*> & getVehicleActionList(void) { return __VehicleActionList; }

      /** Denotes the current execution status of this command. (Units: None)*/
      afrl::cmasi::CommandStatusType::CommandStatusType getStatus(void) const { return __Status; }
      VehicleActionCommand& setStatus(const afrl::cmasi::CommandStatusType::CommandStatusType val);



   protected:
      /** A unique id for this command. automation services should issue new ids with every new command */
      int64_t __CommandID;
      /** The id of the vehicle for this command. */
      int64_t __VehicleID;
      /** a set of actions to be performed immediately by the vehicle. */
      std::vector< afrl::cmasi::VehicleAction* > __VehicleActionList;
      /** Denotes the current execution status of this command. */
      afrl::cmasi::CommandStatusType::CommandStatusType __Status;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_VEHICLEACTIONCOMMAND_H_
