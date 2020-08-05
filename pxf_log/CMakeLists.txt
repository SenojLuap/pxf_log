cmake_minimum_required(VERSION 3.17)
project(pxf_log LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES    pxf_log.cpp
                    log_queue.cpp
                    log_event.cpp
                    log_entry.cpp
                    log_config.cpp
                    severity.cpp)

add_library(pxf_log STATIC ${SOURCE_FILES})
target_include_directories(pxf_log PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_precompile_headers(pxf_log PUBLIC    <thread>
                                            <mutex>
                                            <string>
                                            <queue>
                                            <cstdint>
                                            <memory>
                                            <chrono>
                                            <vector>
                                            <iostream>
                                            <fstream>
                                            <cstdio>
                                            <ctime>)