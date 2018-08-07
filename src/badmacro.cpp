#include <string>

#include <rclcpp/rclcpp.hpp>
#include <rcutils/logging_macros.h>

class BadMacro {
public:
  BadMacro() {}

  int main()
  {
    joy_dev_name_ = "";

    if (!joy_dev_name_.empty())
    {
      std::string joy_dev_path = "/dev/input/js0";
      if (joy_dev_path.empty())
// Uncommenting the brackets will allow this to compile
//      {
        RCUTILS_LOG_ERROR("Couldn't find a joystick with name %s. Falling back to default device.", joy_dev_name_.c_str());
//      }
      else
      {
        RCUTILS_LOG_INFO("Using %s as joystick device.", joy_dev_path.c_str());
      }
    }

    return 0;
  }

private:
  std::string joy_dev_name_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BadMacro b;

  return b.main();
}
