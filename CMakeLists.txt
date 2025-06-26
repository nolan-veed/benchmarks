cmake_minimum_required(VERSION 3.31)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(benchmarks)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.4
)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
FetchContent_MakeAvailable(benchmark)

file(GLOB SOURCES *.cpp)
add_executable(benchmarks ${SOURCES})

target_link_libraries(benchmarks benchmark::benchmark)

set_target_properties(benchmarks PROPERTIES COMPILE_FLAGS "-save-temps -masm=intel -fverbose-asm -Wa,-adhlmn=main.lst")