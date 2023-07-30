# CMakeLists.txt
# Proyecto: The Lambda Matrix
# Autor: Hernan Ander Chambilla Chambilla
# CoAutor: Carlos Alfredo Percca Anchapuri
# Fecha: 2021-06-20

# Define la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.26.0)

# Define el proyecto
project(The_Lambda_Matrix
    VERSION 0.1.0
    DESCRIPTION "A simple matrix library for C++"
    LANGUAGES CXX
)

# Define las opciones de compilación
option(BUILD_TESTS "Build the tests" ON)
option(BUILD_EXAMPLES "Build the examples" ON)

####################################
# Configurar las opciones de CMake #
####################################

# Configurar la carpeta para los archivos de cabecera
# include_directories(include)

# add_subdirectory(src/tlm)
# target_include_directories(lambdalib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src/rational)

add_subdirectory(src/matrix)

# target_link_libraries(lambdalib PUBLIC lambdalib)

# Primero, descargamos y compilamos GTest
add_subdirectory(third_party/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()

if (NOT (TARGET gtest AND TARGET gtest_main))
    message(FATAL_ERROR "gtest y gtest_main objetivos NO encontrados")
endif()

add_subdirectory(tests)

add_subdirectory(examples)