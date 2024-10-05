#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class GoalkeeperArmMover : public rclcpp::Node
{
public:
    GoalkeeperArmMover() : Node("goalkeeper_arm_mover")
    {
        // Membuat subscriber untuk mendengarkan perintah ekstensi lengan
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "goalkeeper/extend_arm", 10,
            std::bind(&GoalkeeperArmMover::move_arm, this, std::placeholders::_1));
    }

private:
    void move_arm(const std_msgs::msg::String::SharedPtr msg)
    {
        if (msg->data == "up") {
            // Panggil fungsi untuk ekstensi lengan ke atas
            extend_up();
            RCLCPP_INFO(this->get_logger(), "Arm extended upwards.");
        } else if (msg->data == "left") {
            // Panggil fungsi untuk ekstensi lengan ke kiri
            extend_left();
            RCLCPP_INFO(this->get_logger(), "Arm extended to the left.");
        } else if (msg->data == "right") {
            // Panggil fungsi untuk ekstensi lengan ke kanan
            extend_right();
            RCLCPP_INFO(this->get_logger(), "Arm extended to the right.");
        } else {
            RCLCPP_WARN(this->get_logger(), "Unknown command received.");
        }
    }

    // Fungsi placeholder untuk ekstensi lengan (implementasi oleh temanmu)
    void extend_up() {
        // Implementasi untuk menggerakkan lengan ke atas
    }

    void extend_left() {
        // Implementasi untuk menggerakkan lengan ke kiri
    }

    void extend_right() {
        // Implementasi untuk menggerakkan lengan ke kanan
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    // Inisialisasi ROS 2
    rclcpp::init(argc, argv);

    // Membuat node penggerak lengan penjaga gawang
    auto node = std::make_shared<GoalkeeperArmMover>();

    // Menjalankan node
    rclcpp::spin(node);

    // Menutup ROS 2
    rclcpp::shutdown();
    return 0;
}
