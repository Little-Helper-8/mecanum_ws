#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "stdio.h"
#include "math.h"

float range_lid=0;
float ct=0;
float avg_val=0;
int flagg=0;
void chatterCallback(const sensor_msgs::LaserScan msg)
{
  
  if(!std::isinf(msg.ranges[40]))
  {
  	ct+=1;
  	range_lid+=msg.ranges[40];
  	ROS_INFO("ct is: %f",ct);
  }
  

  if(ct>=2000&& flagg==0)
  {
  	avg_val = range_lid/ct;
  	ROS_INFO("avg val: %f", avg_val);
  	flagg=1;
  }
  else
  {
  	ROS_INFO("range at 0 deg is: %f", msg.ranges[40]);
  }

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "laserrangefinder");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/LiDAR2/scan", 1000, chatterCallback);
  ros::spin();

  return 0;
}