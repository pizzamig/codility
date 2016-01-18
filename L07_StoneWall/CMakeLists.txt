cmake_minimum_required(VERSION 2.6)
project(l07_stonewall)

add_executable(l07_stonewall main.cpp)

install(TARGETS l07_stonewall RUNTIME DESTINATION bin)
