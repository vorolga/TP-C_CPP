cmake_minimum_required(VERSION 3.5.1)
project(tp_iz1 C CXX)

set(CMAKE_C_STANDARD 99)

set(LIB_SOURCE_FILES src/geometry.c)
set(LIB_HEADERS_FILES include/geometry.h tests/geometry_test.cpp)

add_library(geometry STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall --coverage")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

# AddressSanitize
set(CMAKE_C_FLAGS_ASAN
        "-fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -g -O1"
        CACHE STRING "Flags used by the C compiler during AddressSanitizer builds."
        FORCE)
set(CMAKE_CXX_FLAGS_ASAN
        "-fsanitize=address -fno-optimize-sibling-calls -fno-omit-frame-pointer -g -O1"
        CACHE STRING "Flags used by the C++ compiler during AddressSanitizer builds."
        FORCE)


add_executable(tp_iz1 src/main.c)
target_link_libraries(tp_iz1 geometry m -fprofile-arcs -ftest-coverage -fPIC)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(geometry_test tests/geometry_test.cpp)
target_link_libraries(geometry_test ${GTEST_LIBRARIES} -lpthread geometry)
