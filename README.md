# ROS_SLAM_Learning

本仓库是我入学硕士研究生后学习ROS与SLAM的一些笔记。  
基于 Ubuntu18.04 与 ROS Melodic

## 安装Ubuntu 18.04
（略）

## 安装ROS Melodic

建议在稳定的科学上网环境中安装  
[ROS官方安装指导](https://wiki.ros.org/melodic/Installation/Ubuntu)  
1. 配置 Ubuntu 存储库 **（安装好Ubuntu后几乎不用动）**  
   将您的 Ubuntu 存储库配置为允许 “restricted”、“universe” 和 “multiverse”。您可以按照 [Ubuntu 指南](https://help.ubuntu.com/community/Repositories/Ubuntu)获取有关执行此操作的说明。
2. 设置你的 sources.list  
   将计算机设置为接受来自 packages.ros.org 的软件。  
   ```bash
   sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' # 这是一行指令
   ```
3. 设置密钥
   ```bash
   sudo apt install curl # 如果没有安装过 curl 软件包
   curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
   ```
4. 安装
   ```bash
   sudo apt update
   sudo apt install ros-melodic-desktop-full
   ```
5. 环境设置
   ```bash
   echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
   source ~/.bashrc
   ```   
6. 用于构建包的依赖项
   ```bash
   sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
   sudo apt install python-rosdep
   sudo rosdep init
   rosdep update
   ```     
7. 测试运行
   ```bash
   roscore
   ```

## 参考资料

[机器人工坊阿杰](https://space.bilibili.com/411541289)  
[小虎哥哥爱学习](https://space.bilibili.com/66815220)  

## 引用项目

[ros-visualization/rqt_robot_steering](https://github.com/ros-visualization/rqt_robot_steering)  
[6-robot/wpr_simulation](https://github.com/6-robot/wpr_simulation)（该项目scripts目录下install_for_xx.sh的依赖安装脚本包含了 `hector-mapping` 与 `gmapping` 软件包）  
[tu-darmstadt-ros-pkg/hector_slam](https://github.com/tu-darmstadt-ros-pkg/hector_slam)  
[ros-perception/openslam_gmapping](https://github.com/ros-perception/openslam_gmapping)  
[ros-perception/slam_gmapping](https://github.com/ros-perception/slam_gmapping)  