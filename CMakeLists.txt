cmake_minimum_required(VERSION 3.29)
project(cmake_test)

set(CMAKE_CXX_STANDARD 20)

#find_package(calculator 1.0 REQUIRED HINTS /tmp/cmake_test/lib)
#if (calculator_FOUND)
#    message(STATUS "calculator_INCLUDE_DIRS: " ${calculator_INCLUDE_DIRS})
#    message(STATUS "calculator_LIBRARIES: " ${calculator_LIBRARIES})
#endif ()
#
add_executable(cmake_test main.cpp)
#target_link_libraries(cmake_test PUBLIC calc)

find_package(instinct REQUIRED)