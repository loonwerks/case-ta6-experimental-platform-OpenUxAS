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
#include "afrl/impact/RadioState.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string RadioState::Subscription = "afrl.impact.RadioState";
   const std::string RadioState::TypeName = "RadioState";
   const std::string RadioState::SeriesName = "IMPACT";
   const int64_t RadioState::SeriesId = 5281966179208134656LL;
   const uint16_t RadioState::SeriesVersion = 14;
   const uint32_t RadioState::TypeId = 4;
   
   bool isRadioState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   bool isRadioState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 4) return false;
      return true;
   }
   
   std::vector< std::string > RadioStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   RadioState::RadioState(void) : afrl::cmasi::PayloadState()
   {
      __Enabled = true;
      __InRange = false;

   }
     
   RadioState::RadioState(const RadioState &that) : afrl::cmasi::PayloadState(that)
   {
        __Enabled = that.__Enabled;
        __InRange = that.__InRange;

   }
   
   RadioState & RadioState::operator=(const RadioState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadState::operator=(that);

         __Enabled = that.__Enabled;
         __InRange = that.__InRange;

      }
      return *this;
   }

   RadioState* RadioState::clone() const
   {
        return new RadioState(*this);
   }
   
   RadioState::~RadioState(void)
   {

   }
  
   void RadioState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadState::pack(buf);
      // Copy the class into the buffer
      buf.putBool(__Enabled);
      buf.putBool(__InRange);

   }
   
   void RadioState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadState::unpack(buf);
      // Copy the buffer into the class
      __Enabled = buf.getBool();
      __InRange = buf.getBool();

   }

   uint32_t RadioState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadState::calculatePackedSize();
      size += sizeof(bool);
      size += sizeof(bool);

      return size;
   }

   std::string RadioState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( RadioState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "Enabled (bool) = " << __Enabled << "\n";
      oss << indent << "InRange (bool) = " << __InRange << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string RadioState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<RadioState Series=\"IMPACT\">\n";
      str << ws << "   <Enabled>" << (__Enabled ? "true" : "false") << "</Enabled>\n";
      str << ws << "   <InRange>" << (__InRange ? "true" : "false") << "</InRange>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</RadioState>\n";

      return str.str();
   }

   bool RadioState::operator==(const RadioState & that)
   {
      if( afrl::cmasi::PayloadState::operator!=(that) )
      {
          return false;
      }
      if(__Enabled != that.__Enabled) return false;
      if(__InRange != that.__InRange) return false;
      return true;

   }

   bool RadioState::operator!=(const RadioState & that)
   {
      return( !(operator==(that)) );
   }

   RadioState& RadioState::setEnabled(const bool val)
   {
      __Enabled = val;
      return *this;
   }

   RadioState& RadioState::setInRange(const bool val)
   {
      __InRange = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

