// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from control:msg/HardwareCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control/msg/hardware_command.hpp"


#ifndef CONTROL__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_
#define CONTROL__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "control/msg/detail/hardware_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace control
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

}  // namespace control

namespace rosidl_generator_traits
{

[[deprecated("use control::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const control::msg::HardwareCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  control::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use control::msg::to_yaml() instead")]]
inline std::string to_yaml(const control::msg::HardwareCommand & msg)
{
  return control::msg::to_yaml(msg);
}

template<>
inline const char * data_type<control::msg::HardwareCommand>()
{
  return "control::msg::HardwareCommand";
}

template<>
inline const char * name<control::msg::HardwareCommand>()
{
  return "control/msg/HardwareCommand";
}

template<>
struct has_fixed_size<control::msg::HardwareCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<control::msg::HardwareCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<control::msg::HardwareCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CONTROL__MSG__DETAIL__HARDWARE_COMMAND__TRAITS_HPP_
