/* ==========================================================================
Lesson 2: Benchmarking and Profiling

Theory:
---------
Measuring performance is essential to optimization. Tools and techniques include:
- High-resolution timers (std::chrono)
- Profiling tools (e.g., Valgrind, gprof, Visual Studio Profiler)
- Micro-benchmarking specific code segments

Key Points:
- Use std::chrono to measure time in your code.
- Benchmark critical sections to find bottlenecks.
- Edge Cases: Ensure your benchmarks run multiple iterations to account for
variability.

Example:
---------
Measuring the execution time of a simple loop.
========================================================================== */

#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    volatile long long sum = 0;
    for (long long i = 0; i < 100000000LL; ++i) { // LL suffix for long long
        sum += i;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Loop took " << duration.count() << " milliseconds.\n";
    return 0;
}