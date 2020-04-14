// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _AFRL_CMASI_RECTANGLE_H_
#define _AFRL_CMASI_RECTANGLE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "CMASIEnum.h"
#include "afrl/cmasi/AbstractGeometry.h"
#include "afrl/cmasi/Location3D.h"



namespace afrl {
namespace cmasi {


   bool isRectangle(avtas::lmcp::Object* obj);
   bool isRectangle(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > RectangleDescendants();
   
   class Rectangle : public afrl::cmasi::AbstractGeometry {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      Rectangle(void);

      // Copy Constructor
      Rectangle(const Rectangle &that);

      // Assignment Operator
      Rectangle & operator=(const Rectangle &that);

      // Destructor
      virtual ~Rectangle(void);

      // Equals overload
      bool operator==(const Rectangle & that);
      bool operator!=(const Rectangle & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual Rectangle* clone() const;

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
      /** Center point of the rectangle (note altitude value is ignored). A valid Rectangle must define CenterPoint (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getCenterPoint(void) { return __CenterPoint; }
      Rectangle& setCenterPoint(const afrl::cmasi::Location3D* const val);

      /** Width of the rectangle (Units: meter)*/
      float getWidth(void) const { return __Width; }
      Rectangle& setWidth(const float val);

      /** Height of the rectangle (Units: meter)*/
      float getHeight(void) const { return __Height; }
      Rectangle& setHeight(const float val);

      /** Rotation of the rectangle around the center point (positive from north axis towards east) (Units: degree)*/
      float getRotation(void) const { return __Rotation; }
      Rectangle& setRotation(const float val);



   protected:
      /** Center point of the rectangle (note altitude value is ignored). A valid Rectangle must define CenterPoint (null not allowed). */
      afrl::cmasi::Location3D* __CenterPoint;
      /** Width of the rectangle */
      float __Width;
      /** Height of the rectangle */
      float __Height;
      /** Rotation of the rectangle around the center point (positive from north axis towards east) */
      float __Rotation;

   };

} // end namespace cmasi
} // end namespace afrl


#endif // _AFRL_CMASI_RECTANGLE_H_
