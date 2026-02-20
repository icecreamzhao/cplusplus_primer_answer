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
    int f_v, s_v, i_temp = 0;
    std::cin >> f_v >> s_v;
    if (s_v > f_v)
    {
        i_temp = f_v - 1;
        while (i_temp != s_v) std::cout << ++i_temp << "\t";
    } else if (f_v > s_v)
    {
       i_temp = s_v - 1; 
       while (i_temp != f_v) std::cout << ++i_temp << "\t";
    } else
    {
        std::cout << f_v;
    }
    std::cout << std::endl;
    return 0;
}
