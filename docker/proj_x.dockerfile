FROM ros:humble
WORKDIR /workspace
COPY . /workspace
RUN apt-get update && \
  apt-get install -y git && \
  source /opt/ros/humble/setup.bash && \
  cd /workspace/modules/module_interface && \
  colcon build && \
  source install/setup.bash && \
  cd ../module_x && \
  colcon build && \
  source install/setup.bash && \
  ros2 launch module_x launch_module_x.py

