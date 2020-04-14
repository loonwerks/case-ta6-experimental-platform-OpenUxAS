// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_POINTSEARCHTASK_H_
#define _AFRL_CMASI_POINTSEARCHTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Wedge.h"

#include <vector>


namespace afrl {
namespace cmasi {


   bool isPointSearchTask(avtas::lmcp::Object* obj);
   bool isPointSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > PointSearchTaskDescendants();
   
   class PointSearchTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      PointSearchTask(void);

      // Copy Constructor
      PointSearchTask(const PointSearchTask &that);

      // Assignment Operator
      PointSearchTask & operator=(const PointSearchTask &that);

      // Destructor
      virtual ~PointSearchTask(void);

      // Equals overload
      bool operator==(const PointSearchTask & that);
      bool operator!=(const PointSearchTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual PointSearchTask* clone() const;

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
      /** Point to search. A valid PointSearchTask must define SearchLocation (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getSearchLocation(void) { return __SearchLocation; }
      PointSearchTask& setSearchLocation(const afrl::cmasi::Location3D* const val);

      /**Minimum distance that an aircraft must maintain from the point of interest. (Units: meter)*/
      float getStandoffDistance(void) const { return __StandoffDistance; }
      PointSearchTask& setStandoffDistance(const float val);

      /** A list of acceptable look-angles for this task. Each wedge is defined relative to true North. To be a valid look angle, a sensor must be looking from a direction within the bounds of the wedge. (Units: None)*/
      std::vector<afrl::cmasi::Wedge*> & getViewAngleList(void) { return __ViewAngleList; }



   protected:
      /** Point to search. A valid PointSearchTask must define SearchLocation (null not allowed). */
      afrl::cmasi::Location3D* __SearchLocation;
      /**Minimum distance that an aircraft must maintain from the point of interest. */
      float __StandoffDistance;
      /** A list of acceptable look-angles for this task. Each wedge is defined relative to true North. To be a valid look angle, a sensor must be looking from a direction within the bounds of the wedge. */
      std::vector< afrl::cmasi::Wedge* > __ViewAngleList;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_POINTSEARCHTASK_H_
