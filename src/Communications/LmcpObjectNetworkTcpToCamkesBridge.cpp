// ===============================================================================
// Copyright (c) 2020. Collins Aerospace.
//
// Developed with the sponsorship of Defense Advanced Research Projects Agency
// (DARPA).
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this data, including any software or models in source or binary form, as
// well as any drawings, specifications, and documentation (collectively
// "the Data"), to deal in the Data without restriction, including without
// limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Data, and to permit persons to whom the
// Data is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Data.
//
// THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS, SPONSORS, DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE DATA OR THE
// USE OR OTHER DEALINGS IN THE DATA.
//
// ===============================================================================

#include "LmcpObjectNetworkTcpToCamkesBridge.h"

#include "avtas/lmcp/Factory.h"

#include "UxAS_ConfigurationManager.h"
#include "UxAS_Log.h"
#include "Constants/UxAS_String.h"
#include "UxAS_Time.h"

#include "stdUniquePtr.h"

#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <thread>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define UXAS_LOG_INFORM uxas::common::log::LogManager::getInstance().log<uxas::common::log::LogSeverityLevel::UXASINFO>
// #define UXAS_LOG_DEBUGGING uxas::common::log::LogManager::getInstance().log<uxas::common::log::LogSeverityLevel::UXASDEBUG>
// #define UXAS_LOG_DEBUG_VERBOSE uxas::common::log::LogManager::getInstance().log<uxas::common::log::LogSeverityLevel::UXASDEBUG>

namespace uxas
{
namespace communications
{

LmcpObjectNetworkTcpToCamkesBridge::LmcpObjectNetworkTcpToCamkesBridge()
{
};

LmcpObjectNetworkTcpToCamkesBridge::~LmcpObjectNetworkTcpToCamkesBridge()
{
    if (m_tcpProcessingThread && m_tcpProcessingThread->joinable())
    {
        m_tcpProcessingThread->detach();
    }

    if ((m_emitTrigger.get() != (void *) -1) && m_emitTrigger.get() != 0)
    {
        munmap(m_emitTrigger.get(), m_camkesEmitTriggerSize);
        UXAS_LOG_INFORM(s_typeName(), "::unmapped emit trigger on device ", m_deviceName);
    }

    if ((m_dataport.get() != (void *) -1) && m_dataport.get() != 0)
    {
        munmap(m_dataport.get(), sizeof(data_t));
        UXAS_LOG_INFORM(s_typeName(), "::unmapped port device ", m_deviceName);
    }

    if (m_dataportFd >= 0)
    {
        close(m_dataportFd);
        UXAS_LOG_INFORM(s_typeName(), "::closed port device ", m_deviceName);
    }
};

bool
LmcpObjectNetworkTcpToCamkesBridge::configure(const pugi::xml_node& bridgeXmlNode)
{
    bool isSuccess{true};

    if (!bridgeXmlNode.attribute(uxas::common::StringConstant::DeviceName().c_str()).empty())
    {
        m_deviceName = bridgeXmlNode.attribute(uxas::common::StringConstant::DeviceName().c_str()).value();
        isSuccess = true;
        UXAS_LOG_INFORM(s_typeName(), "::configure setting device name to ", m_deviceName, " from XML configuration");
    }
    else
    {
        UXAS_LOG_INFORM(s_typeName(), "::configure failed to find device name in XML configuration");
    }
    
    if (!bridgeXmlNode.attribute(uxas::common::StringConstant::TcpAddress().c_str()).empty())
    {
        m_tcpReceiveSendAddress = bridgeXmlNode.attribute(uxas::common::StringConstant::TcpAddress().c_str()).value();
        UXAS_LOG_INFORM(s_typeName(), "::configure setting TCP address to ", m_tcpReceiveSendAddress, " from XML configuration");
    }
    else
    {
        isSuccess = false;
        UXAS_LOG_ERROR(s_typeName(), "::configure failed to find TCP address in XML configuration");
    }

    if (isSuccess)
    {
        if (!bridgeXmlNode.attribute(uxas::common::StringConstant::Server().c_str()).empty())
        {
            m_isServer = bridgeXmlNode.attribute(uxas::common::StringConstant::Server().c_str()).as_bool();
            UXAS_LOG_INFORM(s_typeName(), "::configure setting server boolean to ", m_isServer, " from XML configuration");
        }
        else
        {
            UXAS_LOG_INFORM(s_typeName(), "::configure did not find server boolean in XML configuration; server boolean is ", m_isServer);
        }
    }

    if (isSuccess)
    {
        if (!bridgeXmlNode.attribute("ConsiderSelfGenerated").empty())
        {
            m_isConsideredSelfGenerated = bridgeXmlNode.attribute("ConsiderSelfGenerated").as_bool();
            UXAS_LOG_INFORM(s_typeName(), "::configure setting 'ConsiderSelfGenerated' boolean to ", m_isConsideredSelfGenerated, " from XML configuration");
        }
        else
        {
            UXAS_LOG_INFORM(s_typeName(), "::configure did not find 'ConsiderSelfGenerated' boolean in XML configuration; 'ConsiderSelfGenerated' boolean is ", m_isConsideredSelfGenerated);
        }
    }
    
    if (isSuccess)
    {
        for (pugi::xml_node currentXmlNode = bridgeXmlNode.first_child(); currentXmlNode; currentXmlNode = currentXmlNode.next_sibling())
        {
            if (std::string(uxas::common::StringConstant::SubscribeToMessage().c_str()) == currentXmlNode.name())
            {
                std::string lmcpSubscribeAddress = currentXmlNode.attribute(uxas::common::StringConstant::MessageType().c_str()).value();
                if (!lmcpSubscribeAddress.empty())
                {
                    addSubscriptionAddress(lmcpSubscribeAddress);
                }
            }
            else if (std::string(uxas::common::StringConstant::TransformReceivedMessage().c_str()) == currentXmlNode.name())
            {
                const std::string lmcpAddress = currentXmlNode.attribute(uxas::common::StringConstant::MessageType().c_str()).value();
                const std::string alias = currentXmlNode.attribute(uxas::common::StringConstant::Alias().c_str()).value();

                if (!lmcpAddress.empty() && !alias.empty())
                {
                    m_messageAddressToAlias[lmcpAddress] = alias;
                }
            }
        }

        //
        // DESIGN 20150911 RJT message addressing - entity ID
        // - received/sent LMCP messages always include entity ID
        // - the entity cast address is derived from entity ID (see getEntityCastAddress function)
        // - bridges never subscribe to the entity cast address on the internal network
        // - bridges usually subscribe (or coordinate subscription) to the entity cast address on external networks
        //   (TCP and serial bridges do not have external subscription)
        //

        // do not forward any uni-cast messages addressed to this bridge
        UXAS_LOG_INFORM(s_typeName(), "::configure adding non-forward address [", getNetworkClientUnicastAddress(m_entityId, m_networkId), "]");
        m_nonImportForwardAddresses.emplace(getNetworkClientUnicastAddress(m_entityId, m_networkId));
        m_nonExportForwardAddresses.emplace(getNetworkClientUnicastAddress(m_entityId, m_networkId));
    }

    return (isSuccess);
};

bool
LmcpObjectNetworkTcpToCamkesBridge::initialize()
{
    bool isSuccess{false};

    UXAS_LOG_INFORM(s_typeName(), "::initialize - START");

    // initialize the connection
    m_dataportFd = open(m_deviceName.c_str(), O_RDWR);
    if (m_dataportFd >= 0)
    {
        size_t port_size = sizeof(queue_t);
        queue_t *dp = (queue_t *) mmap(NULL, port_size, PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, 1 * getpagesize());
        m_dataport.reset(dp);
        if (m_dataport.get() == (void *) -1)
        {
            UXAS_LOG_ERROR(s_typeName(), "::initialize failed to mmap port device ", m_deviceName, ": ", strerror(errno));
            close(m_dataportFd);
        }
        else
        {
            int *emit = (int *) mmap(NULL, m_camkesEmitTriggerSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, 0 * getpagesize());
            m_emitTrigger.reset(emit);
            if (emit == (void *) -1)
            {
                UXAS_LOG_ERROR(s_typeName(), "::initialize failed to mmap emit trigger on device ", m_deviceName, ": ", strerror(errno));
                munmap(m_dataport.get(), port_size);
                close(m_dataportFd);
            }

        }
        queue_init(m_dataport.get());
        isSuccess = true;
        UXAS_LOG_INFORM(s_typeName(), "::initialized port device ", m_deviceName, " successfully, port size ", port_size);
    }
    else
    {
        UXAS_LOG_ERROR(s_typeName(), "::initialize failed to open port device ", m_deviceName, ": ", strerror(errno));
    }
    
    m_externalLmcpObjectMessageTcpReceiverSenderPipe.initializeStream(m_entityId, m_networkId, m_tcpReceiveSendAddress, m_isServer);

    UXAS_LOG_INFORM(s_typeName(), "::initialize returning ", isSuccess);
    return (isSuccess);
};

bool
LmcpObjectNetworkTcpToCamkesBridge::start()
{
    m_tcpProcessingThread = uxas::stduxas::make_unique<std::thread>(&LmcpObjectNetworkTcpToCamkesBridge::executeTcpReceiveProcessing, this);
    UXAS_LOG_INFORM(s_typeName(), "::start TCP receive processing thread [", m_tcpProcessingThread->get_id(), "]");
    return (true);
};

bool
LmcpObjectNetworkTcpToCamkesBridge::terminate()
{
    m_isTerminate = true;
    if (m_tcpProcessingThread && m_tcpProcessingThread->joinable())
    {
        m_tcpProcessingThread->join();
        UXAS_LOG_INFORM(s_typeName(), "::terminate calling thread completed m_tcpProcessingThread join");
    }
    else
    {
        UXAS_LOG_WARN(s_typeName(), "::terminate unexpectedly could not join m_tcpProcessingThread");
    }
    return (true);
};

bool
LmcpObjectNetworkTcpToCamkesBridge::processReceivedSerializedLmcpMessage(std::unique_ptr<uxas::communications::data::AddressedAttributedMessage> receivedLmcpMessage)
{
    // send message to the external entity
    UXAS_LOG_DEBUGGING(s_typeName(), "::processReceivedSerializedLmcpMessage [", m_entityIdNetworkIdUnicastString, 
            "] before processing serialized message having address ", receivedLmcpMessage->getAddress(),
                  " and size ", receivedLmcpMessage->getPayload().size());

    // process messages from a local service (only)
    // do nothing -- this service receives from external sources only

    return (false); // always false implies never terminating bridge from here
};

void
LmcpObjectNetworkTcpToCamkesBridge::executeTcpReceiveProcessing()
{
    try
    {
        while (!m_isTerminate)
        {
            UXAS_LOG_DEBUG_VERBOSE_BRIDGE("LmcpObjectNetworkTcpBridge::executeTcpReceiveProcessing BEFORE calling receivedTcpMessage");
            std::unique_ptr<uxas::communications::data::AddressedAttributedMessage> receivedTcpMessage 
                    = m_externalLmcpObjectMessageTcpReceiverSenderPipe.getNextSerializedMessage();

            if (receivedTcpMessage)
            {
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("LmcpObjectNetworkTcpBridge::executeTcpReceiveProcessing RECEIVED EXTERNAL serialized message");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("Address:          [", receivedTcpMessage->getAddress(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("ContentType:      [", receivedTcpMessage->getMessageAttributesReference()->getContentType(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("Descriptor:       [", receivedTcpMessage->getMessageAttributesReference()->getDescriptor(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("SourceGroup:      [", receivedTcpMessage->getMessageAttributesReference()->getSourceGroup(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("SourceEntityId:   [", receivedTcpMessage->getMessageAttributesReference()->getSourceEntityId(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("SourceServiceId:  [", receivedTcpMessage->getMessageAttributesReference()->getSourceServiceId(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("AttributesString: [", receivedTcpMessage->getMessageAttributesReference()->getString(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("getPayload:       [", receivedTcpMessage->getPayload(), "]");
                UXAS_LOG_DEBUG_VERBOSE_BRIDGE("getString:        [", receivedTcpMessage->getString(), "]");

                if (m_nonImportForwardAddresses.find(receivedTcpMessage->getAddress()) == m_nonImportForwardAddresses.end())
                {
                    if(m_isConsideredSelfGenerated)
                    {
                        receivedTcpMessage->updateSourceAttributes("TcpBridge", std::to_string(m_entityId), std::to_string(m_networkId));
                    }

                    const auto it = m_messageAddressToAlias.find(receivedTcpMessage->getAddress());
                    if (it != m_messageAddressToAlias.cend())
                    {
                        receivedTcpMessage->updateAddress(it->second);
                    }

                    UXAS_LOG_INFORM(s_typeName(), "::executeTcpReceiveProcessing processing message with source entity ID ", receivedTcpMessage->getMessageAttributesReference()->getSourceEntityId());
                    try
                    {
                        std::string messageString = receivedTcpMessage->getString();
                        size_t messageStringLength = messageString.length();
                        data_t *data = (data_t*) calloc(1, sizeof(data_t));
                        if (data != NULL)
                        {
                            size_t data_len = (messageStringLength <= m_camkesMaxBytesReadCount) ? messageStringLength : m_camkesMaxBytesReadCount;
                            memcpy((void *) data->payload, (const void *) messageString.data(), data_len);
                            queue_enqueue(m_dataport.get(), data);
                            (m_emitTrigger.get())[0] = 1;
                            UXAS_LOG_INFORM(s_typeName(), "::executeTcpReceiveProcessing sent message of ", data_len, " octets");
                            free(data);
                        }
                        else
                        {
                            UXAS_LOG_ERROR(s_typeName(), "::executeTcpReceiveProcessing could not allocate data buffer");
                        }
                
                    }
                    catch (std::exception& ex)
                    {
                        std::string errorMessage;
                        UXAS_LOG_ERROR(errorMessage, " EXCEPTION: ", ex.what());
                    }
                }
                else
                {
                    UXAS_LOG_INFORM(s_typeName(), "::executeTcpReceiveProcessing ignoring non-import message with address ", receivedTcpMessage->getAddress(), ", source entity ID ", receivedTcpMessage->getMessageAttributesReference()->getSourceEntityId(), " and source service ID ", receivedTcpMessage->getMessageAttributesReference()->getSourceServiceId());
                }
            }
            else
            {
                UXAS_LOG_INFORM(s_typeName(), "::executeTcpReceiveProcessing ignoring external message with entity ID ", m_entityIdString, " since it matches its own entity ID");
            }
        }
        UXAS_LOG_INFORM(s_typeName(), "::executeTcpReceiveProcessing exiting infinite loop thread [", std::this_thread::get_id(), "]");
    }
    catch (std::exception& ex)
    {
        UXAS_LOG_ERROR(s_typeName(), "::executeTcpReceiveProcessing EXCEPTION: ", ex.what());
    }
};

}; //namespace communications
}; //namespace uxas
