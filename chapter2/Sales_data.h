#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>

struct Sales_data
{
	string isbn = "";
	double price = 0.0;
	int item = 0;
	double revenue = 0.0;

	void clear()
	{
		isbn = "";
		price = 0.0;
		item = 0;
		revenue = 0.0;
	}
};

#endif // !SALES_DATA
