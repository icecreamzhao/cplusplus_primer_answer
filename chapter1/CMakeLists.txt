cmake_minimum_required (VERSION 3.8)

set(PUBLIC_INCLUDE_DIR "../include/chapter1")

include_directories("../include")

# exercise
add_executable(ex1_1 ex_1_1.cpp)
add_executable(ex1_2 ex_1_2.cpp)
add_executable(ex1_3 ex_1_3.cpp)
add_executable(ex1_4 ex_1_4.cpp)
add_executable(ex1_5 ex_1_5.cpp)
add_executable(ex1_7 ex_1_7.cpp)
add_executable(ex1_8 ex_1_8.cpp)
add_library(ex1_9 "")
target_sources(ex1_9
  PRIVATE
    "ex_1_9.cpp"
    "${PUBLIC_INCLUDE_DIR}/chapter_1.h"
)
add_library(ex1_10 "")
target_sources(ex1_10
  PRIVATE
    "ex_1_10.cpp"
    "${PUBLIC_INCLUDE_DIR}/chapter_1.h"
)
add_library(ex1_11 "")
target_sources(ex1_11
  PRIVATE
    "ex_1_11.cpp"
    "${PUBLIC_INCLUDE_DIR}/chapter_1.h"
)
add_library(ex1_13 "")
target_sources(ex1_13
  PRIVATE
    "ex_1_13.cpp"
    "${PUBLIC_INCLUDE_DIR}/chapter_1.h"
)
add_library(ex1_16 "")
target_sources(ex1_16
  PRIVATE
    "ex_1_16.cpp"
    "${PUBLIC_INCLUDE_DIR}/chapter_1.h"
)
add_executable(ex1_17 ex_1_17.cpp)
add_executable(ex1_20 ex_1_20.cpp)
add_executable(ex1_21 ex_1_21.cpp)
add_executable(ex1_22 ex_1_22.cpp)
add_executable(ex1_23 ex_1_23.cpp)

# program
add_executable(pr1_2 pr_1_2.cpp)
add_library(pr1_4_4 pr_1_4_4.cpp)

target_link_libraries(ex1_17 PUBLIC pr1_4_4)
