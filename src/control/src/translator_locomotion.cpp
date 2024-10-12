#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "can_msgs/msg/frame.hpp"
#include <iostream>
#include <cstdint>
#include <cmath>

#define motor1_angle 225.00
#define motor2_angle 135.00
#define motor3_angle 315.00
#define motor4_angle 45.00
#define TO_RADIANS(degrees) ((degrees) * (M_PI / 180.0))



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

        // RCLCPP_INFO(this->get_logger(), "Linear Velocity X: %.2f, Linear Velocity Y: %.2f", linear_x, linear_y);

        twist_to_vel(linear_x, linear_y);
    }

    void twist_to_vel(double linear_x, double linear_y) const
    { 
        auto can_msg1 = can_msgs::msg::Frame();
        auto can_msg2 = can_msgs::msg::Frame();
        double scalingFactor = 1.0/cos(TO_RADIANS(motor4_angle));
        can_msg1.id = 0x123;
        can_msg2.id = 0x124;
        can_msg1.dlc = 8;
        can_msg2.dlc = 8;
        
        double motor1_vel = (linear_x * sin(TO_RADIANS(motor1_angle))) + (linear_y * cos(TO_RADIANS(motor1_angle)));
        double motor2_vel = (linear_x * sin(TO_RADIANS(motor2_angle))) + (linear_y * cos(TO_RADIANS(motor2_angle)));
        double motor3_vel = (linear_x * sin(TO_RADIANS(motor3_angle))) + (linear_y * cos(TO_RADIANS(motor3_angle)));
        double motor4_vel = (linear_x * sin(TO_RADIANS(motor4_angle))) + (linear_y * cos(TO_RADIANS(motor4_angle)));
        motor1_vel = motor1_vel / scalingFactor * 2;
        motor2_vel = motor2_vel / scalingFactor * 2;
        motor3_vel = motor3_vel / scalingFactor * 2;
        motor4_vel = motor4_vel / scalingFactor * 2;

        if(motor1_vel == -0.00) motor1_vel = 0.00;
        
        RCLCPP_INFO(this->get_logger(), "Motor1 Velocity : %.2f, Motor2 Velocity : %.2f, Motor3 Velocity : %.2f, Motor4 Velocity : %.2f", motor1_vel, motor2_vel, motor3_vel, motor4_vel);


        uint8_t motor1[4];
        float_to_hex(motor1_vel,motor1);
        can_msg1.data[0] = motor1[0];
        can_msg1.data[1] = motor1[1];
        can_msg1.data[2] = motor1[2];
        can_msg1.data[3] = motor1[3];
        
        uint8_t motor2[4];
        float_to_hex(motor2_vel,motor2);
        can_msg1.data[4] = motor2[0];
        can_msg1.data[5] = motor2[1];
        can_msg1.data[6] = motor2[2];
        can_msg1.data[7] = motor2[3];

        uint8_t motor3[4];
        float_to_hex(motor3_vel,motor3);
        can_msg2.data[0] = motor3[0];
        can_msg2.data[1] = motor3[1];
        can_msg2.data[2] = motor3[2];
        can_msg2.data[3] = motor3[3];


        uint8_t motor4[4];
        float_to_hex(motor4_vel,motor4);
        can_msg2.data[4] = motor4[0];
        can_msg2.data[5] = motor4[1];
        can_msg2.data[6] = motor4[2];
        can_msg2.data[7] = motor4[3];


        can_publisher_->publish(can_msg2);
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
