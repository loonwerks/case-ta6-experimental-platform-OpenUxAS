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
#include "afrl/cmasi/GoToWaypointAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string GoToWaypointAction::Subscription = "afrl.cmasi.GoToWaypointAction";
   const std::string GoToWaypointAction::TypeName = "GoToWaypointAction";
   const std::string GoToWaypointAction::SeriesName = "CMASI";
   const int64_t GoToWaypointAction::SeriesId = 4849604199710720000LL;
   const uint16_t GoToWaypointAction::SeriesVersion = 3;
   const uint32_t GoToWaypointAction::TypeId = 28;
   
   bool isGoToWaypointAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   bool isGoToWaypointAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 28) return false;
      return true;
   }
   
   std::vector< std::string > GoToWaypointActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   GoToWaypointAction::GoToWaypointAction(void) : afrl::cmasi::NavigationAction()
   {
      __WaypointNumber = 0LL;

   }
     
   GoToWaypointAction::GoToWaypointAction(const GoToWaypointAction &that) : afrl::cmasi::NavigationAction(that)
   {
        __WaypointNumber = that.__WaypointNumber;

   }
   
   GoToWaypointAction & GoToWaypointAction::operator=(const GoToWaypointAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::NavigationAction::operator=(that);

         __WaypointNumber = that.__WaypointNumber;

      }
      return *this;
   }

   GoToWaypointAction* GoToWaypointAction::clone() const
   {
        return new GoToWaypointAction(*this);
   }
   
   GoToWaypointAction::~GoToWaypointAction(void)
   {

   }
  
   void GoToWaypointAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::NavigationAction::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__WaypointNumber);

   }
   
   void GoToWaypointAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::NavigationAction::unpack(buf);
      // Copy the buffer into the class
      __WaypointNumber = buf.getLong();

   }

   uint32_t GoToWaypointAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::NavigationAction::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string GoToWaypointAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( GoToWaypointAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";


      oss << indent << "WaypointNumber (int64_t) = " << __WaypointNumber << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string GoToWaypointAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<GoToWaypointAction Series=\"CMASI\">\n";
      str << ws << "   <WaypointNumber>" << __WaypointNumber << "</WaypointNumber>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</GoToWaypointAction>\n";

      return str.str();
   }

   bool GoToWaypointAction::operator==(const GoToWaypointAction & that)
   {
      if( afrl::cmasi::NavigationAction::operator!=(that) )
      {
          return false;
      }
      if(__WaypointNumber != that.__WaypointNumber) return false;
      return true;

   }

   bool GoToWaypointAction::operator!=(const GoToWaypointAction & that)
   {
      return( !(operator==(that)) );
   }

   GoToWaypointAction& GoToWaypointAction::setWaypointNumber(const int64_t val)
   {
      __WaypointNumber = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

