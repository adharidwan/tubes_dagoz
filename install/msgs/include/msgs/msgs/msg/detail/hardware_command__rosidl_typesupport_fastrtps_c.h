// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice
#ifndef MSGS__MSG__DETAIL__HARDWARE_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define MSGS__MSG__DETAIL__HARDWARE_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "msgs/msg/detail/hardware_command__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
bool cdr_serialize_msgs__msg__HardwareCommand(
  const msgs__msg__HardwareCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
bool cdr_deserialize_msgs__msg__HardwareCommand(
  eprosima::fastcdr::Cdr &,
  msgs__msg__HardwareCommand * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t get_serialized_size_msgs__msg__HardwareCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t max_serialized_size_msgs__msg__HardwareCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
bool cdr_serialize_key_msgs__msg__HardwareCommand(
  const msgs__msg__HardwareCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t get_serialized_size_key_msgs__msg__HardwareCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
size_t max_serialized_size_key_msgs__msg__HardwareCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, msgs, msg, HardwareCommand)();

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__HARDWARE_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
