cmake_minimum_required(VERSION 3.8)
project(control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(msgs REQUIRED)
find_package(ros2_socketcan REQUIRED)
find_package(rosidl_default_generators REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncurses)

include_directories(${NCURSES_INCLUDE_DIRS})
include_directories(
  include ${msgs_INCLUDE_DIRS}
)
link_directories(${NCURSES_LIBRARY_DIRS})

add_executable(keyboard_input src/keyboard_input.cpp)
add_executable(translator_node src/translator_node.cpp)

ament_target_dependencies(keyboard_input rclcpp geometry_msgs msgs)
ament_target_dependencies(translator_node rclcpp geometry_msgs ros2_socketcan msgs)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

target_link_libraries(keyboard_input ${NCURSES_LIBRARIES})

install(TARGETS
  keyboard_input
  translator_node
  DESTINATION lib/${PROJECT_NAME}
)



ament_package()
