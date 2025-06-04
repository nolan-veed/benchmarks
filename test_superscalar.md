# Goal

I was curious about how long simple operations take.

So, I wrote some trivial benchmarks.
* We go from 1 to 1000000000.
* And add/multiply those into a variable. 

## Example output

    2025-06-04T09:53:27+01:00
    Running /home/nolan-veed/nolan-veed/benchmarks/cmake-build-release/benchmarks
    Run on (16 X 829.034 MHz CPU s)
    CPU Caches:
    L1 Data 48 KiB (x8)
    L1 Instruction 32 KiB (x8)
    L2 Unified 1280 KiB (x8)
    L3 Unified 24576 KiB (x1)
    Load Average: 0.46, 0.43, 0.53
    -----------------------------------------------------
    Benchmark           Time             CPU   Iterations
    -----------------------------------------------------
    BM_Add       56002369 ns     55988747 ns           13
    BM_Add2     174727175 ns    174686940 ns            4
    BM_Add3     137654951 ns    137638465 ns            5
    BM_Add4     348894993 ns    348845732 ns            2
    BM_Mul      629630225 ns    629452905 ns            1
    BM_Mul2     629381732 ns    629159280 ns            1
    BM_Mul3     628621434 ns    628515041 ns            1
    BM_Mul4     838427008 ns    838235256 ns            1
    BM_Mul5    1047356921 ns   1047101664 ns            1
    BM_Mul6    1257812609 ns   1257581458 ns            1
    BM_AddMul   634604660 ns    634409074 ns            1
