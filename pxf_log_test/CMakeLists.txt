cmake_minimum_required(VERSION 3.17)
project(pxf_log_test)

set(TEST_SOURCE_FILES main.cpp)

add_executable(pxf_log_test ${TEST_SOURCE_FILES})
target_link_libraries(pxf_log_test pxf_log)
target_include_directories(pxf_log_test PUBLIC ../include)