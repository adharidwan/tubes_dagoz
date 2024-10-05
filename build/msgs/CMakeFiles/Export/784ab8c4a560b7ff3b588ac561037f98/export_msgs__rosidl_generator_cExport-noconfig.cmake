#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "msgs::msgs__rosidl_generator_c" for configuration ""
set_property(TARGET msgs::msgs__rosidl_generator_c APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(msgs::msgs__rosidl_generator_c PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmsgs__rosidl_generator_c.so"
  IMPORTED_SONAME_NOCONFIG "libmsgs__rosidl_generator_c.so"
  )

list(APPEND _cmake_import_check_targets msgs::msgs__rosidl_generator_c )
list(APPEND _cmake_import_check_files_for_msgs::msgs__rosidl_generator_c "${_IMPORT_PREFIX}/lib/libmsgs__rosidl_generator_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
