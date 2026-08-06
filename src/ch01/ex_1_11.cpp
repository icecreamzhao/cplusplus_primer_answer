// ============================================================
// @file    ex_1_11.cpp
// @brief   C++ Primer - 第一章 练习十一
//
// @details
// 编写程序，提示用户输入两个整数，打印这两个整数所指定范围内的所有整数
//
// ============================================================

#include <iostream>

int main()
{
    std::cout << "please enter two numbers：";
    int first, second, temp = 0;
    std::cin >> first >> second;
    if (second > first)
    {
        temp = first - 1;
        while (temp != second) std::cout << ++temp << "\t";
    } else if (first > second)
    {
       temp = second - 1; 
       while (temp != first) std::cout << ++temp << "\t";
    } else
    {
        std::cout << first;
    }
    std::cout << std::endl;
    return 0;
}
