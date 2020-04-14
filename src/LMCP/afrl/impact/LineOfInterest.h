// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_LINEOFINTEREST_H_
#define _AFRL_IMPACT_LINEOFINTEREST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/impact/AreaActionOptions.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isLineOfInterest(avtas::lmcp::Object* obj);
   bool isLineOfInterest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > LineOfInterestDescendants();
   
   class LineOfInterest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      LineOfInterest(void);

      // Copy Constructor
      LineOfInterest(const LineOfInterest &that);

      // Assignment Operator
      LineOfInterest & operator=(const LineOfInterest &that);

      // Destructor
      virtual ~LineOfInterest(void);

      // Equals overload
      bool operator==(const LineOfInterest & that);
      bool operator!=(const LineOfInterest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual LineOfInterest* clone() const;

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
      /** ID for lines of interest (Units: None)*/
      int64_t getLineID(void) const { return __LineID; }
      LineOfInterest& setLineID(const int64_t val);

      /** List of points to search (Units: None)*/
      std::vector<afrl::cmasi::Location3D*> & getLine(void) { return __Line; }

      /** Action that updated this line of interest (e.g. created, destroyed, modified) (Units: None)*/
      afrl::impact::AreaActionOptions::AreaActionOptions getLineAction(void) const { return __LineAction; }
      LineOfInterest& setLineAction(const afrl::impact::AreaActionOptions::AreaActionOptions val);

      /** Human readable label for line of interest (Units: None)*/
      std::string getLineLabel(void) const { return __LineLabel; }
      LineOfInterest& setLineLabel(const std::string val);

      /** Background Behavior line is true if point is for background behavior (Units: None)*/
      bool getBackgroundBehaviorLine(void) const { return __BackgroundBehaviorLine; }
      LineOfInterest& setBackgroundBehaviorLine(const bool val);



   protected:
      /** ID for lines of interest */
      int64_t __LineID;
      /** List of points to search */
      std::vector< afrl::cmasi::Location3D* > __Line;
      /** Action that updated this line of interest (e.g. created, destroyed, modified) */
      afrl::impact::AreaActionOptions::AreaActionOptions __LineAction;
      /** Human readable label for line of interest */
      std::string __LineLabel;
      /** Background Behavior line is true if point is for background behavior */
      bool __BackgroundBehaviorLine;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_LINEOFINTEREST_H_
