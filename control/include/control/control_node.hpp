#ifndef CONTROL_NODE_HPP
#define CONTROL_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "tubes_dagoz_msgs/msg/hardware_command.hpp"

class ControlNode : public rclcpp::Node {
public:
    ControlNode();

private:
    void control_callback();
    rclcpp::Publisher<tubes_dagoz_msgs::msg::HardwareCommand>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // CONTROL_NODE_HPP
