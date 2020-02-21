#include "ros/ros.h"
#include "message_filters/subscriber.h"
#include "message_filters/time_synchronizer.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/Imu.h"
#include <summit_description/IMU_info.h>
#include <tf/transform_broadcaster.h>


struct Quaternion
{
    double w, x, y, z;
};


class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<sensor_msgs::Imu>("imu/data_raw", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("imu_info_topic", 1, &SubscribeAndPublish::callback, this);
  }

  //I'm not sure that a second input will work at all (input2)
  void callback(const summit_description::IMU_info::ConstPtr& input)
  {
      sensor_msgs::Imu output;
      ros::Time current_time = ros::Time::now();

      tf::TransformBroadcaster broadcaster;
      broadcaster.sendTransform(tf::StampedTransform(tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.0, 0.0)), current_time, "imu_link", "imu"));

      output.header.stamp = current_time;
      output.header.frame_id = "imu";

      //.... do something with the input and generate the output...

      // Abbreviations for the various angular functions
      //Orientation
   	 double cy = cos(input->yaw * 0.5);
   	 double sy = sin(input->yaw * 0.5);
   	 double cp = cos(input->pitch * 0.5);
   	 double sp = sin(input->pitch * 0.5);
   	 double cr = cos(input->roll * 0.5);
   	 double sr = sin(input->roll * 0.5);

   	 Quaternion q;
   	 q.w = cy * cp * cr + sy * sp * sr;
   	 q.x = cy * cp * sr - sy * sp * cr;
   	 q.y = sy * cp * sr + cy * sp * cr;
   	 q.z = sy * cp * cr - cy * sp * sr;


     output.orientation.x = q.x;
   	 output.orientation.y = q.y;
   	 output.orientation.z = q.z;
   	 output.orientation.w = q.w;

     //Angular velocity (Might not work)
     output.angular_velocity.x = input->x;
     output.angular_velocity.y = input->y;
     output.angular_velocity.z = input->z;

     //linear acceleration
      output.linear_acceleration.x = input->linaccx;
      output.linear_acceleration.y  = input->linaccy;
      output.linear_acceleration.z  = input->linaccz;

      pub_.publish(output);
  }

private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "MessageTransformer");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}
















/*
sensor_msgs::Imu output;

struct Quaternion
{
    double w, x, y, z;
};



  //I'm not sure that a second input will work at all (input2)
  void callback(const geometry_msgs::Pose::ConstPtr& input_rpy, const geometry_msgs::Pose::ConstPtr& input_angvel)
  {

      //.... do something with the input and generate the output...

      // Abbreviations for the various angular functions
      //Orientation
   	 double cy = cos(input_rpy->position.z * 0.5);
   	 double sy = sin(input_rpy->position.z * 0.5);
   	 double cp = cos(input_rpy->position.y * 0.5);
   	 double sp = sin(input_rpy->position.y * 0.5);
   	 double cr = cos(input_rpy->position.x * 0.5);
   	 double sr = sin(input_rpy->position.x * 0.5);

   	 Quaternion q;
   	 q.w = cy * cp * cr + sy * sp * sr;
   	 q.x = cy * cp * sr - sy * sp * cr;
   	 q.y = sy * cp * sr + cy * sp * cr;
   	 q.z = sy * cp * cr - cy * sp * sr;


     output.orientation.x = q.x;
   	 output.orientation.y = q.y;
   	 output.orientation.z = q.z;
   	 output.orientation.w = q.w;

     //Angular velocity (Might not work)
     output.angular_velocity.x = input_angvel->position.x;
     output.angular_velocity.y = input_angvel->position.y;
     output.angular_velocity.z = input_angvel->position.z;
  }


int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "MessageTransformer");
  ros::NodeHandle n_;
  ros::Publisher pub_;

  pub_ = n_.advertise<sensor_msgs::Imu>("imu_data", 1);
  message_filters::Subscriber<geometry_msgs::Pose> sub_1(n_, "imu_rpy", 1);
  message_filters::Subscriber<geometry_msgs::Pose> sub_2(n_, "imu_gyr", 1);

  message_filters::TimeSynchronizer<geometry_msgs::Pose, geometry_msgs::Pose> sync(sub_1, sub_2, 10);
  sync.registerCallback(boost::bind(&callback, _1, _2));

  pub_.publish(output);


  ros::spin();

  return 0;
}
*/



/*
struct Quaternion
{
    double w, x, y, z;
};


void rollpitchyaw_Callback(const geometry_msgs::Pose::ConstPtr& rpymsg)
{

	 // Abbreviations for the various angular functions
	 double cy = cos(rpymsg->position.z * 0.5);
	 double sy = sin(rpymsg->position.z * 0.5);
	 double cp = cos(rpymsg->position.y * 0.5);
	 double sp = sin(rpymsg->position.y * 0.5);
	 double cr = cos(rpymsg->position.x * 0.5);
	 double sr = sin(rpymsg->position.x * 0.5);

	 Quaternion q;
	 q.w = cy * cp * cr + sy * sp * sr;
	 q.x = cy * cp * sr - sy * sp * cr;
	 q.y = sy * cp * sr + cy * sp * cr;
	 q.z = sy * cp * cr - cy * sp * sr;


   imu_msg.orientation.x = q.x;
	 imu_msg.orientation.y = q.y;
	 imu_msg.orientation.z = q.z;
	 imu_msg.orientation.w = q.w;
	 Orientation_pub.publish(&imu_msg);
}



int main(int argc, char **argv)
{
		ros::NodeHandle n;
		sensor_msgs::Imu imu_msg;


		ros::init(argc, argv, "MessageTransformer");
		ros::Subscriber sub = n.subscribe("imu_rpy", 1, rollpitchyaw_Callback);
		ros::Publisher Orientation_pub = n.advertise<sensor_msgs::Imu>("imu_data", 1);
		ros::Rate loop_rate(100);

		while(ros::ok())
		{
		    ros::spinOnce();
				loop_rate.sleep();
		}


		return 0;
}
*/
