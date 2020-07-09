cmake_minimum_required(VERSION 3.2)
project(main)
# 下面这句就是设置成debug模式，而不是release模式
set(CMAKE_BUILD_TYPE DEBUG)
add_executable(main main.cc)