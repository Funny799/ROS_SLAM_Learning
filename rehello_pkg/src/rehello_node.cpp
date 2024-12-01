#include <ros/ros.h>
#include <std_msgs/String.h>

//接收消息后的回调函数
void reply_callback(std_msgs::String msg);

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"rehello_node");
    ros::NodeHandle nh;

    //配置订阅名称为"Publish_Test"的话题，接收窗口为10，接收到消息后执行回调函数reply_callback()
    ros::Subscriber sub = nh.subscribe("Publish_Test",10,reply_callback);

    while (ros::ok())
    {
        //轮询话题中是否有消息传来
        ros::spinOnce();
    }
    
    return 0;
}

//回调函数 实现
void reply_callback(std_msgs::String msg){
    ROS_INFO(msg.data.c_str());
}

