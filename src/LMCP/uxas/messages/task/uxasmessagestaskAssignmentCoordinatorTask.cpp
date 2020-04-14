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
#include "uxas/messages/task/AssignmentCoordinatorTask.h"


namespace uxas {
namespace messages {
namespace task {


   // Subscription string is namespace separated by '.' followed by type name
   const std::string AssignmentCoordinatorTask::Subscription = "uxas.messages.task.AssignmentCoordinatorTask";
   const std::string AssignmentCoordinatorTask::TypeName = "AssignmentCoordinatorTask";
   const std::string AssignmentCoordinatorTask::SeriesName = "UXTASK";
   const int64_t AssignmentCoordinatorTask::SeriesId = 6149757930721443840LL;
   const uint16_t AssignmentCoordinatorTask::SeriesVersion = 8;
   const uint32_t AssignmentCoordinatorTask::TypeId = 1;
   
   bool isAssignmentCoordinatorTask(avtas::lmcp::Object* obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   bool isAssignmentCoordinatorTask(std::shared_ptr<avtas::lmcp::Object>& obj)
   {
      if(!obj) return false;
      if(obj->getSeriesNameAsLong() != 6149757930721443840LL) return false;
      if(obj->getSeriesVersion() != 8) return false;
      if(obj->getLmcpType() != 1) return false;
      return true;
   }
   
   std::vector< std::string > AssignmentCoordinatorTaskDescendants()
   {
       std::vector< std::string > descendants;
       

       return descendants;
   }
   
   AssignmentCoordinatorTask::AssignmentCoordinatorTask(void) : afrl::cmasi::Task()
   {

   }
     
   AssignmentCoordinatorTask::AssignmentCoordinatorTask(const AssignmentCoordinatorTask &that) : afrl::cmasi::Task(that)
   {

   }
   
   AssignmentCoordinatorTask & AssignmentCoordinatorTask::operator=(const AssignmentCoordinatorTask &that)
   {
      if (this != &that)
      {
         afrl::cmasi::Task::operator=(that);


      }
      return *this;
   }

   AssignmentCoordinatorTask* AssignmentCoordinatorTask::clone() const
   {
        return new AssignmentCoordinatorTask(*this);
   }
   
   AssignmentCoordinatorTask::~AssignmentCoordinatorTask(void)
   {

   }
  
   void AssignmentCoordinatorTask::pack(avtas::lmcp::ByteBuffer & buf) const
   {
      // Call parent's pack method
      afrl::cmasi::Task::pack(buf);
      // Copy the class into the buffer

   }
   
   void AssignmentCoordinatorTask::unpack(avtas::lmcp::ByteBuffer & buf)
   {
      // Call parent's unpack method
      afrl::cmasi::Task::unpack(buf);
      // Copy the buffer into the class

   }

   uint32_t AssignmentCoordinatorTask::calculatePackedSize(void) const
   {
      uint32_t size = 0;
      size += afrl::cmasi::Task::calculatePackedSize();

      return size;
   }

   std::string AssignmentCoordinatorTask::toString(int32_t depth) const
   {
      std::string indent(depth*3, ' ');
      std::ostringstream oss;
      oss << std::setprecision(15);
      oss << indent << "Object ( AssignmentCoordinatorTask ) {\n";
      indent = std::string((++depth)*3, ' ');
      oss << indent << "TaskID (int64_t) = " << __TaskID << "\n";
      oss << indent << "Label (std::string) = " << __Label << "\n";
      oss << indent << "EligibleEntities (int64 [ " << __EligibleEntities.size() << ", var ])\n";
      oss << indent << "RevisitRate (float) = " << __RevisitRate << "\n";
      oss << indent << "Parameters (KeyValuePair [ " << __Parameters.size() << ", var ])\n";
      oss << indent << "Priority (uint8_t) = " << __Priority << "\n";
      oss << indent << "Required (bool) = " << __Required << "\n";


      indent = std::string((--depth)*3, ' ');
      oss << indent << "}\n";
      return oss.str();
   }

   std::string AssignmentCoordinatorTask::toXML(int32_t depth)
   {
      std::string ws(depth*3, ' ');
      std::ostringstream str;
      str << std::setprecision(15);
      str << ws << "<AssignmentCoordinatorTask Series=\"UXTASK\">\n";
      str << ws << "   <TaskID>" << __TaskID << "</TaskID>\n";
      str << ws << "   <Label>" << __Label << "</Label>\n";
      str << ws << "   <EligibleEntities>\n";
      for (size_t i=0; i<__EligibleEntities.size(); i++)
      {
         str << ws << "   <int64>" << __EligibleEntities[i] << "</int64>\n";
      }
      str << ws << "   </EligibleEntities>\n";
      str << ws << "   <RevisitRate>" << __RevisitRate << "</RevisitRate>\n";
      str << ws << "   <Parameters>\n";
      for (size_t i=0; i<__Parameters.size(); i++)
      {
         str << (__Parameters[i] == nullptr ? ( ws + "   <null/>\n") : (__Parameters[i]->toXML(depth + 1))) ;
      }
      str << ws << "   </Parameters>\n";
      str << ws << "   <Priority>" << (int32_t) __Priority << "</Priority>\n";
      str << ws << "   <Required>" << (__Required ? "true" : "false") << "</Required>\n";
      str << ws << "</AssignmentCoordinatorTask>\n";

      return str.str();
   }

   bool AssignmentCoordinatorTask::operator==(const AssignmentCoordinatorTask & that)
   {
      if( afrl::cmasi::Task::operator!=(that) )
      {
          return false;
      }
      return true;

   }

   bool AssignmentCoordinatorTask::operator!=(const AssignmentCoordinatorTask & that)
   {
      return( !(operator==(that)) );
   }


} // end namespace task
} // end namespace messages
} // end namespace uxas

