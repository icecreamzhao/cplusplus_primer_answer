#include <iostream>

int main()
{
	std::cout << "enter two numbers";
	int i = 0, j = 0;
	std::cin >> i >> j;
	std::cout << "The product of ";
	std::cout << i;
	std::cout << " and ";
	std::cout << j;
	std::cout << " is ";
	std::cout << i * j;
	std::cout << std::endl;
	return 0;
}