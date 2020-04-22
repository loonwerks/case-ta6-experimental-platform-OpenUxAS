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

#ifndef UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_RECEIVER_BRIDGE_H
#define UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_RECEIVER_BRIDGE_H

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

/** \class LmcpObjectNetworkCamkesReceiverBridge
    \brief A component that connects an external CAmkES receiver port to the internal message bus.

 * 
 * 
 *  @par Description:
 * The <B>CAmkES Receiver Bridge<B/> component connects to external entities using a
 * CAmkES receiver port mapped as a PCI device.  The external entity sends and receives LMCP messages
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
 * </ul> @n
 * 
 */

class LmcpObjectNetworkCamkesReceiverBridge : public LmcpObjectNetworkClientBase
{
public:

    static const std::string&
    s_typeName() { static std::string s_string("LmcpObjectNetworkCamkesReceiverBridge"); return (s_string); };
    
    LmcpObjectNetworkCamkesReceiverBridge();

    ~LmcpObjectNetworkCamkesReceiverBridge();

private:

    /** \brief Copy construction not permitted */
    LmcpObjectNetworkCamkesReceiverBridge(LmcpObjectNetworkCamkesReceiverBridge const&) = delete;

    /** \brief Copy assignment operation not permitted */
    void operator=(LmcpObjectNetworkCamkesReceiverBridge const&) = delete;

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

    void
    camkesPortInAadlEventDataWait(counter_t *numDropped, data_t *data);

    void
    executeCamkesReceiveProcessing();

    std::atomic<bool> m_isTerminate{false};

    /** \brief External processing thread.  */
    std::unique_ptr<std::thread> m_camkesProcessingThread;
    
    std::unique_ptr<recv_queue_t> m_camkesRecvQueue;
    int m_dataportFd{-1};
    std::unique_ptr<queue_t> m_dataport;

    std::string m_deviceName = std::string("/dev/uio0");

    /** \brief maximum number of characters to read from connection
     * 
     * 20150819 DBK, RJT: approximate maximum size of an object is expected to be 300-500 bytes.
     */
    uint32_t m_camkesMaxBytesReadCount{DATA_T_MAX_PAYLOAD};

    /** \brief count of messages dropped by the receiver */
    counter_t m_numDropped{0};

    std::set<std::string> m_nonImportForwardAddresses;
    std::set<std::string> m_nonExportForwardAddresses;
    
    /** \brief  If this is set to `true`, the bridge service will report all received
     * messages as if they originated from the vehicle hosting the bridge rather
     * than the external sender. This can be used when connected directly to a vehicle 
     * simulation where the messages received would be considered self-generated in
     * normal operation. */
    bool m_isConsideredSelfGenerated{true};

};

}; //namespace communications
}; //namespace uxas

#endif /* UXAS_MESSAGE_LMCP_OBJECT_NETWORK_CAMKES_RECEIVER_BRIDGE_H */
