// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#include <cassert>
#include <sstream>
#include <iomanip>
#include "uxas/messages/uxnative/SimulationTimeStepAcknowledgement.h"


namespace uxas {
namespace messages {
namespace uxnative {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string SimulationTimeStepAcknowledgement::Subscription = "uxas.messages.uxnative.SimulationTimeStepAcknowledgement";
   const std::string SimulationTimeStepAcknowledgement::TypeName = "SimulationTimeStepAcknowledgement";
   const std::string SimulationTimeStepAcknowledgement::SeriesName = "UXNATIVE";
   const int64_t SimulationTimeStepAcknowledgement::SeriesId = 6149751333668345413LL;
   const uint16_t SimulationTimeStepAcknowledgement::SeriesVersion = 9;
   const uint32_t SimulationTimeStepAcknowledgement::TypeId = 16;
   
   bool isSimulationTimeStepAcknowledgement(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   bool isSimulationTimeStepAcknowledgement(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149751333668345413LL) return false;
      if(obj->getSeriesVersion() != 9) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   std::vector< std::string > SimulationTimeStepAcknowledgementDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   SimulationTimeStepAcknowledgement::SimulationTimeStepAcknowledgement(void) : avtas::lmcp::Object()
   {
      __VehicleID = 0LL;
      __ReportedTime = 0LL;

   }
     
   SimulationTimeStepAcknowledgement::SimulationTimeStepAcknowledgement(const SimulationTimeStepAcknowledgement &that) : avtas::lmcp::Object(that)
   {
        __VehicleID = that.__VehicleID;
        __ReportedTime = that.__ReportedTime;

   }
   
   SimulationTimeStepAcknowledgement & SimulationTimeStepAcknowledgement::operator=(const SimulationTimeStepAcknowledgement &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __VehicleID = that.__VehicleID;
         __ReportedTime = that.__ReportedTime;

      }
      return *this;
   }

   SimulationTimeStepAcknowledgement* SimulationTimeStepAcknowledgement::clone() const
   {
        return new SimulationTimeStepAcknowledgement(*this);
   }
   
   SimulationTimeStepAcknowledgement::~SimulationTimeStepAcknowledgement(void)
   {

   }
  
   void SimulationTimeStepAcknowledgement::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__VehicleID);
      buf.putLong(__ReportedTime);

   }
   
   void SimulationTimeStepAcknowledgement::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __VehicleID = buf.getLong();
      __ReportedTime = buf.getLong();

   }

   uint32_t SimulationTimeStepAcknowledgement::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);

      return size;
   }

   std::string SimulationTimeStepAcknowledgement::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( SimulationTimeStepAcknowledgement ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "ReportedTime (int64_t) = " << __ReportedTime << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string SimulationTimeStepAcknowledgement::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<SimulationTimeStepAcknowledgement Series=\"UXNATIVE\">\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <ReportedTime>" << __ReportedTime << "</ReportedTime>\n";
      str << ws << "</SimulationTimeStepAcknowledgement>\n";

      return str.str();
   }

   bool SimulationTimeStepAcknowledgement::operator==(const SimulationTimeStepAcknowledgement & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__VehicleID != that.__VehicleID) return false;
      if(__ReportedTime != that.__ReportedTime) return false;
      return true;

   }

   bool SimulationTimeStepAcknowledgement::operator!=(const SimulationTimeStepAcknowledgement & that)
   {
      return( !(operator==(that)) );
   }

   SimulationTimeStepAcknowledgement& SimulationTimeStepAcknowledgement::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }

   SimulationTimeStepAcknowledgement& SimulationTimeStepAcknowledgement::setReportedTime(const int64_t val)
   {
      __ReportedTime = val;
      return *this;
   }


} // end namespace uxnative
} // end namespace messages
} // end namespace uxas

