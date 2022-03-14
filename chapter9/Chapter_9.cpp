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
������������
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
	cout << "vector β������һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	vector<int> vec2;
	for (int i = 0; i != 100000; ++i)
		vec2.insert(vec2.begin(), i);
	end = GetTickCount64();
	cout << "vector ͷ������ʮ������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

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
	cout << "vector �м����ʮ������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

	// deque
	deque<int> deq;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		deq.push_back(i);
	end = GetTickCount64();
	cout << "deque β������һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

	start = GetTickCount64();
	deque<int> deq2;
	for (int i = 0; i != 1000000; ++i)
		deq2.push_front(i);
	end = GetTickCount64();
	cout << "deque ͷ������һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

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
	cout << "deque �м����һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

	// list
	list<int> list1;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		list1.push_back(i);
	end = GetTickCount64();
	cout << "list β������һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

	list<int> list2;
	start = GetTickCount64();
	for (int i = 0; i != 1000000; ++i)
		list2.push_front(i);
	end = GetTickCount64();
	cout << "list ͷ������һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;

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
	cout << "list �м����һ��������������ʱ��: " << ((end - start) * 1.0 / 1000) << endl;
}

/*
======================================
����һ��list����, ��Ԫ��������int��deque
======================================
*/
void Chapter_nine::p_9p2_9p2()
{
	list<deque<int>> list;
	list = { {1,2,3,4,5}, {6,7,8,9,10} };
}

/*
======================================
��д����, ����һ��ָ��vector<int>�ĵ�������һ��intֵ, ������
������ָ����Χ�ڲ��Ҹ�����ֵ, ����һ������ֵ��ָ���Ƿ��ҵ�

����:

>> beg:		ָ��vector�ĵ�����
>> last:	ָ��vector�ĵ�����
>> i:		Ҫ�ҵ�Ԫ��
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
��д����, ����һ��ָ��vector<int>�ĵ�������һ��intֵ, ������
������ָ����Χ�ڲ��Ҹ�����ֵ, ����һ������ֵ��ָ���Ƿ��ҵ�

����:

>> beg:		ָ��vector�ĵ�����
>> last:	ָ��vector�ĵ�����
>> i:		Ҫ�ҵ�Ԫ��
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
����vector��6�г�ʼ����ʽ
======================================
*/
void Chapter_nine::p_9p2p4_p9p11()
{
	// 10 ��Ԫ��, ����0
	vector<int> vec(10);
	// 10 ��Ԫ��, ����2
	vector<int> vec2(10, 2);
	// 10 ��Ԫ��
	vector<int> vec3 = { 1,2,3,4,5,6,7,8,9,10 };
	// ������ʼ��
	vector<int> vec4(vec);
	// ������ʼ��(��Χ)
	vector<int> vec5(vec.begin(), vec.end() - 1);
	// ������ʼ��
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
����assign��ʹ�÷�ʽ
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
����swap��ʹ�÷�ʽ
======================================
*/
void Chapter_nine::swapTest()
{
	vector<int> vec(10, 2);
	vector<int> vec2(10, 3);

	// ֻ�ǽ������ڲ������ݽṹ, ����δ��Ԫ�ر�������������
	swap(vec, vec2);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;
}

/*
======================================
��vector�в���Ԫ��(����β���ͻ�ܺ�ʱ)
======================================
*/
void Chapter_nine::insertTest()
{
	// ����ͷ��(��ܺ�ʱ)
	vector<int> vec = {1,2,3,4,5};
	vec.insert(vec.begin(), 0);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;

	// ������Ԫ�ص�β��
	vec.insert(vec.end(), 10, 5);
	for (int i : vec)
		cout << i << "\t";
	cout << endl;
	
	// ����insert��������ָ��������֮ǰ����һ����Ԫ��, ������֮��
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
��list�е�char *ָ��Ԫ�ظ�ֵ��һ��vector�е�string
======================================
*/
void Chapter_nine::p_9p2p5_p9p14()
{
	list<char *> cStrList(10, "a");
	// ����ֱ�����������Զ�ת��
	vector<string> strVec(cStrList.cbegin(), cStrList.cend());

	for (string s : strVec)
		cout << s << "\t";
	cout << endl;
}

/*
======================================
�ж�����vector<int>�Ƿ����
======================================
*/
void Chapter_nine::p_9p2p7_p9p15()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {1,2,3};

	bool a = (v1 == v2);
	cout << (a ? "���" : "�����") << endl;
}

/*
======================================
�Ƚ�list<int> �е�Ԫ�غ� vector<int> �е�Ԫ��
======================================
*/
void Chapter_nine::p_9p2p7_p9p16()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = {1,2,3};

	bool a = (v1[0] == v2[0]);
	cout << (a ? "���" : "�����") << endl;
}

/*
======================================
��д����, �ӱ�׼�����ȡstring����, 
����һ��deque��, ��дһ��ѭ��,�õ�������ӡdeque�е�Ԫ��
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
������һ��ĳ���, ʹ��list���deque, ָ������
Ҫ����Щ�ı�
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
��д����, ��һ��list����������deque��, ֵΪż����
������һ��deque��, ֵΪ�����Ŀ�������һ��deque��
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
ʹ��front��back��Ա��ȡԪ��
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
����б���ֻ��һ��ֵ, ��front back �ȳ�Ա������ֵ�Ƕ���
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
�ֱ�ʹ��at, �±������, front��begin��ȡvector�е�
��һ��Ԫ��
======================================
*/
void Chapter_nine::p_9p3p2_p9p24()
{
	vector<int> iv;
	// ʹ���±������
	cout << iv[0] << endl;
	// ʹ��at�����, �׳� out_of_range �쳣
	cout << iv.at(0) << endl;
	// ʹ��front
	cout << iv.front() << endl;
	// ʹ��begin
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
ʹ��������붨���ia, ��ia������vector��һ��list��, ʹ��
���������汾��erase��list��ɾ������Ԫ��, ��vector��ɾ��ż��Ԫ��
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
ʹ��forward_listɾ������Ԫ��
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
��д����, ����һ��forward_list<string>, ����string
����Ӧ�ڵ�һ�������в��ҵ�һ��string, �����ڶ���string
���뵽��һ��string��, ���û�ҵ�, �ŵ�ĩβ

params:
>> lst: ��Ҫ�������б�
>> s1:  ����string
>> s2:  ����string
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
��vectorʹ�õ�����������Ӻ�ɾ��
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
ʹ��list��forward_list���и���ֵ
======================================
*/
void Chapter_nine::p_9p3p6_p9p31()
{
	// ʹ��list
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

	// ʹ��forward_list
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
����ѭ��
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
ʹ��capacity��shrink_to_fit������vector��չ����
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
����һ��vector��capacity��size������
======================================
*/
void Chapter_nine::p_9p4_p9p35()
{
	/*
	vector��capacity���Ի�ȡ�ٲ���չ�ڴ������»��ܴ����Ԫ��, size���ǻ�ȡ�Ѿ��洢�˶��ٸ�Ԫ��
	*/
}

/*
======================================
һ��������capacity��С��sizeô
======================================
*/
void Chapter_nine::p_9p4_p9p36()
{
	// ����
}

/*
======================================
Ϊʲôlist��arrayû��capacity��Ա����?
======================================
*/
void Chapter_nine::p_9p4_p9p37()
{
	// ��Ϊlist���ṩ�������, ���Դ洢˳������
	// array��֧�ִ洢��չ
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
stackʹ��deque������
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