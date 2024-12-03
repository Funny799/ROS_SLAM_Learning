# 学习笔记（二）：安装 Ubuntu 常用软件包 与 配置

## Hector Mapping
1. 软件包直接安装
   ```bash
   sudo apt install ros-noetic-hector-mapping
   ```
2. 下载源码编译（推荐）
   ```bash
   cd ~/catkin_ws/src
   git clone https://github.com/tu-darmstadt-ros-pkg/hector_slam.git
   cd ~/catkin_ws
   catkin_make
   ```
3. 运行 Bag 仿真
   ```bash
   roslaunch hector_slam_launch tutorial.launch
   rosbag play Team_Hector_MappingBox_RoboCup_2011_Rescue_Arena.bag  --clock
   ```
4. 故障排除
   如果你从源码构建hector_slam，但在 Team_Hector_MappingBox_RoboCup_2011_Rescue_Arena.bag 上发现你的 hector 映射与作者的映射不同。检查您是否在 Release 版本中构建了 hector_slam 以获得完整的性能：
   ```bash
   catkin_make -DCMAKE_BUILD_TYPE=Release
   ```
   hector_slam的参数在映射结果中也起着作用。例如，检查 `hector_mapping/mapping_default.launch` 中的 map_update_angle_thresh：
`   <param name="map_update_angle_thresh" value="0.9" />`

## G Mapping 
1. 软件包直接安装
   ```bash
   sudo apt install ros-noetic-openslam-gmapping ros-noetic-gmapping
   ```
2. 下载源码编译（推荐）   
   ```bash
   sudo apt remove ros-noetic-openslam-gmapping ros-noetic-gmapping # 先通过软件包安装，再卸载软件包保证依赖
   cd ~/catkin_ws/src
   git clone https://github.com/ros-perception/slam_gmapping.git
   git clone https://github.com/ros-perception/openslam_gmapping.git
   cd ~/catkin_ws
   catkin_make
   ```
3. 运行 Bag 仿真
   ```bash
   rosrun gmapping slam_gmapping scan:=base_scan
   rosbag play --clock basic_localization_stage_indexed.bag

   ```

## Cartographer
参考[官方指导教程](https://google-cartographer-ros.readthedocs.io/en/latest/compilation.html)

1. 安装构建工具
   ```bash
   sudo apt-get update
   sudo apt-get install -y python3-wstool python3-rosdep ninja-build stow
   ```
2. 新建 cartographer 的工作空间  
   由于 cartographer 编译略有不同，建议不要再 catkin_ws/src 编译 cartographer
   ```bash
   cd ~
   mkdir cartographer_ws
   cd cartographer_ws
   wstool init src
   wstool merge -t src https://raw.githubusercontent.com/cartographer-project/cartographer_ros/master/cartographer_ros.rosinstall
   wstool update -t src
   ```
3. 安装 cartographer_ros 的依赖项
   首先 删除 或 注释 `cartographer_ws/src/cartographer/package.xml` 中 `<depend>libabsl-dev</depend>` 一项
   ```bash
   sudo rosdep init # 安装 ROS 时已执行，可以不执行
   rosdep update
   rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y
   src/cartographer/scripts/install_abseil.sh
   sudo apt-get remove ros-${ROS_DISTRO}-abseil-cpp # 如果发生 abseil-cpp 库版本冲突再运行该指令
   catkin_make_isolated --install --use-ninja
   ```
4. 构建和安装
   ```bash
   catkin_make_isolated --install --use-ninja
   # 在 ~/cartographer_ws 下运行此命令
   ```
5. 配置环境变量
   ```bash
   echo "source ~/cartographer_ws/install_isolated/setup.bash" >> ~/.bashrc
   ```
6. 运行 Bag 仿真
   ```bash
   roslaunch cartographer_ros demo_backpack_2d.launch bag_filename:=<自行修改为 bag 文件位置>
   ```