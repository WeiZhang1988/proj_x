FROM ros:humble
# refer to docs/env_setup.txt for setting docker environment with nvidia gpu.
# here we suppose nvidia gpu works in docker
WORKDIR /workspace
COPY . /workspace
RUN apt-get update
RUN apt-get install -y git
RUN source /opt/ros/humble/setup.bash
RUN cd /workspace/modules/module_interface
RUN colcon build
RUN source install/setup.bash
RUN cd ../module_x
RUN colcon build
RUN source install/setup.bash
RUN ros2 launch module_x launch_module_x.py

RUN cd ../module_y
RUN apt-get install -y python3.10
RUN pip3 install -r requirements.txt
RUN cd extensions/chamfer_dist
RUN python3 setup.py install
RUN cd ../..
RUN python3 tools/generate_occupancy_nuscenes.py
RUN python3 tools/train.py
