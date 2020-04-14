// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_PATTERNSEARCHTASK_H_
#define _AFRL_IMPACT_PATTERNSEARCHTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/impact/AreaSearchPattern.h"



namespace afrl {
namespace impact {


   bool isPatternSearchTask(avtas::lmcp::Object* obj);
   bool isPatternSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PatternSearchTaskDescendants();
   
   class PatternSearchTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PatternSearchTask(void);

      // Copy Constructor
      PatternSearchTask(const PatternSearchTask &that);

      // Assignment Operator
      PatternSearchTask & operator=(const PatternSearchTask &that);

      // Destructor
      virtual ~PatternSearchTask(void);

      // Equals overload
      bool operator==(const PatternSearchTask & that);
      bool operator!=(const PatternSearchTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PatternSearchTask* clone() const;

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
      /** Point at which to search is centered (from available points of interest) (Units: None)*/
      int64_t getSearchLocationID(void) const { return __SearchLocationID; }
      PatternSearchTask& setSearchLocationID(const int64_t val);

      /** Defines coordinates directly, only used when SearchLocationID is non-zero (Units: None)*/
      afrl::cmasi::Location3D* const getSearchLocation(void) { return __SearchLocation; }
      PatternSearchTask& setSearchLocation(const afrl::cmasi::Location3D* const val);

      /** Search pattern to use (Units: None)*/
      afrl::impact::AreaSearchPattern::AreaSearchPattern getPattern(void) const { return __Pattern; }
      PatternSearchTask& setPattern(const afrl::impact::AreaSearchPattern::AreaSearchPattern val);

      /** Pattern extent (Units: meters)*/
      float getExtent(void) const { return __Extent; }
      PatternSearchTask& setExtent(const float val);



   protected:
      /** Point at which to search is centered (from available points of interest) */
      int64_t __SearchLocationID;
      /** Defines coordinates directly, only used when SearchLocationID is non-zero */
      afrl::cmasi::Location3D* __SearchLocation;
      /** Search pattern to use */
      afrl::impact::AreaSearchPattern::AreaSearchPattern __Pattern;
      /** Pattern extent */
      float __Extent;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_PATTERNSEARCHTASK_H_
