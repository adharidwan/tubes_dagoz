#include <chrono>
#include <memory>
#include <iostream>
#include <cstdint>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

union FloatToBytes {
    float floatValue;
    uint8_t byteArray[4];
};

class TranslatorNode : public rclcpp::Node
{
public:
  TranslatorNode() : Node("translator_node")
  {

    // subscribe to cmd_vel
    subscription_ = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", 10, std::bind(&TranslatorNode::cmd_vel_callback, this, std::placeholders::_1));
    // publish to /to_can_bus
    publisher_ = this->create_publisher<can_msgs::msg::Frame>("to_can_bus", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1000),
        std::bind(&TranslatorNode::CanPublisher, this));
  }

private:
  // geometry_msgs::msg::Twist::SharedPtr latest_cmd_vel_msg_;

  // void timer_callback(){
  //   if (latest_cmd_vel_msg_){
  //     cmd_vel_callback(latest_cmd_vel_msg_);
  //   }
  //   else{
  //     RCLCPP_WARN(this->get_logger(), "No cmd_vel message received yet");
  //   }
  // }
  
  void CanPublisher()
  {
  //  RCLCPP_INFO(this->get_logger(), "Received cmd_vel message \n");

    auto frame = can_msgs::msg::Frame();

    // Extract velocities
    double linear_x = msg->linear.x;
    double linear_y = msg->linear.y;
    double angular_z = msg->angular.z;

    sendtocan.id = 0x130;
    frame.dlc = 8;

    frame.data[0] = 0xDE;  // Example data
    frame.data[1] = 0xAD;  // Example data
    frame.data[2] = 0xBE;  // Example data
    frame.data[3] = 0xEF;  // Example data
    frame.data[4] = 0x00;  // Example data
    frame.data[5] = 0x00;  // Example data
    frame.data[6] = 0x00;  // Example data
    frame.data[7] = 0x00;  // Example data

    frame.is_rtr = false;  // Not a remote transmission request
    frame.is_extended = false;  // Standard frame
    frame.is_error = false;  // Not an error frame
    

    // if (linear_x == 0 && linear_y == 0 && angular_z == 0){
    //   hardware_command.motor1 = 0.0;
    //   hardware_command.motor2 = 0.0;
    //   hardware_command.motor3 = 0.0;
    //   hardware_command.motor4 = 0.0;
    // }
    
    // else if (linear_x == 1){
    //   hardware_command.motor1 = 1.0;
    //   hardware_command.motor2 = 1.0;
    //   hardware_command.motor3 = 1.0;
    //   hardware_command.motor4 = 1.0;
    // }

    RCLCPP_INFO(this->get_logger(), "Publishing CAN frame: ID: %X", frame.id);
    publisher_->publish(message);

  };
  
  rclcpp::Publisher<can_msgs::msg::Frame>::SharedPtr publisher_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TranslatorNode>());
  rclcpp::shutdown();

  FloatToBytes converter;
    converter.floatValue = -23.75f;  // Example float value

    // Output the byte array in hexadecimal
    std::cout << "Float value: " << converter.floatValue << std::endl;
    std::cout << "4-byte array in hex: ";
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", converter.byteArray[i]);
    }
    std::cout << std::endl;

  return 0;
}