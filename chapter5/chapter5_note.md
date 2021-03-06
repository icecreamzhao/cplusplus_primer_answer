# 第五章笔记

## 异常

编写异常安全的代码非常困难, 异常中断了程序的正常流程。异常发生时, 调用者请求的一部分计算可能已经完成了, 另一部分则尚未完成。通常情况下, 略过部分程序意味着某些对象处理到一半就戛然而止, 从而导致对象处于无效或未完成的状态, 或者资源没有正常释放等。**那些在异常发生期间正确执行了"清理"工作的程序被称为异常安全(exception safe)的代码。**

## 标准异常

c++定义了一组类, 用于报告标准函数遇到的问题, 分别定义在四个头文件中:

* exception 头文件定义了最通用的异常类exception, 他只报告异常的发生, 不提供额外的异常信息
* stdexcept 头文件定义了几种常用的异常类
* new 头文件定义了bad_alloc异常类型
* type_info头文件定义了bad_cast异常类型

stdexcept 定义的异常类

| 异常类名称 | 说明 |
| -------: | :-- |
| exception | 最常见的问题 |
| runtime_error | 只有在运行时才能检测出的问题 |
| range_error | 运行时错误, 生成的结果超出了有意义的值域范围 |
| overflow_error | 运行时错误, 计算上溢 |
| underflow_error | 运行时错误, 计算下溢 |
| logic_error | 程序逻辑错误 |
| domain_error | 逻辑错误, 参数对应的结果值不存在 |
| invalid_argument | 逻辑错误, 无效参数 |
| length_error | 逻辑错误, 试图创建一个超出该类型最大长度的对象 |
| out_of_range | 逻辑错误, 使用一个超出有效范围的值 | 