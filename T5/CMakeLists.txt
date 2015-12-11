cmake_minimum_required(VERSION 2.6)
project(t5)

add_executable(t5 main.cpp)

install(TARGETS t5 RUNTIME DESTINATION bin)
