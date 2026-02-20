// 解释下列程序是否合法
/**
 * std::cout << "The sum of " << v1;
 * << " and " << v2;
 * << " is " << v1 + v2 << std::endl;
 */

#include <iostream>
#ifdef _WIN32
#include <Windows.h> // 或用 <cstdlib> 配合 system("chcp 65001")
#endif

#define FIRST_CHINESE "解释下列程序是否合法\n"
#define FIRST_CODE "std::cout << \"The sum of \" << v1;\n"
#define SECOND_CODE "<< \" and \" << v2;\n"
#define THIRD_CODE "<< \" is \" << v1 + v2 << std::endl;\n"

int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出编码为 UTF-8
    // 或者使用 system("chcp 65001"); // 这种方法会在控制台显示一条提示信息
    #endif
    std::cout << FIRST_CHINESE;
    std::cout << FIRST_CODE;
    std::cout << SECOND_CODE;
    std::cout << THIRD_CODE;

    std::cout << "不合法，首先没有声明v1和v2变量, 其次第二行没有先写std::cout却直接写了 << 运算符， 第三行也是同样的道理" << std::endl;
    return 0;
}
