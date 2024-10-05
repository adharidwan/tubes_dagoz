// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "msgs/msg/hardware_command.h"


#ifndef MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_
#define MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/HardwareCommand in the package msgs.
typedef struct msgs__msg__HardwareCommand
{
  float motor1;
  float motor2;
  float motor3;
  float motor4;
} msgs__msg__HardwareCommand;

// Struct for a sequence of msgs__msg__HardwareCommand.
typedef struct msgs__msg__HardwareCommand__Sequence
{
  msgs__msg__HardwareCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs__msg__HardwareCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_
