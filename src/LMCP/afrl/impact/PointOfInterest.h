// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_POINTOFINTEREST_H_
#define _AFRL_IMPACT_POINTOFINTEREST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/impact/AreaActionOptions.h"



namespace afrl {
namespace impact {


   bool isPointOfInterest(avtas::lmcp::Object* obj);
   bool isPointOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PointOfInterestDescendants();
   
   class PointOfInterest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PointOfInterest(void);

      // Copy Constructor
      PointOfInterest(const PointOfInterest &that);

      // Assignment Operator
      PointOfInterest & operator=(const PointOfInterest &that);

      // Destructor
      virtual ~PointOfInterest(void);

      // Equals overload
      bool operator==(const PointOfInterest & that);
      bool operator!=(const PointOfInterest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PointOfInterest* clone() const;

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
      /** ID for points of interest (Units: None)*/
      int64_t getPointID(void) const { return __PointID; }
      PointOfInterest& setPointID(const int64_t val);

      /** Point of interest location. A valid PointOfInterest must define Location (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getLocation(void) { return __Location; }
      PointOfInterest& setLocation(const afrl::cmasi::Location3D* const val);

      /** Action that updated this point of interest (e.g. created, destroyed, modified) (Units: None)*/
      afrl::impact::AreaActionOptions::AreaActionOptions getPointAction(void) const { return __PointAction; }
      PointOfInterest& setPointAction(const afrl::impact::AreaActionOptions::AreaActionOptions val);

      /** Human readable label for point of interest (Units: None)*/
      std::string getPointLabel(void) const { return __PointLabel; }
      PointOfInterest& setPointLabel(const std::string val);

      /** Background Behavior point is true if point is for background behavior (Units: None)*/
      bool getBackgroundBehaviorPoint(void) const { return __BackgroundBehaviorPoint; }
      PointOfInterest& setBackgroundBehaviorPoint(const bool val);



   protected:
      /** ID for points of interest */
      int64_t __PointID;
      /** Point of interest location. A valid PointOfInterest must define Location (null not allowed). */
      afrl::cmasi::Location3D* __Location;
      /** Action that updated this point of interest (e.g. created, destroyed, modified) */
      afrl::impact::AreaActionOptions::AreaActionOptions __PointAction;
      /** Human readable label for point of interest */
      std::string __PointLabel;
      /** Background Behavior point is true if point is for background behavior */
      bool __BackgroundBehaviorPoint;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_POINTOFINTEREST_H_
