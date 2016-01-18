cmake_minimum_required(VERSION 2.6)
project(l07_nesting)

add_executable(l07_nesting main.cpp)

install(TARGETS l07_nesting RUNTIME DESTINATION bin)
