// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_LOITERACTION_H_
#define _AFRL_CMASI_LOITERACTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/NavigationAction.h"
#include "afrl/cmasi/LoiterType.h"
#include "afrl/cmasi/LoiterDirection.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace cmasi {


   bool isLoiterAction(avtas::lmcp::Object* obj);
   bool isLoiterAction(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > LoiterActionDescendants();
   
   class LoiterAction : public afrl::cmasi::NavigationAction {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      LoiterAction(void);

      // Copy Constructor
      LoiterAction(const LoiterAction &that);

      // Assignment Operator
      LoiterAction & operator=(const LoiterAction &that);

      // Destructor
      virtual ~LoiterAction(void);

      // Equals overload
      bool operator==(const LoiterAction & that);
      bool operator!=(const LoiterAction & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual LoiterAction* clone() const;

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
      /** The loiter shape that the vehicle should fly (Units: none)*/
      afrl::cmasi::LoiterType::LoiterType getLoiterType(void) const { return __LoiterType; }
      LoiterAction& setLoiterType(const afrl::cmasi::LoiterType::LoiterType val);

      /** The radius for the loiter. May be used for any curvature parameter of the vehicle specific hold pattern. (Units: meter)*/
      float getRadius(void) const { return __Radius; }
      LoiterAction& setRadius(const float val);

      /** Direction of the major axis of the vehicle specific hold pattern. For Racetracks and Figure-Eights, this is the direction of the long axis. Hovering loiters, this is direction the aircraft should face in the loiter. (Units: degree)*/
      float getAxis(void) const { return __Axis; }
      LoiterAction& setAxis(const float val);

      /** Used in racetrack and figure-eight loiters. For figure-eight loiters, this is the length between the focii of the turn circles. For racetracks, this is the length of the straight-away. Both types have a total length of Length + 2 * Radius. For figure-eight loiters, if Length is less than 2 * radius, then this field is ignored. (Units: meter)*/
      float getLength(void) const { return __Length; }
      LoiterAction& setLength(const float val);

      /** Direction of travel. (Units: None)*/
      afrl::cmasi::LoiterDirection::LoiterDirection getDirection(void) const { return __Direction; }
      LoiterAction& setDirection(const afrl::cmasi::LoiterDirection::LoiterDirection val);

      /** The time to loiter at this point before continuing. A negative time value denotes perpetual orbit. (Units: milliseconds)*/
      int64_t getDuration(void) const { return __Duration; }
      LoiterAction& setDuration(const int64_t val);

      /** Commanded True Airspeed (Units: meter/sec)*/
      float getAirspeed(void) const { return __Airspeed; }
      LoiterAction& setAirspeed(const float val);

      /** The geometric center point of the loiter. A valid LoiterAction must define Location (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getLocation(void) { return __Location; }
      LoiterAction& setLocation(const afrl::cmasi::Location3D* const val);



   protected:
      /** The loiter shape that the vehicle should fly */
      afrl::cmasi::LoiterType::LoiterType __LoiterType;
      /** The radius for the loiter. May be used for any curvature parameter of the vehicle specific hold pattern. */
      float __Radius;
      /** Direction of the major axis of the vehicle specific hold pattern. For Racetracks and Figure-Eights, this is the direction of the long axis. Hovering loiters, this is direction the aircraft should face in the loiter. */
      float __Axis;
      /** Used in racetrack and figure-eight loiters. For figure-eight loiters, this is the length between the focii of the turn circles. For racetracks, this is the length of the straight-away. Both types have a total length of Length + 2 * Radius. For figure-eight loiters, if Length is less than 2 * radius, then this field is ignored. */
      float __Length;
      /** Direction of travel. */
      afrl::cmasi::LoiterDirection::LoiterDirection __Direction;
      /** The time to loiter at this point before continuing. A negative time value denotes perpetual orbit. */
      int64_t __Duration;
      /** Commanded True Airspeed */
      float __Airspeed;
      /** The geometric center point of the loiter. A valid LoiterAction must define Location (null not allowed). */
      afrl::cmasi::Location3D* __Location;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_LOITERACTION_H_
