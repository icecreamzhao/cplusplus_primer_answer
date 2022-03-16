#include "chapter1/Chapter_1.h"

/*
编写程序, 使用while循环将50到100的数相加。
--- return: result
*/
namespace CHAPTER_ONE
{
	int AddFifthToHundred()
	{
		int sum = 0, i = 50, j = 100;
		while (i <= j)
		{
			sum += (++i);
		}
		return sum;
	}
}