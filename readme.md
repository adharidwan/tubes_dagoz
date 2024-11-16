# TUBES PROGRAMMING KRU 16 DAGOZILLA

"#mainbersih" - Rimba Harits Hartanto 2024

## Table of Contents

- [KRU 16](#kru-16)
- [General Information](#general-information)
- [Technologies Used](#technologies-used)
- [Features](#features)
- [Setup](#setup)
- [How-to-use](#how-to-use)
- [Structure](#structure)

## KRU 16

1. Alya Zahra Raisa Rahma
2. Bevinda Vivian
3. Kesha Mufrih Ramadhan
4. Muhammad Adha Ridwan
5. Sabilul Huda 

## General Information

Simple control package for locomotion and expanding arm 

## Technologies Used

- C++
- ROS2 - Jazzy

## Features

- Simple Movement using  W,A,S,D Key.
- Expand and Retract Arm using RIGHT,LEFT,UP Key.

## Setup

- Setup ROS2 Jazzy Enviroment (https://docs.ros.org/en/jazzy/Installation.html)
- Download all folder and files on this repository or simply clone this repo!
- Download Autoware's CAN Message Wrapper, Choose Jazzy := ros2_socketcan & ros2_socketcan_msg (https://github.com/autowarefoundation/ros2_socketcan)
- Download Dependencies, Choose Dashing := can_msgs (https://github.com/ros-industrial/ros_canopen)

## How-to-use

    git clone https://github.com/adharidwan/tubes_dagoz.git
    cd tubes_dagoz
    cd src
    make a new directories named ros2_socketcan then put ros2_socketcan,ros2_socketcan_msg and can_msgs package inside
    make sure ros2_socketcan looks like this:
    ├── src              
    |   └── ros2_socketcan  
    |       └── ros2_socketcan
    |       └── ros2_socketcan_msgs
    |       └── can_msgs
    colcon build
    ros2 launch control my_launch_file.launch.py

## Structure

```
├── src                 # contains all package
│   └── control         # contain all control node and code    
|   └── launch          # contain launch package 
|   └── ros2_socketcan  # contain autoware's ros2_socketcan wrapper for can_massage (https://github.com/autowarefoundation/ros2_socketcan)
|       └── ros2_socketcan
|       └── ros2_socketcan_msgs
|       └── can_msgs
└── README.md           # documentation
└── .gitignore          # gitignore for launch,build,log and vscode settings
```

## Feature Documentation

### Movements

Ensure all packages are successfully built with colcon build, and that the ROS 2 Jazzy environment is set up.

Locomotion Controls
 1. Basic Movement:

    - Use the following keys to control the robot's movement:
      - W: Move Forward
      - A: Move Left
      - S: Move Backward
      - D: Move Right
    - These controls enable basic movement for navigating the robot.
    
2. Running the Locomotion Nodes:
    - Launch the keyboard_input node to enable keyboard controls:
        ros2 run control keyboard_input
    - Then, in a separate terminal, run the translator_locomotion node to translate the keyboard inputs         into movement actions:
        ros2 run control translator_locomotion
   
Expanding and Retracting Arm Controls
1. Arm Controls:

    - Use the following keys to control the arm:
      - UP Arrow: Extend arm
      - DOWN Arrow: Retract arm
      - RIGHT Arrow: Move arm to the right
      - LEFT Arrow: Move arm to the left
    - This allows smooth extension, retraction, and horizontal movement of the arm.

2. Running the Arm Control Node:

- Start the translator_expanding node in a new terminal to handle arm control commands:
      ros2 run control translator_expanding
  
3. Testing the Controls:

- After launching all nodes (keyboard_input, translator_locomotion, and translator_expanding), test each movement and arm control to ensure they respond correctly. Recommended to use tmux

