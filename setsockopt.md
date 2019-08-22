#### 套接字选项
##### 一、函数
```C
#include <sys/socket.h>
int getsockopt(int sockfd, int level, int optname,       void *val, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname, const void *val, socklen_t optlen);
            //Returns: 0 if OK, −1 on error
```
`level`      | `optname`      | `说明`
------       |---------         |-----
`SOL_SOCKET` | `SO_BROADCAST` | 允许发送广播数据段
`SOL_SOCKET` | `SO_LINGER`    | 若有数据待发送则延迟关闭
`SOL_SOCKET` | `SO_REUSEADDR` | 允许重用本地地址

`setsockopt`函数需要一个不为0的`*optval`值来启用选项，一个为0的`optval`值来禁止选项。

##### 二、`SO_BROADCAST`套接字选项
&emsp;&emsp;本选项开启或禁止进程发送广播消息的能力。由于应用进程在发送广播数据之前必须设置本套接字选项，因此它能够有效地防止一个进程在其应用进程根本没有设计成可广播时就发送广播数据报。
##### 三、`SO_LINGER`套接字选项
&emsp;&emsp;本选项指定close函数对面向连接的协议`TCP`如何操作。默认操作是`close`立即返回，但是如果有数据残留在套接字发送缓冲区中，系统将试着把这些数据发送给对端。

```C
struct linger{
    int     l_onoff;
    int     l_linger;
};
```

- `l_onoff = 0`; 那么关闭本选项，`l_linger`值被忽略。相当于默认设置。
- `l_onoff = 1, l_linger = 0`;     `TCP`将丢弃保留在套接字发送缓冲区中的任何数据，并发送一个`RST`给对端，而没有通常的四分组连接终止序列，这么一来避免了`TCP`的`TIME_WAIT`状态。
- `l_onoff = 1, l_linger = 1`;套接字关闭时内核会拖延一段时间，如果套接字发送缓冲区中仍有残留数据，那么进程将被投入休眠，直到所有数据都已发送完毕且均被对方确认或延滞时间到。

##### 四、`SO_REUSEADDR`选项
起到以下4个不同的作用：
&emsp;&emsp;(1) `SO_REUSEADDR`允许启动一个监听服务器并捆绑其众所周知端口，即使以前建立的将该端口用作他们的本地端口的连接仍然存在。这个条件通常是这样碰到的：
&emsp;&emsp;a)启动一个监听服务器
&emsp;&emsp;b)连接请求到达，派生一个子进程来处理客户，
&emsp;&emsp;c)服务器终止，子进程仍然继续为客户服务。
&emsp;&emsp;d)重启监听服务器。
&emsp;&emsp;默认情况下，当监听服务器在步骤d通过调用socket、bind和listen重新启动时，由于它试图绑定一个现有连接(早先派生的那个子进程的连接)上的端口，从而bind调用将失败。*如果服务器在socket和bind两个调用之间设置了`SO_REUSEADDR`套接字选项，bind将成功*。**所有TCP服务器都应指定本套接字选项，以允许服务器在这种情形下被重新启动**。

&emsp;&emsp;(2) `SO_REUSEADDR`允许在同一端口上启动同一服务器的多个实例，只要每个实例捆绑一个不同的本地IP地址即可。对于TCP，我们绝不可能启动捆绑相同的IP地址和相同的端口号的多个服务器。

&emsp;&emsp;(3) `SO_REUSEADDR`允许单个进程捆绑同一端口到多个套接字上，只要每次捆绑指定不同的本地IP即可。TCP服务器通常不使用这种方法。
&emsp;&emsp;(4) `SO_REUSEADDR`允许完全重复的捆绑：当一个IP地址和端口号已绑定到某个套接字上时，如果传输协议支持，同样的IP地址和端口还可以捆绑到另一个套接字上。一般来说本特性仅支持UDP套接字。`UDP`多播时，允许在同一主机上同时运行同一个应用程序的多个副本。

总结和建议：
&emsp;&emsp;(1) 在所有`TCP`服务器程序中，在调用`bind`之前设置`SO_REUSEADDR`选项。
&emsp;&emsp;(2) 当编写一个可在同一时刻在同一主机上运行多次的多播应用程序时，设置`SO_REUSEADDR`套接字选项，并将所参加多播组的地址作为本地IP地址捆绑。


—————————————
参考资料：
《UNIX网络高级编程》第三版第7章