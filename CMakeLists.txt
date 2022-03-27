cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME CXX_PRIMER_ANSWER)
project(${PROJECT_NAME})

include_directories("include")

# chapter1 的练习
add_subdirectory(chapter1)
add_executable(chapter_1 chapter_1.cpp)
target_link_libraries(chapter_1 PUBLIC ex1_9)
target_link_libraries(chapter_1 PUBLIC ex1_10)
target_link_libraries(chapter_1 PUBLIC ex1_11)
target_link_libraries(chapter_1 PUBLIC ex1_13)
target_link_libraries(chapter_1 PUBLIC ex1_16)

# chapter2 的练习
add_subdirectory(chapter2)
