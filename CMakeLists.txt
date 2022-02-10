cmake_minimum_required(VERSION 3.15)

project(
        parallel-factorial
        VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
