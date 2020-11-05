# Linux

## Day 1

 ### Linux基础

#### 为什么学习linux

* 安全
* 稳定
* 费用低

#### 如何学习linux

* 操作系统

* 软件制作

  * shell
    * bash
    * zsh
    * sh
    * csh
  * 编辑器
  * 编译
  * gdb调试
  * 静态库和共享库
  * 项目工程管理
  * 系统编程(api)
### 常用命令

* history 查看历史信息
* ls 查看当前路径下的文件和文件夹
  * ls -l 显示详细信息
  * ls -a 显示所有文件
  * ls -R 递归显示当前目录和子目录的文件内容
  * ls -lrt 按照时间进行排序
  * ls *.c 星号代表任意多个字符
  * ls func.?  问号代表任意一个字符
* cd -- change dir
  * cd - 回到上次目录
  * $代表普通用户 #代表管理员
  * cd ~,cd,cd $HOME,cd /home/username可以回到家目录
* pwd查看当前目录
* mkdir 创建目录
  * mkdir [option] dirname1 dirname1
  * mkdir -p dirname1/dirname2 递归创建
* rmdir 删除目录
  * rm -r dirname1
  * 空目录只有. 和..
* which
  * which ls //ls命令所在路径
* tree 将目录以树状显示
* touch 创建文件
  * touch [option] filename1 filename2
* rm -rf *
* cp 拷贝文件或者目录
  * cp -r dir1 dir2
* mv 移动文件或者目录（剪切）
* cat 查看文件信息
* more 分页显示文件信息
* less 分页显示文件信息
* head 查看文件头 10行  head -n 5 显示5行
* tail 查看文件尾 10行 tail -n 5 显示5行
  * tail -f filename 跟踪文件 来了新信息可以立即显示

### unix系统目录结构

* /根目录
* /bin 可执行文件所在目录
* /lib 库目录 主要存放系统基本的动态共享库
* /media 挂在u盘 光盘等
* /mnt 为了让用户挂载别的文件系统
* /usr unix system resource 
* /usr/local 用户自己安装的软件
* /sbin 超级管理员root的可执行目录
* /proc 系统内存映射， 系统运行时会保留进程的一些信息
* /etc 配置文件 
* /dev 设备文件所在目录
* /etc/passwd  man 5 passwd 查看文件格式
* /home/user 用户文件

 *linux一切皆文件*

### 相对路径和绝对路径

* 以/开头是绝对路径
* 不以/开头是相对路径

### 统计信息

* wc filename 统计行数 单词数 字节数
  * wc -l 显示行
  * wc -w 显示单词
  * wc -c 显示字节数
* du -h 显示磁盘信息
  * du -h --max-depth=1
* df -h 显示系统磁盘空间

### 文件属性和用户组

![image-20201026113622405](D:\Study\CPlusLearn\image-20201026113622405.png)

权限-硬链接计数-用户-组-大小-时间-名称

* 文件权限标志位 d/wrx/r-x/r-x

  * d代表文件夹，-代表文件
  * 归属用户权限
  * 归属组权限
  * 其他用户权限

* r可读，w可写，x可执行，如果对应位置无权限写-

* 权限位数字表示法（8进制数）

  * rw- 110 -->6 用户位
  * r-- 100 -->4 组权限位
  * r-- 100 -->4 其他权限位
  * 三个数加起来+0 0644

* 硬连接计数

  * ln命令 --建立软硬链接 注意与拷贝的区别

    * ln sourcefile hardfil
    * 软链接  ln -s filesoft -> file
      * 快捷方式,不增加硬连接计数
  * unlink filename/rm filename
    * 减少硬连接计数，计数为0 就真正删除
  * 软连接和硬连接的区别？

### 改变文件权限

```
chmod
chmod [u|g|o|a] [+|-] [r|w|x|-] filename//a可以省略
//用数字
chmod 666 filename
```

* 目录可执行权限指 是否能进入目录

###  chown 改变用户

* chown 用户:组 文件名|目录
* chown 用户 文件名|目录

### chgrp改变组

###  查找

* find

  * find dir [option] 内容 

    * find ./ -name "*.c" //按名字查找

    * find./ -type f //按类型查找 (文件)

    * find ./ -type -d //文件夹类型

    * find ./ -size +1M //大于1M的文件

    * find ./ -size +1M -size -5M

    * find ./  -maxdepth 1 -size +1M

    * find ./  -maxdepth 1 -size +1M -exec ls -l {}\;

    * find ./  -maxdepth 1 -size +1M -ok ls -l {}\;

    * find./ -type f|xargs ls -l //xargs将find命令查找的结果分为若干块传递给ls-l命令

* grep
  * grep 内容 文件名
  * grep -v 排除
  * grep -rn 内容 可以递归 且 显示行数
* zip
  * zip -r dir.zip dir1 dir2// -r递归子目录
  * unzip dir zip
* gzip/gunzip 解压之后的格式是.gz
  * tar --最常用的打包工具 .tar.gz
    * tar zcvf dir.tar.gz sourcedir
    * tar zxvf dir.tar.gz //解压
      * -c 压缩
      * -v显示信息
      * -f指定压缩包名
      * -z gz格式压缩
      * tar[option] 压缩包名 原材料
    * tar jcvf dir.tar.bzip2 filename
    * tarjxvf dir.tar.bzip2
* rar
  * rar a  -r dir file //自动添加后缀 --打包
    * a代表压缩 -r递归子目录
    * rar a -r 压缩包名 原材料
  * rar x  -r 压缩包名

### 其他常用命令

* date
* alias
* umask 补码
* shutdown
  * init
  * poweroff
  * reboot
  * shutdown -h now

## Day 2

### Vim 

* 移动光标
  * 0 行首
  * $ 行尾
  * gg 文件得开头
  * G 文件得末尾
  * nG 到n行
* 删除
  * x 删除光标内容
  * X删除光标前内容
  * dw删除单词
  * d0删除光标到行首
  * d$删除到行尾
  * dd 删除光标所在行
  * ndd 删除光标所在行起得n行
* 撤销
  * u
  * ctrl+r反撤销
* 赋值粘贴
  * yy赋值所在行
  * p粘贴
  * P粘贴
  * nyy
  * ndd 剪切n行内容
  * r 替换
  * v 可视模式
* 内容查找
  * /content
    * n/N 进行遍历
* 格式调整
  * gg=G
  * << 向左移动一个tab
  * n<< n行左移一个tab
* man
  * K或者nK可以查看函数原型
* 编辑模式
  *  i 光标前插入
  * a 光标后插入
  * I行首插入
  * A行尾插入
  * o向上一行插入
  * O向下一行插入
  * s删除当前字母进入编辑模式
  * S删除当前行进入编辑模式
* 末行模式
  * :!ls -l
  * :%s /content1 /content2 /g
  * ZZ 保存
  * vsp  filename 分屏
    * qall
    * wqall
* shell设置vim快捷键： set -o vi 加入 ~/.bashrc

### gcc编译流程

#### gcc工作流程

hello.c---------->gcc -E （预处理、头文件展开、宏替换）（调用cpp）生成.i文件 ----------------> gcc -S hello.i (生成汇编指令，hello.s)-----------------> gcc -c 得到hello.o 将汇编编译为二进制文件，但是没有链接（调用as汇编命令）-------->链接(调用ld)---->a.out

* 当找不到头文件
  * gcc add.c -I ./include/
* 当没有设置宏
  * gcc add.c -I ./include/ -D DEBUG -o hello.out
* gcc  add.c -lstdc++
* 开启gdb选项用来调试 -g
* -Wall 开启警告
* g++ 编译c++代码
* -O 优化选项
* l 指定库名 -lxxx (其中xxx为中libxxx.so)
* -L包含库文件 

### 静态库制作(.a)

1. 编译为.o文件
   1. gcc -c *c -I include/
2. 将.o文件 打包  ar rcs libxxx.a file1.o file2.o
   1. ar rcs libCalc.a *o
3. 将头文件和库一起发布

### 动态库制作（.so）

1. 编译与位置无关的代码 生成.o 关键参数-fPIC

   1. gcc -fPIC -c *c -I include/

2. 将.o文件打包 关键参数-shared

   1. gcc -shared -o libCalc.so *.o

3. 将库与头文件一起打包

   

​      ![image-20201027202252664](C:\Users\Noisyes\AppData\Roaming\Typora\typora-user-images\image-20201027202252664.png)

* 使用 gcc main.c -o newapp -I include/ -L lib/ -lCalc

#### 使用动态库

* 将动态库加入/lib 或者/usr/lib
* 将库路径增加到 LD_LIBRARY_PATH 环境变量(生效一次，关闭shell就没了)
  * export LD_LIBRARY_PATH = *******:$LD_LIBRARY_PATH
* sudo vim /etc/ld.so.conf 将库路径增加到这个文件 
  * sudo ldconfig  -v

## Day 3

### makefile

#### 命名规则

* makefile
* Makefile

#### 三要素

* 目标
* 依赖
* 规则命令

#### makefile编写1

写法 ：

目标:依赖

tab 规则命令

```makefile
app: main.c add.c sub.c div.c mul.c
	gcc -o app -I /include main.c add.c sub.c div.c mul.c
	
```

执行： make

缺点：更改其中一个文件，所有代码重新编译

#### makefile编写2

* 考虑分解过程，先生成.o 文件 使用.o文件生成out文件。
  * 依赖文件如果比目标文件新，则重新生成目标文件

```makefile
# ObjFiles目标文件
ObjFiles = main.o add.o sub.o div.o mul.o
# 目标文件用法 $(var)
app:$(ObjFiles)
	gcc -o app -I ./Include main.o add.o sub.o div.o mul.o
main.o:main.c
	gcc -c main.c -I ./Include
sub.o:sub.c
	gcc -c sub.c -I ./Include
//后面重复
```

* make默认处理第一个目标

#### makefile编写3

函数：

​	wildcard 文件匹配

​	patsubst 内容替换

变量：

	* $@ 代表目标
	* $^ 代表全部依赖
	* $< 第一依赖
	* $? 第一个变换的依赖

```makefile
#得到所有.c文件
SrcFile= $(wildcard *.c)
#all .c files -->.o files
ObjFiles = $(patsubst %.c,%.o,$(SrcFiles))
# 目标文件用法 $(var)
app:$(ObjFiles)
	gcc -o app -I ./Include $(ObjFiles)
#$< 和 $<这样的变量，只能在规则中出现
%.o:%.c
	gcc -c $< -I ./Include -o $@
//后面重复
```

#### makefile4

```makefile
#得到所有.c文件
SrcFile= $(wildcard *.c)
#all .c files -->.o files
ObjFiles = $(patsubst %.c,%.o,$(SrcFiles))
all:app
# 目标文件用法 $(var)
app:$(ObjFiles)
	gcc -o app -I ./Include $(ObjFiles)
#$< 和 $<这样的变量，只能在规则中出现
%.o:%.c
	gcc -c $< -I ./Include -o $@
//后面重复
.PHONY:clean all#伪目标，不是生成目录中的真正目标 消除歧义
clean:
	-@rm -f *.o #@可以不看命令 -代表报错仍然继续执行
	-@rm -f app
```

* make -f makefilename

### gdb调试

* 使用gdb 编译的时候使用 -g

`gcc func.c main.c -o app -I ./Include -g`

* gdb app(启动gdb)
* 在gdb里面启动程序

  * run
  * start //分步调试 停留在main函数
  * n(ext) //下一步
  * s(tep) //下一步 进入函数内部
  * quit 推出gdb
* 提供参数
    * set args 10 6
    * run
    
* 设置断点

  * list 看代码
  * b 17 //break 17行设置断点（主函数所在文件的行号）
  * run //停留断点
  * b sum //设置函数
  * b main.c:25 文件：行数
  * list func.c:1 展示func.c文件
  * info b 查看设置了几个断点
  * 删除断点 d(el) 4
  * c //跳到下一个断点
  * p(rint) 打印变量值
  * ptype 打印类型
  * set gdb过程中设置变量的值
    * set argc = 4;
    * set argv[1] = "12"

* 跟踪变量
    * display argc // 执行每个指令可以查看是否变换
    * info display
    * undisplay 编号 不跟踪
* 条件断点
    * b 32 if i==1 //在循环中设置条件断点

#### gdb跟踪core

* `ulimit -c unlimited`
* gdb app core // core是案发现场
  * where 告诉报错具体行数
* 设置core
  * /proc/sys/kernel/core_pattern
  * sudo su
  * echo "core-%e-%t" > /proc/sys/kernel/core_pattern
    * %e 进程名
    * %t时间戳

### 文件IO

* 查看linux函数 man 2 open
  * int open(const char * filename,int flag)
  * O_NONBLOCK非阻塞
  * 返回最小的可用文件描述符
* int close(int fd)
* read 读
* write 写
* lseek 移动文件读写位置

#### 阻塞

read函数在读设备或者读管道，或者读网络的时候，有一种等待状态。

输入输出设备对应/dev/tty

* fcntl()函数可以设置非阻塞

## Day 4

* ls -i filename 查看inode id

### stat函数

* pathname 文件名
* struct stat* buf 传出参数
* 返回值，成功为0，失败返回-1
* 需要使用getpwuid 获得用户名
* getgrgid() 获得组名
* localtime获取时间

### lstat

stat碰到连接，会追述到源文件，lstat不会穿透

### access函数

* 判断文件权限和是否存在

### chmod函数

* 更改文件权限

### truncate函数

* 截断文件
* 对应文件必须存在，长度大于源文件 直接拓展，小于直接截断。

### link 硬连接

### symlink 符号链接

### readlink

* 读取符号链接

### unlink

* 取消软硬连接
* 删除硬连接计数
* 有进程引用文件的时候不删除，进程结束最后再删除。

### chown

* int chown(const char* pathname,uid_t owner,gid_t group)
* pathowner
* owner 用户id /etc/passwd
* group 组id /etc/group

### rename

* 文件目录皆可以

### getcwd

目录相关函数

* 获得当前工作路径
  * 成功返回路径指针
  * 失败返回null

### chdir 

* 改变工作目录
  * 成功返回0
  * 失败返回-1
* mkdir 
  * 创建文件夹
  * 权限注意给0777,如果目录没有执行权限就不可进入

### opendir

* 打开目录

### readdir

* 读取目录

### closedir

* 关闭目录

### rewinddir

* 把目录指针恢复到起始位置

### telldir

### seelkdir

### strerror

* 输出错误信息

### dup2（int oldfd,int newfd）

* 关闭newfd所指文件描述符
* 将newfd指向oldfd所指向的文件描述符

### dup（int oldfd）

* 将最小的文件描述符，又指向oldfd指向的文件
## Day 5

* 什么是程序
  * 编译好的二进制文件 
* 什么是进程
  * 运行的程序
* 站在程序员的角度：运行一系列指令的过程
* 站在操作系统的角度：分配系统资源的基本单位
* 区别：
  * 程序占用磁盘，不占用系统资源
  * 内存占用系统资源
  * 一个程序对应多个进程，一个进程对应一个程序。
* MMU
  * 物理内存和虚拟内存的映射
  * 用户空间映射到物理内存是独立的

### PCB

​	linux进程控制块是task_struct

### 环境变量

* env

  * 写法key=value 不能有空格

* PATH

* SHELL

* TERM

* LANG

* HOME

* getenv 得到环境变量

### fork

* 返回值
  * 失败 -1
  * 成功 两次返回
    * 父进程返回子进程id
    * 子进程返回0

### getpid

* 获得当前进程的进程id

### getppid

* 获得当前进程父进程的id

### ps aux

* 查看进程信息

### ps ajx

* 可以看到进程组相关信息 能看到进程之间的血缘关系

### kill

* kill -l 查看信号
* 给进程发送信号
* kill -9 pid 或者kill -SIGKILL pid

### 父子进程不同

1. 进程id
2. fork返回值
3. 父进程id
4. 进程运行时间
5. 闹钟
6. 未决信号集
7. 全局变量

* 读时共享 写时复制

### exec族函数

* execl(const * *path,const char* *arg  );
  * 执行其他程序
* execlp(const char *file,const char* *arg  );
  * 执行程序的时候，使用path环境变量，执行的程序可以不用加路径
  * 参数列表最后需要一个null作为结尾，哨兵
  * 只有失败才返回

### 孤儿进程与僵尸进程

孤儿进程(orphan)：父亲死了，子进程被init领养

僵尸进程：子进程死了，父进程没有回收子进程的资源（PCB）

### wait

* 作用
  * 阻塞等待
  * 回收资源
  * 查看死亡原因(参考man手册)

* 回收子进程，知道子进程的死亡原因
* pid_t wait(* status)
  * status是传出参数
  * 返回值
    * 成功返回 终止的子进程ID
    * 失败 -1 

### waitpid

* pid 
  * <-1 -组id
  * =-1 回收任意
  * ==0 为回收和调用进程组id相同的子进程
  * 大于0回收指定进程
* option
  * 0与wait相同，也会阻塞
  * WNOHANG，不会阻塞，子进程没有退出也会立即返回
* 返回值
    * 如果设置了WNOHANG，那么如果没有子进程退出，返回0
      * 如果有子进程退出，返回退出id
    *  失败返回-1（没有子进程）

## Day 6

### IPC概念（进程间通信）

* inter process communication
* 通过内核提供的缓冲区进行数据交换
* 通信方式：
  * pipe 管道--只支持有血缘关系的进程之间
  * fifo 有名管道
  * mmap 文件映射共享IO --速度最快（操作内存）
  * 本地socket --最稳定

### pipe

### FIFO

* 注意事项，打开fifo文件的时候 先打开read端会阻塞等待打开write端，write端先打开同理。

### MMAP映射

* 创建映射区
  * mmap 
* 释放映射区
  * munmap
* 注意事项
  * 得到的内存地址mem不能更改
  * 文件大小，对于映射区长度有影响。
  * offset必须是4k的整数倍
  *  文件关闭 没有影响
  * 新创建的文件不行，文件长度为0会报错
  * O_WRONLY不行，必须O_RDWR
  * 选择shared，权限必须要有读写。
  * open选择的权限必须大于等于mmap映射区给的权限
  * 如果匿名映射的宏没有
    * /dev/zero 聚宝盆，可以随意映射
    * /dev/null 无底洞，一般错误信息可以重定向到这个文件中。
* 支持无血缘进程之间的通信
* 内存 谁都可以读取，fifo读了就没有了

## Day 7

信号的特点：简单、不能携带大量信息、满足特定条件发生

信号机制：进程b发送给进程a，本质上信号都是内核产生，内核处理的。

信号也叫软件中断，可能有延迟

### 产生信号

* 按键产生
  * ctrl+c ，ctrl+\， ctrl+z
  * 系统调用： kill raise
  * 定时器 alarm setitmer
  * 命令产生 kill
  * 硬件异常 段错误 浮点型错误 总线错误，SIGPIPE

* 信号的状态
  * 产生
  * 到达 信号到达并且处理完毕
  * 未决 信号被阻塞
* 信号默认处理方式
  * 忽略
  * 执行默认动作
  * 捕获
* 信号4要素
  * 编号
  * 事件
  * 名称
  * 默认处理动作
    * 终止
    * 忽略
    * 产生core
    * 暂停
    * 继续
* 信号的处理方式
  * 执行默认动作
  * 忽略
  * 捕捉
  * 9,19不能捕捉不能忽略，甚至不能阻塞。

### 未决信号集和阻塞信号集



### 函数信号

	* kill
	* raise
	* abort

### 时钟信号

* alarm
* 定时给自己发送sigalrm
* 参数，几秒后发送信号
* 返回值，上一次闹钟剩余秒数
* 参数设为0，取消闹钟
* 每个进程都有自己的时钟

### setitimer函数

* 周期性发送信号
* 一个进程只有一个时钟

### 信号集函数

* int sigemptyset(sigset_t *set)

* int sigfillset(sigset_t *set)

* int sigaddset(sigset_t *set,int signum)

* int sigdelset(sigset_t *set,int signum)

* int sigismember(sigset_t *set,int signum)

* sigprocmask(int how,const sigset_t *set,sigset_t *oldset)

  * 阻塞和接触阻塞信号集
  * how 宏定义 具体查看manpage

* sigpending(sigset_t *set)

  * 获取未决信号集
  * set为传出参数

### 信号捕捉

* 防止进程意外死亡
* signal(int signum,sighandler_t handler)
* sigaction

### 信号捕捉特性

* 在信号捕捉函数执行期间，相同信号会被临时屏蔽
* 未决信号集不支持排队，多次发送可能只能执行一次

### 信号回收子进程

* 借助SIGCHLD信号

## Day 8

### 守护进程

* 独立于终端的进程，关闭终端也可以继续执行

#### 进程组

* 多个进程在同一个组，第一个进程默认是组长

#### 会话

* 进程组的更高一级，多个进程组对应一个会话
* 组长不可以创建，必须是组员创建

#### 创建守护进程

1. 创建子进程，父进程退出
2. 在子进程中创建新的会话
3. 改变当前目录为~目录
   1. chdir
4. 重设文件权限掩码
   1. umask函数
5. 关闭文件描述符（0，1，2）为了避免浪费资源
6. 开始执行守护进程核心工作
7. 守护进程退出处理程序模型

#### 扩展了解

* 通过nohup指令也可以达到守护进程创建的效果
  * nohup cmd &
  * nohup 会让cmd收不到sighup信号
    * &代表后台运行

### 线程

* 轻量级的进程，本质仍是进程，一个进程内部可以多个线程，默认情况下一个进程只有一个线程
* 线程是最小执行单位，进程是最小的分配系统资源的单位
* 内核实现都是通过clone函数实现的
* 每个线程也有自己的pcb
* 线程可以看作寄存器和栈的集合
* ps -Lf pid 可以查看指定线程的lwp号
  * lwp可以理解成线程编号
* 线程中最好不要使用信号

### 线程共享资源

* 文件描述符
* 每种信号的处理方式
* 当前工作目录
* 用户ID和组ID
* 内存地址空间，栈不共享

### 线程非共享资源

* 线程id
* 处理器现场和栈指针
* 独立的栈空间
* errno变量
  * 线程用strerror函数
* 信号屏蔽字
* 调度优先级

#### 优缺点

* 优点
  * 提高并发性
  * 占用资源小
  * 通信便利
* 缺点
  * 调试费劲
  * 编写困难
  * 库函数不稳定
  * 对信号支持不好
* 缺点可以客服 优点很突出

### 线程的操作函数

* pthread_create
  * 返回值
    * 成功返回0
    * 失败返回errornum
  * 编译和连接的时候需要加上-pthread
* pthread_self
  * 获得自己的线程id
* pthread_exit
  * 线程退出函数
  * 在线程中可以使用该函数和return，但是不能使用exit，不然进程会直接退出。
  * 主控线程不能使用return，这样整个进程就会退出
  * 返回值
* pthread_join 
  * 线程回收函数 

### 线程回收

* 子线程死亡，父线程没有回收 造成僵尸线程
* 线程回收会阻塞等待

### 杀死线程

* pthread_cancel
  * 需要传入tid
  * 返回值
    * 失败返回errno
    * 成功返回0
  * 被pthread-cancel杀死的线程，退出状态为PTHREAD_CANCELED ((void *)-1)
  * 空循环的话，需要一个取消点才能杀死
  * 设置取消点
    * pthread_testcancel

### 线程分离

 * pthread_detach
   	* 线程不需要用户自行回收，系统会自动回收资源

### 线程相等

* 比较两个线程id是否相等
* pthread_equal 线程id在进程内部是唯一的



### 进程属性

* pthread_attr_init

* pthread_attr_destroy

* pthread_attr_setdetachstate

  

### 查看线程库版本

* getconf GNU_LIBPTHREAD_VERSION
* NPTL: native posix thread library

  

### 线程注意事项

* 主线程退出其他线程不退出，主线程应该调用pthread_exit
* 避免僵尸线程，注意回收
* 避免在多线程模型中fork，子进程只有保留调用fork的线程，其他线程在子进程中全部pthread_exit
* 避免在多线程中引入信号机制
* malloc和mmap可以被其他线程所释放，因为共享

### 创建多少个线程合适

* cpu核数*2 +2

### 线程同步

* 协调步调，顺序执行
* 解决同步的问题：加锁
* 数据混乱原因：
  * 资源共享
  * 调度随机
  * 缺乏同步机制

### mutex函数

* pthread_mutex_init
  * restrict 约束该块内存区域对应的数据，只能通过后面的变量进行访问和修改
  * mutex 互斥量
  * attr 互斥量属性，可以不考虑,传NULL
* pthread_mutex_lock
  * init出来的锁
  * 如果当前没锁，成功加锁
  * 如果当前有锁，阻塞等待
* pthread_mutex_destroy
  * 摧毁锁
* 常量初始化
  * pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER 
* pthread_mutex_unlock
  * 解锁

## Day 9

### 学习目标

* 掌握互斥量的使用
* 说出死锁以及解决方案
* 掌握读写锁的使用
* 掌握条件变量的使用
* 理解条件变量的生产者消费者模型
* 理解信号量实现的生产消费者模型 

### 互斥量

* 两个线程同时访问同一个共享资源，会造成数据混乱
* 步骤
  * 初始化锁
  * 加锁
  * 执行逻辑
  * 解锁
* 加锁应该是最小粒度的，一旦不使用共享区域需要立马解锁



### trylock

* 尝试加锁，如果已经加锁，就返回错误
* 

### 死锁

* 原因

  * 系统资源不足
  * 进程运行推进顺序不合适
  * 资源分配不当

* 四个必要条件

  * 互斥条件：一个资源只能一个进程使用
  * 请求与保持条件：一个进程因为请求资源而阻塞时，对已获得的资源保持不放
  * 不剥夺条件：进程已获得的资源，在未使用完之前，不能强制剥夺
  * 循环等待条件：若干进程之间形成一种头尾相接的循环等待资源关系

  发生死锁以上条件必然成立，而只要这上面4个条件任意一个不被满足，就不会发生死锁。

  ### 读写锁

* 多个读进程可以共享

* 写进程只能独占，同时读锁优先级高

* 读写锁仍然是一把锁，有不同的状态

  * 未加锁
  * 读锁
  * 写锁

* 读写锁使用场景

  * 适合读的线程多

* pthread_rwlock_destroy

* pthread_rwlock_rdlock

* pthread_rwlock_wrlock

* pthread_rwlock_init

* pthread_rwlock_unlock

### 条件变量和生产者消费者模型

* 条件变量避免没有必要的竞争

* 要和互斥量组合使用
  
* 本质上是先释放锁，然后阻塞到条件变量上
  
* 可以引起阻塞，并非是锁

* pthread_cond_init

* pthread_cond_wait

  * 条件变量的阻塞等待

* pthread_cond_timedwait

  * 超时等待

* pthread_cond_signal

  * 唤醒至少一个阻塞在条件变量cond上的线程

* pthread_cond_broadcast

  * 唤醒阻塞在条件变量cond上的全部线程 

* pthread_cond_init

  

  ### 信号量

* sem_init
  * pshared
    * 0为线程信号量
    * 非0为进程信号量
  * value定义的信号量的个数
* sem_destroy
  * 摧毁信号量
* sem_wait
  * 申请信号量，--
  * 当信号量为0时，阻塞
* sem_trywait
* sem_timedwait
* sem_getvalue
* sem_pos
  * 释放信号量，++
* sem_open
* sem_close
* sem_getvalue
* 信号量的初值，决定了有多少线程能同时使用资源

#### 信号量的生产者和消费者模型

### 文件锁

* 保证当前只运行一个进程
* 使用fcntl函数中的setlk  







