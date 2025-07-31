# Goal

I was curious about how cache lines affect performance.

So, I wrote some trivial benchmarks.
* We increment variables in a struct, 10000000 times.
* We do this for non-atomic/atomic variables that are in the same or different cache-lines, using different threads.

## Example output

    /home/nolan-veed/nolan-veed/benchmarks/cmake-build-release/benchmarks --benchmark_filter=BM_Cache*
    2025-07-31T12:00:15+01:00
    Running /home/nolan-veed/nolan-veed/benchmarks/cmake-build-release/benchmarks
    Run on (16 X 4341.68 MHz CPU s)
    CPU Caches:
    L1 Data 48 KiB (x8)
    L1 Instruction 32 KiB (x8)
    L2 Unified 1280 KiB (x8)
    L3 Unified 24576 KiB (x1)
    Load Average: 0.75, 0.52, 0.64
    ------------------------------------------------------------------------------
    Benchmark                                    Time             CPU   Iterations
    ------------------------------------------------------------------------------
    BM_CacheAtomicOneThread               42303676 ns        42831 ns          100
    BM_CacheAtomicsTogetherTwoThreads    180052333 ns        50527 ns          100
    BM_CacheAtomicsTogetherThreeThreads  277200032 ns        73196 ns           10
    BM_CacheAtomicsApartTwoThreads        42150153 ns        54341 ns          100
    BM_CacheAtomicsApartThreeThreads      42466279 ns        59058 ns          100


