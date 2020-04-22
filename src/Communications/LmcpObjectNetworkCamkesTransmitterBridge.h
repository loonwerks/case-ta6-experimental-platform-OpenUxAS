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

#ifndef UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_TRANSMITTER_BRIDGE_H
#define UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_TRANSMITTER_BRIDGE_H

#include "LmcpObjectNetworkClientBase.h"

extern "C" {
#include "queue.h"
}

#include <atomic>
#include <cstdint>

namespace uxas
{
namespace communications
{

/** \class LmcpObjectNetworkCamkesTransmitterBridge
    \brief A component that connects an external CAmkES transmitter port from the internal message bus.

 * 
 * 
 *  @par Description:
 * The <B>CAmkES Transmitter Bridge<B/> component connects to external entities using a
 * CAmkES transmitter port mapped as a PCI device.  The external entity sends and receives LMCP messages
 * to/from the UxAS in message datagrams on this device.  Messages from the external entity are deserialized,
 * converted to LMCP objects, and sent to the local bus.
 * 
 * @par Details:
 * <ul style="padding-left:1em;margin-left:0">
 * 
 * <li> DeviceName -
 * The device name of the CAmkES port device is set via the configuration
 * file. The attribute: <B><I>DeviceName<I/><B/> is used to set the address, 
 * see @ref m_ptr_ZsckTcpConnection.
 * 
  * <li> Subscription -
 * Subscribed messages are configured through a XML configuration string. The
 * <B><I>SubscribeToMessages<I/><B/> XML node contains <B><I>SubscribeToMessage<I/><B/>
 * XML nodes that contain the messages to subscribe.
 * 
* </ul> @n
 * 
 */

class LmcpObjectNetworkCamkesTransmitterBridge : public LmcpObjectNetworkClientBase
{
public:

    static const std::string&
    s_typeName() { static std::string s_string("LmcpObjectNetworkCamkesTransmitterBridge"); return (s_string); };
    
    LmcpObjectNetworkCamkesTransmitterBridge();

    ~LmcpObjectNetworkCamkesTransmitterBridge();

private:

    /** \brief Copy construction not permitted */
    LmcpObjectNetworkCamkesTransmitterBridge(LmcpObjectNetworkCamkesTransmitterBridge const&) = delete;

    /** \brief Copy assignment operation not permitted */
    void operator=(LmcpObjectNetworkCamkesTransmitterBridge const&) = delete;

private:

    bool
    configure(const pugi::xml_node& bridgeXmlNode) override;

    bool
    initialize() override;

    bool
    start() override;

    bool
    terminate() override;
    
    bool
    processReceivedSerializedLmcpMessage(std::unique_ptr<uxas::communications::data::AddressedAttributedMessage>
                                        receivedLmcpMessage) override;

    std::atomic<bool> m_isTerminate{false};

    int m_dataportFd{-1};
    std::unique_ptr<queue_t> m_dataport;
    std::unique_ptr<int> m_emitTrigger;

    std::string m_deviceName = std::string("/dev/uio0");

    /** \brief maximum number of characters to read from connection
     * 
     * 20150819 DBK, RJT: approximate maximum size of an object is expected to be 300-500 bytes.
     */
    size_t m_camkesMaxBytesReadCount{DATA_T_MAX_PAYLOAD};

    const size_t m_camkesEmitTriggerSize{0x1000};

    std::set<std::string> m_externalSubscriptionAddresses;
    std::set<std::string> m_nonImportForwardAddresses;
    std::set<std::string> m_nonExportForwardAddresses;
    
};

}; //namespace communications
}; //namespace uxas

#endif /* UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_TRANSMITTER_BRIDGE_H */
