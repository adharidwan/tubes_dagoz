cmake_minimum_required(VERSION 3.8)
project(control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(can_msgs REQUIRED)

# find_package(tutorial_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(include)
include_directories(include ${ncurses_INCLUDE_DIRS})

add_executable(keyboard_input src/keyboard_input.cpp)
ament_target_dependencies(keyboard_input rclcpp geometry_msgs)
target_link_libraries(keyboard_input ncurses)
ament_export_dependencies(rosidl_default_runtime)

add_executable(translator_node src/translator_node.cpp)
ament_target_dependencies(translator_node rclcpp geometry_msgs can_msgs msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  keyboard_input
  translator_node
  DESTINATION lib/${PROJECT_NAME})

# install(DIRECTORY msg
#   DESTINATION share/${PROJECT_NAME})


# rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} rosidl_typesupport_cpp)
# target_link_libraries(cmd_translate "${cpp_typesupport_target}")

ament_package()
