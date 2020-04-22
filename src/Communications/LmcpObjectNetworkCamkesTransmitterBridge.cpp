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

#include "LmcpObjectNetworkCamkesTransmitterBridge.h"

#include "SerialHelper.h"

#include "UxAS_Log.h"
#include "Constants/UxAS_String.h"

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace uxas
{
namespace communications
{

LmcpObjectNetworkCamkesTransmitterBridge::LmcpObjectNetworkCamkesTransmitterBridge()
{
};

LmcpObjectNetworkCamkesTransmitterBridge::~LmcpObjectNetworkCamkesTransmitterBridge()
{
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
LmcpObjectNetworkCamkesTransmitterBridge::configure(const pugi::xml_node& bridgeXmlNode)
{
    bool isSuccess{false};

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
    
    if (isSuccess)
    {
        for (pugi::xml_node currentXmlNode = bridgeXmlNode.first_child(); currentXmlNode; currentXmlNode = currentXmlNode.next_sibling())
        {
            if (std::string(uxas::common::StringConstant::SubscribeToMessage().c_str()) == currentXmlNode.name())
            {
                std::string subscriptionAddress = currentXmlNode.attribute(uxas::common::StringConstant::MessageType().c_str()).value();
                if (!subscriptionAddress.empty())
                {
                    addSubscriptionAddress(subscriptionAddress);
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

        // do not forward uni-cast messages addressed to this bridge
        UXAS_LOG_INFORM(s_typeName(), "::configure adding non-forward address [", getNetworkClientUnicastAddress(m_entityId, m_networkId), "]");
        m_nonImportForwardAddresses.emplace(getNetworkClientUnicastAddress(m_entityId, m_networkId));
        m_nonExportForwardAddresses.emplace(getNetworkClientUnicastAddress(m_entityId, m_networkId));
    }

    return (isSuccess);
};

bool
LmcpObjectNetworkCamkesTransmitterBridge::initialize()
{
    bool isSuccess{false};

    // initialize the connection
    m_dataportFd = open(m_deviceName.c_str(), O_RDWR);
    if (m_dataportFd >= 0)
    {
        queue_t *dp = (queue_t *) mmap(NULL, sizeof(data_t), PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, 1 * getpagesize());
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
                UXAS_LOG_ERROR(s_typeName(), "::initialize failed to mmap emit trigger on device  ", m_deviceName, ": ", strerror(errno));
                munmap(m_dataport.get(), sizeof(data_t));
                close(m_dataportFd);
            }

        }
        queue_init(m_dataport.get());
        isSuccess = true;
        UXAS_LOG_INFORM(s_typeName(), "::initialized initialized port device ", m_deviceName, "successfully");
    }
    else
    {
        UXAS_LOG_ERROR(s_typeName(), "::initialize failed to open port device ", m_deviceName, ": ", strerror(errno));
    }
    
    return (isSuccess);
};

bool
LmcpObjectNetworkCamkesTransmitterBridge::start()
{
    return (true);
};

bool
LmcpObjectNetworkCamkesTransmitterBridge::terminate()
{
    m_isTerminate = true;
    return (true);
};

bool
LmcpObjectNetworkCamkesTransmitterBridge::processReceivedSerializedLmcpMessage(std::unique_ptr<uxas::communications::data::AddressedAttributedMessage> 
                                                                   receivedLmcpMessage)
{
    // send message to the external entity
    UXAS_LOG_DEBUGGING(s_typeName(), "::processReceivedSerializedLmcpMessage [", m_entityIdNetworkIdUnicastString, 
            "] before processing serialized message having address ", receivedLmcpMessage->getAddress(),
                  " and size ", receivedLmcpMessage->getPayload().size());

    // process messages from a local service (only)
    if (m_entityIdString == receivedLmcpMessage->getMessageAttributesReference()->getSourceEntityId())
    {
        if (m_nonExportForwardAddresses.find(receivedLmcpMessage->getAddress()) == m_nonExportForwardAddresses.end())
        {
            UXAS_LOG_INFORM(s_typeName(), "::processReceivedSerializedLmcpMessage processing message with source entity ID ", receivedLmcpMessage->getMessageAttributesReference()->getSourceEntityId());
            try
            {
                std::string messageString = receivedLmcpMessage->getString();
                size_t messageStringLength = messageString.length();
                data_t data;
                data.len = (messageStringLength <= m_camkesMaxBytesReadCount) ? messageStringLength : m_camkesMaxBytesReadCount;
                memcpy((void *) data.payload, (const void *) messageString.data(), data.len);
                queue_enqueue(m_dataport.get(), &data);
                (m_emitTrigger.get())[0] = 1;
            }
            catch (std::exception& ex)
            {
                std::string errorMessage;
                UXAS_LOG_ERROR(errorMessage, " EXCEPTION: ", ex.what());
            }
        }
        else
        {
            UXAS_LOG_INFORM(s_typeName(), "::processReceivedSerializedLmcpMessage ignoring non-export message with address ", receivedLmcpMessage->getAddress(), ", source entity ID ", receivedLmcpMessage->getMessageAttributesReference()->getSourceEntityId(), " and source service ID ", receivedLmcpMessage->getMessageAttributesReference()->getSourceServiceId());
        }
    }
    else
    {
        UXAS_LOG_INFORM(s_typeName(), "::processReceivedSerializedLmcpMessage ignoring message with source entity ID ", receivedLmcpMessage->getMessageAttributesReference()->getSourceEntityId());
    }


    return (false); // always false implies never terminating bridge from here
};

}; //namespace communications
}; //namespace uxas
