// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

#ifndef _UXAS_MESSAGES_UXNATIVE_FILETRANSFERREQUEST_H_
#define _UXAS_MESSAGES_UXNATIVE_FILETRANSFERREQUEST_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "avtas/lmcp/Factory.h"
#include "UXNATIVEEnum.h"
#include "avtas/lmcp/Object.h"

#include <vector>


namespace uxas {
namespace messages {
namespace uxnative {


   bool isFileTransferRequest(avtas::lmcp::Object* obj);
   bool isFileTransferRequest(std::shared_ptr<avtas::lmcp::Object>& obj);
   std::vector< std::string > FileTransferRequestDescendants();
   
   class FileTransferRequest : public avtas::lmcp::Object {
   public:
      static const std::string Subscription;
      static const std::string TypeName;
      static const std::string SeriesName;
      static const int64_t SeriesId;
      static const uint16_t SeriesVersion;
      static const uint32_t TypeId;
      
      // Constructor
      FileTransferRequest(void);

      // Copy Constructor
      FileTransferRequest(const FileTransferRequest &that);

      // Assignment Operator
      FileTransferRequest & operator=(const FileTransferRequest &that);

      // Destructor
      virtual ~FileTransferRequest(void);

      // Equals overload
      bool operator==(const FileTransferRequest & that);
      bool operator!=(const FileTransferRequest & that);

      // Serializes calling object into a ByteBuffer.
      virtual void pack(avtas::lmcp::ByteBuffer & buf) const;

      // Deserializes ByteBuffer into calling object.
      virtual void unpack(avtas::lmcp::ByteBuffer & buf);

      // Calculates current object size in bytes
      virtual uint32_t calculatePackedSize(void) const;

      // Creates a copy of this object and returns a pointer to it.
      virtual FileTransferRequest* clone() const;

      // Returns string representation of object
      virtual std::string toString(int32_t depth=0) const;

      // Returns an XML string representation of the object.
      virtual std::string toXML(int32_t depth=0);

      // Returns object type id
      virtual uint32_t getLmcpType(void) const { return TypeId; }
	  
      // Returns object type name string
      virtual std::string getLmcpTypeName(void) const { return TypeName; }
	  
      // Returns object type name string with full namespace prepended, same as subscription name
      virtual std::string getFullLmcpTypeName(void) const { return Subscription; }

      // Returns series name string
      virtual std::string getSeriesName(void) const { return SeriesName; }

      // gets the series name as a long value
      virtual int64_t getSeriesNameAsLong(void) const { return SeriesId; }

      //gets the version number of the series
      virtual uint16_t getSeriesVersion(void) const { return SeriesVersion; }

      // Accessors and Modifiers
      /** Nonce identifier (used to identify the FileTransfer associated with this request) (Units: None)*/
      int64_t getNonce(void) const { return __Nonce; }
      FileTransferRequest& setNonce(const int64_t val);

      /** The Entity to send the file (Units: None)*/
      int64_t getSourceEntityID(void) const { return __SourceEntityID; }
      FileTransferRequest& setSourceEntityID(const int64_t val);

      /** Intended recipient Entity ID(Units: None)*/
      int64_t getDestinationEntityID(void) const { return __DestinationEntityID; }
      FileTransferRequest& setDestinationEntityID(const int64_t val);

      /** The name of the file (on Source Entity) that should be sent (Units: None)*/
      std::vector<std::string> & getFileNames(void) { return __FileNames; }



   protected:
      /** Nonce identifier (used to identify the FileTransfer associated with this request) */
      int64_t __Nonce;
      /** The Entity to send the file */
      int64_t __SourceEntityID;
      /** Intended recipient Entity ID*/
      int64_t __DestinationEntityID;
      /** The name of the file (on Source Entity) that should be sent */
      std::vector< std::string > __FileNames;

   };

} // end namespace uxnative
} // end namespace messages
} // end namespace uxas


#endif // _UXAS_MESSAGES_UXNATIVE_FILETRANSFERREQUEST_H_
