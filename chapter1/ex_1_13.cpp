#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	/*
	��д����, ʹ��forѭ����50��100������ӡ�
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
	ʹ�õݼ��������ѭ���а��ݼ�˳���ӡ10��0֮���������
	*/
	void PrintTenToZeroForVersion()
	{
		for (int i = 10; i != -1; --i)
			std::cout << i << "\t";
		std::cout << std::endl;
	}
	/*
	��д����, ��ʾ�û�������������, ��ӡ������������ָ����Χ�ڵ�����������
	---
	i, j �����Χ
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