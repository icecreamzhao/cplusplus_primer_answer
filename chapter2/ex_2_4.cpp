#include <iostream>

int main()
{
	int i = 0;
	const int *ip = &i;
	std::cout << *ip << std::endl;

	i = 2;
	std::cout << *ip << std::endl;
}