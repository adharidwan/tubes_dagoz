// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "msgs/msg/hardware_command.hpp"


#ifndef MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_HPP_
#define MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msgs__msg__HardwareCommand __attribute__((deprecated))
#else
# define DEPRECATED__msgs__msg__HardwareCommand __declspec(deprecated)
#endif

namespace msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HardwareCommand_
{
  using Type = HardwareCommand_<ContainerAllocator>;

  explicit HardwareCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor1 = 0.0f;
      this->motor2 = 0.0f;
      this->motor3 = 0.0f;
      this->motor4 = 0.0f;
    }
  }

  explicit HardwareCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor1 = 0.0f;
      this->motor2 = 0.0f;
      this->motor3 = 0.0f;
      this->motor4 = 0.0f;
    }
  }

  // field types and members
  using _motor1_type =
    float;
  _motor1_type motor1;
  using _motor2_type =
    float;
  _motor2_type motor2;
  using _motor3_type =
    float;
  _motor3_type motor3;
  using _motor4_type =
    float;
  _motor4_type motor4;

  // setters for named parameter idiom
  Type & set__motor1(
    const float & _arg)
  {
    this->motor1 = _arg;
    return *this;
  }
  Type & set__motor2(
    const float & _arg)
  {
    this->motor2 = _arg;
    return *this;
  }
  Type & set__motor3(
    const float & _arg)
  {
    this->motor3 = _arg;
    return *this;
  }
  Type & set__motor4(
    const float & _arg)
  {
    this->motor4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs::msg::HardwareCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs::msg::HardwareCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs::msg::HardwareCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs::msg::HardwareCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs::msg::HardwareCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::HardwareCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs::msg::HardwareCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs::msg::HardwareCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs::msg::HardwareCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs::msg::HardwareCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs__msg__HardwareCommand
    std::shared_ptr<msgs::msg::HardwareCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs__msg__HardwareCommand
    std::shared_ptr<msgs::msg::HardwareCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HardwareCommand_ & other) const
  {
    if (this->motor1 != other.motor1) {
      return false;
    }
    if (this->motor2 != other.motor2) {
      return false;
    }
    if (this->motor3 != other.motor3) {
      return false;
    }
    if (this->motor4 != other.motor4) {
      return false;
    }
    return true;
  }
  bool operator!=(const HardwareCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HardwareCommand_

// alias to use template instance with default allocator
using HardwareCommand =
  msgs::msg::HardwareCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__HARDWARE_COMMAND__STRUCT_HPP_
