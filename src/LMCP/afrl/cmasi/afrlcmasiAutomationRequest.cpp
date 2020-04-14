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
#include "afrl/cmasi/AutomationRequest.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AutomationRequest::Subscription = "afrl.cmasi.AutomationRequest";
   const std::string AutomationRequest::TypeName = "AutomationRequest";
   const std::string AutomationRequest::SeriesName = "CMASI";
   const int64_t AutomationRequest::SeriesId = 4849604199710720000LL;
   const uint16_t AutomationRequest::SeriesVersion = 3;
   const uint32_t AutomationRequest::TypeId = 40;
   
   bool isAutomationRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 40) return false;
      return true;
   }
   
   bool isAutomationRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 40) return false;
      return true;
   }
   
   std::vector< std::string > AutomationRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AutomationRequest::AutomationRequest(void) : avtas::lmcp::Object()
   {
      __TaskRelationships = std::string("");
      __OperatingRegion = 0LL;
      __RedoAllTasks = false;

   }
     
   AutomationRequest::AutomationRequest(const AutomationRequest &that) : avtas::lmcp::Object(that)
   {
        __EntityList.clear();
        for (size_t i=0; i< that.__EntityList.size(); i++)
        {
           __EntityList.push_back( that.__EntityList[i]);
        }
        __TaskList.clear();
        for (size_t i=0; i< that.__TaskList.size(); i++)
        {
           __TaskList.push_back( that.__TaskList[i]);
        }
        __TaskRelationships = that.__TaskRelationships;
        __OperatingRegion = that.__OperatingRegion;
        __RedoAllTasks = that.__RedoAllTasks;

   }
   
   AutomationRequest & AutomationRequest::operator=(const AutomationRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __EntityList.clear();
         for (size_t i=0; i< that.__EntityList.size(); i++)
         {
            __EntityList.push_back( that.__EntityList[i]);
         }
         __TaskList.clear();
         for (size_t i=0; i< that.__TaskList.size(); i++)
         {
            __TaskList.push_back( that.__TaskList[i]);
         }
         __TaskRelationships = that.__TaskRelationships;
         __OperatingRegion = that.__OperatingRegion;
         __RedoAllTasks = that.__RedoAllTasks;

      }
      return *this;
   }

   AutomationRequest* AutomationRequest::clone() const
   {
        return new AutomationRequest(*this);
   }
   
   AutomationRequest::~AutomationRequest(void)
   {

   }
  
   void AutomationRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putUShort( static_cast<uint16_t>(__EntityList.size()));
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         buf.putLong(__EntityList[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__TaskList.size()));
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         buf.putLong(__TaskList[i]);
      }
      buf.putString(__TaskRelationships);
      buf.putLong(__OperatingRegion);
      buf.putBool(__RedoAllTasks);

   }
   
   void AutomationRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __EntityList.clear();
      uint16_t __EntityList_length = buf.getUShort();
      for (uint32_t i=0; i< __EntityList_length; i++)
      {
         __EntityList.push_back(buf.getLong() );
      }
      __TaskList.clear();
      uint16_t __TaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskList_length; i++)
      {
         __TaskList.push_back(buf.getLong() );
      }
      __TaskRelationships = buf.getString();
      __OperatingRegion = buf.getLong();
      __RedoAllTasks = buf.getBool();

   }

   uint32_t AutomationRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += 2 + sizeof(int64_t) * __EntityList.size();
      size += 2 + sizeof(int64_t) * __TaskList.size();
      size += 2 + __TaskRelationships.length();
      size += sizeof(int64_t);
      size += sizeof(bool);

      return size;
   }

   std::string AutomationRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AutomationRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "EntityList (int64 [ " << __EntityList.size() << ", var ])\n";
      oss << indent << "TaskList (int64 [ " << __TaskList.size() << ", var ])\n";
      oss << indent << "TaskRelationships (std::string) = " << __TaskRelationships << "\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "RedoAllTasks (bool) = " << __RedoAllTasks << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AutomationRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AutomationRequest Series=\"CMASI\">\n";
      str << ws << "   <EntityList>\n";
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         str << ws << "   <int64>" << __EntityList[i] << "</int64>\n";
      }
      str << ws << "   </EntityList>\n";
      str << ws << "   <TaskList>\n";
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         str << ws << "   <int64>" << __TaskList[i] << "</int64>\n";
      }
      str << ws << "   </TaskList>\n";
      str << ws << "   <TaskRelationships>" << __TaskRelationships << "</TaskRelationships>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <RedoAllTasks>" << (__RedoAllTasks ? "true" : "false") << "</RedoAllTasks>\n";
      str << ws << "</AutomationRequest>\n";

      return str.str();
   }

   bool AutomationRequest::operator==(const AutomationRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__EntityList.size() != that.__EntityList.size()) return false;
      for (size_t i=0; i<__EntityList.size(); i++)
      {
         if(__EntityList[i] != that.__EntityList[i]) return false;
      }
      if(__TaskList.size() != that.__TaskList.size()) return false;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if(__TaskList[i] != that.__TaskList[i]) return false;
      }
      if(__TaskRelationships != that.__TaskRelationships) return false;
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__RedoAllTasks != that.__RedoAllTasks) return false;
      return true;

   }

   bool AutomationRequest::operator!=(const AutomationRequest & that)
   {
      return( !(operator==(that)) );
   }



   AutomationRequest& AutomationRequest::setTaskRelationships(const std::string val)
   {
      __TaskRelationships = val;
      return *this;
   }

   AutomationRequest& AutomationRequest::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }

   AutomationRequest& AutomationRequest::setRedoAllTasks(const bool val)
   {
      __RedoAllTasks = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

