// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from control:msg/Frame.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "control/msg/frame.hpp"


#ifndef CONTROL__MSG__DETAIL__FRAME__BUILDER_HPP_
#define CONTROL__MSG__DETAIL__FRAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "control/msg/detail/frame__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace control
{

namespace msg
{

namespace builder
{

class Init_Frame_data
{
public:
  explicit Init_Frame_data(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  ::control::msg::Frame data(::control::msg::Frame::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_dlc
{
public:
  explicit Init_Frame_dlc(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_data dlc(::control::msg::Frame::_dlc_type arg)
  {
    msg_.dlc = std::move(arg);
    return Init_Frame_data(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_is_error
{
public:
  explicit Init_Frame_is_error(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_dlc is_error(::control::msg::Frame::_is_error_type arg)
  {
    msg_.is_error = std::move(arg);
    return Init_Frame_dlc(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_is_extended
{
public:
  explicit Init_Frame_is_extended(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_error is_extended(::control::msg::Frame::_is_extended_type arg)
  {
    msg_.is_extended = std::move(arg);
    return Init_Frame_is_error(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_is_rtr
{
public:
  explicit Init_Frame_is_rtr(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_extended is_rtr(::control::msg::Frame::_is_rtr_type arg)
  {
    msg_.is_rtr = std::move(arg);
    return Init_Frame_is_extended(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_id
{
public:
  explicit Init_Frame_id(::control::msg::Frame & msg)
  : msg_(msg)
  {}
  Init_Frame_is_rtr id(::control::msg::Frame::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Frame_is_rtr(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

class Init_Frame_header
{
public:
  Init_Frame_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Frame_id header(::control::msg::Frame::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Frame_id(msg_);
  }

private:
  ::control::msg::Frame msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::control::msg::Frame>()
{
  return control::msg::builder::Init_Frame_header();
}

}  // namespace control

#endif  // CONTROL__MSG__DETAIL__FRAME__BUILDER_HPP_
