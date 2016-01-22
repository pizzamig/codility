cmake_minimum_required(VERSION 2.6)
project(l10_flags)

add_executable(l10_flags main.cpp)

install(TARGETS l10_flags RUNTIME DESTINATION bin)
