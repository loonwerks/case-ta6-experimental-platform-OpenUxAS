# CASE Challenge Problem #2 - Waterway Search Example

This an adaptation of the OpenUxAS Waterway Search Example to provide a scenario demonstrating data transfer.

Instead of all UxAS service running on a single host, the configuration files and start scripts have been modified to distribute the Waterway Search Example activities across
one UxAS instance running on the experimental platform target, one UxAS instance running on the host, and OpenAMASE running on the host.

## Files:

* `cfg_WaterwaySearch-Vehicle400.xml` - Configuration for UxAS instance to run on experimental platform target
* `runUxAS_WaterwaySearch-Vehicle400.sh` - Run script for UxAS instance to run on experimental platform target
* `cfg_WaterwaySearch-ground.xml` - Configuration for UxAS instance to run on experimental platform target
* `runUxAS_WaterwaySearch-ground.sh` - Configuration for UxAS instance to run on host
* `runAMASE_WaterwaySearch.sh` - Run script for UxAS instance to run on experimental platform target
* `Scenario_WaterwaySearch.xml` -
* `MessagesToSend/` - most of the messages in this directory are explained in the document, `WaterwayExample_MessageFLow.pdf`. A few are explained below:
* `MessagesToSend/LINE_Waterway_Deschutes.kml` - a 'kml' file from Google Earth, used to define the line search task.
* `MessagesToSend/KmlToBoundariesTasks.WaterwaySearch.py` - a python script that process the kml file and generates LMCP messages for the example. 

## Modification to Suit Your Environment

The configuration files cfg_WaterwaySearch-Vehicle400.xml and cfg_WaterwaySearch-ground.xml need to have the identified network addresses and interface names changed to match the
network topology for your local site.  Note the the ZyreMQ bridge operates only on a single ethernet segment.  Accordingly, both the host and the ODROID target must be connected to
the same ethernet segment.  At line 3 of the configuration host configuration file cfg_WaterwaySearch-ground.xml the `NetworkDevice` should be changed to the name of the interface
for the ethernet segment on which both the host and ODROID target are connected.  At line 10 of the target configuration file cfg_WaterwaySearch-Vehicle400.xml, the `TcpAddress`
should be changed to match the IP address of the host interface of the IP subnetwork on which both the host and the target are connected.

## Running the Example:

1. on the target, open a ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/02_Example_WaterwaySearch/"
2. and enter the command: `./runUxAS_WaterwaySearch-Vehicle400.sh`
3. on the host, open a ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/02_Example_WaterwaySearch/"
4. and enter the command: `./runUxAS_WaterwaySearch-ground.sh`
5. on the host open another ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/02_Example_WaterwaySearch/"
6. and enter the command: `./runAMASE_WaterwaySearch.sh`
7. start the Amase simulation (i.e. push the play button)

### What Happens?

* When the Amase simulation starts, two UAVs will be initialized and begin loitering about to different loactions. Note: Amase uses NASA Worldwind for background imagery. If no imagery is available, Amase's background will be black.
* Vehice-400 UxAS instance (running on the experimental target platform) will periodically write aircraft state LMCP messages for connected UAVs (Vehicles 400 and 500) to files: Vehicle-400.txt and Vehicle-500.txt respectively (tracking the aircraft state history for each vehicle on the experimental platform).
* .3 seconds after UxAS starts a line representing the LineSearchTask will appear in Amase
* 2 seconds after the simulation starts, a DownloadRequest message is sent to the UxAS instance on the target
* Shortly after this the target should respond with a DownloadReply message
* 5 seconds after UxAS start an AutomationRequest is sent to UxAS which kick off the mission
* Once the plans have been calculated and a UAV is assigned to perform the LineSearchTask, waypoints will be displayed in Amase and the UAV will start following them.
* When the UAV reaches the first waypoint of the LineSearchTask, its sensor will move to follow the river.
* As the search progresses, the UAV will cross through a KeepOutZone identified in the ZeroizeCondition and at this point ZeroizationCommands will be issued.
* 10 seconds after UxAS simulation begins a file transfer will automatically transfer Vehicle-400.txt and Vehicle-500.txt files from the Vehicle 400 instance of UxAS running on the experimental platform to the ground instance of UxAS running on the host platform.  As a result, a copy of the files (Vehicle-400.txt and Vehicle-500.txt) should appear in the run directory for the ground instance of UxAS on the host platform.


