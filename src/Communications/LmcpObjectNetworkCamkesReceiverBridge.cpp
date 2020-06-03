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

#include "LmcpObjectNetworkCamkesReceiverBridge.h"

#include "UxAS_Log.h"
#include "Constants/UxAS_String.h"

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

LmcpObjectNetworkCamkesReceiverBridge::LmcpObjectNetworkCamkesReceiverBridge()
{
};

LmcpObjectNetworkCamkesReceiverBridge::~LmcpObjectNetworkCamkesReceiverBridge()
{
    if (m_camkesProcessingThread && m_camkesProcessingThread->joinable())
    {
        m_camkesProcessingThread->detach();
    }

    if (m_camkesRecvQueue.get() != NULL && m_camkesRecvQueue.get()->queue != NULL)
    {
        munmap(m_camkesRecvQueue.get()->queue, sizeof(data_t));
        m_camkesRecvQueue.get()->queue = NULL;
        UXAS_LOG_INFORM(s_typeName(), "::unmapped initialized port device ", m_deviceName);
    }

    if (m_dataportFd >= 0)
    {
        close(m_dataportFd);
        UXAS_LOG_INFORM(s_typeName(), "::closed initialized port device ", m_deviceName);
    }
};

bool
LmcpObjectNetworkCamkesReceiverBridge::configure(const pugi::xml_node& bridgeXmlNode)
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
    
    if (!bridgeXmlNode.attribute("ConsiderSelfGenerated").empty())
    {
        m_isConsideredSelfGenerated = bridgeXmlNode.attribute("ConsiderSelfGenerated").as_bool();
        UXAS_LOG_INFORM(s_typeName(), "::configure setting 'ConsiderSelfGenerated' boolean to ", m_isConsideredSelfGenerated, " from XML configuration");
    }
    else
    {
        UXAS_LOG_INFORM(s_typeName(), "::configure did not find 'ConsiderSelfGenerated' boolean in XML configuration; 'ConsiderSelfGenerated' boolean is ", m_isConsideredSelfGenerated);
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
LmcpObjectNetworkCamkesReceiverBridge::initialize()
{
    bool isSuccess{false};

    // initialize the connection
    m_dataportFd = open(m_deviceName.c_str(), O_RDWR);
    if (m_dataportFd >= 0)
    {
        size_t port_size = sizeof(queue_t);
        int port_offset = 1 * getpagesize();
        queue_t *dp = (queue_t *) mmap(NULL, port_size, PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, port_offset);
        if (dp == (void *) -1)
        {
            UXAS_LOG_ERROR(s_typeName(), "::initialize failed to mmap port device ", m_deviceName, ": ", strerror(errno));
            close(m_dataportFd);
        }
        else
        {
            m_camkesRecvQueue = uxas::stduxas::make_unique<recv_queue_t>();
            recv_queue_init(m_camkesRecvQueue.get(), dp);
            isSuccess = true;
            UXAS_LOG_INFORM(s_typeName(), "::initialized port device ", m_deviceName, " successfully, port size ", port_size, " port offset ", port_offset);
        }        
   }
    else
    {
        UXAS_LOG_ERROR(s_typeName(), "::initialize failed to open port device ", m_deviceName, ": ", strerror(errno));
    }
    
    return (isSuccess);
};

bool
LmcpObjectNetworkCamkesReceiverBridge::start()
{
    m_camkesProcessingThread = uxas::stduxas::make_unique<std::thread>(&LmcpObjectNetworkCamkesReceiverBridge::executeCamkesReceiveProcessing, this);
    UXAS_LOG_INFORM(s_typeName(), "::start camkes receive processing thread [", m_camkesProcessingThread->get_id(), "]");
    return (true);
};

bool
LmcpObjectNetworkCamkesReceiverBridge::terminate()
{
    m_isTerminate = true;
    if (m_camkesProcessingThread && m_camkesProcessingThread->joinable())
    {
        m_camkesProcessingThread->join();
        UXAS_LOG_INFORM(s_typeName(), "::terminate calling thread completed m_camkesProcessingThread join");
    }
    else
    {
        UXAS_LOG_WARN(s_typeName(), "::terminate unexpectedly could not join m_camkesProcessingThread");
    }
    return (true);
};

bool
LmcpObjectNetworkCamkesReceiverBridge::processReceivedSerializedLmcpMessage(std::unique_ptr<uxas::communications::data::AddressedAttributedMessage> 
                                                                   receivedLmcpMessage)
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
LmcpObjectNetworkCamkesReceiverBridge::camkesPortInAadlEventDataWait(counter_t *numDropped, data_t *data) {
    UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::camkesPortInAadlEventDataWait [", m_entityIdNetworkIdUnicastString,
        "] port [", m_deviceName, "] BEFORE queue_dequeue");
    while (!queue_dequeue(m_camkesRecvQueue.get(), numDropped, data)) {
    	int val;
    	/* Blocking read */
        UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::camkesPortInAadlEventDataWait [", m_entityIdNetworkIdUnicastString,
            "] port [", m_deviceName, "] BEFORE blocking read (replaced by usleep)");
    	int result = usleep(1000000); /* read(m_dataportFd, &val, sizeof(val)); */
        UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::camkesPortInAadlEventDataWait [", m_entityIdNetworkIdUnicastString,
            "] port [", m_deviceName, "] AFTER blocking read, returned ", result);
        if (result < 0) {
            UXAS_LOG_WARN(s_typeName(), "::camkesPortInAadlEventDataWait [", m_entityIdNetworkIdUnicastString,
                "] port [", m_deviceName, "] read error: ", strerror(errno));
            return;
        } 
    }
    UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::camkesPortInAadlEventDataWait [", m_entityIdNetworkIdUnicastString,
        "] port [", m_deviceName, "] AFTER queue_dequeue loop, returning");
}

void
LmcpObjectNetworkCamkesReceiverBridge::executeCamkesReceiveProcessing()
{
    try
    {
        while (!m_isTerminate)
        {
            try
            {
                // check serial connection for inputs
                UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::executeCamkesReceiveProcessing [", m_entityIdNetworkIdUnicastString,
                                  "] port [", m_deviceName, "] BEFORE camkes connection read");
                data_t* portInput = (data_t *) calloc(1, sizeof(data_t));
                if (portInput != NULL)
                {
                    camkesPortInAadlEventDataWait(&m_numDropped, portInput);
                    unsigned long long dropCount = m_numDropped;
                    UXAS_LOG_DEBUG_VERBOSE(s_typeName(), "::executeCamkesReceiveProcessing [", m_entityIdNetworkIdUnicastString,
                            "] port [", m_deviceName, "] AFTER camkes connection read message, numDropped ", dropCount, ".");

                    UXAS_LOG_DEBUGGING(s_typeName(), "::executeCamkesReceiveProcessing [", m_deviceName, "] before processing received string");
                    std::unique_ptr<uxas::communications::data::AddressedAttributedMessage> recvdAddAttMsg = uxas::stduxas::make_unique<uxas::communications::data::AddressedAttributedMessage>();
                    std::string recvdDataSegment((const char *) portInput->payload, sizeof(portInput->payload));
                    std::string::size_type payloadLength = computeAddAttrLmcpMessageSize(recvdDataSegment);
                    UXAS_LOG_DEBUGGING(s_typeName(), "::executeCamkesReceiveProcessing [", m_deviceName, "] computed payload length ", payloadLength);
                    if (payloadLength > 0)
                    {
                        std::string recvdPayload(recvdDataSegment.substr(0, payloadLength));
                        if (recvdAddAttMsg->setAddressAttributesAndPayloadFromDelimitedString(std::move(recvdPayload)))
                        {
                            if (m_nonImportForwardAddresses.find(recvdAddAttMsg->getAddress()) == m_nonImportForwardAddresses.end())
                            {
                                if(m_isConsideredSelfGenerated)
                                {
                                    recvdAddAttMsg->updateSourceAttributes("CamkesReceiverBridge", std::to_string(m_entityId), std::to_string(m_networkId));
                                }
                                sendSerializedLmcpObjectMessage(std::move(recvdAddAttMsg));
                            }
                            else
                            {
                                UXAS_LOG_INFORM(s_typeName(), "::executeCamkesReceiveProcessing ignoring non-import message with address ", recvdAddAttMsg->getAddress(), ", source entity ID ", recvdAddAttMsg->getMessageAttributesReference()->getSourceEntityId(), " and source service ID ", recvdAddAttMsg->getMessageAttributesReference()->getSourceServiceId());
                            }
                        }
                        else
                        {
                            UXAS_LOG_WARN(s_typeName(), "::executeCamkesReceiveProcessing failed to create AddressedAttributedMessage object from serial data buffer string segment");
                        }
                    }
                    else
                    {
                        UXAS_LOG_WARN(s_typeName(), "::executeCamkesReceiveProcessing ignoring message with non-computable LMCP message size");
                    }
                    free(portInput);
                }
                else
                {
                    UXAS_LOG_ERROR(s_typeName(), "::executeCamkesReceiveProcessing could not allocate memory for receive buffer");
                }
                
                
            }
            catch (std::exception& ex2)
            {
                std::cerr << "CAmkES receiver exception: " << ex2.what() << std::endl;
            }
        }
        std::cerr << "executeCamkesReceiveProcessing exiting infinite loop thread" << std::endl;
        UXAS_LOG_INFORM(s_typeName(), "::executeCamkesReceiveProcessing exiting infinite loop thread [", std::this_thread::get_id(), "]");
    }
    catch (std::exception& ex)
    {
        std::cerr << "executeCamkesReceiveProcessing catching unknown exception: " << ex.what() << std::endl;
        UXAS_LOG_ERROR(s_typeName(), "::executeCamkesReceiveProcessing EXCEPTION: ", ex.what());
    }
};

std::string::size_type
LmcpObjectNetworkCamkesReceiverBridge::computeAddAttrLmcpMessageSize(const std::string& delimitedString) const
{
    std::string::size_type endOfAddressDelimIndex = delimitedString.find(*(data::AddressedAttributedMessage::s_addressAttributesDelimiter().c_str()));
    if (endOfAddressDelimIndex == std::string::npos)
    {
        UXAS_LOG_ERROR(s_typeName(), "::computeAddAttrLmcpMessageSize failed to parse address from delimited string ", delimitedString);
        return 0;
    }
        
    std::string::size_type endOfMessageAttributesDelimIndex = delimitedString.find(*(data::AddressedAttributedMessage::s_addressAttributesDelimiter().c_str()), (endOfAddressDelimIndex + 1));
    if (endOfMessageAttributesDelimIndex == std::string::npos)
    {
        UXAS_LOG_ERROR(s_typeName(), "::computeAddAttrLmcpMessageSize failed to parse message attribute string from delimited string ", delimitedString);
        return 0;
    }
    else if (endOfMessageAttributesDelimIndex == (delimitedString.length() - 1))
    {
        UXAS_LOG_ERROR(s_typeName(), "::computeAddAttrLmcpMessageSize payload must be non-empty");
        return 0;
    }

    const std::string::size_type lmcp_control_string_size = 4;
    const std::string::size_type checksum_size = 4;

    std::string::size_type lmcp_message_size_pos = endOfMessageAttributesDelimIndex + 1 + (std::string::size_type) lmcp_control_string_size;
    std::string::size_type lmcp_message_size = ((std::string::size_type) delimitedString.at(lmcp_message_size_pos + 0) << 24)
                                             + ((std::string::size_type) delimitedString.at(lmcp_message_size_pos + 1) << 16)
                                             + ((std::string::size_type) delimitedString.at(lmcp_message_size_pos + 2) <<  8)
                                             + ((std::string::size_type) delimitedString.at(lmcp_message_size_pos + 3) <<  0);
    
    if (lmcp_message_size > delimitedString.length())
    {
        return 0;
    }
    
    return lmcp_message_size_pos + lmcp_control_string_size + lmcp_message_size + checksum_size;
}

}; //namespace communications
}; //namespace uxas
