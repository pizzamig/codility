cmake_minimum_required(VERSION 2.6)
project(t6)

add_executable(t6 main.cpp)

install(TARGETS t6 RUNTIME DESTINATION bin)
