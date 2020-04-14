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
#include "afrl/impact/BatchRoutePlanRequest.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string BatchRoutePlanRequest::Subscription = "afrl.impact.BatchRoutePlanRequest";
   const std::string BatchRoutePlanRequest::TypeName = "BatchRoutePlanRequest";
   const std::string BatchRoutePlanRequest::SeriesName = "IMPACT";
   const int64_t BatchRoutePlanRequest::SeriesId = 5281966179208134656LL;
   const uint16_t BatchRoutePlanRequest::SeriesVersion = 14;
   const uint32_t BatchRoutePlanRequest::TypeId = 9;
   
   bool isBatchRoutePlanRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   bool isBatchRoutePlanRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 9) return false;
      return true;
   }
   
   std::vector< std::string > BatchRoutePlanRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   BatchRoutePlanRequest::BatchRoutePlanRequest(void) : avtas::lmcp::Object()
   {
      __RequestID = 0LL;
      __OperatingRegion = 0LL;
      __ComputeTaskToTaskTiming = false;
      __ComputeInterTaskToTaskTiming = false;

   }
     
   BatchRoutePlanRequest::BatchRoutePlanRequest(const BatchRoutePlanRequest &that) : avtas::lmcp::Object(that)
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
        __OperatingRegion = that.__OperatingRegion;
        __ComputeTaskToTaskTiming = that.__ComputeTaskToTaskTiming;
        __ComputeInterTaskToTaskTiming = that.__ComputeInterTaskToTaskTiming;
        __InterTaskPercentage.clear();
        for (size_t i=0; i< that.__InterTaskPercentage.size(); i++)
        {
           __InterTaskPercentage.push_back( that.__InterTaskPercentage[i]);
        }

   }
   
   BatchRoutePlanRequest & BatchRoutePlanRequest::operator=(const BatchRoutePlanRequest &that)
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
         __OperatingRegion = that.__OperatingRegion;
         __ComputeTaskToTaskTiming = that.__ComputeTaskToTaskTiming;
         __ComputeInterTaskToTaskTiming = that.__ComputeInterTaskToTaskTiming;
         __InterTaskPercentage.clear();
         for (size_t i=0; i< that.__InterTaskPercentage.size(); i++)
         {
            __InterTaskPercentage.push_back( that.__InterTaskPercentage[i]);
         }

      }
      return *this;
   }

   BatchRoutePlanRequest* BatchRoutePlanRequest::clone() const
   {
        return new BatchRoutePlanRequest(*this);
   }
   
   BatchRoutePlanRequest::~BatchRoutePlanRequest(void)
   {

   }
  
   void BatchRoutePlanRequest::pack(avtas::lmcp::ByteBuffer & buf) const
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
      buf.putLong(__OperatingRegion);
      buf.putBool(__ComputeTaskToTaskTiming);
      buf.putBool(__ComputeInterTaskToTaskTiming);
      buf.putUShort( static_cast<uint16_t>(__InterTaskPercentage.size()));
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         buf.putFloat(__InterTaskPercentage[i]);
      }

   }
   
   void BatchRoutePlanRequest::unpack(avtas::lmcp::ByteBuffer & buf)
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
      __OperatingRegion = buf.getLong();
      __ComputeTaskToTaskTiming = buf.getBool();
      __ComputeInterTaskToTaskTiming = buf.getBool();
      __InterTaskPercentage.clear();
      uint16_t __InterTaskPercentage_length = buf.getUShort();
      for (uint32_t i=0; i< __InterTaskPercentage_length; i++)
      {
         __InterTaskPercentage.push_back(buf.getFloat() );
      }

   }

   uint32_t BatchRoutePlanRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + sizeof(int64_t) * __Vehicles.size();
      size += 2 + sizeof(int64_t) * __TaskList.size();
      size += sizeof(int64_t);
      size += sizeof(bool);
      size += sizeof(bool);
      size += 2 + sizeof(float) * __InterTaskPercentage.size();

      return size;
   }

   std::string BatchRoutePlanRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( BatchRoutePlanRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "RequestID (int64_t) = " << __RequestID << "\n";
      oss << indent << "Vehicles (int64 [ " << __Vehicles.size() << ", var ])\n";
      oss << indent << "TaskList (int64 [ " << __TaskList.size() << ", var ])\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "ComputeTaskToTaskTiming (bool) = " << __ComputeTaskToTaskTiming << "\n";
      oss << indent << "ComputeInterTaskToTaskTiming (bool) = " << __ComputeInterTaskToTaskTiming << "\n";
      oss << indent << "InterTaskPercentage (real32 [ " << __InterTaskPercentage.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string BatchRoutePlanRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<BatchRoutePlanRequest Series=\"IMPACT\">\n";
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
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <ComputeTaskToTaskTiming>" << (__ComputeTaskToTaskTiming ? "true" : "false") << "</ComputeTaskToTaskTiming>\n";
      str << ws << "   <ComputeInterTaskToTaskTiming>" << (__ComputeInterTaskToTaskTiming ? "true" : "false") << "</ComputeInterTaskToTaskTiming>\n";
      str << ws << "   <InterTaskPercentage>\n";
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         str << ws << "   <real32>" << __InterTaskPercentage[i] << "</real32>\n";
      }
      str << ws << "   </InterTaskPercentage>\n";
      str << ws << "</BatchRoutePlanRequest>\n";

      return str.str();
   }

   bool BatchRoutePlanRequest::operator==(const BatchRoutePlanRequest & that)
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
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__ComputeTaskToTaskTiming != that.__ComputeTaskToTaskTiming) return false;
      if(__ComputeInterTaskToTaskTiming != that.__ComputeInterTaskToTaskTiming) return false;
      if(__InterTaskPercentage.size() != that.__InterTaskPercentage.size()) return false;
      for (size_t i=0; i<__InterTaskPercentage.size(); i++)
      {
         if(__InterTaskPercentage[i] != that.__InterTaskPercentage[i]) return false;
      }
      return true;

   }

   bool BatchRoutePlanRequest::operator!=(const BatchRoutePlanRequest & that)
   {
      return( !(operator==(that)) );
   }

   BatchRoutePlanRequest& BatchRoutePlanRequest::setRequestID(const int64_t val)
   {
      __RequestID = val;
      return *this;
   }



   BatchRoutePlanRequest& BatchRoutePlanRequest::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }

   BatchRoutePlanRequest& BatchRoutePlanRequest::setComputeTaskToTaskTiming(const bool val)
   {
      __ComputeTaskToTaskTiming = val;
      return *this;
   }

   BatchRoutePlanRequest& BatchRoutePlanRequest::setComputeInterTaskToTaskTiming(const bool val)
   {
      __ComputeInterTaskToTaskTiming = val;
      return *this;
   }



} // end namespace impact
} // end namespace afrl

