#include "Chapter_1.h"
#include "Sales_item.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void Chapter_one::enterTwoNum()
{
	cout << "please enter your num: ";
	int i = 0, j = 0;
	cin >> i >> j;
	cout << i + j << endl;
}

/***************************************
* ��д����, �ڱ�׼����ϴ�ӡHello, World *
***************************************/
void Chapter_one::practiceOneOThree()
{
	cout << "Hello, World" << endl;
}

/**************************************
* ��д����ʹ�ó˷����������ӡ�������Ļ� *
**************************************/
void Chapter_one::practiceOneOFour()
{
	cout << "please enter your num: ";
	int i = 0, j = 0;
	cin >> i >> j;
	cout << i * j << endl;
}

/*******************************************
* ��ÿ���������Ĵ�ӡ�����ŵ�һ������������� *
*******************************************/
void Chapter_one::practiceOneOFive()
{
	int v1 = 1, v2 = 3;
	cout << "The sum of ";
	cout << v1;
	cout << " and ";
	cout << v2;
	cout << " is ";
	cout << v1 + v2 << endl;
}

/********************
* ʹ��while����1��10 *
********************/
void Chapter_one::calculateOneToTen()
{
	int i = 0, j = 1;
	while (j != 11)
	{
		i += (j++);
	}
	cout << "sum of 1 to 10 is " << i << endl;
}

/**************************************
* ʹ��whileѭ����50 - 100֮���������� *
**************************************/
void Chapter_one::practiceOneONine()
{
	int i = 0, j = 50;
	while (j != 101)
	{
		i += (j++);
	}
	cout << "sum of 50 - 100 is " << i << endl;
}

/***************************************************
* ʹ�õݼ��������ѭ���а��ݼ�˳���ӡ10 - 0֮������� *
***************************************************/
void Chapter_one::practiceOneOTen()
{
	int i = 10;
	while (i != -1)
	{
		cout << i-- << "\t";
	}
	cout << endl;
}

/***************************
* ��ӡ�û�ָ���ķ�Χ�ڵ����� *
***************************/
void Chapter_one::practiceOneOEleven()
{
	cout << "please enter two num: " << endl;
	int i, j;
	cin >> i >> j;
	if (i < j)
	{
		while (i < j + 1)
		{
			cout << i++ << "\t";
		}
	}
	else
	{
		while (j < i + 1)
		{
			cout << j++ << "\t";
		}
	}
	cout << endl;
}

/****************************************************************************
* ʹ��forѭ����дpracticeOneONine(), practiceOneOTen(), practiceOneOEleven() *
****************************************************************************/
void Chapter_one::practiceOneOThirteen()
{
	// 50 -100
	for (int i = 50; i != 101; ++i)
	{
		cout << i << "\t";
	}
	cout << endl;

	// 10 - 0
	for (int i = 10; i != -1; --i)
	{
		cout << i << "\t";
	}
	cout << endl;

	// input two num
	int i, j;
	cout << "enter two num: " << endl;
	cin >> i >> j;
	if (i < j)
	{
		for (int t = i; t != j + 1; ++t)
		{
			cout << t << "\t";
		}
	}
	else
	{
		for (int t = j; t != i + 1; ++t)
		{
			cout << t << "\t";
		}
	}
	cout << endl;
}

/*********************
* ����������, ����� *
*********************/
void Chapter_one::cinNumToSum()
{
	cout << "enter sum num to sum: " << endl;
	int sum = 0, value;
	while (cin >> value)
	{
		sum += value;
	}
	cout << "sum is " << sum << endl;
}

/*************************************
* ͳ���û��������, ÿһ���������˶��ٴ� *
*************************************/
void Chapter_one::statisticsDisplayNum()
{
	cout << "enter some num: " << endl;
	int currentVal = 0, val = 0;
	// ����
	int count = 1;
	// ��ȡ��ǰ����
	if (cin >> currentVal)
	{
		while (cin >> val)
		{
			if (currentVal == val)
			{
				++count;
			}
			else
			{
				cout << currentVal << " occurs " << count << " times." << endl;
				count = 1;
				currentVal = val;
			}
		}
	}
}

/********************************************
* ��ȡһ�����ۼ�¼, ��ÿ�����ۼ�¼����ӡ������� *
*********************************************/
void Chapter_one::practiceOneOTwenty()
{
	Sales_item item;
	while (cin >> item)
	{
		cout << item << endl;
	}
}

/***********************
* ��ȡ�������ۼ�¼����� *
***********************/
void Chapter_one::practiceOneOTwentyOne()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;
}

/***********************************************
* ��ȡ����������ͬISBN�����ۼ�¼, ������м�¼�ĺ� *
***********************************************/
void Chapter_one::practiceOneOTwentyTwo()
{
	Sales_item item, item2;

	if (cin >> item)
	{
		while (cin >> item2)
		{
			item = item + item2;
		}
	}
	cout << item << endl;
}

/*************************
* ����Ƿ������ͬ��isbn�� *
*************************/
void Chapter_one::checkSameIsbn()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;

	if (item1.isbn() == item2.isbn())
	{
		cout << item1 + item2 << endl;
	}
	else
	{
		cerr << "data must refer to same ISBN" << endl;
	}
}

/*********************************************
* ��ȡ�������ۼ�¼, ��ͳ��ÿ��ISBN�м������ۼ�¼ *
*********************************************/
void Chapter_one::practiceOneOTwentyThree()
{
	Sales_item item1, item2;
	int count = 1;
	if (cin >> item1)
	{
		while (cin >> item2)
		{
			if (item1.isbn() == item2.isbn())
			{
				++count;
			}
			else
			{
				cout << item1.isbn() << " has " << count << " num." << endl;
				count = 1;
				item1 = item2;
			}
		}
	}
	if (item1 == item2)
	{
		cout << item2.isbn() << " has " << count << " num." << endl;
	}
}

/*****************************
* ������ͬisbn�ŵ�������ۼ�¼ *
*****************************/
void Chapter_one::showTotalSales()
{
	Sales_item total;
	if (cin >> total)
	{
		Sales_item trans;
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn())
			{
				total += trans;
			}
			else
			{
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}
}

// ������ϰ
void Chapter_one::runAll()
{
	/*practiceOneOThree();
	practiceOneOFour();
	practiceOneOFive();
	practiceOneONine();
	practiceOneOTen();
	practiceOneOEleven();
	practiceOneOThirteen();
	cinNumToSum();
	statisticsDisplayNum();
	practiceOneOTwenty();
	practiceOneOTwentyOne();
	practiceOneOTwentyTwo();
	checkSameIsbn();
	practiceOneOTwentyThree();*/
}