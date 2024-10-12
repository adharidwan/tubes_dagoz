#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <mutex>

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
    }

    ~KeyboardInputNode()
    {
        endwin();
        if (control_thread_.joinable()) {
            control_thread_.join();
        }
    }

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

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    geometry_msgs::msg::Twist velocity_msg_;
    std::thread control_thread_;
    double velocity_duration_;  
    std::mutex mutex_;           
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<KeyboardInputNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}