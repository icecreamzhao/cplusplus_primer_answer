cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME CXX_PRIMER_ANSWER)
project(${PROJECT_NAME})

add_executable (
primerFifth 
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
 "chapter9/Chapter_9.h"
 "chapter8/Chaper_8.cpp"
 "chapter8/Person.h"
 "chapter9/Chapter_9.cpp"
 "chapter9/Chapter_9.h" 
 "chapter10/chapter_10.cpp" 
 "chapter10/chapter_10.h" "chapter_1.cpp")

include_directories("include")

# chapter1 的练习
add_subdirectory(chapter1)
add_executable(chapter_1 chapter_1.cpp)
target_link_libraries(chapter_1 PUBLIC ex1_9)
target_link_libraries(chapter_1 PUBLIC ex1_10)
target_link_libraries(chapter_1 PUBLIC ex1_11)
target_link_libraries(chapter_1 PUBLIC ex1_13)
target_link_libraries(chapter_1 PUBLIC ex1_16)
