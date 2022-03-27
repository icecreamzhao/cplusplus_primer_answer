#include "chapter2/chapter_2.h"

int main()
{
	int i = 10;
	int *ip = &i;
	*ip = 4;
	std::cout << *ip << " " << i << std::endl;
	i = 5;
	std::cout << *ip << " " << i << std::endl;
}