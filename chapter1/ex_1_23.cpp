#include "chapter1/chapter_1.h"

/*
编写程序, 读取多条销售记录, 并统计每个ISBN有几本销售记录。
*/
int main()
{
	Sales_item pre;
	int count = 1;

	if (std::cin >> pre)
	{
		Sales_item cur;
		while (std::cin >> cur)
		{
			if (cur.isbn() == pre.isbn())
				++count;
			else
			{
				std::cout << pre.isbn() << " occurs " << count << " times." << std::endl;
				pre = cur;
				count = 1;
			}
		}
		std::cout << pre.isbn() << " occurs " << count << " times." << std::endl;
	}
	else
	{
		std::cout << "No Data?!" << std::endl;
		return -1;
	}
	return 0;
}