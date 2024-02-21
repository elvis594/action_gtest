# 指定头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 创建一个库add，基于add.cpp
add_library(add add.cpp)

# 如果你有一个主程序，你可以在这里添加
# add_executable(main main.cpp)
# target_link_libraries(main add)
