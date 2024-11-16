#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "can_msgs/msg/frame.hpp"
#include <chrono>
#include <thread>
#include <cstdint>

// Kelas GoalkeeperArmMover adalah node ROS 2 yang bertanggung jawab 
// untuk menerima perintah gerakan lengan penjaga gawang melalui topik 
// dan mengirim pesan CAN untuk menggerakkan lengan tersebut.
class GoalkeeperArmMover : public rclcpp::Node {
public:
    // Konstruktor untuk node GoalkeeperArmMover
    GoalkeeperArmMover() : Node("goalkeeper_arm_mover") {
        // Membuat subscriber untuk menerima perintah dari topik "goalkeeper/extend_arm".
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "goalkeeper/extend_arm", 10,
            std::bind(&GoalkeeperArmMover::listener_callback, this, std::placeholders::_1));
        
        // Membuat publisher untuk mengirim pesan CAN ke topik "/to_can_bus".
        can_publisher_ = this->create_publisher<can_msgs::msg::Frame>("/to_can_bus", 10);
    }

private:
    // Callback untuk menangani pesan yang diterima pada topik "goalkeeper/extend_arm".
    void listener_callback(const std_msgs::msg::String::SharedPtr msg) {
        if (msg->data == "up") {
            // Jika perintah adalah "up", gerakkan lengan ke atas.
            RCLCPP_INFO(this->get_logger(), "Arm extended upwards.");
            twist_to_pwm(0x15);  // Kirim sinyal CAN untuk membuka lengan ke atas.
            std::this_thread::sleep_for(std::chrono::seconds(2));  // Tunggu 2 detik.
            twist_to_pwm(0x14);  // Kirim sinyal CAN untuk menutup lengan.
        } else if (msg->data == "left") {
            // Jika perintah adalah "left", gerakkan lengan ke kiri.
            RCLCPP_INFO(this->get_logger(), "Arm extended to the left.");
            twist_to_pwm(0x0B);  // Kirim sinyal CAN untuk membuka lengan ke kiri.
            std::this_thread::sleep_for(std::chrono::seconds(2));  // Tunggu 2 detik.
            twist_to_pwm(0x0A);  // Kirim sinyal CAN untuk menutup lengan.
        } else if (msg->data == "right") {
            // Jika perintah adalah "right", gerakkan lengan ke kanan.
            RCLCPP_INFO(this->get_logger(), "Arm extended to the right.");
            twist_to_pwm(0x1F);  // Kirim sinyal CAN untuk membuka lengan ke kanan.
            std::this_thread::sleep_for(std::chrono::seconds(2));  // Tunggu 2 detik.
            twist_to_pwm(0x1E);  // Kirim sinyal CAN untuk menutup lengan.
        } else {
            // Jika perintah tidak dikenali, log pesan peringatan.
            RCLCPP_WARN(this->get_logger(), "Unknown command received.");
        }
    }

    // Fungsi untuk mengirim sinyal CAN berdasarkan nilai direct (arah gerakan).
    void twist_to_pwm(int direct) {
        auto can_msg = can_msgs::msg::Frame();
        can_msg.id = 0x125;  // ID pesan CAN untuk lengan penjaga gawang.
        can_msg.is_rtr = false;  // Pesan ini bukan pesan RTR (Remote Transmission Request).
        can_msg.is_extended = false;  // Menggunakan format ID CAN standar (11-bit).
        can_msg.is_error = false;  // Tidak ada indikasi kesalahan pada pesan.
        can_msg.dlc = 8;  // Panjang data pesan adalah 8 byte.

        // Memasukkan nilai direct ke dalam 4 byte pertama data CAN.
        can_msg.data[0] = (direct >> 24) & 0xFF;
        can_msg.data[1] = (direct >> 16) & 0xFF;
        can_msg.data[2] = (direct >> 8) & 0xFF;
        can_msg.data[3] = direct & 0xFF;

        // Byte lainnya diinisialisasi ke 0.
        can_msg.data[4] = 0;
        can_msg.data[5] = 0;
        can_msg.data[6] = 0;
        can_msg.data[7] = 0;

        // Publikasikan pesan CAN.
        can_publisher_->publish(can_msg);

        // Logging informasi pesan CAN yang diterbitkan.
        RCLCPP_INFO(this->get_logger(), "Sending CAN message with ID: %x", can_msg.id);
        RCLCPP_INFO(this->get_logger(), 
            "Publishing CAN message ID: %d, data: [%02x, %02x, %02x, %02x, %02x, %02x, %02x, %02x]",
            can_msg.id, can_msg.data[0], can_msg.data[1], can_msg.data[2], can_msg.data[3],
            can_msg.data[4], can_msg.data[5], can_msg.data[6], can_msg.data[7]);
    }

    // Subscriber untuk menerima perintah gerakan lengan.
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    // Publisher untuk mengirim pesan CAN ke bus CAN.
    rclcpp::Publisher<can_msgs::msg::Frame>::SharedPtr can_publisher_;
};

// Fungsi utama program.
int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);  // Inisialisasi sistem ROS 2.
    auto node = std::make_shared<GoalkeeperArmMover>();  // Buat instance node.
    rclcpp::spin(node);  // Jalankan node untuk mendengarkan pesan.
    rclcpp::shutdown();  // Tutup sistem ROS 2.
    return 0;
}
