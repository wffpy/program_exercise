cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(window VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(window min_cover_sub_string.cc)
