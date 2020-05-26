// ===============================================================================
// Authors: Collins Aerospace
// Organization: Enterprise Engineering Foundational Capabilities, Trusted Systems
// 
// Copyright (c) 2020 Collins Aerospace
// BSD 3-Clause License.
// ===============================================================================

#ifndef UXAS_COMMON_LOG_UDPNET_LOGGER_H
#define UXAS_COMMON_LOG_UDPNET_LOGGER_H

#include "UxAS_LoggerBase.h"

#include <string>
#include <cstdint>
#include <mutex>

#include <arpa/inet.h>

namespace uxas
{
namespace common
{
namespace log
{

class UDPNetLogger : public LoggerBase
{
public:

    static const std::string&
    s_defaultUxasUDPNetLoggerName() { static std::string s_string("UxasUDPNetLogger"); return (s_string); };

    static const std::string&
    s_typeName() { static std::string s_string("UDPNetLogger"); return (s_string); };

    static
    LoggerBase*
    create()
    {
        return new UDPNetLogger;
    };

    UDPNetLogger();

    ~UDPNetLogger() { };

private:

    static LoggerBase::CreationRegistrar<UDPNetLogger> s_registrar;

    // \brief Prevent copy construction
    UDPNetLogger(const UDPNetLogger&) = delete;

    // \brief Prevent copy assignment operation
    UDPNetLogger& operator=(const UDPNetLogger&) = delete;

    int m_dataportFd{-1};
    struct sockaddr_in m_clientSockaddr;
    struct sockaddr_in m_destinationSockaddr;

    std::mutex m_mutex;

    std::string m_destinationAddress = std::string("127.0.0.1:5577");

public:

    bool
    openStream(std::string& destinationAddress) override;

    bool
    closeStream() override;

    bool
    outputTextToStream(const std::string& text) override;
    
    bool    
    outputTimeTextToStream(const std::string& text, bool isTimeIsolatedLine) override;

    bool
    outputToStream(HeadLogData& headerAndData) override;

private:

    bool
    internalOutputTextToStream(const std::string& text);
    
};

}; //namespace log
}; //namespace common
}; //namespace uxas

#endif /* UXAS_COMMON_LOG_UDPNET_LOGGER_H */
