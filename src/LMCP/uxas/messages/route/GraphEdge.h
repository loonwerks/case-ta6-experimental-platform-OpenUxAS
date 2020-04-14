// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_GRAPHEDGE_H_
#define _UXAS_MESSAGES_ROUTE_GRAPHEDGE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "afrl/cmasi/Location3D.h"

#include <vector>


namespace uxas {
namespace messages {
namespace route {


   bool isGraphEdge(avtas::lmcp::Object* obj);
   bool isGraphEdge(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GraphEdgeDescendants();
   
   class GraphEdge : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GraphEdge(void);

      // Copy Constructor
      GraphEdge(const GraphEdge &that);

      // Assignment Operator
      GraphEdge & operator=(const GraphEdge &that);

      // Destructor
      virtual ~GraphEdge(void);

      // Equals overload
      bool operator==(const GraphEdge & that);
      bool operator!=(const GraphEdge & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GraphEdge* clone() const;

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
      /** Unique ID for the edge (Units: None)*/
      int64_t getEdgeID(void) const { return __EdgeID; }
      GraphEdge& setEdgeID(const int64_t val);

      /** GraphNode ID which defines the start point of the edge (Units: None)*/
      int64_t getStartNode(void) const { return __StartNode; }
      GraphEdge& setStartNode(const int64_t val);

      /** GraphNode ID which defines the end point of the edge (Units: None)*/
      int64_t getEndNode(void) const { return __EndNode; }
      GraphEdge& setEndNode(const int64_t val);

      /** Optional waypoints describing physical edge in lat/lon coordinates (Units: None)*/
      std::vector<afrl::cmasi::Location3D*> & getWaypoints(void) { return __Waypoints; }



   protected:
      /** Unique ID for the edge */
      int64_t __EdgeID;
      /** GraphNode ID which defines the start point of the edge */
      int64_t __StartNode;
      /** GraphNode ID which defines the end point of the edge */
      int64_t __EndNode;
      /** Optional waypoints describing physical edge in lat/lon coordinates */
      std::vector< afrl::cmasi::Location3D* > __Waypoints;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_GRAPHEDGE_H_
