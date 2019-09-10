
##### 1.`sudo apt-get install cifs-utils`
##### 2.`sudo gedit /etc/nsswitch.conf`

找到
`hosts: files mdns4_minimal [NOTFOUND=return] dns`
添加`wins`
`hosts: files mdns4_minimal [NOTFOUND=return] wins dns`

##### 3.创建一个校验文件
    
`gedit ~/.smbcredentials`
内容如下
`username=远程主机名`
`password=远程登录密码`
    
##### 4.`sudo gedit /etc/fstab`

在最后一行添加
`//10.1.74.174/luwenwen /home/ww/Desktop/10.1.74.174 cifs ·credential=/home/ww/.smbcredentials,vers=1.0,iocharset=utf8,gid=1000,uid=1000,file_mode=0777,dir_mode=0777 00`
 注:`10.1.74.174/luwenwen`为我的远程编译服务器   
 注:`/home/ww/Desktop/10.1.74.174`为在本地桌面建立的名为`10.1.74.174`文件夹，便于识别。
 注:我的配置是`vers=1.0 `其他版本失败。

##### 5.连接驱动器
`sudo mount -a`



