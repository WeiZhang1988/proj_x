This is a simple example template with ROS2 humble and occupancy perception ground truth generation and application in network.

Currently there are module_interface, module_x, and module_y in the project as examples
module_y is specifically for occupancy.

For example template with ROS2 humble:

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

For occupancy:

The module_y covers an occupancy ground truth generation tool using semantic segmentation of lidar point cloud. Then the generated ground truth will be used by model training, etc. Detail please refer to its own docs inside module_y

