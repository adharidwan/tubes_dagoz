from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='control',
            namespace='Maxwell',
            executable='keyboard_input',
            name='keyboard_input_node'
        ),
        Node(
            package='control',
            namespace='Maxwell',
            executable='translator_locomotion',
            name='translator_node'
        ),
        Node(
            package='control',
            namespace='Maxwell',
            executable='translator_expanding',
            name='goalkeeper_arm_mover'
        )
    ])