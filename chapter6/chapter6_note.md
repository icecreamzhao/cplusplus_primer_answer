# 第六章笔记

## 局部静态对象

初始化后知道程序终止才会被销毁, 即便是函数块结束执行也不会影响到该对象的生命周期。

## 参数传递

参数传递有两种形式, 分别是**值传递**和**引用传递**。

值传递的方式是, 实参的值被拷贝给形参, 对形参的操作不会影响到实参

引用传递的方式是, 形参的类型是引用类型, 传的值是引用的地址, 对形参的操作则是对实参的操作。

> 指针形参
> 如果形参类型是指针, 由于指针也是对象, 那么改变指针形参有两种方式:

```c++
void ract(int *p)
{
    // 改变的是拷贝之后的形参指针, 对实参无影响
    p = 0;
    // 改变的是指针所指的对象的值, 实参所指向的对象的值也被改变
    *p = 0;
}
```

## 数组形参

不允许拷贝数组以及使用数组时通常会转换成指针。

不能用值传递方式传递数组。

```c++
void print(const int*);
void print(const int[]);
void print(const int[10]);
```

这三种方式是等价的。

### 使用标记指定数组长度

```c++
void print(const char *cp)
{
    if (cp) // cp不是一个空指针
        while (*cp) // cp指向的字符不是一个空字符
            cout << *cp++; // 输出当前字符并将指针向前移动一个位置
}
```

这种对于C风格字符串来说比较适用, 因为C风格字符串最后位一定是空字符, 但是对于int类型, 就不适用了。

### 使用标准库规范

```c++
void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++;
}
```

### 显示传递一个表示数组大小的形参

```c++
void print(const int ca[], size_t size)
{
 for (size_t i = 0; i != size; ++i)
    cout << ca[i];
}
```

### 含有可变形参的函数

如果函数的实参数量未知但是类型相同, 则可以使用`initializer_list` 类型的形参。

initializer_list 类型定义在同名的头文件中, 提供的操作如下:

| 操作 | 说明 |
| --: | :--- |
| initializer_list<T> lst; | 默认初始化, T类型元素的空列表 |
| initializer_list<T> lst{a,b,c,...}; | lst的初始值数量和列表中的元素一样多; lst的元素是对应初始值的副本; 列表中的元素是 const |
| lst2(lst); lst2 = lst; | 拷贝或赋值一个initializer_list对象不会拷贝列表中的元素, 拷贝后, 原始列表和副本共享元素 |
| lst.size() | 列表中的元素数量 |
| lst.begin() | 返回指向lst首元素的指针 |
| lst.end() | 返回指向lst尾元素的指针 |

initializer_list列表中的元素永远都是常量值。

使用:

```c++
void err_msg(Errcode code, initializer_list<string> msg)
{
    cout << code.msg() << endl;
    for (const string &msgItem : msg)
        cout << msgItem;
    cout << endl;

    // or...

    for (auto beg = msg.begin(); beg != msg.end(); ++beg)
        cout << *beg;
    cout << endl;
}

// call it
err_msg(code, {"functionX", "okey"});
```

## 返回类型

C++11 标准规定, 函数可以返回花括号包围的值列表,

永远不要返回临时对象的引用。

## 函数重载

除了指针和引用, 其他类型的顶层const都不能作为重载的条件。

### const_cast 和重载

如果一个版本的shortString函数的形参和返回值都是const, 而另外一个不是, 则可以使用const_cast:

```c++
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() >= s2.size() ? s2 : s1;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const<string &>(r);
}
```

## 内联函数和constexpr函数

内联函数的作用:

在编译过程中内联的展开, 比如:

```c++
cout << shortString(s1, s2) << endl;

// 编译之后如下:
cout << (s1.size() >= s2.size() ? s2 : s1) << endl;
```

内联机制用于优化规模较小, 流程直接, 频繁调用的函数。

constexpr函数的定义:

constexpr函数是指能用于常量表达式的函数, 定义了constexpr函数的方法需要遵循几项约定:

* 函数的返回类型及形参类型都得是字面值类型
* 函数体有且只能有一条return语句

```c++
constexpr int new_sz() {return 42;}
constexpr int foo = new_sz();
```

内联函数和constexpr函数的定义通常会放到头文件中。

## 调试帮助

assert(expr) 是一种预处理宏, 首先对expr求值, 如果表达式为假, assert输出信息并终止程序的执行, 如果表达式为真, assert什么也不做。

由于是预处理宏, 所以由预处理器而非编译器管理, 因此我们可以直接使用预处理的名字而不用using声明。

### NODEBUG预处理变量

如果定义了`NODEBUG`变量, 则assert什么也不做

```c++
#define NODEBUG
``` 

assert应该仅用于验证那些确实不可能发生的事, 但不能替代真正的运行时逻辑检查, 也不能替代程序本身应该包含的错误检查。

如果没有定义NODEBUG, 将执行`#ifndef`和`#endif`之间的代码, 如果定义了, 这些代码将会被忽略掉。

## 实参类型转换

为了确定最佳匹配, 编译器将实参类型到形参类型的转换分为了以下几个等级:

1. 精确匹配, 包含以下几种情况:
    * 实参类型与形参类型相同
    * 实参从数组类型或函数类型转换成指针类型
    * 向实参添加顶层const或删除顶层const
2. 通过const转换实现匹配
3. 通过类型提升实现匹配
4. 通过算术类型转换或指针转换实现匹配
5. 通过类类型转换实现匹配

### 需要类型提升或算数类型的转换的匹配

```c++
void ff(int);
void ff(short);

ff('x'); // 调用的是ff(int)

void manip(long);
void mainip(float);
mainip(3.14); //error, 存在二义性
```

## 函数指针

函数指针指向的是一个函数, 声明方式如下:

```c++
// pf 首先是一个指针, 其次是一个函数
bool (*pf)(const string &, const string &);
// pf 是一个函数, 返回的是一个指向bool类型的指针
bool *pf(const string &, const string &);
```

* 使用函数指针

```c++
pf = lengthCompare;
pf = &lengthCompare; // 等价的赋值语句, 取地址符是可选的
bool f1 = pf("hello", "goodbye"); // 调用lengthCompare
bool f1 = (*pf)("hello", "goodbye"); // 一个等价的调用
```

* 重载函数的指针

```c++
void ff(int*);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff; // pf1指向ff(unsigned int)
```

* 函数指针形参

```c++
// 第三个形参是函数类型, 会自动转换成指向函数的指针
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));

// 显式的将形参定义成指向函数的指针
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

// 调用, 自动将lengthCompare转换成指针
useBigger(s1, s2, lengthCompare);
```

* 返回指向函数的指针

```c++
using F = int(int *, int) // 函数类型
using PF = int(*)(int *, int) // PF是指针类型

PF f1(); // f1返回一个指向函数的指针
F *f2(); // f2返回一个指向函数的指针
F f3(); // error, f3不能返回函数, 需要显式的定义为指针类型

// 显式的定义一个返回指向函数的指针
// 首先f1是一个函数, 其次f1返回的类型是一个指针, 接着该指针本身也包含形参列表(int *, int), 所以该指针指向函数, 最后这个指向的函数的返回值是int
int (*f1(int))(int *, int);
```
