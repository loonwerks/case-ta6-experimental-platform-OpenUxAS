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

#include "UxAS_PersistentMapDatabaseHelper.h"

#include <map>
#include <memory>

#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include "avtas/lmcp/Object.h"
#include "avtas/lmcp/Factory.h"

#include "UxAS_Log.h"

namespace uxas
{
namespace common
{
namespace persistence
{

std::mutex PersistentMapDatabaseHelper::s_mutex;

PersistentMapDatabaseHelper::PersistentMapDatabaseHelper()
 : m_dbName(), m_mapName() { }

PersistentMapDatabaseHelper::~PersistentMapDatabaseHelper() { }

void
PersistentMapDatabaseHelper::configure
(const std::string& dbName, const std::string& mapName)
{
    m_dbName = dbName;
    m_mapName = mapName;
    try {
        std::lock_guard<std::mutex> lock(s_mutex);

        SQLite::Database db(m_dbName, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);

        //SQLite::Transaction transaction(db);

        std::ostringstream createStmtStringStream;
        createStmtStringStream
            << "CREATE TABLE IF NOT EXISTS "
            << m_mapName
            << " (\"keyId\" INTEGER PRIMARY KEY, \"blobValue\" BLOB);";

        db.exec(createStmtStringStream.str());

        //transaction.commit();
    } catch (std::exception& e) {
        UXAS_LOG_WARN("PersistentMapDatabaseHelper::configure: ", e.what());
    }
}

std::shared_ptr<avtas::lmcp::Object>
PersistentMapDatabaseHelper::lookup
(int64_t key)
{
    std::shared_ptr<avtas::lmcp::Object> result = nullptr;
    try {
        std::lock_guard<std::mutex> lock(s_mutex);

        SQLite::Database db(m_dbName);

        std::ostringstream selectStmtStringStream;
        selectStmtStringStream
            << "SELECT blobValue FROM "
            << m_mapName
            << " WHERE keyId = "
            << key << ";";

        SQLite::Statement selectStmt(db, selectStmtStringStream.str());

        while (selectStmt.executeStep()) {
            const SQLite::Column& blobColumn = selectStmt.getColumn(1);
            const size_t blobSize = (size_t) blobColumn.getBytes();
            const char * const blob = (const char *) blobColumn.getBlob();
            result = deserializeMessage(blob, blobSize);
        }

    } catch (std::exception& e) {
        UXAS_LOG_WARN("PersistentMapDatabaseHelper::lookup: ", e.what());
    }
    return result;
}

void
PersistentMapDatabaseHelper::put
(int64_t key, std::shared_ptr<avtas::lmcp::Object> value)
{
    try {
        std::lock_guard<std::mutex> lock(s_mutex);

        const sqlite_int64 sqlKey = key;
        std::string serializedValue = serializeMessage(value);

        SQLite::Database db(m_dbName, SQLITE_OPEN_READWRITE);

        SQLite::Transaction transaction(db);

        std::ostringstream insertStmtStringStream;
        insertStmtStringStream
            << "INSERT OR REPLACE INTO " << m_mapName
            << " (keyId, blobValue) VALUES(?, ?)";
        std::string insertStmtText = insertStmtStringStream.str();

        SQLite::Statement insertStmt(db, insertStmtText);
        insertStmt.bind(1, sqlKey);
        insertStmt.bind(2, serializedValue.c_str(), serializedValue.size());

        insertStmt.exec();

        transaction.commit();
    } catch (std::exception& e) {
        UXAS_LOG_WARN("PersistentMapDatabaseHelper::put: ", e.what());
    }
}

std::shared_ptr<std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>>
PersistentMapDatabaseHelper::asStdMap
()
{
    std::shared_ptr<std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>> result
        = std::make_shared<std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>>(std::map<int64_t, std::shared_ptr<avtas::lmcp::Object>>());
    try {
        std::lock_guard<std::mutex> lock(s_mutex);

        SQLite::Database db(m_dbName);

        std::ostringstream selectStmtStringStream;
        selectStmtStringStream
            << "SELECT * FROM "
            << m_mapName << ";";

        SQLite::Statement selectStmt(db, selectStmtStringStream.str());

        while (selectStmt.executeStep()) {
            const sqlite_int64 key = selectStmt.getColumn(0).getInt64();
            // TODO: Can we get rid of the copy here?
            const SQLite::Column& blobColumn = selectStmt.getColumn(1);
            const size_t blobSize = (size_t) blobColumn.getBytes();
            const char * const blob = (const char *) blobColumn.getBlob();
            (*result)[key] = deserializeMessage(blob, blobSize);
        }

    } catch (std::exception &e) {
        UXAS_LOG_WARN("PersistentMapDatabaseHelper::asStdMap: ", e.what());
    }
    return result;
}

std::string
PersistentMapDatabaseHelper::serializeMessage
(std::shared_ptr<avtas::lmcp::Object> value)
{
    avtas::lmcp::ByteBuffer* lmcpByteBuffer = avtas::lmcp::Factory::packMessage(value.get(), true);
    std::string result(lmcpByteBuffer->capacity(), '\0');
    // TODO: More copying that might be eliminated.
    for (size_t charIndex = 0; charIndex < lmcpByteBuffer->capacity(); charIndex++)
    {
        result[charIndex] = lmcpByteBuffer->get(charIndex);
    }
    return result;
}

std::shared_ptr<avtas::lmcp::Object>
PersistentMapDatabaseHelper::deserializeMessage
(const char * const payload, size_t payloadSize)
{
    std::shared_ptr<avtas::lmcp::Object> lmcpObject;

    // allocate memory
    avtas::lmcp::ByteBuffer lmcpByteBuffer;
    lmcpByteBuffer.allocate(payloadSize);
    lmcpByteBuffer.rewind();

    // TODO:  Yuck! Can we eliminate the need to copy the byte data?
    for (size_t charIndex = 0; charIndex < payloadSize; charIndex++)
    {
        lmcpByteBuffer.putByte(payload[charIndex]); // TODO REVIEW
    }
    lmcpByteBuffer.rewind();

    // TODO: Check checksum

    lmcpObject.reset(avtas::lmcp::Factory::getObject(lmcpByteBuffer));
    if (!lmcpObject)
    {
        UXAS_LOG_ERROR("PersistentMapDatabaseHelper::deserializeMessage failed to convert message payload string into an LMCP object");
    }

    return lmcpObject;
}

} //namespace persistence
} //namespace common
} //namespace uxas
