#  数据库和SQL概念

####  一、简介
**数据库（Database）**是按照数据结构来组织、存储和管理数据的仓库。
结构化查询语言(Structured Query Language)简称 SQL.
在WEB应用方面 MySQL 是最好的 RDBMS(Relational Database Management System关系数据库管理系统)应用软件之一。
#### 二、安装和启动

```
//安装 MySQL 服务端、核心程序
sudo apt-get install mysql-server
// 安装 MySQL 客户端
sudo apt-get install mysql-client
安装结束后，用命令验证是否安装并启动成功：
sudo netstat -tap | grep mysql 

//启动 MySQL 服务
sudo service mysql start
//使用 root 用户登录，实验楼环境的密码为空，直接回车就可以登录
mysql -u root -p
```
SQL中的通配符是 _ 和 % 。其中 _ 代表一个未指定字符，% 代表不定个未指定字符。

约束类型：|	主键 | 默认值 | 唯一 | 外键 | 非空
------------ |----- |----------| -----|------|-------
关键字： | PRIMARY KEY | DEFAULT | UNIQUE | FOREIGN KEY | NOT NULL

**主键 (PRIMARY KEY)**是用于约束表中的一行，作为这一行的唯一标识符，在一张表中通过主键就能准确定位到一行，因此主键十分重要，主键不能有重复记录且不能为空。

**唯一约束 (UNIQUE) **比较简单，它规定一张表中指定的一列的值必须不能有重复值，即这一列每个值都是唯一的。

**外键 (FOREIGN KEY) **既能确保数据完整性，也能表现表之间的关系。一个表可以有多个外键，每个外键必须 REFERENCES (参考) 另一个表的主键，被外键约束的列，取值必须在它参考的列中有对应值。

#### 三、数据库原理相关

-   第一项
+   第二项
-   第三项
+   第四项
-   第五项
+   第六项
[百度](https://www.baidu.com)







