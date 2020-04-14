// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_AUTOPILOTKEEPALIVE_H_
#define _UXAS_MESSAGES_UXNATIVE_AUTOPILOTKEEPALIVE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"



namespace uxas {
namespace messages {
namespace uxnative {


   bool isAutopilotKeepAlive(avtas::lmcp::Object* obj);
   bool isAutopilotKeepAlive(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > AutopilotKeepAliveDescendants();
   
   class AutopilotKeepAlive : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      AutopilotKeepAlive(void);

      // Copy Constructor
      AutopilotKeepAlive(const AutopilotKeepAlive &that);

      // Assignment Operator
      AutopilotKeepAlive & operator=(const AutopilotKeepAlive &that);

      // Destructor
      virtual ~AutopilotKeepAlive(void);

      // Equals overload
      bool operator==(const AutopilotKeepAlive & that);
      bool operator!=(const AutopilotKeepAlive & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual AutopilotKeepAlive* clone() const;

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
      /** Enable communications between UxAS and the autopilot (Units: None)*/
      bool getAutopilotEnabled(void) const { return __AutopilotEnabled; }
      AutopilotKeepAlive& setAutopilotEnabled(const bool val);

      /** Allow UxAS to send speed commands to the autopilot (Units: None)*/
      bool getSpeedAuthorized(void) const { return __SpeedAuthorized; }
      AutopilotKeepAlive& setSpeedAuthorized(const bool val);

      /** Enable communications between UxAS and the Gimbal. Note: this does not effect the video stream. (Units: None)*/
      bool getGimbalEnabled(void) const { return __GimbalEnabled; }
      AutopilotKeepAlive& setGimbalEnabled(const bool val);

      /** Time that this message was sent (Units: milliseconds since 1 Jan 1970)*/
      int64_t getTimeSent(void) const { return __TimeSent; }
      AutopilotKeepAlive& setTimeSent(const int64_t val);

      /** Overrides speed to this value if greater than zero (Units: meters/sec)*/
      float getSpeedOverride(void) const { return __SpeedOverride; }
      AutopilotKeepAlive& setSpeedOverride(const float val);

      /** Overrides altitude to this value (MSL) if greater than zero (Units: meters MSL)*/
      float getAltOverride(void) const { return __AltOverride; }
      AutopilotKeepAlive& setAltOverride(const float val);



   protected:
      /** Enable communications between UxAS and the autopilot */
      bool __AutopilotEnabled;
      /** Allow UxAS to send speed commands to the autopilot */
      bool __SpeedAuthorized;
      /** Enable communications between UxAS and the Gimbal. Note: this does not effect the video stream. */
      bool __GimbalEnabled;
      /** Time that this message was sent */
      int64_t __TimeSent;
      /** Overrides speed to this value if greater than zero */
      float __SpeedOverride;
      /** Overrides altitude to this value (MSL) if greater than zero */
      float __AltOverride;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_AUTOPILOTKEEPALIVE_H_
