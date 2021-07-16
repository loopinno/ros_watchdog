#include <ros/ros.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_watchdog");
    ros::NodeHandle nh, private_nh("~");
    ros::spin(); 
    return 0;
}