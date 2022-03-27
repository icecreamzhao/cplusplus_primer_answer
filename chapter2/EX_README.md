# 练习2.1

> 类型int, long, long long 和 short的区别是什么? 无符号类型和带符号类型的区别是什么? float 和 double 的区别是什么?

int 和 short 最小长度为16位, long 最小长度为32位, long long 最小长度为64位, 

无符号类型只包含正数, 有符号类型正负数都包括。

float可以表示6位有效数字, double可以表示10位有效数字。

# 练习2.2

> 计算按揭贷款时, 对于利率, 本金和付款分别应选择何种数据类型?

应选择无符号double。

# 练习2.3

> 读程序写结果

```c++
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;

// output:
/**
 * 32
 * int is 32 bit, result is 4,294,967,264
 * 32
 * -32
 * 0
 * 0
 */
```

# 练习2.4

> 编写程序并检查你的估计是否正确, 如果不正确, 请仔细研读本节直到弄明白问题所在

# 练习2.5

> 指出下述字面值的数据类型并说明每一组内几种字面值的区别:

```
(a) 'a', L'a', "a", L"a"
    char, wchar_t, string, wchar_t const * __ptr64
(b) 10, 10u, 10L, 10uL, 012, 0xC
    int, unsigned int, long, unsigned long, int, int
(c) 3.14, 3.14f, 3.14L
    double, float, long double
(d) 10, 10u, 10., 10e-2
    int, unsigned int, double, double
```

# 练习2.6

> 下面两组定义是否有区别? 如果有, 请叙述之

```c++
int month = 9, day = 7;
int month = 09, day = 07;

```

第二句使用的是八进制的声明方式, 不能通过编译。

# 练习2.7

> 下述字面值表示何种含义? 它们各自的数据类型是什么?

```c++
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L (c) 1024f (d) 3.14L
```

(a) 字符串字面值, std::string
(b) 双精度类型 long double
(c) 单精度类型 float
(d) 双精度类型 long double

# 练习2.8

> 请利用转义序列编写一段程序, 要求先输出2M, 然后转到新的一行。修改程序使其先输出2, 然后输出制表符, 在输出M, 最后转到新的一行。

# 练习2.9

> 解析下列定义的含义。对于非法的定义, 请说明错在何处并将其改正。

```c++
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```

(a) 应先定义input_value, 在对其进行cin操作
(b) 使用列表初始化编译器会进行类型转换检查, 此处会有丢失信息的风险, 所以编译通不过
(c) wage没有声明
(d) 有丢失信息的风险, 但不会报错

# 练习2.10

下列变量的初值分别是什么?

```c++
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}

// output
global_str 的初始值是 ""
global_int 的初始值是 0
local_int 的初始值是 0
local_str 的初始值是 ""
```

# 练习2.11

> 指出下面的语句是声明还是定义

```c++
(a) extern int ix = 1024; // 声明并定义
(b) int iy; // 声明并定义
(c) extern int iz; // 声明
```

# 练习2.12

> 请指出下面的名字中哪些是非法的:

```c++
(a) int double = 3.14; // 非法, double是关键字
(b) int _; // 合法
(c) int catch-22; // 非法, 变量名中不能有中划线
(d) int 1_or_2 = 1; // 非法, 变量名不能用数字开头
(e) double Double = 3.14; // 非法 Double是关键字
```

# 练习2.13

> 下面程序中的j的值是多少?

```c++
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}

// output: j is 100
```

# 练习2.14

> 下面的程序合法吗? 如果合法, 它将输出什么?

```c++
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;

// output: 100 45
```

# 练习2.15

> 下面的哪个定义是不合法的? 为什么?

```c++
int ival = 1.01; // 合法
int &rval1 = 1.01; // 不合法, 引用不能直接引用常量
int &rval2 = ival; // 合法
int &rval3; // 不合法, 引用必须直接初始化
```

# 练习2.16

> 考察下面的所有赋值然后回答, 哪些赋值是不合法的? 为什么? 哪些赋值是合法的? 他们执行了什么样的操作?

```c++
int i = 0, &rl = i; // 合法
double d = 0, &r2 = d; // 合法
r2 = 3.14159; // 合法
r2 = r1; // 合法, 自动转型
i = r2; // 合法, 会丢失信息
r1 = d; // 合法, 会丢失信息
```

# 练习2.17

> 执行下面的代码将输出什么结果?

```c++
int i, &ri = i;
i = 5, ri = 10;
std::cout << i << " " << ri << std::endl;
```

10 10

# 练习2.18

> 编写代码分别更改指针的值以及指针所指对象的值

# 练习2.19

> 说明指针和引用的主要区别

指针是一个对象, 指针是别名

# 练习2.20

> 请叙述下列代码的作用

```c++
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

声明一个int指针, 指向int, 最后给p1赋值为指向的int的平方

# 练习2.21

> 请解释下述定义, 在这些定义中有非法的么? 如果有, 为什么?

```c++
int i = 0;
(a) double *dp = &i; (b) int *ip = i; (c) int *p = &i;
```

a 不合法, 指针只能指向同类型的对象
b 不合法, 指针需要取地址符
c 合法

# 练习2.22

> 假设p是一个int型指针, 请说明下述代码的含义

```c++
if (p) // ...
if (*p) // ...
```

第一个判断是判断指针是否是空指针
第二个判断是判断指针指向的对象值是否为0

# 练习2.23

> 给定指针p, 你能知道它是否指向了一个合法的对象么? 如果能叙述思路, 如果不能也请说明原因

不能, 因为需要更多的信息来确定该指针是否合法

# 练习2.24

> 在下面这段代码中为什么p合法而lp非法?

```c++
int i = 42;
void *p = &i;
long *lp = &i;
```

因为p是void指针, 可以指向任何类型的对象, 而lp和i的类型不符合

# 练习2.25

> 说明下列变量的类型和值

```c++
(a) int *ip, i, &r = i;
(b) int i, *ip = 0;
(c) int *ip, ip2;
```

a ip是指向int类型的指针, i为int整型, r为int引用
b i int整型, ip为空指针
c ip为int类型指针, ip2为int整型

# 练习2.26

> 下面哪些句子是合法的? 如果有不合法的句子, 请说明为什么?

```c++
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;

a 不合法, const修饰需要初始化
b 合法
c 合法
d 不合法, 不能修改常量值
```

# 练习2.27

> 下面的哪些初始化是合法的? 请说明原因

```c++
a) int i = -1, &r = 0; // 不合法, 引用需要绑定到对象上
b) int *const p2 = &i2; //合法, p2是指向int的常量指针
c) const int i = -1, &r = 0; // 合法
d) const int *const p3 = &i2; // 合法
e) const int *p1 = &i2; // 合法
f) const int &const r2; //不合法, r2是一个绑定到常量上的引用常量
g) const int i2 = i, &r = i; // 合法, r也是const引用
```

# 练习2.28

> 说明下面的这些定义是什么意思, 挑出其中不合法的。

```c++
a) int i, *const cp; // 不合法, i 是 int变量, cp是指向int常量指针
b) int *p1, *const p2; // 不合法, p1是int指针, p2是指向int的常量指针
c) const int ic, &r = ic; // 不合法, ic需要初始化; i 是常量, r是常量引用
d) const int *const p3; // 不合法, p3是指向常量的常量指针, 不能通过指针改变指向对象的值
e) const int *p; // p是指向常量的int指针
```

# 练习2.29

> 假设已有上一个练习中定义的那些变量, 则下面的呢哪些语句是合法的? 请说明原因。

```c++
a) i = ic; // 合法
b) p1 = p3; // 不合法, p1不是指向常量的指针 error: const int * can not convert to int *
c) p1 = &ic; // 不合法, p1不是指向常量的指针 error: const int can not convert to int
d) p3 = &ic; // 不合法, 无法改变常量的值
e) p2 = p1; // 不合法, 无法改变常量值
f) ic = *p3; // 不合法, 无法改变常量值
```

# 练习2.30

> 对于下面的这些语句, 请说明对象被声明成了顶层const还是底层const?

```c++
const int v2 = 0; // 顶层const
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2; // p2是底层const, p3顶层底层都有, r2是底层const
```

# 练习2.31

> 假设已有上一个练习中所做的哪些声明, 则下面的哪些语句是合法的? 请说明顶层const 和 底层const 在每个例子中有何体现?

```c++
r1 = v2; // 合法
p1 = p2; // 不合法, p1不是指向常量的指针(p2是底层const)
p2 = p1; // 合法
p1 = p3; // 不合法, 同第二句
p2 = p3; // 合法
```

如果是底层const, 属于类型不同, 不能互相赋值; 如果顶层const, 则其他非顶层const的相同类型的对象可以使用该常量赋值

# 练习2.32

> 下面的代码是否合法? 如果非法, 请设法将其修改正确。

```c++
int null = 0, *p = null;

// repair
int i = 0, *p = nullptr;
```

# 练习2.33

> 利用本节定义的变量, 判断下列语句的运行结果

```c++
// a is int
// b is int
// c is int
// d is int *
// e is const int *
// g is const int &
a = 42; b = 42; c = 42;
// 下面的代码都不能编译成功, 其中d和e都是指针, 需要解引用; g是常量引用, 不能赋值
d = 42; e = 42; g = 42;
```

# 练习2.34

> 基于上一个练习中的变量和语句编写一段程序, 输出赋值前后变量的内容。

见 2.33

# 练习2.35

> 判断下列定义推断出来的类型是什么, 然后编写程序验证。

```c++
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k = i;

// j is int
// k is const int &
// p is const int *
// j2 is const int
// k is const int &
```

# 练习 2.36

> 关于下面的代码, 请指出每一个变量的类型以及程序结束后他们各自的值

```c++
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;

// output:
// c is int and value is 3
// d is int & and value is 3
// c is 4, d is 4, a is 4
```

# 练习2.37

> 赋值是会产生引用的一类典型表达式, 引用的类型就是左值的类型。也就是说, 如果i是int, 则表达式`i = x`的类型是int&, 根据这一特点, 请指出下面的代码中每一个变量的类型和值。

```c++
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

c 是int类型, d是int&类型; c和d的值为3

# 练习2.38

> 说明由decltype指定类型由auto指定类型有何区别。请举出一个例子, decltype指定的类型与auto指定的类型一样; 再举一个例子, decltype指定的类型与auto指定的类型不一样。

decltype可以指定表达式或者函数类型来指定, 而auto是根据右值指定。
decltype和auto处理顶级const和引用的方式不同。

```c++
// decltype 与 auto 指定的类型一样
int i = 0;
auto j = i;
decltype(i) k = 0;

// decltype 与 auto 指定的类型不一样
const int i = 0;
// j 是 int, k是const int
auto j = i;
decltype(i) k = 0;
```

# 练习2.39

> 编译下面的程序观察其运行结果, 注意, 如果忘记写类定义体后面的分号会发生什么情况? 记录下相关信息, 以后可能会有用。

```c++
struct Foo {} // 没有分号
int main()
{
    return 0;
}
```

# 练习 2.40

> 根据自己的理解写出Sales_data类, 最好与书中的例子有所区别。

# 练习 2.41

> 使用你自己的Sales_data类重写1.5.1, 1.5.2的练习, 眼下先将Sales_data类的定义和main函数放到同一个文件里。

# 练习 2.42

> 根据你自己的理解重写一个Sales_data.h头文件, 并以此为基础重做2.6.2节的练习。
