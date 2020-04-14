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
#include "afrl/impact/PowerPlantState.h"


namespace afrl {
namespace impact {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string PowerPlantState::Subscription = "afrl.impact.PowerPlantState";
   const std::string PowerPlantState::TypeName = "PowerPlantState";
   const std::string PowerPlantState::SeriesName = "IMPACT";
   const int64_t PowerPlantState::SeriesId = 5281966179208134656LL;
   const uint16_t PowerPlantState::SeriesVersion = 14;
   const uint32_t PowerPlantState::TypeId = 8;
   
   bool isPowerPlantState(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   bool isPowerPlantState(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 5281966179208134656LL) return false;
      if(obj->getSeriesVersion() != 14) return false;
      if(obj->getLmcpType() != 8) return false;
      return true;
   }
   
   std::vector< std::string > PowerPlantStateDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   PowerPlantState::PowerPlantState(void) : afrl::cmasi::PayloadState()
   {
      __ActivePowerPlant = afrl::impact::PowerPlant::Gasoline;

   }
     
   PowerPlantState::PowerPlantState(const PowerPlantState &that) : afrl::cmasi::PayloadState(that)
   {
        __ActivePowerPlant = that.__ActivePowerPlant;

   }
   
   PowerPlantState & PowerPlantState::operator=(const PowerPlantState &that)
   {
      if (this != &that)
      {
         afrl::cmasi::PayloadState::operator=(that);

         __ActivePowerPlant = that.__ActivePowerPlant;

      }
      return *this;
   }

   PowerPlantState* PowerPlantState::clone() const
   {
        return new PowerPlantState(*this);
   }
   
   PowerPlantState::~PowerPlantState(void)
   {

   }
  
   void PowerPlantState::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::PayloadState::pack(buf);
      // Copy the class into the buffer
      buf.putInt( (int32_t) __ActivePowerPlant);

   }
   
   void PowerPlantState::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::PayloadState::unpack(buf);
      // Copy the buffer into the class
      __ActivePowerPlant = (afrl::impact::PowerPlant::PowerPlant) buf.getInt();

   }

   uint32_t PowerPlantState::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::PayloadState::calculatePackedSize();
      size += sizeof(afrl::impact::PowerPlant::PowerPlant);

      return size;
   }

   std::string PowerPlantState::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( PowerPlantState ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "PayloadID (int64_t) = " << __PayloadID << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";

      oss << indent << "ActivePowerPlant (PowerPlant) = " << __ActivePowerPlant << "\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string PowerPlantState::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<PowerPlantState Series=\"IMPACT\">\n";
      str << ws << "   <ActivePowerPlant>" << afrl::impact::PowerPlant::get_string(__ActivePowerPlant) << "</ActivePowerPlant>\n";
      str << ws << "   <PayloadID>" << __PayloadID << "</PayloadID>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "</PowerPlantState>\n";

      return str.str();
   }

   bool PowerPlantState::operator==(const PowerPlantState & that)
   {
      if( afrl::cmasi::PayloadState::operator!=(that) )
      {
          return false;
      }
      if(__ActivePowerPlant != that.__ActivePowerPlant) return false;
      return true;

   }

   bool PowerPlantState::operator!=(const PowerPlantState & that)
   {
      return( !(operator==(that)) );
   }

   PowerPlantState& PowerPlantState::setActivePowerPlant(const afrl::impact::PowerPlant::PowerPlant val)
   {
      __ActivePowerPlant = val;
      return *this;
   }


} // end namespace impact
} // end namespace afrl

