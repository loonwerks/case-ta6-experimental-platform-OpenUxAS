// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_ONBOARDSTATUSREPORT_H_
#define _UXAS_MESSAGES_UXNATIVE_ONBOARDSTATUSREPORT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace uxas {
namespace messages {
namespace uxnative {


   bool isOnboardStatusReport(avtas::lmcp::Object* obj);
   bool isOnboardStatusReport(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > OnboardStatusReportDescendants();
   
   class OnboardStatusReport : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      OnboardStatusReport(void);

      // Copy Constructor
      OnboardStatusReport(const OnboardStatusReport &that);

      // Assignment Operator
      OnboardStatusReport & operator=(const OnboardStatusReport &that);

      // Destructor
      virtual ~OnboardStatusReport(void);

      // Equals overload
      bool operator==(const OnboardStatusReport & that);
      bool operator!=(const OnboardStatusReport & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual OnboardStatusReport* clone() const;

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
      /** ID of vehicle for status report (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      OnboardStatusReport& setVehicleID(const int64_t val);

      /** List of entities in communication with vehicle (from join/exit message traffic) (Units: None)*/
      std::vector<int64_t> & getConnectedEntities(void) { return __ConnectedEntities; }

      /** Current task list being carried out by vehicle (Units: None)*/
      std::vector<int64_t> & getCurrentTaskList(void) { return __CurrentTaskList; }

      /** Entity has valid state (Units: None)*/
      bool getValidState(void) const { return __ValidState; }
      OnboardStatusReport& setValidState(const bool val);

      /** Entity is authorized to act (Units: None)*/
      bool getValidAuthorization(void) const { return __ValidAuthorization; }
      OnboardStatusReport& setValidAuthorization(const bool val);

      /** Entity is authorized to change speed (Units: None)*/
      bool getSpeedAuthorization(void) const { return __SpeedAuthorization; }
      OnboardStatusReport& setSpeedAuthorization(const bool val);

      /** Entity is authorized to change payload/gimbal (Units: None)*/
      bool getGimbalAuthorization(void) const { return __GimbalAuthorization; }
      OnboardStatusReport& setGimbalAuthorization(const bool val);

      /** Time of last entity state message received (Units: milliseconds since 1 Jan 1970)*/
      int64_t getVehicleTime(void) const { return __VehicleTime; }
      OnboardStatusReport& setVehicleTime(const int64_t val);



   protected:
      /** ID of vehicle for status report */
      int64_t __VehicleID;
      /** List of entities in communication with vehicle (from join/exit message traffic) */
      std::vector< int64_t > __ConnectedEntities;
      /** Current task list being carried out by vehicle */
      std::vector< int64_t > __CurrentTaskList;
      /** Entity has valid state */
      bool __ValidState;
      /** Entity is authorized to act */
      bool __ValidAuthorization;
      /** Entity is authorized to change speed */
      bool __SpeedAuthorization;
      /** Entity is authorized to change payload/gimbal */
      bool __GimbalAuthorization;
      /** Time of last entity state message received */
      int64_t __VehicleTime;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_ONBOARDSTATUSREPORT_H_
