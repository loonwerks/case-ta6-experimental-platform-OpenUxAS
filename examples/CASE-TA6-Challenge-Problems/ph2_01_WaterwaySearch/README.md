# Waterway Search Example

This is an example of running UxAS service that communicates to the AMASE simulation in order to generate plans and an assignment for one of one UAVs to survay a waterway as commanded from a ground station. For more background see the file 'doc/UxAS_UserManual.pdf'

## Mapping AADL model to OpenUxAS implementation

The AADL model maps to the implementation very much in one-to-one manner.  However, the following implementation details are observed:

* The OpenUxAS executable contains all services implemented to date.  Services listed in the architectural model are present in the binary code but are not activated.
* The ground station is a second instance of the OpenUxAS executable is used to implement the ground station.  Only the "SendMessagesService" is active, transmitting the operating region, line search task, and automation request messages to drive the scenario.
* The LmcpObjectNetworkZeroMqZyreBridge service implements the radio in the architectural model.  For these, the "SubscribeToMessage" configurations implement the input ports to the radio and the "SubscribeToExternalMessage" configurations implement the output ports from the radio.
* The output of the UxAS to via serial to the flight control computer is implemented by the LmcpObjectNetworkTcpBridge service to the AMASE simulation front end.


## Files:

* `cfg_WaterwaySearch_UAV.xml` - Configuration file for services to be run on the UAV instance of UxAS
* `cfg_WaterwaySearch_GS.xml` - Configuration file for services to be run on the ground station instance of UxAS
* `runUxAS_WaterwaySearch_UAV.sh` - Bash shell script to run the UAV instance of UxAS
* `runUxAS_WaterwaySearch_GS.sh` - Bash shell script to run the ground station instance of UxAS
* `runAMASE_WaterwaySearch.sh` - Bash shell script to run the OpenAMASE simulation environment
* `Scenario_WaterwaySearch.xml` - Configuration file for the OpenAMASE simulation environment
* `Messages/` - most of the messages in this directory are explained in the document, `WaterwayExample_MessageFLow.pdf`. A few are explained below
* `InitMessages/` - Messages sent internally at the UAV to establish initial operating state


## The 'Messages' directory contains files with xml encoded LMCP messages that are sent in to UxAS using the 'Messages' service. ##

* `Messages/KeepInZone_334.xml` - defines polygon containing the search area
* `Messages/KeepOutZone_335.xml` - defines circular region in river bend UAV should avoid
* `Messages/ZeroizeCondition_V400.xml` - defines conditions on which UAV should zeroize with respect to keep-in and keep-out zones
* `Messages/tasks/AutomationRequest.xml` - request by ID the line search task


## Running the Example:
1. open a terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
2. enter the command: `./runAMASE_WaterwaySearch.sh`
3. start the AMASE simulation (i.e. push the play button)
4. open another terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
5. enter the command: `./runUxAS_WaterwaySearch_UAV.sh`
6. open another terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
7. enter the command: `./runUxAS_WaterwaySearch_GS.sh`
8. click the "play" button on the AMASE simulation window


### What Happens?
* When the AMASE simulation starts, one UAV and one ground station will be initialized.  The UAV begins loitering about to a location near the waterway. Note: AMASE uses NASA Worldwind for background imagery. If no imagery is available, AMASE's background will be black.
* .3 seconds after UxAS starts a line representing the LineSearchTask will appear in AMASE
* 5 seconds after UxAS start an AutomationRequest is sent but the ground station to the UAV which kick off the mission
* Once the plans have been calculated and the UAV is assigned to perform the LineSearchTask, waypoints will be displayed in AMASE and the UAV will start following them.
* When the UAV reaches the first waypoint of the LineSearchTask, its sensor will move to follow the river.


### Things to Try:
1. Inject malformed AutomationRequest message to attempt to distrupt the UAV.
2. Attack network interfaces to UAV or ground station via radio.
3. Other???


## To Do:

1. Integrate onto target ODROID XU4 target.



