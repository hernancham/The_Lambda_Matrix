add_library(Rational_lib STATIC Rational.cpp)
target_include_directories(Rational_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
