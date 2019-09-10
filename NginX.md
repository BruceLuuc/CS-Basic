- Nginx读音'Engine X'
一款高性能的HTTP和反向代理服务器软件

 > Nginx的模块从结构上分为核心模块、基础模块和第三方模块。 
 
- 核心模块： HTTP模块、EVENT模块和MAIL模块
+ 基础模块： HTTP Access模块、HTTP FastCGI模块、HTTP Proxy模块和HTTP Rewrite模块
- 第三方模块： HTTP Upstream Request Hash模块、Notice模块和HTTP Access Key模块及用户自己开发的模块

Nginx的模块默认编译进nginx中，如果需要增加或删除模块，需要重新编译Nginx,这一点不如Apache的动态加载模块方便。如果有需要动态加载模块，可以使用由淘宝网发起的web服务器**Tengine**，在nginx的基础上增加了很多高级特性，完全兼容Nginx，已被国内很多网站采用。

#### 安装LNMP

##### 1.安装nginx：
~~~
sudo apt-get update
sudo apt-get install -y nginx
~~~
启动服务:
~~~
sudo /etc/init.d/nginx start
或者
 sudo service nginx start
~~~

测试,打开浏览器，访问 
~~~
http://localhost 
~~~

停止命令:
~~~
sudo /etc/init.d/nginx stop
或者
 sudo service nginx stop 
~~~
 
 重启命令:
~~~
sudo /etc/init.d/nginx restart
或者
sudo service nginx restart
~~~
 
 - nginx 安装后的初级配置
 sudo vim /etc/nginx/sites-available/default
PHP 需要配置 location ~ .php$ {}，所以要让 php 与 nginx 一起工作，就得在这个配置文件中放出这个模块。修改（**54 行**开始） 把 注释去掉-- vim技巧：ctrl+v进入列编辑，选中要删除的#，再按d删除 .
~~~
 	location ~ \.php$ {
 		root /usr/share/nginx/html;
		fastcgi_split_path_info ^(.+\.php)(/.+)$;
 		fastcgi_pass unix:/var/run/php5-fpm.sock;
		fastcgi_index index.php;
 		include fastcgi_params;
   	}
~~~
 
+ 接着测试配置文件：**sudo nginx -t
 测试成功后，重载配置文件：sudo service nginx reload
 
 **2.安装MYSQL**
 sudo apt-get install mysql-server mysql-client
 启动MYSQL
 sudo service mysql start
 修改 mysql 的配置文件
sudo vim /etc/mysql/my.cnf
将 bind-address = 127.0.0.1 注释掉，就可以远程连接数据库了
 
 
 **3.安装PHP**
 
 在 LNMP 中的作用或角色：nginx 本身不能处理 PHP，它只是个 web 服务器，当接收到请求后，如果是 php 请求，则发给 php 解释器处理，并把结果返回给客户端.php-fpm 是一个守护进程（FastCGI 进程管理器）用于替换 PHP FastCGI 的大部分附加功能，对于高负载网站是非常有用的。
~~~
sudo apt-get install -y php5-fpm
~~~
 
 安装好以后连同上面的 nginx 一同测试，现在创建一个探针文件保存在 /usr/share/nginx/html 目录下(这个目录就是刚刚 nginx 配置文件中 root 目录)，以便测试。
sudo vim /usr/share/nginx/html/phpinfo.php
输入以下代码测试：

~~~
<?php
		phpinfo();
~~~
 
 接下来使用命令启动 php5-fpm 服务：
sudo service php5-fpm start
然后访问 http://localhost/phpinfo.php （记得刷新)

（1）.要想让 php5 支持 Mysql，还需要安装一系列的配套模块。
 安装 php5-mysql 模块
sudo apt-get install php5-mysql
安装好以后 紧接着你需要需要重启 php
sudo service php5-fpm restart
 
 
( 2).改变监听端口
在某些情况下我们需要改变服务器的端口，因为套接字是通过绑定 ip 端口连接的，那就只需要将刚才的 nginx 的 default（所在目录/etc/nginx/sites-available/）配置中的端口打开，然后改成你想要监听的端口.
这是 nginx 的 default:/etc/nginx/sites-available/default
~~~
server {
        listen 9000 default_server;
        listen [::]:9000 default_server ipv6only=on;

        root /usr/share/nginx/html;
        index index.html index.htm;

        # Make site accessible from http://localhost/
        server_name localhost;
~~~

命令重载配置文件使之生效:sudo service nginx reload
接下来重启 nginx 和 php: sudo service nginx restart
刷新刚才的页面 http://localhost:9000/phpinfo.php 


#### nginx进程与模块
 > Nginx 的代码是由一个核心和一系列的模块组成。

核心主要用于提供 WebServer 的基本功能，以及 Web 和 Mail 反向代理的功能；还用于启用网络协议，创建必要的运行时环境以及确保不同的模块之间平滑地进行交互。不过，大多跟协议相关的功能和应用特有的功能都是由 nginx 的模块实现的。

这些功能模块大致可以分为事件模块、阶段性处理器、输出过滤器、变量处理器、协议、upstream 和负载均衡几个类别，这些共同组成了 nginx 的 http 功能。事件模块主要用于提供 OS 独立的(不同操作系统的事件机制有所不同)事件通知机制如 kqueue 或 epoll 等。协议模块则负责实现 nginx 通过 http、tls/ssl、smtp、pop3 以及 imap 与对应的客户端建立会话。在 Nginx 内部，进程间的通信是通过模块的 pipeline 或 chain 实现的；换句话说，每一个功能或操作都由一个模块来实现。例如：压缩、通过 FastCGI 或 uwsgi 协议与 upstream 服务器通信、以及与 memcached 建立会话等。


