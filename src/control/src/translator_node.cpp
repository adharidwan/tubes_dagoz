#include <memory>

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/twist.hpp>

class TranslatorNode : public rclcpp::Node
{
public:
  TranslatorNode() : Node("translator_node")
  {
    auto topic_callback =
      [this](geometry_msgs::msg::Twist msg) -> void {
        (void)msg;
        RCLCPP_INFO(this->get_logger(), "Test.");
      };
    subscription_ =
      this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", 10, topic_callback);
  }

private:
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TranslatorNode>());
  rclcpp::shutdown();
  return 0;
}