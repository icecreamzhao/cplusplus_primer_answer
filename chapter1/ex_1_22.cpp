#include "chapter1/chapter_1.h"

/*
��д����, ��ȡ���ж����ͬISBN�����ۼ�¼, ������м�¼�ĺ͡�
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