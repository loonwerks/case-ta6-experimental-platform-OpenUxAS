// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_IMPACT_IMPACTLINESEARCHTASK_H_
#define _AFRL_IMPACT_IMPACTLINESEARCHTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "IMPACTEnum.h"
#include "afrl/cmasi/SearchTask.h"
#include "afrl/cmasi/Wedge.h"

#include <vector>


namespace afrl {
namespace impact {


   bool isImpactLineSearchTask(avtas::lmcp::Object* obj);
   bool isImpactLineSearchTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > ImpactLineSearchTaskDescendants();
   
   class ImpactLineSearchTask : public afrl::cmasi::SearchTask {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      ImpactLineSearchTask(void);

      // Copy Constructor
      ImpactLineSearchTask(const ImpactLineSearchTask &that);

      // Assignment Operator
      ImpactLineSearchTask & operator=(const ImpactLineSearchTask &that);

      // Destructor
      virtual ~ImpactLineSearchTask(void);

      // Equals overload
      bool operator==(const ImpactLineSearchTask & that);
      bool operator!=(const ImpactLineSearchTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual ImpactLineSearchTask* clone() const;

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
      /** ID of line to search (from available lines of interest) (Units: None)*/
      int64_t getLineID(void) const { return __LineID; }
      ImpactLineSearchTask& setLineID(const int64_t val);

      /** Defines a list of acceptable look-angles for this task. See the documentation above for details. (Units: None)*/
      std::vector<afrl::cmasi::Wedge*> & getViewAngleList(void) { return __ViewAngleList; }

      /** If true, the ViewAngleList specifies inertial (North-East) angles. See documentation above. (Units: None)*/
      bool getUseInertialViewAngles(void) const { return __UseInertialViewAngles; }
      ImpactLineSearchTask& setUseInertialViewAngles(const bool val);



   protected:
      /** ID of line to search (from available lines of interest) */
      int64_t __LineID;
      /** Defines a list of acceptable look-angles for this task. See the documentation above for details. */
      std::vector< afrl::cmasi::Wedge* > __ViewAngleList;
      /** If true, the ViewAngleList specifies inertial (North-East) angles. See documentation above. */
      bool __UseInertialViewAngles;

   };

} // end namespace impact
} // end namespace afrl


#endif // _AFRL_IMPACT_IMPACTLINESEARCHTASK_H_
