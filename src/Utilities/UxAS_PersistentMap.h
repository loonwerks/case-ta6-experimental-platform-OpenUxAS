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

#ifndef UXAS_COMMON_PERSISTENT_MAP_H
#define UXAS_COMMON_PERSISTENT_MAP_H

#include <map>
#include <memory>

#include "avtas/lmcp/Object.h"

#include "UxAS_PersistentMapDatabaseHelper.h"

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
template<class T> class PersistentMap
{
public:

    PersistentMap() : m_helper() { };

    ~PersistentMap() { };

private:

    PersistentMapDatabaseHelper m_helper;

    // \brief Prevent copy construction
    PersistentMap(const PersistentMap&) = delete;

    // \brief Prevent copy assignment operation
    PersistentMap& operator=(const PersistentMap&) = delete;

public:

    void configure(const std::string& dbName, const std::string& mapName)
    {
        m_helper.configure(dbName, mapName);
    };

    size_t size() const
    {
        return m_helper.size();
    }

    std::shared_ptr<T> lookup(int64_t key)
    {
        std::shared_ptr<T> result = nullptr;
        try {
            auto castMessage = std::dynamic_pointer_cast<T>(m_helper.lookup(key));
            if (castMessage) {
                result = castMessage;
            }
        } catch (std::exception e) {
            UXAS_LOG_WARN("PersistentMap::lookup: ", e.what());
        }
        return result;
    };

    void put(int64_t key, const std::shared_ptr<T> value)
    {
        try {
            m_helper.put(key, value);
        } catch (std::exception e) {
            UXAS_LOG_WARN("PersistentMap::put: ", e.what());
        }
    };

    std::shared_ptr<std::map<int64_t, std::shared_ptr<T>>> asStdMap()
    {
        std::shared_ptr<std::map<int64_t, std::shared_ptr<T>>> result
            = std::make_shared<std::map<int64_t, std::shared_ptr<T>>>(std::map<int64_t, std::shared_ptr<T>>());
        try {
            std::shared_ptr<std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>> objMap = m_helper.asStdMap();
            for (std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>::iterator iter = objMap->begin();
                iter != objMap->end(); ++iter)
            {
                std::shared_ptr<T> castMessage = std::dynamic_pointer_cast<T>(iter->second);
                if (castMessage)
                {
                    (*result)[iter->first] = castMessage;
                }
            }

        } catch (std::exception e) {
            UXAS_LOG_WARN("PersistentMap::asStdMap: ", e.what());
        }
        return result;
    };

    void zeroizeMap()
    {
        m_helper.zeroizeMap();
    }

};

} //namespace persistence
} //namespace common
} //namespace uxas

#endif /* UXAS_COMMON_PERSISTENT_DATABASE_H */