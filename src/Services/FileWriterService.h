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
 * File:   FileWriterService.h
 * Author: steve
 *
 * Created on March 17, 2017, 5:55 PM
 */

#ifndef FILE_WRITER_SERVICE_H
#define FILE_WRITER_SERVICE_H



#include "ServiceBase.h"
#include "CallbackTimer.h"
#include "TypeDefs/UxAS_TypeDefs_Timer.h"

namespace uxas
{
namespace service
{

/*! \class FileWriterService
    \brief This is a basic service that can be used as a template when 
 * constructing new services.

 * 
 * 
 *  @par To add a new service:
 * <ul style="padding-left:1em;margin-left:0">
 * <li>Make copies of the source and header files of this template.</li>
 * <li>Search for the string FileWriterService and Replace it with the new 
 * service name.</li>
 * <li>Change the unique include guard entries, in the header file, i.e. 
 * "UXAS_00_SERVICE_TEMPLATE_H" to match the new service name</li>
 * <li> include the new service header file in ServiceManager.cpp</li>
 * <li> add a dummy instance of the new service in ServiceManager.cpp, e.g.
 * {auto svc = uxas::stduxas::make_unique<uxas::service::MyNewService>();} 
 * Note: this is required to link the new service in when building UxAS</li>
 *  
 * </ul> @n
 * 
 * Configuration String: <Service Type="FileWriterService" OptionString="Option_01" OptionInt="36" />
 * 
 * Options:
 *  - OptionString - sample string option
 *  - OptionInt - sample integer option
 * 
 * Subscribed Messages:
 *  - afrl::cmasi::KeyValuePair
 * 
 * Sent Messages:
 *  - afrl::cmasi::KeyValuePair
 * 
 * 
 */

class FileWriterService : public ServiceBase
{
public:

    /** \brief This string is used to identify this service in XML configuration
     * files, i.e. Service Type="FileWriterService". It is also entered into
     * service registry and used to create new instances of this service. */
    static const std::string&
    s_typeName()
    {
        static std::string s_string("FileWriterService");
        return (s_string);
    };

    static const std::vector<std::string>
    s_registryServiceTypeNames()
    {
        std::vector<std::string> registryServiceTypeNames = {s_typeName()};
        return (registryServiceTypeNames);
    };

    /** \brief If this string is not empty, it is used to create a data 
     * directory to be used by the service. The path to this directory is
     * accessed through the ServiceBase variable m_workDirectoryPath. */
    static const std::string&
    s_directoryName() { static std::string s_string(""); return (s_string); };

    static ServiceBase*
    create()
    {
        return new FileWriterService;
    };

    FileWriterService();

    virtual
    ~FileWriterService();

private:

    static
    ServiceBase::CreationRegistrar<FileWriterService> s_registrar;

    /** brief Copy construction not permitted */
    FileWriterService(FileWriterService const&) = delete;

    /** brief Copy assignment operation not permitted */
    void operator=(FileWriterService const&) = delete;

    bool
    configure(const pugi::xml_node& serviceXmlNode) override;

    bool
    initialize() override;

    bool
    start() override;

    bool
    terminate() override;

    bool
    processReceivedLmcpMessage(std::unique_ptr<uxas::communications::data::LmcpMessage> receivedLmcpMessage) override;
    
    ////////////////////////
    // TIMER CALLBACKS
    /*! \brief this function gets called when the response timer expires */
    void OnWriteTime();
    
    /*! \brief  this timer is used to track time for the system to respond to automation requests */
    uint64_t m_writeTimerId{0};
    
    //Data storage
    std::vector<std::string> writeData;
    std::vector<int64_t> vehicleIDs;

private:
    // storage for the option entries
    // Name of the file base to write
    std::string m_filenamePrefix = std::string("Vehicle-");
    std::string m_fileExtension = std::string("txt");
    // Period (in ms) to write file
    uint64_t m_fileWritePeriod_ms = 10000U;
    //Most recent data only
    bool m_trackHistoricalData = false;
};

}; //namespace service
}; //namespace uxas

#endif /* UXAS_00_SERVICE_TEMPLATE_H */

