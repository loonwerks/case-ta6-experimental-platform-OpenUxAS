// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_ROADPOINTSCONSTRAINTS_H_
#define _UXAS_MESSAGES_ROUTE_ROADPOINTSCONSTRAINTS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Location3D.h"



namespace uxas {
namespace messages {
namespace route {


   bool isRoadPointsConstraints(avtas::lmcp::Object* obj);
   bool isRoadPointsConstraints(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RoadPointsConstraintsDescendants();
   
   class RoadPointsConstraints : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      RoadPointsConstraints(void);

      // Copy Constructor
      RoadPointsConstraints(const RoadPointsConstraints &that);

      // Assignment Operator
      RoadPointsConstraints & operator=(const RoadPointsConstraints &that);

      // Destructor
      virtual ~RoadPointsConstraints(void);

      // Equals overload
      bool operator==(const RoadPointsConstraints & that);
      bool operator!=(const RoadPointsConstraints & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual RoadPointsConstraints* clone() const;

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
      /** ID denoting this set of road points constraints (Units: None)*/
      int64_t getRoadPointsID(void) const { return __RoadPointsID; }
      RoadPointsConstraints& setRoadPointsID(const int64_t val);

      /** Location from which the road points will start (Units: None)*/
      afrl::cmasi::Location3D* const getStartLocation(void) { return __StartLocation; }
      RoadPointsConstraints& setStartLocation(const afrl::cmasi::Location3D* const val);

      /** Location to which theroad points will end (Units: None)*/
      afrl::cmasi::Location3D* const getEndLocation(void) { return __EndLocation; }
      RoadPointsConstraints& setEndLocation(const afrl::cmasi::Location3D* const val);



   protected:
      /** ID denoting this set of road points constraints */
      int64_t __RoadPointsID;
      /** Location from which the road points will start */
      afrl::cmasi::Location3D* __StartLocation;
      /** Location to which theroad points will end */
      afrl::cmasi::Location3D* __EndLocation;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_ROADPOINTSCONSTRAINTS_H_
