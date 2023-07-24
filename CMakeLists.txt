cmake_minimum_required(VERSION 3.27.0)
project(The_Lambda_Matrix VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#########
# GTest #
#########

enable_testing()
add_subdirectory(third-party/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

###########
# Project #
###########

add_subdirectory(src)