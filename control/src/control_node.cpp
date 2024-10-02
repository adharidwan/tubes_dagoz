#include "rclcpp/rclcpp.hpp"
#include "tubes_dagoz_msgs/msg/hardware_command.hpp"
#include "control/control_node.hpp"

class ControlNode : public rclcpp::Node {
public:
    ControlNode() : Node("control_node") {
        publisher_ = this->create_publisher<tubes_dagoz_msgs::msg::HardwareCommand>("/control/command/hardware", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&ControlNode::control_callback, this));
    }

private:
    void control_callback() {
        auto message = tubes_dagoz_msgs::msg::HardwareCommand();
        message.motor1 = 0.5;
        message.motor2 = 0.5;
        message.motor3 = 0.5;
        message.motor4 = 0.5;
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Published motor commands.");
    }

    rclcpp::Publisher<tubes_dagoz_msgs::msg::HardwareCommand>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControlNode>());
    rclcpp::shutdown();
    return 0;
}