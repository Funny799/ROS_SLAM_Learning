# 学习笔记（二）：安装 Ubuntu 常用软件包 与 配置

1. 超级终端
   ```bash
   sudo apt install terminator 
   gedit ~/.config/terminator/config # 修改默认打开的窗口大小
   ```
   配置文件如下：
   ```
   [[[window0]]]
      type = Window
      parent = ""
      size = 1280, 720
   ```
2. 修改 Ubuntu 开关机等待时间
   ```bash
   sudo gedit /etc/systemd/system.conf
   ```
   配置文件如下：
   ```
   DefaultTimeoutStartSec=15s
   #DefaultTimeoutStopSec=90s
   DefaultTimeoutStopSec=15s
   #DefaultTimeoutStopSec=90s
   ```
3. git 工具
   ```bash
   # 安装
   sudo apt install git
   sudo apt install ssh
   git config --global user.name ""
   git config --global user.email ""
   git config --global color.ui true
   # 配置
   ssh-keygen -t rsa -C "邮箱地址" # 生成密钥
   cat ~/.ssh/id_rsa.pub # 查看并复制本地密钥，将此密钥添加至 Github 账户中
   ```
   ```bash
   gedit ~/.ssh/config # 修改 ssh 连接 Github 的端口
   
   Host github.com
	   port 443
	   HostName ssh.github.com
	   IdentityFile ~/.ssh/id_rsa
   ```
   ``` bash
   # 常用命令
   git add .
   git commit -m ""
   git push
   ```