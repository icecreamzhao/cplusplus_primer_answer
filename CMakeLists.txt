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
 "chapter6/Chapter_6.h"
 "chapter7/Sales_data.h" 
 "chapter7/Chapter_7.h"
 "chapter7/Chapter_7.cpp"
 "chapter7/Person.h"
 "chapter7/Screen.h"
 "chapter7/Screen.cpp"
 "chapter7/Class_X.h"
 "chapter7/Window_mgr.cpp"
 "chapter7/Window_mgr.h"
 "chapter7/No_default.h"
 "chapter7/No_default.cpp"
 "chapter7/Person.cpp"
 "chapter7/Debug.h"
 "chapter8/Chapter_8.h"
 "chapter8/Chaper_8.cpp"
 "chapter8/Person.h")

# TODO: 如有需要，请添加测试并安装目标。
