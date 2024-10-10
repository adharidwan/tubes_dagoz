// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control:msg/HardwareCommand.idl
// generated code does not contain a copyright notice
#include "control/msg/detail/hardware_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
control__msg__HardwareCommand__init(control__msg__HardwareCommand * msg)
{
  if (!msg) {
    return false;
  }
  // motor1
  // motor2
  // motor3
  // motor4
  return true;
}

void
control__msg__HardwareCommand__fini(control__msg__HardwareCommand * msg)
{
  if (!msg) {
    return;
  }
  // motor1
  // motor2
  // motor3
  // motor4
}

bool
control__msg__HardwareCommand__are_equal(const control__msg__HardwareCommand * lhs, const control__msg__HardwareCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor1
  if (lhs->motor1 != rhs->motor1) {
    return false;
  }
  // motor2
  if (lhs->motor2 != rhs->motor2) {
    return false;
  }
  // motor3
  if (lhs->motor3 != rhs->motor3) {
    return false;
  }
  // motor4
  if (lhs->motor4 != rhs->motor4) {
    return false;
  }
  return true;
}

bool
control__msg__HardwareCommand__copy(
  const control__msg__HardwareCommand * input,
  control__msg__HardwareCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // motor1
  output->motor1 = input->motor1;
  // motor2
  output->motor2 = input->motor2;
  // motor3
  output->motor3 = input->motor3;
  // motor4
  output->motor4 = input->motor4;
  return true;
}

control__msg__HardwareCommand *
control__msg__HardwareCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control__msg__HardwareCommand * msg = (control__msg__HardwareCommand *)allocator.allocate(sizeof(control__msg__HardwareCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control__msg__HardwareCommand));
  bool success = control__msg__HardwareCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control__msg__HardwareCommand__destroy(control__msg__HardwareCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control__msg__HardwareCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control__msg__HardwareCommand__Sequence__init(control__msg__HardwareCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control__msg__HardwareCommand * data = NULL;

  if (size) {
    data = (control__msg__HardwareCommand *)allocator.zero_allocate(size, sizeof(control__msg__HardwareCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control__msg__HardwareCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control__msg__HardwareCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
control__msg__HardwareCommand__Sequence__fini(control__msg__HardwareCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      control__msg__HardwareCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

control__msg__HardwareCommand__Sequence *
control__msg__HardwareCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control__msg__HardwareCommand__Sequence * array = (control__msg__HardwareCommand__Sequence *)allocator.allocate(sizeof(control__msg__HardwareCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control__msg__HardwareCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control__msg__HardwareCommand__Sequence__destroy(control__msg__HardwareCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control__msg__HardwareCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control__msg__HardwareCommand__Sequence__are_equal(const control__msg__HardwareCommand__Sequence * lhs, const control__msg__HardwareCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control__msg__HardwareCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control__msg__HardwareCommand__Sequence__copy(
  const control__msg__HardwareCommand__Sequence * input,
  control__msg__HardwareCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control__msg__HardwareCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control__msg__HardwareCommand * data =
      (control__msg__HardwareCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control__msg__HardwareCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control__msg__HardwareCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control__msg__HardwareCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
