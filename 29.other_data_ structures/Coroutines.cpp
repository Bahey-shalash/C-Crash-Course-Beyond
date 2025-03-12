/* ==========================================================================
Crash Course: Coroutines (C++20)

Theory:
---------
Coroutines allow functions to suspend and resume execution. Their state is stored 
in a coroutine frame (usually allocated on the heap). The key components include:
  
   +------------------------------------------------+
   |           Coroutine Frame                    |
   |  +------------------------------------------+  |  
   |  | Promise Object: holds current value, etc.|  |  
   |  | Local variables                          |  |  
   |  | ...                                      |  |  
   |  +------------------------------------------+  |
   +------------------------------------------------+
                ^         ^
                |         |
       Coroutine Handle   Caller uses this to resume,
                          check status, and retrieve values.
  
Key Keywords:
- co_await, co_yield, and co_return are used to suspend and resume execution.
- A promise_type defines how to store state and how to yield values.

Edge Cases:
- Proper exception handling and cleanup within coroutines is essential.
- When a coroutine is done, its frame must be destroyed to free memory.

Example:
---------
A minimal generator that yields integers from 0 to max - 1 using co_yield.
========================================================================== */

#include <coroutine>
#include <iostream>
using namespace std;

template<typename T>
struct Generator {
    struct promise_type {
        T current_value;
        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        void unhandled_exception() { std::exit(1); }
        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;
    Generator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~Generator() { if (handle) handle.destroy(); }
    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;
    Generator(Generator&& other) : handle(other.handle) { other.handle = nullptr; }
    Generator& operator=(Generator&& other) {
        if (this != &other) {
            if (handle) handle.destroy();
            handle = other.handle;
            other.handle = nullptr;
        }
        return *this;
    }
    bool next() {
        handle.resume();
        return !handle.done();
    }
    T current() { return handle.promise().current_value; }
};

Generator<int> counter(int max) {
    for (int i = 0; i < max; i++) {
        co_yield i;
    }
}

int main() {
    cout << "Coroutine Generator Example:" << endl;
    auto gen = counter(5);
    while (gen.next()) {
        cout << "Value: " << gen.current() << endl;
    }
    return 0;
}