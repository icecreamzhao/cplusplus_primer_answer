#include "Chapter_5.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::vector;
using std::runtime_error;

/*****************************************
 * 使用if else 语句将数字成绩转换成字母成绩 *
 ****************************************/
void Chapter_five::p_5p3p1_5p5()
{
	const char score[] = { 'F', 'D', 'C', 'B', 'A' };
	int scoreInput = 0;
	string result;
	while (cin >> scoreInput)
	{
		if (scoreInput < 60)
		{
			result = score[0];
		}
		else
		{
			result = score[(scoreInput - 50) / 10];
			if (scoreInput % 10 > 7)
				result = result + "++";
			else if (scoreInput % 10 < 3)
				result = result + "--";
		}
		cout << result << endl;
	}
}

/*****************
 * 条件运算符版本 *
 ****************/
void Chapter_five::p_5p3p1_5p6()
{
	const char score[] = { 'F', 'D', 'C', 'B', 'A' };
	int scoreInput = 0;
	string result;
	while (cin >> scoreInput)
	{
		result = scoreInput < 60 ? score[0] : score[(scoreInput - 50) / 10];
		result += scoreInput < 60 ? "" : scoreInput % 10 > 7 ? "++" : scoreInput % 10 < 3 ? "--" : "";
		cout << result << endl;
	}
}

/*********************************************
 * 统计读入的文本中有多少元音字母(大小写包含在内) *
 ********************************************/
void Chapter_five::p_5p3p2_5p9()
{
	string input = "";
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	while (getline(cin, input))
	{
		auto beginStr = input.begin();
		while (beginStr != input.end())
		{
			if (tolower(*beginStr) == 'a')
				++aCnt;
			else if (tolower(*beginStr) == 'e')
				++eCnt;
			else if (tolower(*beginStr) == 'i')
				++iCnt;
			else if (tolower(*beginStr) == 'o')
				++oCnt;
			else if (tolower(*beginStr) == 'u')
				++uCnt;
			++beginStr;
		}
		cout << "number of vowel a: \t" << aCnt << '\n'
			<< "number of vowel e: \t" << eCnt << '\n'
			<< "number of vowel i: \t" << iCnt << '\n'
			<< "number of vowel o: \t" << oCnt << '\n'
			<< "number of vowel u: \t" << uCnt << '\n';
		aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	}
}

/************************
 * 统计空格, 制表符的数量 *
 ***********************/
void Chapter_five::p_5p3p2_5p11()
{
	string input = "";
	unsigned spaceCnt = 0, tabCnt = 0, enterCnt = 0;
	while (getline(cin, input))
	{
		auto beginStr = input.begin();
		while (beginStr != input.end())
		{
			if (*beginStr == ' ')
				++spaceCnt;
			else if (*beginStr == '\t')
				++tabCnt;
			else if (*beginStr == '\n')
				++enterCnt;
			++beginStr;
		}
		cout << "number of vowel space: \t" << spaceCnt << '\n'
			<< "number of vowel tab: \t" << tabCnt << '\n'
			<< "number of vowel enter: \t" << enterCnt << '\n';
		spaceCnt = 0, tabCnt = 0, enterCnt = 0;
	}
}

/*********************************
 * 从标准输入中查找连续出现的字符串 *
 ********************************/
void Chapter_five::p_5p4p1_5p14()
{
	string str;
	int count = 1;
	string tmp = "";
	while (cin >> str)
	{
		if (tmp != str)
		{
			cout << "count is " << count << endl;
			count = 1;
			tmp = str;
		}
		else
		{
			++count;
		}
	}
}

/****************************
 * 分别使用for和while循环遍历 *
 ***************************/
void Chapter_five::p_5p4p2_5p16()
{
	int ir[] = { 1,2,3,4,5,6,7,8,9,10 };
	// 使用while遍历数组
	auto irBegin = begin(ir); // type is int*
	while (irBegin != end(ir))
	{
		cout << *irBegin << "\t";
		++irBegin;
	}
	cout << endl;

	// 使用for遍历数组(通过指针的方式)
	for (irBegin = begin(ir); irBegin != end(ir); ++irBegin)
	{
		cout << *irBegin << "\t";
	}
	cout << endl;
	// 使用for遍历数组(通过下标的方式)
	for (unsigned i = 0; i != sizeof(ir) / sizeof(ir[0]); ++i)
	{
		cout << ir[i] << "\t";
	}
	cout << endl;

	vector<int> iv = { 1,2,3,4,5,6,7,8,9,10 };
	// 使用while遍历vector(使用迭代器)
	auto ivBegin = iv.begin(); // type is vector<int>::iterator
	while (ivBegin != iv.end())
	{
		cout << *ivBegin << "\t";
		++ivBegin;
	}
	cout << endl;
	// 使用for遍历vector(使用迭代器)
	for (ivBegin = iv.begin(); ivBegin != iv.end(); ++ivBegin)
	{
		cout << *ivBegin << "\t";
	}
	cout << endl;
}

/**************************************************
 * 检测其中一个vector对象是否是另一个vector对象的前缀 *
 *************************************************/
void Chapter_five::p_5p4p2_5p17()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v2 = { 1,2,3,4 };
	vector<int> v3 = { 5,6,7,8,9,10 };

	// v2size type is size_t
	for (decltype(v2.size()) v2Size = 0; v2Size != v2.size(); ++v2Size)
	{
		if (v2[v2Size] != v1[v2Size])
		{
			cout << "not true" << endl;
			break;
		}
	}
}

/**********************************
 * 使用do while 循环输出较短的字符串 *
 *********************************/
void Chapter_five::p_5p4p4_5p19()
{
	string input1;
	cin >> input1;
	do
	{
		string input2;
		cin >> input2;
		cout << (input1.length() > input2.length() ? input2 : input1) << endl;
	} while (cin >> input1);
}

/****************************************************
 * 使用while循环一次读取一次单词, 当一个单词连续出现两次 *
 * 时使用break中止循环, 输出连续出现的单词, 或者输出一条 *
 * 消息说明没有任何单词时连续出现的。					*
 ****************************************************/
void Chapter_five::p_5p5p1_5p20()
{
	string input;
	string input2;
	if (cin >> input)
	{
		while (cin >> input2)
		{
			if (input2 == input)
			{
				cout << input << endl;
				return;
			}
			input = input2;
		}
		input = "";
	}
	if (input != input2)
		cout << "no equal string." << endl;
}

/***********************************************
 * 修改上面的练习, 使其找到的单词必须以大写字母开头 *
 **********************************************/
void Chapter_five::p_5p5p2_5p21()
{
	string input;
	string input2;
	if (cin >> input)
	{
		while (cin >> input2)
		{
			if (input == input2 && isupper(input[0]))
			{
				cout << input << endl;
				return;
			}
			input = input2;
		}
		input = "";
	}
	if (input != input2)
		cout << "no equal string." << endl;
}

/******************************************************
 * 从标准输入中读取两个整数, 输出第一个数除以第二个数的结果 *
 *****************************************************/
int &Chapter_five::p_5p6p3_5p23()
{
	int i, j;
	cin >> i >> j;
	int result = i / j;
	int &resultR = result;
	cout << result << endl;
	return resultR;
}

/*************************
 * 当第二个数为0时抛出异常 *
 ************************/
void Chapter_five::p_5p6p3_5p24()
{
	int i, j;
	cin >> i >> j;
	if (j == 0)
		throw runtime_error("second data must not equal zero!");
	int result = i / j;
	int &resultR = result;
	cout << result << endl;
}

/***************************
 * 使用try catch 去捕获异常 *
 **************************/
void Chapter_five::p_5p6p3_5p25()
{
again:
	try
	{
		int i, j;
		cin >> i >> j;
		if (j == 0)
			throw runtime_error("second data must not equal zero!");
		int result = i / j;
		int &resultR = result;
	}
	catch (runtime_error err)
	{
		cout << err.what() << endl;
		cout << "retry again? y/n" << endl;
		string input;
		cin >> input;
		if (input == "y")
			goto again;
	}
}

/***************
 * 运行所有练习 *
 **************/
void Chapter_five::runAll()
{
	//p_5p3p1_5p5();
	//p_5p3p1_5p6();
	//p_5p3p2_5p9();
	//p_5p3p2_5p11();
	//p_5p4p1_5p14();
	//p_5p4p2_5p16();
	//p_5p4p2_5p17();
	//p_5p4p4_5p19();
	//p_5p5p1_5p20();
	//p_5p5p2_5p21();
	//p_5p6p3_5p23();
	//p_5p6p3_5p24();
	//p_5p6p3_5p25();
}