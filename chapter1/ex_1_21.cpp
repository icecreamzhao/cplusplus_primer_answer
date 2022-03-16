#include "chapter1/chapter_1.h"

/*
编写程序, 读取两个ISBN相同的Sales_item对象, 输出它们的和。
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