# 判断当前使用的 C++ 编译器类型
# CMAKE_CXX_COMPILER_ID 是 CMake 内置变量
# 常见取值：
# - "Clang"        → clang / clang++
# - "GNU"          → gcc / g++
# - "MSVC"         → Visual C++
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")

    # 为 Clang / GCC 系列编译器添加编译选项
    # add_compile_options 是“目录级”的：
    # - 会作用于当前 CMakeLists.txt 及其子目录中定义的所有 target
    add_compile_options(

        # 禁用 C++ 异常支持
        # - 减小二进制体积
        # - 避免异常表（.eh_frame 等）
        # - 常见于嵌入式 / 实时 / 工业控制场景
        -fno-exceptions

        # 禁用 RTTI（Run-Time Type Information）
        # - 禁止 dynamic_cast / typeid
        # - 减小可执行文件体积
        # - 常用于对性能和尺寸敏感的系统
        -fno-rtti

        # 将全局/静态数据放入独立的 section
        # 目的是配合链接器进行垃圾回收（--gc-sections）
        -fdata-sections

        # 将每个函数放入独立的 section
        # 同样是为了让未使用的函数在链接阶段被裁剪
        -ffunction-sections
    )

# 如果使用的是 MSVC 编译器（Visual Studio / clang-cl 也可能走这里）
elseif (MSVC)

    # 为 MSVC 编译器添加特定的编译选项
    add_compile_options(

        # 启用标准一致性模式（关闭 MSVC 的非标准扩展）
        # 有助于提高代码的可移植性和标准符合度
        /permissive-

        # 修正 __cplusplus 宏的值
        # 没有该选项时 MSVC 可能返回错误的 C++ 标准版本
        # 对 C++20 / 特性检测非常重要
        /Zc:__cplusplus

        # 启用标准的 C++ 异常处理模型（try / catch）
        # 等价于：
        # - 同时支持同步异常
        # - 使用 C++ 风格的异常语义
        /EHsc
    )
endif()
