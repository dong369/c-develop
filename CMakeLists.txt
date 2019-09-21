cmake_minimum_required(VERSION 3.13)
project(c_develop)

set(CMAKE_CXX_STANDARD 14)

# C基础
add_subdirectory(base-01)

# C++基础
add_subdirectory(base-02)

# 数据结构+算法（C语言版）
add_subdirectory(base-03)

# 数据结构+算法（C++语言版）
add_subdirectory(base-04)