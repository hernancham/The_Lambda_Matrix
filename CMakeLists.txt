cmake_minimum_required(VERSION 3.27)
project(gtest_project CXX)

find_package(GTest)

add_executable(${PROJECT_NAME} src/main.cpp)

# Use the global target
target_link_libraries(${PROJECT_NAME} gtest::gtest)
