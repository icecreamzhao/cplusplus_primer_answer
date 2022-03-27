#include "chapter2/chapter_2.h"
struct Sales_data
{
	std::string isbn;
	std::string bookName;
	double price = 0.0;
	unsigned int item = 0;
	double revenue = 0;

	void clear()
	{
		isbn = "";
		bookName = "";
		price = 0.0;
		item = 0;
		revenue = 0.0;
	}
};
/*
======================================
使用sales_data完成1.5.1, 1.5.2, 1.6节练习
======================================
*/
int main()
{
	// 读取一组销售记录, 并把每一条打印在标准输出上
	Sales_data data;

	while (std::cin >> data.isbn >> data.item >> data.price)
	{
		if (data.item > 0)
			data.revenue = data.item * data.price;
		std::cout << data.isbn << "\t" << data.item << "\t" << data.revenue << std::endl;

		std::cout << "continue? enter y or n:" << std::endl;
		char answer;
		std::cin >> answer;
		if (answer == 'n')
			break;
	}

	std::cout << "next practice: " << std::endl;

	// 读取两个isbn相同的记录并输出和
	data.clear();
	Sales_data data2;
	std::cin >> data.isbn >> data.item >> data.price;
	std::cin >> data2.isbn >> data2.item >> data2.price;

	data.revenue = data.item * data.price;
	data2.revenue = data2.item * data2.price;

	if (data.isbn == data.isbn)
	{
		unsigned int totalCnt = data.item + data2.item;
		if (totalCnt != 0)
		{
			double totalRev = data.revenue + data2.revenue;
			std::cout << data.isbn << "\t" << totalCnt << "\t" << totalRev << std::endl;
		}
		else
		{
			std::cout << "no sales!" << std::endl;
		}
	}
	else
	{
		std::cerr << "isbn is not equal" << std::endl;
	}

	// 读取多个具有相同isbn销售记录, 输出所有记录的和
	std::cout << "next practice: " << std::endl;
	data.clear();
	data2.clear();

	if (std::cin >> data.isbn >> data.item >> data.price)
	{
		data.revenue = data.item * data.price;
		while (std::cin >> data2.isbn >> data2.item >> data2.price)
		{
			data2.revenue = data2.item * data2.price;
			if (data.isbn == data2.isbn)
			{
				data.revenue += data2.revenue;
				data.item += data2.item;
			}
			else
			{
				std::cout << data.isbn << "\t" << data.item << "\t" << data.revenue << std::endl;
				data.isbn = data2.isbn;
				data.item = data2.item;
				data.price = data2.price;
				data.revenue = data2.revenue;
			}
			std::cout << "continue? enter y or n:" << std::endl;
			char answer;
			std::cin >> answer;
			if (answer == 'n')
				break;
		}
		std::cout << data.isbn << "\t" << data.item << "\t" << data.revenue << std::endl;
	}

	// 读取多条销售记录,	统计每个isbn有几条销售记录
	std::cout << "next practice: " << std::endl;
	data.clear();
	data2.clear();

	if (std::cin >> data.isbn)
	{
		unsigned int count = 1;
		while (std::cin >> data2.isbn)
		{
			if (data.isbn == data2.isbn)
			{
				++count;
			}
			else
			{
				std::cout << data.isbn << " occurs " << count << " times" << std::endl;
				data.isbn = data2.isbn;
				count = 1;
			}
			std::cout << "continue? enter y or n:" << std::endl;
			char answer;
			std::cin >> answer;
			if (answer == 'n')
				break;
		}
	}
}
