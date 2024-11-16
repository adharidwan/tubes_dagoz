from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    # Create a temporary layout config file
    config_content = """
[layouts]
  [[default]]
    [[[window0]]]
      type = Window
      parent = ""
      size = 1000, 600
    [[[child1]]]
      type = VPaned
      parent = window0
      position = 300
    [[[child2]]]
      type = HPaned
      parent = child1
      position = 500
    [[[terminal1]]]
      type = Terminal
      parent = child2
      profile = default
      command = "bash -c 'echo \"Keyboard Input Node\" && ros2 run control keyboard_input; exec bash'"
    [[[terminal2]]]
      type = Terminal
      parent = child2
      profile = default
      command = "bash -c 'echo \"Translator Locomotion Node\" && ros2 run control translator_locomotion; exec bash'"
    [[[terminal3]]]
      type = Terminal
      parent = child1
      profile = default
      command = "bash -c 'echo \"Goalkeeper Arm Node\" && ros2 run control translator_expanding; exec bash'"
"""
    
    # Write the config to a temporary file
    config_path = "/tmp/terminator_layout.conf"
    with open(config_path, "w") as f:
        f.write(config_content)
    
    # Command to launch terminator with the config
    terminator_cmd = f"terminator -l default -g {config_path}"

    return LaunchDescription([
        ExecuteProcess(
            cmd=['bash', '-c', terminator_cmd],
            name='terminator_windows'
        )
    ])