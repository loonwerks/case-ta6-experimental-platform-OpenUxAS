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

#ifndef UXAS_ZEROIZECONDITIONRECOGNIZERSERVICE_H
#define UXAS_ZEROIZECONDITIONRECOGNIZERSERVICE_H

#include "ServiceBase.h"
#include "CallbackTimer.h"
#include "TypeDefs/UxAS_TypeDefs_Timer.h"

#include "afrl/cmasi/AbstractZone.h"
#include "afrl/cmasi/AirVehicleState.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/OperatingRegion.h"

namespace uxas
{
namespace service
{

/*! \class ZeroizeConditionRecognizerService
    \brief This is a basic service that can be used as a template when 
 * constructing new services.

 * 
 * 
 *  @par To add a new service:
 * <ul style="padding-left:1em;margin-left:0">
 * <li>Make copies of the source and header files of this template.</li>
 * <li>Search for the string ZeroizeConditionRecognizerService and Replace it with the new 
 * service name.</li>
 * <li>Change the unique include guard entries, in the header file, i.e. 
 * "UXAS_ZEROIZECONDITIONRECOGNIZERSERVICE_H" to match the new service name</li>
 * <li> include the new service header file in ServiceManager.cpp</li>
 * <li> add a dummy instance of the new service in ServiceManager.cpp, e.g.
 * {auto svc = uxas::stduxas::make_unique<uxas::service::MyNewService>();} 
 * Note: this is required to link the new service in when building UxAS</li>
 *  
 * </ul> @n
 * 
 * Configuration String: <Service Type="ZeroizeConditionRecognizerService" OptionString="Option_01" OptionInt="36" />
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

class ZeroizeConditionRecognizerService : public ServiceBase
{
public:

    /** \brief This string is used to identify this service in XML configuration
     * files, i.e. Service Type="ZeroizeConditionRecognizerService". It is also entered into
     * service registry and used to create new instances of this service. */
    static const std::string&
    s_typeName()
    {
        static std::string s_string("ZeroizeConditionRecognizerService");
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
        return new ZeroizeConditionRecognizerService;
    };

    ZeroizeConditionRecognizerService();

    virtual
    ~ZeroizeConditionRecognizerService();

private:

    static
    ServiceBase::CreationRegistrar<ZeroizeConditionRecognizerService> s_registrar;

    /** brief Copy construction not permitted */
    ZeroizeConditionRecognizerService(ZeroizeConditionRecognizerService const&) = delete;

    /** brief Copy assignment operation not permitted */
    void operator=(ZeroizeConditionRecognizerService const&) = delete;

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

private:
    // storage for the option entries
    int64_t m_vehicleID;
    bool m_zeroizeOnLanding;
    bool m_zeroizeOnExitingOperationalArea;
    bool m_zeroizeData;
    bool m_zeroizeKeys;
    bool m_zeroizeLogs;
    bool m_zeroizeTasks;
    int64_t m_activeOperationalArea;
    int64_t m_accumulationTime;
    int64_t m_holdoffTime;

    // state machine
    enum class State {Detect, Accumulate, Holdoff};
    State m_state;
    int64_t m_timeOfNextTransition;


    // local state
    std::unordered_map<int64_t, std::shared_ptr<afrl::cmasi::KeepInZone> > m_idVsKeepInZone;
    std::unordered_map<int64_t, std::shared_ptr<afrl::cmasi::KeepOutZone> > m_idVsKeepOutZone;
    std::unordered_map<int64_t, std::shared_ptr<afrl::cmasi::OperatingRegion> > m_idVsOperatingRegion;

    static bool isWithinKeepInZone(const std::shared_ptr<afrl::cmasi::Location3D>& location, const std::shared_ptr<afrl::cmasi::KeepInZone>& zone);

    static bool isWithinKeepOutZone(const std::shared_ptr<afrl::cmasi::Location3D>& location, const std::shared_ptr<afrl::cmasi::KeepOutZone>& zone);

    bool isConditionViolation(const std::shared_ptr<afrl::cmasi::AirVehicleState>& airVehicleState) const;

    void sendZeroizeCommand();

    static int timeCompareModular(int64_t t1, int64_t t2);

    friend std::ostream &operator<<(std::ostream &os, State state);
    friend std::string operator+(std::string &str, State state);

};

std::ostream &operator<<(std::ostream &os, ZeroizeConditionRecognizerService::State state);

std::string operator+(std::string &str, ZeroizeConditionRecognizerService::State state);

}; //namespace service
}; //namespace uxas

#endif /* UXAS_ZEROIZECONDITIONRECOGNIZERSERVICE_H */

