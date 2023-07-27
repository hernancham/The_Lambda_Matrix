######################################
# Configurar los archivos de ejemplo #
######################################

# Agregar los archivos de ejemplo
if(BUILD_EXAMPLES)
    add_executable(Examples1 Examples1.cpp)
    target_link_libraries(Examples1 PUBLIC Matrix_lib)

    add_executable(Examples2 Examples2.cpp)
    target_link_libraries(Examples2 PUBLIC Matrix_lib)
endif()