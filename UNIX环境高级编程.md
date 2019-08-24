

#### <center> 第1章 `UNIX`基础知识 </center>

- 从严格意义上说，可将操作系统定义为一种软件，它控制计算机硬件资源，提供程序运行环境，通常将这种软件称为内核(kernel)。内核的接口被称为系统调用(system call)，公用函数库构建在系统调用接口之上，应用程序即可使用公用函数库也可使用系统调用。
- 当创建一个新目录时，自动创建了两个文件名：`.`(称为点)和`..`(称为点点)。点引用当前目录，点点则引用父目录。在最高层次的根目录中，点点与点相同。

+ 文件描述符(file descriptor)是一个小的非负整数，内核用以标识一个特定进程正在存访的文件。当内核打开一个现存文件或创建一个新文件时，它就返回一个文件描述符。当读、写文件时，就可使用它。

- 每当运行一个新程序时，所有的shell都为其打开三个文件描述符：标准输入(standard input)、标准输出(standard output)以及标准错误(standard error)。
- 函数open、read、write、lseek以及close提供了不带缓冲的I/O，这些函数都使用文件描述符。

##### 程序和进程
> 程序(program)是一个存储在磁盘上某个目录中的可执行文件。内核使用`exec`函数(7个`exec`函数之一)，将程序读入内存，并执行程序。

> 程序的执行实例被称为进程(process)，某些操作系统用任务(task)表示正在被执行的程序。
> UNIX系统确保每个进程都有一个唯一的数字标识符，称为进程ID（process ID）。进程ID总是一非负整数。

> 有三个用于进程控制的主要函数： `fork`、`exec`和`waitpid`,  `exec`函数有7种变体，但经常把它们统称为`exec`函数
> 与进程相同，线程也用ID标识。但是线程ID只在她所属的进程内起作用。一个进程中的线程ID在另一个进程中没有意义。



#### <center> 第3章 文件`I/O` </center>

##### 3.1 引言
&emsp;&emsp;文件I/O函数：打开文件，读文件，写文件.
&emsp;&emsp;常用到五个函数：`open`, `read`, `write`, `lseek`, `close`.
&emsp;&emsp;本章描述的函数都是：不带缓冲的I/O(unbuffered I/O)，属于不带缓冲 是指每个`read`和`write`都是调用内核中一个系统调用。

##### 3.2 文件描述符

&emsp;&emsp;对于内核而言，所有打开的文件都是通过文件描述符引用的.文件描述符是一个非负整数。当打开
&emsp;&emsp;一个现存文件或创建一个新文件时，内核向进程返回一个文件描述符。
&emsp;&emsp;当读或写一个文件的时候，使用`open`或`creat`返回的文件描述符标示该文件，将其参数传给`read`或`write`.
&emsp;&emsp;通常文件描述符0与标准输入关联，1与标准输出关联，2与标准错误关联，替换成`STDIN_FILENO`, `STDOUT_FILENO`, `STDERR_FILENO`以提高可读性。


##### 3.3 函数open和openat

&emsp;&emsp;调用`open`函数可以打开或创建一个文件。

```C
#include<fcntl.h>
int open(const char *path, int oflag, .../*mode_t mode*/);
int openat(int fd, const char *path, int oflag, .../*mode_t mode*/)
//若成功,返回文件描述符，若出错，返回-1
```

&emsp;&emsp; `path`参数是要打开或创建文件的名字。
&emsp;&emsp; `oflag`参数：
数字|    常量  |  含义
---|----------|-------
 0 | O_RDONLY | 只读打开
 1 | O_WRONLY | 只写打开
 2 | O_RDWR   | 读写打开
  \  |O_EXEC　|只执行打开
   \ |O_SEARCH　|只搜索打开

&emsp;&emsp;由`open`和`openat`函数返回的文件描述符一定是最小未用的文件描述符数值。

&emsp;&emsp;*fd*参数把`open`和`openat`函数区分开：
&emsp;&emsp;1）path参数指绝对路径，fd被忽略，此时openat函数相当于open函数。
&emsp;&emsp;2）path指相对路径，fd参数指出了相对路径名在文件系统中的起始地址．fd参数是通过打开相对路径文件名所在的文件目录获取。
&emsp;&emsp;3）path参数指定了相对路径名，fd参数具有特殊值`AT_FDCWD`,这种情况下，路径名在当前工作目录中获取，openat在操作上与open类似。

##### 3.4 函数create


```C
#include <fcntl.h>
int creat(const char *path, mode_t mode);
//若成功,返回为只写打开的文件描述符，若出错返回-1
```
&emsp;&emsp;注意，此函数等效于：

```C
open(path, O_WRONLY｜O_CREAT｜O_TRUNC, mode);
```

> &emsp;&emsp;在早期的UNIX系统版本中， open的第二个参数只能是0、1或2。没有办法打开一个尚未存在的文件，因此需要另一个系统调用create以创建新文件。现在， open函数提供了选择项O_CREAT和O_TRUNC，于是也就不再需要creat函数了。

&emsp;&emsp;creat的一个不足之处是它只能以只写的方式创建文件。在提供open的新版本之前，如果想创建一个临时文件，然后再读这个临时文件，必须先调用creat,close然后再调用open，现在可以直接调用open实现：
```C
open(path, O_WRONLY｜O_CREAT｜O_TRUNC, mode);
```


##### 3.5 函数close
&emsp;&emsp;可以调用`close`函数关闭文件
```C
#include<unistd.h>
int close(int fd);//成功返回0，出错返回-1
```
&emsp;&emsp;关闭一个文件时还会释放该进程加在该文件上的所有记录锁。
&emsp;&emsp;当一个进程终止时，内核自动关闭它所有的打开文件，很多程序都利用了这一功能而不显式地用close关闭打开文件。

##### 3.6 函数lseek

&emsp;&emsp;每个打开文件都有一个与其相关联的“当前文件偏移量”(current file offset)。它是一个非负整数，用以度量从文件开始处计算的字节数。通常，读、写操作都从当前文件位移量处开始，并使位移量增加所读或写的字节数。按系统默认，当打开一个文件时，除非指定`O_APPEND`选择项，否则该位移量被设置为0。

&emsp;&emsp;可以调用`lseek`显式地为一个打开文件设置文件偏移量:
```C
#include<unistd.h>
off_t lseek(int fd, off_t offset, int whence);
//若成功，返回新的文件偏移量
```

对参数*offset*的解释与参数whence的值有关。
- *whence* 是`SEEK_SET`，将文件的偏移量设置为距文件开始处`offset`
+ *whence* 是`SEEK_CUR`，将文件的偏移量设置为当前值加`offset`
- *whence* 是`SEEK_END`，将文件的偏移量设置为文件长度加上`offset`, `offset`可为正可为负

&emsp;&emsp;可以用下列方式确定打开文件的当前偏移量。
```C
   off_t currpos;
   currpos=lseek(fd,0,SEEK_CUR);
```

&emsp;&emsp;`lseek`仅将当前的文件偏移量记录在内核中，它并不引起任何的I/O操作．偏移量用于下一个读写操作。


##### 3.7 函数read

```C
#include <unistd.h>
ssize_t read(int fd, void *buf,size_t nbytes);
//返回：读到的字节数，若已到文件尾返回0，若出错，返回-1
```
&emsp;&emsp;若read成功。返回读到的字节数。如果已到达文件尾端，返回0.

##### 3.8 函数write

```C
#include<unistd.h>
ssize_t write(int fd, const void *buf, size_t nbytes);
```
&emsp;&emsp;若成功，返回已写的字节数；若出错，返回-1，其返回值通常与参数`nbytes`相同，否则表示出错。

##### 3.9 I/O的效率
&emsp;&emsp;大多数文件系统为改善性能都采用了某种预读技术(read already)。Linux ext4文件系统，其磁盘块长度4096字节，4096之后继续增加缓冲区长度对时间几乎没有影响。




#### <center> 第4章 文件和目录 </center>

##### 4.2 函数  stat、fstat、fstatat 和 lstat

&emsp;&emsp;本章主要讨论4个`stat`函数以及他们的返回信息，使用`stat`函数最多的地方可能就是`ls -l`命令，用其可以获得相关文件的所有信息。

```C
#include <sys/stat.h>
int stat(const char *restrict pathname, struct stat *restrict buf );
int fstat(int fd, struct stat *buf );
int lstat(const char *restrict pathname, struct stat *restrict buf );
int fstatat(int fd, const char *restrict pathname,struct stat *restrict buf, int flag);
//All four return: 0 if OK, −1 on error
```

一旦给出`pathname`，`stat`函数将返回与此命名文件有关的信息结构。
第二个参数`buf`是一个指针，它指向一个我们必须提供的结构`stat`，基本形式如下：

```C
struct stat {
   mode_t st_mode;         /* file type & mode (permissions) */
   ino_t st_ino;           /* i-node number (serial number) */
   dev_t st_dev;           /* device number (file system) */
   dev_t st_rdev;          /* device number for special files */
   nlink_t st_nlink;       /* number of links */
   uid_t st_uid;           /* user ID of owner */
   gid_t st_gid;           /* group ID of owner */
   off_t st_size;          /* size in bytes, for regular files */
   truct timespec st_atim; /* time of last access */
   struct timespec st_mtim; /* time of last modification */
   struct timespec st_ctim; /* time of last file status change */
   blksize_t st_blksize;   /* best I/O block size */
   blkcnt_t st_blocks;     /* number of disk blocks allocated */
};
```
##### 4.3 文件类型

> 1）普通文件(regular file)
> 2)目录文件(directory file).包含了其他文件的名字以及指向与这些文件有关信息的指针。对一个目录文件具有读权限的任一进程都可以读该目录的内容，但只有内核可以直接写目录文件。
> 3）块特殊文件(block special file)
> 4）字符特殊文件(character special file).系统中的所有设备要么是字符特殊文件，要么是块特殊文件。
> 5）FIFO.用于进程间通信，有时也称为命名管道(named pipe).
> 6）套接字(socket).用于进程间网络通信。
> 7）符号链接(symbolic link).指向另一个文件。


可用宏确定文件类型：
Macro | Type of file
---|----------
S_ISREG() | regular file
S_ISDIR() | directory file
S_ISCHR() | character special file
S_ISBLK() | block special file
S_ISFIFO()| pipe or FIFO
S_ISLNK() | symbolic link
S_ISSOCK()| socket
S_TYPEISMQ() | 消息队列
S_TYPEISSEM() | 信号量
S_TYPEISSHM() | 共享存储对象

实例4-3：
```C
int main(int argc,char*argv[]){
    int i;
    struct stat buf;
    char *ptr;
    for(i=1;i<argc;i++){
        printf("%s:",argv[i]);
        if (lstat(argv[i],&buf)<0){
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if (S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(buf.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "** unknown mode **";
        printf("%s\n", ptr);
    }
    exit(0);
}
```
编译运行：

> \$ ./a.out &emsp; /etc/passwd &emsp; /etc  &emsp;/dev/log&emsp; /dev/tty \
\> /var/lib/oprofile/opd_pipe &emsp; /dev/sr0 &emsp; /dev/cdrom
/etc/passwd: regular
/etc: directory
/dev/log: socket
/dev/tty: character special
/var/lib/oprofile/opd_pipe: fifo
/dev/sr0: block special
/dev/cdrom: symbolic link

##### 4.5 文件访问权限

`st_mode`值也包含了对文件的访问权限位。所有文件类型(目录、字符特别文件等)都有访问权限(access permission).
每个文件有9个访问权限，如下：
st_mode mask | Meaning
---|----------
S_IRUSR | user-read
S_IWUSR | user-write
S_IXUSR | user-execute
S_IRGRP | group-read
S_IWGRP | group-write
S_IXGRP | group-execute
S_IROTH | other-read
S_IWOTH | other-write
S_IXOTH | other-execute


- 打开任一类型的文件时，对该名字包含的每一个目录具有执行权限。例如；为了打开文件`/usr/include/stdio.h` ，需要对目录 `/` 、 `/usr` 和 `/usr/include` 具有执行权限。对于目录的读权限和执行权限的意义是不相同的。读权限允许我们读目录，获得在该目录中所有文件名的列表。
- 删除一个现有文件，必须对该文件的目录具有写权限和执行权限，对该文件本身不需要读写权限。
  
进程每次打开、创建或删除一个文件时，内核就进行文件访问权限测试。









#### <center> 第5章 标准`I/O`库 </center>

#### 5.1 引言
本章讲述标准I/O库，标准I/O库是由Dennis Ritchie在1975年左右编写的，令人惊讶的是，45年来，几乎没有对标准I/O库进行修改。
#### 5.2 流和FILE对象
当用标准I/O库打开或创建一个文件时，我们已使一个流与一个文件相关联。
只有两个函数可改变流的定向。freopen函数清除一个流的定向，fwide函数可用于设置流的定向。
#### 5.4 缓冲
标准I/O库提供缓冲的目的是尽可能减少使用read和write调用的次数。
标准I/O提供了3种类型的缓冲。
1）全缓冲。填满标准I/O缓冲区后才进行实际I/O操作。
2）行缓冲。当在输入和输出中遇到换行符时，标准I/O库执行I/O操作。终端通常使用行缓冲。
3）不带缓冲。标准错误流stderr通常是不带缓冲的，这样错误信息就可以尽快显现出来。
```C
#include <stdio.h>
void setbuf(FILE *restrict fp, char *restrict buf);
int setvbuf(FILE *restrict fp, char *restrict buf, int mode,size_t size);
/* 成功返回0；出错返回非0 */
```
可以使用setbuf函数打开或关闭缓冲机制，参数buf必须指向一个长度为BUFSIZE的缓冲区(定义在<stdio.h>)，通常此后该流就是全缓冲的。关闭缓冲，将buf设置为NULL.
使用setvbuf，可以精确地说明所需的缓冲类型，用mode参数实现。
任何时候我们都可以强制冲洗一个流
```C
#include <stdio.h>
int fflush(FILE *fp);
/** 成功返回0；出错返回EOF **/
```


#### 5.5 打开流
```C
#include <stdio.h>
FILE *fopen(const char *restrict pathname, const char *restrict type);
FILE *freopen(const char *restrict pathname, const char *restrict type, FILE *restrict fp);
FILE *fdopen(int fd,const char *type);
/** 成功返回文件指针，出错返回NULL **/
```
fdopen函数取一个已有的文件描述符，并使一个标准的I/O流与该描述符相结合。常用于由创建管道和网络通信通道函数返回的描述符。
调用fclose关闭一个打开的流。
```C
#include <stdio.h>
int fclose(FILE *fp);
```

#### 5.6 读和写流
一旦打开了流，则可在3种不同类型的非格式化I/O中进行选择。
1）每次一个字符的I/O。
2）每次一行的I/O。
3）直接I/O。

以下三个函数可用于一次读一个字符。
```C
#include <stdio.h>
int getc(FILE *fp);
int fgetc(FILE *fp);
int getchar(void);
/** **/
```
函数getchar等同于getc(stdin),getc可被实现为宏，fgetc不能。

对应上面所述的每个输入函数都有一个输出函数：
```C
#include <stdio.h>
int putc(int c, FILE *fp);
int fputc(int c,FILE *fp);
int putchar(int c);
```

#### 5.7 每次一行I/O

```C
#include <stdio.h>
char *fgets(char *restrict buf, int n, FILE *restrict fp);
char *gets(char *buf);
/** 成功返回buf，若已到达文件尾端或出错，返回NULL **/
```

这两个函数都指定了缓冲区的地址，读入的行送入其中。
gets从标准输入读，fgets从指定的流读。
gets是一个不推荐使用的函数，可能造成缓冲区溢出。

fputs和puts提供每次输出一行的功能。
```C
#include <stdio.h>
int fputs(const char *restrict str, FILE *restrict fp);
int puts(const char *str);
```
#### 5.9 二进制I/O
```C
size_t fread(void *restrict ptr, size_t size,size_t nobj,FILE *restrict fp);
size_t fwrite(const void *restrict ptr,size_t size,size_t nobj, FILE *restrict fp);
```
















#### <center> 第7章 进程环境 </center>
#### 7.2 main函数
C程序总是从main函数开始执行，main函数原型是：

```C
int main(int argc, char *argv[]);
```
`argc`是命令行参数的数目，`argv`是指向参数的各个指针所构成的数组。

#### 7.3 进程终止
`_exit`和`_Exit`立即进入内核，`exit`则先执行一些清理处理，然后返回内核。
`main`函数返回一个整型值与用该值调用`exit`是等价的。

`exit(0);`等价于`return (0);`

#### 7.5 环境表
每个程序都接收到一张环境表，环境表也是一个字符指针数组。

#### 7.6 `C`程序的存储空间布局
- 正文段。CPU执行的机器指令部分。

+ 初始化数据段。
- 未初始化数据段。`BSS`段，`block started by symbol`
- 栈。
- 堆。堆位于未初始化数据段和栈之间。


#### <center> 第8章 进程控制 </center>

##### 8.2 进程标识
ID为0的进程通常是调度进程，常常被称为交换进程(`swapper`)。该进程是内核的一部分，它并不执行任何磁盘上的程序，因此也被称为系统进程。进程ID 1通常是init进程，在自举过程结束时由内核调用。

```C
#include <unistd.h>
pid_t getpid(void);  //返回值：调用进程的进程ID
pid_t getppid(void); //返回值：调用进程的父进程ID
```

##### 8.3 函数`fork`

一个现有的进程可以调用`fork`函数创建一个新进程。
```C
#include <unistd.h>
pid_t fork(void);
//返回值：子进程返回0，父进程返回子进程ID；若出错，返回-1
```
`fork`函数被调用一次，但返回两次。父进程和子进程共享正文段，子进程获得父进程数据空间、堆、和栈的副本。
一般来说，在fork之后是父进程先执行还是子进程先执行是不确定的，这取决于内核所使用的调度算法。

- `strlen()`不包含终止null字节的字符长度。
- `sizeof()`包括null.

父进程和子进程共享一个文件偏移量。

fork有以下两种用法。

1）一个父进程希望复制自己，使父进程和子进程同时执行不同的代码。

2）一个进程要执行一个不同的程序。`shell`，子进程从`fork`返回后立即调用`exec`。

#### 8.4 函数vfork
可移植的应用程序不应该使用这个函数。

`vfork`函数用于创建一个新进程，而该新进程的目的是`exec`一个新程序。shell的基本部分就是这样。

`vfork`保证子进程先运行，在它调用`exec`或`exit`之后父进程才可能被调度运行。
对于父进程已终止的所有进程，它的父进程都改变为init进程，我们称这些进程由init进程收养。

内核为每个终止进程保存了一定量的信息，所以当终止进程的父进程调用`wait`或`waitpi`d时，可以得到这些信息。



#### 8.6 函数`wait`和`waitpid`

当一个进程正常或异常终止时，内核就向其父进程发送`SIGCHLD`信号。
```C
#include <sys/wait.h>
pid_t wait(int *statloc);
pid_t waitpid(pid_t pid, int *statloc, int options);
```
#### 8.10 函数`exec`
当进程调用一种`exec`函数时，该进程执行的程序完全替换为新程序，而新程序则从其`main`函数开始执行。`exec`只是用磁盘上的一个新程序替换了当前进程的正文段、数据段、堆段和栈段。






#### <center> 第10章 信号 </center>

#### 10.1 引言
信号是软件中断。很多比较重要的应用程序都需要处理信号。信号提供了一种处理异步事件的方法。
#### 10.2 信号的概念
在头文件`<signal.h>`中，信号名都被定义为正整数常量(信号编号)。

很多条件可以产生信号：
- 按终止键。
- 硬件异常产生信号：除数为0、无效内存引用。
- 进程调用`kill(2)`函数可将任意信号发送给另一个进程或进程组。
- 用户可用`Kill(1)`命令将信号发送给其他进程。此命令只是`kill`函数的接口。常用此命令终止一个失控的后台进程。
- 当检测到某种软件条件已经发生，并将其通知有关进程时也产生信号。例如`SIGURG`(在网络连接上传来带外的数据)、`SIGPIPE`(在管道的读进程已终止后，一个进程写此管道)以及`SIGALRM`(进程所设置的定时器已经超时)。

信号是异步事件的经典实例。产生信号的事件对进程而言是随机出现的。在某个信号出现时，可以告诉内核按下列3种方式之一进行处理：

（1）忽略此信号。`SIGKILL`和`SIGSTOP`不能被忽略，他俩向内核和超级用户提供了使进程终止或停止的可靠方法。

（2）捕捉信号。为了做到这一点，要通知内核在某种信号发生时，调用一个用户函数。注意，不能捕捉`SIGKILL`和`SIGSTOP`信号。

（3）执行系统默认动作。绝大多数信号的系统默认动作是终止该进程。

#### 10.3 函数`signal`
UNIX系统信号机制最简单的接口是`signal`函数。
```C
#include <signal.h>
void (*signal(int signo, void (*func)(int)))(int);
                        成功返回以前的信号处理配置，出错返回SIG_ERR
```



#### 10.6 可重入函数
`Single UNIX Specification` 说明了在信号处理程序中保证调用安全的函数。这些函数是可重入的并被称为是异步信号安全的。除了可重入以外，在信号处理操作期间，它会阻塞任何会引起不一致的信号发送。
不可重入函数的几个特性：
1. 使用静态数据结构
2. 调用`malloc`或`free`
3. 是标准I/O函数。标准I/O库的很多实现都以不可重入方式使用全局数据结构。


#### 10.9 函数`kill`和`raise`

`kill`函数将信号发送给进程或进程组。`raise`函数则允许进程向自身发送信号。
```C
#include <signal.h>
int kill(pid_t pid, int signo);
int raise(int signo);
                    //OK return 0;  Error return -1
```

调用`raise(signo);`等价于调用`kill(getpid(), signo);`

kill的pid参数有以下4种不同情况：

-    `pid>0`   将该信号发送给进程ID为pid的进程。
-    `pid==0`  发送给同一进程组的所有进程。
-    `pid<0 `  发送给ID等于pid绝对值，而且发送进程具有权限向其发送信号的所有进程。
-    `pid==-1` 将信号发送给发送进程有权限向他们发送信号的所有进程。



#### 10.10 函数`alarm`和`pause`
使用`alarm`函数可以设定一个定时器(闹钟时间)，在将来的某个时刻该定时器会超时。当定时器超时时，产生`SIGALRM`信号。如果忽略或不捕捉此信号，则其默认动作是终止调用该`alarm`函数的进程。

```C
#include <unistd.h>
unsigned int alarm(unsigned int seconds);
```
每个进程只能有一个闹钟时间。

`pause`函数使调用进程挂起直至捕捉到一个信号。
```C
#include <unistd.h>
int pause(void);
```
只有执行了一个信号处理程序并从其返回时，`pause`才返回。在这种情况下，`pause`返回-1，`errno`设置为`EINTR`。

