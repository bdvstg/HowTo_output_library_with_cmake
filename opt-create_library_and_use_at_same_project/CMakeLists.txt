cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0063 NEW)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)

add_library(myApis SHARED
    myAdd.cpp
    myClass.cpp
    myMul.cpp
    myApi.h)

add_executable(myApiTestProgram main.cpp)

# 因為是在同一個專案，所以myApis一定找的到，不用先用find_library去找
target_link_libraries(myApiTestProgram myApis)
