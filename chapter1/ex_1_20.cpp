#include "chapter1/chapter_1.h"

/*
将Sales_item.h拷贝到自己的工作目录中, 用它编写一个程序, 读取一组销售记录, 将每条销售记录打印到标准输出上。
*/
int main()
{
	for (Sales_item item; std::cin >> item; std::cout << item << std::endl)
		;
	return 0;
}