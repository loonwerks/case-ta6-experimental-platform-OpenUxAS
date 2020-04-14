// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_POWERCONFIGURATION_H_
#define _AFRL_IMPACT_POWERCONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/PayloadConfiguration.h"
#include "afrl/impact/PowerPlant.h"



namespace afrl {
namespace impact {


   bool isPowerConfiguration(avtas::lmcp::Object* obj);
   bool isPowerConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PowerConfigurationDescendants();
   
   class PowerConfiguration : public afrl::cmasi::PayloadConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PowerConfiguration(void);

      // Copy Constructor
      PowerConfiguration(const PowerConfiguration &that);

      // Assignment Operator
      PowerConfiguration & operator=(const PowerConfiguration &that);

      // Destructor
      virtual ~PowerConfiguration(void);

      // Equals overload
      bool operator==(const PowerConfiguration & that);
      bool operator!=(const PowerConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PowerConfiguration* clone() const;

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
      /** Power generation system (used for acoustic signature) (Units: None)*/
      afrl::impact::PowerPlant::PowerPlant getNominalPowerConfiguration(void) const { return __NominalPowerConfiguration; }
      PowerConfiguration& setNominalPowerConfiguration(const afrl::impact::PowerPlant::PowerPlant val);



   protected:
      /** Power generation system (used for acoustic signature) */
      afrl::impact::PowerPlant::PowerPlant __NominalPowerConfiguration;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_POWERCONFIGURATION_H_
