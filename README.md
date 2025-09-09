This project has two main goals:

1, to provide a simple example template with ROS2 humble;

2, to practice occupancy perception ground truth generation and application in network.

Currently there are module_interface, module_x, and module_y in the project as examples

module_interface and module_x are for example template topic.
module_y is for occupancy perception topic.

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

For occupancy perception:

The module_y implements a pipeline of occupancy ground truth generation based on semantic segmentation of lidar point cloud. 
Nuscenes mini dataset is used for the generation and further network training.
A series of dummy nueral network are implemented to utilize the generated data for training.
Files are orgnized based on their functions. Detail report please refer to docs inside module_y.

