cmake_minimum_required(VERSION 2.6)
project(l11_countsemiprimes)

add_executable(l11_countsemiprimes main.cpp)

install(TARGETS l11_countsemiprimes RUNTIME DESTINATION bin)
