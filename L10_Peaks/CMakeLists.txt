cmake_minimum_required(VERSION 2.6)
project(l10_peaks)

add_executable(l10_peaks main.cpp)

install(TARGETS l10_peaks RUNTIME DESTINATION bin)
