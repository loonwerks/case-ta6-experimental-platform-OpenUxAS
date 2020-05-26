// ===============================================================================
// Authors: Collins Aerospace
// Organization: Enterprise Engineering Foundational Capabilities, Trusted Systems
// 
// Copyright (c) 2020 Collins Aerospace
// BSD 3-Clause License.
// ===============================================================================

#include "UxAS_UDPNetLogger.h"

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>

#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <unistd.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>


namespace uxas
{
namespace common
{
namespace log
{

UDPNetLogger::LoggerBase::CreationRegistrar<UDPNetLogger> UDPNetLogger::s_registrar(s_typeName());

UDPNetLogger::UDPNetLogger()
: LoggerBase(s_typeName())
{
};

bool
UDPNetLogger::openStream(std::string& logFilePath)
{
    bool isSuccess{true};

    m_destinationAddress = logFilePath;

    std::string delimiter = ":";
    std::size_t delimiterPosition = m_destinationAddress.find(delimiter);

    memset((void *) &m_clientSockaddr, 0, sizeof(struct sockaddr_in));
    m_clientSockaddr.sin_family = AF_INET;
    m_clientSockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_clientSockaddr.sin_port = htons(0);

    // TODO: accept FQDN in addition to IP addresses as with following code:
    // look up the address of the server given its name
    // struct hostent* hp = gethostbyname(host);
    // if (!hp)
    // {
    //     fprintf(stderr, "could not obtain address of %s\n", host);
    //     return 0;
    // }
    // put the host's address into the server address structure
    // memcpy((void *)&m_destinationSockaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

    memset((void *) &m_destinationSockaddr, 0, sizeof(struct sockaddr_in));
    m_destinationSockaddr.sin_family = AF_INET;
    if (delimiterPosition == std::string::npos)
    {
        std::cout << "INFORM: " << s_typeName() << "::openStream socket destination " << m_destinationAddress.c_str() << std::endl;
        m_destinationSockaddr.sin_addr.s_addr = inet_addr(m_destinationAddress.c_str());
        m_destinationSockaddr.sin_port = htons(5577);
    }
    else
    {
        std::cout << "INFORM: " << s_typeName() << "::openStream socket destination address "
            << m_destinationAddress.substr(0, delimiterPosition).c_str() << " port "
            << m_destinationAddress.substr(delimiterPosition + 1, std::string::npos).c_str() << " ("
            << m_destinationAddress.c_str() << ")" << std::endl;
        m_destinationSockaddr.sin_addr.s_addr = inet_addr(m_destinationAddress.substr(0, delimiterPosition).c_str());
        m_destinationSockaddr.sin_port = htons(atoi(m_destinationAddress.substr(delimiterPosition + 1, std::string::npos).c_str()));
    }

    if ((m_dataportFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "WARN: " << s_typeName() << "::openStream cannot create socket " << ": " << strerror(errno);
        isSuccess = false;
    }

    if (isSuccess && bind(m_dataportFd, (struct sockaddr *) &m_clientSockaddr, sizeof(struct sockaddr_in)) < 0)
    {
        std::cout << "WARN: " << s_typeName() << "::openStream bind failed " << ": " << strerror(errno);
        isSuccess = false;
    }

    return (isSuccess);
};

bool
UDPNetLogger::closeStream()
{
    bool isSuccess{true};
    close(m_dataportFd);
    return (isSuccess);
};

bool
UDPNetLogger::outputTextToStream(const std::string& text)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    bool isSuccess = outputTextToStream(text);
    return (isSuccess);
};

bool
UDPNetLogger::outputTimeTextToStream(const std::string& text, bool isTimeIsolatedLine)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::stringstream ss;
    bool isSuccess = outputToStreamBasicFormat(ss, text, m_isLogThreadId, isTimeIsolatedLine);
    if (isSuccess)
    {
        isSuccess = outputTextToStream(ss.str());
    }
    return (isSuccess);
};

bool
UDPNetLogger::outputToStream(HeadLogData& headerAndData)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::stringstream ss;
    bool isSuccess = outputToStreamBasicFormat(ss, headerAndData);
    if (isSuccess)
    {
        isSuccess = outputTextToStream(ss.str());
    }
    return (isSuccess);
};

bool
UDPNetLogger::internalOutputTextToStream(const std::string& text)
{
    bool isSuccess{true};
    size_t textLength = text.length();
    size_t currentOffset = 0;
    const size_t mtu = 1440;  // TODO: ask the interface via getsockopt()
    while (currentOffset < textLength) {
        size_t lengthRemaining = textLength - currentOffset;
        size_t chunkSize = (lengthRemaining <= mtu) ? lengthRemaining : mtu;
        if (sendto(m_dataportFd, &(text.data()[currentOffset]), chunkSize, 0, (struct sockaddr *)&m_destinationSockaddr, sizeof(struct sockaddr_in)) < 0)
        {
            std::cout << "WARN: " << s_typeName() << "::initialize sendto failed " << ": " << strerror(errno);
            isSuccess = false;
	        break;
        }
        currentOffset += chunkSize;
    }
    return (isSuccess);
};

}; //namespace log
}; //namespace common
}; //namespace uxas
