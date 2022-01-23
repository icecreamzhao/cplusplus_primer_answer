# �����±ʼ�

## ��������

��Ҫ����һ��ɹ��ĳ���, ���߱������˽Ⲣʵ���û�������ͬ����, �������������ҲӦ�����й�ע��Щ�п���ʹ�ø���ĳ���Ա��������Ϊһ��������õ���, ��Ҫ��ֱ��������ʹ�õĽӿ�, Ҳ����߱���Ч��ʵ�ֹ��̡�

```c++
struct Sales_data
{
    std::string isbn () const { return bookNo; }
};
```

���ｫconst���ں�����֮��, ��ζ�Ž���ʽ��thisָ������Ϊ����ָ�롣 isbn����Ϊ������Ա������

���԰�isbn���������������ʽ:

```c++
std::string Sales_data::isbn(const Sales_data *const this)
{
    return this->bookNo;
}
```

> ��������, �������ú�ָ�붼ֻ�ܵ��ó�����Ա������

### ����һ������this�ĺ���

```c++
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## ���캯��

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

c++11 �±�׼�涨, ����ʹ��default���ñ���������Ĭ�ϵĹ��캯����
���������������������캯����ʼֵ�б�, ���б����ʼ�����ڵĳ�Ա��

## ���ʿ������װ

ʹ��`class`��`struct`�����ؼ��ֵ�Ψһ��������, class�ڵ�һ�����ʷ�֮ǰ�ĳ�ԱĬ��Ϊprivate, structĬ����public

## ��Ԫ

��һ���ǳ�Ա������ʹ��ĳ�����private��Աʱ, ���������н��ú�������Ϊfriend:

```c++
struct Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data &);
}

// add ���Է���Sales_data��private��Ա
Sales_data add(const Sales_data&, const Sales_data &);
```

## �ɱ����ݳ�Ա

��һ����Ա������Ϊ`mutable`ʱ, ��ʹ��const����, �ó�ԱҲ�ǿ��Ա��ı�ġ�

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

## �����ݳ�Ա�ĳ�ʼֵ

```c++
class Window_mgr
{
prviate:
    vector<Screen> screen_vec{Screen(24, 80, ' ')};
};
```

> ���ṩһ�����ڳ�ʼֵʱ, Ҫʹ�õȺ�(=)���߻�����({})����ʽ


��ʵ����, ������õ�C++���볣������������С�ĺ���, ͨ��������Щ����, �������һ������������"ʵ��"�Ĺ�����

## ������

�����Ƚ���������, Ȼ���ڶ���, ������������Ϊǰ������, ������֮����֮ǰ��һ������ȫ����:

```c++
// Y ��һ������ȫ����
class Y;

class X
{
    // �����Ƚ�������(ָ��, ���������), �����ж���
    Y *y;
};

class Y
{
    X x;
}
```

## ���캯����̽

ʹ�ù��캯�����Գ�Ա���г�ʼ����

�����캯����ʼֵ��˳�����Ա������˳�򱣳�һ��, ����:

```c++
clsss X
{
public:
    X(int val) : j(i), i(val) {}
private:
    int i, j;
};
```

����ʹ��Ĭ��ֵ�Գ�ʼֵ�б���г�ʼ��:

```c++
class Sales_data
{
public:
    Sales_data(string s = "") : bookNo(s) {}
private:
    string bookNo;
};
```

## ί�й��캯��

ί�й��캯����C++11�±�׼��չ��, ������java�еĶ�����캯��, ��ͬ����֮����õ���ʽ:

```c++
class Sales_data
{
public:
    Sales_data(string s, unsigned n, double d) : bookNo(s), units_sold(n), price(d) {}
    // ί�й��캯��
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(string s) : Sales_data(s, 0, 0) {}
    Sales_data(istream &is) : Sales_data() { read(is, *this); }
};
```

## ��ʽ��������ת��

��һ�����캯������ͨ��ĳ���������͹���ʱ, ����ֱ��ʹ�øû����������䵱��ʱ����:

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
book1.combine(null_book); //��ȷ, ��������ʽ���͵�ת��
book1.combine("9999-999-999"); // ����, ��ʽת��ֻ֧��һ������ת��, �����Ƚ� const char *ת����string, Ȼ�����ת���� Sales_data
```

### ���ƹ��캯���������ʽת��

ʹ��explicit�ؼ���������ʽת��:

```c++
class Sales_data
{
    Sales_data() = default;
    explicit Sales_data(const string &s) : bookNo(s) {}
};

Sales_data data = Sales_data();
data.combine(string("9999-999-999")); // ����, �޷��� const string & ת��Ϊ Sales_data ����
```

��ʹ��explicit�������캯��ʱ, ֻ����ֱ�ӳ�ʼ���ķ�ʽʹ��, ����ʹ�ÿ�����ʼ���ķ�ʽ:

```c++
Sales_data data = Sales_data(null_book); // ֱ�ӳ�ʼ��
Sales_data data = null_book; // ����, �޷�ʹ��explicit���캯�����п�����ʼ��
```

������ʾת��:

```c++
data.combine(static_cast<Sales_data)(string("9999-999-999")));
```

## �ۺ���

��һ����������������ʱ, ����˵���Ǿۺϵ�:

* ���г�Ա�� public ��
* û�ж����κι��캯��
* û�����ڳ�ʼֵ
* û�л���, Ҳû��virtual����

����:

```c++
struct Data
{
    int ival;
    string s;
};
```

����ʹ�����ֳ�ʼ����ʽ:

```c++
// ��ʼ����˳����������˳��һ��
Data val1 = {0, "Anna"};
```

## ����ֵ������

���ݳ�Ա��������ֵ���͵ľۺ���������ֵ������, ���һ���಻�Ǿۺ���, ����������Ҫ��, ��Ҳ��һ������ֵ������:

* ���ݳ�Ա������������ֵ����
* ��������ٺ���һ�� constexpr ���캯��
* ���һ�����ݳ�Ա�������ڳ�ʼֵ, ���������ͳ�Ա�ĳ�ʼֵ������һ���������ʽ; ���������Ա����ĳ��������, ���ʼֵ����ʹ�ó�Ա�Լ��� constexpr ���캯����
* �����ʹ������������Ĭ�϶���, �ó�Ա����������Ķ���

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

Debug ��������ֵ�����ࡣ

constexpr �� const ����������:
> constexpr ��ʾ����������
> �� const ֻ��ʾ�˳���(��δ���ֱ������������������ڳ���)

## ��ľ�̬��Ա

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

// ʹ����������������ʾ�̬��Ա
double r = Account::rate();
```

### ���徲̬��Ա

��������ⲿ���徲̬��Աʱ, �����ظ� `static` �ؼ���, �ùؼ���ֻ�ܳ������ڲ����������:

```c++
void Account::rate(double r)
{
    interestRate = r;
}
```

һ����˵, ���ǲ�������ڲ�����ͳ�ʼ����̬��Ա, ����������ⲿ����ͳ�ʼ��ÿ����̬��Ա��

��������ڲ���ʼ����̬��Ա, ��Ҫ��̬��Ա����������ֵ�������͵� constexpr, ��ʼֵ�����ǳ������ʽ��

��̬��Ա�����Ϳ����ǲ���ȫ����, ���Ǿ�̬���ݳ�Ա��������ǲ���ȫ����, ��ֻ����ָ�������:

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

��̬��Ա������Ϊ���캯����Ĭ��ʵ��:

```c++
class Screen
{
public:
    Screen & clear(char = bkGround);

private:
    static const char bkGround;
};
```
