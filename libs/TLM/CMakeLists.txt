set(LIBRARY_HEADERS
    include/TLM/Matrix.hpp
    include/TLM/Rational.hpp
)

set(LIBRARY_SOURCES
    src/Matrix.cpp
    src/Rational.cpp
)

add_library(${PROJECT_NAME} STATIC 
    ${LIBRARY_HEADERS} 
    ${LIBRARY_SOURCES}
)

target_include_directories(TLM PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/TLM>
    $<INSTALL_INTERFACE:include/TLM>
)

target_include_directories(TLM PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(test)