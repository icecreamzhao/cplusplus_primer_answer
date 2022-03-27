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
ʹ��sales_data���1.5.1, 1.5.2, 1.6����ϰ
======================================
*/
int main()
{
	// ��ȡһ�����ۼ�¼, ����ÿһ����ӡ�ڱ�׼�����
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

	// ��ȡ����isbn��ͬ�ļ�¼�������
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

	// ��ȡ���������ͬisbn���ۼ�¼, ������м�¼�ĺ�
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

	// ��ȡ�������ۼ�¼,	ͳ��ÿ��isbn�м������ۼ�¼
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
