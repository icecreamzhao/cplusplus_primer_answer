#include "chapter1/Chapter_1.h"

int main()
{
	//std::cout << CHAPTER_ONE::AddFifthToHundred() << std::endl;

	//CHAPTER_ONE::PrintTenToZero();
	int i = 0, j = 0;
	//std::cin >> i >> j;
	//CHAPTER_ONE::PrintUserInputNum(i, j);
	//std::cout << CHAPTER_ONE::AddFifthToHundredForVersion() << std::endl;

	//CHAPTER_ONE::PrintTenToZeroForVersion();
	
	//CHAPTER_ONE::PrintUserInputNumForVersion(i, j);

	int sum = CHAPTER_ONE::PrintSum(std::cin);
	std::cout << sum << std::endl;
}