// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_SIMULATIONTIMESTEPACKNOWLEDGEMENT_H_
#define _UXAS_MESSAGES_UXNATIVE_SIMULATIONTIMESTEPACKNOWLEDGEMENT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"



namespace uxas {
namespace messages {
namespace uxnative {


   bool isSimulationTimeStepAcknowledgement(avtas::lmcp::Object* obj);
   bool isSimulationTimeStepAcknowledgement(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > SimulationTimeStepAcknowledgementDescendants();
   
   class SimulationTimeStepAcknowledgement : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      SimulationTimeStepAcknowledgement(void);

      // Copy Constructor
      SimulationTimeStepAcknowledgement(const SimulationTimeStepAcknowledgement &that);

      // Assignment Operator
      SimulationTimeStepAcknowledgement & operator=(const SimulationTimeStepAcknowledgement &that);

      // Destructor
      virtual ~SimulationTimeStepAcknowledgement(void);

      // Equals overload
      bool operator==(const SimulationTimeStepAcknowledgement & that);
      bool operator!=(const SimulationTimeStepAcknowledgement & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual SimulationTimeStepAcknowledgement* clone() const;

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
      /** Vehicle for which the entity state update was handled (Units: None)*/
      int64_t getVehicleID(void) const { return __VehicleID; }
      SimulationTimeStepAcknowledgement& setVehicleID(const int64_t val);

      /** Associated time from the handled entity state (Units: milliseconds)*/
      int64_t getReportedTime(void) const { return __ReportedTime; }
      SimulationTimeStepAcknowledgement& setReportedTime(const int64_t val);



   protected:
      /** Vehicle for which the entity state update was handled */
      int64_t __VehicleID;
      /** Associated time from the handled entity state */
      int64_t __ReportedTime;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_SIMULATIONTIMESTEPACKNOWLEDGEMENT_H_
