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
* ��д����, һ�ζ�ȡһ���� *
* ��д����, һ�ζ�ȡһ���� *
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
* ���������ַ���, �Ƚϳ����Ƿ����, ������, ��������Ƚϴ���ַ��� *
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
* �������ж�ȡһ���ַ���, ���ϲ���һ������ַ���;	*
* �������ж�ȡһ���ַ���, �ϲ����ַ�����ʹ�ÿո�ָ� *
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
* �����ַ����еı����� *
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
* ���ַ�����Ϊ��д *
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
* ʹ���±�����ַ��� *
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
* �����������ת����ʮ������ *
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
* ʹ�÷�Χfor��佫�ַ��������ַ�ʹ��X���� *
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
* ʹ�ô�ͳfor��while�޸��������ϰ *
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
* ��ȡһ������, ����ӽ�vector *
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
* ���������ϰ�ĳ�string *
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
* ʹ����������vector *
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
* ��cin����һ��ʴ���vector, Ȼ���Ϊ��д, ������, ÿ��ռһ�� *
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
* ʹ�����ַ�ʽ��ʼ����10��intֵ��vector, ֵΪ42 *
*********************************************/
void Chapter_three::p_3p2p3_3p19()
{
	vector<int> v1(10, 42);
	vector<int> v2 = { 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	vector<int> v3{ 10, 42 };
}

/*************************************************
* ����һ������, ����vector��, ��ÿ�����������ĺ���� *
* ����һ�������һ�������ĺ����, �Դ�����			 *
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
		// ��ÿ�����������ĺ����
		for (unsigned i = 0; i < (result.size() % 2 == 0 ? result.size() : result.size() - 1); i += 2)
		{
			cout << result[i] + result[i + 1] << endl;
		}
		// ����һ�������һ�������ĺ����
		for (unsigned i = 0; i < (result.size() % 2 != 0 ? (result.size() - 1) / 2 : result.size() / 2); ++i)
		{
			//cout << i << endl;
			cout << result[i] + result[result.size() - 1 - i] << endl;
		}
	}
}

/***********************
* ʹ�õ������������ַ��� *
***********************/
void Chapter_three::useVectorIterator()
{
	// �����ַ�������ĸΪ��д
	string s("some thing");
	if (s.begin() != s.end())
	{
		auto first = s.begin();
		*first = toupper(*first);
	}
	cout << s << endl;

	// �����ַ�����д
	s = "some thing";
	for (auto i = s.begin(); i != s.end() && !isspace(*i); ++i)
		*i = toupper(*i);
	cout << s << endl;

	// ʹ�ü�ͷ�����
	vector<string> v1;
	v1.push_back("string1");
	v1.push_back("string2");
	for (auto i = v1.cbegin(); i != v1.cend() && !(i->empty()); ++i)
		cout << *i << endl;
}

/***********************
* �޸��ַ�����һ��Ϊ��д *
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
* ��������10��Ԫ�ص�vector����, ʹ�õ�������ԭ����ֵ��Ϊ���� *
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
* ʹ�õ�����ʵ�ֶ��������� *
*************************/
void Chapter_three::search()
{
	// Ҫ����������
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	int target = 9;
	int target2 = 2;

	// �м�ֵ
	auto mid = v1.begin() + v1.size() / 2;

	// ���м��ж�, ���Ҫ�ҵ�ֵ�����м�ֵ, ���������, ������ǰ����
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
* practiceThreeOTwenty�������汾 *
********************************/
void Chapter_three::p_3p4p2_3p24()
{
	// ������ڵ����ĺ�
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

	// ������һ���͵�һ���ĺ�, �Դ�����
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
* ʹ���±�ʵ�ֻ��ַ����� *
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
* ����һ������, ��ÿ��Ԫ�ص�ֵ�������±� *
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
* ����һ������鸴�Ƶ���һ��������, ��ʹ��vector��д *
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

	// ʹ��vectorʵ����ͬ�Ĺ���
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
* ����ָ�뽫�����е�Ԫ����Ϊ0 *
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
* �Ƚ������vector�Ƿ���ͬ *
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
			cout << "��һ��" << endl;
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
			cout << "��һ��" << endl;
			v1Begin = v1.cend();
		}
	}
}

/*****************************
* �Ƚ�C����ַ����ͱ�׼���ַ��� *
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
		cout << "s1 " << (s1 > s2 ? "����" : "С��") << " s2" << endl;
	}

	char ca1[] = "abc";
	char ca2[] = { 'd' , 'e', 'f', '\0'};
	if (strcmp(ca1, ca2) == 0)
	{
		cout << "s1 equals s2" << endl;
	}
	else
	{
		cout << "s1 " << (strcmp(ca1, ca2) > 0 ? "����" : "С��") << " s2" << endl;
	}
}

/****************************************************
* ʹ��strcpy��strcat��ǰ������������ݿ����������������� *
*****************************************************/
void Chapter_three::p_3p5p4_3p40()
{
	// ����һ��Ҫָ��ca1�ĳ���, Ҫ��Ȼstrcat֮��ca1�Ͳ�������
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
* C��������� *
***************/
void Chapter_three::cCodeTest()
{
	// ����ʹ���Կ��ַ���β���ַ������ʼ���ַ���
	char ca1[] = {'c', '+', '+', '\0'};
	string s = ca1;
	// ��string�ļӷ������������ַ�������Ϊ���е��������(�����ܶ���)
	string s2 = s + " and " + ca1;
	// ���ϸ�ֵ������, ����ʹ���ַ�������Ϊ�Ҳ���������
	s2 += ca1;
	cout << s2 << endl;

	// ʹ��c_str������ʼ���ַ�����
	const char* cp = s2.c_str();
	while (*cp)
	{
		cout << *cp;
		++cp;
	}
	cout << endl;
}

/***********************
* �����������ʼ��vector *
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
* vector�������ݸ��������� *
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
* ��ά������� *
**************/
void Chapter_three::multiArray()
{
	int arr[2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
	};

	// ���ﲻ����ôд
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
* �����ָ�� *
************/
void Chapter_three::multiArrayAndPoint()
{
	int arr[3][4] = {};
	// ����һ��ָ�����ĸ����������ָ��
	int(*p)[4] = arr;
	p = &arr[2];
	cout << (*p)[0] << endl;

	// ����һ�������ĸ�����ָ�������
	int itemp = 0;
	int* pa[4] = {&itemp, &itemp, &itemp, &itemp };
	cout << *(pa[0]) << endl;

	// ʹ��ָ��ѭ������
	for (auto i = arr; i != arr + 3; ++i)
	{
		for (auto j = *i; j != *i + 4; ++j)
		{
			cout << *j << "\t";
		}
	}
	cout << endl;

	// ʹ��ָ��ѭ������(ʹ��begin��end)
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
	// ʹ�÷�Χfor����������
	for (int(&i)[two_size] : ia)
		for (int& j : i)
			cout << j << "\t";

	cout << endl;
	// ʹ����ͨfor���±�����������
	for (size_t i = 0; i != one_size; ++i)
	{
		for (size_t j = 0; j != two_size; ++j)
		{
			cout << ia[i][j] << "\t";
		}
	}
	cout << endl;

	// ʹ����ͨfor��ָ��
	for (int (*i)[two_size] = ia; i != end(ia); ++i)
		for (int *j = *i; j != end(*i); ++j)
			cout << *j << "\t";
	cout << endl;
}

// ʹ�����ͱ�����
using int_array = int(&)[4];

/**************
* ����������ϰ *
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