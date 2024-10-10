#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "can_msgs/msg/frame.hpp"
#include <iostream>
#include <cstdint>

union FloatBytes {
    float floatValue;
    uint8_t byteArray[4];
};


class VelocitySubscriber : public rclcpp::Node
{
public:
    VelocitySubscriber()
    : Node("translator_node")
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

        twist_to_vel(linear_x, linear_y);
    }

    void twist_to_vel(double linear_x, double linear_y) const
    { 

        float vel_motor1 = linear_x;
        float vel_motor2 = linear_y;
        float vel_motor3 = linear_x;
        float vel_motor4 = linear_y;

        auto can_msg1 = can_msgs::msg::Frame();

        can_msg1.id = 0x123;
        can_msg1.dlc = 8;    

        can_msg1.data[0] = vel_motor1;
        can_msg1.data[1] = vel_motor2;
        can_msg1.data[2] = vel_motor3;
        can_msg1.data[3] = vel_motor4;

        uint8_t motor1[4];
        float_to_hex(-23.75,motor1);
        can_msg1.data[0] = motor1[0];
        can_msg1.data[1] = motor1[1];
        can_msg1.data[2] = motor1[2];
        can_msg1.data[3] = motor1[3];
        
        uint8_t motor2[4];
        float_to_hex(-21.5,motor2);
        can_msg1.data[4] = motor2[0];
        can_msg1.data[5] = motor2[1];
        can_msg1.data[6] = motor2[2];
        can_msg1.data[7] = motor2[3];
        can_publisher_->publish(can_msg1);
    }

    void float_to_hex(double vel, uint8_t* buffer) const {
        FloatBytes converter;
        converter.floatValue = vel;
        for(int i = 0 ; i < 4;i++){
            buffer[i] = converter.byteArray[i];
        }
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
