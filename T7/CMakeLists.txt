cmake_minimum_required(VERSION 2.6)
project(t7)

add_executable(t7 main.cpp)

install(TARGETS t7 RUNTIME DESTINATION bin)
