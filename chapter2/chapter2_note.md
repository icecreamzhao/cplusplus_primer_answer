# 第二章笔记

c++算术类型

| 类型 | 含义 | 具体尺寸 |
| :--: | :--: | :---: |
| bool | 布尔类型 | 未定义 |
| char | 字符 | 8位 |
| wchar_t | 宽字符 | 16位 |
| char16_t | Unicode 字符 | 16位 |
| char32_t | Unicode 字符 | 32位 |
| short | 短整型 | 16位 |
| int | 整形 | 16位 |
| long | 长整型 | 32位 |
| long long | 长整型 | 64位 |
| float | 单精度浮点数 | 6位有效数字 |
| double | 双精度浮点数 | 10位有效数字 |
| long double | 扩展精度浮点数 | 10位有效数字 |

> long long 是c++ 11标准带来的

## 计算机中的单位

1 bit = 2
2 bit = 2^2
8 bit = 2^8

1 byte = 8 bit = 2^8
2 byte = 16 bit = 2^16

## 字面值常量

以0开头为8进制
0x开头为16进制

严格来说, 十进制字面值不会是负数, 如果使用了形如-42的负十进制的字面值, 符号并不在字面值之内, 只是对字面值取负值

字符串字面值是由常量字符组成的数组构成的, 编译器在每个字符串的结尾处添加一个空字符'\0'

> 指定字面值类型

字符和字符串字面值

| 前缀 | 含义 | 类型 |
| :--: | :--: | :--: |
| u | Unicode 16字符 | char16_t |
| U | Unicode 32字符 | char32_t |
| L | 宽字符 | wchar_t |
| u8 | UTF-8 | char |

整形字面值

| 后缀 | 最小匹配类型 |
| :--: | :--: |
| u or U | unsigned |
| l or L | long |
| ll or LL | long long |

浮点型字面值
| 后缀 | 最小匹配类型 |
| :--: | :--: |
| f or F | float |
| l or L | long double |

## 转义序列

换行符 \n		横向制表符 \t		报警符 \a
纵向制表符 \v		退格符 \b		双引号 \"
反斜线 \\		问号 \?			单引号 \'
回车符 \r		进纸符 \f

## 对象

> 对象的定义: 对象是具有某种数据类型的内存空间

## 初始化

初始化和赋值的区别在于, 初始化的含义是在创建变量时赋予一个初始值, 赋值则是把对象当前的值擦除, 以一个新的值来替代

> 列表初始化
```c++
int units_sold = 0;
int units_sold = {0};
int units_sold{0};
int units_sold(0);
```
当使用列表初始化形式(花括号)初始化内置类型时, 如果有潜在的丢失信息的风险, 则编译器会报错。

## 作用域

当在第一次使用变量时在定义它, 这样会给他赋一个比较合理的初始值

## 引用

形如:

```c++
int ival = 10;
int &refVal = ival;
// int &refVal; error, 引用必须被初始化
```
引用的特点:

* 引用即别名, 对引用的操作都会作用于与之绑定的对象上。
* 引用只能绑定在对象上, 而不能和字面值绑定在一起。
* 大部分情况下, 引用类型必须和要与之绑定的对象类型严格匹配。(除非该引用是const, const引用可以使用字面值常量或者其他表达式进行初始化, 只要表达式结果可以转化成引用类型即可)

## 指针

与引用类似, 指针也实现了对其他对象的间接访问。

指针和引用的不同:

* 指针本身是对象, 允许对指针赋值和拷贝, 而且在指针的生命周期内可以先后指向不同的对象。
引用不是对象, 引用只能指向一个对象。
* 指针无需在定义时赋初值, 在作用域内如果没有被初始化, 则也会有一个不确定的值

任何非0指针对应的条件都是true。(条件指if中的条件)

`int *p1, p2`
p1是int类型的指针, p2是int变量

### 获取对象的地址

```c++
int ival = 12;
int *p = &ival; // p存放变量ival的地址
```

和引用一样, 指针在大部分情况也需要和所指向的对象类型保持一致。(例外是常量指针可以指向非常量对象)

指针值:

1. 指向一个对象
2. 指向紧邻的对象所占的下一个位置
3. 空指针, 意味着指针没有指向任何对象
4. 无效指针, 上述情况之外的其他值

2, 3, 4种情况, 由于没有指向具体的对象, 当使用时后果无法预计。

### 利用指针访问对象

```c++
int val = 42;
int *p = val;
*p = 5;
cout << *p;
```
使用*(解引用符)来访问指针指向的对象。

解引用符只适用于已经指向了对象的指针。

#### 空指针

生成空指针的方法:

* int *p = nullptr;
* int *p = 0;
* int *p = null;

三种方式等价。

不能直接把int变量赋值给指针, 形如:

```c++
int zero = 0;
int *pi = null;
pi = zero;
```

#### void* 指针

```c++
double obj = 3.14, *pi = &obj;
void *pv = &obj;
pv = pi;
```
void指针可以存放任意类型的对象地址, 不能直接操作指向的对象, 因为不知道它属于什么类型。

### 指向指针的指针

```c++
int i = 42, *pi = &i;
int **ppi = &pi;
```

ppi是pi的指针。访问方式是:

```c++
cout << **ppi;
```

### 指向指针的引用

```c++
int i = 42, *pi = &i;
int *&rpi = pi;
```

从右往左读rpi的类型, 首先它是一个引用, 然后引用的类型是一个指针, 所以它是一个指针的引用。

## const 限定符

const 被设定为仅在文件内有效, 如果想在文件共享该常量, 则需要在定义和声明时使用 extern 关键字:

```c++
// file_1.h:
extern const int buf_size = fcn();

// file_1.cc:
extern const int buf_size; //和file_1.h中的buf_size是同一个
```

#### const 引用

对常量的引用需要使用const来修饰。

```c++
const int c = 42;
const int &cr = c; // right
cr = 42; // error
int &r = c; // error
```

const引用可以使用表达式和字面值常量进行初始化。

#### const 指针

同const引用, const指针可以指向非常量对象, 不能通过常量指针改变对象, 但是如果该对象是非常量, 则可以直接改变。

形如:

```c++
int errNumb = 0;
int *const curErr = &errNumb; // curErr将一直指向errNumb
const double pi = 3.14;
const double *const pip = &pi; 
```

分析pip:
按照从右往左读的顺序, 首先pip是一个常量(意味着他不能指向其他的对象了), 接着他是一个指针, 说明他是一个常量指针, 最后看到他指向的也是一个常量(const double), 说明也不能通过该指针改变对象的值了。

#### constexpr 变量

c++ 11 中使用 `constexpr` 来声明一个变量的值来验证是否是常量表达式, 声明为 `constexpr` 的变量一定是一个常量, 形如:

```c++
constexpr int mf = 20; //right, 20 是常量表达式
constexpr int limit = mf + 1; //right, mf + 1 是常量表达式
constexpr int sz = size(); // 当size()是constexpr函数时, 该表达式才正确
```

constexpr也可以修饰指针/引用, 但是初始值只能是nullptr或0。

constexpr修饰的指针属于顶层const

## 类型别名

传统方式:
`typedef double wages;`

新标准使用:
`using SI = Sales_item;`

### 指针, 常量和类型别名

```c++
using char *pstring;
const pstring cstr = 0;
```

cstr是一个指向char的常量指针(顶层const)

## auto 类型说明符

auto 会直接以引用的类型作为auto的类型:

```c++
int i = 0, &ir = i;
auto r = ir; // r's type is int
```
## decltype 类型指示符

```c++
decltype(f()) sum = x;
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x's type is const int
decltype(cj) y = x; // y's type is const int&
decltype(cj) z; // z's type is const int&
```

sum的类型是当调用f()函数时返回的数据类型。

```c++
int b = 0;
decltype((b)) a = 1; // b 是int引用类型
```

decltype中加上双层括号的结果类型永远是引用。

## 自定义数据结构

数据结构是把一组相关的数据组织起来, 然后使用它们的策略和方法。