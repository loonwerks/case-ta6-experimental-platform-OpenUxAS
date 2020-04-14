// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_ANGLEDAREASEARCHTASK_H_
#define _AFRL_IMPACT_ANGLEDAREASEARCHTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace impact {


   bool isAngledAreaSearchTask(avtas::lmcp::Object* obj);
   bool isAngledAreaSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AngledAreaSearchTaskDescendants();
   
   class AngledAreaSearchTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AngledAreaSearchTask(void);

      // Copy Constructor
      AngledAreaSearchTask(const AngledAreaSearchTask &that);

      // Assignment Operator
      AngledAreaSearchTask & operator=(const AngledAreaSearchTask &that);

      // Destructor
      virtual ~AngledAreaSearchTask(void);

      // Equals overload
      bool operator==(const AngledAreaSearchTask & that);
      bool operator!=(const AngledAreaSearchTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AngledAreaSearchTask* clone() const;

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
      /** Area to search (from available areas of interest) (Units: None)*/
      int64_t getSearchAreaID(void) const { return __SearchAreaID; }
      AngledAreaSearchTask& setSearchAreaID(const int64_t val);

      /** Sweep angle defined from true North in clockwise manner (Units: degrees)*/
      float getSweepAngle(void) const { return __SweepAngle; }
      AngledAreaSearchTask& setSweepAngle(const float val);

      /** Optional start point that must be reached before beginning search (Units: None)*/
      afrl::cmasi::Location3D* const getStartPoint(void) { return __StartPoint; }
      AngledAreaSearchTask& setStartPoint(const afrl::cmasi::Location3D* const val);



   protected:
      /** Area to search (from available areas of interest) */
      int64_t __SearchAreaID;
      /** Sweep angle defined from true North in clockwise manner */
      float __SweepAngle;
      /** Optional start point that must be reached before beginning search */
      afrl::cmasi::Location3D* __StartPoint;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_ANGLEDAREASEARCHTASK_H_
