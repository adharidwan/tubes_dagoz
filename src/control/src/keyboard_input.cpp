#include <rclcpp/rclcpp.hpp>               // ROS2 library untuk membuat node
#include <geometry_msgs/msg/twist.hpp>    // Pesan untuk kontrol kecepatan robot
#include <ncurses.h>                      // Library untuk manipulasi input keyboard dan terminal
#include <thread>                         // Library untuk threading
#include <chrono>                         // Library untuk manajemen waktu
#include <mutex>                          // Library untuk sinkronisasi akses data di multi-threading
#include <std_msgs/msg/string.hpp>        // Pesan string untuk mengontrol ekstensi lengan robot
#include <termios.h>                      // Library untuk pengaturan mode terminal
#include <unistd.h>                       // Fungsi terkait terminal
#include <iostream>                       // Library standar untuk input-output

// Kelas utama untuk node ROS2 yang menangani input keyboard
class KeyboardInputNode : public rclcpp::Node
{
public:
    // Konstruktor untuk inisialisasi node
    KeyboardInputNode() : Node("keyboard_input_node"), velocity_duration_(3.0)
    {
        // Membuat publisher untuk mengirim perintah kecepatan robot
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Inisialisasi ncurses untuk input keyboard
        initscr();       // Memulai mode ncurses
        cbreak();        // Mematikan buffering input
        noecho();        // Mematikan echo input
        keypad(stdscr, TRUE); // Mengaktifkan deteksi tombol khusus (seperti panah)

        // Inisialisasi pesan kecepatan dengan nilai nol
        velocity_msg_.linear.x = 0.0;
        velocity_msg_.linear.y = 0.0;

        // Membuat thread untuk loop kontrol input
        control_thread_ = std::thread(&KeyboardInputNode::controlLoop, this);

        // Membuat publisher untuk mengirim perintah ekstensi lengan
        publisher_exp = this->create_publisher<std_msgs::msg::String>("goalkeeper/extend_arm", 10);

        // Mengatur terminal untuk mode non-kanonik
        setup_terminal();
    }

    // Destruktor untuk membersihkan sumber daya
    ~KeyboardInputNode()
    {
        endwin();  // Menutup mode ncurses
        if (control_thread_.joinable()) {
            control_thread_.join();  // Menunggu thread selesai
        }
    }

private:
    // Fungsi utama untuk membaca input keyboard dan mengontrol robot
    void controlLoop()
    {
        int ch; // Variabel untuk menyimpan input keyboard
        while (rclcpp::ok()) // Loop utama selama ROS aktif
        {
            ch = getch(); // Membaca input keyboard
            switch (ch)
            {
                case 'w': // Maju
                    updateVelocity(1.0, 0.0);
                    break;
                case 's': // Mundur
                    updateVelocity(-1.0, 0.0);
                    break;
                case 'a': // Geser kiri
                    updateVelocity(0.0, -1.0);
                    break;
                case 'd': // Geser kanan
                    updateVelocity(0.0, 1.0);
                    break;
                case KEY_UP: // Panah atas: perintah ekstensi lengan ke atas
                    message.data = "up";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm upwards.");
                    break;
                case KEY_LEFT: // Panah kiri: perintah ekstensi lengan ke kiri
                    message.data = "left";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the left.");
                    break;
                case KEY_RIGHT: // Panah kanan: perintah ekstensi lengan ke kanan
                    message.data = "right";
                    publisher_exp->publish(message);
                    RCLCPP_INFO(this->get_logger(), "Extending arm to the right.");
                    break;
                case 'q': // Keluar program
                    RCLCPP_INFO(this->get_logger(), "Exiting...");
                    rclcpp::shutdown();
                    return;
                default:
                    break;
            }

            // Memberikan jeda sebelum kecepatan direset
            std::this_thread::sleep_for(std::chrono::duration<double>(velocity_duration_));
            resetVelocity(); // Mengatur ulang kecepatan ke nol
        }
    }

    // Fungsi untuk memperbarui kecepatan linear robot
    void updateVelocity(double linearx, double lineary)
    {
        std::lock_guard<std::mutex> lock(mutex_); // Mengamankan akses ke pesan kecepatan
        velocity_msg_.linear.x = linearx;
        velocity_msg_.linear.y = lineary;
        publisher_->publish(velocity_msg_); // Mengirim pesan kecepatan
    }

    // Fungsi untuk mengatur ulang kecepatan ke nol
    void resetVelocity()
    {
        std::lock_guard<std::mutex> lock(mutex_); // Mengamankan akses ke pesan kecepatan
        velocity_msg_.linear.x = 0.0;
        velocity_msg_.linear.y = 0.0;
        publisher_->publish(velocity_msg_); // Mengirim pesan kecepatan
    }

    // Fungsi untuk mengatur terminal ke mode non-kanonik
    void setup_terminal()
    {
        struct termios settings;
        tcgetattr(STDIN_FILENO, &settings); // Membaca pengaturan terminal
        settings.c_lflag &= ~(ICANON | ECHO); // Mematikan mode kanonik dan echo
        tcsetattr(STDIN_FILENO, TCSANOW, &settings); // Menerapkan pengaturan
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_; // Publisher untuk perintah kecepatan
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_exp; // Publisher untuk perintah lengan
    geometry_msgs::msg::Twist velocity_msg_;  // Pesan untuk menyimpan kecepatan
    std_msgs::msg::String message;           // Pesan untuk menyimpan perintah ekstensi lengan
    std::thread control_thread_;             // Thread untuk loop kontrol
    double velocity_duration_;               // Durasi kecepatan sebelum reset
    std::mutex mutex_;                       // Mutex untuk sinkronisasi akses data
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv); // Inisialisasi ROS2
    auto node = std::make_shared<KeyboardInputNode>(); // Membuat node
    rclcpp::spin(node); // Menjalankan node
    rclcpp::shutdown(); // Mematikan ROS2
    return 0;
}
