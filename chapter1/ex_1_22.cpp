#include "chapter1/chapter_1.h"

/*
编写程序, 读取具有多个相同ISBN的销售记录, 输出所有记录的和。
*/
int main()
{
	Sales_item pre;
	if (std::cin >> pre)
	{
		Sales_item cur;
		while (std::cin >> cur)
		{
			if (pre.isbn() == cur.isbn())
				pre += cur;
			else
			{
				std::cout << pre << std::endl;
				pre = cur;
			}
		}
		std::cout << pre << std::endl;
	}
	else
	{
		cout << "No data! " << endl;
		return -1;
	}
	return 0;
}