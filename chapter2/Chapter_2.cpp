#include "Chapter_2.h"
#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

/*******************
* 写出下列式子的结果 *
*******************/
void Chapter_two::p_2p1p2_2p3()
{
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl; // 32
	cout << u - u2 << endl; // 32bit: 4,294,967,264

	int i = 10, i2 = 42;
	cout << i2 - i << endl; // 32
	cout << i - i2 << endl; // -32
	cout << i - u << endl; // 0
	cout << u - i << endl; // 0
}

/**************
* 使用转义序列 *
**************/
void Chapter_two::p_2p1p3_2p8()
{
	cout << "2M\n" << endl;
	cout << "2\tM\n" << endl;
}

/*****************************************
* 下列赋值都是合法的, 但是会有信息丢失的风险 *
*****************************************/
void Chapter_two::p_2p3p1_2p16()
{
	int i = 0, & r1 = i;
	double d = 3.14, & r2 = d;

	r2 = 3.15;
	r2 = r1;
	i = r2;
	r1 = d;
}

/*****************************************
* 编写程序, 修改指针的值以及指针所指对象的值 *
*****************************************/
void Chapter_two::p_2p3p2_2p18()
{
	int val = 1, * p = &val;
	int val2 = 2;
	cout << "val is " << val << ", val2 is " << val2 << ", p(pointer) is " << *p << endl;
	// change point
	p = &val2;
	cout << "val is " << val << ", val2 is " << val2 << ", p(pointer) is " << *p << endl;
	// change val2's value
	*p = 3;
	cout << "val is " << val << ", val2 is " << val2 << ", p(pointer) is " << *p << endl;
}

/**************
* 常量引用示例 *
**************/
void Chapter_two::constReference()
{
	const int i = 42;
	const int& cri = i;
	int j = 42;
	const int& crj = j;
	cout << crj << endl;
	j = 43;
	cout << crj << endl;
}

/**************
* 常量指针示例 *
**************/
void Chapter_two::constPointer()
{
	int i = 3;
	int* const pi = &i;
	*pi = 4; // right
	//pi = j; // error, pi is const
	const double dpi = 3.14;
	//double* const pdpi = &dpi; //error, type is const double, not double
	const double* const pdpi = &dpi; // right
	double* pd = nullptr;
}

/***************************************
* 使用Sales_data读入一笔交易, 并输出总和 *
***************************************/
void Chapter_two::calculateSalesData()
{
	Sales_data data1, data2;
	// 读入第一笔交易(包括isbn, 平均价格和销售量)
	cin >> data1.isbn >> data1.price >> data1.item;
	data1.revenue = data1.price * data1.item;
	cin >> data2.isbn >> data2.price >> data2.item;
	data2.revenue = data2.price * data2.item;
	
	if (data1.isbn == data2.isbn)
	{
		unsigned int totalCnt = data1.item + data2.item;
		if (totalCnt != 0)
		{
			double totalRev = data1.revenue + data2.revenue;
			cout << data1.isbn << " 售出了 " << totalCnt << " 册, 总销售额为 " << totalRev << " 元" << endl;
		}
	}
	else
	{
		cout << "isbn 不一致" << endl;
	}
}

/****************************************
* 使用sales_data完成1.5.1, 1.5.2, 1.6节练习 *
****************************************/
void Chapter_two::p_2p6p2_2p41()
{
	// 读取一组销售记录, 并把每一条打印在标准输出上
	Sales_data data;

	while (cin >> data.isbn >> data.item >> data.price)
	{
		if (data.item > 0)
			data.revenue = data.item * data.price;
		cout << data.isbn << "\t" << data.item << "\t" << data.revenue << endl;

		cout << "continue? enter y or n:" << endl;
		char answer;
		cin >> answer;
		if (answer == 'n')
			break;
	}

	cout << "next practice: " << endl;

	// 读取两个isbn相同的记录并输出和
	data.clear();
	Sales_data data2;
	cin >> data.isbn >> data.item >> data.price;
	cin >> data2.isbn >> data2.item >> data2.price;

	data.revenue = data.item * data.price;
	data2.revenue = data2.item * data2.price;

	if (data.isbn == data.isbn)
	{
		unsigned int totalCnt = data.item + data2.item;
		if (totalCnt != 0)
		{
			double totalRev = data.revenue + data2.revenue;
			cout << data.isbn << "\t" << totalCnt << "\t" << totalRev << endl;
		}
		else
		{
			cout << "no sales!" << endl;
		}
	}
	else
	{
		cerr << "isbn is not equal" << endl;
	}

	// 读取多个具有相同isbn销售记录, 输出所有记录的和
	cout << "next practice: " << endl;
	data.clear();
	data2.clear();

	if (cin >> data.isbn >> data.item >> data.price)
	{
		data.revenue = data.item * data.price;
		while (cin >> data2.isbn >> data2.item >> data2.price)
		{
			data2.revenue = data2.item * data2.price;
			if (data.isbn == data2.isbn)
			{
				data.revenue += data2.revenue;
				data.item += data2.item;
			}
			else
			{
				cout << data.isbn << "\t" << data.item << "\t" << data.revenue << endl;
				data.isbn = data2.isbn;
				data.item = data2.item;
				data.price = data2.price;
				data.revenue = data2.revenue;
			}
			cout << "continue? enter y or n:" << endl;
			char answer;
			cin >> answer;
			if (answer == 'n')
				break;
		}
		cout << data.isbn << "\t" << data.item << "\t" << data.revenue << endl;
	}

	// 读取多条销售记录,	统计每个isbn有几条销售记录
	cout << "next practice: " << endl;
	data.clear();
	data2.clear();

	if (cin >> data.isbn)
	{
		unsigned int count = 1;
		while (cin >> data2.isbn)
		{
			if (data.isbn == data2.isbn)
			{
				++count;
			}
			else
			{
				cout << data.isbn << " occurs " << count << " times" << endl;
				data.isbn = data2.isbn;
				count = 1;
			}
			cout << "continue? enter y or n:" << endl;
			char answer;
			cin >> answer;
			if (answer == 'n')
				break;
		}
	}
}

// 运行练习
void Chapter_two::runAll()
{
	p_2p1p2_2p3();
	p_2p1p3_2p8();
	p_2p3p1_2p16();
	p_2p3p2_2p18();
	constReference();
	constPointer();
	calculateSalesData();
	p_2p6p2_2p41();
}