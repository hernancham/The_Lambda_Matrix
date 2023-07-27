####################################
# Configurar las pruebas con GTest #
####################################

# Luego, agregamos los archivos de prueba y los vinculamos con la biblioteca GTest y la biblioteca lambdalib
if(BUILD_TESTS)
    add_executable(Rationaltest1 RationalTest.cpp)
    target_link_libraries(Rationaltest1 gtest gtest_main Matrix_lib)
    add_test(tlm_test1 Rationaltest1)

    add_executable(Matrixtest2 MatrixTest.cpp)
    target_link_libraries(Matrixtest2 gtest gtest_main Matrix_lib)
    add_test(tlm_test2 Matrixtest2)    
endif()