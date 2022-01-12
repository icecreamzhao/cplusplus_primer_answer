# 第三章笔记

## using 声明

头文件不应该包含using声明。

## string

初始化方式:

```c++
string s(10, 'c'); // value is "cccccccccc"
string s(s1); // s = s1
string s("value") // value is "value"
```

### 使用getline()读取一整行

```c++
string line;
while (getline(cin, line))
{
	cout << line << endl;
}
```

这样即便输入的语句中包含空格, 也可以获取到了。

## const 和 auto

```c++
const string s = "abc";
auto &c = s[0];
// what is type of c?
```
c 的类型是 const char&

## vector

vector是类模板, 不是类或函数

c++11新标准和老版本的区别:

```c++
//old version:
vector<vector<int> >
//c++ new version: (without space)
vector<vector<int>>
```

新的列表初始化的方式:

`vector<int> v = {1, 2, 3, 4};`

创建指定数量的元素:

`vector<int> v(10, 1);`
`vector<int> v(10);` 十个元素, 都是0

### != 和 < 或 >
使用`!=`符号的原因是因为在c++中, 只有string, vector等一些标准库类型有下标运算符, 而并非全都如此。与之类似, 所有的标准库容器的迭代器都定义了!=和==, 而大多数没有定义<和>。

### 迭代器类型

```c++
vector<string>::iterator it1; // 可以读写vector<string>中的元素
string::iterator it2; // 可以读写string中的字符

vector<string>::const_iteraotr it3; // 只能读元素
string::iterator it4; // 同上
```

c++11 引入了常量begin和end:

```c++
vector<string> v1;
auto it = v1.cbegin(); // 常量迭代器类型
auto it2 = v1.cend(); // 同上
```

> vector可以动态增长, 但是不能在for范围语句或者迭代器中向vector中添加元素。

### 迭代器

迭代器可以进行运算, 通过运算符来移动迭代器所在的位置。

## 数组

字符数组可以直接使用字符串来初始化:

`char[] a1 = "abc";`

不支持拷贝和复制。

## 定义复杂的数组声明

定义一个含有指针的数组:

```c++
int *ptrs[10]; // ptrs是一个含有是个整形指针的数组
// int &refs[10]; //error, 不能定义引用的数组
int (*parray)[10] = &arr; // parray是一个指针, 指向含有十个整数的数组
int (&rarray)[10] = arr; // rarray是一个引用, 引用一个含有是个整数的数组
```

> 理解指针, 可以从右往左阅读, 理解类型
> 理解数组, 可以从内往外阅读, 理解类型
> int *(&array)[10] =ptrs; 从内往外阅读, 首先array是一个引用, 引用的是一个含有10个指针的数组

### 指针和数组

```c++
string nums[] = {"one", "two", "three"};
int* s1 = nums; // 等价于 int* p = &nums[0];
```
> 在大多数表达式中, 使用数组类型的对象其实是使用一个指向该数组首元素的指针。

```c++
int ia[] = {0,1,2,3,4,5,6,7,8,9};
auto ia2(ia);
```
ia2的初始化等价于 `auto ia2(&ia[0]);`

使用 `decltype` 关键字时, 返回的类型是数组(而不是指针)。

* 迭代器

指针也是迭代器, vector和string的迭代器支持的运算, 数组的指针全都支持

* 标准库函数begin和and

> 这里的begin()和end()需要
> ```c++
> #include <iterator>
> using std::begin;
> using std::end;
> ```

可以使用begin()和end()来获取到指向数组的首元素和尾元素的指针。

```c++
int ia[] = {1,2,3,4,5,6,7,8,9};
int* be = begin(ia);
int* en = end(ia);
```

两个指针相减的结果类型是`ptrdiff_t`标准库类型, (数组索引类型是`size_t`标准库类型)

内置的(数组)下标运算符所用的索引值不是无符号类型, 这一点与vector和string不一样(索引值是无符号类型)。

## C 风格字符串

C风格字符串的函数

| 函数名 | 说明 |
| :----: | :--: |
| strlen(p) | 返回p的长度, 空字符不计算在内 |
| strcmp(p1, p2) | 比较p1, p2的相等性, p1==p2, 返回0; p1>p2, 返回一个正值; p1<p2, 返回一个负值 |
| strcat(p1, p2) | 将p2附加到p1后, 返回p1 |
| strcpy(p1, p2) | 将p2拷贝给p1, 返回p1 |

> 函数定义在<cstring>头文件中

```c++
char ca[] = {'c', '+', '+', '\0'};
cout << strlen(p) << endl; //输出3
```

### 比较字符串

比较标准库字符串对象时, 可以直接使用关系运算符(< >)和相等性运算符(==, !=)

比较C风格字符串时, 如果使用关系运算符来比较, 比较的其实是指向数组首元素的指针地址, 毫无意义

```c++
const char ca1[] = "A string example";
const char ca2[] = "another string example";
// 未定义的, 试图比较两个无关地址
if (ca1 > ca2)
{
	// do something
}

// 使用函数来判断:
if (strcmp(ca1, ca2) > 0)
{
	// 当ca1大于ca2时做的事情...
}
```

## 与旧代码的接口

混用string和C风格字符串

```c++
// 允许使用以空字符结尾的字符数组初始化字符串
char ca1[] = {'c', '+', '+', '\0'};
string s = ca1;
// 在string的加法运算中允许将字符数组作为其中的运算对象(但不能都是)
string s2 = s + " and " + ca1;
// 复合赋值运算中, 允许使用字符数组作为右侧的运算对象
s2 += ca1;

// 使用c_str函数初始化字符数组
const char* cp = s2.c_str();
```

如果想让c_str函数返回的数组一直有效, 如果后续改变了s2
的值, 就可能会让之前的数组失去效用, 所以可以先进行拷贝操作, 然后使用拷贝后的数组。

### 使用数组初始化vector对象

```c++
int int_arr[] = {1,2,3,4,5};
vector<int> invc(begin(int_arr), end(int_arr));
```
只需要指明要用来初始化的开始位置和结束位置就可以了。

## 多维数组

```c++
// 如果这样写, 编译不通过, i会自动转换为指针, 需要加上引用符将i转换为引用
for (auto i : arr)
{
	for (auto j : i)
	{
		cout << j << endl;
	}
}
```

### 多维数组和指针

```c++
// p 是一个指向含有四个整数的数组
int (*p)[4];

// p 是一个含有四个整型指针的的数组
int *p[4];
```