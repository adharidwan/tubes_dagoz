// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "msgs/msg/hardware_command.hpp"


#ifndef MSGS__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_
#define MSGS__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs/msg/detail/hardware_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HardwareCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor1
  {
    out << "motor1: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1, out);
    out << ", ";
  }

  // member: motor2
  {
    out << "motor2: ";
    rosidl_generator_traits::value_to_yaml(msg.motor2, out);
    out << ", ";
  }

  // member: motor3
  {
    out << "motor3: ";
    rosidl_generator_traits::value_to_yaml(msg.motor3, out);
    out << ", ";
  }

  // member: motor4
  {
    out << "motor4: ";
    rosidl_generator_traits::value_to_yaml(msg.motor4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HardwareCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor1: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1, out);
    out << "\n";
  }

  // member: motor2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor2: ";
    rosidl_generator_traits::value_to_yaml(msg.motor2, out);
    out << "\n";
  }

  // member: motor3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor3: ";
    rosidl_generator_traits::value_to_yaml(msg.motor3, out);
    out << "\n";
  }

  // member: motor4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor4: ";
    rosidl_generator_traits::value_to_yaml(msg.motor4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HardwareCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msgs

namespace rosidl_generator_traits
{

[[deprecated("use msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msgs::msg::HardwareCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs::msg::HardwareCommand & msg)
{
  return msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs::msg::HardwareCommand>()
{
  return "msgs::msg::HardwareCommand";
}

template<>
inline const char * name<msgs::msg::HardwareCommand>()
{
  return "msgs/msg/HardwareCommand";
}

template<>
struct has_fixed_size<msgs::msg::HardwareCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msgs::msg::HardwareCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msgs::msg::HardwareCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_
