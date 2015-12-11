cmake_minimum_required(VERSION 2.6)
project(t4)

add_executable(t4 main.cpp)

install(TARGETS t4 RUNTIME DESTINATION bin)
