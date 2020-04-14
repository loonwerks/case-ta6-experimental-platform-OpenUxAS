// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_ROUTE_GRAPHREGION_H_
#define _UXAS_MESSAGES_ROUTE_GRAPHREGION_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "ROUTEEnum.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/route/GraphNode.h"
#include "uxas/messages/route/GraphEdge.h"

#include <vector>


namespace uxas {
namespace messages {
namespace route {


   bool isGraphRegion(avtas::lmcp::Object* obj);
   bool isGraphRegion(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > GraphRegionDescendants();
   
   class GraphRegion : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      GraphRegion(void);

      // Copy Constructor
      GraphRegion(const GraphRegion &that);

      // Assignment Operator
      GraphRegion & operator=(const GraphRegion &that);

      // Destructor
      virtual ~GraphRegion(void);

      // Equals overload
      bool operator==(const GraphRegion & that);
      bool operator!=(const GraphRegion & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual GraphRegion* clone() const;

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
      /** ID for full region data structure (Units: None)*/
      int64_t getID(void) const { return __ID; }
      GraphRegion& setID(const int64_t val);

      /** List of all nodes that represent the network (note 2^24 max) (Units: None)*/
      std::vector<uxas::messages::route::GraphNode*> & getNodeList(void) { return __NodeList; }

      /** List of all edges that represent the network (note 2^24 max) (Units: None)*/
      std::vector<uxas::messages::route::GraphEdge*> & getEdgeList(void) { return __EdgeList; }



   protected:
      /** ID for full region data structure */
      int64_t __ID;
      /** List of all nodes that represent the network (note 2^24 max) */
      std::vector< uxas::messages::route::GraphNode* > __NodeList;
      /** List of all edges that represent the network (note 2^24 max) */
      std::vector< uxas::messages::route::GraphEdge* > __EdgeList;

   };

} // end namespace route
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_ROUTE_GRAPHREGION_H_
