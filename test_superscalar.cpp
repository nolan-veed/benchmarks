// Test the superscalar pipeline nature of CPUs.
#include <benchmark/benchmark.h>

static void Add(int &sum) {
    sum = 0;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
    }
}

static void Add2(int &sum, int &sum2) {
    sum = 0;
    sum2 = 10;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
        sum2 += i;
    }
}

static void Add3(int &sum, int &sum2, int &sum3) {
    sum = 0;
    sum2 = 10;
    sum3 = 100;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
        sum2 += i;
        sum3 += i;
    }
}

static void Add4(int &sum, int &sum2, int &sum3, int &sum4) {
    sum = 0;
    sum2 = 10;
    sum3 = 100;
    sum4 = 1000;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
        sum2 += i;
        sum3 += i;
        sum4 += i;
    }
}

static void Mul(int &prod) {
    prod = 1;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
    }
}

static void Mul2(int &prod, int &prod2) {
    prod = 1;
    prod2 = 10;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
        prod2 *= i;
    }
}

static void Mul3(int &prod, int &prod2, int &prod3) {
    prod = 1;
    prod2 = 10;
    prod3 = 100;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
        prod2 *= i;
        prod3 *= i;
    }
}

static void Mul4(int &prod, int &prod2, int &prod3, int &prod4) {
    prod = 1;
    prod2 = 10;
    prod3 = 100;
    prod4 = 1000;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
        prod2 *= i;
        prod3 *= i;
        prod4 *= i;
    }
}

static void Mul5(int &prod, int &prod2, int &prod3, int &prod4, int &prod5) {
    prod = 1;
    prod2 = 10;
    prod3 = 100;
    prod4 = 1000;
    prod5 = 10000;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
        prod2 *= i;
        prod3 *= i;
        prod4 *= i;
        prod5 *= i;
    }
}

static void Mul6(int &prod, int &prod2, int &prod3, int &prod4, int &prod5, int &prod6) {
    prod = 1;
    prod2 = 10;
    prod3 = 100;
    prod4 = 1000;
    prod5 = 10000;
    prod6 = 100000;
    for (int i = 1; i < 1000000001; i++) {
        prod *= i;
        prod2 *= i;
        prod3 *= i;
        prod4 *= i;
        prod5 *= i;
        prod6 *= i;
    }
}

static void AddMul(int &sum, int &sum2, int &sum3, int &sum4, int &prod, int &prod2, int &prod3) {
    sum = 0;
    sum2 = 0;
    sum3 = 0;
    sum4 = 0;
    prod = 1;
    prod2 = 10;
    prod3 = 100;
    for (int i = 1; i < 1000000001; i++) {
        sum += i;
        sum2 += i;
        sum3 += i;
        sum4 += i;
        prod *= i;
        prod2 *= i;
        prod3 *= i;
    }
}

static void BM_Add(benchmark::State &state) {
    int sum = 0;
    for (auto _: state) {
        Add(sum);
        benchmark::DoNotOptimize(sum);
    }
}

static void BM_Add2(benchmark::State &state) {
    int sum, sum2 = 0;
    for (auto _: state) {
        Add2(sum, sum2);
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(sum2);
    }
}

static void BM_Add3(benchmark::State &state) {
    int sum, sum2, sum3 = 0;
    for (auto _: state) {
        Add3(sum, sum2, sum3);
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(sum2);
        benchmark::DoNotOptimize(sum3);
    }
}

static void BM_Add4(benchmark::State &state) {
    int sum, sum2, sum3, sum4 = 0;
    for (auto _: state) {
        Add4(sum, sum2, sum3, sum4);
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(sum2);
        benchmark::DoNotOptimize(sum3);
        benchmark::DoNotOptimize(sum4);
    }
}

static void BM_Mul(benchmark::State &state) {
    int prod = 0;
    for (auto _: state) {
        Mul(prod);
        benchmark::DoNotOptimize(prod);
    }
}

static void BM_Mul2(benchmark::State &state) {
    int prod, prod2 = 0;
    for (auto _: state) {
        Mul2(prod, prod2);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
    }
}

static void BM_Mul3(benchmark::State &state) {
    int prod, prod2, prod3 = 0;
    for (auto _: state) {
        Mul3(prod, prod2, prod3);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
        benchmark::DoNotOptimize(prod3);
    }
}

static void BM_Mul4(benchmark::State &state) {
    int prod, prod2, prod3, prod4 = 0;
    for (auto _: state) {
        Mul4(prod, prod2, prod3, prod4);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
        benchmark::DoNotOptimize(prod3);
        benchmark::DoNotOptimize(prod4);
    }
}

static void BM_Mul5(benchmark::State &state) {
    int prod, prod2, prod3, prod4, prod5 = 0;
    for (auto _: state) {
        Mul5(prod, prod2, prod3, prod4, prod5);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
        benchmark::DoNotOptimize(prod3);
        benchmark::DoNotOptimize(prod4);
        benchmark::DoNotOptimize(prod5);
    }
}

static void BM_Mul6(benchmark::State &state) {
    int prod, prod2, prod3, prod4, prod5, prod6 = 0;
    for (auto _: state) {
        Mul6(prod, prod2, prod3, prod4, prod5, prod6);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
        benchmark::DoNotOptimize(prod3);
        benchmark::DoNotOptimize(prod4);
        benchmark::DoNotOptimize(prod5);
        benchmark::DoNotOptimize(prod6);
    }
}

static void BM_AddMul(benchmark::State &state) {
    int sum, sum2, sum3, sum4, prod, prod2, prod3 = 0;
    for (auto _: state) {
        AddMul(sum, sum2, sum3, sum4, prod, prod2, prod3);
        benchmark::DoNotOptimize(sum);
        benchmark::DoNotOptimize(sum2);
        benchmark::DoNotOptimize(sum3);
        benchmark::DoNotOptimize(sum4);
        benchmark::DoNotOptimize(prod);
        benchmark::DoNotOptimize(prod2);
        benchmark::DoNotOptimize(prod3);
    }
}

BENCHMARK(BM_Add);
BENCHMARK(BM_Add2);
BENCHMARK(BM_Add3);
BENCHMARK(BM_Add4);
BENCHMARK(BM_Mul);
BENCHMARK(BM_Mul2);
BENCHMARK(BM_Mul3);
BENCHMARK(BM_Mul4);
BENCHMARK(BM_Mul5);
BENCHMARK(BM_Mul6);
BENCHMARK(BM_AddMul);
