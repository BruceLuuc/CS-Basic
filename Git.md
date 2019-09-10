#### Git和GitHub

windows下vscode push失败(去掉git的ssl验证)：git config --global http.sslVerify false

`
sudo apt update  # 更新源
`
`
sudo apt install software-properties-common # 安装 PPA 需要的依赖
`
`
sudo add-apt-repository ppa:git-core/ppa    # 向 PPA 中添加 git 的软件源
`
`
sudo apt install -y git 安装 Git
`
<br/><br/><br/>

git status 查看整个仓库的状态<br/>
git add [文件名] 命令跟踪此新建文件<br/>
git add . 命令全部添加到暂存区<br/>
git reset -- [文件名]撤销暂存区的修改<br/>
git reset -- 把暂存区的全部修改撤销<br/>
git diff查看工作区被跟踪的文件的修改详情<br/>
git diff --cached 查看暂存区的全部修改

对 Git 进行一些本地配置：
user.email：写入你自己注册 GitHub 账号的邮箱
user.name：你自己的 GitHub 账号名字

git config --global user.email "BruceLuu007@Gmail.com"
git config --global user.name "Bruce"
git config -l #查看配置信息

完成后，系统自动生成 Git 的配置文件，就是家目录中的隐藏文件 .gitconfig 

查看cat -n ~/.gitconfig

git commit -m 'commit message'提交

git branch -avv，它用来查看全部分支信息

git push  将本地新增的提交推送到 GitHub 远程仓库中(未上传秘钥前需要输入github用户名和密码)

git reset --soft HEAD^ 撤销最近的一次commit，将修改还原到暂存区

git push -f 强制推送

git reset --hard HEAD@{2} 回退到指定版本


- 每次提交都要手动输入用户名和密码，若想避免这些麻烦，可以在系统中创建 SSH 公私钥，并将公钥放到 GitHub 指定位置。如此操作即可生成 GitHub 账户对于当前系统中的 Git 授权。
+ 终端执行$ ssh-keygen 命令按几次回车生成公私钥，公私钥存放在家目录下的隐藏目录 .ssh 中的两个文件中
+ 然后将 ~/.ssh/id_rsa.pub 文件中的公钥内容复制github：
+ $cat ~/.ssh/id_rsa.pub #复制终端的公钥内容到github

> 重要的一点：只有使用这种 **git** 开头的地址克隆仓库，SSH 关联才会起作用。

使用 SSH 的好处主要有两点：

- 免密码推送，执行 git push 时不再需要输入用户名和密码了；
- 提高数据传输速度。


#### Git 分支管理


在 GitHub 页面上对  文件进行修改并增加一次提交,在本地中执行 git fetch 命令，fetch 命令的作用是刷新保存在本地仓库的远程分支信息，此命令需要联网。此时若想使本地 master 分支的提交版本为最新，可以执行 git pull 命令来拉取远程分支到本地，pull 是拉取远程仓库的数据到本地，需要联网，而由于前面执行过 git fetch 命令，所以也可以执行 $git rebase origin/master 命令来实现 “使本地 master 分支基于远程仓库的 master 分支”,执行 git branch -avv 查看分支信息.

在自己的分支上进行修改，然后向 master 分支提 PR（pull request），最后从 master 分支推送到线上。

#### 创建分支

git branch [分支名] 创建新的分支
git checkout [分支名] 切换分支
git checkout -b [分支名] 创建分支并切换到新分支(常用，创建完直接切换到新分支)


例如：
git checkout dev     #创建新分支
git checkout -b dev1 #创建并切换到新分支

在新分支dev1上修改并commit提交后，新功能已经写好并提交到了版本区，现在要推送了。
git push [主机名] [本地分支名]:[远程分支名] 即可将本地分支推送到远程仓库的分支中，通常冒号前后的分支名是相同的，如果是相同的，可以省略 :[远程分支名]，如果远程分支不存在，会自动创建：

$git push origin dev1:dev1  #可简写为git push origin dev1

git branch -u [主机名/远程分支名] [本地分支名] 将本地分支与远程分支关联。(设置当前所在分支跟踪远程分支，最后一个参数本地分支名可以省略不写)如：git branch -u origin/dev1

推送时自动跟踪远程分支:加个-u即可，如：git push -u origin dev
(推送并跟踪dev)


#### 删除远程分支

git push [主机名] :[远程分支名]   # 删除远程分支
git push origin :dev1 #注意和提交对比git push origin dev1
:dev前为空为以空格  提交一个空分支 自然就是删除了。


#### 本地分支的更名与删除

 git branch -D [分支名] 删除本地分支
 git branch -m [原分支名] [新分支名]

如：git branch -m ved #新名字为ved
git branch -D ved dev1 #删除ved和dev1分支，必须切换出去



#### 多人协作github部分

同步主仓库：git remote add [主机名] [主仓库的地址]
如：git remote add up https://.....(up自己定的名)

#### Git标签tag和GitHub版本releases

git tag v1.0 -m '发布项目正式版本1.0'
git tag 显示仓库中的全部标签列表
git show v1.0 | cat  #查看标签详情

当我们执行 git add [标签名] 创建本地标签后，在仓库主目录的 .git/refs/tags 目录下就会生成一个标签文件：
tree .git/refs/tags

