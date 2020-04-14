// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_GRAPHNODE_H_
#define _UXAS_MESSAGES_ROUTE_GRAPHNODE_H_

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


   bool isGraphNode(avtas::lmcp::Object* obj);
   bool isGraphNode(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GraphNodeDescendants();
   
   class GraphNode : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GraphNode(void);

      // Copy Constructor
      GraphNode(const GraphNode &that);

      // Assignment Operator
      GraphNode & operator=(const GraphNode &that);

      // Destructor
      virtual ~GraphNode(void);

      // Equals overload
      bool operator==(const GraphNode & that);
      bool operator!=(const GraphNode & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GraphNode* clone() const;

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
      /** Unique ID for the node, used to build edges between nodes (Units: None)*/
      int64_t getNodeID(void) const { return __NodeID; }
      GraphNode& setNodeID(const int64_t val);

      /** Lat/Lon coordinates of node. A valid GraphNode must define Coordinates (null not allowed). (Units: None)*/
      afrl::cmasi::Location3D* const getCoordinates(void) { return __Coordinates; }
      GraphNode& setCoordinates(const afrl::cmasi::Location3D* const val);

      /** IDs of edges that have this node as an endpoint (Units: None)*/
      std::vector<int64_t> & getAssociatedEdges(void) { return __AssociatedEdges; }



   protected:
      /** Unique ID for the node, used to build edges between nodes */
      int64_t __NodeID;
      /** Lat/Lon coordinates of node. A valid GraphNode must define Coordinates (null not allowed). */
      afrl::cmasi::Location3D* __Coordinates;
      /** IDs of edges that have this node as an endpoint */
      std::vector< int64_t > __AssociatedEdges;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_GRAPHNODE_H_
