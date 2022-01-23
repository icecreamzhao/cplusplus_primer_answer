#ifndef __SALES_DATA_BETTER__
#define __SALES_DATA_BETTER__
#include <iostream>

using std::string;
using std::istream;
using std::cout;
using std::endl;

struct Sales_data_better
{
	// ----- constructor -----

	Sales_data_better() = default;
	Sales_data_better(const string &s, unsigned n, double d) : bookNo(s), item(n), price(d) {}

	// ----- friend constructor -----

	friend istream &read(istream &, Sales_data_better &data);
	friend Sales_data_better &add(Sales_data_better &data1, const Sales_data_better &data2);
	friend void printSales(const Sales_data_better &);

	// ----- member -----

	string isbn() const { return bookNo;  }
	Sales_data_better &combine(const Sales_data_better &rhs)
	{
		item += rhs.item;
		revenue += revenue;
		return *this;
	}

	void clear()
	{
		bookNo = "";
		price = 0.0;
		item = 0;
		revenue = 0.0;
	}

private:
	string bookNo = "";
	double price = 0.0;
	int item = 0;
	double revenue = 0.0;

};

/*
======================================
读入销售数据

>> cin:		读入流对象
>> better:  要读入的对象
======================================
*/
istream &read(istream &cin, Sales_data_better &better)
{
	cin >> better.bookNo >> better.item >> better.price;
	better.revenue = better.item * better.price;
	return cin;
}

/*
======================================
将两条销售数据相加

>> item1:要相加的数据
>> item2:要相加的数据
======================================
*/
Sales_data_better &add(Sales_data_better &item1, const Sales_data_better& item2)
{
	if (item1.bookNo == item2.bookNo)
	{
		item1.item += item2.item;
		item1.revenue += item2.revenue;
	}
	return item1;
}

/*
======================================
打印销售数据

>> better: 销售数据
======================================
*/
void printSales(const Sales_data_better &better)
{
	cout << "bookNo: " << better.bookNo << ", item: " << better.item << ", revenue: " << better.revenue << endl;
}

#endif