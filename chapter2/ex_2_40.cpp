#include "chapter2/chapter_2.h"
#include <string>

struct Sales_data
{
	std::string isbn;
	std::string bookName;
	double price = 0.0;
	unsigned int unit_sold = 0;
};

int main()
{
	Sales_data data;
	data.isbn = "abcde";
	data.price = 30;
	data.unit_sold = 5;

	
	std::cout << "isbn is " << data.isbn << ", price is " << data.price << " and sold " << data.unit_sold << std::endl;
}