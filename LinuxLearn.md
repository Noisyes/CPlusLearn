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

### chown 改变用户

* chown 用户:组 文件名|目录
* chown 用户 文件名|目录

### chgrp改变组



​    

  

  