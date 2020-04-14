// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_PERCEIVE_ENTITYPERCEPTION_H_
#define _AFRL_CMASI_PERCEIVE_ENTITYPERCEPTION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "PERCEIVEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"

#include <vector>


namespace afrl {
namespace cmasi {
namespace perceive {


   bool isEntityPerception(avtas::lmcp::Object* obj);
   bool isEntityPerception(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > EntityPerceptionDescendants();
   
   class EntityPerception : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      EntityPerception(void);

      // Copy Constructor
      EntityPerception(const EntityPerception &that);

      // Assignment Operator
      EntityPerception & operator=(const EntityPerception &that);

      // Destructor
      virtual ~EntityPerception(void);

      // Equals overload
      bool operator==(const EntityPerception & that);
      bool operator!=(const EntityPerception & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual EntityPerception* clone() const;

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
      /** A scenario-unique ID for this target entity. IDs should be greater than zero. Since this is a perception, the entity ID may not be known. In that case, this field should be set to zero. (Units: None)*/
      uint32_t getPerceivedEntityID(void) const { return __PerceivedEntityID; }
      EntityPerception& setPerceivedEntityID(const uint32_t val);

      /** ID of the entity or aircraft that reported the detection/perception (Units: None)*/
      uint32_t getPerceiverID(void) const { return __PerceiverID; }
      EntityPerception& setPerceiverID(const uint32_t val);

      /** The IDs of the payloads that reported this perception. (Units: None)*/
      std::vector<uint32_t> & getPerceiverPayloads(void) { return __PerceiverPayloads; }

      /** The perceived target velocity in three-dimensions. The velocity should be stated in tangential-plane coordinates using the North-East-Down coordinate system. (Units: meter/sec)*/
      float* getVelocity(void) { return __Velocity; }

      /** Velocity error for this perception. The error terms should be in the same coordinate system as the velocity. (Units: meter/sec)*/
      float* getVelocityError(void) { return __VelocityError; }

      /** If true, denotes that the velocity and velocity error have meaning. (Units: None)*/
      bool getVelocityValid(void) const { return __VelocityValid; }
      EntityPerception& setVelocityValid(const bool val);

      /** Euler angle tangential-plane attitude for this entity. Should be stated as Psi-Theta-Phi. For information on Euler coordinates, see <a href="http://en.wikipedia.org/wiki/Euler_angle">Euler Angles</a> (Units: degree)*/
      float* getAttitude(void) { return __Attitude; }

      /** Error in the perception of the entity attitude. This should be in the same coordinate system as the attitude. (Units: degree)*/
      float* getAttitudeError(void) { return __AttitudeError; }

      /** If true, denotes that the attitude and attitude error have meaning. (Units: None)*/
      bool getAttitudeValid(void) const { return __AttitudeValid; }
      EntityPerception& setAttitudeValid(const bool val);

      /** The entity location. A valid EntityPerception must define Location (null not allowed) (Units: None)*/
      afrl::cmasi::Location3D* const getLocation(void) { return __Location; }
      EntityPerception& setLocation(const afrl::cmasi::Location3D* const val);

      /** Error in the perception of the location of this entity. The first index is North-South error, the second index is the East-West error, and the third index is the vertical error. The result is an error cylinder. (Units: meter)*/
      float* getLocationError(void) { return __LocationError; }

      /** Time that this entity was perceived since scenario start. (Units: millisecond)*/
      int64_t getTimeLastSeen(void) const { return __TimeLastSeen; }
      EntityPerception& setTimeLastSeen(const int64_t val);



   protected:
      /** A scenario-unique ID for this target entity. IDs should be greater than zero. Since this is a perception, the entity ID may not be known. In that case, this field should be set to zero. */
      uint32_t __PerceivedEntityID;
      /** ID of the entity or aircraft that reported the detection/perception */
      uint32_t __PerceiverID;
      /** The IDs of the payloads that reported this perception. */
      std::vector< uint32_t > __PerceiverPayloads;
      /** The perceived target velocity in three-dimensions. The velocity should be stated in tangential-plane coordinates using the North-East-Down coordinate system. */
      float __Velocity[3];
      /** Velocity error for this perception. The error terms should be in the same coordinate system as the velocity. */
      float __VelocityError[3];
      /** If true, denotes that the velocity and velocity error have meaning. */
      bool __VelocityValid;
      /** Euler angle tangential-plane attitude for this entity. Should be stated as Psi-Theta-Phi. For information on Euler coordinates, see <a href="http://en.wikipedia.org/wiki/Euler_angle">Euler Angles</a> */
      float __Attitude[3];
      /** Error in the perception of the entity attitude. This should be in the same coordinate system as the attitude. */
      float __AttitudeError[3];
      /** If true, denotes that the attitude and attitude error have meaning. */
      bool __AttitudeValid;
      /** The entity location. A valid EntityPerception must define Location (null not allowed) */
      afrl::cmasi::Location3D* __Location;
      /** Error in the perception of the location of this entity. The first index is North-South error, the second index is the East-West error, and the third index is the vertical error. The result is an error cylinder. */
      float __LocationError[3];
      /** Time that this entity was perceived since scenario start. */
      int64_t __TimeLastSeen;

   };

} // end namespace perceive
} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_PERCEIVE_ENTITYPERCEPTION_H_
