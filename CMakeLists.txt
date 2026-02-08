# 指定 CMake 的最低版本要求
# 3.23 是一个相对较新的版本，支持较完善的 CMake Presets、现代特性
cmake_minimum_required(VERSION 3.23)

# 定义项目名称、版本号以及使用的语言
# project() 会：
# - 设置 PROJECT_NAME / PROJECT_VERSION 等变量
# - 启用对应语言的编译器检测
project(minimal_industrial_framework
    VERSION 0.1.0
    LANGUAGES C CXX
)

# 设置 C 语言标准为 C11
# 等价于给 C 编译器添加 -std=c11（或 MSVC 对应选项）
set(CMAKE_C_STANDARD 11)

# 设置 C++ 语言标准为 C++20
# 等价于给 C++ 编译器添加 -std=c++20（或 /std:c++20）
set(CMAKE_CXX_STANDARD 20)

# 强制要求编译器必须支持指定的 C++ 标准
# 如果编译器不支持 C++20，CMake 会直接报错，而不是回退
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 导出 compile_commands.json
# 这个文件通常用于：
# - clangd / VSCode / CLion 等 IDE 的智能提示
# - clang-tidy / clangd / 静态分析工具
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 引入自定义的编译器配置文件
# 一般在这里做的事情包括：
# - 根据平台选择 clang / clang-cl / gcc / msvc
# - 设置 CMAKE_C_COMPILER / CMAKE_CXX_COMPILER
# - 设置编译器相关的通用选项
include(cmake/compiler.cmake)

# 引入编译告警配置
# 通常用于：
# - 统一开启 -Wall -Wextra -Wpedantic
# - 针对 MSVC / Clang / GCC 做差异化处理
# - 将警告视为错误（-Werror / /WX）
include(cmake/warnings.cmake)

add_subdirectory(src/ch01)
add_subdirectory(src/ch02)
