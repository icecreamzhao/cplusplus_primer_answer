#include "chapter1/chapter_1.h"

/*
��д����, ��ȡ����ISBN��ͬ��Sales_item����, ������ǵĺ͡�
*/
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
		std::cout << item1 + item2 << std::endl;
	else
		std::cout << "isbn is not equal." << std::endl;
}