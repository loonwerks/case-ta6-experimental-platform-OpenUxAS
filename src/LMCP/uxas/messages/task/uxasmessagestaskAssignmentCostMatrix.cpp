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
#include "uxas/messages/task/AssignmentCostMatrix.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AssignmentCostMatrix::Subscription = "uxas.messages.task.AssignmentCostMatrix";
   const std::string AssignmentCostMatrix::TypeName = "AssignmentCostMatrix";
   const std::string AssignmentCostMatrix::SeriesName = "UXTASK";
   const int64_t AssignmentCostMatrix::SeriesId = 6149757930721443840LL;
   const uint16_t AssignmentCostMatrix::SeriesVersion = 8;
   const uint32_t AssignmentCostMatrix::TypeId = 16;
   
   bool isAssignmentCostMatrix(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   bool isAssignmentCostMatrix(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 16) return false;
      return true;
   }
   
   std::vector< std::string > AssignmentCostMatrixDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AssignmentCostMatrix::AssignmentCostMatrix(void) : avtas::lmcp::Object()
   {
      __CorrespondingAutomationRequestID = 0LL;
      __TaskLevelRelationship = std::string("");
      __OperatingRegion = 0LL;

   }
     
   AssignmentCostMatrix::AssignmentCostMatrix(const AssignmentCostMatrix &that) : avtas::lmcp::Object(that)
   {
        __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
        __TaskLevelRelationship = that.__TaskLevelRelationship;
        __TaskList.clear();
        for (size_t i=0; i< that.__TaskList.size(); i++)
        {
           __TaskList.push_back( that.__TaskList[i]);
        }
        __OperatingRegion = that.__OperatingRegion;
        __CostMatrix.clear();
        for (size_t i=0; i< that.__CostMatrix.size(); i++)
        {
           __CostMatrix.push_back( that.__CostMatrix[i] == nullptr ? nullptr : that.__CostMatrix[i]->clone());
        }

   }
   
   AssignmentCostMatrix & AssignmentCostMatrix::operator=(const AssignmentCostMatrix &that)
   {
      if (this != &that)
      {
         avtas::lmcp::Object::operator=(that);
         for (size_t i=0; i<__CostMatrix.size(); i++)
         {
            if (__CostMatrix[i] != nullptr) delete __CostMatrix[i];
         }

         __CorrespondingAutomationRequestID = that.__CorrespondingAutomationRequestID;
         __TaskLevelRelationship = that.__TaskLevelRelationship;
         __TaskList.clear();
         for (size_t i=0; i< that.__TaskList.size(); i++)
         {
            __TaskList.push_back( that.__TaskList[i]);
         }
         __OperatingRegion = that.__OperatingRegion;
         __CostMatrix.clear();
         for (size_t i=0; i< that.__CostMatrix.size(); i++)
         {
            __CostMatrix.push_back( that.__CostMatrix[i] == nullptr ? nullptr : that.__CostMatrix[i]->clone());
         }

      }
      return *this;
   }

   AssignmentCostMatrix* AssignmentCostMatrix::clone() const
   {
        return new AssignmentCostMatrix(*this);
   }
   
   AssignmentCostMatrix::~AssignmentCostMatrix(void)
   {
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         if (__CostMatrix[i] != nullptr) delete __CostMatrix[i];
      }

   }
  
   void AssignmentCostMatrix::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      avtas::lmcp::Object::pack(buf);
      // Copy the class into the buffer
      buf.putLong(__CorrespondingAutomationRequestID);
      buf.putString(__TaskLevelRelationship);
      buf.putUShort( static_cast<uint16_t>(__TaskList.size()));
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         buf.putLong(__TaskList[i]);
      }
      buf.putLong(__OperatingRegion);
      buf.putUShort( static_cast<uint16_t>(__CostMatrix.size()));
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         assert(__CostMatrix[i] != nullptr);
         avtas::lmcp::Factory::putObject( (avtas::lmcp::Object*) __CostMatrix[i], buf);
      }

   }
   
   void AssignmentCostMatrix::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      avtas::lmcp::Object::unpack(buf);
      // Copy the buffer into the class
      __CorrespondingAutomationRequestID = buf.getLong();
      __TaskLevelRelationship = buf.getString();
      __TaskList.clear();
      uint16_t __TaskList_length = buf.getUShort();
      for (uint32_t i=0; i< __TaskList_length; i++)
      {
         __TaskList.push_back(buf.getLong() );
      }
      __OperatingRegion = buf.getLong();
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         if (__CostMatrix[i] != nullptr)
            delete __CostMatrix[i];
      }
      __CostMatrix.clear();
      uint16_t __CostMatrix_length = buf.getUShort();
      for (uint32_t i=0; i< __CostMatrix_length; i++)
      {
         if (buf.getBool())
         {
            int64_t series_id = buf.getLong();
            uint32_t msgtype = buf.getUInt();
            uint16_t version = buf.getUShort();
            uxas::messages::task::TaskOptionCost* e = (uxas::messages::task::TaskOptionCost*) avtas::lmcp::Factory::createObject( series_id, msgtype, version );
            if ( e != nullptr) e->unpack(buf); 
            else assert( e != nullptr); 
            __CostMatrix.push_back(e);
         }
      }

   }

   uint32_t AssignmentCostMatrix::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += avtas::lmcp::Object::calculatePackedSize();
      size += sizeof(int64_t);
      size += 2 + __TaskLevelRelationship.length();
      size += 2 + sizeof(int64_t) * __TaskList.size();
      size += sizeof(int64_t);
      size += 2;
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         if (__CostMatrix[i] != nullptr)
         {
            size += __CostMatrix[i]->calculatePackedSize() + 15;
         }
         else { size += 1; }
      }

      return size;
   }

   std::string AssignmentCostMatrix::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AssignmentCostMatrix ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "CorrespondingAutomationRequestID (int64_t) = " << __CorrespondingAutomationRequestID << "\n";
      oss << indent << "TaskLevelRelationship (std::string) = " << __TaskLevelRelationship << "\n";
      oss << indent << "TaskList (int64 [ " << __TaskList.size() << ", var ])\n";
      oss << indent << "OperatingRegion (int64_t) = " << __OperatingRegion << "\n";
      oss << indent << "CostMatrix (TaskOptionCost [ " << __CostMatrix.size() << ", var ])\n";

      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AssignmentCostMatrix::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AssignmentCostMatrix Series=\"UXTASK\">\n";
      str << ws << "   <CorrespondingAutomationRequestID>" << __CorrespondingAutomationRequestID << "</CorrespondingAutomationRequestID>\n";
      str << ws << "   <TaskLevelRelationship>" << __TaskLevelRelationship << "</TaskLevelRelationship>\n";
      str << ws << "   <TaskList>\n";
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         str << ws << "   <int64>" << __TaskList[i] << "</int64>\n";
      }
      str << ws << "   </TaskList>\n";
      str << ws << "   <OperatingRegion>" << __OperatingRegion << "</OperatingRegion>\n";
      str << ws << "   <CostMatrix>\n";
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         str << (__CostMatrix[i] == nullptr ? ( ws + "   <null/>\n") : (__CostMatrix[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </CostMatrix>\n";
      str << ws << "</AssignmentCostMatrix>\n";

      return str.str();
   }

   bool AssignmentCostMatrix::operator==(const AssignmentCostMatrix & that)
   {
      if( avtas::lmcp::Object::operator!=(that) )
      {
          return false;
      }
      if(__CorrespondingAutomationRequestID != that.__CorrespondingAutomationRequestID) return false;
      if(__TaskLevelRelationship != that.__TaskLevelRelationship) return false;
      if(__TaskList.size() != that.__TaskList.size()) return false;
      for (size_t i=0; i<__TaskList.size(); i++)
      {
         if(__TaskList[i] != that.__TaskList[i]) return false;
      }
      if(__OperatingRegion != that.__OperatingRegion) return false;
      if(__CostMatrix.size() != that.__CostMatrix.size()) return false;
      for (size_t i=0; i<__CostMatrix.size(); i++)
      {
         if(__CostMatrix[i] && that.__CostMatrix[i])
         {
            if(__CostMatrix[i]->getSeriesNameAsLong() != that.__CostMatrix[i]->getSeriesNameAsLong()) return false;
            if(__CostMatrix[i]->getSeriesVersion() != that.__CostMatrix[i]->getSeriesVersion()) return false;
            if(__CostMatrix[i]->getLmcpType() != that.__CostMatrix[i]->getLmcpType()) return false;
            if( *(__CostMatrix[i]) != *(that.__CostMatrix[i]) ) return false;
         }
         else if(__CostMatrix[i] != that.__CostMatrix[i]) return false;
      }
      return true;

   }

   bool AssignmentCostMatrix::operator!=(const AssignmentCostMatrix & that)
   {
      return( !(operator==(that)) );
   }

   AssignmentCostMatrix& AssignmentCostMatrix::setCorrespondingAutomationRequestID(const int64_t val)
   {
      __CorrespondingAutomationRequestID = val;
      return *this;
   }

   AssignmentCostMatrix& AssignmentCostMatrix::setTaskLevelRelationship(const std::string val)
   {
      __TaskLevelRelationship = val;
      return *this;
   }


   AssignmentCostMatrix& AssignmentCostMatrix::setOperatingRegion(const int64_t val)
   {
      __OperatingRegion = val;
      return *this;
   }



} // end namespace task
} // end namespace messages
} // end namespace uxas

