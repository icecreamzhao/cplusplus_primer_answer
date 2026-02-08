# 介绍

本项目是本人学习C++ primer 5th的过程，包含了英文原版与中文版翻译的对照，以及书中所有的练习。

# 启动方式

## windows 启动

```bash
cmake --preset windows-clang-cl
cmake --build build/windows
```

## linux 启动

```bash
cmake --preset linux-clang
cmake --build build/linux
```

## macos 启动

```bash
cmake --preset macos-clang
cmake --build build/macos
```

# 对于`CMakePresets.json`的解释

```json
"version": 6
```

* 表示 CMake Presets 规范版本, version 6 对应 CMake ≥ 3.23

```json
{
  "name": "windows-clang-cl",
  "displayName": "Windows + clang-cl + Ninja",
  "generator": "Ninja",
  "binaryDir": "build/windows",
  "cacheVariables": {
    "CMAKE_C_COMPILER": "clang-cl",
    "CMAKE_CXX_COMPILER": "clang-cl"
  }
}
```

* `generator: "Ninja"` 表示放弃 Visual Studio 工程, 使用 单一构建系统（Ninja）, 与 Linux / macOS 保持一致
* `binaryDir: "build/windows"` 表示 Windows 构建产物隔离, 不同平台互不污染, 非常利于并行开发 / CI
* `CMAKE_C_COMPILER / CMAKE_CXX_COMPILER = clang-cl` clang-cl 使用 MSVC ABI, 可以链接 MSVC rumtime, Windows SDK, 但享受 clang 更严格的诊断

```json
{
  "name": "linux-clang",
  "displayName": "Linux + clang++ + Ninja",
  "generator": "Ninja",
  "binaryDir": "build/linux",
  "cacheVariables": {
    "CMAKE_C_COMPILER": "clang",
    "CMAKE_CXX_COMPILER": "clang++"
  }
}
```

* 在 Linux 上强制使用 LLVM 工具链，而不是 GCC

```json
{
  "name": "macos-clang",
  "displayName": "macOS + AppleClang",
  "generator": "Ninja",
  "binaryDir": "build/macos"
}
```

* macOS 上系统自带 AppleClang, 所以无需指定编译器