// ===============================================================================
// Authors: Collins Aerospace
// Organization: Enterprise Engineering Foundational Capabilities, Trusted Systems
// 
// Copyright (c) 2020 Collins Aerospace
// BSD 3-Clause License.
// ===============================================================================

#include "UxAS_CAmkESLogger.h"

#include <cerrno>
#include <cstring>
#include <iostream>
#include <sstream>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern "C" {
#include "camkes_log_queue.h"
}

namespace uxas
{
namespace common
{
namespace log
{

CAmkESLogger::LoggerBase::CreationRegistrar<CAmkESLogger> CAmkESLogger::s_registrar(s_typeName());

CAmkESLogger::CAmkESLogger()
: LoggerBase(s_typeName())
{
};

bool
CAmkESLogger::openStream(std::string& logFilePath)
{
    bool isSuccess{false};

    m_deviceName = logFilePath;
    m_dataportFd = open(m_deviceName.c_str(), O_RDWR);

    if (m_dataportFd >= 0)
    {
        size_t port_size = sizeof(camkes_log_queue_t);
        m_dataport = (camkes_log_queue_t *) mmap(NULL, port_size, PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, 1 * getpagesize());
        if (m_dataport == (camkes_log_queue_t *) -1)
        {
            std::cout << "WARN: " << s_typeName() << "::initialize failed to mmap port device " << m_deviceName << ": " << strerror(errno);
            close(m_dataportFd);
        }
        else
        {
            int *emit = (int *) mmap(NULL, m_camkesEmitTriggerSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_dataportFd, 0 * getpagesize());
            m_emitTrigger.reset(emit);
            if (emit == (void *) -1)
            {
                std::cout << "WARN: " << s_typeName() << "::initialize failed to mmap emit trigger on device " << m_deviceName << ": " << strerror(errno);
                munmap((void *) m_dataport, port_size);
                close(m_dataportFd);
            }

        }
        queue_init(m_dataport);
        isSuccess = true;
        std::cout << "WARN: " << s_typeName() << "::initialized port device " << m_deviceName << " successfully, port size " << port_size;
    }
    else
    {
        std::cout << "WARN: " << s_typeName() << "::initialize failed to open port device " << m_deviceName << ": " << strerror(errno);
    }
    return (isSuccess);
};

bool
CAmkESLogger::closeStream()
{
    bool isSuccess{true};
    if ((m_emitTrigger.get() != (void *) -1) && m_emitTrigger.get() != 0)
    {
        munmap(m_emitTrigger.get(), m_camkesEmitTriggerSize);
        std::cout << "WARN: " << s_typeName() << "::unmapped emit trigger on device " << m_deviceName;
    }

    if ((m_dataport != (camkes_log_queue_t *) -1) && m_dataport != 0)
    {
        munmap((void *) m_dataport, sizeof(camkes_log_queue_t));
        std::cout << "WARN: " << s_typeName() << "::unmapped port device " << m_deviceName;
    }

    if (m_dataportFd >= 0)
    {
        close(m_dataportFd);
        std::cout << "WARN: " << s_typeName() << "::closed port device " << m_deviceName;
    }
    return (isSuccess);
};

bool
CAmkESLogger::outputTextToStream(const std::string& text)
{
    size_t textLength = text.length();
    size_t currentOffset = 0;
    camkes_log_data_t data;
    while (currentOffset < textLength) {
        size_t lengthRemaining = textLength - currentOffset;
        data.payload_length = (lengthRemaining <= sizeof(data.payload)) ? lengthRemaining : sizeof(data.payload);
        memcpy((void *) data.payload, (const void *) text.data(), (size_t) data.payload_length);
        queue_enqueue(m_dataport, &data);
        (m_emitTrigger.get())[0] = 1;
        currentOffset += data.payload_length;
    }
    data.payload_length = (uint32_t) (textLength <= sizeof(data.payload) ? textLength : sizeof(data.payload));
    return (true);
};

bool
CAmkESLogger::outputTimeTextToStream(const std::string& text, bool isTimeIsolatedLine)
{
    std::stringstream ss;
    bool isSuccess = outputToStreamBasicFormat(ss, text, m_isLogThreadId, isTimeIsolatedLine);
    if (isSuccess)
    {
        isSuccess = outputTextToStream(ss.str());
    }
    return (isSuccess);
};

bool
CAmkESLogger::outputToStream(HeadLogData& headerAndData)
{
    std::stringstream ss;
    bool isSuccess = outputToStreamBasicFormat(ss, headerAndData);
    if (isSuccess)
    {
        isSuccess = outputTextToStream(ss.str());
    }
    return (isSuccess);
};

}; //namespace log
}; //namespace common
}; //namespace uxas
