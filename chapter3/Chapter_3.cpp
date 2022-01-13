#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
#include <cstring>
#include "Chapter_3.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::strcmp;
using std::strcat;
using std::strcpy;
using std::strlen;

/*************************
* 编写程序, 一次读取一整行 *
* 编写程序, 一次读取一个词 *
*************************/
void Chapter_three::p_3p2p2_3p2()
{
	string line;
	if (getline(cin, line))
	{
		cout << line << endl;
	}

	if (cin >> line)
	{
		cout << line << endl;
	}
}

/***************************************************************
* 输入两个字符串, 比较长度是否相等, 如果相等, 则输出长度较大的字符串 *
***************************************************************/
void Chapter_three::p_3p2p2_3p4()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() == s2.size())
	{
		cout << s1 << endl;
	}
	else
	{
		cout << (s1.size() > s2.size() ? s1 : s2) << endl;
	}
}

/************************************************
* 从输入中读取一组字符串, 并合并成一个大的字符串;	*
* 从输入中读取一组字符串, 合并成字符串并使用空格分割 *
************************************************/
void Chapter_three::p_3p2p2_3p5()
{
	string s1, s2 = "";
	while (cin >> s1)
	{
		s2 += s1;
		cout << "continue? enter y or n:" << endl;
		char answer;
		cin >> answer;
		if (answer == 'n')
			break;
	}
	cout << s2 << endl;

	s2 = "";
	while (cin >> s1)
	{
		s2 += (s1 + " ");
		cout << "continue? enter y or n:" << endl;
		char answer;
		cin >> answer;
		if (answer == 'n')
			break;
	}
	cout << s2 << endl;
}

/***********************
* 计算字符串中的标点符号 *
***********************/
void Chapter_three::countPunct()
{
	string s = "hello, world!!!";

	int punctCount = 0;
	for (auto c : s)
	{
		if (ispunct(c))
		{
			++punctCount;
		}
	}
	cout << punctCount << " punctuation characters in \"" << s << "\"" << endl;
}

/******************
* 将字符串改为大写 *
******************/
void Chapter_three::myToUpperCase()
{
	string s = "hello, World";
	for (auto& c : s)
	{
		c = toupper(c);
	}
	cout << s << endl;
}

/*******************
* 使用下标访问字符串 *
*******************/
void Chapter_three::useIndex()
{
	string s = "hello, world";
	if (!s.empty())
	{
		for (decltype(s.size()) index = 0; !isspace(s[index]) && index != s.size(); ++index)
		{
			cout << s[index];
		}
		cout << endl;
	}
}

/**************************
* 将输入的数字转换成十六进制 *
**************************/
void Chapter_three::toHex()
{
	const string hexString = "123456789ABCDEF";
	int input;
	if (cin >> input)
	{
		if (input < hexString.size())
		{
			cout << "your hex number is " << hexString[input - 1] << endl;
		}
	}
}

/***************************************
* 使用范围for语句将字符串所有字符使用X代替 *
***************************************/
void Chapter_three::p_3p2p3_3p6()
{
	string s = "hello, world";
	for (auto &c : s)
	{
		c = 'x';
	}
	cout << s << endl;
}

/*********************************
* 使用传统for和while修改上面的练习 *
*********************************/
void Chapter_three::p_3p2p3_3p8()
{
	// while
	string s = "hello, world";
	decltype(s.size()) index = 0;
	while (index != s.size())
	{
		auto& c = s[index];
		++index;
		c = 'x';
	}
	cout << s << endl;

	// tranditial for
	s = "hello, world";
	for (decltype(s.size()) index = 0; index != s.size(); ++index)
	{
		auto& c = s[index];
		c = 'x';
	}
	cout << s << endl;
	// foreach > for > while
}

/*****************************
* 读取一组整数, 并添加进vector *
*****************************/
void Chapter_three::p_3p2p2_3p14()
{
	vector<int> inputs;
	int input = 0;
	while (cin >> input)
	{
		inputs.push_back(input);
	}

	cout << inputs.size() << endl;
}

/************************
* 将上面的练习改成string *
************************/
void Chapter_three::p_3p2p2_3p15()
{
	vector<string> inputs;
	string s = "";
	while (cin >> s)
	{
		inputs.push_back(s);
	}
	cout << inputs.size() << endl;
}

/********************
* 使用索引操作vector *
********************/
void Chapter_three::vectorIndex()
{
	vector<int> results(11, 0);
	unsigned int item = 0;
	while (cin >> item)
	{
		++results[item < 10 ? 0 : (item == 100 ? 10 : item / 10)];
	}

	for (auto i : results)
	{
		cout << i << " ";
	}
	cout << endl;
}

/***********************************************************
* 从cin读入一组词存入vector, 然后改为大写, 最后输出, 每词占一行 *
***********************************************************/
void Chapter_three::p_3p2p3_3p17()
{
	vector<string> strings;
	string input;
	while (cin >> input)
	{
		strings.push_back(input);
	}

	for (auto& item : strings)
	{
		for (auto& c : item)
		{
			c = toupper(c);
		}
	}

	for (string item : strings)
	{
		cout << item << endl;
	}
}

/*********************************************
* 使用三种方式初始化有10个int值的vector, 值为42 *
*********************************************/
void Chapter_three::p_3p2p3_3p19()
{
	vector<int> v1(10, 42);
	vector<int> v2 = { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> v3{ 10, 42 };
}

/*************************************************
* 输入一组整数, 存入vector中, 将每对相邻整数的和输出 *
* 将第一个和最后一个整数的和输出, 以此类推			 *
*************************************************/
void Chapter_three::p_3p2p3_3p20()
{
	vector<int> result;
	int input;
	while (cin >> input)
	{
		result.push_back(input);
	}

	if (result.size() > 1)
	{
		// 将每对相邻整数的和输出
		for (unsigned i = 0; i < (result.size() % 2 == 0 ? result.size() : result.size() - 1); i += 2)
		{
			cout << result[i] + result[i + 1] << endl;
		}
		// 将第一个和最后一个整数的和输出
		for (unsigned i = 0; i < (result.size() % 2 != 0 ? (result.size() - 1) / 2 : result.size() / 2); ++i)
		{
			//cout << i << endl;
			cout << result[i] + result[result.size() - 1 - i] << endl;
		}
	}
}

/***********************
* 使用迭代器来操作字符串 *
***********************/
void Chapter_three::useVectorIterator()
{
	// 更改字符串首字母为大写
	string s("some thing");
	if (s.begin() != s.end())
	{
		auto first = s.begin();
		*first = toupper(*first);
	}
	cout << s << endl;

	// 更改字符串大写
	s = "some thing";
	for (auto i = s.begin(); i != s.end() && !isspace(*i); ++i)
		*i = toupper(*i);
	cout << s << endl;

	// 使用箭头运算符
	vector<string> v1;
	v1.push_back("string1");
	v1.push_back("string2");
	for (auto i = v1.cbegin(); i != v1.cend() && !(i->empty()); ++i)
		cout << *i << endl;
}

/***********************
* 修改字符串第一段为大写 *
***********************/
void Chapter_three::p_3p4p1_3p22()
{
	string text = "some thing";
	bool haveSpace = false;
	for (auto it = text.begin(); it != text.end(); ++it)
	{
		if (!isspace(*it) && !haveSpace)
			*it = toupper(*it);
		else
			haveSpace = true;
		cout << *it;
	}
	cout << endl;
}

/********************************************************
* 创建含有10个元素的vector对象, 使用迭代器将原来的值变为两倍 *
********************************************************/
void Chapter_three::p_3p4p1_3p23()
{
	vector<int> v1(10, 2);
	for (auto it = v1.begin(); it != v1.end(); ++it)
	{
		*it = *it << 1;
		cout << *it << "\t";
	}
	cout << endl;
}

/*************************
* 使用迭代器实现二分搜索法 *
*************************/
void Chapter_three::search()
{
	// 要搜索的数据
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	int target = 9;
	int target2 = 2;

	// 中间值
	auto mid = v1.begin() + v1.size() / 2;

	// 从中间判断, 如果要找的值大于中间值, 则往后查找, 否则往前查找
	for (decltype(v1.size()) i = 0; i != v1.size() / 2; ++i)
	{
		if (*mid > target2)
		{
			--mid;
		}
		else if (*mid < target2)
		{
			++mid;
		}
		else
		{
			cout << target2 << endl;
			break;
		}
	}

	auto begin = v1.begin();
	auto end = v1.end();
	mid = begin + v1.size() / 2;
	while (mid != end && *mid != target)
	{
		if (*mid > target)
			end = mid;
		else
			begin = mid;
		mid = begin + (end - begin) / 2;
	}
	cout << *mid << endl;
}

/********************************
* practiceThreeOTwenty迭代器版本 *
********************************/
void Chapter_three::p_3p4p2_3p24()
{
	// 输出相邻的数的和
	vector<int> target;
	int input;
	while (cin >> input)
	{
		target.push_back(input);
	}

	auto it = target.begin();
	while (it != (target.size() % 2 == 0 ? target.end() : target.end() - 1))
	{
		cout << *it + *(it + 1) << endl;
		it += 2;
	}

	// 输出最后一个和第一个的和, 以此类推
	auto begin = target.begin();
	auto end = target.end() - 1;
	while (begin < end)
	{
		cout << ((*begin) + (*end)) << endl;
		++begin;
		--end;
	}
}

/***********************
* 使用下标实现划分分数段 *
***********************/
void Chapter_three::p_3p4p2_3p25()
{
	vector<int> score(11, 0);
	int input;
	auto begin = score.begin();
	while (cin >> input)
	{
		if (input < 10)
			begin = score.begin();
		else if (input < 100)
			begin += input / 10;
		else
			begin = score.end() - 1;
		++(*begin);
		begin = score.begin();
	}
	for (int i : score)
	{
		cout << i << "\t";
	}
	cout << endl;
}

/*************************************
* 定义一个数组, 令每个元素的值就是其下标 *
*************************************/
int* Chapter_three::p_3p5p2_3p31()
{
	constexpr size_t array_size = 10;
	int *iarray = new int[array_size];
	for (int i = 0; i != array_size; ++i)
	{
		iarray[i] = i;
		cout << iarray[i] << "\t";
	}
	cout << endl;
	return iarray;
}

/*************************************************
* 将上一题的数组复制到另一个数组中, 并使用vector重写 *
*************************************************/
void Chapter_three::p_3p5p2_3p32()
{
	constexpr size_t array_size = 10;
	int* p = p_3p5p2_3p31();
	int iarray[array_size];

	for (int i = 0; i != array_size; ++i)
	{
		iarray[i] = *(p + i);
		cout << iarray[i] << "\t";
	}
	cout << endl;

	// 使用vector实现相同的功能
	vector<int> result;
	for (int i = 0; i != array_size; ++i)
	{
		result.push_back(*(p + i));
	}
	for (auto i : result)
	{
		cout << i << "\t";
	}
	cout << endl;
}

/***************************
* 利用指针将数组中的元素置为0 *
***************************/
void Chapter_three::p_3p5p3_3p35()
{
	int ia[] = { 1,2,3,4,5 };
	int* be = begin(ia);
	int* en = end(ia);
	while (be != en)
	{
		*be = 0;
		++be;
	}
	for (auto i : ia)
	{
		cout << i << "\t";
	}
	cout << endl;
}

/*************************
* 比较数组和vector是否相同 *
*************************/
void Chapter_three::p_3p5p3_3p36()
{
	int ia[] = { 1,2,3,4,5 };
	int ia2[] = { 1,2,3,4,5 };
	int ia3[] = { 2,3,4,5,6 };

	int* pia = ia;
	int* pia2 = ia3;
	while (pia != end(ia))
	{
		if (*pia == *pia2) {
			++pia;
			++pia2;
		}
		else
		{
			cout << "不一致" << endl;
			pia = end(ia);
		}
	}

	vector<int> v1(10, 1);
	vector<int> v2(10, 1);
	vector<int> v3(10, 2);

	auto v1Begin = v1.cbegin();
	auto v2Begin = v3.cbegin();
	while (v1Begin != v1.cend())
	{
		if (*v1Begin == *v2Begin)
		{
			++v1Begin;
			++v2Begin;
		}
		else
		{
			cout << "不一致" << endl;
			v1Begin = v1.cend();
		}
	}
}

/*****************************
* 比较C风格字符串和标准库字符串 *
*****************************/
void Chapter_three::p_3p5p4_3p39()
{
	string s1 = "abc";
	string s2 = "def";

	if (s1 == s2)
	{
		cout << "s1 equals s2" << endl;
	}
	else
	{
		cout << "s1 " << (s1 > s2 ? "大于" : "小于") << " s2" << endl;
	}

	char ca1[] = "abc";
	char ca2[] = { 'd' , 'e', 'f', '\0'};
	if (strcmp(ca1, ca2) == 0)
	{
		cout << "s1 equals s2" << endl;
	}
	else
	{
		cout << "s1 " << (strcmp(ca1, ca2) > 0 ? "大于" : "小于") << " s2" << endl;
	}
}

/****************************************************
* 使用strcpy和strcat把前两个数组的内容拷贝到第三个数组中 *
*****************************************************/
void Chapter_three::p_3p5p4_3p40()
{
	// 这里一定要指定ca1的长度, 要不然strcat之后ca1就不够用了
	char ca1[8] = { 'a', 'b', 'c', '\0' };
	char ca2[4] = { 'd', 'e', 'f', '\0' };
	char ca3[12];
	strcat(ca1, ca2);
	strcpy(ca3, ca1);
	const char *p = ca3;
	while (*p)
	{
		cout << *p << "\t";
		++p;
	}
	cout << endl;
}

/***************
* C风格代码混用 *
***************/
void Chapter_three::cCodeTest()
{
	// 允许使用以空字符结尾的字符数组初始化字符串
	char ca1[] = {'c', '+', '+', '\0'};
	string s = ca1;
	// 在string的加法运算中允许将字符数组作为其中的运算对象(但不能都是)
	string s2 = s + " and " + ca1;
	// 复合赋值运算中, 允许使用字符数组作为右侧的运算对象
	s2 += ca1;
	cout << s2 << endl;

	// 使用c_str函数初始化字符数组
	const char* cp = s2.c_str();
	while (*cp)
	{
		cout << *cp;
		++cp;
	}
	cout << endl;
}

/***********************
* 用整型数组初始化vector *
***********************/
void Chapter_three::p_3p5p5_3p41()
{
	int int_arr[] = { 1,2,3,4,5 };
	vector<int> vec_int(int_arr + 1, int_arr + 4); // 2, 3, 4
	for (auto p = vec_int.cbegin(); p != vec_int.cend(); ++p)
	{
		cout << *p << endl;
	}
}

/*************************
* vector拷贝数据给整型数组 *
*************************/
void Chapter_three::p_3p5p5_3p42()
{
	vector<int> vec_int(10, 2);
	int int_arr[10];
	int* be = &int_arr[0];
	for (auto p = vec_int.cbegin(); p != vec_int.cend(); ++p)
	{
		*be = *p;
		++be;
	}
	int *be2 = &int_arr[0];
	while (be2 != end(int_arr))
	{
		cout << *be2 << endl;
		++be2;
	}
}

/**************
* 多维数组遍历 *
**************/
void Chapter_three::multiArray()
{
	int arr[2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
	};

	// 这里不能这么写
	/*for (auto i : arr)
	{
		for (auto j : i)
		{
			cout << j << endl;
		}
	}*/
	for (auto& i : arr)
	{
		for (auto& j : i)
		{
			cout << j << endl;
		}
	}
}

/************
* 数组和指针 *
************/
void Chapter_three::multiArrayAndPoint()
{
	int arr[3][4] = {};
	// 声明一个指向含有四个整型数组的指针
	int(*p)[4] = arr;
	p = &arr[2];
	cout << (*p)[0] << endl;

	// 声明一个含有四个整型指针的数组
	int itemp = 0;
	int* pa[4] = {&itemp, &itemp, &itemp, &itemp };
	cout << *(pa[0]) << endl;

	// 使用指针循环数组
	for (auto i = arr; i != arr + 3; ++i)
	{
		for (auto j = *i; j != *i + 4; ++j)
		{
			cout << *j << "\t";
		}
	}
	cout << endl;

	// 使用指针循环数组(使用begin和end)
	for (auto i = arr; i != end(arr); ++i)
	{
		for (auto j = *i; j != end(*i); ++j)
		{
			cout << *j << "\t";
		}
	}
	cout << endl;
}

void Chapter_three::p_3p5p6_3p43()
{
	constexpr size_t one_size = 3;
	constexpr size_t two_size = 4;
	int ia[one_size][two_size] = {};
	// 使用范围for来遍历数组
	for (int(&i)[two_size] : ia)
		for (int& j : i)
			cout << j << "\t";

	cout << endl;
	// 使用普通for和下标来遍历数组
	for (size_t i = 0; i != one_size; ++i)
	{
		for (size_t j = 0; j != two_size; ++j)
		{
			cout << ia[i][j] << "\t";
		}
	}
	cout << endl;

	// 使用普通for和指针
	for (int (*i)[two_size] = ia; i != end(ia); ++i)
		for (int *j = *i; j != end(*i); ++j)
			cout << *j << "\t";
	cout << endl;
}

// 使用类型别名简化
using int_array = int(&)[4];

/**************
* 运行所有练习 *
**************/
void Chapter_three::runAll()
{
	/*p_3p2p2_3p2();
	p_3p2p2_3p4();
	p_3p2p2_3p5();
	countPunct();
	myToUpperCase();
	useIndex();
	toHex();
	p_3p2p3_3p6();
	p_3p2p3_3p8();
	p_3p2p2_3p14();
	vectorIndex();
	p_3p2p3_3p17();
	p_3p2p3_3p19();
	p_3p2p3_3p20();
	useVectorIterator();
	p_3p4p1_3p22();
	p_3p4p1_3p23();
	search();
	p_3p4p2_3p24();
	p_3p4p2_3p25();
	p_3p5p2_3p31();
	p_3p5p2_3p32();
	p_3p5p3_3p35();
	p_3p5p3_3p36();
	p_3p5p4_3p39();
	p_3p5p4_3p40();
	cCodeTest();
	p_3p5p5_3p41();
	p_3p5p5_3p42();
	multiArray();
	multiArrayAndPoint();*/
	p_3p5p6_3p43();
}