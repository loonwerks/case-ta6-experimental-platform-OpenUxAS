// ===============================================================================
// Authors: AFRL/RQQA
// Organization: Air Force Research Laboratory, Aerospace Systems Directorate, Power and Control Division
// 
// Copyright (c) 2017 Government of the United State of America, as represented by
// the Secretary of the Air Force.  No copyright is claimed in the United States under
// Title 17, U.S. Code.  All Other Rights Reserved.
// ===============================================================================

// This file was auto-created by LmcpGen. Modifications will be overwritten.

// Utility libraries from standard c++
# ifdef LINUX
#include <arpa/inet.h>
#include <cstring> // memcpy
#endif
#include <string>
#include <cstdint>
#include <iostream>
#include <vector>

// Include appropriate socket implementation headers.
# ifdef WIN32
#include <winsock.h>
#endif
#define socklen_t int

#include "avtas/lmcp/ByteBuffer.h"
#include "avtas/lmcp/Factory.h"
#include "avtas/lmcp/Object.h"
#include "uxas/messages/uxnative/UXNATIVE.h"
#include "uxas/messages/task/UXTASK.h"
#include "uxas/messages/route/ROUTE.h"
#include "afrl/cmasi/perceive/PERCEIVE.h"
#include "afrl/vehicles/VEHICLES.h"
#include "afrl/impact/IMPACT.h"
#include "afrl/cmasi/CMASI.h"


# ifdef LINUX
typedef int SOCKET;
int SOCKET_ERROR = -1;  // error return code for socket()
int INVALID_SOCKET = -1;  // error return code for connect()
#endif

void SendMessages(SOCKET);
bool EstablishConnection(SOCKET&, int, std::string&);

// Define the main method.
int main(int argc, char* argv[])
{
	int port = 11041;
	std::string host = "127.0.0.1";
  
	// create connection
	SOCKET connectionSocket;
	while( !EstablishConnection(connectionSocket,port,host) )
	{
		std::cout << "Could not establish connection!" << std::endl;
	}

	// send initial messages
	SendMessages(connectionSocket);

	// Create the buffer to hold incoming messages. Choosing an arbitrarily large sized
	// buffer big enough to hold any message we want to receive.
	uint32_t bufferSize = 1048576;
	char* buffer = new char[bufferSize];

	// display any messages coming across network
	avtas::lmcp::ByteBuffer buf;
	avtas::lmcp::Object* obj;
	for(;;)
	{
		int bytesReceived = recv(connectionSocket, buffer, bufferSize, 0);

		if(bytesReceived <= 0)
		{
			std::cout << "Connection closed or message receive error. Reconnecting ..." << std::endl;
			while( !EstablishConnection(connectionSocket,port,host) )
			{
				std::cout << "Could not establish connection!" << std::endl;
			}
			SendMessages(connectionSocket);
			continue;
		}
		
		// potentially received multiple messages back-to-back
		int offsetindex = 0;
		while(bytesReceived > static_cast<int>(avtas::lmcp::Factory::HEADER_SIZE))
		{
			uint8_t* startByte = (uint8_t*) &buffer[offsetindex];
			uint32_t objsize = avtas::lmcp::Factory::getObjectSize(startByte, avtas::lmcp::Factory::HEADER_SIZE);
			objsize += avtas::lmcp::Factory::HEADER_SIZE + avtas::lmcp::Factory::CHECKSUM_SIZE;
				
			// process message
			buf.allocate(objsize);
                        buf.rewind();
			memcpy(buf.array(),startByte,objsize);
			bytesReceived -= objsize;
			offsetindex += objsize;
			obj = avtas::lmcp::Factory::getObject(buf);
			if(!obj)
			{
				std::cout << "Invalid message format" << std::endl;
				continue;
			}
			std::cout << obj->toString() << std::endl;
			delete obj;
		}
	}
}


void SendMessages(SOCKET connectionSocket)
{
	// send out all of messages
	avtas::lmcp::ByteBuffer* sendBuf = nullptr;
	uint8_t* pBuf = nullptr;

	uxas::messages::uxnative::VideoRecord* _uxasmessagesuxnativevideorecord = new uxas::messages::uxnative::VideoRecord();
	std::cout << "Sending uxas::messages::uxnative::VideoRecord" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativevideorecord, true);
	delete _uxasmessagesuxnativevideorecord;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::StartupComplete* _uxasmessagesuxnativestartupcomplete = new uxas::messages::uxnative::StartupComplete();
	std::cout << "Sending uxas::messages::uxnative::StartupComplete" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativestartupcomplete, true);
	delete _uxasmessagesuxnativestartupcomplete;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::CreateNewService* _uxasmessagesuxnativecreatenewservice = new uxas::messages::uxnative::CreateNewService();
	std::cout << "Sending uxas::messages::uxnative::CreateNewService" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativecreatenewservice, true);
	delete _uxasmessagesuxnativecreatenewservice;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::KillService* _uxasmessagesuxnativekillservice = new uxas::messages::uxnative::KillService();
	std::cout << "Sending uxas::messages::uxnative::KillService" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativekillservice, true);
	delete _uxasmessagesuxnativekillservice;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::IncrementWaypoint* _uxasmessagesuxnativeincrementwaypoint = new uxas::messages::uxnative::IncrementWaypoint();
	std::cout << "Sending uxas::messages::uxnative::IncrementWaypoint" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeincrementwaypoint, true);
	delete _uxasmessagesuxnativeincrementwaypoint;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::SafeHeadingAction* _uxasmessagesuxnativesafeheadingaction = new uxas::messages::uxnative::SafeHeadingAction();
	std::cout << "Sending uxas::messages::uxnative::SafeHeadingAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativesafeheadingaction, true);
	delete _uxasmessagesuxnativesafeheadingaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::EntityLocation* _uxasmessagesuxnativeentitylocation = new uxas::messages::uxnative::EntityLocation();
	std::cout << "Sending uxas::messages::uxnative::EntityLocation" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeentitylocation, true);
	delete _uxasmessagesuxnativeentitylocation;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::BandwidthTest* _uxasmessagesuxnativebandwidthtest = new uxas::messages::uxnative::BandwidthTest();
	std::cout << "Sending uxas::messages::uxnative::BandwidthTest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativebandwidthtest, true);
	delete _uxasmessagesuxnativebandwidthtest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::BandwidthReceiveReport* _uxasmessagesuxnativebandwidthreceivereport = new uxas::messages::uxnative::BandwidthReceiveReport();
	std::cout << "Sending uxas::messages::uxnative::BandwidthReceiveReport" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativebandwidthreceivereport, true);
	delete _uxasmessagesuxnativebandwidthreceivereport;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::SubTaskExecution* _uxasmessagesuxnativesubtaskexecution = new uxas::messages::uxnative::SubTaskExecution();
	std::cout << "Sending uxas::messages::uxnative::SubTaskExecution" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativesubtaskexecution, true);
	delete _uxasmessagesuxnativesubtaskexecution;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::SubTaskAssignment* _uxasmessagesuxnativesubtaskassignment = new uxas::messages::uxnative::SubTaskAssignment();
	std::cout << "Sending uxas::messages::uxnative::SubTaskAssignment" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativesubtaskassignment, true);
	delete _uxasmessagesuxnativesubtaskassignment;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::AutopilotKeepAlive* _uxasmessagesuxnativeautopilotkeepalive = new uxas::messages::uxnative::AutopilotKeepAlive();
	std::cout << "Sending uxas::messages::uxnative::AutopilotKeepAlive" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeautopilotkeepalive, true);
	delete _uxasmessagesuxnativeautopilotkeepalive;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::OnboardStatusReport* _uxasmessagesuxnativeonboardstatusreport = new uxas::messages::uxnative::OnboardStatusReport();
	std::cout << "Sending uxas::messages::uxnative::OnboardStatusReport" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeonboardstatusreport, true);
	delete _uxasmessagesuxnativeonboardstatusreport;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::EntityJoin* _uxasmessagesuxnativeentityjoin = new uxas::messages::uxnative::EntityJoin();
	std::cout << "Sending uxas::messages::uxnative::EntityJoin" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeentityjoin, true);
	delete _uxasmessagesuxnativeentityjoin;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::EntityExit* _uxasmessagesuxnativeentityexit = new uxas::messages::uxnative::EntityExit();
	std::cout << "Sending uxas::messages::uxnative::EntityExit" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativeentityexit, true);
	delete _uxasmessagesuxnativeentityexit;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::SimulationTimeStepAcknowledgement* _uxasmessagesuxnativesimulationtimestepacknowledgement = new uxas::messages::uxnative::SimulationTimeStepAcknowledgement();
	std::cout << "Sending uxas::messages::uxnative::SimulationTimeStepAcknowledgement" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativesimulationtimestepacknowledgement, true);
	delete _uxasmessagesuxnativesimulationtimestepacknowledgement;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::SpeedOverrideAction* _uxasmessagesuxnativespeedoverrideaction = new uxas::messages::uxnative::SpeedOverrideAction();
	std::cout << "Sending uxas::messages::uxnative::SpeedOverrideAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativespeedoverrideaction, true);
	delete _uxasmessagesuxnativespeedoverrideaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::ZeroizeCommand* _uxasmessagesuxnativezeroizecommand = new uxas::messages::uxnative::ZeroizeCommand();
	std::cout << "Sending uxas::messages::uxnative::ZeroizeCommand" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativezeroizecommand, true);
	delete _uxasmessagesuxnativezeroizecommand;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::ZeroizeCondition* _uxasmessagesuxnativezeroizecondition = new uxas::messages::uxnative::ZeroizeCondition();
	std::cout << "Sending uxas::messages::uxnative::ZeroizeCondition" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativezeroizecondition, true);
	delete _uxasmessagesuxnativezeroizecondition;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::DownloadRequest* _uxasmessagesuxnativedownloadrequest = new uxas::messages::uxnative::DownloadRequest();
	std::cout << "Sending uxas::messages::uxnative::DownloadRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativedownloadrequest, true);
	delete _uxasmessagesuxnativedownloadrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::DownloadReply* _uxasmessagesuxnativedownloadreply = new uxas::messages::uxnative::DownloadReply();
	std::cout << "Sending uxas::messages::uxnative::DownloadReply" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativedownloadreply, true);
	delete _uxasmessagesuxnativedownloadreply;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::FileTransferRequest* _uxasmessagesuxnativefiletransferrequest = new uxas::messages::uxnative::FileTransferRequest();
	std::cout << "Sending uxas::messages::uxnative::FileTransferRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativefiletransferrequest, true);
	delete _uxasmessagesuxnativefiletransferrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::File* _uxasmessagesuxnativefile = new uxas::messages::uxnative::File();
	std::cout << "Sending uxas::messages::uxnative::File" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativefile, true);
	delete _uxasmessagesuxnativefile;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::uxnative::FileTransfer* _uxasmessagesuxnativefiletransfer = new uxas::messages::uxnative::FileTransfer();
	std::cout << "Sending uxas::messages::uxnative::FileTransfer" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesuxnativefiletransfer, true);
	delete _uxasmessagesuxnativefiletransfer;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::AssignmentCoordinatorTask* _uxasmessagestaskassignmentcoordinatortask = new uxas::messages::task::AssignmentCoordinatorTask();
	std::cout << "Sending uxas::messages::task::AssignmentCoordinatorTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskassignmentcoordinatortask, true);
	delete _uxasmessagestaskassignmentcoordinatortask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::RendezvousTask* _uxasmessagestaskrendezvoustask = new uxas::messages::task::RendezvousTask();
	std::cout << "Sending uxas::messages::task::RendezvousTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskrendezvoustask, true);
	delete _uxasmessagestaskrendezvoustask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::PlanningState* _uxasmessagestaskplanningstate = new uxas::messages::task::PlanningState();
	std::cout << "Sending uxas::messages::task::PlanningState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskplanningstate, true);
	delete _uxasmessagestaskplanningstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::AssignmentCoordination* _uxasmessagestaskassignmentcoordination = new uxas::messages::task::AssignmentCoordination();
	std::cout << "Sending uxas::messages::task::AssignmentCoordination" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskassignmentcoordination, true);
	delete _uxasmessagestaskassignmentcoordination;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::CoordinatedAutomationRequest* _uxasmessagestaskcoordinatedautomationrequest = new uxas::messages::task::CoordinatedAutomationRequest();
	std::cout << "Sending uxas::messages::task::CoordinatedAutomationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskcoordinatedautomationrequest, true);
	delete _uxasmessagestaskcoordinatedautomationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskAutomationRequest* _uxasmessagestasktaskautomationrequest = new uxas::messages::task::TaskAutomationRequest();
	std::cout << "Sending uxas::messages::task::TaskAutomationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskautomationrequest, true);
	delete _uxasmessagestasktaskautomationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskAutomationResponse* _uxasmessagestasktaskautomationresponse = new uxas::messages::task::TaskAutomationResponse();
	std::cout << "Sending uxas::messages::task::TaskAutomationResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskautomationresponse, true);
	delete _uxasmessagestasktaskautomationresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::UniqueAutomationRequest* _uxasmessagestaskuniqueautomationrequest = new uxas::messages::task::UniqueAutomationRequest();
	std::cout << "Sending uxas::messages::task::UniqueAutomationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskuniqueautomationrequest, true);
	delete _uxasmessagestaskuniqueautomationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::UniqueAutomationResponse* _uxasmessagestaskuniqueautomationresponse = new uxas::messages::task::UniqueAutomationResponse();
	std::cout << "Sending uxas::messages::task::UniqueAutomationResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskuniqueautomationresponse, true);
	delete _uxasmessagestaskuniqueautomationresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::SensorFootprintRequests* _uxasmessagestasksensorfootprintrequests = new uxas::messages::task::SensorFootprintRequests();
	std::cout << "Sending uxas::messages::task::SensorFootprintRequests" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasksensorfootprintrequests, true);
	delete _uxasmessagestasksensorfootprintrequests;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::FootprintRequest* _uxasmessagestaskfootprintrequest = new uxas::messages::task::FootprintRequest();
	std::cout << "Sending uxas::messages::task::FootprintRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskfootprintrequest, true);
	delete _uxasmessagestaskfootprintrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::SensorFootprint* _uxasmessagestasksensorfootprint = new uxas::messages::task::SensorFootprint();
	std::cout << "Sending uxas::messages::task::SensorFootprint" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasksensorfootprint, true);
	delete _uxasmessagestasksensorfootprint;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::SensorFootprintResponse* _uxasmessagestasksensorfootprintresponse = new uxas::messages::task::SensorFootprintResponse();
	std::cout << "Sending uxas::messages::task::SensorFootprintResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasksensorfootprintresponse, true);
	delete _uxasmessagestasksensorfootprintresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskImplementationRequest* _uxasmessagestasktaskimplementationrequest = new uxas::messages::task::TaskImplementationRequest();
	std::cout << "Sending uxas::messages::task::TaskImplementationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskimplementationrequest, true);
	delete _uxasmessagestasktaskimplementationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskImplementationResponse* _uxasmessagestasktaskimplementationresponse = new uxas::messages::task::TaskImplementationResponse();
	std::cout << "Sending uxas::messages::task::TaskImplementationResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskimplementationresponse, true);
	delete _uxasmessagestasktaskimplementationresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::AssignmentCostMatrix* _uxasmessagestaskassignmentcostmatrix = new uxas::messages::task::AssignmentCostMatrix();
	std::cout << "Sending uxas::messages::task::AssignmentCostMatrix" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskassignmentcostmatrix, true);
	delete _uxasmessagestaskassignmentcostmatrix;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskOptionCost* _uxasmessagestasktaskoptioncost = new uxas::messages::task::TaskOptionCost();
	std::cout << "Sending uxas::messages::task::TaskOptionCost" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskoptioncost, true);
	delete _uxasmessagestasktaskoptioncost;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskAssignment* _uxasmessagestasktaskassignment = new uxas::messages::task::TaskAssignment();
	std::cout << "Sending uxas::messages::task::TaskAssignment" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskassignment, true);
	delete _uxasmessagestasktaskassignment;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskAssignmentSummary* _uxasmessagestasktaskassignmentsummary = new uxas::messages::task::TaskAssignmentSummary();
	std::cout << "Sending uxas::messages::task::TaskAssignmentSummary" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskassignmentsummary, true);
	delete _uxasmessagestasktaskassignmentsummary;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskOption* _uxasmessagestasktaskoption = new uxas::messages::task::TaskOption();
	std::cout << "Sending uxas::messages::task::TaskOption" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskoption, true);
	delete _uxasmessagestasktaskoption;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskPlanOptions* _uxasmessagestasktaskplanoptions = new uxas::messages::task::TaskPlanOptions();
	std::cout << "Sending uxas::messages::task::TaskPlanOptions" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskplanoptions, true);
	delete _uxasmessagestasktaskplanoptions;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskPause* _uxasmessagestasktaskpause = new uxas::messages::task::TaskPause();
	std::cout << "Sending uxas::messages::task::TaskPause" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskpause, true);
	delete _uxasmessagestasktaskpause;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskResume* _uxasmessagestasktaskresume = new uxas::messages::task::TaskResume();
	std::cout << "Sending uxas::messages::task::TaskResume" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskresume, true);
	delete _uxasmessagestasktaskresume;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskProgress* _uxasmessagestasktaskprogress = new uxas::messages::task::TaskProgress();
	std::cout << "Sending uxas::messages::task::TaskProgress" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskprogress, true);
	delete _uxasmessagestasktaskprogress;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskProgressRequest* _uxasmessagestasktaskprogressrequest = new uxas::messages::task::TaskProgressRequest();
	std::cout << "Sending uxas::messages::task::TaskProgressRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskprogressrequest, true);
	delete _uxasmessagestasktaskprogressrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskInitialized* _uxasmessagestasktaskinitialized = new uxas::messages::task::TaskInitialized();
	std::cout << "Sending uxas::messages::task::TaskInitialized" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskinitialized, true);
	delete _uxasmessagestasktaskinitialized;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskActive* _uxasmessagestasktaskactive = new uxas::messages::task::TaskActive();
	std::cout << "Sending uxas::messages::task::TaskActive" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskactive, true);
	delete _uxasmessagestasktaskactive;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::TaskComplete* _uxasmessagestasktaskcomplete = new uxas::messages::task::TaskComplete();
	std::cout << "Sending uxas::messages::task::TaskComplete" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestasktaskcomplete, true);
	delete _uxasmessagestasktaskcomplete;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::task::CancelTask* _uxasmessagestaskcanceltask = new uxas::messages::task::CancelTask();
	std::cout << "Sending uxas::messages::task::CancelTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagestaskcanceltask, true);
	delete _uxasmessagestaskcanceltask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::GraphNode* _uxasmessagesroutegraphnode = new uxas::messages::route::GraphNode();
	std::cout << "Sending uxas::messages::route::GraphNode" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesroutegraphnode, true);
	delete _uxasmessagesroutegraphnode;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::GraphEdge* _uxasmessagesroutegraphedge = new uxas::messages::route::GraphEdge();
	std::cout << "Sending uxas::messages::route::GraphEdge" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesroutegraphedge, true);
	delete _uxasmessagesroutegraphedge;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::GraphRegion* _uxasmessagesroutegraphregion = new uxas::messages::route::GraphRegion();
	std::cout << "Sending uxas::messages::route::GraphRegion" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesroutegraphregion, true);
	delete _uxasmessagesroutegraphregion;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RouteConstraints* _uxasmessagesrouterouteconstraints = new uxas::messages::route::RouteConstraints();
	std::cout << "Sending uxas::messages::route::RouteConstraints" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouteconstraints, true);
	delete _uxasmessagesrouterouteconstraints;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RouteRequest* _uxasmessagesrouterouterequest = new uxas::messages::route::RouteRequest();
	std::cout << "Sending uxas::messages::route::RouteRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouterequest, true);
	delete _uxasmessagesrouterouterequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoutePlanRequest* _uxasmessagesrouterouteplanrequest = new uxas::messages::route::RoutePlanRequest();
	std::cout << "Sending uxas::messages::route::RoutePlanRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouteplanrequest, true);
	delete _uxasmessagesrouterouteplanrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoutePlan* _uxasmessagesrouterouteplan = new uxas::messages::route::RoutePlan();
	std::cout << "Sending uxas::messages::route::RoutePlan" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouteplan, true);
	delete _uxasmessagesrouterouteplan;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoutePlanResponse* _uxasmessagesrouterouteplanresponse = new uxas::messages::route::RoutePlanResponse();
	std::cout << "Sending uxas::messages::route::RoutePlanResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouteplanresponse, true);
	delete _uxasmessagesrouterouteplanresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RouteResponse* _uxasmessagesrouterouteresponse = new uxas::messages::route::RouteResponse();
	std::cout << "Sending uxas::messages::route::RouteResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouterouteresponse, true);
	delete _uxasmessagesrouterouteresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::EgressRouteRequest* _uxasmessagesrouteegressrouterequest = new uxas::messages::route::EgressRouteRequest();
	std::cout << "Sending uxas::messages::route::EgressRouteRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouteegressrouterequest, true);
	delete _uxasmessagesrouteegressrouterequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::EgressRouteResponse* _uxasmessagesrouteegressrouteresponse = new uxas::messages::route::EgressRouteResponse();
	std::cout << "Sending uxas::messages::route::EgressRouteResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouteegressrouteresponse, true);
	delete _uxasmessagesrouteegressrouteresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoadPointsConstraints* _uxasmessagesrouteroadpointsconstraints = new uxas::messages::route::RoadPointsConstraints();
	std::cout << "Sending uxas::messages::route::RoadPointsConstraints" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouteroadpointsconstraints, true);
	delete _uxasmessagesrouteroadpointsconstraints;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoadPointsRequest* _uxasmessagesrouteroadpointsrequest = new uxas::messages::route::RoadPointsRequest();
	std::cout << "Sending uxas::messages::route::RoadPointsRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouteroadpointsrequest, true);
	delete _uxasmessagesrouteroadpointsrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	uxas::messages::route::RoadPointsResponse* _uxasmessagesrouteroadpointsresponse = new uxas::messages::route::RoadPointsResponse();
	std::cout << "Sending uxas::messages::route::RoadPointsResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_uxasmessagesrouteroadpointsresponse, true);
	delete _uxasmessagesrouteroadpointsresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::perceive::EntityPerception* _afrlcmasiperceiveentityperception = new afrl::cmasi::perceive::EntityPerception();
	std::cout << "Sending afrl::cmasi::perceive::EntityPerception" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiperceiveentityperception, true);
	delete _afrlcmasiperceiveentityperception;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::perceive::TrackEntityAction* _afrlcmasiperceivetrackentityaction = new afrl::cmasi::perceive::TrackEntityAction();
	std::cout << "Sending afrl::cmasi::perceive::TrackEntityAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiperceivetrackentityaction, true);
	delete _afrlcmasiperceivetrackentityaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::perceive::TrackEntityTask* _afrlcmasiperceivetrackentitytask = new afrl::cmasi::perceive::TrackEntityTask();
	std::cout << "Sending afrl::cmasi::perceive::TrackEntityTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiperceivetrackentitytask, true);
	delete _afrlcmasiperceivetrackentitytask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::GroundVehicleConfiguration* _afrlvehiclesgroundvehicleconfiguration = new afrl::vehicles::GroundVehicleConfiguration();
	std::cout << "Sending afrl::vehicles::GroundVehicleConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclesgroundvehicleconfiguration, true);
	delete _afrlvehiclesgroundvehicleconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::GroundVehicleState* _afrlvehiclesgroundvehiclestate = new afrl::vehicles::GroundVehicleState();
	std::cout << "Sending afrl::vehicles::GroundVehicleState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclesgroundvehiclestate, true);
	delete _afrlvehiclesgroundvehiclestate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::SurfaceVehicleConfiguration* _afrlvehiclessurfacevehicleconfiguration = new afrl::vehicles::SurfaceVehicleConfiguration();
	std::cout << "Sending afrl::vehicles::SurfaceVehicleConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclessurfacevehicleconfiguration, true);
	delete _afrlvehiclessurfacevehicleconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::SurfaceVehicleState* _afrlvehiclessurfacevehiclestate = new afrl::vehicles::SurfaceVehicleState();
	std::cout << "Sending afrl::vehicles::SurfaceVehicleState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclessurfacevehiclestate, true);
	delete _afrlvehiclessurfacevehiclestate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::StationarySensorConfiguration* _afrlvehiclesstationarysensorconfiguration = new afrl::vehicles::StationarySensorConfiguration();
	std::cout << "Sending afrl::vehicles::StationarySensorConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclesstationarysensorconfiguration, true);
	delete _afrlvehiclesstationarysensorconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::vehicles::StationarySensorState* _afrlvehiclesstationarysensorstate = new afrl::vehicles::StationarySensorState();
	std::cout << "Sending afrl::vehicles::StationarySensorState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlvehiclesstationarysensorstate, true);
	delete _afrlvehiclesstationarysensorstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::PowerConfiguration* _afrlimpactpowerconfiguration = new afrl::impact::PowerConfiguration();
	std::cout << "Sending afrl::impact::PowerConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactpowerconfiguration, true);
	delete _afrlimpactpowerconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::RadioConfiguration* _afrlimpactradioconfiguration = new afrl::impact::RadioConfiguration();
	std::cout << "Sending afrl::impact::RadioConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactradioconfiguration, true);
	delete _afrlimpactradioconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::RadioTowerConfiguration* _afrlimpactradiotowerconfiguration = new afrl::impact::RadioTowerConfiguration();
	std::cout << "Sending afrl::impact::RadioTowerConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactradiotowerconfiguration, true);
	delete _afrlimpactradiotowerconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::RadioState* _afrlimpactradiostate = new afrl::impact::RadioState();
	std::cout << "Sending afrl::impact::RadioState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactradiostate, true);
	delete _afrlimpactradiostate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::RadioTowerState* _afrlimpactradiotowerstate = new afrl::impact::RadioTowerState();
	std::cout << "Sending afrl::impact::RadioTowerState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactradiotowerstate, true);
	delete _afrlimpactradiotowerstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ImpactPayloadConfiguration* _afrlimpactimpactpayloadconfiguration = new afrl::impact::ImpactPayloadConfiguration();
	std::cout << "Sending afrl::impact::ImpactPayloadConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactimpactpayloadconfiguration, true);
	delete _afrlimpactimpactpayloadconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::DeployImpactPayload* _afrlimpactdeployimpactpayload = new afrl::impact::DeployImpactPayload();
	std::cout << "Sending afrl::impact::DeployImpactPayload" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactdeployimpactpayload, true);
	delete _afrlimpactdeployimpactpayload;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::PowerPlantState* _afrlimpactpowerplantstate = new afrl::impact::PowerPlantState();
	std::cout << "Sending afrl::impact::PowerPlantState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactpowerplantstate, true);
	delete _afrlimpactpowerplantstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::BatchRoutePlanRequest* _afrlimpactbatchrouteplanrequest = new afrl::impact::BatchRoutePlanRequest();
	std::cout << "Sending afrl::impact::BatchRoutePlanRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactbatchrouteplanrequest, true);
	delete _afrlimpactbatchrouteplanrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::BatchRoutePlanResponse* _afrlimpactbatchrouteplanresponse = new afrl::impact::BatchRoutePlanResponse();
	std::cout << "Sending afrl::impact::BatchRoutePlanResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactbatchrouteplanresponse, true);
	delete _afrlimpactbatchrouteplanresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::TaskTimingPair* _afrlimpacttasktimingpair = new afrl::impact::TaskTimingPair();
	std::cout << "Sending afrl::impact::TaskTimingPair" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpacttasktimingpair, true);
	delete _afrlimpacttasktimingpair;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::BatchSummaryRequest* _afrlimpactbatchsummaryrequest = new afrl::impact::BatchSummaryRequest();
	std::cout << "Sending afrl::impact::BatchSummaryRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactbatchsummaryrequest, true);
	delete _afrlimpactbatchsummaryrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::BatchSummaryResponse* _afrlimpactbatchsummaryresponse = new afrl::impact::BatchSummaryResponse();
	std::cout << "Sending afrl::impact::BatchSummaryResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactbatchsummaryresponse, true);
	delete _afrlimpactbatchsummaryresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::TaskSummary* _afrlimpacttasksummary = new afrl::impact::TaskSummary();
	std::cout << "Sending afrl::impact::TaskSummary" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpacttasksummary, true);
	delete _afrlimpacttasksummary;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::VehicleSummary* _afrlimpactvehiclesummary = new afrl::impact::VehicleSummary();
	std::cout << "Sending afrl::impact::VehicleSummary" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactvehiclesummary, true);
	delete _afrlimpactvehiclesummary;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::SpeedAltPair* _afrlimpactspeedaltpair = new afrl::impact::SpeedAltPair();
	std::cout << "Sending afrl::impact::SpeedAltPair" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactspeedaltpair, true);
	delete _afrlimpactspeedaltpair;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ImpactAutomationRequest* _afrlimpactimpactautomationrequest = new afrl::impact::ImpactAutomationRequest();
	std::cout << "Sending afrl::impact::ImpactAutomationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactimpactautomationrequest, true);
	delete _afrlimpactimpactautomationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ImpactAutomationResponse* _afrlimpactimpactautomationresponse = new afrl::impact::ImpactAutomationResponse();
	std::cout << "Sending afrl::impact::ImpactAutomationResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactimpactautomationresponse, true);
	delete _afrlimpactimpactautomationresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::PointOfInterest* _afrlimpactpointofinterest = new afrl::impact::PointOfInterest();
	std::cout << "Sending afrl::impact::PointOfInterest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactpointofinterest, true);
	delete _afrlimpactpointofinterest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::LineOfInterest* _afrlimpactlineofinterest = new afrl::impact::LineOfInterest();
	std::cout << "Sending afrl::impact::LineOfInterest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactlineofinterest, true);
	delete _afrlimpactlineofinterest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::AreaOfInterest* _afrlimpactareaofinterest = new afrl::impact::AreaOfInterest();
	std::cout << "Sending afrl::impact::AreaOfInterest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactareaofinterest, true);
	delete _afrlimpactareaofinterest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ImpactPointSearchTask* _afrlimpactimpactpointsearchtask = new afrl::impact::ImpactPointSearchTask();
	std::cout << "Sending afrl::impact::ImpactPointSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactimpactpointsearchtask, true);
	delete _afrlimpactimpactpointsearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::PatternSearchTask* _afrlimpactpatternsearchtask = new afrl::impact::PatternSearchTask();
	std::cout << "Sending afrl::impact::PatternSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactpatternsearchtask, true);
	delete _afrlimpactpatternsearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::AngledAreaSearchTask* _afrlimpactangledareasearchtask = new afrl::impact::AngledAreaSearchTask();
	std::cout << "Sending afrl::impact::AngledAreaSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactangledareasearchtask, true);
	delete _afrlimpactangledareasearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ImpactLineSearchTask* _afrlimpactimpactlinesearchtask = new afrl::impact::ImpactLineSearchTask();
	std::cout << "Sending afrl::impact::ImpactLineSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactimpactlinesearchtask, true);
	delete _afrlimpactimpactlinesearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::WatchTask* _afrlimpactwatchtask = new afrl::impact::WatchTask();
	std::cout << "Sending afrl::impact::WatchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactwatchtask, true);
	delete _afrlimpactwatchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::MultiVehicleWatchTask* _afrlimpactmultivehiclewatchtask = new afrl::impact::MultiVehicleWatchTask();
	std::cout << "Sending afrl::impact::MultiVehicleWatchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactmultivehiclewatchtask, true);
	delete _afrlimpactmultivehiclewatchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::CommRelayTask* _afrlimpactcommrelaytask = new afrl::impact::CommRelayTask();
	std::cout << "Sending afrl::impact::CommRelayTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactcommrelaytask, true);
	delete _afrlimpactcommrelaytask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::CordonTask* _afrlimpactcordontask = new afrl::impact::CordonTask();
	std::cout << "Sending afrl::impact::CordonTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactcordontask, true);
	delete _afrlimpactcordontask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::BlockadeTask* _afrlimpactblockadetask = new afrl::impact::BlockadeTask();
	std::cout << "Sending afrl::impact::BlockadeTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactblockadetask, true);
	delete _afrlimpactblockadetask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::EscortTask* _afrlimpactescorttask = new afrl::impact::EscortTask();
	std::cout << "Sending afrl::impact::EscortTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactescorttask, true);
	delete _afrlimpactescorttask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::ConfigurationRequest* _afrlimpactconfigurationrequest = new afrl::impact::ConfigurationRequest();
	std::cout << "Sending afrl::impact::ConfigurationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactconfigurationrequest, true);
	delete _afrlimpactconfigurationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::WaterReport* _afrlimpactwaterreport = new afrl::impact::WaterReport();
	std::cout << "Sending afrl::impact::WaterReport" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactwaterreport, true);
	delete _afrlimpactwaterreport;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::WaterZone* _afrlimpactwaterzone = new afrl::impact::WaterZone();
	std::cout << "Sending afrl::impact::WaterZone" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactwaterzone, true);
	delete _afrlimpactwaterzone;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::impact::PayloadDropTask* _afrlimpactpayloaddroptask = new afrl::impact::PayloadDropTask();
	std::cout << "Sending afrl::impact::PayloadDropTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlimpactpayloaddroptask, true);
	delete _afrlimpactpayloaddroptask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AbstractGeometry* _afrlcmasiabstractgeometry = new afrl::cmasi::AbstractGeometry();
	std::cout << "Sending afrl::cmasi::AbstractGeometry" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiabstractgeometry, true);
	delete _afrlcmasiabstractgeometry;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::KeyValuePair* _afrlcmasikeyvaluepair = new afrl::cmasi::KeyValuePair();
	std::cout << "Sending afrl::cmasi::KeyValuePair" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasikeyvaluepair, true);
	delete _afrlcmasikeyvaluepair;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Location3D* _afrlcmasilocation3d = new afrl::cmasi::Location3D();
	std::cout << "Sending afrl::cmasi::Location3D" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasilocation3d, true);
	delete _afrlcmasilocation3d;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PayloadAction* _afrlcmasipayloadaction = new afrl::cmasi::PayloadAction();
	std::cout << "Sending afrl::cmasi::PayloadAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipayloadaction, true);
	delete _afrlcmasipayloadaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PayloadConfiguration* _afrlcmasipayloadconfiguration = new afrl::cmasi::PayloadConfiguration();
	std::cout << "Sending afrl::cmasi::PayloadConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipayloadconfiguration, true);
	delete _afrlcmasipayloadconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PayloadState* _afrlcmasipayloadstate = new afrl::cmasi::PayloadState();
	std::cout << "Sending afrl::cmasi::PayloadState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipayloadstate, true);
	delete _afrlcmasipayloadstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::VehicleAction* _afrlcmasivehicleaction = new afrl::cmasi::VehicleAction();
	std::cout << "Sending afrl::cmasi::VehicleAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasivehicleaction, true);
	delete _afrlcmasivehicleaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Task* _afrlcmasitask = new afrl::cmasi::Task();
	std::cout << "Sending afrl::cmasi::Task" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasitask, true);
	delete _afrlcmasitask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::SearchTask* _afrlcmasisearchtask = new afrl::cmasi::SearchTask();
	std::cout << "Sending afrl::cmasi::SearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasisearchtask, true);
	delete _afrlcmasisearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AbstractZone* _afrlcmasiabstractzone = new afrl::cmasi::AbstractZone();
	std::cout << "Sending afrl::cmasi::AbstractZone" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiabstractzone, true);
	delete _afrlcmasiabstractzone;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::EntityConfiguration* _afrlcmasientityconfiguration = new afrl::cmasi::EntityConfiguration();
	std::cout << "Sending afrl::cmasi::EntityConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasientityconfiguration, true);
	delete _afrlcmasientityconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::FlightProfile* _afrlcmasiflightprofile = new afrl::cmasi::FlightProfile();
	std::cout << "Sending afrl::cmasi::FlightProfile" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiflightprofile, true);
	delete _afrlcmasiflightprofile;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AirVehicleConfiguration* _afrlcmasiairvehicleconfiguration = new afrl::cmasi::AirVehicleConfiguration();
	std::cout << "Sending afrl::cmasi::AirVehicleConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiairvehicleconfiguration, true);
	delete _afrlcmasiairvehicleconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::EntityState* _afrlcmasientitystate = new afrl::cmasi::EntityState();
	std::cout << "Sending afrl::cmasi::EntityState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasientitystate, true);
	delete _afrlcmasientitystate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AirVehicleState* _afrlcmasiairvehiclestate = new afrl::cmasi::AirVehicleState();
	std::cout << "Sending afrl::cmasi::AirVehicleState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiairvehiclestate, true);
	delete _afrlcmasiairvehiclestate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Wedge* _afrlcmasiwedge = new afrl::cmasi::Wedge();
	std::cout << "Sending afrl::cmasi::Wedge" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiwedge, true);
	delete _afrlcmasiwedge;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AreaSearchTask* _afrlcmasiareasearchtask = new afrl::cmasi::AreaSearchTask();
	std::cout << "Sending afrl::cmasi::AreaSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiareasearchtask, true);
	delete _afrlcmasiareasearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::CameraAction* _afrlcmasicameraaction = new afrl::cmasi::CameraAction();
	std::cout << "Sending afrl::cmasi::CameraAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasicameraaction, true);
	delete _afrlcmasicameraaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::CameraConfiguration* _afrlcmasicameraconfiguration = new afrl::cmasi::CameraConfiguration();
	std::cout << "Sending afrl::cmasi::CameraConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasicameraconfiguration, true);
	delete _afrlcmasicameraconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimballedPayloadState* _afrlcmasigimballedpayloadstate = new afrl::cmasi::GimballedPayloadState();
	std::cout << "Sending afrl::cmasi::GimballedPayloadState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimballedpayloadstate, true);
	delete _afrlcmasigimballedpayloadstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::CameraState* _afrlcmasicamerastate = new afrl::cmasi::CameraState();
	std::cout << "Sending afrl::cmasi::CameraState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasicamerastate, true);
	delete _afrlcmasicamerastate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Circle* _afrlcmasicircle = new afrl::cmasi::Circle();
	std::cout << "Sending afrl::cmasi::Circle" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasicircle, true);
	delete _afrlcmasicircle;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimbalAngleAction* _afrlcmasigimbalangleaction = new afrl::cmasi::GimbalAngleAction();
	std::cout << "Sending afrl::cmasi::GimbalAngleAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimbalangleaction, true);
	delete _afrlcmasigimbalangleaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimbalConfiguration* _afrlcmasigimbalconfiguration = new afrl::cmasi::GimbalConfiguration();
	std::cout << "Sending afrl::cmasi::GimbalConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimbalconfiguration, true);
	delete _afrlcmasigimbalconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimbalScanAction* _afrlcmasigimbalscanaction = new afrl::cmasi::GimbalScanAction();
	std::cout << "Sending afrl::cmasi::GimbalScanAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimbalscanaction, true);
	delete _afrlcmasigimbalscanaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimbalStareAction* _afrlcmasigimbalstareaction = new afrl::cmasi::GimbalStareAction();
	std::cout << "Sending afrl::cmasi::GimbalStareAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimbalstareaction, true);
	delete _afrlcmasigimbalstareaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GimbalState* _afrlcmasigimbalstate = new afrl::cmasi::GimbalState();
	std::cout << "Sending afrl::cmasi::GimbalState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigimbalstate, true);
	delete _afrlcmasigimbalstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::GoToWaypointAction* _afrlcmasigotowaypointaction = new afrl::cmasi::GoToWaypointAction();
	std::cout << "Sending afrl::cmasi::GoToWaypointAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasigotowaypointaction, true);
	delete _afrlcmasigotowaypointaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::KeepInZone* _afrlcmasikeepinzone = new afrl::cmasi::KeepInZone();
	std::cout << "Sending afrl::cmasi::KeepInZone" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasikeepinzone, true);
	delete _afrlcmasikeepinzone;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::KeepOutZone* _afrlcmasikeepoutzone = new afrl::cmasi::KeepOutZone();
	std::cout << "Sending afrl::cmasi::KeepOutZone" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasikeepoutzone, true);
	delete _afrlcmasikeepoutzone;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::LineSearchTask* _afrlcmasilinesearchtask = new afrl::cmasi::LineSearchTask();
	std::cout << "Sending afrl::cmasi::LineSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasilinesearchtask, true);
	delete _afrlcmasilinesearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::NavigationAction* _afrlcmasinavigationaction = new afrl::cmasi::NavigationAction();
	std::cout << "Sending afrl::cmasi::NavigationAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasinavigationaction, true);
	delete _afrlcmasinavigationaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::LoiterAction* _afrlcmasiloiteraction = new afrl::cmasi::LoiterAction();
	std::cout << "Sending afrl::cmasi::LoiterAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiloiteraction, true);
	delete _afrlcmasiloiteraction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::LoiterTask* _afrlcmasiloitertask = new afrl::cmasi::LoiterTask();
	std::cout << "Sending afrl::cmasi::LoiterTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiloitertask, true);
	delete _afrlcmasiloitertask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Waypoint* _afrlcmasiwaypoint = new afrl::cmasi::Waypoint();
	std::cout << "Sending afrl::cmasi::Waypoint" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiwaypoint, true);
	delete _afrlcmasiwaypoint;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::MissionCommand* _afrlcmasimissioncommand = new afrl::cmasi::MissionCommand();
	std::cout << "Sending afrl::cmasi::MissionCommand" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasimissioncommand, true);
	delete _afrlcmasimissioncommand;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::MustFlyTask* _afrlcmasimustflytask = new afrl::cmasi::MustFlyTask();
	std::cout << "Sending afrl::cmasi::MustFlyTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasimustflytask, true);
	delete _afrlcmasimustflytask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::OperatorSignal* _afrlcmasioperatorsignal = new afrl::cmasi::OperatorSignal();
	std::cout << "Sending afrl::cmasi::OperatorSignal" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasioperatorsignal, true);
	delete _afrlcmasioperatorsignal;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::OperatingRegion* _afrlcmasioperatingregion = new afrl::cmasi::OperatingRegion();
	std::cout << "Sending afrl::cmasi::OperatingRegion" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasioperatingregion, true);
	delete _afrlcmasioperatingregion;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AutomationRequest* _afrlcmasiautomationrequest = new afrl::cmasi::AutomationRequest();
	std::cout << "Sending afrl::cmasi::AutomationRequest" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiautomationrequest, true);
	delete _afrlcmasiautomationrequest;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PointSearchTask* _afrlcmasipointsearchtask = new afrl::cmasi::PointSearchTask();
	std::cout << "Sending afrl::cmasi::PointSearchTask" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipointsearchtask, true);
	delete _afrlcmasipointsearchtask;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Polygon* _afrlcmasipolygon = new afrl::cmasi::Polygon();
	std::cout << "Sending afrl::cmasi::Polygon" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipolygon, true);
	delete _afrlcmasipolygon;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::Rectangle* _afrlcmasirectangle = new afrl::cmasi::Rectangle();
	std::cout << "Sending afrl::cmasi::Rectangle" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasirectangle, true);
	delete _afrlcmasirectangle;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::RemoveTasks* _afrlcmasiremovetasks = new afrl::cmasi::RemoveTasks();
	std::cout << "Sending afrl::cmasi::RemoveTasks" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiremovetasks, true);
	delete _afrlcmasiremovetasks;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::ServiceStatus* _afrlcmasiservicestatus = new afrl::cmasi::ServiceStatus();
	std::cout << "Sending afrl::cmasi::ServiceStatus" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiservicestatus, true);
	delete _afrlcmasiservicestatus;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::SessionStatus* _afrlcmasisessionstatus = new afrl::cmasi::SessionStatus();
	std::cout << "Sending afrl::cmasi::SessionStatus" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasisessionstatus, true);
	delete _afrlcmasisessionstatus;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::VehicleActionCommand* _afrlcmasivehicleactioncommand = new afrl::cmasi::VehicleActionCommand();
	std::cout << "Sending afrl::cmasi::VehicleActionCommand" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasivehicleactioncommand, true);
	delete _afrlcmasivehicleactioncommand;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::VideoStreamAction* _afrlcmasivideostreamaction = new afrl::cmasi::VideoStreamAction();
	std::cout << "Sending afrl::cmasi::VideoStreamAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasivideostreamaction, true);
	delete _afrlcmasivideostreamaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::VideoStreamConfiguration* _afrlcmasivideostreamconfiguration = new afrl::cmasi::VideoStreamConfiguration();
	std::cout << "Sending afrl::cmasi::VideoStreamConfiguration" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasivideostreamconfiguration, true);
	delete _afrlcmasivideostreamconfiguration;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::VideoStreamState* _afrlcmasivideostreamstate = new afrl::cmasi::VideoStreamState();
	std::cout << "Sending afrl::cmasi::VideoStreamState" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasivideostreamstate, true);
	delete _afrlcmasivideostreamstate;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::AutomationResponse* _afrlcmasiautomationresponse = new afrl::cmasi::AutomationResponse();
	std::cout << "Sending afrl::cmasi::AutomationResponse" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiautomationresponse, true);
	delete _afrlcmasiautomationresponse;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::RemoveZones* _afrlcmasiremovezones = new afrl::cmasi::RemoveZones();
	std::cout << "Sending afrl::cmasi::RemoveZones" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiremovezones, true);
	delete _afrlcmasiremovezones;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::RemoveEntities* _afrlcmasiremoveentities = new afrl::cmasi::RemoveEntities();
	std::cout << "Sending afrl::cmasi::RemoveEntities" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiremoveentities, true);
	delete _afrlcmasiremoveentities;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::FlightDirectorAction* _afrlcmasiflightdirectoraction = new afrl::cmasi::FlightDirectorAction();
	std::cout << "Sending afrl::cmasi::FlightDirectorAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiflightdirectoraction, true);
	delete _afrlcmasiflightdirectoraction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::WeatherReport* _afrlcmasiweatherreport = new afrl::cmasi::WeatherReport();
	std::cout << "Sending afrl::cmasi::WeatherReport" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiweatherreport, true);
	delete _afrlcmasiweatherreport;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::FollowPathCommand* _afrlcmasifollowpathcommand = new afrl::cmasi::FollowPathCommand();
	std::cout << "Sending afrl::cmasi::FollowPathCommand" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasifollowpathcommand, true);
	delete _afrlcmasifollowpathcommand;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PathWaypoint* _afrlcmasipathwaypoint = new afrl::cmasi::PathWaypoint();
	std::cout << "Sending afrl::cmasi::PathWaypoint" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipathwaypoint, true);
	delete _afrlcmasipathwaypoint;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::StopMovementAction* _afrlcmasistopmovementaction = new afrl::cmasi::StopMovementAction();
	std::cout << "Sending afrl::cmasi::StopMovementAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasistopmovementaction, true);
	delete _afrlcmasistopmovementaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::WaypointTransfer* _afrlcmasiwaypointtransfer = new afrl::cmasi::WaypointTransfer();
	std::cout << "Sending afrl::cmasi::WaypointTransfer" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasiwaypointtransfer, true);
	delete _afrlcmasiwaypointtransfer;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

	afrl::cmasi::PayloadStowAction* _afrlcmasipayloadstowaction = new afrl::cmasi::PayloadStowAction();
	std::cout << "Sending afrl::cmasi::PayloadStowAction" << std::endl;
	sendBuf = avtas::lmcp::Factory::packMessage(_afrlcmasipayloadstowaction, true);
	delete _afrlcmasipayloadstowaction;
	std::cout << sendBuf->toString() << std::endl;
	pBuf = sendBuf->array();
	send(connectionSocket, (char*) pBuf, sendBuf->position(), 0);
	delete sendBuf;

}

bool EstablishConnection(SOCKET& connectionSocket, int port, std::string& host)
{
# ifdef WIN32
	// Start Winsock
	WSAData wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
#endif

	connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(connectionSocket == INVALID_SOCKET) 
		return false;
	sockaddr_in source;
	source.sin_family = AF_INET;
	source.sin_addr.s_addr = inet_addr(host.c_str());
	source.sin_port = htons((u_short)port);
	memset(&(source.sin_zero), '\0', 8);
	socklen_t source_len = sizeof(source);
	if( connect(connectionSocket, (sockaddr*)&source, source_len) == SOCKET_ERROR)
		return false;

	return true;
}
