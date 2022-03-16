#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	编写程序, 使用for循环将50到100的数相加。
	--- return: result
	*/
	int AddFifthToHundredForVersion()
	{
		int result = 0;
		for (int i = 50; i != 101; ++i)
			result += i;
		return result;
	}

	/*
	使用递减运算符在循环中按递减顺序打印10到0之间的整数。
	*/
	void PrintTenToZeroForVersion()
	{
		for (int i = 10; i != -1; --i)
			std::cout << i << "\t";
		std::cout << std::endl;
	}
	/*
	编写程序, 提示用户输入两个整数, 打印这两个整数所指定范围内的所有整数。
	---
	i, j 输出范围
	*/
	void PrintUserInputNumForVersion(int i, int j)
	{
		if (i > j)
			PrintUserInputNumForVersion(j, i);
		else
		{
			for (; i != j + 1; ++i)
				std::cout << i << "\t";
			std::cout << std::endl;
		}
	}
}