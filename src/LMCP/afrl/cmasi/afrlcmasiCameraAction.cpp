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
#include "afrl/cmasi/CameraAction.h"


namespace afrl {
namespace cmasi {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string CameraAction::Subscription = "afrl.cmasi.CameraAction";
   const std::string CameraAction::TypeName = "CameraAction";
   const std::string CameraAction::SeriesName = "CMASI";
   const int64_t CameraAction::SeriesId = 4849604199710720000LL;
   const uint16_t CameraAction::SeriesVersion = 3;
   const uint32_t CameraAction::TypeId = 18;
   
   bool isCameraAction(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   bool isCameraAction(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 4849604199710720000LL) return false;
      if(obj->getSeriesVersion() != 3) return false;
      if(obj->getLmcpType() != 18) return false;
      return true;
   }
   
   std::vector< std::string > CameraActionDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   CameraAction::CameraAction(void) : afrl::cmasi::PayloadAction()
   {
      __HorizontalFieldOfView = 0.f;

   }
     
   CameraAction::CameraAction(const CameraAction &that) : afrl::cmasi::PayloadAction(that)
   {
        __HorizontalFieldOfView = that.__HorizontalFieldOfView;

   }
   
   CameraAction & CameraAction::operator=(const CameraAction &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadAction::operator=(that);

         __HorizontalFieldOfView = that.__HorizontalFieldOfView;

      }
      return *this;
   }

   CameraAction* CameraAction::clone() const
   {
        return new CameraAction(*this);
   }
   
   CameraAction::~CameraAction(void)
   {

   }
  
   void CameraAction::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadAction::pack(buf);
      // Copy the class into the buffer
      buf.putFloat(__HorizontalFieldOfView);

   }
   
   void CameraAction::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadAction::unpack(buf);
      // Copy the buffer into the class
      __HorizontalFieldOfView = buf.getFloat();

   }

   uint32_t CameraAction::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadAction::calculatePackedSize();
      size += sizeof(float);

      return size;
   }

   std::string CameraAction::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( CameraAction ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "AssociatedTaskList (int64 [ " << __AssociatedTaskList.size() << ", var ])\n";

      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";

      oss << indent << "HorizontalFieldOfView (float) = " << __HorizontalFieldOfView << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string CameraAction::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<CameraAction Series=\"CMASI\">\n";
      str << ws << "   <HorizontalFieldOfView>" << __HorizontalFieldOfView << "</HorizontalFieldOfView>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <AssociatedTaskList>\n";
      for (size_t i=0; i<__AssociatedTaskList.size(); i++)
      {
         str << ws << "   <int64>" << __AssociatedTaskList[i] << "</int64>\n";
      }
      str << ws << "   </AssociatedTaskList>\n";
      str << ws << "</CameraAction>\n";

      return str.str();
   }

   bool CameraAction::operator==(const CameraAction & that)
   {
      if( afrl::cmasi::PayloadAction::operator!=(that) )
      {
          return false;
      }
      if(__HorizontalFieldOfView != that.__HorizontalFieldOfView) return false;
      return true;

   }

   bool CameraAction::operator!=(const CameraAction & that)
   {
      return( !(operator==(that)) );
   }

   CameraAction& CameraAction::setHorizontalFieldOfView(const float val)
   {
      __HorizontalFieldOfView = val;
      return *this;
   }


} // end namespace cmasi
} // end namespace afrl

