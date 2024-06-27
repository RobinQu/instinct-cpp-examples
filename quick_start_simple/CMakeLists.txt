cmake_minimum_required(VERSION 3.29)
project(quick_start)

set(CMAKE_CXX_STANDARD 20)

add_executable(quick_start main.cpp)
target_link_libraries(quick_start PUBLIC instinct-cpp::instinct-cpp)

find_package(instinct-cpp REQUIRED)