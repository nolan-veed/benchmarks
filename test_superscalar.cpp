// Test the superscalar pipeline nature of CPUs.
#include <benchmark/benchmark.h>

static void Sum(int &sum) {
    sum = 0;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
    }
}

static void Mul(int &prod) {
    prod = 1;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
    }
}

static void Superscalar(int &sum, int &sum2, int &prod, int &prod2) {
    sum = 0;
    sum2 = 0;
    prod = 1;
    prod2 = 1;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
        sum2 -= i;
        prod *= i;
        prod2 *= i;
    }
}

static void BM_Sum(benchmark::State &state) {
    int sum = 0;
    for (auto _: state) {
        Sum(sum);
        benchmark::DoNotOptimize(sum);
    }
}

static void BM_Mul(benchmark::State &state) {
    int prod = 0;
    for (auto _: state) {
        Mul(prod);
        benchmark::DoNotOptimize(prod);
    }
}

static void BM_Superscalar(benchmark::State &state) {
    int sum = 0;
    int sum2 = 0;
    int prod = 0;
    int prod2 = 0;
    for (auto _: state) {
        Superscalar(sum, sum2, prod, prod2);
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(sum2);
    }
}

BENCHMARK(BM_Sum);
BENCHMARK(BM_Mul);
BENCHMARK(BM_Superscalar);

// Example output:
//
// 2025-06-02T10:58:06+01:00
// Running /home/nolan-veed/nolan-veed/benchmarks/cmake-build-release/benchmarks
// Run on (16 X 2425.75 MHz CPU s)
// CPU Caches:
//   L1 Data 48 KiB (x8)
//   L1 Instruction 32 KiB (x8)
//   L2 Unified 1280 KiB (x8)
//   L3 Unified 24576 KiB (x1)
// Load Average: 1.96, 2.50, 1.39
// ---------------------------------------------------------
// Benchmark               Time             CPU   Iterations
// ---------------------------------------------------------
// BM_Sum           55224333 ns     55220661 ns           12
// BM_Mul          628653383 ns    628557756 ns            1
// BM_Superscalar  428165822 ns    428114326 ns            2
