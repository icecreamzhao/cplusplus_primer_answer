// ============================================================
// @file    ex_1_09.cpp
// @brief   C++ Primer - 第一章 练习九
//
// @details
// 编写程序，使用 while 循环将 50 到 100 的整数相加
//
// ============================================================

#include <iostream>

int main()
{
    constexpr int min = 50;
    constexpr int max = 100;
    int sum = 0, i = min;
    while (i != max) sum += ++i;
    std::cout << "the sum of 50 to 100 is " << sum << std::endl;
    return 0;
}
