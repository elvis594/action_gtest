# 使用Github Action进行C++单元测试

[![codecov](https://codecov.io/gh/elvis594/action_gtest/graph/badge.svg?token=IHEM9XN2Y7)](https://codecov.io/gh/elvis594/action_gtest)


## 所需工具
- codecov
- googletest
- github action

## 编写测试用例

## 运行测试用例

- 构建编译目录
```shell
mkdir build
cd build 
cmake .. -DCMAKE_BUILD_TYPE=Release
```

- 编译工程
```shell
cmake --build
```

- 运行所有测试用例
```shell
ctest -C
```
## 生成覆盖率报告
```
make coverage
```


## 使用CI自动化生成


## README中展示覆盖率