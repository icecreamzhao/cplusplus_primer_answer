// 将每个运算对象的打印操作放到一条独立的语句中。

#include <iostream>

int main()
{
    std::cout << "the product of two numbers is ";
    std::cout << (8 * 7);
    std::cout << std::endl;
    return 0;
}
