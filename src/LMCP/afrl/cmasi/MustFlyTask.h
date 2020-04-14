// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_MUSTFLYTASK_H_
#define _AFRL_CMASI_MUSTFLYTASK_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/Task.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace cmasi {


   bool isMustFlyTask(avtas::lmcp::Object* obj);
   bool isMustFlyTask(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > MustFlyTaskDescendants();
   
   class MustFlyTask : public afrl::cmasi::Task {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      MustFlyTask(void);

      // Copy Constructor
      MustFlyTask(const MustFlyTask &that);

      // Assignment Operator
      MustFlyTask & operator=(const MustFlyTask &that);

      // Destructor
      virtual ~MustFlyTask(void);

      // Equals overload
      bool operator==(const MustFlyTask & that);
      bool operator!=(const MustFlyTask & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual MustFlyTask* clone() const;

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
      /** Point that vehicle must fly through. Null position not allowed. (Units: None)*/
      afrl::cmasi::Location3D* const getPosition(void) { return __Position; }
      MustFlyTask& setPosition(const afrl::cmasi::Location3D* const val);

      /** Denotes whether altitude should be used in this MustFlyTask. If false, the aircraft should maintain altitude according to previous commands. (Units: None)*/
      bool getUseAltitude(void) const { return __UseAltitude; }
      MustFlyTask& setUseAltitude(const bool val);



   protected:
      /** Point that vehicle must fly through. Null position not allowed. */
      afrl::cmasi::Location3D* __Position;
      /** Denotes whether altitude should be used in this MustFlyTask. If false, the aircraft should maintain altitude according to previous commands. */
      bool __UseAltitude;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_MUSTFLYTASK_H_
