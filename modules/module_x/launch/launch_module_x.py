from launch import LaunchDescription
from launch_ros.actions import LifecycleNode

def generate_launch_description():
  return LaunchDescription([
    LifecycleNode(
      package='module_x',
      executable='component_x',
      name='algorithm_x_wrapper',
      namespace='',
      output='screen',
      parameters=[
        {'config_file': '../config/params.yaml'}
      ]
    )
])