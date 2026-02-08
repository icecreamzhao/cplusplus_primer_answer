# 根据当前使用的 C++ 编译器类型选择不同的告警参数
# CMAKE_CXX_COMPILER_ID 常见取值：
# - Clang → clang / clang++
# - GNU   → gcc / g++
# - MSVC  → Visual C++
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")

    # 为 Clang / GCC 编译器添加常用且较严格的告警选项
    # 这些选项主要用于：
    # - 提前发现潜在 bug
    # - 提高代码质量
    # - 强化对隐式行为的约束
    add_compile_options(

        # 启用大多数常见的基础告警
        # 类似于“推荐最低告警级别”
        -Wall

        # 启用额外的一批告警（比 -Wall 更激进）
        # 通常能发现一些边界情况或不常见问题
        -Wextra

        # 严格遵循 ISO C++ 标准
        # 对非标准扩展或可疑写法给出告警
        -Wpedantic

        # 当局部变量 / 成员变量遮蔽（shadow）外层同名变量时给出告警
        # 这是实际工程中非常容易引入 bug 的情况
        -Wshadow

        # 对可能发生“隐式类型转换导致精度丢失”的地方给出告警
        # 例如：int -> float，double -> int
        -Wconversion

        # 专门针对有符号 / 无符号整数之间的隐式转换给出告警
        # 例如：int 与 size_t 混用
        -Wsign-conversion
    )

# 如果使用的是 MSVC 编译器
elseif (MSVC)

    # 为 MSVC 设置告警级别
    add_compile_options(

        # /W4 是 MSVC 推荐的“高但可用”的告警等级
        # - /W1 ~ /W4 依次更严格
        # - /Wall 过于激进，通常不适合真实工程
        /W4
    )
endif()
