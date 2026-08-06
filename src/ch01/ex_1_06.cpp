// ============================================================
// @file    ex_1_06.cpp
// @brief   C++ Primer - 第一章 练习六
//
// @details
// 解释下列程序是否合法
// std::cout << "The sum of " << v1;
// << " and " << v2;
// << " is " << v1 + v2 << std::endl;
//
// ============================================================

#include <iostream>

int main()
{
    constexpr auto first_line  = "please explain to us if this code is right\n";
    constexpr auto second_line = "std::cout << \"The sum of \" << v1;\n";
    constexpr auto third_line  = "<< \" and \" << v2;\n";
    constexpr auto fourth_line = "<< \" is \" << v1 + v2 << std::endl;\n";

    std::cout << first_line;
    std::cout << second_line;
    std::cout << third_line;
    std::cout << fourth_line;

    std::cout << "不合法，首先没有声明v1和v2变量, 其次第二行没有先写std::cout却直接写了 << 运算符， 第三行也是同样的道理" << std::endl;
    return 0;
}
