cmake_minimum_required (VERSION 3.0)

project (Matrix)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB src/matrix.cpp)			

add_library(libmatrix STATIC ${SOURCE_LIB})	

add_executable(matrix ${SOURCE_EXE})	

target_link_libraries(matrix libmatrix)
