#### 跟我一起来玩转Makefile

在执行make的时候，我们可以带上-f <文件名>参数，来指定make命令从哪里读取makefile文件；而如果我们不显式指定，则make就会在当前目录下依次查找名字为GNUmakefile, makefile,和 Makefile的文件来作为其makefile文件。

精确的分析清楚项目的依赖关系，是编写一个好的makefile的关键。

makefile中“#”字符后的内容被作为是注释内容（和shell脚本一样）处理。

如果此行的第一个非空字符为“#”，那么此行为注释行。

注释行的结尾如果存在反斜线（\），那么下一行也被作为注释行。




