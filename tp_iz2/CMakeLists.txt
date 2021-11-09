cmake_minimum_required(VERSION 3.20)
project(tp_iz2 C CXX)

set(CMAKE_C_STANDARD 23)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC -Werror -Wpedantic -pthread")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC -Werror -Wpedantic")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)


include_directories(employee employee_arr include_main_func list_position_experience)

set(LIB_SOURCE_FILES employee/employee.c employee_arr/employee_arr.c list_position_experience/list_position_experience.c include_main_func/main_func.c)
set(LIB_HEADERS_FILES employee/employee.h employee_arr/employee_arr.h list_position_experience/list_position_experience.h include_main_func/main_func.h)

add_executable(tp_iz2 src/main.c)
add_executable(stress_test stress_test.c)

option(USE_PARALLEL "parallel lib" NO)
if (USE_PARALLEL)
    set(LIB_SOURCE list_position_experience/shared_make_report.c)
    add_library(make_report_shared SHARED ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES} list_position_experience/shared_make_report.c)
    install(TARGETS make_report_shared DESTINATION /usr/lib)
    target_link_libraries(tp_iz2 make_report_shared -ldl)
    target_link_libraries(stress_test make_report_shared -ldl)

else()
    set(LIB_SOURCE list_position_experience/static_make_report.c)
    add_library(make_report STATIC ${LIB_SOURCE_FILES} ${LIB_HEADERS_FILES} list_position_experience/static_make_report.c)
    target_link_libraries(tp_iz2 make_report)
    target_link_libraries(stress_test make_report)
endif ()


add_compile_options(--coverage)
add_link_options(--coverage)

add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
add_link_options(-fsanitize=address)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(make_report_test tests/read_file_test.cpp tests/make_report_test.cpp tests/free_node_test.cpp tests/add_employee_test.cpp tests/main.cpp ${LIB_SOURCE_FILES} ${LIB_SOURCE})
target_link_libraries(make_report_test ${GTEST_LIBARIES} -lpthread -lgtest -lgtest_main)