# 学习笔记（一）：安装 ROS Noetic

建议在稳定的科学上网环境中安装  
[ROS官方安装指导](https://wiki.ros.org/noetic/Installation/Ubuntu)

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
   sudo apt install ros-noetic-desktop-full
   ```
5. 环境设置
   ```bash
   echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
   echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
   
   source ~/.bashrc
   ```   
6. 用于构建包的依赖项
   ```bash
   sudo apt install -y python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
   sudo rosdep init
   rosdep update
   ```     
7. 测试运行
   ```bash
   roscore
   ```