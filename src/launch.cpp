#include <cstdio>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"

int main(int argc, char ** argv)
{
    srand(time(NULL));
    std::string nodeName = "node_launcher" + std::to_string(rand()%1000000000000);
    rclcpp::Node nodeHandle(nodeName);

    nodeHandle.declare_parameter("package");
    nodeHandle.declare_parameter("launch_file");
    nodeHandle.declare_parameter("launch_args");
    nodeHandle.declare_parameter("ip");
    nodeHandle.declare_parameter("user");
    nodeHandle.declare_parameter("password");

    std::string package_name;
    std::string launch_file_name;
    std::string launch_args_name;
    std::string ip_name;
    std::string user_name;
    std::string password_name;


    nodeHandle.get_parameter("package", package_name);              
    nodeHandle.get_parameter("launch_file", launch_file_name);     
    nodeHandle.get_parameter("launch_args", launch_args_name);     
    nodeHandle.get_parameter("ip", ip_name);              
    nodeHandle.get_parameter("user", user_name);              
    nodeHandle.get_parameter("password", password_name);     


    // ssh into a computer here if the other parameters are provided
    std::string launch_cmd = "ros2 launch " + package_name + " " + launch_file_name + " " + launch_args_name;
    // Get User Data
    if(!ip_name.empty() && !user_name.empty() && !password_name.empty())
    {
      // ssh into computer and run command
    }
    else
    {
      std::printf("running: %s", launch_cmd.c_str());
      system(launch_cmd.c_str());
    }
    return 0;
}
