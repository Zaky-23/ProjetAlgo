cmake_minimum_required(VERSION 3.25)

project(ProjetAlgo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src incl bin)

add_executable(app 
src/main.cpp 
src/tree.cpp src/string-parsing.cpp src/utils.cpp
incl/tree.hpp incl/string-parsing.hpp incl/utils.hpp)