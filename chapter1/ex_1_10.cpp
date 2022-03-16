#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	使用递减运算符在循环中按递减顺序打印10到0之间的整数。
	*/
	void PrintTenToZero()
	{
		int i = 10;
		while (i >= 0)
			std::cout << i-- << "\t";
		std::cout << std::endl;
	}
}