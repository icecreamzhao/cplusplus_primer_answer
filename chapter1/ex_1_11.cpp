#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	��д����, ��ʾ�û�������������, ��ӡ������������ָ����Χ�ڵ�����������
	---
	i, j �����Χ
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
