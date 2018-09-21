# CASE Challenge Problem #1 - Distributed Cooperation Example

This an adaptation of the OpenUxAS Distributed Cooperation Example to provide a scenario demonstrating zeroization.

Instead of all UxAS services running on a single host, the configuration files and start scripts have been modified to distribute the Distributed Cooperation Example activities across
one UxAS instance running on the experimental platform target, one UxAS instance running on the host, and OpenAMASE running on the host.

## Files:

* `cfgDistributedCooperation_1000-host.xml` - UxAS configuration file for vehicle 1000 on the host
* `cfgDistributedCooperation_2000-xu4.xml` - UxAS configuration file for vehicle 2000 on the target
* `runAMASE_DistributedCooperation.sh` - bash script to run the example
* `runUxAS_DistributedCooperation-host.sh` - bash script to run the example on the host
* `runUxAS_DistributedCooperation-xu4.sh` - bash script to run the example on the target
 
## The 'MessagesToSend' directory contains files with xml encoded LMCP messages that are sent in to UxAS using the 'MessagesToSend' service. ##

* `MessagesToSend/AirVehicleConfiguration_V????.xml` - the air vehicle configurations for vehicles 1000, 2000, and 3000.
* `MessagesToSend/AirVehicleState_V????.xml` - initial air vehicle states for vehicles  1000 and 2000.
* `MessagesToSend/AngledAreaSearchTask_51.xml` - an IMPACT angled area search task.
* `MessagesToSend/AreaOfInterest_100.xml` - the area that AngledAreaSearchTask_51 will search.
* `MessagesToSend/AreaSearchTask_50.xml` - a CMASI area search task.
* `MessagesToSend/AssignmentCoordinatorTask.xml` - the task that coordinates vehicle states before the assignment
* `MessagesToSend/CoordinatedAutomationRequest.xml` - the automation request used in conjunction with the AssignmentCoordinatorTask
* `MessagesToSend/ImpactLineSearchTask_21.xml` - an IMPACT line search task.
* `MessagesToSend/KeepOutZone_??.xml` - polygons that represent areas that the vehicle are not to enter.
* `MessagesToSend/LineOfInterest_101.xml` - points of the line for ImpactLineSearchTask_21.
* `MessagesToSend/LineSearchTask_??.xml` - a CMASI line search task.
* `MessagesToSend/OperatingRegion_100.xml` - the operating region, i.e. set of keep-in and keep-out tasks, to be used in the assignment.

## Modification to Suit Your Environment

The configuration files cfgDistributedCooperation_1000-host.xml and cfgDistributedCooperation_2000-xu4.xml need to have the identified network addresses and interface names changed
to match the network topology for your local site.  Note the the ZyreMQ bridge operates only on a single ethernet segment.  Accordingly, both the host and the ODROID target must be
connected to the same ethernet segment.  At line 9 of the configuration host configuration file cfgDistributedCooperation_1000-host.xml the `NetworkDevice` should be changed to the
name of the interface for the ethernet segment on which both the host and ODROID target are connected.  At line 15 of the target configuration file cfgDistributedCooperation_2000-xu4.xml,
the `TcpAddress` should be changed to match the IP address of the host interface of the IP subnetwork on which both the host and the target are connected.

## Running the Example:

1. on the target, open a ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/03_Example_DistributedCooperation/"
2. and enter the command: `./runUxAS_DistributedCooperation-xu4.sh`
3. on the host, open a ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/03_Example_DistributedCooperation/"
4. and enter the command: `./runUxAS_DistributedCooperation-host.sh`
5. on the host open another ternimal window in the directory: "examples/CASE-TA6-Challenge-Problems/01_Zeroize/03_Example_DistributedCooperation/"
6. and enter the command: `./runAMASE_DistributedCooperation.sh`
7. start the Amase simulation (i.e. push the play button)

### What Happens?
* Two console windows will open, each will have UxAS running.
* 2 seconds after the simulation starts, a ZeroizeCondition messages is sent to the UxAS instance on the target
## FOR EACH COPY OF UxAS ##
* By the end of the first second, all air vehicle configurations and states, as well as all tasks and associated messages are sent in to UxAS using the 'SendMessages' service.
* Each 'LmcpObjectNetworkZeroMqZyreBridge' will make a connection with the other copy of UxAS.
* At two seconds an air vehicle state, corresponding to the entity ID, is sent to UxAS. This state must be sent to UxAS after the assignment coordinator task, so the task has an air vehicle state from the local vehicle.
* At five seconds the coordinated automation request is sent in which starts the assignment process.
* After receiving the coordinated automation request, the assignment coordinator task send out an 'AssignmentCoordination' message containg the state that the local vehicle will use for planning.
* The 'AssignmentCoordination' is picked up by the 'LmcpObjectNetworkZeroMqZyreBridge' and sent to the other running copy of UxAS
* The assignment coordinator recieves the 'AssignmentCoordination' message from the UxAS and checks to see if its time to send in a TaskAutomationRequest. The 'CoordinatedAutomationRequest' specifies three vehicle IDs and since the the third vehicle is not present, the assignment coordinator must wait untile the specified has passed, 10 seconds from recipt of the request, to sent out the 'TaskAutomationRequest'.
* Once the timer has expired, a 'TaskAutomationRequest' specifing two vheicles is sent out. This causes the UxAS services to calculate assignments for both vehicle.
* The resulting assignment can be plotted using the python scripts located in the sub-directory of '03_Example_DistributedCooperation/UAV_1000/datawork/AutomationDiagramDataService/'
* As the search progresses, the UAV will cross throug a KeepOutZone identified in the ZeroizeCondition and at this point ZeroizationCommands will be issued.

