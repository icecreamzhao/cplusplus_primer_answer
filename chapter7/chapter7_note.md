# 第七章笔记

## 定义类型

想要开发一款成功的程序, 作者必须充分了解并实现用户的需求。同样的, 优秀的类的设计者也应该密切关注那些有可能使用该类的程序员的需求。作为一个设计良好的类, 既要有直观且易于使用的接口, 也必须具备高效的实现过程。

```c++
struct Sales_data
{
    std::string isbn () const { return bookNo; }
};
```

这里将const放在函数名之后, 意味着将隐式的this指针声明为常量指针。 isbn被称为常量成员函数。

可以把isbn函数想象成以下形式:

```c++
std::string Sales_data::isbn(const Sales_data *const this)
{
    return this->bookNo;
}
```

> 常量对象, 常量引用和指针都只能调用常量成员函数。

### 定义一个返回this的函数

```c++
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## 构造函数

```c++
struts Sales_data
{
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(istream &is)
    {
        read(is, *this);
    }
}
```

c++11 新标准规定, 可以使用default来让编译器生成默认的构造函数。
其他两个构造器包含构造函数初始值列表, 该列表负责初始化类内的成员。

## 访问控制与封装

使用`class`和`struct`两个关键字的唯一区别在于, class在第一个访问符之前的成员默认为private, struct默认是public

## 友元

当一个非成员函数想使用某个类的private成员时, 可以在类中将该函数定义为friend:

```c++
struct Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data &);
}

// add 可以访问Sales_data的private成员
Sales_data add(const Sales_data&, const Sales_data &);
```

## 可变数据成员

当一个成员被声明为`mutable`时, 即使是const对象, 该成员也是可以被改变的。

```c++
class Screen
{
public:
    void some_member() const;
private:
    mutable size_t access_str;
};

void Screen::some_member() const
{
    ++access_str;
}
```

## 类数据成员的初始值

```c++
class Window_mgr
{
prviate:
    vector<Screen> screen_vec{Screen(24, 80, ' ')};
};
```

> 当提供一个类内初始值时, 要使用等号(=)或者花括号({})的形式


在实践中, 设计良好的C++代码常常包含大量的小的函数, 通过调用这些函数, 可以完成一组其他函数的"实际"的工作。

## 类声明

可以先进行类声明, 然后在定义, 这种声明被称为前向声明, 在声明之后定义之前是一个不完全类型:

```c++
// Y 是一个不完全类型
class Y;

class X
{
    // 可以先进行声明(指针, 对象或引用), 随后进行定义
    Y *y;
};

class Y
{
    X x;
}
```

## 构造函数再探

使用构造函数来对成员进行初始化。

最好令构造函数初始值的顺序与成员声明的顺序保持一致, 比如:

```c++
clsss X
{
public:
    X(int val) : j(i), i(val) {}
private:
    int i, j;
};
```

可以使用默认值对初始值列表进行初始化:

```c++
class Sales_data
{
public:
    Sales_data(string s = "") : bookNo(s) {}
private:
    string bookNo;
};
```

## 委托构造函数

委托构造函数是C++11新标准扩展的, 类似于java中的多个构造函数, 不同参数之间调用的形式:

```c++
class Sales_data
{
public:
    Sales_data(string s, unsigned n, double d) : bookNo(s), units_sold(n), price(d) {}
    // 委托构造函数
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(string s) : Sales_data(s, 0, 0) {}
    Sales_data(istream &is) : Sales_data() { read(is, *this); }
};
```

## 隐式的类类型转换

当一个构造函数可以通过某个基本类型构建时, 可以直接使用该基本类型来充当临时对象:

```c++
struct Sales_data
{
public:
    Sales_data(string s) : bookNo(s) {}

    void combine(const Sales_data &);
// ....
};

string null_book = "9999-999-999";
Sales_data book1 = Sales_data();
book1.combine(null_book); //正确, 进行了隐式类型的转换
book1.combine("9999-999-999"); // 错误, 隐式转换只支持一步类型转换, 这里先将 const char *转换成string, 然后接着转换成 Sales_data
```

### 抑制构造函数定义的隐式转换

使用explicit关键字抑制隐式转换:

```c++
class Sales_data
{
    Sales_data() = default;
    explicit Sales_data(const string &s) : bookNo(s) {}
};

Sales_data data = Sales_data();
data.combine(string("9999-999-999")); // 错误, 无法将 const string & 转换为 Sales_data 类型
```

当使用explicit声明构造函数时, 只能以直接初始化的方式使用, 不能使用拷贝初始化的方式:

```c++
Sales_data data = Sales_data(null_book); // 直接初始化
Sales_data data = null_book; // 错误, 无法使用explicit构造函数进行拷贝初始化
```

可以显示转换:

```c++
data.combine(static_cast<Sales_data)(string("9999-999-999")));
```

## 聚合类

当一个类满足如下条件时, 我们说它是聚合的:

* 所有成员的 public 的
* 没有定义任何构造函数
* 没有类内初始值
* 没有基类, 也没有virtual函数

例如:

```c++
struct Data
{
    int ival;
    string s;
};
```

可以使用这种初始化方式:

```c++
// 初始化的顺序必须和声明顺序一致
Data val1 = {0, "Anna"};
```

## 字面值常量类

数据成员都是字面值类型的聚合类是字面值常量类, 如果一个类不是聚合类, 但符合下述要求, 则也是一个字面值常量类:

* 数据成员都必须是字面值类型
* 类必须至少含有一个 constexpr 构造函数
* 如果一个数据成员含有类内初始值, 则内置类型成员的初始值必须是一条常量表达式; 或者如果成员属于某种类类型, 则初始值必须使用成员自己的 constexpr 构造函数。
* 类必须使用析构函数的默认定义, 该成员负责销毁类的对象。

```c++
class Debug
{
public:
    constexpr Debug(bool b = true) : io(b), hw(b), other(b) {}

private:
    bool io;
    bool hw;
    bool other;
};

constexpr Debug prod(false);
```

Debug 属于字面值常量类。

constexpr 和 const 的区别在于:
> constexpr 表示编译器常量
> 而 const 只表示了常量(而未区分编译器常量还是运行期常量)

## 类的静态成员

```c++
class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

// 使用作用域运算符访问静态成员
double r = Account::rate();
```

### 定义静态成员

当在类的外部定义静态成员时, 不能重复 `static` 关键字, 该关键字只能出现在内部的声明语句:

```c++
void Account::rate(double r)
{
    interestRate = r;
}
```

一般来说, 我们不在类的内部定义和初始化静态成员, 必须在类的外部定义和初始化每个静态成员。

如果在类内部初始化静态成员, 则要求静态成员必须是字面值常量类型的 constexpr, 初始值必须是常量表达式。

静态成员的类型可以是不完全类型, 而非静态数据成员类型如果是不完全类型, 则只能是指针或引用:

```c++
class Bar
{
public:
    // ...
private:
    static Bar bar;
    Bar *bp;
    Bar &br;
};
```

静态成员可以作为构造函数的默认实参:

```c++
class Screen
{
public:
    Screen & clear(char = bkGround);

private:
    static const char bkGround;
};
```
