# 第四章笔记

## 箭头运算符

ptr->item() 等价于 (*ptr).item()

## 命名的强制类型转换

一个命名的强制类型转换有如下形式:

`cast-name<type>(expression)`

type 是目标类型, 而expression是要转换的值。

cast-name可以是

* static_cast
* dynamic cast
* const_cast
* reinterpret_cast

### static_cast

任何具有明确定义的类型转换, 只要不包含底层const, 都可以用`static_cast_`

```c++
double slope = static_cast<double>i / j;
```

当较大的算术类型转型为较小的算术类型时, 使用static_cast转型可以关闭精度损失的警告。

对于编译器无法自动转换的类型转换也有用, 比如找回存放在void指针中的变量类型:

```c++
void *p = &i;
int j = static_cast<int*>(p);
```

但是强制转换的类型如果不符, 则会产生未定义的效果。

### const_cast

const_cast只能改变对象底层const。

```c++
const int *ip;
int *p = const_cast<int*>(ip);
```

不能用 `const_cast` 改变表达式的类型, 只能改变表达式的常量属性:

```c++
const char* cpc;
char *cp = const_cast<char*>(cp);

// error
int *ip = const_cast<int*>(cp);
```

const_cast常用于函数重载的上下文中。

### reinterpret_cast

reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释。

```c++
int *ip;
chat *cp = reinterpret_cast<char*>(ip);
```

这里的cp指向的实际上是一个int类型, 如果把cp当成普通的字符指针使用就可能会发生运行时发生错误:

```c++
string str(pc);
```

> reinterpret_cast本质上依赖机器, 想要安全的使用必须对涉及的类型和编译器实现转换的过程都非常了解

