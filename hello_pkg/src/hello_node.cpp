#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    //起手操作，ROS初始化
    ros::init(argc,argv,"hello_node");
    printf("Hello ROS Melodic !\r\n");

    ros::NodeHandle nh;

    //配置话题名称为Publish_Test，发送窗口为10
    ros::Publisher pub = nh.advertise<std_msgs::String>("Publish_Test",10);

    //配置循环速度为10次/秒
    ros::Rate loop_rate(10);

    //ROS中使用ros::ok()函数为死循环条件，以保证程序可以响应ctrl+c终止
    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "Publish Testing.\n";//发布消息内容
        pub.publish(msg);//发布消息
        loop_rate.sleep();
    }
    
    return 0;
}
