//ROS头文件
#include <ros/ros.h>
//包含自定义msg产生的头文件
#include <test/gps.h>
//ROS标准msg头文件
#include <std_msgs/Float32.h>

void gpsCallback(const test::gps::ConstPtr &msg)
{  
    ROS_INFO("Listener: %s",msg->state.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener1");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("gps_info", 1, gpsCallback);
  ros::spin(); 
  return 0;
}

