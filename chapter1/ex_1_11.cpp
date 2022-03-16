#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	编写程序, 提示用户输入两个整数, 打印这两个整数所指定范围内的所有整数。
	---
	i, j 输出范围
	*/
	void PrintUserInputNum(int i, int j)
	{
		if (i > j)
			PrintUserInputNum(j, i);
		else
		{
			while (i != j + 1)
				std::cout << i++ << "\t";
			std::cout << std::endl;
		}
	}
}
