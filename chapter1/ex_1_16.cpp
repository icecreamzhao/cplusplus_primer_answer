#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	编写程序, 从cin读取一组数, 输出其和
	*/
	int PrintSum(std::istream &is)
	{
		int result = 0;
		for (int i = 0; is >> i; result += i)
			;
		return result;
	}
}