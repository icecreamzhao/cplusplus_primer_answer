# 第八章笔记

## IO 类

为了支持使用宽字符的语言, 标准库定义了一组类型和对象来操作 wchar_t 类型的数据。宽字符版本的类型和函数的名字以一个 w 开始。例如: wcin、wcout 和 wcerr。

### 条件状态

| 状态 | 说明 |
| ---: | :-- |
| strm::iostate | iostate 是一种机器相关的类型, 提供了表达条件状态的完整功能 |
| strm::badbit | 用来指出流已崩溃 |
| strm::failbit | 用来指出一个IO操作失败了 |
| strm::eofbit | 用来指出流达到了文件结束 |
| strm::goodbit | 用来指出流未处于错误状态。此值保证为零 |
| s.eof() | 若流s的eofbit置位, 则返回true |
| s.fail() | 若流s的 failbit 或 badbit 置位, 则返回 true |
| s.bad() | 若流s的 badbit 置位, 则返回 true |
| s.good() | 若流s处于有效状态, 则返回 true |
| s.clear() | 将流s中所有条件状态位复位, 将流的状态设置为有效, 返回 void |
| s.clear(flags) | 根据给定的 flags 标志位, 将流s中对应的条件状态位复位。flags的类型为strm::iostate。返回void |
| s.setState(flags) | 根据给定的 flags 标志位, 将流s中对应条件状态位置位。flags的类型为strm::iostate。返回void |
| s.rdstate() | 返回流s的当前条件状态, 返回值类型为 strm::iostate |

### 查询流的状态

IO库定义了四个iostate类型的constexpr值, 用来表示流当前的状态。

* badbit 表示系统级错误, 一旦badbit被置位, 流就无法再使用了。
* failbit 表示可恢复错误, 如到达文件结束位置, eofbit和failbit都会被置位
* goodbit 表示流未发生错误

除了goodbit之外, 其他任意一个状态被置位, 条件检测(if 或者 while) 都会失败。

### 管理输出缓冲

可以使用以下字符来刷新缓冲区:

* flush 直接输出, 不附加任何字符
* ends 附加一个空格字符并刷新
* endl 附加一个换行符并刷新

unitbuf 字符

```c++
// 接下来所有的输出都会进行一次flush操作
cout << unitbuf;
// 关掉
cout << nounitbuf;
```

> waring 如果程序崩溃, 缓存区不会自动刷新

### 关联输入流和输出流

当一个输入流和输出流关联时, 任何试图从输入流读取的操作都会先关联输出流。

`cin >> inval` 会导致cout被刷新

```c++
cin.tie(&cout);
// 解除cin的关联
ostream *old_tie = cin.tie(nullptr);
```
## 文件输入输出

适用于cout, cin的操作也可以用在ifstream和ofstream上, 因为ifstream和ofstream继承自stream类型。

fstream特有的操作:

| 方法 | 说明 |
| --: | :--- |
| fstream fstrm | 创建一个未绑定的文件流, fstream是头文件fstream定义的一个类型 |
| fstream fstrm(s) | 创建一个fstream, 并打开名为s的文件, s可以是string类型, 或者是一个指向C风格字符串的指针, 这些构造函数都是explicit的, 默认的文件模式mode依赖于fstream的类型 |
| fstream fstrm(s, mode); | 与前一个构造函数类似, 但按指定mode打开文件 |
| fstrm.open(s) | 打开名为s的文件, 并将文件与fstrm绑定。s可以是一个string或一个指向C风格字符串的指针。默认的文件mode 依赖于fstream类型, 返回void |
| fstrm.close() | 关闭与fstrm绑定的文件, 返回void |
| fstrm.is_open() | 返回一个bool值, 指出与fstrm关联的文件是否成功打开并且尚未关闭 |

### 成员函数open和close

如果定义一个空文件流对象, 可以调用open来将它与文件关联起来:

```c++
// 直接使用ifile初始化文件流
ifstream in(ifile);

// 输出文件流未与任何文件相关联
ofstream out;
out.open(ifile + "copy");

if (out)
    // file open success

in.close(); // 关闭文件
```

当一个fstream对象被销毁时, 会自动调用close()函数。

## 文件模式

| 文件模式 | 说明 |
| ------: | :--- |
| in | 以读方式打开 |
| out | 以写方式打开 |
| app | 每次写操作前均定位到文件末尾 |
| ate | 打开文件后立即定位到文件末尾 |
| trunc | 截断文件 |
| binary | 以二进制方式进行IO |

指定文件模式时有如下限制:

* 只可以对ofstream或fstream设置out模式
* 只可以对ifstream或fstream设置in模式
* 只有当out也被设定时才可以设置trunc模式
* 只要trunc模式没有被设定, 就可以设置app模式。在app模式下, 即使没有设定out模式, 文件也总是以输出方式打开
* 默认情况下, 即使没有指定trunc模式, 以out模式打开的文件也会被截断, 为了保留以out模式打开的文件的内容, 必须同时指定app模式, 这样只会将数据追加至文件末尾; 或者同时指定in模式, 打开文件的同时进行读写操作
* ate和binary可用于任何类型的文件流对象, 且可以与任何文件模式组合使用

未指定文件模式时, ifstream关联的文件默认以in模式打开, ofstream默认以out模式打开, fstream默认以out和in模式打开。

以out模式打开文件会丢弃已有数据, 此处可以查看`Chapter_8.h`中的overwrite_file()方法。

调用open方法和文件名隐式初始化的方式都可以指定文件模式:

```c++
ifstream ifs("test.txt", ifstream::app);
ifstream ifs;
ifs.open("test.txt", ifstream::app);
```

## string 流

stringstream 特有的操作:

| 操作 | 说明 |
| ---: | :-- |
| sstream strm; | strm 是一个未绑定的stringstream对象, sstream 是头文件sstream的一个类型 |
| sstream strm(s) | strm 是一个sstream对象, 保存 string s 的一个拷贝, 此构造函数是 explicit 的 |
| strm.str() | 返回strm所保存的string的拷贝 |
| strm.str(s) | 将string s拷贝到strm中, 返回void |

istringstream 和 ostringstream

