#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Imu.h"
#include "stdio.h"
#include "math.h"

float max_value=0;
float max_value_prev=0;
void chatterCallback(const sensor_msgs::Imu msg)
{
  
  max_value = msg.linear_acceleration.x;
  if(max_value>max_value_prev)
    max_value_prev = max_value;
  ROS_INFO("max acc is: %f", max_value_prev);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "accelrationtest");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/imu_data", 1000, chatterCallback);
  ros::spin();

  return 0;
}