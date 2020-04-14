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
#include "afrl/impact/BatchSummaryRequest.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BatchSummaryRequest::Subscription = "afrl.impact.BatchSummaryRequest";
   const std::string BatchSummaryRequest::TypeName = "BatchSummaryRequest";
   const std::string BatchSummaryRequest::SeriesName = "IMPACT";
   const int64_t BatchSummaryRequest::SeriesId = 5281966179208134656LL;
   const uint16_t BatchSummaryRequest::SeriesVersion = 14;
   const uint32_t BatchSummaryRequest::TypeId = 12;
   
   bool isBatchSummaryRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   bool isBatchSummaryRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 12) return false;
      return true;
   }
   
   std::vector< std::string > BatchSummaryRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BatchSummaryRequest::BatchSummaryRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __TaskRelationships = std::string("");
      __OperatingRegion = 0LL;

   }
     
   BatchSummaryRequest::BatchSummaryRequest(const BatchSummaryRequest &that) : avtas::lmcp::Object(that)
   {
        __RequestID = that.__RequestID;
        __Vehicles.clear();
        for (size_t i=0; i< that.__Vehicles.size(); i++)
        {
           __Vehicles.push_back( that.__Vehicles[i]);
        }
        __TaskList.clear();
        for (size_t i=0; i< that.__TaskList.size(); i++)
        {
           __TaskList.push_back( that.__TaskList[i]);
        }
        __TaskRelationships = that.__TaskRelationships;
        __InterTaskPercentage.clear();
        for (size_t i=0; i< that.__InterTaskPercentage.size(); i++)
        {
           __InterTaskPercentage.push_back( that.__InterTaskPercentage[i]);
        }
        __OperatingRegion = that.__OperatingRegion;

   }
   
   BatchSummaryRequest & BatchSummaryRequest::operator=(const BatchSummaryRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __RequestID = that.__RequestID;
         __Vehicles.clear();
         for (size_t i=0; i< that.__Vehicles.size(); i++)
         {
            __Vehicles.push_back( that.__Vehicles[i]);
         }
         __TaskList.clear();
         for (size_t i=0; i< that.__TaskList.size(); i++)
         {
            __TaskList.push_back( that.__TaskList[i]);
         }
         __TaskRelationships = that.__TaskRelationships;
         __InterTaskPercentage.clear();
         for (size_t i=0; i< that.__InterTaskPercentage.size(); i++)
         {
            __InterTaskPercentage.push_back( that.__InterTaskPercentage[i]);
         }
         __OperatingRegion = that.__OperatingRegion;

      }
      return *this;
   }

   BatchSummaryRequest* BatchSummaryRequest::clone() const
   {
        return new BatchSummaryRequest(*this);
   }
   
   BatchSummaryRequest::~BatchSummaryRequest(void)
   {

   }
  
   void BatchSummaryRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__RequestID);
      buf.putUShort( static_cast<uint16_t>(__Vehicles.size()));
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         buf.putLong(__Vehicles[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__TaskList.size()));
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         buf.putLong(__TaskList[i]);
      }
      buf.putString(__TaskRelationships);
      buf.putUShort( static_cast<uint16_t>(__InterTaskPercentage.size()));
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         buf.putFloat(__InterTaskPercentage[i]);
      }
      buf.putLong(__OperatingRegion);

   }
   
   void BatchSummaryRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __RequestID = buf.getLong();
      __Vehicles.clear();
      uint16_t __Vehicles_length = buf.getUShort();
      for (uint32_t i=0; i< __Vehicles_length; i++)
      {
         __Vehicles.push_back(buf.getLong() );
      }
      __TaskList.clear();
      uint16_t __TaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskList_length; i++)
      {
         __TaskList.push_back(buf.getLong() );
      }
      __TaskRelationships = buf.getString();
      __InterTaskPercentage.clear();
      uint16_t __InterTaskPercentage_length = buf.getUShort();
      for (uint32_t i=0; i< __InterTaskPercentage_length; i++)
      {
         __InterTaskPercentage.push_back(buf.getFloat() );
      }
      __OperatingRegion = buf.getLong();

   }

   uint32_t BatchSummaryRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __Vehicles.size();
      size += 2 + sizeof(int64_t) * __TaskList.size();
      size += 2 + __TaskRelationships.length();
      size += 2 + sizeof(float) * __InterTaskPercentage.size();
      size += sizeof(int64_t);

      return size;
   }

   std::string BatchSummaryRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BatchSummaryRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "Vehicles (int64 [ " << __Vehicles.size() << ", var ])\n";
      oss << indent << "TaskList (int64 [ " << __TaskList.size() << ", var ])\n";
      oss << indent << "TaskRelationships (std::string) = " << __TaskRelationships << "\n";
      oss << indent << "InterTaskPercentage (real32 [ " << __InterTaskPercentage.size() << ", var ])\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BatchSummaryRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BatchSummaryRequest Series=\"IMPACT\">\n";
      str << ws << "   <RequestID>" << __RequestID << "</RequestID>\n";
      str << ws << "   <Vehicles>\n";
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         str << ws << "   <int64>" << __Vehicles[i] << "</int64>\n";
      }
      str << ws << "   </Vehicles>\n";
      str << ws << "   <TaskList>\n";
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         str << ws << "   <int64>" << __TaskList[i] << "</int64>\n";
      }
      str << ws << "   </TaskList>\n";
      str << ws << "   <TaskRelationships>" << __TaskRelationships << "</TaskRelationships>\n";
      str << ws << "   <InterTaskPercentage>\n";
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         str << ws << "   <real32>" << __InterTaskPercentage[i] << "</real32>\n";
      }
      str << ws << "   </InterTaskPercentage>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "</BatchSummaryRequest>\n";

      return str.str();
   }

   bool BatchSummaryRequest::operator==(const BatchSummaryRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__RequestID != that.__RequestID) return false;
      if(__Vehicles.size() != that.__Vehicles.size()) return false;
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         if(__Vehicles[i] != that.__Vehicles[i]) return false;
      }
      if(__TaskList.size() != that.__TaskList.size()) return false;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if(__TaskList[i] != that.__TaskList[i]) return false;
      }
      if(__TaskRelationships != that.__TaskRelationships) return false;
      if(__InterTaskPercentage.size() != that.__InterTaskPercentage.size()) return false;
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         if(__InterTaskPercentage[i] != that.__InterTaskPercentage[i]) return false;
      }
      if(__OperatingRegion != that.__OperatingRegion) return false;
      return true;

   }

   bool BatchSummaryRequest::operator!=(const BatchSummaryRequest & that)
   {
      return( !(operator==(that)) );
   }

   BatchSummaryRequest& BatchSummaryRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }



   BatchSummaryRequest& BatchSummaryRequest::setTaskRelationships(const std::string val)
   {
      __TaskRelationships = val;
      return *this;
   }


   BatchSummaryRequest& BatchSummaryRequest::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

