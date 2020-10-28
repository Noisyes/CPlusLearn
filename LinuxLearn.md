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
  * export LD_LIBRARY_PATH = *******:$LDLD_LIBRARY_PATH
* sudo vim /etc/ld.so.conf 将库路径增加到这个文件 
  * sudo ldconfig  -v