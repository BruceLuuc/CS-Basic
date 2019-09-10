## *vim*学习笔记


> 定义快捷键的前缀为`;` `let mapleader=";"`
  任何时候都要使用非递归映射：`nnoremap`、`vnoremap`,`nore`非递归的意思。


#### 一、多文件与多窗口操作
` vim -r 1 ` 恢复1
` vim 1 2 `
`:n` 转到2
`:N` 转到1
`:e 3` 新打开3
`:e#` 回到前一个文件
`:b 2` 回到2
`;h/j/k/l`或`;gg` 窗口间跳转

#### 二、视图操作
普通模式下输入`v`进入选择模式
`shift+v`行选择
`Ctrl+v`区域选择
例：选中一竖列后 `r+# `第一列变为 #

#### 三、屏幕控制
`H` 跳转到当前屏幕最上方
`M` 屏中央
`L `跳转到当前屏幕最下面一行
`Ctrl+f(;u) `向下翻屏
`Ctrl+b(;d)` 向上翻屏
`;s` 水平分屏
`;v` 竖直分屏

#### 四、代码编辑与阅读
`;n `打开目录树
`;m `打开函数和变量树显示
`;gt`跳转函数定义的地方(需安装`ctags`,并先输入`;tg`)
`;gr ` 跳回，对应着`;gt`
`;tg ` 对当前目录打`ctag` 
`;gg` 文件目录、函数、代码区转换
`gcc` 注释当前行
`gc` 注释块
`;a` 切换.h和.cpp
`F1` 一键编译


#### 五、基本编辑
`w` 下一个单词
`b` 上一个单词
`cw` 删除后insert
`x` 删除游标所在字符
`dd` 删除整行, `6dd`删除6行
`dw` 删除单词
`gg` 第一行
`G ` 最后一行
`0`  或者`^`或者`;1` 行首 
`$ ` 或者`;2`行尾 
`o`  open a line below
`cc`删除整行直接插入
`O`  行前插入
`/word`  查找word 回车后按`n/N`循环查找
`Ctrl+r/u`  撤销/重做 
`yy` 复制当前行
`y0(y^)` 复制到行首
`y$` 复制到行尾
`yw` 复制一个单词
`p` 黏贴


#### 六、插件篇
> vim-plug、Vundle、Pathogen、DeinVim、volt --**plugin manager**
nerdtree  --**file drawer**
ctrlp  --**fuzzy file finder**
fugitive  --**git tool**
syntastic  --**syntax checker/linter**

https://vimawesome.com //插件搜索网站
github.com/vim-airline/vim-airline //状态栏美化
github.com/yggdroot/indentline  //代码缩进线条

#### 七、Vim-Plug
1.安装
- 方式一：` curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim `
- 方式二：
`
mkdir ~/.vim/autoload/
cd ~/.vim/autoload/
wget https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
`

2.在.vimrc中添加：
```C
call plug#begin('~/.vim/plugged')
//把GitHub地址放这里，重启后执行:PlugInstall(或者在vim中:source ~/.vimrc)重新加载配置
Plug 'mhinz/vim-startify'
Plug 'scrooloose/nerdtree'
//...等等插件地址
call plug#end()
```

3.vim-plug操作
`PlugStatus` 检查现在 plug 负责的插件状态
`PlugInstall` 安装配置好的插件
`PlugUpdate` 更新已安装的插件
`PlugClean` 清理插件，在.vimrc里面删除或注释掉先
`PlugUpgrade` 升级自身


-------------------------------------------------
参考资料:
[1] Carl. [PowerVim](https://github.com/youngyangyang04/PowerVim)
[2] [玩转Vim 从放弃到爱不释手](https://www.imooc.com/learn/1129)
[3] [vim+tmux OMG!Code](https://youtube.com/watch?v=5r6yzfexajq&t=2019s)














