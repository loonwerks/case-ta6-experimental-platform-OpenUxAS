// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_RADIOTOWERCONFIGURATION_H_
#define _AFRL_IMPACT_RADIOTOWERCONFIGURATION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/EntityConfiguration.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace impact {


   bool isRadioTowerConfiguration(avtas::lmcp::Object* obj);
   bool isRadioTowerConfiguration(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RadioTowerConfigurationDescendants();
   
   class RadioTowerConfiguration : public afrl::cmasi::EntityConfiguration {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RadioTowerConfiguration(void);

      // Copy Constructor
      RadioTowerConfiguration(const RadioTowerConfiguration &that);

      // Assignment Operator
      RadioTowerConfiguration & operator=(const RadioTowerConfiguration &that);

      // Destructor
      virtual ~RadioTowerConfiguration(void);

      // Equals overload
      bool operator==(const RadioTowerConfiguration & that);
      bool operator!=(const RadioTowerConfiguration & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RadioTowerConfiguration* clone() const;

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
      /** The position of the tower. A valid RadioTowerConfiguration must define Position (null not allowed) (Units: None)*/
      afrl::cmasi::Location3D* const getPosition(void) { return __Position; }
      RadioTowerConfiguration& setPosition(const afrl::cmasi::Location3D* const val);

      /** The range of the radio (Units: meters)*/
      float getRange(void) const { return __Range; }
      RadioTowerConfiguration& setRange(const float val);

      /** Whether the radio is enabled (Units: None)*/
      bool getEnabled(void) const { return __Enabled; }
      RadioTowerConfiguration& setEnabled(const bool val);



   protected:
      /** The position of the tower. A valid RadioTowerConfiguration must define Position (null not allowed) */
      afrl::cmasi::Location3D* __Position;
      /** The range of the radio */
      float __Range;
      /** Whether the radio is enabled */
      bool __Enabled;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_RADIOTOWERCONFIGURATION_H_
