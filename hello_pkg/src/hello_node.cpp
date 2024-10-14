#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello_node");
    printf("Hello ROS Melodic !\r\n");
    while (ros::ok())
    {
        /* code */
    }
    
    return 0;
}
