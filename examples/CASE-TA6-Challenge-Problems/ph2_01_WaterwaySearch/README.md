# Waterway Search Example

This is an example of running UxAS service that communicates to the AMASE simulation in order to generate plans and an assignment for one of one UAVs to survay a waterway as commanded from a ground station. For more background see the file 'doc/UxAS_UserManual.pdf'


## To Do:

1. Modify configuration to have a single UAV and a single ground station.
2. Modify the CPP source code for the services to utilize persistent storage (i.e. UxAS::PersistentMap) to maintain data elements AirVehicleConfiguration, (initial) AirVehicleState, Task, and ZeroizeCondition in the persistent maps.  The following services may be affected StatusReportService, Test_SimulationTime, TaskManagerService, AutomationRequestValidatorService, RoutePlannerVisibilityService, RouteAggregatorService, AssignmentTreeBranchBoundService, AutomationDiagramDataService, WaypointPlanManagerService, PlanBuilderService, and ZeroizeConditionRecognizer.
3. Construct an initialized database containing necessary values for AirVehicleConfiguration, AirVehicleState, ZeroizeCondition, KeepInZones, KeepOutZones, and a LineSearchTask.
4. Configure the ground station instance of UxAS to send a single AutomationRequest message requesting the line search task.
5. Update the AMASE configuration to illustrate this scenario.
6. Integrate onto target ODROID XU4 target.
7. Update this README.md again (sections files, running the example, what happens, things to try).


## Files:

* `cfg_WaterwaySearch_UAV.xml` - Configuration file for services to be run on the UAV instance of UxAS
* `cfg_WaterwaySearch_UAV.xml` - Configuration file for services to be run on the ground station instance of UxAS
* `runUxAS_WaterwaySearch_UAV.sh` - Bash shell script to run the UAV instance of UxAS
* `runUxAS_WaterwaySearch_GS.sh` - Bash shell script to run the ground station instance of UxAS
* `runAMASE_WaterwaySearch.sh` - Bash shell script to run the OpenAMASE simulation environment
* `Scenario_WaterwaySearch.xml` - Configuration file for the OpenAMASE simulation environment
* `MessagesToSend/` - most of the messages in this directory are explained in the document, `WaterwayExample_MessageFLow.pdf`. A few are explained below:
* `MessagesToSend/LINE_Waterway_Deschutes.kml` - a 'kml' file from Google Earth, used to define the line search task.
* `MessagesToSend/KmlToBoundariesTasks.WaterwaySearch.py` - a python script that process the kml file and generates LMCP messages for the example. 


## The 'MessagesToSend' directory contains files with xml encoded LMCP messages that are sent in to UxAS using the 'MessagesToSend' service. ##

* `MessagesToSend/Tasks/AutomationRequest.xml` - the operating region, i.e. set of keep-in and keep-out tasks, to be used in the assignment.


## Running the Example:
1. open a terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
2. enter the command: `./runAMASE_WaterwaySearch.sh`
3. start the AMASE simulation (i.e. push the play button)
4. open another terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
5. enter the command: `./runUxAS_WaterwaySearch_UAV.sh`
6. open another terminal window in the directory: "examples/CASE-TA6-Challenge-Problems/ph2_01_WaterwaySearch/"
7. enter the command: `./runUxAS_WaterwaySearch_GS.sh`


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


