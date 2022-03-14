#include "Chapter_9.h"
#include <windows.h>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <string>
#include <iterator>
#include <stack>

using std::deque;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::string;
using std::begin;
using std::end;
using std::forward_list;
using std::stack;

/*
======================================
测试容器性能
======================================
*/
void Chapter_nine::containerTest()
{
	ULONGLONG start, end;

	// vector
	vector<int> vec;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		vec.push_back(i);
	end = GetTickCount64();
	cout << "vector 尾部插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	vector<int> vec2;
	for (int i = 0; i != 100000; ++i)
		vec2.insert(vec2.begin(), i);
	end = GetTickCount64();
	cout << "vector 头部插入十万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	vector<int> vec3;
	for (int i = 0; i != 100000; ++i)
	{
		if (vec3.size() > 0)
			vec3.insert(vec3.begin() + 1, i);
		else
			vec3.insert(vec3.begin(), i);
	}
	end = GetTickCount64();
	cout << "vector 中间插入十万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	// deque
	deque<int> deq;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		deq.push_back(i);
	end = GetTickCount64();
	cout << "deque 尾部插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	deque<int> deq2;
	for (int i = 0; i != 1000000; ++i)
		deq2.push_front(i);
	end = GetTickCount64();
	cout << "deque 头部插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	deque<int> deq3;
	for (int i = 0; i != 1000000; ++i)
	{
		if (deq3.size() > 0)
			deq3.insert(deq3.begin() + 1, i);
		else
			deq3.insert(deq3.begin(), i);
	}
	end = GetTickCount64();
	cout << "deque 中间插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	// list
	list<int> list1;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		list1.push_back(i);
	end = GetTickCount64();
	cout << "list 尾部插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	list<int> list2;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		list2.push_front(i);
	end = GetTickCount64();
	cout << "list 头部插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	list<int> list3;
	for (int i = 0; i != 1000000; ++i)
	{
		if (list3.size() > 0)
			list3.insert(list3.begin()++, i);
		else
			list3.insert(list3.begin(), i);
	}
	end = GetTickCount64();
	cout << "list 中间插入一百万条数据所需时间: " << ((end - start) * 1.0 / 1000) << endl;
}

/*
======================================
定义一个list对象, 其元素类型是int的deque
======================================
*/
void Chapter_nine::p_9p2_9p2()
{
	list<deque<int>> list;
	list = { {1,2,3,4,5}, {6,7,8,9,10} };
}

/*
======================================
编写函数, 接受一对指向vector<int>的迭代器和一个int值, 在两个
迭代器指定范围内查找给定的值, 返回一个布尔值来指出是否找到

参数:

>> beg:		指向vector的迭代器
>> last:	指向vector的迭代器
>> i:		要找的元素
======================================
*/
bool Chapter_nine::p_9p2p1_9p4(vector<int>::iterator beg, vector<int>::const_iterator last, const int i)
{
	while (beg != last)
		if ((*beg++) == i)
			return true;
	return false;
}

/*
======================================
编写函数, 接受一对指向vector<int>的迭代器和一个int值, 在两个
迭代器指定范围内查找给定的值, 返回一个布尔值来指出是否找到

参数:

>> beg:		指向vector的迭代器
>> last:	指向vector的迭代器
>> i:		要找的元素
======================================
*/
vector<int>::iterator Chapter_nine::p_9p2p1_9p5(vector<int>::iterator beg, vector<int>::const_iterator last, const int i)
{
	while (beg != last)
	{
		if ((*beg++) == i)
			return beg - 1;
	}
	return beg - 1;
}

/*
======================================
尝试vector的6中初始化方式
======================================
*/
void Chapter_nine::p_9p2p4_p9p11()
{
	// 10 个元素, 都是0
	vector<int> vec(10);
	// 10 个元素, 都是2
	vector<int> vec2(10, 2);
	// 10 个元素
	vector<int> vec3 = { 1,2,3,4,5,6,7,8,9,10 };
	// 拷贝初始化
	vector<int> vec4(vec);
	// 拷贝初始化(范围)
	vector<int> vec5(vec.begin(), vec.end() - 1);
	// 拷贝初始化
	vector<int> vec6 = vec;
}

void Chapter_nine::p_9p2p4_p9p13()
{
	list<int> intList(10, 1);
	vector<double> doubleVec(intList.begin(), intList.end());

	for (double d : doubleVec)
		cout << d << "\t";

	cout << endl;

	vector<int> vec(intList.begin(), intList.end());
	for (double d : doubleVec)
		cout << d << "\t";

	cout << endl;
}

/*
======================================
尝试assign的使用方式
======================================
*/
void Chapter_nine::assignTest()
{
	vector<int> vec(10, 4);
	list<int> list(10, 2);
	list.assign(vec.cbegin(), vec.cend() - 1);

	for (int i : list)
		cout << i << "\t";
	cout << list.size() << endl;

	list.assign(5, 7);
	for (int i : list)
		cout << i << "\t";
	cout << list.size() << endl;
}

/*
======================================
尝试swap的使用方式
======================================
*/
void Chapter_nine::swapTest()
{
	vector<int> vec(10, 2);
	vector<int> vec2(10, 3);

	// 只是交换了内部的数据结构, 而并未对元素本身做交换操作
	swap(vec, vec2);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
向vector中插入元素(不是尾部就会很耗时)
======================================
*/
void Chapter_nine::insertTest()
{
	// 插入头部(会很耗时)
	vector<int> vec = {1,2,3,4,5};
	vec.insert(vec.begin(), 0);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;

	// 插入多个元素到尾部
	vec.insert(vec.end(), 10, 5);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;
	
	// 这里insert方法会在指定迭代器之前创建一个新元素, 而不是之后
	vec = { 6,7,8,9,10 };
	auto be = vec.begin();
	for (int i = 5; i != 0; --i)
		be = vec.insert(be, i);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
将list中的char *指针元素赋值给一个vector中的string
======================================
*/
void Chapter_nine::p_9p2p5_p9p14()
{
	list<char *> cStrList(10, "a");
	// 可以直接利用类型自动转换
	vector<string> strVec(cStrList.cbegin(), cStrList.cend());

	for (string s : strVec)
		cout << s << "\t";
	cout << endl;
}

/*
======================================
判定两个vector<int>是否相等
======================================
*/
void Chapter_nine::p_9p2p7_p9p15()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {1,2,3};

	bool a = (v1 == v2);
	cout << (a ? "相等" : "不相等") << endl;
}

/*
======================================
比较list<int> 中的元素和 vector<int> 中的元素
======================================
*/
void Chapter_nine::p_9p2p7_p9p16()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {1,2,3};

	bool a = (v1[0] == v2[0]);
	cout << (a ? "相等" : "不相等") << endl;
}

/*
======================================
编写程序, 从标准输入读取string序列, 
存入一个deque中, 编写一个循环,用迭代器打印deque中的元素
======================================
*/
void Chapter_nine::p_9p3p1_p9p18()
{
	string inputS;
	deque<string> deque_string;
	while (cin >> inputS)
	{
		deque_string.push_back(inputS);
	}
	deque<string>::const_iterator iter = deque_string.cbegin();
	while (iter != deque_string.cend())
	{
		cout << *iter++ << endl;
	}
}

/*
======================================
重新上一题的程序, 使用list替代deque, 指出程序
要做那些改变
======================================
*/
void Chapter_nine::p_9p3p1_p9p19()
{
	string inputS;
	list<string> deque_string;
	while (cin >> inputS)
	{
		deque_string.push_back(inputS);
	}
	list<string>::const_iterator iter = deque_string.cbegin();
	while (iter != deque_string.cend())
	{
		cout << *iter++ << endl;
	}
}

/*
======================================
编写程序, 从一个list拷贝到两个deque中, 值为偶数的
拷贝到一个deque中, 值为奇数的拷贝到另一个deque中
======================================
*/
void Chapter_nine::p_9p3p1_p9p20()
{
	list<int> list1 = {1,2,3,4,5,6,7,8,9};
	list<int>::const_iterator citer = list1.cbegin();

	deque<int> de1;
	deque<int> de2;
	for (auto citer = list1.cbegin(); citer != list1.cend(); ++citer)
	{
		if (*citer % 2 == 0)
			de1.push_back(*citer);
		else
			de2.push_back(*citer);
	}

	for (auto iter = de1.cbegin(); iter != de1.cend(); ++iter)
		cout << *iter << endl;
	for (auto iter = de2.cbegin(); iter != de2.cend(); ++iter)
		cout << *iter << endl;
}

/*
======================================
使用front和back成员获取元素
======================================
*/
void Chapter_nine::frontAndBackTest()
{
	vector<int> vi = {1,2,3,4,5};
	auto i = vi.front();
	i = 6;
	for (vector<int>::const_iterator beg = vi.cbegin(); beg != vi.cend(); ++beg)
		cout << *beg << "\t";
	cout << endl;

	auto &ir = vi.front();
	ir = 6;
	for (vector<int>::const_iterator beg = vi.cbegin(); beg != vi.cend(); ++beg)
		cout << *beg << "\t";
	cout << endl;
}

/*
======================================
如果列表中只有一个值, 则front back 等成员函数的值是多少
======================================
*/
void Chapter_nine::p_9p3p2_p9p23()
{
	vector<int> vi = {1};

	if (!vi.empty())
	{
		auto val1 = vi.front(), val2 = *(vi.begin());
		auto last = vi.end();
		auto val3 = *(--last);
		auto val4 = vi.back();

		bool result = val1 == val2 == val3 == val4;

		if (result)
			cout << "right" << endl;
		else
			cout << "fail" << endl;
	}
}

/*
======================================
分别使用at, 下标运算符, front和begin提取vector中的
第一个元素
======================================
*/
void Chapter_nine::p_9p3p2_p9p24()
{
	vector<int> iv;
	// 使用下标运算符
	cout << iv[0] << endl;
	// 使用at运算符, 抛出 out_of_range 异常
	cout << iv.at(0) << endl;
	// 使用front
	cout << iv.front() << endl;
	// 使用begin
	cout << *(iv.begin()) << endl;
}

/*
======================================

======================================
*/
void Chapter_nine::p_9p3p3_p9p25()
{
	vector<int> vi = {1,2,3,4,5};
	if (!vi.empty())
	{
		auto be = vi.cbegin();
		vector<int>::const_iterator next = be + 1;
		vi.erase(be, next);
	}
	for (auto be = vi.cbegin(); be != vi.end(); ++be)
	{
		cout << *be << endl;
	}
}

/*
======================================
使用下面代码定义的ia, 将ia拷贝到vector和一个list中, 使用
单迭代器版本的erase从list中删除奇数元素, 从vector中删除偶数元素
======================================
*/
void Chapter_nine::p_9p3p3_p9p26()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vi(begin(ia), end(ia));
	list<int> li(begin(ia), end(ia));

	auto be = vi.begin();
	while (be != vi.end())
	{
		if (*be % 2 != 0)
			be = vi.erase(be);
		else
			++be;
	}

	auto be1 = li.begin();
	while (be1 != li.end())
	{
		if (*be1 % 2 == 0)
			be1 = li.erase(be1);
		else
			++be1;
	}

	for (auto be = vi.begin(); be != vi.end(); ++be)
		cout << *be << "\t";
	for (auto be = li.begin(); be != li.end(); ++be)
		cout << *be << "\t";
	cout << endl;
}

/*
======================================
使用forward_list删除奇数元素
======================================
*/
void Chapter_nine::forward_list_earse()
{
	forward_list<int> lst = { 1,2,3,4,5,6,7,8,9,10 };
	auto prev = lst.before_begin();
	auto curr = lst.begin();

	while (curr != lst.end())
	{
		if (*curr % 2 != 0)
			curr = lst.erase_after(prev);
		else
		{
			prev = curr;
			++curr;
		}
	}

	for (auto i : lst)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
编写函数, 接收一个forward_list<string>, 两个string
函数应在第一个参数中查找第一个string, 并将第二个string
放入到第一个string后, 如果没找到, 放到末尾

params:
>> lst: 需要操作的列表
>> s1:  查找string
>> s2:  插入string
======================================
*/
void Chapter_nine::p_9p3p4_p9p28(forward_list<string> lst, const string s1, const string s2)
{
	auto be = lst.begin();
	auto prev = lst.before_begin();
	while (be != lst.cend())
	{
		if (*be == s1)
		{
			lst.insert_after(be, s2);
			break;
		}
		prev = be;
		++be;
	}
	if (be == lst.cend())
		lst.insert_after(prev, s2);

	be = lst.begin();
	while (be != lst.end())
	{
		cout << *be << endl;
		++be;
	}
}

/*
======================================
对vector使用迭代器进行添加和删除
======================================
*/
void Chapter_nine::insert_and_earse()
{
	vector<int> vi = { 1,2,3,4,5,6,7,8,9,10 };

	auto be = vi.begin();

	while (be != vi.end())
	{
		if (*be % 2 == 0)
		{
			be = vi.insert(be, *be);
			be += 2;
		}
		else
		{
			be = vi.erase(be);
		}
	}

	for (auto i : vi)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
使用list和forward_list进行复制值
======================================
*/
void Chapter_nine::p_9p3p6_p9p31()
{
	// 使用list
	list<int> lst = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto be = lst.begin(); be != lst.end();)
	{
		if (*be & 0x1)
			be = lst.insert(be, *be), advance(be, 2);
		else
			be = lst.erase(be);
	}
	for (auto i : lst)
		cout << i << "\t";
	cout << endl;

	// 使用forward_list
	forward_list<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto prev = data.before_begin(), curr = data.begin(); curr != data.end();)
	{
		if (*curr & 0x1)
			curr = data.insert_after(curr, *curr),
			advance(curr, 2),
			advance(prev, 2);
		else
			curr = data.erase_after(curr);
	}
}

/*
======================================
无限循环
======================================
*/
void Chapter_nine::p_9p3p6_p9p34()
{
	vector<int> vi = {1,2,3,4,5};
	auto be = vi.begin();

	while (be != vi.end())
	{
		if (*be % 2)
			be = vi.insert(be, *be);
		be += 2;
	}

	for (auto i : vi)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
使用capacity和shrink_to_fit来操作vector扩展容量
======================================
*/
void Chapter_nine::capacityAndShrink()
{
	vector<int> vi;
	cout << "vi's size is " << vi.size() << endl;
	cout << "vi's capacity is " << vi.capacity() << endl;

	vi.push_back(1);
	cout << "vi's size is " << vi.size() << endl;
	cout << "vi's capacity is " << vi.capacity() << endl;

	vi.reserve(10);
	cout << "vi's capacity is " << vi.capacity() << endl;

	while (vi.size() != vi.capacity())
		vi.push_back(1);
	cout << "vi's size is " << vi.size() << endl;
	cout << "vi's capacity is " << vi.capacity() << endl;

	vi.push_back(1);
	cout << "vi's size is " << vi.size() << endl;
	cout << "vi's capacity is " << vi.capacity() << endl;

	vi.shrink_to_fit();
	cout << "vi's size is " << vi.size() << endl;
	cout << "vi's capacity is " << vi.capacity() << endl;
}

/*
======================================
解释一下vector的capacity和size的区别
======================================
*/
void Chapter_nine::p_9p4_p9p35()
{
	/*
	vector的capacity可以获取再不扩展内存的情况下还能存多少元素, size则是获取已经存储了多少个元素
	*/
}

/*
======================================
一个容器的capacity会小于size么
======================================
*/
void Chapter_nine::p_9p4_p9p36()
{
	// 不会
}

/*
======================================
为什么list或array没有capacity成员函数?
======================================
*/
void Chapter_nine::p_9p4_p9p37()
{
	// 因为list不提供随机访问, 所以存储顺序不连续
	// array不支持存储扩展
}

void Chapter_nine::p_9p4_p9p38()
{
	vector<int> vi;
	vi.reserve(2);

	vi.push_back(1);
	vi.push_back(1);
	vi.push_back(1);
	vi.push_back(1);
	cout << vi.size() << endl;
	cout << vi.capacity() << endl;
	vi.resize(vi.size() + vi.size() / 2);
	cout << vi.size() << endl;
	cout << vi.capacity() << endl;
}

/*
======================================
stack使用deque适配器
======================================
*/
void Chapter_nine::stackAdapter()
{
	deque<int> deq = {1,2,3,4,5};
	stack<int> my_stack(deq);

	while (!my_stack.empty())
	{
		int i = my_stack.top();
		my_stack.pop();
		cout << i << "\t";
	}
	cout << endl;
}

void Chapter_nine::p_9p6_p9p52()
{
	stack<char> statement;
	char c;
	while (cin >> c)
	{
		if (c == 'q')
			break;
		statement.push(c);
	}

	int i = 0;
	while (!statement.empty())
	{
		char ctemp = statement.top();
		if (ctemp == ')' || i != 0)
		{
			statement.pop();
			++i;
			if (ctemp == '(')
			{
				statement.push('!');
				break;
			}
		}
	}
	while (!statement.empty())
	{
		char ctemp = statement.top();
		cout << ctemp;
		statement.pop();
	}
}

void Chapter_nine::runAll()
{
	//containerTest();
	//p_9p2_9p2();
	vector<int> vec = {1,2,3,4,5};
	//bool result = p_9p2p1_9p4(vec.begin(), vec.cend(), 6);
	//cout << result << endl;
	//auto iter = p_9p2p1_9p5(vec.begin(), vec.cend(), 37);
	//cout << *iter << endl;
	//p_9p2p4_p9p11();
	//p_9p2p4_p9p13();
	//assignTest();
	//swapTest();
	//p_9p2p5_p9p14();
	//p_9p2p7_p9p15();
	//p_9p2p7_p9p16();
	//insertTest();
	//p_9p3p1_p9p18();
	//p_9p3p1_p9p19();
	//p_9p3p1_p9p20();
	//frontAndBackTest();
	//p_9p3p2_p9p23();
	//p_9p3p2_p9p24();
	//p_9p3p3_p9p25();
	//p_9p3p3_p9p26();
	//forward_list_earse();
	forward_list<string> lst = {"a", "b", "c"};
	//p_9p3p4_p9p28(lst, "a", "d");
	//p_9p3p4_p9p28(lst, "d", "d");
	//insert_and_earse();
	//p_9p3p6_p9p31();
	//p_9p3p6_p9p34();
	//capacityAndShrink();
	//p_9p4_p9p38();
	//stackAdapter();
	p_9p6_p9p52();
}