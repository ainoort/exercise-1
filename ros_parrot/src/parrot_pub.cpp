#include "ros/ros.h"
#include "iostream"
#include "string"
#include "std_msgs/String.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "ros_parrot_pub");
	ros::NodeHandle nh;
	ros::Publisher parrot_pub = nh.advertise<std_msgs::String>("/words",10);
	
	ros::Rate rate(10);
	
	while (ros::ok()){

	 std::cout <<"Enter a word ...";
	 std_msgs::String msg;
         std::getline(std::cin, msg.data);
	 
	 ROS_INFO("%s",msg.data.c_str());
	 parrot_pub.publish(msg);


}
return 0;
}
