# CMakeList.txt: primerFifth 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("primerFifth")

# 将源代码添加到此项目的可执行文件。
add_executable (
primerFifth 
 "primerFifth.cpp" 
 "primerFifth.h" 
 "chapter1/chapter_1.h" 
 "chapter1/Chapter_1.cpp" 
 "chapter1/sales_item.h" 
 "chapter2/Chapter_2.h" 
 "chapter2/Chapter_2.cpp" 
 "chapter2/Sales_data.h" 
 "chapter3/Chapter_3.h" 
 "chapter3/Chapter_3.cpp"
 "chapter4/Chapter_4.cpp"
 "chapter4/Chapter_4.h"
 "chapter5/Chapter_5.h"
 "chapter5/Chapter_5.cpp" 
 "chapter6/Chapter_6.cpp"
 "chapter6/Chapter_6.h")

# TODO: 如有需要，请添加测试并安装目标。
