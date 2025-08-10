This is a simple example template with ROS2 humble.

Currently there is only module_interface and module_x in the project as examples
Build module_interface first
The module_x includes implementation of algorithm and component which are independent.
The component is a wrapper of the algorithm and implements lifecycle node with publiser/subsrciption, service, etc.
One publisher is managed by lifecycle management.
An independent state transition system is implemented covering states of UNCONFIGURED, STANDBY, ACTIVE, ERROR, EMERGENCY_STOP triggered by std_srvs/srv/Trigger
An action server is implemented.
Build module_x and then play around with it with the commond shown in docs/play_around.txt
Test of algorithm is implemented in test folder with google test.
Build it and run ctest can have the results.
Some errors are added purposely to make the algorithm fail. See the code for detail.

