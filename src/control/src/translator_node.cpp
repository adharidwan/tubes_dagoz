#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

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
    }

private:
    void listener_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
        double linear_x = msg->linear.x;
        double angular_z = msg->angular.z;
        RCLCPP_INFO(this->get_logger(), "Linear Velocity: %.2f, Angular Velocity: %.2f", linear_x, angular_z);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<VelocitySubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
