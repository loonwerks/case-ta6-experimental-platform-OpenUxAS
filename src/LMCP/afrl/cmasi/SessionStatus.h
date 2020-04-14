// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_SESSIONSTATUS_H_
#define _AFRL_CMASI_SESSIONSTATUS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/SimulationStatusType.h"
#include "afrl/cmasi/KeyValuePair.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isSessionStatus(avtas::lmcp::Object* obj);
   bool isSessionStatus(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SessionStatusDescendants();
   
   class SessionStatus : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SessionStatus(void);

      // Copy Constructor
      SessionStatus(const SessionStatus &that);

      // Assignment Operator
      SessionStatus & operator=(const SessionStatus &that);

      // Destructor
      virtual ~SessionStatus(void);

      // Equals overload
      bool operator==(const SessionStatus & that);
      bool operator!=(const SessionStatus & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SessionStatus* clone() const;

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
      /** The current state of the session (Units: None)*/
      afrl::cmasi::SimulationStatusType::SimulationStatusType getState(void) const { return __State; }
      SessionStatus& setState(const afrl::cmasi::SimulationStatusType::SimulationStatusType val);

      /** The simulation or scenario start time. This is absolute time in milliseconds since epoch (1 Jan 1970 00:00 GMT). If this field is zero, then no start time is specfied and each sim component is to use the first receipt of this Struct with a SimStatus of "Running" as the start time. (Units: millisecond)*/
      int64_t getStartTime(void) const { return __StartTime; }
      SessionStatus& setStartTime(const int64_t val);

      /** The current time in scenario time . This is the internal time for the simulation, not the absolute time since epoch, as in "StartTime". The internal simualation time is based on the start time and the real-time muiltiple, which can change throughout the simulation. (Units: millisecond)*/
      int64_t getScenarioTime(void) const { return __ScenarioTime; }
      SessionStatus& setScenarioTime(const int64_t val);

      /** The ratio of simulation time to real time. Values greater than 1.0 denote faster than real-time. Values less than 0.0 have no meaning. (Units: None)*/
      float getRealTimeMultiple(void) const { return __RealTimeMultiple; }
      SessionStatus& setRealTimeMultiple(const float val);

      /** A field to store command-line style parameters used to initialize or modify an execution. (Units: None)*/
      std::vector<afrl::cmasi::KeyValuePair*> & getParameters(void) { return __Parameters; }



   protected:
      /** The current state of the session */
      afrl::cmasi::SimulationStatusType::SimulationStatusType __State;
      /** The simulation or scenario start time. This is absolute time in milliseconds since epoch (1 Jan 1970 00:00 GMT). If this field is zero, then no start time is specfied and each sim component is to use the first receipt of this Struct with a SimStatus of "Running" as the start time. */
      int64_t __StartTime;
      /** The current time in scenario time . This is the internal time for the simulation, not the absolute time since epoch, as in "StartTime". The internal simualation time is based on the start time and the real-time muiltiple, which can change throughout the simulation. */
      int64_t __ScenarioTime;
      /** The ratio of simulation time to real time. Values greater than 1.0 denote faster than real-time. Values less than 0.0 have no meaning. */
      float __RealTimeMultiple;
      /** A field to store command-line style parameters used to initialize or modify an execution. */
      std::vector< afrl::cmasi::KeyValuePair* > __Parameters;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_SESSIONSTATUS_H_
