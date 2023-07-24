
cmake_minimum_required(VERSION 3.27.0)

project(TLM_Library_Tests)

enable_testing()

if (NOT (TARGET gtest AND TARGET gtest_main))
    message(FATAL_ERROR "gtest and gtest_main targets NOT found")
endif()

add_executable(TLM_Library_Tests TLM_Tests.cpp)
target_link_libraries(TLM_Library_Tests 
    gtest 
    gtest_main 
    TLM
)
add_test(TLM_Library_Tests TLM_Tests.cpp)
