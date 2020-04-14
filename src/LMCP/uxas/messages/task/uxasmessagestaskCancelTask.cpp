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
#include "uxas/messages/task/CancelTask.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CancelTask::Subscription = "uxas.messages.task.CancelTask";
   const std::string CancelTask::TypeName = "CancelTask";
   const std::string CancelTask::SeriesName = "UXTASK";
   const int64_t CancelTask::SeriesId = 6149757930721443840LL;
   const uint16_t CancelTask::SeriesVersion = 8;
   const uint32_t CancelTask::TypeId = 29;
   
   bool isCancelTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 29) return false;
      return true;
   }
   
   bool isCancelTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 29) return false;
      return true;
   }
   
   std::vector< std::string > CancelTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CancelTask::CancelTask(void) : avtas::lmcp::Object()
   {

   }
     
   CancelTask::CancelTask(const CancelTask &that) : avtas::lmcp::Object(that)
   {
        __Vehicles.clear();
        for (size_t i=0; i< that.__Vehicles.size(); i++)
        {
           __Vehicles.push_back( that.__Vehicles[i]);
        }
        __CanceledTasks.clear();
        for (size_t i=0; i< that.__CanceledTasks.size(); i++)
        {
           __CanceledTasks.push_back( that.__CanceledTasks[i]);
        }

   }
   
   CancelTask & CancelTask::operator=(const CancelTask &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __Vehicles.clear();
         for (size_t i=0; i< that.__Vehicles.size(); i++)
         {
            __Vehicles.push_back( that.__Vehicles[i]);
         }
         __CanceledTasks.clear();
         for (size_t i=0; i< that.__CanceledTasks.size(); i++)
         {
            __CanceledTasks.push_back( that.__CanceledTasks[i]);
         }

      }
      return *this;
   }

   CancelTask* CancelTask::clone() const
   {
        return new CancelTask(*this);
   }
   
   CancelTask::~CancelTask(void)
   {

   }
  
   void CancelTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__Vehicles.size()));
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         buf.putLong(__Vehicles[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__CanceledTasks.size()));
      for (size_t i=0; i<__CanceledTasks.size(); i++)
      {
         buf.putLong(__CanceledTasks[i]);
      }

   }
   
   void CancelTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __Vehicles.clear();
      uint16_t __Vehicles_length = buf.getUShort();
      for (uint32_t i=0; i< __Vehicles_length; i++)
      {
         __Vehicles.push_back(buf.getLong() );
      }
      __CanceledTasks.clear();
      uint16_t __CanceledTasks_length = buf.getUShort();
      for (uint32_t i=0; i< __CanceledTasks_length; i++)
      {
         __CanceledTasks.push_back(buf.getLong() );
      }

   }

   uint32_t CancelTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __Vehicles.size();
      size += 2 + sizeof(int64_t) * __CanceledTasks.size();

      return size;
   }

   std::string CancelTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CancelTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "Vehicles (int64 [ " << __Vehicles.size() << ", var ])\n";
      oss << indent << "CanceledTasks (int64 [ " << __CanceledTasks.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CancelTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CancelTask Series=\"UXTASK\">\n";
      str << ws << "   <Vehicles>\n";
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         str << ws << "   <int64>" << __Vehicles[i] << "</int64>\n";
      }
      str << ws << "   </Vehicles>\n";
      str << ws << "   <CanceledTasks>\n";
      for (size_t i=0; i<__CanceledTasks.size(); i++)
      {
         str << ws << "   <int64>" << __CanceledTasks[i] << "</int64>\n";
      }
      str << ws << "   </CanceledTasks>\n";
      str << ws << "</CancelTask>\n";

      return str.str();
   }

   bool CancelTask::operator==(const CancelTask & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__Vehicles.size() != that.__Vehicles.size()) return false;
      for (size_t i=0; i<__Vehicles.size(); i++)
      {
         if(__Vehicles[i] != that.__Vehicles[i]) return false;
      }
      if(__CanceledTasks.size() != that.__CanceledTasks.size()) return false;
      for (size_t i=0; i<__CanceledTasks.size(); i++)
      {
         if(__CanceledTasks[i] != that.__CanceledTasks[i]) return false;
      }
      return true;

   }

   bool CancelTask::operator!=(const CancelTask & that)
   {
      return( !(operator==(that)) );
   }




} // end namespace task
} // end namespace messages
} // end namespace uxas

