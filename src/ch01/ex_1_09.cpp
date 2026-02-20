// ============================================================
// @file    ex_1_09.cpp
// @brief   C++ Primer - 第一章 练习九
//
// @details
// 编写程序，使用 while 循环将 50 到 100 的整数相加
//
// ============================================================

#include <iostream>

#define MAX_WHILE 100

int main()
{
    int i = 50, sum = 50;
    while (i != MAX_WHILE) sum += ++i;
    std::cout << "the sum of 50 and 100 is " << sum << std::endl;
    return 0;
}
