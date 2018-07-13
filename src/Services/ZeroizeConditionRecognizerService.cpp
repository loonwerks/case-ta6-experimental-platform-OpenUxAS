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

// include header for this service
#include "ZeroizeConditionRecognizerService.h"

#include <iostream> // std::cout, cerr, etc

#include "afrl/cmasi/AbstractZone.h"
#include "afrl/cmasi/AirVehicleState.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/KeepInZone.h"
#include "afrl/cmasi/KeepOutZone.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/OperatingRegion.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"
#include "uxas/messages/route/RoutePlanRequest.h"
#include "uxas/messages/task/UniqueAutomationRequest.h"
#include "uxas/messages/uxnative/CreateNewService.h"
#include "uxas/messages/uxnative/KillService.h"
#include "uxas/messages/uxnative/ZeroizeCommand.h"
#include "uxas/messages/uxnative/ZeroizeCondition.h"

#include "FlatEarthGeometryUtilities.h"

// convenience definitions for the option strings
#define STRING_XML_ZEROIZE_ON_LANDING "ZeroizeOnLanding"
#define STRING_XML_ZEROIZE_ON_EXITING_OPERATIONAL_AREA "ZeroizeOnExitingOperationalArea"
#define STRING_XML_ZEROIZE_DATA "ZeroizeData"
#define STRING_XML_ZEROIZE_KEYS "ZeroizeKeys"
#define STRING_XML_ZEROIZE_LOGS "ZeroiseLogs"
#define STRING_XML_ZEROIZE_TASKS "ZeroizeTasks"

// namespace definitions
namespace uxas // uxas::
{
namespace service // uxas::service::
{

// this entry registers the service in the service creation registry
ZeroizeConditionRecognizerService::ServiceBase::CreationRegistrar<ZeroizeConditionRecognizerService>
    ZeroizeConditionRecognizerService::s_registrar(ZeroizeConditionRecognizerService::s_registryServiceTypeNames());

// service constructor
ZeroizeConditionRecognizerService::ZeroizeConditionRecognizerService()
    : ServiceBase(ZeroizeConditionRecognizerService::s_typeName(), ZeroizeConditionRecognizerService::s_directoryName()),
      m_zeroizeOnLanding(false), m_zeroizeOnExitingOperationalArea(false),
      m_zeroizeData(true), m_zeroizeKeys(true), m_zeroizeLogs(false), m_zeroizeTasks(false),
      m_accumulationTime(10000), m_holdoffTime(5000), m_state(State::Detect), m_timeOfNextTransition(0) {};

// service destructor
ZeroizeConditionRecognizerService::~ZeroizeConditionRecognizerService(){};

bool ZeroizeConditionRecognizerService::configure(const pugi::xml_node &ndComponent)
{
    bool isSuccess(true);

    // process options from the XML configuration node:
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_ON_LANDING).empty())
    {
        m_zeroizeOnLanding = ndComponent.attribute(STRING_XML_ZEROIZE_ON_LANDING).as_bool();
    }
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_ON_EXITING_OPERATIONAL_AREA).empty())
    {
        m_zeroizeOnExitingOperationalArea = ndComponent.attribute(STRING_XML_ZEROIZE_ON_EXITING_OPERATIONAL_AREA).as_bool();
    }
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_DATA).empty())
    {
        m_zeroizeData = ndComponent.attribute(STRING_XML_ZEROIZE_DATA).as_bool();
    }
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_KEYS).empty())
    {
        m_zeroizeKeys = ndComponent.attribute(STRING_XML_ZEROIZE_KEYS).as_bool();
    }
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_LOGS).empty())
    {
        m_zeroizeLogs = ndComponent.attribute(STRING_XML_ZEROIZE_LOGS).as_bool();
    }
    if (!ndComponent.attribute(STRING_XML_ZEROIZE_TASKS).empty())
    {
        m_zeroizeTasks = ndComponent.attribute(STRING_XML_ZEROIZE_TASKS).as_bool();
    }

    // subscribe to messages::
    addSubscriptionAddress(afrl::cmasi::KeepInZone::Subscription);
    addSubscriptionAddress(afrl::cmasi::KeepOutZone::Subscription);
    addSubscriptionAddress(afrl::cmasi::OperatingRegion::Subscription);
    addSubscriptionAddress(afrl::cmasi::AirVehicleState::Subscription);
    // addSubscriptionAddress(afrl::cmasi::EntityState::Subscription);
    // std::vector< std::string > childstates = afrl::cmasi::EntityStateDescendants();
    // for(auto child : childstates)
    //     addSubscriptionAddress(child);
    addSubscriptionAddress(uxas::messages::route::RoutePlanRequest::Subscription);
    addSubscriptionAddress(uxas::messages::task::UniqueAutomationRequest::Subscription);
    addSubscriptionAddress(uxas::messages::uxnative::CreateNewService::Subscription);
    addSubscriptionAddress(uxas::messages::uxnative::KillService::Subscription);
    addSubscriptionAddress(uxas::messages::uxnative::ZeroizeCondition::Subscription);

    return (isSuccess);
}

bool ZeroizeConditionRecognizerService::initialize()
{
    // perform any required initialization before the service is started
    std::cout << "*** INITIALIZING:: Service[" << s_typeName() << "] Service Id[" << m_serviceId << "] with working directory [" << m_workDirectoryName << "] *** " << std::endl;

    return (true);
}

bool ZeroizeConditionRecognizerService::start()
{
    // perform any actions required at the time the service starts
    std::cout << "*** STARTING:: Service[" << s_typeName() << "] Service Id[" << m_serviceId << "] with working directory [" << m_workDirectoryName << "] *** " << std::endl;

    return (true);
};

bool ZeroizeConditionRecognizerService::terminate()
{
    // perform any action required during service termination, before destructor is called.
    std::cout << "*** TERMINATING:: Service[" << s_typeName() << "] Service Id[" << m_serviceId << "] with working directory [" << m_workDirectoryName << "] *** " << std::endl;

    return (true);
}

bool ZeroizeConditionRecognizerService::processReceivedLmcpMessage(std::unique_ptr<uxas::communications::data::LmcpMessage> receivedLmcpMessage)
{
    if (afrl::cmasi::isAirVehicleState(receivedLmcpMessage->m_object))
    {
        auto airVehicleState = std::static_pointer_cast<afrl::cmasi::AirVehicleState>(receivedLmcpMessage->m_object);
        int64_t currentTime = airVehicleState->getTime();

        bool conditionViolation = isConditionViolation(airVehicleState);

        switch(m_state) {
            case State::Detect:
                if (conditionViolation)
                {
                    m_timeOfNextTransition = currentTime + m_accumulationTime;
                    m_state = State::Accumulate;
                }
                break;
            case State::Accumulate:
                if (conditionViolation)
                {
                    if (timeCompareModular(currentTime, m_timeOfNextTransition) >= 0)
                    {
                        sendZeroizeCommand();
                        m_timeOfNextTransition = currentTime + m_holdoffTime;
                        m_state = State::Holdoff;
                    }
                }
                else
                {
                    m_state = State::Detect;
                }
                break;
            case State::Holdoff:
                if (conditionViolation)
                {
                    if (timeCompareModular(currentTime, m_timeOfNextTransition) >= 0)
                    {
                        sendZeroizeCommand();
                        m_timeOfNextTransition = currentTime + m_holdoffTime;
                        m_state = State::Holdoff;
                    }
                }
                else
                {
                    m_state = State::Detect;
                }
                break;
            default:
                UXAS_LOG_ERROR("ZeroizeConditionRecognizerService: reached unrecognized state, resetting.");
                m_state = State::Detect;
                break;
        }
        if (conditionViolation)
        {
            sendZeroizeCommand();
        }
    }
    else if (afrl::cmasi::isKeepInZone(receivedLmcpMessage->m_object))
    {
        std::shared_ptr<afrl::cmasi::KeepInZone>  keepInZone = std::static_pointer_cast<afrl::cmasi::KeepInZone>(receivedLmcpMessage->m_object);
        m_idVsKeepInZone[keepInZone->getZoneID()] = keepInZone;
    }
    else if (afrl::cmasi::isKeepOutZone(receivedLmcpMessage->m_object))
    {
        std::shared_ptr<afrl::cmasi::KeepOutZone>  keepOutZone = std::static_pointer_cast<afrl::cmasi::KeepOutZone>(receivedLmcpMessage->m_object);
        m_idVsKeepOutZone[keepOutZone->getZoneID()] = keepOutZone;
    }
    else if (afrl::cmasi::isOperatingRegion(receivedLmcpMessage->m_object))
    {
        std::shared_ptr<afrl::cmasi::OperatingRegion>  operatingRegion = std::static_pointer_cast<afrl::cmasi::OperatingRegion>(receivedLmcpMessage->m_object);
        m_idVsOperatingRegion[operatingRegion->getID()] = operatingRegion;
    }
    else if (uxas::messages::uxnative::isZeroizeCondition(receivedLmcpMessage->m_object))
    {
        auto zeroizeConditionIn = std::static_pointer_cast<uxas::messages::uxnative::ZeroizeCondition>(receivedLmcpMessage->m_object);
        m_accumulationTime = zeroizeConditionIn->getZeroizeAccumulationTime();
        m_holdoffTime = zeroizeConditionIn->getZeroizeHoldoffTime();
        m_zeroizeOnExitingOperationalArea = zeroizeConditionIn->getZeroizeOnExitingOperationalArea();
        m_zeroizeOnLanding = zeroizeConditionIn->getZeroizeOnLanding();
        m_activeOperationalArea = zeroizeConditionIn->getActiveOperationalArea();
        for (auto keepInZone : zeroizeConditionIn->getKeepInZones())
        {
            m_idVsKeepInZone[keepInZone->getZoneID()] = std::make_shared<afrl::cmasi::KeepInZone>(*keepInZone);
        }
        for (auto &keepOutZone : zeroizeConditionIn->getKeepOutZones())
        {
            m_idVsKeepOutZone[keepOutZone->getZoneID()] = std::make_shared<afrl::cmasi::KeepOutZone>(*keepOutZone);
        }
        for (auto &operatingRegion : zeroizeConditionIn->getOperationalAreas())
        {
            m_idVsOperatingRegion[operatingRegion->getID()] = std::make_shared<afrl::cmasi::OperatingRegion>(*operatingRegion);
        }
        UXAS_LOG_INFORM(m_serviceId, "Received ZeroizeCondition: zeroizeOnLanding=", m_zeroizeOnLanding, ", zeroizeOnExitingOperationalArea=", m_zeroizeOnExitingOperationalArea);
    }
    return false;
}

bool ZeroizeConditionRecognizerService::isWithinKeepInZone(const std::shared_ptr<afrl::cmasi::Location3D> &location,
                                                           const std::shared_ptr<afrl::cmasi::KeepInZone> &zone)
{
    // TODO: altitudes may be AGL or MSL, need to handle this...
    float altitude = location->getAltitude();
    float zoneMinAltitude = zone->getMinAltitude();
    float zoneMaxAltitude = zone->getMaxAltitude();

    // TODO: need to handle time of effectivity for zone
    // TODO: need to handle aircraft applicability

    auto boundary = zone->getBoundary();
    if (zoneMinAltitude <= altitude && altitude <= zoneMaxAltitude)
    {
        if (afrl::cmasi::isCircle(boundary)) {
            afrl::cmasi::Circle* pCircle = static_cast<afrl::cmasi::Circle*> (boundary);
            auto circle = std::make_shared<afrl::cmasi::Circle>(*pCircle);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinCircle(location, circle);
        } else if (afrl::cmasi::isPolygon(zone->getBoundary())) {
            afrl::cmasi::Polygon* pPolygon = static_cast<afrl::cmasi::Polygon*> (boundary);
            auto polygon = std::make_shared<afrl::cmasi::Polygon>(*pPolygon);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinPolygon(location, polygon);
        } else if (afrl::cmasi::isRectangle(zone->getBoundary())) {
            afrl::cmasi::Rectangle* pRectangle = static_cast<afrl::cmasi::Rectangle*> (boundary);
            auto rectangle = std::make_shared<afrl::cmasi::Rectangle>(*pRectangle);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinRectangle(location, rectangle);
        } else {
            UXAS_LOG_ERROR("ZeroizeConditionRecognizerService::isWithinKeepInZone: encountered unknown zone->getBoundary() type");
        }
    }

    return false;
}

bool ZeroizeConditionRecognizerService::isWithinKeepOutZone(const std::shared_ptr<afrl::cmasi::Location3D> &location,
                                                            const std::shared_ptr<afrl::cmasi::KeepOutZone> &zone)
{
    // TODO: altitudes may be AGL or MSL, need to handle this...
    float altitude = location->getAltitude();
    float zoneMinAltitude = zone->getMinAltitude();
    float zoneMaxAltitude = zone->getMaxAltitude();

    // TODO: need to handle time of effectivity for zone
    // TODO: need to handle aircraft applicability

    auto boundary = zone->getBoundary();
    if (zoneMinAltitude <= altitude && altitude <= zoneMaxAltitude)
    {
        if (afrl::cmasi::isCircle(boundary)) {
            afrl::cmasi::Circle* pCircle = static_cast<afrl::cmasi::Circle*> (boundary);
            auto circle = std::make_shared<afrl::cmasi::Circle>(*pCircle);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinCircle(location, circle);
        } else if (afrl::cmasi::isPolygon(zone->getBoundary())) {
            afrl::cmasi::Polygon* pPolygon = static_cast<afrl::cmasi::Polygon*> (boundary);
            auto polygon = std::make_shared<afrl::cmasi::Polygon>(*pPolygon);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinPolygon(location, polygon);
        } else if (afrl::cmasi::isRectangle(zone->getBoundary())) {
            afrl::cmasi::Rectangle* pRectangle = static_cast<afrl::cmasi::Rectangle*> (boundary);
            auto rectangle = std::make_shared<afrl::cmasi::Rectangle>(*pRectangle);
            return uxas::common::utilities::FlatEarthGeometryUtilities::locationWithinRectangle(location, rectangle);
        } else {
            UXAS_LOG_ERROR("ZeroizeConditionRecognizerService::isWithinKeepOutZone: encountered unknown zone->getBoundary() type");
        }
    }

    return false;
}

bool
ZeroizeConditionRecognizerService::isConditionViolation
(const std::shared_ptr<afrl::cmasi::AirVehicleState>& airVehicleState) const
{
    bool result = false;
    bool inAllKeepInZones = true;
    bool inAnyKeepOutZone = false;

    auto location = std::make_shared<afrl::cmasi::Location3D>(*airVehicleState->getLocation());

    if (m_zeroizeOnExitingOperationalArea)
    {
        auto operatingRegionIter = m_idVsOperatingRegion.find(m_activeOperationalArea);
        if (operatingRegionIter != m_idVsOperatingRegion.end())
        {
            auto operatingRegion = operatingRegionIter->second;
            for (int64_t keepInZoneID : operatingRegion->getKeepInAreas())
            {
                auto keepInZoneIter = m_idVsKeepInZone.find(keepInZoneID);
                if (keepInZoneIter != m_idVsKeepInZone.end())
                {
                    auto keepInZone = std::static_pointer_cast<afrl::cmasi::KeepInZone>(keepInZoneIter->second);
                    inAllKeepInZones = inAllKeepInZones && isWithinKeepInZone(location, keepInZone);
                }
                else
                {
                    UXAS_LOG_WARN("Keep-In Zone id ", keepInZoneID, " not known.");
                }
            }
            for (int64_t keepOutZoneID : operatingRegion->getKeepOutAreas())
            {
                auto keepOutZoneIter = m_idVsKeepOutZone.find(keepOutZoneID);
                if (keepOutZoneIter != m_idVsKeepOutZone.end())
                {
                    auto keepOutZone = std::static_pointer_cast<afrl::cmasi::KeepOutZone>(keepOutZoneIter->second);
                    inAnyKeepOutZone = inAnyKeepOutZone || isWithinKeepOutZone(location, keepOutZone);
                }
                else
                {
                    UXAS_LOG_WARN("Keep-Out Zone id ", keepOutZoneID, " not known.");
                }
            }
        }
        else
        {
            UXAS_LOG_WARN("OperatingRegion id ", m_activeOperationalArea, " not known.");
        }
    }

    if (inAnyKeepOutZone || !inAllKeepInZones)
    {
        if (m_zeroizeOnExitingOperationalArea)
        {
            result = true;
        }
    }

    return result;
}

void
ZeroizeConditionRecognizerService::sendZeroizeCommand
()
{
    auto zeroizeCommandMessage = std::make_shared<uxas::messages::uxnative::ZeroizeCommand>();
    zeroizeCommandMessage->setEntityID(m_entityId);
    zeroizeCommandMessage->setZeroizeData(m_zeroizeData);
    zeroizeCommandMessage->setZeroizeKeys(m_zeroizeKeys);
    zeroizeCommandMessage->setZeroizeLogs(m_zeroizeLogs);
    zeroizeCommandMessage->setZeroizeTasks(m_zeroizeTasks);
    auto lmcpMessage = std::static_pointer_cast<avtas::lmcp::Object>(zeroizeCommandMessage);
    sendSharedLmcpObjectBroadcastMessage(lmcpMessage);
    UXAS_LOG_INFORM("Zeroization condition recognized, sent ZeroizeCommand message.");
}

int
ZeroizeConditionRecognizerService::timeCompareModular
(int64_t t1, int64_t t2)
{
    if (t1 == t2)
    {
        return 0;
    }
    else
    {
        if ((t1 - t2) > 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

}; //namespace service
}; //namespace uxas
