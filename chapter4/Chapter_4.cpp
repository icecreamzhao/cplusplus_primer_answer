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
* ��ֵ *
*******/
void Chapter_four::p_4p1p2_4p1()
{
	int i = 5 + 10 * 20 / 2; // result is 105
	cout << "result is " << i << endl;
}

/**********
* �ж����� *
**********/
void Chapter_four::p_4p1p2_4p2()
{
	vector<int> vec = { 0 };
	// vec �����Ǵ��int��vector, vec.begin()������iterator, ����Ҫ�Դ˽�����
	// *(vec.begin()) �ȼ��� *vec.begin()
	cout << *vec.begin() << endl;

	// *vec.begin() + 1
	cout << (*(vec.begin())) + 1 << endl;
}

/**********************************
* �ӱ�׼�����ж�ȡ����, ����42ʱֹͣ *
**********************************/
void Chapter_four::p_4p3_4p10()
{
	int i = 0;
	while (cin >> i)
		if (i == 42)
			break;
}

/******************************
* ��дһ�����ʽ���ж�abcd�Ĺ�ϵ *
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
* ʹ�������������vector�е��������� *
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
* ʹ������������ж����ֳɼ�(high pass, low pass, pass, fail) *
***********************************************************/
void Chapter_four::p_4p7_4p22()
{
	int score = 0;
	while (cin >> score)
	{
		// ����������汾
		string result = score > 90 ? "high pass" : (score > 75 ? "low pass" : (score > 60 ? "pass" : "fail"));
		cout << "result is " << result << endl;
		// if ���汾
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
* �������б��ʽ�Ľ�� *
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
* ���ÿ���������͵Ĵ�С *
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
* �������б��ʽ��� *
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
 * ʹ�ú��ð汾��д *
 *****************/
void Chapter_four::p_4p10_4p31()
{
	// ԭ��
	vector<int> ivec(10, 2);
	vector<int>::size_type size = ivec.size();
	for (vector<int>::iterator i = ivec.begin(); i != ivec.end(); ++i, --size)
	{
		*i = static_cast<int>(size);
		cout << *i << "\t";
	}
	cout << endl;

	// ���ð汾
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
 * �����ʽ�޸�Ϊ�Ǹ������͵ĳ˷� *
 ******************************/
void Chapter_four::p_4p11p3_3p36()
{
	int i = 5;
	double d = 2.1;
	i = i * static_cast<int>(d);
	cout << i << endl;
}

/***************
 * ���ͻ���ת�� *
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