// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_AREAOFINTEREST_H_
#define _AFRL_IMPACT_AREAOFINTEREST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/AbstractGeometry.h"
#include "afrl/impact/AreaActionOptions.h"



namespace afrl {
namespace impact {


   bool isAreaOfInterest(avtas::lmcp::Object* obj);
   bool isAreaOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AreaOfInterestDescendants();
   
   class AreaOfInterest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AreaOfInterest(void);

      // Copy Constructor
      AreaOfInterest(const AreaOfInterest &that);

      // Assignment Operator
      AreaOfInterest & operator=(const AreaOfInterest &that);

      // Destructor
      virtual ~AreaOfInterest(void);

      // Equals overload
      bool operator==(const AreaOfInterest & that);
      bool operator!=(const AreaOfInterest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AreaOfInterest* clone() const;

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
      /** ID for area of interest (Units: None)*/
      int64_t getAreaID(void) const { return __AreaID; }
      AreaOfInterest& setAreaID(const int64_t val);

      /** Geometry describing the area. A valid AreaOfInterest must define Area (null not allowed). (Units: None)*/
      afrl::cmasi::AbstractGeometry* const getArea(void) { return __Area; }
      AreaOfInterest& setArea(const afrl::cmasi::AbstractGeometry* const val);

      /** Action that updated this area of interest (e.g. created, destroyed, modified) (Units: None)*/
      afrl::impact::AreaActionOptions::AreaActionOptions getAreaAction(void) const { return __AreaAction; }
      AreaOfInterest& setAreaAction(const afrl::impact::AreaActionOptions::AreaActionOptions val);

      /** Human readable label for area of interest (Units: None)*/
      std::string getAreaLabel(void) const { return __AreaLabel; }
      AreaOfInterest& setAreaLabel(const std::string val);

      /** Background Behavior area is true if point is for background behavior (Units: None)*/
      bool getBackgroundBehaviorArea(void) const { return __BackgroundBehaviorArea; }
      AreaOfInterest& setBackgroundBehaviorArea(const bool val);



   protected:
      /** ID for area of interest */
      int64_t __AreaID;
      /** Geometry describing the area. A valid AreaOfInterest must define Area (null not allowed). */
      afrl::cmasi::AbstractGeometry* __Area;
      /** Action that updated this area of interest (e.g. created, destroyed, modified) */
      afrl::impact::AreaActionOptions::AreaActionOptions __AreaAction;
      /** Human readable label for area of interest */
      std::string __AreaLabel;
      /** Background Behavior area is true if point is for background behavior */
      bool __BackgroundBehaviorArea;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_AREAOFINTEREST_H_
