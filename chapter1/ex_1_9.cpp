#include "chapter1/Chapter_1.h"

/*
��д����, ʹ��whileѭ����50��100������ӡ�
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