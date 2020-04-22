#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class Parrot_Sub{

 public:
   Parrot_Sub();
   void callback(std_msgs::StringConstPtr data);
 private :
   ros::NodeHandle nh;
   ros::Subscriber parrot_sub;
 };

 Parrot_Sub::Parrot_Sub(){
 parrot_sub = nh.subscribe("/words", 0 , &Parrot_Sub::callback, this);
}

void Parrot_Sub::callback(const std_msgs::String::ConstPtr data)
{
 ROS_INFO(" ros pub node says : %s",data->data.c_str());
}
int main( int argc, char **argv)
{
 ros::init(argc, argv, "ros_parrot_sub");
 Parrot_Sub sub;
 ros::spin();
 return 0;
}
