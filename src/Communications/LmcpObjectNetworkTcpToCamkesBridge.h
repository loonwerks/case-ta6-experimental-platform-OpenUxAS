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

#ifndef UXAS_MESSAGE_LMCP_OBJECT_NETWORK_TCP_TO_CAMKES_BRIDGE_H
#define UXAS_MESSAGE_LMCP_OBJECT_NETWORK_TCP_TO_CAMKES_BRIDGE_H

#include "LmcpObjectNetworkClientBase.h"
#include "LmcpObjectMessageTcpReceiverSenderPipe.h"

extern "C" {
#include "queue.h"
}

#include <atomic>
#include <cstdint>
#include <functional>
#include <map>
#include <mutex>
#include <thread>
#include <set>

namespace uxas
{
namespace communications
{

/** \class LmcpObjectNetworkTcpToCamkesBridge
    \brief A service that connects an external TCP/IP stream input to CAmkES cross-VM communication output.

 * 
 * 
 *  @par Description:
 * The <B>TCP Bridge<B/> component connects to external entities using a
 * ZeroMQ ZMQ_STREAM socket. The external entity sends and receives LMCP messages
 * to the this bridge in TCP streams. Messages from the external entity are transmitted
 * directly to the CAmkES output port without deserialization/serialization.
 * 
 * @par Details:
 * <ul style="padding-left:1em;margin-left:0">
 * <li> Message Subscription - 
 * The external entity subscribes to messages through the PUB socket using "setsockopt", e.g.:
 * 
 * <li> DeviceName -
 * The device name of the CAmkES port device is set via the configuration
 * file. The attribute: <B><I>DeviceName<I/><B/> is used to set the address.
 * 
 * <li> Subscription -
 * Subscribed messages are configured through a XML configuration string. The
 * <B><I>SubscribeToMessages<I/><B/> XML node contains <B><I>SubscribeToMessage<I/><B/>
 * XML nodes that contain the messages to subscribe.
 * 
 * <li> Client/Server -
 * The <B>TCP Bridge<B/> acts as a client, by default. If the configuration file
 * attribute: <B><I>Server<I/><B/> is set to "true", then the <B>TCP Bridge<B/>
 * acts as a server.
 * 
 * <li> Addressing -
 * The TCP/IP addresses for the ZMQ_STREAM socket is set via the configuration
 * file. The attribute: <B><I>TcpAddress<I/><B/> is used to set the address, 
 * see @ref m_ptr_ZsckTcpConnection.
 * 
 * 
 * 
 * </ul> @n
 * 
 * 
 * 
 * 
 */

class LmcpObjectNetworkTcpToCamkesBridge : public LmcpObjectNetworkClientBase
{
public:

    static const std::string&
    s_typeName() { static std::string s_string("LmcpObjectNetworkTcpToCamkesBridge"); return (s_string); };

    LmcpObjectNetworkTcpToCamkesBridge();

    ~LmcpObjectNetworkTcpToCamkesBridge();

private:

    /** \brief Copy construction not permitted */
    LmcpObjectNetworkTcpToCamkesBridge(LmcpObjectNetworkTcpToCamkesBridge const&) = delete;

    /** \brief Copy assignment operation not permitted */
    void operator=(LmcpObjectNetworkTcpToCamkesBridge const&) = delete;

public:

    bool
    configure(const pugi::xml_node& bridgeXmlNode) override;

private:

    bool
    initialize() override;

    bool
    start() override;

    bool
    terminate() override;
    
    bool
    processReceivedSerializedLmcpMessage(std::unique_ptr<uxas::communications::data::AddressedAttributedMessage>
                                receivedLmcpMessage) override;

    void
    executeTcpReceiveProcessing();

    std::atomic<bool> m_isTerminate{false};

    /** \brief External TCP processing thread.  */
    std::unique_ptr<std::thread> m_tcpProcessingThread;

    std::string m_remoteConfigurationString;

    uxas::communications::LmcpObjectMessageTcpReceiverSenderPipe m_externalLmcpObjectMessageTcpReceiverSenderPipe;

    std::set<std::string> m_nonImportForwardAddresses;
    std::set<std::string> m_nonExportForwardAddresses;

    /// \brief  this is the tcp/ip address, including port, of the PUB
    /// socket, e.g.  "tcp://xxx.xxx.xxx.xxx:5555" or "tcp://*:5555". Used to
    /// relay messages to the external entity.
    std::string m_tcpReceiveSendAddress = std::string("tcp://*:5555");
    /** \brief  If this is set to true the TcpBridge connects (binds) as a server. 
     If it is false the TcpBridge connects as a client. Defaults to true */
    bool m_isServer{true};
    /** \brief  If this is set to `true`, the TcpBridge service will report all received
     * messages as if they originated from the vehicle hosting the TcpBridge rather
     * than the external sender. This can be used when connected directly to a vehicle 
     * simulation where the messages received would be considered self-generated in
     * normal operation. */
    bool m_isConsideredSelfGenerated{false};
    
    int m_dataportFd{-1};
    std::unique_ptr<queue_t> m_dataport;
    std::unique_ptr<int> m_emitTrigger;

    std::string m_deviceName = std::string("/dev/uio0");

    size_t m_camkesMaxBytesReadCount{DATA_T_MAX_PAYLOAD};

    const size_t m_camkesEmitTriggerSize{0x1000};

    std::map<std::string, std::string> m_messageAddressToAlias;
};

}; //namespace communications
}; //namespace uxas

#endif /* UXAS_MESSAGE_LMCP_OBJECT_NETWORK_TCP_TO_CAMKES_BRIDGE_H */

