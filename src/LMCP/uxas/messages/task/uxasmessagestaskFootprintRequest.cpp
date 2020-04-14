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
#include "uxas/messages/task/FootprintRequest.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string FootprintRequest::Subscription = "uxas.messages.task.FootprintRequest";
   const std::string FootprintRequest::TypeName = "FootprintRequest";
   const std::string FootprintRequest::SeriesName = "UXTASK";
   const int64_t FootprintRequest::SeriesId = 6149757930721443840LL;
   const uint16_t FootprintRequest::SeriesVersion = 8;
   const uint32_t FootprintRequest::TypeId = 11;
   
   bool isFootprintRequest(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   bool isFootprintRequest(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 11) return false;
      return true;
   }
   
   std::vector< std::string > FootprintRequestDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   FootprintRequest::FootprintRequest(void) : avtas::lmcp::Object()
   {
      __FootprintRequestID = 0LL;
      __VehicleID = 0LL;

   }
     
   FootprintRequest::FootprintRequest(const FootprintRequest &that) : avtas::lmcp::Object(that)
   {
        __FootprintRequestID = that.__FootprintRequestID;
        __VehicleID = that.__VehicleID;
        __EligibleWavelengths.clear();
        for (size_t i=0; i< that.__EligibleWavelengths.size(); i++)
        {
           __EligibleWavelengths.push_back( that.__EligibleWavelengths[i]);
        }
        __GroundSampleDistances.clear();
        for (size_t i=0; i< that.__GroundSampleDistances.size(); i++)
        {
           __GroundSampleDistances.push_back( that.__GroundSampleDistances[i]);
        }
        __AglAltitudes.clear();
        for (size_t i=0; i< that.__AglAltitudes.size(); i++)
        {
           __AglAltitudes.push_back( that.__AglAltitudes[i]);
        }
        __ElevationAngles.clear();
        for (size_t i=0; i< that.__ElevationAngles.size(); i++)
        {
           __ElevationAngles.push_back( that.__ElevationAngles[i]);
        }

   }
   
   FootprintRequest & FootprintRequest::operator=(const FootprintRequest &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);

         __FootprintRequestID = that.__FootprintRequestID;
         __VehicleID = that.__VehicleID;
         __EligibleWavelengths.clear();
         for (size_t i=0; i< that.__EligibleWavelengths.size(); i++)
         {
            __EligibleWavelengths.push_back( that.__EligibleWavelengths[i]);
         }
         __GroundSampleDistances.clear();
         for (size_t i=0; i< that.__GroundSampleDistances.size(); i++)
         {
            __GroundSampleDistances.push_back( that.__GroundSampleDistances[i]);
         }
         __AglAltitudes.clear();
         for (size_t i=0; i< that.__AglAltitudes.size(); i++)
         {
            __AglAltitudes.push_back( that.__AglAltitudes[i]);
         }
         __ElevationAngles.clear();
         for (size_t i=0; i< that.__ElevationAngles.size(); i++)
         {
            __ElevationAngles.push_back( that.__ElevationAngles[i]);
         }

      }
      return *this;
   }

   FootprintRequest* FootprintRequest::clone() const
   {
        return new FootprintRequest(*this);
   }
   
   FootprintRequest::~FootprintRequest(void)
   {

   }
  
   void FootprintRequest::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__FootprintRequestID);
      buf.putLong(__VehicleID);
      buf.putUShort( static_cast<uint16_t>(__EligibleWavelengths.size()));
      for (size_t i=0; i<__EligibleWavelengths.size(); i++)
      {
         buf.putInt( (int32_t) __EligibleWavelengths[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__GroundSampleDistances.size()));
      for (size_t i=0; i<__GroundSampleDistances.size(); i++)
      {
         buf.putFloat(__GroundSampleDistances[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__AglAltitudes.size()));
      for (size_t i=0; i<__AglAltitudes.size(); i++)
      {
         buf.putFloat(__AglAltitudes[i]);
      }
      buf.putUShort( static_cast<uint16_t>(__ElevationAngles.size()));
      for (size_t i=0; i<__ElevationAngles.size(); i++)
      {
         buf.putFloat(__ElevationAngles[i]);
      }

   }
   
   void FootprintRequest::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __FootprintRequestID = buf.getLong();
      __VehicleID = buf.getLong();
      __EligibleWavelengths.clear();
      uint16_t __EligibleWavelengths_length = buf.getUShort();
      for (uint32_t i=0; i< __EligibleWavelengths_length; i++)
      {
         __EligibleWavelengths.push_back( (afrl::cmasi::WavelengthBand::WavelengthBand) buf.getInt() );
      }
      __GroundSampleDistances.clear();
      uint16_t __GroundSampleDistances_length = buf.getUShort();
      for (uint32_t i=0; i< __GroundSampleDistances_length; i++)
      {
         __GroundSampleDistances.push_back(buf.getFloat() );
      }
      __AglAltitudes.clear();
      uint16_t __AglAltitudes_length = buf.getUShort();
      for (uint32_t i=0; i< __AglAltitudes_length; i++)
      {
         __AglAltitudes.push_back(buf.getFloat() );
      }
      __ElevationAngles.clear();
      uint16_t __ElevationAngles_length = buf.getUShort();
      for (uint32_t i=0; i< __ElevationAngles_length; i++)
      {
         __ElevationAngles.push_back(buf.getFloat() );
      }

   }

   uint32_t FootprintRequest::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += sizeof(int64_t);
      size += 2 + sizeof(afrl::cmasi::WavelengthBand::WavelengthBand) * __EligibleWavelengths.size();
      size += 2 + sizeof(float) * __GroundSampleDistances.size();
      size += 2 + sizeof(float) * __AglAltitudes.size();
      size += 2 + sizeof(float) * __ElevationAngles.size();

      return size;
   }

   std::string FootprintRequest::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( FootprintRequest ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "FootprintRequestID (int64_t) = " << __FootprintRequestID << "\n";
      oss << indent << "VehicleID (int64_t) = " << __VehicleID << "\n";
      oss << indent << "EligibleWavelengths (WavelengthBand [ " << __EligibleWavelengths.size() << ", var ])\n";
      oss << indent << "GroundSampleDistances (real32 [ " << __GroundSampleDistances.size() << ", var ])\n";
      oss << indent << "AglAltitudes (real32 [ " << __AglAltitudes.size() << ", var ])\n";
      oss << indent << "ElevationAngles (real32 [ " << __ElevationAngles.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string FootprintRequest::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<FootprintRequest Series=\"UXTASK\">\n";
      str << ws << "   <FootprintRequestID>" << __FootprintRequestID << "</FootprintRequestID>\n";
      str << ws << "   <VehicleID>" << __VehicleID << "</VehicleID>\n";
      str << ws << "   <EligibleWavelengths>\n";
      for (size_t i=0; i<__EligibleWavelengths.size(); i++)
      {
         str << ws << "   <WavelengthBand>" << afrl::cmasi::WavelengthBand::get_string(__EligibleWavelengths[i]) << "</WavelengthBand>\n";
      }
      str << ws << "   </EligibleWavelengths>\n";
      str << ws << "   <GroundSampleDistances>\n";
      for (size_t i=0; i<__GroundSampleDistances.size(); i++)
      {
         str << ws << "   <real32>" << __GroundSampleDistances[i] << "</real32>\n";
      }
      str << ws << "   </GroundSampleDistances>\n";
      str << ws << "   <AglAltitudes>\n";
      for (size_t i=0; i<__AglAltitudes.size(); i++)
      {
         str << ws << "   <real32>" << __AglAltitudes[i] << "</real32>\n";
      }
      str << ws << "   </AglAltitudes>\n";
      str << ws << "   <ElevationAngles>\n";
      for (size_t i=0; i<__ElevationAngles.size(); i++)
      {
         str << ws << "   <real32>" << __ElevationAngles[i] << "</real32>\n";
      }
      str << ws << "   </ElevationAngles>\n";
      str << ws << "</FootprintRequest>\n";

      return str.str();
   }

   bool FootprintRequest::operator==(const FootprintRequest & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__FootprintRequestID != that.__FootprintRequestID) return false;
      if(__VehicleID != that.__VehicleID) return false;
      if(__EligibleWavelengths.size() != that.__EligibleWavelengths.size()) return false;
      for (size_t i=0; i<__EligibleWavelengths.size(); i++)
      {
         if(__EligibleWavelengths[i] != that.__EligibleWavelengths[i]) return false;
      }
      if(__GroundSampleDistances.size() != that.__GroundSampleDistances.size()) return false;
      for (size_t i=0; i<__GroundSampleDistances.size(); i++)
      {
         if(__GroundSampleDistances[i] != that.__GroundSampleDistances[i]) return false;
      }
      if(__AglAltitudes.size() != that.__AglAltitudes.size()) return false;
      for (size_t i=0; i<__AglAltitudes.size(); i++)
      {
         if(__AglAltitudes[i] != that.__AglAltitudes[i]) return false;
      }
      if(__ElevationAngles.size() != that.__ElevationAngles.size()) return false;
      for (size_t i=0; i<__ElevationAngles.size(); i++)
      {
         if(__ElevationAngles[i] != that.__ElevationAngles[i]) return false;
      }
      return true;

   }

   bool FootprintRequest::operator!=(const FootprintRequest & that)
   {
      return( !(operator==(that)) );
   }

   FootprintRequest& FootprintRequest::setFootprintRequestID(const int64_t val)
   {
      __FootprintRequestID = val;
      return *this;
   }

   FootprintRequest& FootprintRequest::setVehicleID(const int64_t val)
   {
      __VehicleID = val;
      return *this;
   }






} // end namespace task
} // end namespace messages
} // end namespace uxas

