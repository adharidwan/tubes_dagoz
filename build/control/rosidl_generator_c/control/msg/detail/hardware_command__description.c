// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from control:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

#include "control/msg/detail/hardware_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_control
const rosidl_type_hash_t *
control__msg__HardwareCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xab, 0xb0, 0xda, 0x66, 0xd8, 0x5e, 0xe1, 0xb6,
      0x7d, 0xbe, 0xb1, 0xa5, 0x3a, 0x5a, 0x46, 0xcd,
      0x3c, 0xbc, 0xb8, 0xf8, 0x49, 0xcb, 0xa7, 0x67,
      0x53, 0xe2, 0x9d, 0x39, 0x0a, 0x44, 0xfc, 0x62,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char control__msg__HardwareCommand__TYPE_NAME[] = "control/msg/HardwareCommand";

// Define type names, field names, and default values
static char control__msg__HardwareCommand__FIELD_NAME__motor1[] = "motor1";
static char control__msg__HardwareCommand__FIELD_NAME__motor2[] = "motor2";
static char control__msg__HardwareCommand__FIELD_NAME__motor3[] = "motor3";
static char control__msg__HardwareCommand__FIELD_NAME__motor4[] = "motor4";

static rosidl_runtime_c__type_description__Field control__msg__HardwareCommand__FIELDS[] = {
  {
    {control__msg__HardwareCommand__FIELD_NAME__motor1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {control__msg__HardwareCommand__FIELD_NAME__motor2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {control__msg__HardwareCommand__FIELD_NAME__motor3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {control__msg__HardwareCommand__FIELD_NAME__motor4, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
control__msg__HardwareCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {control__msg__HardwareCommand__TYPE_NAME, 27, 27},
      {control__msg__HardwareCommand__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 motor1\n"
  "float32 motor2\n"
  "float32 motor3\n"
  "float32 motor4";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
control__msg__HardwareCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {control__msg__HardwareCommand__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 59, 59},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
control__msg__HardwareCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *control__msg__HardwareCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
