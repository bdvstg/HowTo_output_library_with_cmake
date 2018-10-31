cmake_minimum_required(VERSION 3.0)

# 這個寫法是全域的，會影響到myApis跟myApiTestProgram，比較不好，所以註解掉
#cmake_policy(SET CMP0063 NEW)
#set(CMAKE_CXX_VISIBILITY_PRESET hidden)
#set(CMAKE_C_VISIBILITY_PRESET hidden)

add_library(myApis SHARED
    myAdd.cpp
    myClass.cpp
    myMul.cpp
    myApi.h)
# 這寫法就只會影響到myApis
set_target_properties(myApis PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    C_VISIBILITY_PRESET hidden)
# 注意！CXX_VISIBILITY_PRESET 前面沒有CMAKE
# CMAKE_CXX_VISIBILITY_PRESET跟CXX_VISIBILITY_PRESET不一樣

add_executable(myApiTestProgram main.cpp)

# 因為是在同一個專案，所以myApis一定找的到，不用先用find_library去找
target_link_libraries(myApiTestProgram myApis)
