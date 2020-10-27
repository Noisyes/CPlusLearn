# STL学习

## Day 1

### STL基本概念

* 容器
* 算法
* 迭代器
* 仿函数
* 适配器
* 空间配置器

容器通过空间配置器获取数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同的策略变换，适配器可以修饰仿函数。

## STL优点

* 高重复性

* 高性能

* 高移植性

### 三大组件

#### 容器

* 序列式容器
* 关联式容器

#### 算法

* 质变算法。改变了容器内原本的数据
* 非质变算法。没有改变容器内原本的数据

#### 迭代器

* 依序访问容器内各个元素

  * 输入迭代器
  * 输出迭代器
  * 前向迭代器
  * 双向迭代器
  * 随机访问迭代器

#### 常用容器

##### String

```c++
//构造函数
string();
string(const string& str);
string(const char* s);
string& string(const string& str);
string(int n,char c);
string& assign(const char *s);
string& assign(const string &s);
string& assign(const char *s,int n);
string& assign(const char *s,int start,int n);

```