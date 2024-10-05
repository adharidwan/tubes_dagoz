// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

#include "msgs/msg/detail/hardware_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_msgs
const rosidl_type_hash_t *
msgs__msg__HardwareCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x85, 0x5e, 0x55, 0x34, 0xc9, 0xe2, 0xe2, 0x99,
      0x9c, 0x0e, 0xce, 0x95, 0x61, 0xc7, 0xfa, 0xff,
      0xe6, 0x49, 0xd3, 0x00, 0xb9, 0xb1, 0xdc, 0xea,
      0xe5, 0x3b, 0xeb, 0x34, 0xf2, 0x3f, 0xcb, 0x32,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char msgs__msg__HardwareCommand__TYPE_NAME[] = "msgs/msg/HardwareCommand";

// Define type names, field names, and default values
static char msgs__msg__HardwareCommand__FIELD_NAME__motor1[] = "motor1";
static char msgs__msg__HardwareCommand__FIELD_NAME__motor2[] = "motor2";
static char msgs__msg__HardwareCommand__FIELD_NAME__motor3[] = "motor3";
static char msgs__msg__HardwareCommand__FIELD_NAME__motor4[] = "motor4";

static rosidl_runtime_c__type_description__Field msgs__msg__HardwareCommand__FIELDS[] = {
  {
    {msgs__msg__HardwareCommand__FIELD_NAME__motor1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__HardwareCommand__FIELD_NAME__motor2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__HardwareCommand__FIELD_NAME__motor3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {msgs__msg__HardwareCommand__FIELD_NAME__motor4, 6, 6},
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
msgs__msg__HardwareCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {msgs__msg__HardwareCommand__TYPE_NAME, 24, 24},
      {msgs__msg__HardwareCommand__FIELDS, 4, 4},
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
msgs__msg__HardwareCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {msgs__msg__HardwareCommand__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 59, 59},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
msgs__msg__HardwareCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *msgs__msg__HardwareCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
