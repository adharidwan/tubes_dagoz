// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from control:msg/Frame.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control/msg/frame.h"


#ifndef CONTROL__MSG__DETAIL__FRAME__STRUCT_H_
#define CONTROL__MSG__DETAIL__FRAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Frame in the package control.
typedef struct control__msg__Frame
{
  std_msgs__msg__Header header;
  uint32_t id;
  bool is_rtr;
  bool is_extended;
  bool is_error;
  uint8_t dlc;
  uint8_t data[8];
} control__msg__Frame;

// Struct for a sequence of control__msg__Frame.
typedef struct control__msg__Frame__Sequence
{
  control__msg__Frame * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} control__msg__Frame__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CONTROL__MSG__DETAIL__FRAME__STRUCT_H_
