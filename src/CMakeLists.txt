find_package(Threads REQUIRED)

set(
        SOURCE
        main.cc
        parallel_factorial.cc
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
add_library(parallel-factorial-lib STATIC ${SOURCE})
