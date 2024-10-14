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
    ```
    ├── src              
    |   └── ros2_socketcan  
    |       └── ros2_socketcan
    |       └── ros2_socketcan_msgs
    |       └── can_msgs
    colcon build

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