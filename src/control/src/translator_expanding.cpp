#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "can_msgs/msg/frame.hpp"
#include <chrono>
#include <thread>
#include <cstdint>

class GoalkeeperArmMover : public rclcpp::Node {
public:
    GoalkeeperArmMover() : Node("goalkeeper_arm_mover") {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "goalkeeper/extend_arm", 10,
            std::bind(&GoalkeeperArmMover::listener_callback, this, std::placeholders::_1));
        can_publisher_ = this->create_publisher<can_msgs::msg::Frame>("/to_can_bus", 10);
    }

private:
    void listener_callback(const std_msgs::msg::String::SharedPtr msg) {
        if (msg->data == "up") {
            RCLCPP_INFO(this->get_logger(), "Arm extended upwards.");
            twist_to_pwm(0x15);  // Notasi hexadecimal
            std::this_thread::sleep_for(std::chrono::seconds(2));
            twist_to_pwm(0x14);  // Notasi hexadecimal
        } else if (msg->data == "left") {
            RCLCPP_INFO(this->get_logger(), "Arm extended to the left.");
            twist_to_pwm(0x0B);  // Notasi hexadecimal
            std::this_thread::sleep_for(std::chrono::seconds(2));
            twist_to_pwm(0x0A);  // Notasi hexadecimal
        } else if (msg->data == "right") {
            RCLCPP_INFO(this->get_logger(), "Arm extended to the right.");
            twist_to_pwm(0x1F);  // Notasi hexadecimal
            std::this_thread::sleep_for(std::chrono::seconds(2));
            twist_to_pwm(0x1E);  // Notasi hexadecimal
        } else {
            RCLCPP_WARN(this->get_logger(), "Unknown command received.");
        }
    }

    void twist_to_pwm(int direct) {
        auto can_msg = can_msgs::msg::Frame();
        can_msg.id = 0x125;  // ID dari pesan
        can_msg.is_rtr = false;  // Jika tidak menggunakan RTR
        can_msg.is_extended = false;  // Menggunakan ID standar
        can_msg.is_error = false;  // Tidak ada kesalahan
        can_msg.dlc = 8;  // Mengatur panjang data 8 byte

        // Mengisi 4 byte pertama dengan nilai direct
        can_msg.data[0] = (direct >> 24) & 0xFF;
        can_msg.data[1] = (direct >> 16) & 0xFF;
        can_msg.data[2] = (direct >> 8) & 0xFF;
        can_msg.data[3] = direct & 0xFF;

        // Mengisi byte lainnya dengan 0
        can_msg.data[4] = 0;
        can_msg.data[5] = 0;
        can_msg.data[6] = 0;
        can_msg.data[7] = 0;

        // Publikasikan pesan CAN
        can_publisher_->publish(can_msg);

        // Logging CAN message
        RCLCPP_INFO(this->get_logger(), "Sending CAN message with ID: %x", can_msg.id);
        RCLCPP_INFO(this->get_logger(), "Publishing CAN message ID: %d, data: [%02x, %02x, %02x, %02x, %02x, %02x, %02x, %02x]",
            can_msg.id, can_msg.data[0], can_msg.data[1], can_msg.data[2], can_msg.data[3],
            can_msg.data[4], can_msg.data[5], can_msg.data[6], can_msg.data[7]);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Publisher<can_msgs::msg::Frame>::SharedPtr can_publisher_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<GoalkeeperArmMover>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}