# Git related

看起来好多同学似乎在Git配置出现了困难. 这里分享下Camber自己配置的经验.

## 0x01 Installing Git

### On Windows 10 
从Git-scm下载Git套件, 安装.  
Windows insider build可以在Powershell下使用`winget`下载: `winget install Git.Git`.(好像是这个, 不保证准确性)

### On Windows Subsystem Linux (WSL) [私货警告]
WSL是Windows10的一个特性, 可以在Windows上原生使用Linux终端执行Linux二进制文件. Linux的一个优点是环境配置极其方便, **拱拱本人推荐这种方式.**  
在`启用和删除Windows功能`上把`适用于Windows的Linux子系统`勾选上, 重启电脑后去Windows store搜索下载Ubuntu(推荐的)即可使用. WSL配置过程略. 

有Linux环境就好说了, Ubuntu自带OpenSSH套件和Git. 如果需要访问本地文件的话, 他们一般在`/mnt/盘符`处.

### Linux
都用上Linux了拱拱觉得也不需要说啥了, 忽略吧.

## 0x02 OpenSSH 相关配置
Windows 10 自带OpenSSH套件.  
要用到的主要命令是`ssh-keygen`.  
一般直接就这么输入进命令行就行了. 可以不用带任何参数.

跑完后你会得到一个 私钥文件 `id_rsa` / 公钥文件 `id_rsa.pub`, 位于`~/.ssh/`  
在Windows下`~` = `C:\Users\你用户名\`
在Linux下`~` = `/home/你用户名` (如果是root账户的话就是`/root/`)

### Github相关
Github 在处理用户鉴权时, 使用SSH公钥或HTTPS认证.  
也就意味着你的远端可以是 `git@github.com/后略`[ssh] 或者 `https://github.com/后略`[https]

使用SSH公钥时, 前往 https://github.com/settings/keys 将得到的`id_rsa.pub`内容复制粘帖到New SSH key中.  
使用HTTPS认证时, 一般不需要做什么, 但就是在处理私有仓库(Private Repo)或者Push时会有一个交互, 让你填写用户名和密码. **拱拱本人不推荐这个方式.**  

## 0x03 Git 基本配置

### 前期配置
在Commit前需要设置邮箱和名字: 
`git config --global user.name "你名字, 可以是中文"`
`git config --global user.email "你邮箱"`

如果vim使不来的话, 可以更换默认文本编辑器
`git config --global core.editor ""`
参考 https://help.github.com/cn/github/using-git/associating-text-editors-with-git  
私货: 这里推荐VSCode[GUI/图形界面] 和nano[CLI/命令行界面]


### Git add相关
该命令用于暂存文件. 暂存过的文件才能被Commit提交和Push推送.  
可以使用`git add *`暂存所有已保存到本地的修改. **在使用前请注意.**

### Git commit相关
该命令用于提交暂存的修改.  
在[前期配置](#前期配置)中, 有说明关于文本编辑器的事情.
如果不想使用文本编辑器, 也可以使用`-m "信息"`参数.
携带`--allow-empty-message`参数可以允许一个信息为空的提交. **不推荐, 实在没东西写了再用.**

### Git push/pull
`git push`用于向远端推送你已经*提交*(commit)的更改. 请注意只能在**自己已经没有任何更改可以拉取**(窝觉得用`最新`不妥)的情况下推送.  
`git pull`用于从远端拉取最新的更改.

如果出现了文件冲突, 可以参考`Git merge`相关文档. 拱拱没用过所以就不说了.  
从Git 2.26还是27开始, 执行Git pull时有如下提示:

> warning: 不建议在没有为偏离分支指定合并策略时执行 pull 操作。 您可以在执行下一次  
> pull 操作之前执行下面一条命令来抑制本消息：
> 
> git config pull.rebase false  # 合并（缺省策略） 
> git config pull.rebase true   # 变基  
> git config pull.ff only       # 仅快进  
> 
> 您可以将 "git config" 替换为 "git config --global" 以便为所有仓库设置  
> 缺省的配置项。您也可以在每次执行 pull 命令时添加 --rebase、--no-rebase，  
> 或者 --ff-only 参数覆盖缺省设置。

窝也没有去了解那么多. 如有需要可以阅读相关文档.  

## 0xFE vim相关
声明: 我使不来.  

最基本的操作是
`i`: 进入编辑模式, 按下`esc`退出
`:wq`: 保存后退出
`:q`: 一般退出
`:q!`: 不保存退出/强制退出

## 0xFF GPG相关
GPG的作用是证明 **你是你自己**. 社会的基本问题.  
如果有需要的话可以参考Github的GPG配置相关文档.

## Reference
https://help.github.com/cn/github 只有这个了.
英文版 https://help.github.com/en/github
