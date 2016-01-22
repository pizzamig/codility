cmake_minimum_required(VERSION 2.6)
project(l10_countfactors)

add_executable(l10_countfactors main.cpp)

install(TARGETS l10_countfactors RUNTIME DESTINATION bin)
