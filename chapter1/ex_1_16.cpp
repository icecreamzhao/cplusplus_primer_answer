#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	��д����, ��cin��ȡһ����, ������
	*/
	int PrintSum(std::istream &is)
	{
		int result = 0;
		for (int i = 0; is >> i; result += i)
			;
		return result;
	}
}