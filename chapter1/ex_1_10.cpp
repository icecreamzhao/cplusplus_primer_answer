#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	ʹ�õݼ��������ѭ���а��ݼ�˳���ӡ10��0֮���������
	*/
	void PrintTenToZero()
	{
		int i = 10;
		while (i >= 0)
			std::cout << i-- << "\t";
		std::cout << std::endl;
	}
}