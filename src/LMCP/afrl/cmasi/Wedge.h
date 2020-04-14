// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_WEDGE_H_
#define _AFRL_CMASI_WEDGE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "avtas/lmcp/Object.h"



namespace afrl {
namespace cmasi {


   bool isWedge(avtas::lmcp::Object* obj);
   bool isWedge(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > WedgeDescendants();
   
   class Wedge : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      Wedge(void);

      // Copy Constructor
      Wedge(const Wedge &that);

      // Assignment Operator
      Wedge & operator=(const Wedge &that);

      // Destructor
      virtual ~Wedge(void);

      // Equals overload
      bool operator==(const Wedge & that);
      bool operator!=(const Wedge & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual Wedge* clone() const;

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
      /** Azimuthal centerline of the wedge. (Units: degree)*/
      float getAzimuthCenterline(void) const { return __AzimuthCenterline; }
      Wedge& setAzimuthCenterline(const float val);

      /** Vertical centerline of the wedge. (Units: degree)*/
      float getVerticalCenterline(void) const { return __VerticalCenterline; }
      Wedge& setVerticalCenterline(const float val);

      /** Azimuthal angular extent of the wedge. The extent is centered around the centerline. A value of zero denotes that this wedge is defined as a single angle. (Units: degree)*/
      float getAzimuthExtent(void) const { return __AzimuthExtent; }
      Wedge& setAzimuthExtent(const float val);

      /** Vertical angular extent of the wedge. The extent is centered around the centerline. A value of zero denotes that this wedge is defined as a single angle. (Units: degree)*/
      float getVerticalExtent(void) const { return __VerticalExtent; }
      Wedge& setVerticalExtent(const float val);



   protected:
      /** Azimuthal centerline of the wedge. */
      float __AzimuthCenterline;
      /** Vertical centerline of the wedge. */
      float __VerticalCenterline;
      /** Azimuthal angular extent of the wedge. The extent is centered around the centerline. A value of zero denotes that this wedge is defined as a single angle. */
      float __AzimuthExtent;
      /** Vertical angular extent of the wedge. The extent is centered around the centerline. A value of zero denotes that this wedge is defined as a single angle. */
      float __VerticalExtent;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_WEDGE_H_
