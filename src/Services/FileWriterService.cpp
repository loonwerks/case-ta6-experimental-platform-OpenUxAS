/**************************************************************************
  Copyright (c) 2018 Rockwell Collins. Developed with the sponsorship
  of the Defense Advanced Research Projects Agency (DARPA).

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this data, including any software or models
  in source or binary form, as well as any drawings,
  specifications, and documentation (collectively "the Data"), to
  deal in the Data without restriction, including without
  limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Data, and to
  permit persons to whom the Data is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Data.

  THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, SPONSORS,
  DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
  DATA.
 **************************************************************************/

/* 
 * File:   FileWriterService.cpp
 * Author: Kyle Peters
 *
 * Created on October 05, 2018, 2:35 PM
 *
 * <Service Type="FileWriterService" OptionString="Option_01" OptionInt="36" />
 * 
 */

#include <iostream>
#include <fstream>

// include header for this service
#include "FileWriterService.h"

//include for KeyValuePair LMCP Message
#include "afrl/cmasi/KeyValuePair.h"
#include "afrl/cmasi/AirVehicleState.h"

#include "UxAS_TimerManager.h"

#include <iostream>     // std::cout, cerr, etc

// convenience definitions for the option strings
#define STRING_XML_FILE_NAME "FileName"
#define STRING_XML_FILE_EXT "FileExtension"
#define STRING_XML_WRITE_PERIOD "Period"
#define STRING_XML_HISTORY "HistoryTracking"

// namespace definitions
namespace uxas  // uxas::
{
namespace service   // uxas::service::
{

// this entry registers the service in the service creation registry
FileWriterService::ServiceBase::CreationRegistrar<FileWriterService>
FileWriterService::s_registrar(FileWriterService::s_registryServiceTypeNames());

// service constructor
FileWriterService::FileWriterService()
: ServiceBase(FileWriterService::s_typeName(), FileWriterService::s_directoryName()) { };

// service destructor
FileWriterService::~FileWriterService() { };


bool FileWriterService::configure(const pugi::xml_node& ndComponent)
{
    bool isSuccess(true);

    // process options from the XML configuration node:
    if (!ndComponent.attribute(STRING_XML_FILE_NAME).empty())
    {
        m_filenamePrefix = ndComponent.attribute(STRING_XML_FILE_NAME).as_string();
    }
    // process options from the XML configuration node:
    if (!ndComponent.attribute(STRING_XML_FILE_EXT).empty())
    {
        m_fileExtension = ndComponent.attribute(STRING_XML_FILE_EXT).as_string();
    }
    if (!ndComponent.attribute(STRING_XML_WRITE_PERIOD).empty())
    {
        m_fileWritePeriod_ms = static_cast<uint64_t>(ndComponent.attribute(STRING_XML_WRITE_PERIOD).as_int64());
    }
    if (!ndComponent.attribute(STRING_XML_HISTORY).empty())
    {
        m_trackHistoricalData = ndComponent.attribute(STRING_XML_HISTORY).as_bool();
    }

    // subscribe to AirVehicleState (as the data to be written)
    addSubscriptionAddress(afrl::cmasi::AirVehicleState::Subscription);

    return (isSuccess);
}

bool FileWriterService::initialize()
{
    // create timer for writing file
    m_writeTimerId = uxas::common::TimerManager::getInstance().createTimer(
        std::bind(&FileWriterService::OnWriteTime, this),
        "FileWriterService::OnWriteTime()");
    
    return (true);
}

bool FileWriterService::start()
{
    // Kick off the periodic timer for writing data to the file
    uxas::common::TimerManager::getInstance().startPeriodicTimer(m_writeTimerId,0,m_fileWritePeriod_ms);
    
    return (true);
};

void FileWriterService::OnWriteTime()
{
    std::ofstream outputFile;
    std::ios::openmode writeMode = std::ios::app;
    std::string filename;
    
    //If not tracking historical, change write mode to overwrite with each write
    if(!m_trackHistoricalData){
        writeMode = std::ios::out;
    }
    
    for(size_t i = 0;i<vehicleIDs.size();i++)
    {
        //Open data file for this vehicle
        filename = (m_filenamePrefix + std::to_string(vehicleIDs.at(i)) + "." + m_fileExtension);
        outputFile.open(filename,writeMode);
        
        //Log Error on file open failure; otherwise write to file and close
        if(!outputFile.is_open())
        {
            UXAS_LOG_WARN("FileWriterService: Unable to open ", filename, " for writing");
        }
        else
        {
            outputFile<< writeData.at(i);
            outputFile.close();
        }
    } //end loop through all vehicles with data tracked
    
    //Clear out global data stores
    vehicleIDs.erase(vehicleIDs.begin(),vehicleIDs.end());
    writeData.erase(writeData.begin(),writeData.end());
}

bool FileWriterService::terminate()
{
    //Destroy the timer associated with this service
    uxas::common::TimerManager::getInstance().destroyTimer(m_writeTimerId,m_fileWritePeriod_ms);
    // perform any action required during service termination, before destructor is called.
    std::cout << "*** TERMINATING:: Service[" << s_typeName() << "] Service Id[" << m_serviceId << "] with working directory [" << m_workDirectoryName << "] *** " << std::endl;
    
    return (true);
}

bool FileWriterService::processReceivedLmcpMessage(std::unique_ptr<uxas::communications::data::LmcpMessage> receivedLmcpMessage)
{
    if(afrl::cmasi::isAirVehicleState(receivedLmcpMessage->m_object.get())){
        auto airVehicleState = std::static_pointer_cast<afrl::cmasi::AirVehicleState>(receivedLmcpMessage->m_object);
        size_t vehicle_index = vehicleIDs.size();
        
        //If vehicle data already exists, track its location in the vector
        for(size_t i=0;vehicle_index==vehicleIDs.size() && i<vehicleIDs.size();i++)
        {
            if(vehicleIDs.at(i)==airVehicleState->getID())
            {
                vehicle_index = i;
            } // end If: Air Vehicle State is for this vehicle
       } // end loop through vehicles with currently tracked Air Vehicle State
       //If vehicle not found, add an element to the vectors for vehicle data
       if(vehicle_index == vehicleIDs.size())
       {
          vehicleIDs.push_back(airVehicleState->getID());
          writeData.push_back("");
       } // end If: No recorded air vehicle state for this vehicle
      writeData.at(vehicle_index) = airVehicleState->toString();
    } // end If: LMCP message is Air Vehicle State
    
    //Always FALSE unless terminating
    return false;
}

}; //namespace service
}; //namespace uxas
