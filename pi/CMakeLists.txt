cmake_minimum_required (VERSION 3.0)

project (PI)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB src/pi.cpp src/multi_pi.cpp)			

add_library(libpi STATIC ${SOURCE_LIB})	

add_executable(pi ${SOURCE_EXE})	

target_link_libraries(pi libpi)
