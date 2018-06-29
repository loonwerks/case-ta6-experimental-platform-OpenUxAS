/**************************************************************************
  Copyright (c) 2018 Rockwell Collins. Developed with the sponsorship
  of the Defense Advanced Research Projects Agency (DARPA).

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this data, including any software or models
  in source or binary form, as well as any drawings,
  specifications, and documentation (collectively "the Data"), to
  deal in the Data without restriction, including without
  limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Data, and to
  permit persons to whom the Data is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Data.

  THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, SPONSORS,
  DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
  DATA.
 **************************************************************************/

#ifndef UXAS_COMMON_PERSISTENT_MAP_DATABASE_HELPER_H
#define UXAS_COMMON_PERSISTENT_MAP_DATABASE_HELPER_H

#include "UxAS_PersistentMapDatabaseHelper.h"

#include <map>
#include <memory>
#include <mutex>

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Factory.h"

namespace uxas
{
namespace common
{
namespace persistence
{

/**
 * Multithreading limited to that provided by SQLite.
 * No guard against SQL injection.  Use only trusted clients.
 */
class PersistentMapDatabaseHelper
{
public:

    PersistentMapDatabaseHelper();

    ~PersistentMapDatabaseHelper();

private:

    static std::mutex s_mutex;

    std::string m_dbName = nullptr;
    std::string m_mapName = nullptr;

    // \brief Prevent copy construction
    PersistentMapDatabaseHelper(const PersistentMapDatabaseHelper&) = delete;

    // \brief Prevent copy assignment operation
    PersistentMapDatabaseHelper& operator=(const PersistentMapDatabaseHelper&) = delete;

public:

    void configure(const std::string& dbName, const std::string& mapName);

    std::shared_ptr<avtas::lmcp::Object> lookup(int64_t key);

    void put(int64_t key, std::shared_ptr<avtas::lmcp::Object>);

    std::shared_ptr<std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>> asStdMap();

private:

    std::string serializeMessage(std::shared_ptr<avtas::lmcp::Object>);

    std::shared_ptr<avtas::lmcp::Object> deserializeMessage(const char * const payload, size_t payloadSize);

};

} //namespace persistence
} //namespace common
} //namespace uxas

#endif /* UXAS_COMMON_PERSISTENT_MAP_DATABASE_HELPER_H */