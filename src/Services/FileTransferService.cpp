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

/* 
 * File:   FileTransferService.h
 * Author: Kyle Peters
 *
 * Created on October 15, 2018, 4:11 PM
 *
 * <Service Type="FileTransferService" />
 * 
 */

// include header for this service
#include "FileTransferService.h"

//includes for LMCP Messages
#include "uxas/messages/uxnative/FileTransfer.h"
#include "uxas/messages/uxnative/FileTransferRequest.h"

#include <iostream>     // std::cout, cerr, etc
#include <fstream>      // File reading/writing

// convenience definitions for the option strings
#define STRING_XML_OPTION_STRING "OptionString"
#define STRING_XML_OPTION_INT "OptionInt"

// Definitions of chars (bytes) to be cleansed to prevent invalid char sequences in string representations of the file
#define ESCAPE_SEQUENCE_CHAR '\\'
#define ESCAPE_SEQUENCE_REPLACEMENT_STRING std::string("\\\\")
#define NULL_CHAR_REPLACEMENT_STRING std::string("\\0")
#define CHAR_REPLACEMENT_STRING_LENGTH 2


// namespace definitions
namespace uxas  // uxas::
{
namespace service   // uxas::service::
{

// this entry registers the service in the service creation registry
FileTransferService::ServiceBase::CreationRegistrar<FileTransferService>
FileTransferService::s_registrar(FileTransferService::s_registryServiceTypeNames());

// service constructor
FileTransferService::FileTransferService()
: ServiceBase(FileTransferService::s_typeName(), FileTransferService::s_directoryName()) { };

// service destructor
FileTransferService::~FileTransferService() { };


bool FileTransferService::configure(const pugi::xml_node& ndComponent)
{
    bool isSuccess(true);
    // subscribe to File Transfers and File Transfer Requests
    addSubscriptionAddress(uxas::messages::uxnative::FileTransfer::Subscription);
    addSubscriptionAddress(uxas::messages::uxnative::FileTransferRequest::Subscription);

    return (isSuccess);
}

bool FileTransferService::initialize()
{
    return (true);
}

bool FileTransferService::start()
{
    return (true);
};

bool FileTransferService::terminate()
{
    return (true);
}


std::shared_ptr<uxas::messages::uxnative::File> FileTransferService::packFile(std::string filename, std::string& errorMsg)
{
    //Input stream for reading the file
    std::ifstream inputFile;
    
    //Innocent until proven guilty - No errors detected yet
    errorMsg = "";
    
    //Prepare the File MDM
    auto response = std::make_shared<uxas::messages::uxnative::File>();
    
    //Open file for reading and log any errors
    inputFile.open(filename,std::ios::in | std::ios::binary);
    if(!inputFile.is_open())
    {
        errorMsg="Unable to open  "+filename+" for reading";
    } // end If: The input file is unable to be opened
    else
    {
        //Populate a file MDM if (and only if) the file can be read
        response->setFileName(filename);
        //Read input file char-by-char
        while(!inputFile.eof() && errorMsg.compare("")==0)
        {
            uint8_t currentByte = inputFile.get();
            
            if(!inputFile.fail())
            {
                response->getFileContents().push_back(currentByte);
            } // end If: Current char successfully read
            else if(!inputFile.eof())
            {
                errorMsg="Unable to read "+filename+" to completion; MDM may contain partial file contents";
            } // end If: A failure occurred reading a byte within the file (ignore eof failure)
        } // end loop through all bytes of the input file
    } // end If: The input file is successfully opened
    return response;
}

std::string FileTransferService::receiveFile(const std::string filename, const std::vector<uint8_t> fileData)
{
    // Result string/error message for attempting to write the file
    std::string resultString="";
    // Output stream for file writing
    std::ofstream outputFile;
    
    //Open the output file for writing; tracking any failures
    outputFile.open(filename,std::ios::out | std::ios::binary);
    if(!outputFile.is_open())
    {
        resultString="Unable to open "+filename+" for writing";
    } //end If: Output file is unable to be written
    else
    {
        //Write vector contents into the file
        outputFile.write((char*) &fileData[0],(std::streamsize) fileData.size());
        if(outputFile.fail())
        {
            resultString = "Unable to write to  "+filename+"";
        } // end if: Despite successfully opening the file, writing to the file has failed
    } // end If: Output File is able to be written
    return resultString;
}


bool FileTransferService::processReceivedLmcpMessage(std::unique_ptr<uxas::communications::data::LmcpMessage> receivedLmcpMessage)
{
    if (uxas::messages::uxnative::isFileTransfer(receivedLmcpMessage->m_object.get()))
    {
        auto transfer = std::static_pointer_cast<uxas::messages::uxnative::FileTransfer>(receivedLmcpMessage->m_object);
        std::string results;
        if(transfer->getDestinationEntityID()==m_entityId)
        {
            for(long unsigned int i = 0; i<transfer->getFiles().size();i++)
            {
                auto fileMDM = transfer->getFiles()[i];
                results= receiveFile(fileMDM->getFileName(),fileMDM->getFileContents());
                if(results.compare("")!=0)
                {
                    //Log any errors encountered while attempting to read/pack the file
                    UXAS_LOG_WARN(results);
                } // end If: Any errors were encountered while packing the file
            } // end loop through the list of files contained in the FileTransfer LMCP
        } // end If: This entity is the destination of the file transfer
    } // end If: Received LMCP message is a file transfer
    else if(uxas::messages::uxnative::isFileTransferRequest(receivedLmcpMessage->m_object.get()))
    {
        auto request = std::static_pointer_cast<uxas::messages::uxnative::FileTransferRequest>(receivedLmcpMessage->m_object);
        if(request->getSourceEntityID()==m_entityId)
        {
            auto response = std::make_shared<uxas::messages::uxnative::FileTransfer>();
            std::string errorMsg;
            
            //Pack the File Transfer Header
            response->setNonce(request->getNonce());
            response->setDestinationEntityID(request->getDestinationEntityID());
            //Pack the files from the request
            for(long unsigned int i = 0;i<request->getFileNames().size();i++)
            {
                auto fileMDM = packFile(request->getFileNames()[i],errorMsg);
                if(errorMsg.compare("")!=0)
                {
                    //Log any errors encountered while attempting to read/pack the file
                    UXAS_LOG_WARN(errorMsg);
                } // end If: Any errors were encountered while packing the file
                else
                {
                    response->getFiles().push_back(fileMDM->clone());
                } // end If: File was successfully packed into a file MDM
            } // end loop through all of the files listed in the file transfer request
            
            //Send the response/files
            auto lmcpMessage = std::static_pointer_cast<avtas::lmcp::Object>(response);
            sendSharedLmcpObjectBroadcastMessage(lmcpMessage);
        } // end If: This entity is the requested source of the file transfer
    }
    return false;
}
}; //namespace service
}; //namespace uxas
