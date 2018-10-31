cmake_minimum_required(VERSION 3.0)

# Linux GCC預設所有function/class都是可以被引用的
# 底下兩行會改為預設不能被引用
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)

add_library(myApis SHARED
    myAdd.cpp
    myClass.cpp
    myMul.cpp
    myApi.h)
