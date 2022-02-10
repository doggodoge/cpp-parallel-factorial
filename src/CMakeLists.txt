find_package(Threads REQUIRED)

set(
        SOURCE
        main.cpp
        parallel_factorial.cpp
)
add_executable(
        parallel-factorial
        ${SOURCE}
)
target_link_libraries(
        parallel-factorial
        gmp
        Threads::Threads
)
add_library(parallel-factorial-lib STATIC parallel_factorial.cpp parallel_factorial.h)
