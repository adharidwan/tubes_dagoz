// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "msgs/msg/hardware_command.hpp"


#ifndef MSGS__MSG__DETAIL__HARDWARE_COMMAND__BUILDER_HPP_
#define MSGS__MSG__DETAIL__HARDWARE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/hardware_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_HardwareCommand_motor4
{
public:
  explicit Init_HardwareCommand_motor4(::msgs::msg::HardwareCommand & msg)
  : msg_(msg)
  {}
  ::msgs::msg::HardwareCommand motor4(::msgs::msg::HardwareCommand::_motor4_type arg)
  {
    msg_.motor4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::HardwareCommand msg_;
};

class Init_HardwareCommand_motor3
{
public:
  explicit Init_HardwareCommand_motor3(::msgs::msg::HardwareCommand & msg)
  : msg_(msg)
  {}
  Init_HardwareCommand_motor4 motor3(::msgs::msg::HardwareCommand::_motor3_type arg)
  {
    msg_.motor3 = std::move(arg);
    return Init_HardwareCommand_motor4(msg_);
  }

private:
  ::msgs::msg::HardwareCommand msg_;
};

class Init_HardwareCommand_motor2
{
public:
  explicit Init_HardwareCommand_motor2(::msgs::msg::HardwareCommand & msg)
  : msg_(msg)
  {}
  Init_HardwareCommand_motor3 motor2(::msgs::msg::HardwareCommand::_motor2_type arg)
  {
    msg_.motor2 = std::move(arg);
    return Init_HardwareCommand_motor3(msg_);
  }

private:
  ::msgs::msg::HardwareCommand msg_;
};

class Init_HardwareCommand_motor1
{
public:
  Init_HardwareCommand_motor1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HardwareCommand_motor2 motor1(::msgs::msg::HardwareCommand::_motor1_type arg)
  {
    msg_.motor1 = std::move(arg);
    return Init_HardwareCommand_motor2(msg_);
  }

private:
  ::msgs::msg::HardwareCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::HardwareCommand>()
{
  return msgs::msg::builder::Init_HardwareCommand_motor1();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__HARDWARE_COMMAND__BUILDER_HPP_
