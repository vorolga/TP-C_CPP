cmake_minimum_required(VERSION 3.5.1)
project(tp_iz1 C CXX)

set(CMAKE_C_STANDARD 99)

set(LIB_SOURCE_FILES src/geometry.c)
set(LIB_HEADERS_FILES include/geometry.h tests/geometry_test.cpp)

add_library(geometry STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)

add_executable(tp_iz1 src/main.c)
target_link_libraries(tp_iz1 geometry m gcov -fprofile-arcs -ftest-coverage -fPIC)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(geometry_test tests/geometry_test.cpp)
target_link_libraries(geometry_test ${GTEST_LIBRARIES} -lpthread geometry)
