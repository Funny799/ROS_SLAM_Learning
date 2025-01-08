# 学习笔记（IV）：配置 Gazebo 动态行人障碍

[Gazebo 官方资料](https://gazebosim.org/docs/garden/actors/)

## 在 world 添加 actor 标签模型

使用 ```文本编辑器``` 打开 ```.world``` 文件，添加 ```actor``` 标签
```
<actor name="actor_walking">
  <skin>
    <filename>https://fuel.gazebosim.org/1.0/Mingfei/models/actor/tip/files/meshes/walk.dae</filename>
    <scale>1.0</scale>
  </skin>
  <animation name="walk">
    <filename>https://fuel.gazebosim.org/1.0/Mingfei/models/actor/tip/files/meshes/walk.dae</filename>
    <interpolate_x>true</interpolate_x>
  </animation>
  <script>
    <loop>true</loop> #在循环中重复脚本。对于流畅的连续运动，请确保最后一个航点与第一个航点匹配
    <delay_start>0.000000</delay_start>  #这是启动脚本之前等待的时间（以秒为单位）。如果以循环方式运行，则在开始每个循环之前将等待此时间
    <auto_start>true</auto_start>
    <trajectory id="0" type="walk" tension="0.6">
      <waypoint>  #轨迹中可以有任意数量的航点，每个航点都由一个time和一个pose组成
        <time>0</time> #从脚本开头开始计算的应达到姿势的时间（以秒为单位）
        <pose>0 0 1.0 0 0 0</pose> #应相对于初始 actor 姿势达到的姿势
      </waypoint>
    </trajectory>
  </script>
</actor>
```


## actor 标签模型碰撞属性

1. 编译安装 libActorCollisionsPlugin.so 插件
   ```bash
   git clone https://github.com/osrf/gazebo.git
   cd gazebo/examples/plugins/actor_collisions
   mkdir build
   cd build
   cmake ..
   make
   sudo cp libActorCollisionsPlugin.so /usr/lib/x86_64-linux-gnu/gazebo-11/plugins
   gazebo ../actor_collisions.world #测试插件
   ```

2. 在 world 中添加碰撞插件
   ```
   <plugin
      filename="gz-sim-physics-system"
      name="gz::sim::systems::Physics">
    </plugin>
    <plugin
      filename="libgz-sim-sensors-system.so"
      name="gz::sim::systems::Sensors">
      <render_engine>ogre</render_engine>
    </plugin>
    <plugin
      filename="libgz-sim-user-commands-system.so"
      name="gz::sim::systems::UserCommands">
    </plugin>
    <plugin
      filename="libgz-sim-scene-broadcaster-system.so"
      name="gz::sim::systems::SceneBroadcaster">
    </plugin>
   ```

3. 根据 actor 添加碰撞属性
   ```
   <plugin name="actor_collisions_plugin" filename="libActorCollisionsPlugin.so">
        <scaling collision="LHipJoint_LeftUpLeg_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="LeftUpLeg_LeftLeg_collision" scale="
          8.0
          8.0
          1.0
        "/>
        <scaling collision="LeftLeg_LeftFoot_collision" scale="
          8.0
          8.0
          1.0
        "/>
        <scaling collision="LeftFoot_LeftToeBase_collision" scale="
          4.0
          4.0
          1.5
        "/>
        <scaling collision="RHipJoint_RightUpLeg_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="RightUpLeg_RightLeg_collision" scale="
          8.0
          8.0
          1.0
        "/>
        <scaling collision="RightLeg_RightFoot_collision" scale="
          8.0
          8.0
          1.0
        "/>
        <scaling collision="RightFoot_RightToeBase_collision" scale="
          4.0
          4.0
          1.5
        "/>
        <scaling collision="LowerBack_Spine_collision" scale="
          12.0
          20.0
          5.0
        " pose="0.05 0 0 0 -0.2 0"/>
        <scaling collision="Spine_Spine1_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="Neck_Neck1_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="Neck1_Head_collision" scale="
          5.0
          5.0
          3.0
        "/>
        <scaling collision="LeftShoulder_LeftArm_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="LeftArm_LeftForeArm_collision" scale="
          5.0
          5.0
          1.0
        "/>
        <scaling collision="LeftForeArm_LeftHand_collision" scale="
          5.0
          5.0
          1.0
        "/>
        <scaling collision="LeftFingerBase_LeftHandIndex1_collision" scale="
          4.0
          4.0
          3.0
        "/>
        <scaling collision="RightShoulder_RightArm_collision" scale="
          0.01
          0.001
          0.001
        "/>
        <scaling collision="RightArm_RightForeArm_collision" scale="
          5.0
          5.0
          1.0
        "/>
        <scaling collision="RightForeArm_RightHand_collision" scale="
          5.0
          5.0
          1.0
        "/>
        <scaling collision="RightFingerBase_RightHandIndex1_collision" scale="
          4.0
          4.0
          3.0
        "/>
      </plugin>
   ```


