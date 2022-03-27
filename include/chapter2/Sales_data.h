#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>

using std::string;

struct Sales_data
{
	string isbn = "";
	double price = 0.0;
	int item = 0;
	double revenue = 0.0;

	void CalcRevence();
	void Print();
	void AddBook(const Sales_data &);

	void clear()
	{
		isbn = "";
		price = 0.0;
		item = 0;
		revenue = 0.0;
	}
};

void Sales_data::CalcRevence()
{
	revenue = price * item;
}

void Sales_data::Print()
{
	std::cout << isbn << ", price is " << price << ", revenue is " << revenue << std::endl;
}

void Sales_data::AddBook(const Sales_data &data)
{
	if (isbn == data.isbn)
	{
		item += data.item;
		revenue += data.revenue;
	}
}

#endif // !SALES_DATA