#include "chapter1/chapter_1.h"

/*
��д����, ��ȡ�������ۼ�¼, ��ͳ��ÿ��ISBN�м������ۼ�¼��
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