#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <termios.h>
#include <unistd.h>
#include <iostream>

class GoalkeeperArmController : public rclcpp::Node
{
public:
    GoalkeeperArmController() : Node("goalkeeper_arm_controller")
    {
        // Membuat publisher untuk mengirim perintah ekstensi lengan
        publisher_ = this->create_publisher<std_msgs::msg::String>("goalkeeper/extend_arm", 10);
        setup_terminal();
    }

    // Fungsi untuk menerima input dari tombol panah
    void process_input()
    {
        char input;
        input = getchar();  // Menangkap input dari keyboard

        // Memeriksa apakah tombol panah ditekan
        if (input == 27) {  // ESC character
            input = getchar();  // Membaca karakter berikutnya
            if (input == 91) {  // Character '['
                input = getchar();  // Membaca kode panah
                auto message = std_msgs::msg::String();
                if (input == 65) {
                    // Panah atas untuk ekstensi lengan ke atas
                    message.data = "up";
                    publisher_->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm upwards.");
                } else if (input == 67) {
                    // Panah kanan untuk ekstensi lengan ke kanan
                    message.data = "right";
                    publisher_->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the right.");
                } else if (input == 68) {
                    // Panah kiri untuk ekstensi lengan ke kiri
                    message.data = "left";
                    publisher_->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the left.");
                }
            }
        }
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    // Fungsi untuk mengatur terminal agar menerima input secara non-blocking
    void setup_terminal()
    {
        struct termios settings;
        tcgetattr(STDIN_FILENO, &settings);
        settings.c_lflag &= ~(ICANON | ECHO);  // Matikan mode kanonik dan echo
        tcsetattr(STDIN_FILENO, TCSANOW, &settings);
    }
};

int main(int argc, char *argv[])
{
    // Inisialisasi ROS 2
    rclcpp::init(argc, argv);

    // Membuat node pengendali lengan penjaga gawang
    auto node = std::make_shared<GoalkeeperArmController>();

    // Loop untuk menerima input dan memprosesnya
    while (rclcpp::ok()) {
        node->process_input();
        rclcpp::spin_some(node);
    }

    // Menutup ROS 2
    rclcpp::shutdown();
    return 0;
}
