#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "ros2_socketcan_msgs/msg/fd_frame.hpp"

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

        can_publisher_ = this->create_publisher<ros2_socketcan_msgs::msg::FdFrame>("to/can", 10);
    }

private:
    void listener_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {
        double linear_x = msg->linear.x;
        double linear_y = msg->linear.y;

        RCLCPP_INFO(this->get_logger(), "Linear Velocity: %.2f, Angular Velocity: %.2f", linear_x, linear_y);

        // twist_to_pwm(linear_x, angular_z);
    }

    // void twist_to_pwm(double linear_x, double angular_z) const
    // { 

    //     //float pwm_motor1 = 
    //     //float pwm_motor2 = 
    //     //float pwm_motor3 = 
    //     //float pwm_motor4 = 

    //     auto can_msg = socketcan_msgs::msg::CanMsg();
    //     // can_msg.id = can id nanti
    //     can_msg.dlc = 8;    

    //     // can_msg.data[0] = 
    //     // can_msg.data[1] = 
    //     // can_msg.data[2] = 
    //     // can_msg.data[3] = 
    //     // can_msg.data[4] = 
    //     // can_msg.data[5] = 
    //     // can_msg.data[6] = 
    //     // can_msg.data[7] = 

    //     can_publisher_->publish(can_msg);
    // }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<ros2_socketcan_msgs::msg::FdFrame>::SharedPtr can_publisher_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<VelocitySubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
