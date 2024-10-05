// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from control:msg/Frame.idl
// generated code does not contain a copyright notice
#ifndef CONTROL__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CONTROL__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "control/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "control/msg/detail/frame__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
bool cdr_serialize_control__msg__Frame(
  const control__msg__Frame * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
bool cdr_deserialize_control__msg__Frame(
  eprosima::fastcdr::Cdr &,
  control__msg__Frame * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
size_t get_serialized_size_control__msg__Frame(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
size_t max_serialized_size_control__msg__Frame(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
bool cdr_serialize_key_control__msg__Frame(
  const control__msg__Frame * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
size_t get_serialized_size_key_control__msg__Frame(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
size_t max_serialized_size_key_control__msg__Frame(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_control
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, control, msg, Frame)();

#ifdef __cplusplus
}
#endif

#endif  // CONTROL__MSG__DETAIL__FRAME__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
