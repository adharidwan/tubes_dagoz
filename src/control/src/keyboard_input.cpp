#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <ncurses.h>

class TeleopNode : public rclcpp::Node
{
public:
    TeleopNode() : Node("teleop_node")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        // this->initializeNcurses();
        // this->create_timer(std::chrono::milliseconds(100), [this]() { this->timer_callback(); });
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&TeleopNode::timer_callback, this));
        initializeNcurses();

    }

    ~TeleopNode()
    {
        endwin(); // End ncurses mode
    }

private:
    void initializeNcurses()
    {
        initscr(); // Start ncurses mode
        cbreak(); // Disable line buffering
        noecho(); // Don't show typed characters
        keypad(stdscr, TRUE); // Enable special keys capture
        nodelay(stdscr, TRUE); // Non-blocking input
    }

    void timer_callback()
    {
        geometry_msgs::msg::Twist msg;
        int ch = getch(); // Get the keyboard input

        switch (ch)
        {
            case 'w':
                msg.linear.x = 1.0;
                break;
            case 's':
                msg.linear.x = -1.0;
                break;
            case 'a':
                msg.linear.y = -1.0;
                break;
            case 'd':
                msg.linear.y = 1.0;
                break;
            // case KEY_LEFT:
            //     msg.angular.z = 1.0;
            //     break;
            // case KEY_RIGHT:
            //     msg.angular.z = -1.0;
            //    break;
            case 'r':
                msg.angular.z = -1.0;
               break;
            case ERR:
                // No key pressed
                break;
            default:
                msg.linear.x = 0.0;
                msg.linear.y = 0.0;
                msg.angular.z = 0.0;
                break;
        }
        
        // RCLCPP_INFO(this->get_logger(), "Publishing linear.x: %.2f, angular.z: %.2f", msg.linear.x, msg.angular.z);
        publisher_->publish(msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TeleopNode>());
    rclcpp::shutdown();
    return 0;
}
