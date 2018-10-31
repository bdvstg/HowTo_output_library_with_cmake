cmake_minimum_required(VERSION 3.0)

add_executable(myApiTestProgram main.cpp)

find_library(MY_APIS myApis HINTS ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(myApiTestProgram ${MY_APIS})
