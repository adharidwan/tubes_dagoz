// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control/msg/hardware_command.h"


#ifndef CONTROL__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_
#define CONTROL__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/HardwareCommand in the package control.
typedef struct control__msg__HardwareCommand
{
  float motor1;
  float motor2;
  float motor3;
  float motor4;
} control__msg__HardwareCommand;

// Struct for a sequence of control__msg__HardwareCommand.
typedef struct control__msg__HardwareCommand__Sequence
{
  control__msg__HardwareCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control__msg__HardwareCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_H_
