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
#include "afrl/cmasi/NavigationAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string NavigationAction::Subscription = "afrl.cmasi.NavigationAction";
   const std::string NavigationAction::TypeName = "NavigationAction";
   const std::string NavigationAction::SeriesName = "CMASI";
   const int64_t NavigationAction::SeriesId = 4849604199710720000LL;
   const uint16_t NavigationAction::SeriesVersion = 3;
   const uint32_t NavigationAction::TypeId = 32;
   
   bool isNavigationAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 32) return false;
      return true;
   }
   
   bool isNavigationAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 32) return false;
      return true;
   }
   
   std::vector< std::string > NavigationActionDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.GoToWaypointAction");
       descendants.push_back("afrl.cmasi.LoiterAction");
       descendants.push_back("afrl.cmasi.FlightDirectorAction");

       return descendants;
   }
   
   NavigationAction::NavigationAction(void) : afrl::cmasi::VehicleAction()
   {

   }
     
   NavigationAction::NavigationAction(const NavigationAction &that) : afrl::cmasi::VehicleAction(that)
   {

   }
   
   NavigationAction & NavigationAction::operator=(const NavigationAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);


      }
      return *this;
   }

   NavigationAction* NavigationAction::clone() const
   {
        return new NavigationAction(*this);
   }
   
   NavigationAction::~NavigationAction(void)
   {

   }
  
   void NavigationAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer

   }
   
   void NavigationAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t NavigationAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();

      return size;
   }

   std::string NavigationAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( NavigationAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";


      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string NavigationAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<NavigationAction Series=\"CMASI\">\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</NavigationAction>\n";

      return str.str();
   }

   bool NavigationAction::operator==(const NavigationAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool NavigationAction::operator!=(const NavigationAction & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace cmasi
} // end namespace afrl

