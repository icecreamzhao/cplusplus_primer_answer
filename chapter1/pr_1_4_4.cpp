#include "chapter1/chapter_1.h"

namespace CHAPTER_ONE
{
	void pr_1_4_4(std::istream &is)
	{
		int i = 0, count = 1;
		if (is >> i)
		{
			int j = 0;
			while (is >> j)
			{
				if (i != j)
				{
					std::cout << i << " occur is " << count << std::endl;
					i = j;
					count = 1;
				}
				else
				{
					++count;
				}
			}
		}
		std::cout << i << " occur is " << count << std::endl;
	}
}