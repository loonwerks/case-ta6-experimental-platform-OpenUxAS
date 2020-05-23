// ===============================================================================
// Authors: Collins Aerospace
// Organization: Enterprise Engineering Foundational Capabilities, Trusted Systems
// 
// Copyright (c) 2020 Collins Aerospace
// BSD 3-Clause License.
// ===============================================================================

#ifndef UXAS_COMMON_LOG_CAMKES_LOGGER_H
#define UXAS_COMMON_LOG_CAMKES_LOGGER_H

#include "UxAS_LoggerBase.h"

#include <string>

#include <atomic>
#include <cstdint>

#include <camkes_log_queue.h>

namespace uxas
{
namespace common
{
namespace log
{

class CAmkESLogger : public LoggerBase
{
public:

    static const std::string&
    s_defaultUxasCAmkESLoggerName() { static std::string s_string("UxasCAmkESLogger"); return (s_string); };

    static const std::string&
    s_typeName() { static std::string s_string("CAmkESLogger"); return (s_string); };

    static
    LoggerBase*
    create()
    {
        return new CAmkESLogger;
    };

    CAmkESLogger();

    ~CAmkESLogger() { };

private:

    static LoggerBase::CreationRegistrar<CAmkESLogger> s_registrar;

    // \brief Prevent copy construction
    CAmkESLogger(const CAmkESLogger&) = delete;

    // \brief Prevent copy assignment operation
    CAmkESLogger& operator=(const CAmkESLogger&) = delete;

    int m_dataportFd{-1};
    std::unique_ptr<camkes_log_queue_t> m_dataport;
    std::unique_ptr<int> m_emitTrigger;

    std::string m_deviceName = std::string("/dev/uio0");

    const size_t m_camkesEmitTriggerSize{0x1000};

public:

    bool
    openStream(std::string& logFilePath) override;

    bool
    closeStream() override;

    bool
    outputTextToStream(const std::string& text) override;
    
    bool    
    outputTimeTextToStream(const std::string& text, bool isTimeIsolatedLine) override;

    bool
    outputToStream(HeadLogData& headerAndData) override;

};

}; //namespace log
}; //namespace common
}; //namespace uxas

#endif /* UXAS_COMMON_LOG_CAMKES_LOGGER_H */
