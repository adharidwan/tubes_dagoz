#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "can_msgs/msg/frame.hpp"

const int MAX_PWM = 255;

class VelocitySubscriber : public rclcpp::Node
{
public:
    VelocitySubscriber()
    : Node("velocity_subscriber")
    {
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "cmd_vel",
            10,
            std::bind(&VelocitySubscriber::listener_callback, this, std::placeholders::_1));

        can_publisher_ = this->create_publisher<can_msgs::msg::Frame>("/to_can_bus", 10);
    }

private:
    void listener_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
        double linear_x = msg->linear.x;
        double linear_y = msg->linear.y;

        RCLCPP_INFO(this->get_logger(), "Linear Velocity X: %.2f, Linear Velocity Y: %.2f", linear_x, linear_y);

        twist_to_pwm(linear_x, linear_y);
    }

    void twist_to_pwm(double linear_x, double linear_y) const
    { 

        float vel_motor1 = linear_x;
        float vel_motor2 = linear_y;
        float vel_motor3 = linear_x;
        float vel_motor4 = linear_y;

        auto can_msg = can_msgs::msg::Frame();
        can_msg.id = 0x123;
        can_msg.dlc = 8;    

        can_msg.data[0] = vel_motor1;
        can_msg.data[1] = vel_motor1;
        can_msg.data[2] = vel_motor2;
        can_msg.data[3] = vel_motor2;
        can_msg.data[4] = vel_motor3;
        can_msg.data[5] = vel_motor3;
        can_msg.data[6] = vel_motor4;
        can_msg.data[7] = vel_motor4;
        can_publisher_->publish(can_msg);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<can_msgs::msg::Frame>::SharedPtr can_publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<VelocitySubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
