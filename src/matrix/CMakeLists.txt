add_library(Matrix_lib STATIC Matrix.cpp)
target_include_directories(Matrix_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Matrix_lib PUBLIC Rational_lib)