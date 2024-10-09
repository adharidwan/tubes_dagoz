#include "rclcpp/rclcpp.hpp"
#include "tubes_dagoz_msgs/msg/hardware_command.hpp"
#include "control/control_node.hpp"


class ControlNode : public rclcpp::Node {
public:
    ControlNode() : Node("control_node") {
        publisher_ = this->create_publisher<tubes_dagoz_msgs::msg::HardwareCommand>("/control/command/hardware", 1);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&ControlNode::control_callback, this));
    }

private:
    void control_callback() {
        auto message = tubes_dagoz_msgs::msg::HardwareCommand();
        
        message.motor1 = 0.1; 
        message.motor2 = -0.1;
        message.motor3 = 0.1;
        message.motor4 = -0.1;
        
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Published motor commands: motor1 = %f, motor2 = %f, motor3 = %f, motor4 = %f", 
                    message.motor1, message.motor2, message.motor3, message.motor4);
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
