# 第九章笔记

## 顺序容器

顺序容器类型

| 容器名称 | 说明 |
| -------: | :-- |
| vector | 可变大小数组, 支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢 |
| deque | 双端队列, 支持快速随机访问。在头尾位置插入/删除速度很快 |
| list | 双向链表, 只支持双向顺序访问, 在list中任何位置进行插入/删除操作速度都很快 |
| forward_list | 单向链表, 只支持单项顺序访问, 在链表任何位置进行插入/删除操作速度都很快 |
| array | 固定大小数组, 支持快速随机访问, 不能添加/删除元素 |
| string | 与vector相似的容器, 但专门用于保存字符, 随机访问速度快, 在尾部插入/删除速度快 |

选择容器的标准:

* 除非有更好的理由选择其他的容器, 不然应使用vector
* 如果程序有很多小的元素, 且空间的额外开销很重要, 则不要用 list 或 forward_list
* 如果程序要求随机访问元素, 应使用vector或者deque
* 如果程序要求中容器中间插入或删除元素, 则应使用list或forward_list
* 如果程序需要在头尾插入或删除元素, 不会在中间插入或删除操作, 应使用deque
* 如果程序只有在读取输入时才需要在容器中间进行插入或删除元素, 随后需要随机访问元素, 则:
    * 首先确定是否真的需要在中间插入元素, 当处理输入数据时, 可以先进行sort函数, 从而避免在中间插入元素
    * 如果必须在中间插入元素, 考虑在输入阶段使用list, 一旦输入完成, 将list的内容拷贝到vector中

如果程序既需要随机访问元素, 又需要在容器中间插入元素, 取决于在list和forward_list中访问元素与vector或deque中插入/删除元素的相对性能。执行的访问操作更多还是插入删除操作更多决定了选择list/forward_list和vector/deque

## 容器库概览

当一个类如果没有默认构造器, 在使用容器时需要提供元素初始化器。

```c++
vector<nodefault> vec(10, init); // 提供了元素初始化器
vector<nodefault> vec(10); // error: 没有提供元素初始化器
```

容器操作:

| 类型别名 | 说明 |
| ------: | :--- |
| iterator | 此容器类型的迭代器类型 |
| const_iterator | 可以读取元素, 但不能修改元素的迭代器类型 |
| size_type | 无符号整数类型, 足够保存此种容器类型最大可能容器的大小 |
| diffierence_type | 带符号整数类型, 足够保存两个迭代器之间的距离 |
| value_type | 元素类型 |
| reference | 元素的左值类型, 与value_type&含义相同 |
| const_reference | 元素的const左值类型(即 const value_type &) |

| 构造函数 | 说明 |
| ------: | :--- |
| C c; | 默认构造函数, 构造空容器 |
| c c1(c2); | 构造c2的拷贝c1 |
| C c(b, e); | 构造c, 将迭代器 b 和 e 指定的范围内的元素拷贝到 c(array不支持) |
| C c(a, b, c, ...); | 列表初始化 |

| 赋值与swap | 说明 |
| --------: | :--- |
| c1 = c2 | 将c1中的元素替换为c2中的元素 |
| c1 = {a, b, c} | 将c1中的元素替换为列表中元素(不适用于array) |
| a.swap(b) | 交换a和b的元素 |

| 大小 | 说明 |
| --: | :--- |
| c.size() | c中元素的数目(不支持forward_list) |
| c.max_size() | c可保存的最大元素数目 |
| c.empty() | 若c中存储了元素, 返回false, 否则返回true |

添加/删除元素(不适用于array) | 说明 |
| -----------------------: | :--- |
| c.insert(args) | 将args中的元素拷贝进c |
| c.emplace(inits) | 使用inits构造c中的一个元素 |
| c.erase(args) | 删除args指定的元素 |
| c.clear() | 删除c中的所有元素, 返回void |

| 获取迭代器 | 说明 |
| --------: | :--- |
c.begin(), c.end() | 返回指向c的首元素和尾元素之后位置的迭代器 |
| c.cbegin(), c.cend() | 返回 const_iterator |

| 反向容器的额外成员(不支持forward_list) | 说明 |
| ---------------: | :-- |
| reverse_iterator | 按逆序寻址元素的迭代器 |
| const_reverse_iterator | 不能修改元素的逆序迭代器 |
| c.rbegin(), c.rend() | 返回指向c的尾元素和首元素之前位置的迭代器 |
| c.crbegin(), c.crend() | 返回 const_reverse_iterator |

## 迭代器

迭代器范围:

元素范围为左闭合区间, begin指向首元素, end指向最后一个元素的后面的一个位置。

## 容器定义和初始化

将一个容器初始化为另一个容器的拷贝, 容器类型和元素类型必须匹配, 但是当拷贝的是容器之间的范围的时候就不要求容器类型匹配了。

```c++
vector<string> authors = {"a", "b", "c"};
vector<const char*> articles = {"d", "e", "f"};

vector<string> list2(authors); // 容器和元素类型都匹配
list<string> authorList(authors); // error, 容器类型不匹配
deque<const char*> dequeArticles(articles); // 容器类型不匹配
list<const char*> authorList(authors.begin(), authors.end()); // const char* 可以转换为string
```

### 标准库array

定义一个array时, 除了需要指定数据类型, 还需要指定长度。

```c++
array<int, 42> arr;
```

内置数组不支持赋值和拷贝, 但是标准库array支持。

### 赋值和swap

| 操作 | 说明 |
| ---: | :-- |
| c1 = c2 | 将c2中的元素拷贝到c1中, c1和c2都必须具有相同的类型 |
| c = {a,b,c}; | 将初始化列表中的元素拷贝到c中, array不适用 |
| swap(c1, c2); <br/> c1.swap(c2); | 交换c1和c2容器中的元素, c1和c2都必须具有相同的类型, swap通常会比拷贝快得多 |
| seq.assign(b, e); assign不适用于关联容器和array | seq替换为b和e之间的元素 |
| seq.assign(li); | 将seq替换为li中的元素 |
| seq.assign(n, t); | 将seq替换为n个值为t的元素 |

### 关系运算符

比较两个容器实际上是进行元素的逐对比较, 使用的是元素的关系运算符进行的比较。

所以如果容器中的容器没有定义关系运算符, 则不能对其进行比较。

## 顺序容器操作

向顺序容器添加元素的操作

| 操作 | 说明 |
| --: | :--- |
| c.push_back(t)<br/> c.emplace_back(args) | 在c的尾部创建一个值为t或由args创建的元素, 返回void |
| c.push_front(t)<br/>c.emplace_front(args) | 在c的头部创建一个值为t或由args创建的元素, 返回void |
| c.insert(p,t)<br/>c.emplace(p, args) | 在迭代器p指向的元素之前创建一个值为t或args创建的元素, 返回指向新添加的元素的迭代器 |
| c.insert(p,n,t) | 在迭代器p指向的元素之前插入n个值为t的元素, 返回指向新添加的第一个元素的迭代器, 若n为0, 则返回p |
| c.insert(p,b,e) | 将迭代器b和e指定范围内的元素插入到迭代器p所指向的元素之前。b和e不能指向c中的元素, 返回指向新添加的第一个元素的迭代器; 若范围为空, 则返回p |
| c.insert(p, il) | il是一个花括号包围的元素值列表, 将这些给定的值插入到p指向的元素之前, 返回指向新添加的第一个元素的迭代器, 若列表为空, 返回p |

* array不支持这些操作
* forward_list有自己版本的insert和emplace
* forward_list不支持push_back和emplace_back
* vector和string不支持push_front和emplace_front

## 使用 emplace 操作

新标准引入三个新成员 —— emplace_front, emplace, emplace_back, 这些操作是构造而不是拷贝元素。

```c++
// 使用Sales_data构造器的三个参数的版本
c.emplace_back("abcdefg", 25, 19.99);
// 错误, 没有接受三个参数的push_back的版本
c.push_back("abcdefg", 25, 19.99);
// 正确, 构造一个临时对象传递给c
c.push_back(Sales_data("abcdefg", 25, 19.99));
```

## 访问元素

在顺序容器中访问元素:

| 操作 | 说明 |
| :--: | :--: |
| c.back() | 获取尾元素 |
| c.front() | 获取首元素 |
| c[n] | 返回下标为n的元素的引用, n是一个无符号整数, 若 n >= c.size(), 则函数行为未定义 |
| c.at(n) | 返回下标为n的元素的引用, 如果下标越界, 则抛出 out_of_range 异常 |

at 和下标操作只适用于string, vector, deque和array
back 不适用于 forward_list

## 删除元素

在顺序容器中删除元素:

| 操作 | 说明 |
| :--: | :--: |
| c.pop_back(); | 删除尾元素, 如果c为空, 则函数行为未定义, 返回void |
| c.pop_front(); | 删除头元素, 如果c为空, 则函数行为未定义, 返回void |
| c.erase(p); | 删除迭代器p所指定的元素, 返回一个指向被删元素之后的元素迭代器, 若p指向尾元素, 则返回尾后迭代器, 若p是尾后迭代器, 则函数行为未定义 |
| c.erase(b, e); | 删除迭代器b和e所指定范围内的元素, 返回一个指向最后一个被删元素之后的迭代器, 若e本身是尾后迭代器, 则返回尾后迭代器 |
| c.clear(); | 删除c中所有元素, 返回void |

* 以上操作不适用array
* forward_list有特殊版本的earse
* forward_list不支持pop_back; vector和string不支持pop_front

### forward_list的特殊操作

由于forward_list是一个单向链表, 所以只能访问到后面的元素。而当添加或者删除元素时, 需要改变前一个元素指针, 使其指向被删元素的下一个元素, 但是由于单向链表不能轻易获取到前一个元素, 所以单独定义了一系列操作函数来操作forward_list。

| 操作 | 说明 |
| :--: | :--: |
| lst.before_begin() | 返回指向首元素之前不存在的迭代器, 该迭代器不能解引用, cbefore_begin() 返回 const_iterator |
| lst.insert_after(p, t) <br> lst.insert.after(p, n, t) <br> lst.insert_after(p, b, e) <br> lst.insert_after(p, li) | 在迭代器p后面插入元素, n代表数量, b e 代表范围, li表示一组花括号元素, 返回一个指向最后插入元素的迭代器, 若范围为空, 则返回p, 若p为尾后迭代器, 则行为未定义 |
| emplace_after(p, args) | 使用args在p指定的位置之后创建一个元素, 返回一个指向新元素的迭代器, 若p为尾后迭代器, 则函数行为未定义 |
| lst.erase_after(p)<br>lst.earse_after(b, e) | 删除p指向位置之后的元素, 或删除从b之后(但不包含)到e之间的元素。返回一个指向被删元素之后的迭代器, 若不存在这样的元素, 则返回尾后迭代器, 若p指向lst的尾元素或是一个尾后迭代器, 则函数行为未定义 |

## 改变容器大小

| 操作 | 说明 |
| :--: | :--: |
| c.resize(n) | 调整c的大小为n个元素, 若n < c.size(), 则多出去的元素被丢弃, 若必须添加新元素, 对新元素进行值初始化 |
| c.resize(n, t) | 调成c的大小为n个元素, 新元素初始化为t |

## vector对象是如何增长的

为了支持快速随机访问, vector将元素连续存储。而容器的大小是可变的, 如果没有空间添加新的元素, 容器不可能简单的将元素添加到其他位置, 因为元素必须连续存储, 将已有元素从旧的位置移动到新的更大的空间中, 然后添加新元素, 释放旧空间, 为了避免每一次添加新元素就需要进行一次内存分配和释放操作, 采用了减少容器空间分配次数的策略, 当不得不获取新的内存空间时, vector和string通常会获取比新的空间更大的内存空间, 预留空间备用。

> 管理容量的成员函数

| 操作 | 说明 |
| :--: | :--: |
| c.shrink_to_fit() | 将capacity()减少为size()同样大小 |
| c.capacity() | 不重新分配内存的话, 可以保存多少元素 |
| c.reserve(n) | 分配至少能容纳n个元素的空间 |

> shrink_to_fit() 只适用于vector, string和deque
> capacity()和reserve()只适用于vector和string

## 额外的string操作

// TODO: 略过

## 容器适配器

一个容器适配器接受一种已有容器类型, 使其行为看起来像一种不同的类型, 例如stack适配器接受一个顺序容器(除array和forward_list之外), 使其操作看起来像stack一样。

| 类型 | 说明 |
| :--: | :--: |
| size_type | 一种类型, 足以保存当前类型的最大对象的大小 |
| value_type | 元素类型 |
| container_type | 实现适配器的底层容器类型 |
| A a; | 创建一个名为a的空适配器 |
| A a(c); | 创建一个名为a的适配器, 带有一个容器c的拷贝 |
| 关系运算符 | 每个适配器都支持所有关系运算符: == != < <= > >=, 这些运算符返回底层容器的比较结果 |
| a.empty() | 若a包含任何元素, 返回false, 否则返回true |
| a.size() | 返回a中的元素数目 |
| swap(a, b) <br> a.swap(b) | 交换a和b的内容, a和b必须是相同的类型, 包括底层容器类型也必须相同 |

定义一个适配器:

```c++
// deq是一个deque<int>
stack<int> stk(deq);

// 指定默认的适配器类型
stack<int, vector<int>> stk;
```

所有适配器都要求容器具有删除和添加元素及访问尾元素的能力, 所以适配器不能用于array和forward_list。

queue适配器要求back, push_back, front, push_front, 因此可以构造与list和deque之上, 但不能基于vector, priority_queue除了front, push_back和pop_back之外要求具有随机访问的能力, 因此可以构造于vector或deque之上, 但不能基于list构造。


