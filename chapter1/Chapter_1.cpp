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
* 编写程序, 在标准输出上打印Hello, World *
***************************************/
void Chapter_one::p_1p2_1p3()
{
	cout << "Hello, World" << endl;
}

/**************************************
* 编写程序使用乘法运算符来打印两个数的积 *
**************************************/
void Chapter_one::p_1p2_1p4()
{
	cout << "please enter your num: ";
	int i = 0, j = 0;
	cin >> i >> j;
	cout << i * j << endl;
}

/*******************************************
* 将每个运算对象的打印操作放到一条独立的语句中 *
*******************************************/
void Chapter_one::p_1p2_1p5()
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
* 使用while计算1到10 *
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
* 使用while循环将50 - 100之间的整数相加 *
**************************************/
void Chapter_one::p_1p4p1_1p9()
{
	int i = 0, j = 50;
	while (j != 101)
	{
		i += (j++);
	}
	cout << "sum of 50 - 100 is " << i << endl;
}

/***************************************************
* 使用递减运算符在循环中按递减顺序打印10 - 0之间的整数 *
***************************************************/
void Chapter_one::p_1p4p1_1p10()
{
	int i = 10;
	while (i != -1)
	{
		cout << i-- << "\t";
	}
	cout << endl;
}

/***************************
* 打印用户指定的范围内的整数 *
***************************/
void Chapter_one::p_1p4p1_1p11()
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
* 使用for循环重写practiceOneONine(), practiceOneOTen(), practiceOneOEleven() *
****************************************************************************/
void Chapter_one::p_1p4p2_1p13()
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
* 输入多个数字, 计算和 *
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
* 统计用户输入的数, 每一个数出现了多少次 *
*************************************/
void Chapter_one::statisticsDisplayNum()
{
	cout << "enter some num: " << endl;
	int currentVal = 0, val = 0;
	// 计数
	int count = 1;
	// 读取当前的数
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
* 读取一组销售记录, 将每条销售记录都打印到输出上 *
*********************************************/
void Chapter_one::p_1p5p1_1p20()
{
	Sales_item item;
	while (cin >> item)
	{
		cout << item << endl;
	}
}

/***********************
* 读取两组销售记录并相加 *
***********************/
void Chapter_one::p_1p5p1_1p21()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;
	cout << item1 + item2 << endl;
}

/***********************************************
* 读取多条具有相同ISBN的销售记录, 输出所有记录的和 *
***********************************************/
void Chapter_one::p_1p5p1_1p22()
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
* 检测是否具有相同的isbn号 *
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
* 读取多条销售记录, 并统计每个ISBN有几条销售记录 *
*********************************************/
void Chapter_one::p_1p5p2_1p23()
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
* 计算相同isbn号的书的销售记录 *
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

// 运行练习
void Chapter_one::runAll()
{
	/*p_1p2_1p3();
	p_1p2_1p4();
	p_1p2_1p5();
	p_1p4p1_1p9();
	p_1p4p1_1p10();
	p_1p4p1_1p11();
	p_1p4p2_1p13();
	cinNumToSum();
	statisticsDisplayNum();
	p_1p5p1_1p20();
	p_1p5p1_1p21();
	p_1p5p1_1p22();
	checkSameIsbn();
	p_1p5p2_1p23();*/
}