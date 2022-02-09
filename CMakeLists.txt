cmake_minimum_required(VERSION 3.10)

project(parallel-factorial VERSION 0.0.1)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

set(SOURCE src/main.cpp)
add_executable(parallel-factorial ${SOURCE})
target_link_libraries(parallel-factorial gmp Threads::Threads)
