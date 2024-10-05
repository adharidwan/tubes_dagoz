// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "msgs/msg/detail/hardware_command__struct.h"
#include "msgs/msg/detail/hardware_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool msgs__msg__hardware_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("msgs.msg._hardware_command.HardwareCommand", full_classname_dest, 42) == 0);
  }
  msgs__msg__HardwareCommand * ros_message = _ros_message;
  {  // motor1
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor2
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor3
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // motor4
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->motor4 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * msgs__msg__hardware_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of HardwareCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("msgs.msg._hardware_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "HardwareCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  msgs__msg__HardwareCommand * ros_message = (msgs__msg__HardwareCommand *)raw_ros_message;
  {  // motor1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motor4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->motor4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
