include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/0e402173c97aea7a00749e825b194bfede4f2e45.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        parallel-factorial-test
        parallel_factorial.test.cpp
)
add_dependencies(parallel-factorial-test parallel-factorial-lib)
target_link_libraries(
        parallel-factorial-test
        parallel-factorial-lib
        gmp
        gtest_main
)
