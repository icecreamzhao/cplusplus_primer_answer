#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Chapter_6.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::begin;
using std::end;

/********
 * 阶乘 *
 *******/
int Chapter_six::fact(int &num)
{
	int baseI = 1;
	while (num > 1)
		baseI *= num--;
	return baseI;
}

/***************
 * 调用阶乘函数 *
 **************/
void Chapter_six::p_6p1_6p3()
{
	int i = 5;
	cout << fact(i) << endl;
}

/****************************
 * 使用用户输入的数字生成阶乘 *
 ***************************/
void Chapter_six::p_6p1_6p4()
{
	int input;
	cin >> input;
	cout << fact(input) << endl;
}

/******************
 * 输出实参的绝对值 *
 *****************/
void Chapter_six::p_6p1_6p5(const int &i)
{
	cout << abs(i) << endl;
}

/******************************************
 * 编写一个函数, 当它每次被调用时, 返回值加一 *
 *****************************************/
int &Chapter_six::p_6p1p1_6p7()
{
	static int returnNum = 0;
	return ++returnNum;
}

/*****************************
 * 使用指针形参交换两个整数的值 *
 ****************************/
void Chapter_six::p_6p2p1_6p10(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/**************************
 * 将上面的练习改成引用形参 *
 *************************/
void Chapter_six::p_6p2p1_6p12(int &i, int &j)
{
	int tmp = i;
	i = j;
	j = tmp;
}

/**************************
 * 判断参数是否包含大写字母 *
 *************************/
void Chapter_six::p_6p2p3_6p17_1(const string &input)
{
	for (auto beg = begin(input); beg != end(input); ++beg)
	{
		if (isupper(*beg))
		{
			cout << "have upper!" << endl;
			break;
		}
	}
}

/******************
 * 将字符串改成小写 *
 *****************/
void Chapter_six::p_6p2p3_6p17_2(string &input)
{
	for (auto beg = begin(input); beg != end(input); ++beg)
	{
		if (isupper(*beg))
		{
			*beg = tolower(*beg);
		}
		cout << *beg;
	}
	cout << endl;
}

/******************
 * 调用上面两个函数 *
 *****************/
void Chapter_six::p_6p2p3_6p17()
{
	string s = "Input";
	p_6p2p3_6p17_1(s);
	p_6p2p3_6p17_2(s);
}

/******************
 * 判断传入参数大小 *
 *****************/
bool Chapter_six::p_6p2p3_6p18_compare(const int &i, const int &j)
{
	return i > j;
}

/*******************************
 * 将传入参数添加进vector中并返回 *
 ******************************/
vector<int> &Chapter_six::p_6p2p3_6p18_change_val(const int &val, vector<int> &vec)
{
	vec.push_back(val);
	return vec;
}

/******************
 * 调用上面两个函数 *
 *****************/
void Chapter_six::p_6p2p3_6p18()
{
	int i = 1, j = 2;
	cout << p_6p2p3_6p18_compare(i, j) << endl;

	vector<int> vec;
	p_6p2p3_6p18_change_val(i, vec);

	for (auto be = vec.begin(); be != vec.end(); ++be)
	{
		cout << *be << "\t";
	}
	cout << endl;
}

/******************************************************************
 * 令函数接收两个参数, 一个是int指针, 一个是int值, 函数比较指针所指的值 *
 * 和int的值, 返回较大的那个。										  *
 *****************************************************************/
int Chapter_six::p_6p2p4_6p21(const int *i, int j)
{
	return *i > j ? *i : j;
}

/*******************************
 * 交换两个指针				   *
 * 形参类型要声明成指向指针的引用 *
 ******************************/
void Chapter_six::p_6p2p4_6p22(int *&i, int *&j)
{
	int *tmp = &(*i);
	i = &(*j);
	j = &(*tmp);
}

/****************************
 * 输出一个int值和一个int数组 *
 ***************************/
void Chapter_six::p_6p2p4_6p23(int i, int *beg, int *en)
{
	cout << i << endl;
	while (beg != en)
		cout << *beg++;
	cout << endl;
}

/*********************************
 * 计算initializer_list中元素的和 *
 ********************************/
void Chapter_six::p_6p2p6_6p27(initializer_list<int>(&int_list))
{
	int result = 0;
	for (const int &i : int_list)
		result += i;
	cout << result << endl;
}

/*********************
 * 使用递归打印vector *
 ********************/
vector<int>::iterator Chapter_six::p_6p3p2_6p33(vector<int>(&vec), vector<int>::iterator iter)
{
	if (iter != vec.end())
	{
		cout << *iter++;
		return p_6p3p2_6p33(vec, iter);
	}
	return vec.end();
}

/****************************************************************
 * 编写一个函数的声明, 使其返回数组的引用并且该数组包含10个string对象 *
 ***************************************************************/
string(&Chapter_six::p_6p3p3_6p36(string(&arr)[10]))[10]
{
	return arr;
}

/*******************
 * 使用类型别名声明 *
 ******************/
	arrP &Chapter_six::p_6p3p3_6p37_typedef(arrP &arr)
{
	return arr;
}

/*********************
 * 使用递归打印vector *
 ********************/
vector<int>::iterator Chapter_six::p_6p5p3_6p47(vector<int>(&vec), vector<int>::iterator iter)
{
	#ifndef NODEBUG
	cout << "vector size is " << vec.size() << endl;
	#endif
	if (iter != vec.end())
	{
		cout << *iter++;
		return p_6p3p2_6p33(vec, iter);
	}
	return vec.end();
}

/**
 * 接收两个int形参, 返回值也是int
 */
int Chapter_six::p_6p7_6p54_1(int i, int j)
{
	int result = i > j ? 1 : 0;
	return result;
}

/**
 * 声明一个vector对象 令其元素是指向上一个函数的指针
 */
void Chapter_six::p_6p7_6p54()
{
	vector<int(Chapter_six:: *)(int, int)> vec;
	int (Chapter_six:: * pf1)(int, int) = &Chapter_six::p_6p7_6p54_1;;
	vec.push_back(pf1);
}

int Chapter_six::p_6p7_6p55_1(int i, int j)
{
	return i + j;
}

int Chapter_six::p_6p7_6p55_2(int i, int j)
{
	return i - j;
}

int Chapter_six::p_6p7_6p55_3(int i, int j)
{
	return i * j;
}

int Chapter_six::p_6p7_6p55_4(int i, int j)
{
	return i / j;
}

void Chapter_six::p_6p7_6p55()
{
	vector<int(Chapter_six:: *)(int, int)> vec;
	vec.push_back(&Chapter_six::p_6p7_6p55_1);
	vec.push_back(&Chapter_six::p_6p7_6p55_2);
	vec.push_back(&Chapter_six::p_6p7_6p55_3);
	vec.push_back(&Chapter_six::p_6p7_6p55_4);

	for (auto be : vec)
	{
		Chapter_six six;
		cout << (six.*be)(1, 2) << endl;
	}
}

void Chapter_six::runAll()
{
	//p_6p1_6p3();
	//p_6p1_6p4();
	//int i = -2;
	//p_6p1_6p5(i);

	/*for (int i = 0; i != 10; ++i)
		cout << p_6p1p1_6p7() << endl;*/

	int i = 5;
	int j = 1;
	/*p_6p2p1_5p10(&i, &j);
	cout << i << "\t" << j << endl;*/

	/*p_6p2p1_5p12(i, j);
	cout << i << "\t" << j << endl;*/

	//p_6p2p3_6p17();
	//p_6p2p3_6p18();

	int *ip = &i;
	//cout << p_6p2p4_6p21(ip, j) << endl;

	int *jp = &j;
	//p_6p2p4_6p22(ip, jp);
	//cout << *jp << "\t" << * ip << endl;

	int ia[] = { 1,2,3,4,5,6,7,8,9,10 };
	//p_6p2p4_6p23(i, begin(ia), end(ia));

	initializer_list<int> lst = { 1,2,3,4,5 };
	//p_6p2p6_6p27(lst);

	vector<int> vec = { 1,2,3,4,5 };
	//p_6p3p2_6p33(vec, vec.begin());

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//for (int &i : p_6p3p3_6p36(arr))
		//cout << i << "\t";
	//cout << endl;

	string arr_str[10] = { "a", "b", "c" };
	//for (int &i : p_6p3p3_6p37_typedef(arr))
		//cout << i << "\t";

	//p_6p5p3_6p47(vec, vec.begin());
	//p_6p7_6p54();
	p_6p7_6p55();
}