// Cache lines on CPUs.
#include <benchmark/benchmark.h>

#include <thread>
#include <atomic>

struct StoreAtomicsTogether {
    std::atomic<int> v0 = 0;
    std::atomic<int> v1 = 0;
    std::atomic<int> v2 = 0;
};

struct StoreAtomicsApart {
    alignas(std::hardware_destructive_interference_size) std::atomic<int> v0 = 0;
    alignas(std::hardware_destructive_interference_size) std::atomic<int> v1 = 0;
    alignas(std::hardware_destructive_interference_size) std::atomic<int> v2 = 0;
};

static void IncrAtomic(std::atomic<int> &v) {
    while (v.fetch_add(1) < 10'000'000) {
    }
}

static void BM_CacheAtomicOneThread(benchmark::State &state) {
    for (auto _: state) {
        StoreAtomicsTogether store;
        std::jthread t0 = std::jthread(IncrAtomic, std::ref(store.v0));
        t0.join();
        benchmark::DoNotOptimize(store);
    }
}

static void BM_CacheAtomicsTogetherTwoThreads(benchmark::State &state) {
    for (auto _: state) {
        StoreAtomicsTogether store;
        std::jthread t0 = std::jthread(IncrAtomic, std::ref(store.v0));
        std::jthread t1 = std::jthread(IncrAtomic, std::ref(store.v1));
        t0.join();
        t1.join();
        benchmark::DoNotOptimize(store);
    }
}

static void BM_CacheAtomicsTogetherThreeThreads(benchmark::State &state) {
    for (auto _: state) {
        StoreAtomicsTogether store;
        std::jthread t0 = std::jthread(IncrAtomic, std::ref(store.v0));
        std::jthread t1 = std::jthread(IncrAtomic, std::ref(store.v1));
        std::jthread t2 = std::jthread(IncrAtomic, std::ref(store.v2));
        t0.join();
        t1.join();
        t2.join();
        benchmark::DoNotOptimize(store);
    }
}

static void BM_CacheAtomicsApartTwoThreads(benchmark::State &state) {
    for (auto _: state) {
        StoreAtomicsApart store;
        std::jthread t0 = std::jthread(IncrAtomic, std::ref(store.v0));
        std::jthread t1 = std::jthread(IncrAtomic, std::ref(store.v1));
        t0.join();
        t1.join();
        benchmark::DoNotOptimize(store);
    }
}

static void BM_CacheAtomicsApartThreeThreads(benchmark::State &state) {
    for (auto _: state) {
        StoreAtomicsApart store;
        std::jthread t0 = std::jthread(IncrAtomic, std::ref(store.v0));
        std::jthread t1 = std::jthread(IncrAtomic, std::ref(store.v1));
        std::jthread t2 = std::jthread(IncrAtomic, std::ref(store.v2));
        t0.join();
        t1.join();
        t2.join();
        benchmark::DoNotOptimize(store);
    }
}

BENCHMARK(BM_CacheAtomicOneThread);
BENCHMARK(BM_CacheAtomicsTogetherTwoThreads);
BENCHMARK(BM_CacheAtomicsTogetherThreeThreads);
BENCHMARK(BM_CacheAtomicsApartTwoThreads);
BENCHMARK(BM_CacheAtomicsApartThreeThreads);
