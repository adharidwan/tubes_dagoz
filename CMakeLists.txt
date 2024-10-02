cmake_minimum_required(VERSION 3.5)
project(tubes_dagoz)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tubes_dagoz_msgs REQUIRED)

add_executable(control_node src/control/control_node.cpp)
ament_target_dependencies(control_node rclcpp std_msgs tubes_dagoz_msgs)

install(TARGETS
  control_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
