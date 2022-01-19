# �����±ʼ�

## �ֲ���̬����

��ʼ����֪��������ֹ�Żᱻ����, �����Ǻ��������ִ��Ҳ����Ӱ�쵽�ö�����������ڡ�

## ��������

����������������ʽ, �ֱ���**ֵ����**��**���ô���**��

ֵ���ݵķ�ʽ��, ʵ�ε�ֵ���������β�, ���βεĲ�������Ӱ�쵽ʵ��

���ô��ݵķ�ʽ��, �βε���������������, ����ֵ�����õĵ�ַ, ���βεĲ������Ƕ�ʵ�εĲ�����

> ָ���β�
> ����β�������ָ��, ����ָ��Ҳ�Ƕ���, ��ô�ı�ָ���β������ַ�ʽ:

```c++
void ract(int *p)
{
    // �ı���ǿ���֮����β�ָ��, ��ʵ����Ӱ��
    p = 0;
    // �ı����ָ����ָ�Ķ����ֵ, ʵ����ָ��Ķ����ֵҲ���ı�
    *p = 0;
}
```

## �����β�

�������������Լ�ʹ������ʱͨ����ת����ָ�롣

������ֵ���ݷ�ʽ�������顣

```c++
void print(const int*);
void print(const int[]);
void print(const int[10]);
```

�����ַ�ʽ�ǵȼ۵ġ�

### ʹ�ñ��ָ�����鳤��

```c++
void print(const char *cp)
{
    if (cp) // cp����һ����ָ��
        while (*cp) // cpָ����ַ�����һ�����ַ�
            cout << *cp++; // �����ǰ�ַ�����ָ����ǰ�ƶ�һ��λ��
}
```

���ֶ���C����ַ�����˵�Ƚ�����, ��ΪC����ַ������λһ���ǿ��ַ�, ���Ƕ���int����, �Ͳ������ˡ�

### ʹ�ñ�׼��淶

```c++
void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++;
}
```

### ��ʾ����һ����ʾ�����С���β�

```c++
void print(const int ca[], size_t size)
{
 for (size_t i = 0; i != size; ++i)
    cout << ca[i];
}
```

### ���пɱ��βεĺ���

���������ʵ������δ֪����������ͬ, �����ʹ��`initializer_list` ���͵��βΡ�

initializer_list ���Ͷ�����ͬ����ͷ�ļ���, �ṩ�Ĳ�������:

| ���� | ˵�� |
| --: | :--- |
| initializer_list<T> lst; | Ĭ�ϳ�ʼ��, T����Ԫ�صĿ��б� |
| initializer_list<T> lst{a,b,c,...}; | lst�ĳ�ʼֵ�������б��е�Ԫ��һ����; lst��Ԫ���Ƕ�Ӧ��ʼֵ�ĸ���; �б��е�Ԫ���� const |
| lst2(lst); lst2 = lst; | ������ֵһ��initializer_list���󲻻´���б��е�Ԫ��, ������, ԭʼ�б�͸�������Ԫ�� |
| lst.size() | �б��е�Ԫ������ |
| lst.begin() | ����ָ��lst��Ԫ�ص�ָ�� |
| lst.end() | ����ָ��lstβԪ�ص�ָ�� |

initializer_list�б��е�Ԫ����Զ���ǳ���ֵ��

ʹ��:

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

## ��������

C++11 ��׼�涨, �������Է��ػ����Ű�Χ��ֵ�б�,

��Զ��Ҫ������ʱ��������á�

## ��������

����ָ�������, �������͵Ķ���const��������Ϊ���ص�������

### const_cast ������

���һ���汾��shortString�������βκͷ���ֵ����const, ������һ������, �����ʹ��const_cast:

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

## ����������constexpr����

��������������:

�ڱ��������������չ��, ����:

```c++
cout << shortString(s1, s2) << endl;

// ����֮������:
cout << (s1.size() >= s2.size() ? s2 : s1) << endl;
```

�������������Ż���ģ��С, ����ֱ��, Ƶ�����õĺ�����

constexpr�����Ķ���:

constexpr������ָ�����ڳ������ʽ�ĺ���, ������constexpr�����ķ�����Ҫ��ѭ����Լ��:

* �����ķ������ͼ��β����Ͷ���������ֵ����
* ����������ֻ����һ��return���

```c++
constexpr int new_sz() {return 42;}
constexpr int foo = new_sz();
```

����������constexpr�����Ķ���ͨ����ŵ�ͷ�ļ��С�

## ���԰���

assert(expr) ��һ��Ԥ�����, ���ȶ�expr��ֵ, ������ʽΪ��, assert�����Ϣ����ֹ�����ִ��, ������ʽΪ��, assertʲôҲ������

������Ԥ�����, ������Ԥ���������Ǳ���������, ������ǿ���ֱ��ʹ��Ԥ��������ֶ�����using������

### NODEBUGԤ�������

���������`NODEBUG`����, ��assertʲôҲ����

```c++
#define NODEBUG
``` 

assertӦ�ý�������֤��Щȷʵ�����ܷ�������, �������������������ʱ�߼����, Ҳ�������������Ӧ�ð����Ĵ����顣

���û�ж���NODEBUG, ��ִ��`#ifndef`��`#endif`֮��Ĵ���, ���������, ��Щ���뽫�ᱻ���Ե���

## ʵ������ת��

Ϊ��ȷ�����ƥ��, ��������ʵ�����͵��β����͵�ת����Ϊ�����¼����ȼ�:

1. ��ȷƥ��, �������¼������:
    * ʵ���������β�������ͬ
    * ʵ�δ��������ͻ�������ת����ָ������
    * ��ʵ����Ӷ���const��ɾ������const
2. ͨ��constת��ʵ��ƥ��
3. ͨ����������ʵ��ƥ��
4. ͨ����������ת����ָ��ת��ʵ��ƥ��
5. ͨ��������ת��ʵ��ƥ��

### ��Ҫ�����������������͵�ת����ƥ��

```c++
void ff(int);
void ff(short);

ff('x'); // ���õ���ff(int)

void manip(long);
void mainip(float);
mainip(3.14); //error, ���ڶ�����
```

## ����ָ��

����ָ��ָ�����һ������, ������ʽ����:

```c++
// pf ������һ��ָ��, �����һ������
bool (*pf)(const string &, const string &);
// pf ��һ������, ���ص���һ��ָ��bool���͵�ָ��
bool *pf(const string &, const string &);
```

* ʹ�ú���ָ��

```c++
pf = lengthCompare;
pf = &lengthCompare; // �ȼ۵ĸ�ֵ���, ȡ��ַ���ǿ�ѡ��
bool f1 = pf("hello", "goodbye"); // ����lengthCompare
bool f1 = (*pf)("hello", "goodbye"); // һ���ȼ۵ĵ���
```

* ���غ�����ָ��

```c++
void ff(int*);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff; // pf1ָ��ff(unsigned int)
```

* ����ָ���β�

```c++
// �������β��Ǻ�������, ���Զ�ת����ָ������ָ��
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));

// ��ʽ�Ľ��βζ����ָ������ָ��
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));

// ����, �Զ���lengthCompareת����ָ��
useBigger(s1, s2, lengthCompare);
```

* ����ָ������ָ��

```c++
using F = int(int *, int) // ��������
using PF = int(*)(int *, int) // PF��ָ������

PF f1(); // f1����һ��ָ������ָ��
F *f2(); // f2����һ��ָ������ָ��
F f3(); // error, f3���ܷ��غ���, ��Ҫ��ʽ�Ķ���Ϊָ������

// ��ʽ�Ķ���һ������ָ������ָ��
// ����f1��һ������, ���f1���ص�������һ��ָ��, ���Ÿ�ָ�뱾��Ҳ�����β��б�(int *, int), ���Ը�ָ��ָ����, ������ָ��ĺ����ķ���ֵ��int
int (*f1(int))(int *, int);
```
