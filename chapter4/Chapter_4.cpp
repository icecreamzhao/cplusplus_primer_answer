#include <iostream>
#include <vector>
#include "Chapter_4.h"
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::begin;

/*******
* 求值 *
*******/
void Chapter_four::p_4p1p2_4p1()
{
	int i = 5 + 10 * 20 / 2; // result is 105
	cout << "result is " << i << endl;
}

/**********
* 判断类型 *
**********/
void Chapter_four::p_4p1p2_4p2()
{
	vector<int> vec = { 0 };
	// vec 类型是存放int的vector, vec.begin()类型是iterator, 所以要对此解引用
	// *(vec.begin()) 等价于 *vec.begin()
	cout << *vec.begin() << endl;

	// *vec.begin() + 1
	cout << (*(vec.begin())) + 1 << endl;
}

/**********************************
* 从标准输入中读取整数, 遇到42时停止 *
**********************************/
void Chapter_four::p_4p3_4p10()
{
	int i = 0;
	while (cin >> i)
		if (i == 42)
			break;
}

/******************************
* 书写一条表达式连判断abcd的关系 *
******************************/
void Chapter_four::p_4p3_4p11()
{
	int a = 0, b = 0, c = 0, d = 0;
	bool result = a > b > c > d;
	cout << "a > b > c > d is " << result << endl;
	a = 4, b = 3, c = 2, d = 1;
	result = a > b > c > d;
	cout << "a > b > c > d is " << result << endl;
}

/**********************************
* 使用条件运算符将vector中的奇数翻倍 *
**********************************/
void Chapter_four::p_4p7_4p21()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	auto be = vec.begin();
	while (be != vec.end())
	{
		*be = *be % 2 != 0 ? (*be) * 2 : *be;
		cout << *be++ << endl;
	}
}

/***********************************************************
* 使用条件运算符判断四种成绩(high pass, low pass, pass, fail) *
***********************************************************/
void Chapter_four::p_4p7_4p22()
{
	int score = 0;
	while (cin >> score)
	{
		// 条件运算符版本
		string result = score > 90 ? "high pass" : (score > 75 ? "low pass" : (score > 60 ? "pass" : "fail"));
		cout << "result is " << result << endl;
		// if 语句版本
		if (score > 90)
			result = "high pass";
		else if (score > 75)
			result = "low pass";
		else if (score > 60)
			result = "pass";
		else
			result = "fail";
		cout << "result is " << result << endl;

	}
}

/*********************
* 计算下列表达式的结果 *
*********************/
void Chapter_four::p_4p8_4p27()
{
	unsigned long iu1 = 3, iu2 = 7; // iu is 11, iu2 is 1001
	cout << (iu1 & iu2) << endl; // result is "1001"
	cout << (iu1 | iu2) << endl; // result is "11"
	cout << (iu1 && iu2) << endl; // result is "1"
	cout << (iu1 || iu2) << endl; // result is "1"
}

/***********************
* 输出每种内置类型的大小 *
***********************/
void Chapter_four::p_4p9_4p28()
{
	cout << sizeof(char) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(float) << endl;
}

/*******************
* 计算下列表达式结果 *
*******************/
void Chapter_four::p_4p9_4p29()
{
	int a[10] = {};
	int *p = a;
	cout << sizeof(a) << endl;
	cout << sizeof(*a) << endl;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;
	cout << sizeof(a) / sizeof(*a) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
}

/******************
 * 使用后置版本重写 *
 *****************/
void Chapter_four::p_4p10_4p31()
{
	// 原版
	vector<int> ivec(10, 2);
	vector<int>::size_type size = ivec.size();
	for (vector<int>::iterator i = ivec.begin(); i != ivec.end(); ++i, --size)
	{
		*i = static_cast<int>(size);
		cout << *i << "\t";
	}
	cout << endl;

	// 后置版本
	vector<int> ivec2(10, 2);
	vector<int>::size_type size2 = ivec2.size();
	for (vector<int>::iterator i = ivec2.begin(); i != ivec2.end(); i++, size2--)
	{
		*i = static_cast<int>(size2);
		cout << *i << "\t";
	}
	cout << endl;
}

/*******************************
 * 将表达式修改为非浮点类型的乘法 *
 ******************************/
void Chapter_four::p_4p11p3_3p36()
{
	int i = 5;
	double d = 2.1;
	i = i * static_cast<int>(d);
	cout << i << endl;
}

/***************
 * 类型互相转换 *
 **************/
void Chapter_four::p_4p11p3_3p37()
{
	int i = 0;
	double d = 0.0;
	string s = "";
	const string *ps = &s;
	char c = 'a';
	char *pc = &c;
	void *pv = &i;

	pv = static_cast<void *>(const_cast<string *>(ps));
	i = static_cast<int>(*pc);
	pv = &d;
	pc = static_cast<char *>(pv);
}

void Chapter_four::runAll()
{
	/*p_4p1p2_4p1();
	p_4p1p2_4p2();
	p_4p3_4p10();
	p_4p3_4p11();
	p_4p7_4p21();
	p_4p7_4p22();
	p_4p8_4p27();
	p_4p9_4p28();
	p_4p9_4p29();
	p_4p10_4p31();
	p_4p11p3_3p36();*/
	p_4p11p3_3p37();
}