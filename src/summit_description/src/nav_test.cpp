#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal, waypoint1, waypoint2,waypoint3, waypoint4;

  waypoint1.target_pose.header.frame_id = "map";
  waypoint1.target_pose.header.stamp = ros::Time::now();
  waypoint1.target_pose.pose.position.x = 0;
  waypoint1.target_pose.pose.position.y =0;
  waypoint1.target_pose.pose.orientation.z = 0;
  waypoint1.target_pose.pose.orientation.w = 1.0;

  waypoint2.target_pose.header.frame_id = "map";
  waypoint2.target_pose.header.stamp = ros::Time::now();
  waypoint2.target_pose.pose.position.x = 0;
  waypoint2.target_pose.pose.position.y = 2.083;
  waypoint2.target_pose.pose.orientation.z = 0;
  waypoint2.target_pose.pose.orientation.w = 1.0;

  waypoint3.target_pose.header.frame_id = "map";
  waypoint3.target_pose.header.stamp = ros::Time::now();
  waypoint3.target_pose.pose.position.x = 3.5;
  waypoint3.target_pose.pose.position.y = 2.083;
  waypoint3.target_pose.pose.orientation.z = 1;
  waypoint3.target_pose.pose.orientation.w = 0.0;

  waypoint4.target_pose.header.frame_id = "map";
  waypoint4.target_pose.header.stamp = ros::Time::now();
  waypoint4.target_pose.pose.position.x = 3.5;
  waypoint4.target_pose.pose.position.y = 0.0;
  waypoint4.target_pose.pose.orientation.z = 1;
  waypoint4.target_pose.pose.orientation.w = 0.0;

  //we'll send a goal to the robot to move 1 meter forward
  // goal.target_pose.header.frame_id = "map";
  // goal.target_pose.header.stamp = ros::Time::now();

  // goal.target_pose.pose.position.x = 1.0;
  // goal.target_pose.pose.orientation.w = 1.0;

  goal = waypoint1;
  int switch_c =1;

  ROS_INFO("Sending goal");
  while(ros::ok())
  {
  	ac.sendGoal(goal);

	ac.waitForResult();

	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
	{
		ROS_INFO("Hooray, the base moved 1 meter forward");
		if(switch_c==1)
		{
	  		goal = waypoint2;
	  		switch_c=2;
	  		ros::Duration(1.0).sleep();
		}
  	else if(switch_c==2)
  	{
  		goal = waypoint3;
  		switch_c=3;
  		ros::Duration(1.0).sleep();
  	}
    else if(switch_c==3)
    {
      goal = waypoint4;
      switch_c=4;
      ros::Duration(1.0).sleep();
    }
    else if(switch_c==4)
    {
      goal = waypoint1;
      switch_c=1;
      ros::Duration(6.0).sleep();
    }
	}
	else
	{
		ROS_INFO("The base failed to move forward 1 meter for some reason");
	}

  }
  
  return 0;
}