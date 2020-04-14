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
#include "afrl/cmasi/PayloadAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PayloadAction::Subscription = "afrl.cmasi.PayloadAction";
   const std::string PayloadAction::TypeName = "PayloadAction";
   const std::string PayloadAction::SeriesName = "CMASI";
   const int64_t PayloadAction::SeriesId = 4849604199710720000LL;
   const uint16_t PayloadAction::SeriesVersion = 3;
   const uint32_t PayloadAction::TypeId = 4;
   
   bool isPayloadAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   bool isPayloadAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   std::vector< std::string > PayloadActionDescendants()
   {
       std::vector< std::string > descendants;
       
       descendants.push_back("afrl.cmasi.CameraAction");
       descendants.push_back("afrl.cmasi.GimbalAngleAction");
       descendants.push_back("afrl.cmasi.GimbalScanAction");
       descendants.push_back("afrl.cmasi.GimbalStareAction");

       return descendants;
   }
   
   PayloadAction::PayloadAction(void) : afrl::cmasi::VehicleAction()
   {
      __PayloadID = 0LL;

   }
     
   PayloadAction::PayloadAction(const PayloadAction &that) : afrl::cmasi::VehicleAction(that)
   {
        __PayloadID = that.__PayloadID;

   }
   
   PayloadAction & PayloadAction::operator=(const PayloadAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::VehicleAction::operator=(that);

         __PayloadID = that.__PayloadID;

      }
      return *this;
   }

   PayloadAction* PayloadAction::clone() const
   {
        return new PayloadAction(*this);
   }
   
   PayloadAction::~PayloadAction(void)
   {

   }
  
   void PayloadAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::VehicleAction::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__PayloadID);

   }
   
   void PayloadAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::VehicleAction::unpack(buf);
      // Copy the buffer into the class
      __PayloadID = buf.getLong();

   }

   uint32_t PayloadAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::VehicleAction::calculatePackedSize();
      size += sizeof(int64_t);

      return size;
   }

   std::string PayloadAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PayloadAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PayloadAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PayloadAction Series=\"CMASI\">\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</PayloadAction>\n";

      return str.str();
   }

   bool PayloadAction::operator==(const PayloadAction & that)
   {
      if( afrl::cmasi::VehicleAction::operator!=(that) )
      {
          return false;
      }
      if(__PayloadID != that.__PayloadID) return false;
      return true;

   }

   bool PayloadAction::operator!=(const PayloadAction & that)
   {
      return( !(operator==(that)) );
   }

   PayloadAction& PayloadAction::setPayloadID(const int64_t val)
   {
      __PayloadID = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

