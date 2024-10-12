#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <mutex>

#include <std_msgs/msg/string.hpp>
#include <termios.h>
#include <unistd.h>
#include <iostream>

class KeyboardInputNode : public rclcpp::Node
{
public:
    KeyboardInputNode() : Node("keyboard_input_node"), velocity_duration_(3.0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        initscr();
        cbreak();
        noecho(); 
        keypad(stdscr, TRUE); 

        velocity_msg_.linear.x = 0.0;
        velocity_msg_.linear.y = 0.0;

        control_thread_ = std::thread(&KeyboardInputNode::controlLoop, this);

        publisher_exp = this->create_publisher<std_msgs::msg::String>("goalkeeper/extend_arm", 10);
        setup_terminal();
    }

    ~KeyboardInputNode()
    {
        endwin();
        if (control_thread_.joinable()) {
            control_thread_.join();
        }
    }

    // // Fungsi untuk menerima input dari tombol panah
    // void process_input()
    // {
    //     char input;
    //     input = getchar();  // Menangkap input dari keyboard

    //     // Memeriksa apakah tombol panah ditekan
    //     if (input == 27) {  // ESC character
    //         input = getchar();  // Membaca karakter berikutnya
    //         if (input == 91) {  // Character '['
    //             input = getchar();  // Membaca kode panah
    //             auto message = std_msgs::msg::String();
    //             if (input == 65) {
    //                 // Panah atas untuk ekstensi lengan ke atas
    //                 message.data = "up";
    //                 publisher_exp->publish(message);
    //                 RCLCPP_INFO(this->get_logger(), "Extending arm upwards.");
    //             } else if (input == 67) {
    //                 // Panah kanan untuk ekstensi lengan ke kanan
    //                 message.data = "right";
    //                 publisher_exp->publish(message);
    //                 RCLCPP_INFO(this->get_logger(), "Extending arm to the right.");
    //             } else if (input == 68) {
    //                 // Panah kiri untuk ekstensi lengan ke kiri
    //                 message.data = "left";
    //                 publisher_exp->publish(message);
    //                 RCLCPP_INFO(this->get_logger(), "Extending arm to the left.");
    //             }
    //         }
    //     }
    // }

private:
    void controlLoop()
    {
        int ch;
        while (rclcpp::ok())
        {
            ch = getch(); 
            // auto start_time = std::chrono::steady_clock::now(); 
            switch (ch)
            {
                case 'w':
                    updateVelocity(1.0, 0.0);   
                    break;
                case 's':
                    updateVelocity(-1.0, 0.0);
                    break;
                case 'a':
                    updateVelocity(0.0, -1.0);
                    break;
                case 'd':
                    updateVelocity(0.0, 1.0);
                    break;
                case KEY_UP:
                    message.data = "up";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm upwards.");
                case KEY_LEFT:
                    message.data = "left";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the left.");
                case KEY_RIGHT:
                    message.data = "right";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the right.");
                case 'q':
                    RCLCPP_INFO(this->get_logger(), "Exiting...");
                    rclcpp::shutdown();
                    return;
                default:
                    break;
            }

            std::this_thread::sleep_for(std::chrono::duration<double>(velocity_duration_));
            resetVelocity();

        }
    }

    void updateVelocity(double linearx, double lineary)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        velocity_msg_.linear.x = linearx;
        velocity_msg_.linear.y = lineary;
        publisher_->publish(velocity_msg_);
        // RCLCPP_INFO(this->get_logger(), "Published linear velocity x: %.2f, linear velocity y: %.2f",velocity_msg_.linear.x, velocity_msg_.linear.y);
    }

    void resetVelocity()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        velocity_msg_.linear.x = 0.0;
        velocity_msg_.linear.y = 0.0;
        publisher_->publish(velocity_msg_);
        // RCLCPP_INFO(this->get_logger(), "Resetted back after 1s = linear velocity x: %.2f, linear velocity y: %.2f",velocity_msg_.linear.x, velocity_msg_.linear.y);
    }

    void setup_terminal()
    {
        struct termios settings;
        tcgetattr(STDIN_FILENO, &settings);
        settings.c_lflag &= ~(ICANON | ECHO);  // Matikan mode kanonik dan echo
        tcsetattr(STDIN_FILENO, TCSANOW, &settings);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_exp;
    geometry_msgs::msg::Twist velocity_msg_;
    std_msgs::msg::String message;
    std::thread control_thread_;
    double velocity_duration_;  
    std::mutex mutex_;           
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<KeyboardInputNode>();
    // while (rclcpp::ok()) {
    //     node->process_input();
    //     rclcpp::spin_some(node);
    // }
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}