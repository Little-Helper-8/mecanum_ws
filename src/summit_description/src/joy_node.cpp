#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

geometry_msgs::Twist twist;
float speed = 0.5;
void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  twist.angular.z = speed*joy->axes[2];
  twist.linear.x = speed*joy->axes[1];
  twist.linear.y = speed*joy->axes[0];
  twist.linear.z =0;
  twist.angular.x =0;
  twist.angular.y =0;
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_j");
  ros::NodeHandle n;
  ros::Subscriber joy_sub = n.subscribe("joy", 10, joyCallback);
  ros::Publisher joy_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 10);

  
  ros::Rate loop_rate(100);

  while (ros::ok())
  {
    joy_pub.publish(twist);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
